// =============================================================================
// FUN_0060d460  (scaffold alias — prefer CVOGObjectiveRequirement_UseItem_MatchTargetCore.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0060d460
// Address:   0x0060d460  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: UseItem MatchTarget core — identity (COID|CBID) + cargo presence
//          (FindItemByCoid, invert @+0x1d) + optional secondary CBID
//          (FindItemByCbid @+0x2c) + optional character field @+0x54 vs clonebase+0xfc.
// See: reconstructed-exact/CVOGObjectiveRequirement_UseItem_MatchTargetCore.cpp

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory 220 B (2026-07-29).
 * - ret 0x08; returns AL 0/1.
 * - Inventory grid ECX = *(*(character+0x250)+0x2B0) (bytes sealed).
 * - Runtime / differential verification: OPEN.
 */

#include <cstdint>

extern int* __thiscall FUN_00571010(void* grid, int coidLo, int coidHi);
extern int* __thiscall FUN_005710c0(void* grid, int cbid, char skipGate, unsigned short addQty);

// thiscall ECX = requirement; stack character*, target*; ret 8
std::uint32_t __thiscall FUN_0060d460(int param_1, int param_2, int param_3)
{
    int iVar1;

    if ((param_2 == 0) || (param_3 == 0)) {
        return 0;
    }
    if ((((((*(unsigned int*)(param_1 + 0x10) & *(unsigned int*)(param_1 + 0x14)) != 0xffffffff) &&
          (*(unsigned int*)(param_3 + 0x160) == *(unsigned int*)(param_1 + 0x10)) &&
          (*(unsigned int*)(param_3 + 0x164) == *(unsigned int*)(param_1 + 0x14))) ||
         ((*(int*)(param_1 + 0x18) != -1 &&
           (*(int*)(*(int*)(param_3 + 0xa8) + 0x34) == *(int*)(param_1 + 0x18))))) &&
        ((*(int*)(param_2 + 0x250) != 0 &&
          ((*(int*)(*(int*)(param_2 + 0x250) + 0x2b0) != 0 &&
            (iVar1 = (int)FUN_00571010(
                         (void*)*(int*)(*(int*)(param_2 + 0x250) + 0x2b0),
                         *(int*)(param_3 + 0x160),
                         *(int*)(param_3 + 0x164)),
             (iVar1 == 0) == (bool)*(char*)(param_1 + 0x1d))))))) {
        if ((*(int*)(param_1 + 0x2c) != -1) &&
            (iVar1 = (int)FUN_005710c0(
                          (void*)*(int*)(*(int*)(param_2 + 0x250) + 0x2b0),
                          *(int*)(param_1 + 0x2c), 0, 0),
             iVar1 == 0)) {
            return 0;
        }
        if ((*(int*)(param_1 + 0x54) < 1) ||
            (*(int*)(param_1 + 0x54) ==
             *(int*)(*(int*)(*(int*)(*(int*)(param_2 + 4) + 4) + 0xa8 + param_2) + 0xfc))) {
            return 1;
        }
    }
    return 0;
}
