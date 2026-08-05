// =============================================================================
// FUN_00799820  (scaffold alias — prefer XmlAttr_FetchParseLong_StoreByteIfOk)
// -----------------------------------------------------------------------------
// Stable ID: aa_00799820
// Address:   0x00799820  (autoassault.exe, image base 0x400000)
// System:    XML / mission attribute helpers
// Generated: 2026-07-29 W21-G dual seal (refresh of 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: XmlAttr_FetchParseLong_StoreByteIfOk.cpp
// =============================================================================

#include <cstdint>

char FUN_00799460(uint32_t param_1, uint32_t param_2, long *param_3, int param_4);

void FUN_00799820(uint32_t param_1, uint32_t param_2, uint8_t *param_3, uint32_t param_4)
{
    char cVar1;
    uint8_t local_4[4];

    cVar1 = FUN_00799460(param_1, param_2, (long *)local_4, (int)param_4);
    if (cVar1 != '\0') {
        *param_3 = local_4[0];
    }
}
