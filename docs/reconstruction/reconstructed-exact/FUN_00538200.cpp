// =============================================================================
// FUN_00538200  (alias scaffold — prefer CNDHash_ReclaimAll_ValueOwning_009cefec.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00538200
// Address:   0x00538200  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-07-29 dual W18-J (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Canonical named clean: reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009cefec.cpp
// Dual A/B: reviews/A_aa_00538200_* / B_aa_00538200_*
// Decompiler gap: operator_delete is NOT noreturn (bytes continue after call).
// =============================================================================

void __thiscall CNDHash_ReclaimAll_ValueOwning_009cefec(int thisHash);

void __thiscall FUN_00538200(int param_1)
{
    CNDHash_ReclaimAll_ValueOwning_009cefec(param_1);
}
