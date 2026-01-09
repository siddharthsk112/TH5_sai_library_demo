#include <stdio.h>
#include <string.h>
#include <sai.h>
#include <saiversion.h>
#include "sai_internal.h"

// --- 1. Essential Query Function ---
sai_status_t sai_query_api_version(_Out_ sai_api_version_t *version)
{
    if (version == NULL) return SAI_STATUS_INVALID_PARAMETER;
    *version = SAI_API_VERSION;
    return SAI_STATUS_SUCCESS;
}

// --- 2. Dummy Switch API Stub ---
sai_status_t stub_create_switch(
    _Out_ sai_object_id_t *switch_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list)
{
    printf("[TH5-SAI] create_switch called! (Hello World)\n");
    *switch_id = 1;
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_remove_switch(_In_ sai_object_id_t switch_id) {
    return SAI_STATUS_SUCCESS;
}

sai_switch_api_t switch_api = {
    .create_switch = stub_create_switch,
    .remove_switch = stub_remove_switch,
};

// --- 3. Main Entry Point ---
sai_status_t sai_api_query(
    _In_ sai_api_t sai_api_id,
    _Out_ void **api_method_table)
{
    if (api_method_table == NULL) return SAI_STATUS_INVALID_PARAMETER;

    switch (sai_api_id) {
        case SAI_API_SWITCH:
            *api_method_table = &switch_api;
            return SAI_STATUS_SUCCESS;
        case SAI_API_VLAN:
            printf("[TH5-SAI] Requested SAI_API_VLAN\n");
            *api_method_table = &vlan_api; 
            return SAI_STATUS_SUCCESS;
        
        default:
            *api_method_table = NULL;
            return SAI_STATUS_NOT_IMPLEMENTED;
    }
}

// --- 4. Dependency Functions ---
sai_status_t sai_log_set(_In_ sai_api_t sai_api_id, _In_ sai_log_level_t log_level) {
    return SAI_STATUS_SUCCESS;
}

sai_status_t sai_api_initialize(_In_ uint64_t flags, _In_ const sai_service_method_table_t *services) {
    printf("[TH5-SAI] Library Initialized\n");

    printf("[TH5-SAI] Running Self-Test: creating VLAN 100...\n");
    
    sai_object_id_t vlan_id;
    sai_attribute_t attr;
    attr.id = SAI_VLAN_ATTR_VLAN_ID;
    attr.value.u16 = 100;

    vlan_api.create_vlan(&vlan_id, 1, 1, &attr);
    
    return SAI_STATUS_SUCCESS;
}

sai_status_t sai_api_uninitialize(void) {
    return SAI_STATUS_SUCCESS;
}

sai_object_type_t sai_object_type_query(_In_ sai_object_id_t object_id)
{
    if (object_id == 1) return SAI_OBJECT_TYPE_SWITCH;
    return SAI_OBJECT_TYPE_PORT;
}

sai_object_id_t sai_switch_id_query(_In_ sai_object_id_t object_id)
{
    return 1;
}

// --- 5. Other Capability Stubs (to simulate switch return Status) ---
sai_status_t sai_query_attribute_capability(
    _In_ sai_object_id_t switch_id,
    _In_ sai_object_type_t object_type,
    _In_ sai_attr_id_t attr_id,
    _Out_ sai_attr_capability_t *attr_capability)
{
    attr_capability->create_implemented = true;
    attr_capability->set_implemented = true;
    attr_capability->get_implemented = true;
    return SAI_STATUS_SUCCESS;
}

sai_status_t sai_query_attribute_enum_values_capability(
    _In_ sai_object_id_t switch_id,
    _In_ sai_object_type_t object_type,
    _In_ sai_attr_id_t attr_id,
    _Inout_ sai_s32_list_t *enum_values_capability)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t sai_query_stats_capability(
    _In_ sai_object_id_t switch_id,
    _In_ sai_object_type_t object_type,
    _Inout_ sai_stat_capability_list_t *stats_capability)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t sai_object_type_get_availability(
    _In_ sai_object_id_t switch_id,
    _In_ sai_object_type_t object_type,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list,
    _Out_ uint64_t *count)
{
    *count = 100;
    return SAI_STATUS_SUCCESS;
}

sai_status_t sai_dbg_generate_dump(_In_ const char *dump_file_name) {
    return SAI_STATUS_SUCCESS;
}