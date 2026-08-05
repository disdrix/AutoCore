// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_puzzle_solved_in_d_m_00974470
// -----------------------------------------------------------------------------
// Stable ID: aa_00974470
// Callee of Named_CalleeOf_Named_Client_puzzle_solved_in_d_ms (+1 other named callers)
// Address:   0x00974470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_puzzle_solved_in_d_ms: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_Client_puzzle_solved_in_d_ms (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0077fb80×3, CONCAT31, FUN_0077dcb0, FUN_0077f960, FUN_00974470.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_puzzle_solved_in_d_ms (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Named_CalleeOf_Named_CalleeOf_Named_Client_puzzle_solved_in_d_m_00974470(uint32_t /* width from decompiler */ param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ in_EAX;

  uint uVar1;

  uint8_t local_138 [4];

  uint8_t local_134;

  uint8_t local_133;

  uint8_t local_132;

  uint8_t local_131;

  byte local_130 [32];

  uint8_t local_110 [272];

  

  local_134 = (uint8_t)((uint)in_EAX >> 0x18);

  local_133 = (uint8_t)((uint)in_EAX >> 0x10);

  local_132 = (uint8_t)((uint)in_EAX >> 8);

  local_131 = (uint8_t)in_EAX;

  FUN_0077dcb0(local_110);

  FUN_0077fb80(local_110,local_138,8);

  FUN_0077fb80(local_110,param_3,8);

  FUN_0077fb80(local_110,param_4,8);

  FUN_0077f960(local_110,local_130);

  uVar1 = 0;

  while( true ) {

    if (param_2 < 9) {

      return CONCAT31((int3)(uVar1 >> 8),

                      '\x01' - ((-1 << (8U - (char)param_2 & 0x1f) & local_130[uVar1]) != 0));

    }

    if (local_130[uVar1] != 0) break;

    param_2 = param_2 - 8;

    uVar1 = uVar1 + 1;

  }

  return uVar1 & 0xffffff00;

}
