// =============================================================================
// FUN_004d32c0 / CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004d32c0
// Address:   0x004d32c0  (autoassault.exe, image base 0x400000)
// System:    sector-map / combat-pool level index
// Generated: 2026-07-29 dual seal W16-E (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Sector-map character-enter bookkeeping twin of leave path FUN_004d3310:
//     1) this+0xe818 (level/power index) += 1
//     2) if notifyPools: FUN_004d28c0(this, oldIndex, newIndex) pool rescale
//     3) raceHist[def+0x532] at this+0xe81c += 1; return &cell
//
// ABI: __thiscall; stack (Object *entering, char notifyPools); ret 8
// Caller: Client_RecvCreateCharacter @ 0x008147ae
// Callee: FUN_004d28c0 (optional)
// Twin:   FUN_004d3310 (decrement)

#include <cstdint>

// Forward: CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred
extern "C" void __thiscall FUN_004d28c0(void *sectorMap, int oldLevel, int newLevel);

extern "C" int *__thiscall FUN_004d32c0(void *param_1 /*this*/, void *param_2 /*entering*/,
                                         char param_3 /*notifyPools*/)
{
    int *piVar1;
    uint32_t uVar2;

    *(int *)((char *)param_1 + 0xe818) = *(int *)((char *)param_1 + 0xe818) + 1;
    if (param_3 != '\0') {
        FUN_004d28c0(param_1,
                     *(int *)((char *)param_1 + 0xe818) + -1,
                     *(int *)((char *)param_1 + 0xe818));
    }
    uVar2 = (uint32_t)*(uint8_t *)(
        *(int *)(*(int *)(*(int *)(*(int *)((char *)param_2 + 4) + 4) + 0xac +
                          (int)param_2) +
                 0x3c) +
        0x532);
    piVar1 = (int *)((char *)param_1 + 0xe81c + uVar2 * 4);
    *piVar1 = *piVar1 + 1;
    return (int *)((char *)param_1 + 0xe81c + uVar2 * 4);
}

// Named alias (structural / inferred — product symbol open)
extern "C" int *__thiscall CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred(
    void *sectorMap, void *enteringObject, char notifyPools)
{
    return FUN_004d32c0(sectorMap, enteringObject, notifyPools);
}
