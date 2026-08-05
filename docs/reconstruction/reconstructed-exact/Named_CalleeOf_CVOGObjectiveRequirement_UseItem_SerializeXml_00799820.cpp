// =============================================================================
// Named_CalleeOf_CVOGObjectiveRequirement_UseItem_SerializeXml_00799820
// -----------------------------------------------------------------------------
// Stable ID: aa_00799820
// NOTE: Prefer XmlAttr_FetchParseLong_StoreByteIfOk — this alias is a legacy
//       xref-seed name (parent SerializeXml is one of many callers).
// Address:   0x00799820  (autoassault.exe, image base 0x400000)
// =============================================================================

#include <cstdint>

char FUN_00799460(uint32_t param_1, uint32_t param_2, long *param_3, int param_4);

void Named_CalleeOf_CVOGObjectiveRequirement_UseItem_SerializeXml_00799820(
    uint32_t param_1,
    uint32_t param_2,
    uint8_t *param_3,
    uint32_t param_4)
{
    char cVar1;
    uint8_t local_4[4];

    cVar1 = FUN_00799460(param_1, param_2, (long *)local_4, (int)param_4);
    if (cVar1 != '\0') {
        *param_3 = local_4[0];
    }
}
