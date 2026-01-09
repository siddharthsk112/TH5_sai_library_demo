#ifndef __SAI_INTERNAL_H__
#define __SAI_INTERNAL_H__

#include <sai.h>

// Tell sai.c that these structures exist elsewhere
extern sai_vlan_api_t vlan_api;

// If you split switch code later, you would add: extern sai_switch_api_t switch_api;

#endif // __SAI_INTERNAL_H__