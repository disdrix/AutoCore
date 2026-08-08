// =============================================================================
// FUN_004020f0  (alias: BasicStringFlag_Dtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004020f0
// Address:   0x004020f0–0x00402126 inclusive (55 B / 0x37)
// Module:    autoassault.exe, image base 0x400000
// System:    missions-progression (partition); unit = shared aggregate dtor
// Wave:      R10-018 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow + disasm.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

// PURPOSE: SEH-wrapped destructor for BasicStringFlag — destroys only the
//          basic_string subobject at +0 (flag @ +0x1c is POD).
// Preferred name: BasicStringFlag_Dtor_Inferred
// See: reconstructed-exact/BasicStringFlag_Dtor_Inferred.cpp

// READABILITY:
//  - Body size: 55 B; 12 instructions (disassemble_function).
//  - Sole callee: IAT [0x009c62f4] ~basic_string.
//  - Callers: 7 Unwind@* UNCONDITIONAL_CALL.
//  - Epilogue: ADD ESP,0xC; RET 4.

#include <cstdint>

/*
 * Behavioral notes:
 * - Live decompile 2026-08-05 ≡ raw 2026-07-23 CF.
 * - ABI sealed: stack object*, thiscall into string dtor, RET 4.
 * - Family: ctor 00401d30, copy 00402040 (both dualed).
 * - Runtime / differential verification: OPEN (Terminal false).
 */

// Authoritative control-flow shape (Ghidra names retained):
void FUN_004020f0(
    /* basic_string / BasicStringFlag* */ void* param_1)
{
    // SEH: puStack_8 = &LAB_009bbfb9; ExceptionList chain; local_4 = -1
    // MOV ECX, param_1
    // CALL [0x009c62f4]  → std::basic_string<char>::~basic_string
    // ExceptionList restore; ADD ESP,0xC; RET 4
    (void)param_1;
}
