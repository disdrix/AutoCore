// =============================================================================
// FUN_004047a0  /  UiToast_UninitializedCopy_0x98
// -----------------------------------------------------------------------------
// Stable ID: aa_004047a0
// Address:   0x004047a0 – 0x0040480b  (autoassault.exe, image base 0x400000)
// System:    missions-progression / shared UI toast vector helpers
// Generated: 2026-07-29 W22-H dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Range POD copy of toast elements (stride 0x98) via UiToast_PodCopyElement_0x98.
// See also: UiToast_UninitializedCopy_0x98.cpp (named twin).
// =============================================================================

#include <cstdint>

extern "C" void __stdcall FUN_00404710(void* dst, const void* src); // UiToast_PodCopyElement_0x98

// Decompiler formals (3 shown); bytes also load 4th stack dword into EBX/ECX (unused by callee).
extern "C" int FUN_004047a0(int param_1, int param_2, int param_3)
{
    // SEH: ExceptionList / LAB_009bd1c0 — elided
    for (; param_1 != param_2; param_1 = param_1 + 0x98) {
        FUN_00404710(reinterpret_cast<void*>(param_3), reinterpret_cast<const void*>(param_1));
        param_3 = param_3 + 0x98;
    }
    return param_3;
}
