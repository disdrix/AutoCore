// =============================================================================
// FUN_004034c0  (scaffold twin — prefer StdList_InsertN_BeforeNode_Dword_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_004034c0
// Address:   0x004034c0  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list
// Generated: 2026-08-05 MEGA-134 (keeps Ghidra symbol as twin of named clean)
// Exactness: Behavior-preserving; ABI notes from live assembly.
// =============================================================================

// Prefer: reconstructed-exact/StdList_InsertN_BeforeNode_Dword_Inferred.cpp
// Named:  StdList_InsertN_BeforeNode_Dword_Inferred
// Retired scaffold: Named_CalleeOf_Named_CalleeOf_Client_DebugListMissionsStatus_004034c0

#include <cstdint>

// Ghidra-shaped formals (thiscall param_1 = ECX = val*):
//   param_1 ECX  = val*
//   param_2 stk  = list*
//   param_3 stk  = where*
//   param_4 stk  = count
// Decompiler call FUN_004040f0(param_3,param_1) DROPS list this — asm uses ECX=param_2.

extern "C" void __thiscall FUN_004040f0(void *list /*ECX*/, void *where, const void *val);

extern "C" void __thiscall FUN_004034c0(
    uint32_t *param_1_val /*ECX*/,
    void *param_2_list,
    void *param_3_where,
    int param_4_count)
{
    // SEH LAB_009bd210 omitted
    for (; param_4_count != 0; param_4_count = param_4_count + -1) {
        FUN_004040f0(param_2_list, param_3_where, param_1_val);
    }
}
