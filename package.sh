#!/bin/bash

# Configuration
PKG_NAME="libsaibcm"
PKG_DEV_NAME="libsaibcm-dev"
VERSION="1.0.0-th5-dev"
ARCH="amd64"

# Filenames
DEB_FILE="${PKG_NAME}_${VERSION}_${ARCH}.deb"
DEB_DEV_FILE="${PKG_DEV_NAME}_${VERSION}_${ARCH}.deb"

# 1. Clean and Compile
echo "--- Compiling Code ---"
rm -rf build build-dev
make clean
make

# --- PACKAGE 1: RUNTIME (libsai.so.1) ---
echo "--- Creating Runtime Package (libsai) ---"
mkdir -p build/DEBIAN
mkdir -p build/usr/lib/x86_64-linux-gnu/

# Copy Library and Soname Link
cp libsai.so.1.0.0 build/usr/lib/x86_64-linux-gnu/
ln -s libsai.so.1.0.0 build/usr/lib/x86_64-linux-gnu/libsai.so.1

# Control File (Runtime)
cat > build/DEBIAN/control <<EOF
Package: ${PKG_NAME}
Version: ${VERSION}
Section: libs
Priority: optional
Architecture: ${ARCH}
Maintainer: Spanidea <user@example.com>
Description: SAI Runtime Library for TH5
EOF

dpkg-deb --build build ${DEB_FILE}


# --- PACKAGE 2: DEVELOPER (headers + libsai.so) ---
echo "--- Creating Developer Package (libsai-dev) ---"
mkdir -p build-dev/DEBIAN
mkdir -p build-dev/usr/include/sai
mkdir -p build-dev/usr/lib/x86_64-linux-gnu/

# Copy Headers
cp inc/*.h build-dev/usr/include/sai/

# *** CRITICAL FIX: The linker needs libsai.so here ***
# We create a relative link so the compiler finds it
ln -s libsai.so.1.0.0 build-dev/usr/lib/x86_64-linux-gnu/libsai.so

# Control File (Dev)
cat > build-dev/DEBIAN/control <<EOF
Package: ${PKG_DEV_NAME}
Version: ${VERSION}
Section: libdevel
Priority: optional
Architecture: ${ARCH}
Depends: ${PKG_NAME} (= ${VERSION})
Maintainer: Spanidea <user@example.com>
Description: SAI Development Headers for TH5
EOF

dpkg-deb --build build-dev ${DEB_DEV_FILE}

echo "=========================================="
echo "Success! Created:"
echo "1. ${DEB_FILE}"
echo "2. ${DEB_DEV_FILE}"
echo "=========================================="