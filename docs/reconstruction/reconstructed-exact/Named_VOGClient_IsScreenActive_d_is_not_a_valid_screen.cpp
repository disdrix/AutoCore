// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CONCAT31×2, FUN_007a4480, FUN_009321f0, VOGClient::IsScreenActive.
//  - Strings: "VOGClient::IsScreenActive(%d) is not a valid screen #".
//  - Return sites: 3.

// =============================================================================
// Named_VOGClient_IsScreenActive_d_is_not_a_valid_screen
// -----------------------------------------------------------------------------
// Stable ID: aa_009321f0
// Address:   0x009321f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGClient::IsScreenActive(%d) is not a valid screen #"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Named_VOGClient_IsScreenActive_d_is_not_a_valid_screen(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  uint in_EAX;

  int unaff_ESI;

  

  piVar1 = *(int **)(param_2 + 0xf40);

  if (piVar1 != (int *)0x0) {

    if (unaff_ESI == 0) {

      return CONCAT31((int3)((uint)*piVar1 >> 8),*piVar1 == *(int *)(param_2 + 0xf3c));

    }

    if (unaff_ESI == 1) {

      return CONCAT31((int3)((uint)*piVar1 >> 8),*piVar1 == *(int *)(param_2 + 0xf38));

    }

    in_EAX = FUN_007a4480(1,"VOGClient::IsScreenActive(%d) is not a valid screen #");

  }

  return in_EAX & 0xffffff00;

}
