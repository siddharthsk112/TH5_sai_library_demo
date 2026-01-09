#include <stdio.h>
#include <sai.h>
#include "sai_internal.h"

sai_status_t stub_create_vlan(
    _Out_ sai_object_id_t *vlan_id,
    _In_ sai_object_id_t switch_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list)
{
    printf("[TH5-SAI] Inside create vlan function\n");
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_remove_vlan(_In_ sai_object_id_t vlan_id)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_set_vlan_attribute(
    _In_ sai_object_id_t vlan_id,
    _In_ const sai_attribute_t *attr)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_get_vlan_attribute(
    _In_ sai_object_id_t vlan_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_create_vlan_member(
    _Out_ sai_object_id_t *vlan_member_id,
    _In_ sai_object_id_t switch_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_remove_vlan_member(_In_ sai_object_id_t vlan_member_id)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_set_vlan_member_attribute(
    _In_ sai_object_id_t vlan_member_id,
    _In_ const sai_attribute_t *attr)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_get_vlan_member_attribute(
    _In_ sai_object_id_t vlan_member_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_create_vlan_members(
    _In_ sai_object_id_t switch_id,
    _In_ uint32_t object_count,
    _In_ const uint32_t *attr_count,
    _In_ const sai_attribute_t **attr_list,
    _In_ sai_bulk_op_error_mode_t mode,
    _Out_ sai_object_id_t *object_id,
    _Out_ sai_status_t *object_statuses)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_remove_vlan_members(
    _In_ uint32_t object_count,
    _In_ const sai_object_id_t *object_id,
    _In_ sai_bulk_op_error_mode_t mode,
    _Out_ sai_status_t *object_statuses)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_get_vlan_stats(
    _In_ sai_object_id_t vlan_id,
    _In_ uint32_t number_of_counters,
    _In_ const sai_stat_id_t *counter_ids,
    _Out_ uint64_t *counters)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_get_vlan_stats_ext(
    _In_ sai_object_id_t vlan_id,
    _In_ uint32_t number_of_counters,
    _In_ const sai_stat_id_t *counter_ids,
    _In_ sai_stats_mode_t mode,
    _Out_ uint64_t *counters)
{
    return SAI_STATUS_SUCCESS;
}

sai_status_t stub_clear_vlan_stats(
    _In_ sai_object_id_t vlan_id,
    _In_ uint32_t number_of_counters,
    _In_ const sai_stat_id_t *counter_ids)
{
    return SAI_STATUS_SUCCESS;
}

sai_vlan_api_t vlan_api = {
    .create_vlan = stub_create_vlan,
    .remove_vlan = stub_remove_vlan,
    .set_vlan_attribute = stub_set_vlan_attribute,
    .get_vlan_attribute = stub_get_vlan_attribute,
    .create_vlan_member = stub_create_vlan_member,
    .remove_vlan_member = stub_remove_vlan_member,
    .set_vlan_member_attribute = stub_set_vlan_member_attribute,
    .get_vlan_member_attribute = stub_get_vlan_member_attribute,
    .create_vlan_members = stub_create_vlan_members,
    .remove_vlan_members = stub_remove_vlan_members,
    .get_vlan_stats = stub_get_vlan_stats,
    .get_vlan_stats_ext = stub_get_vlan_stats_ext,
    .clear_vlan_stats = stub_clear_vlan_stats
};