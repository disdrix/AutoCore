// =============================================================================
// FUN_0042c2a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c2a0
// Address:   0x0042c2a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042c2a0 @ 0x0042c2a0
// Stable ID: aa_0042c2a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT22×3, FUN_0042c2a0, FUN_007849d0, FUN_00784af0, block, free, htonl.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x0042c2ff) */



void __thiscall FUN_0042c2a0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  u_long uVar1;

  short local_14;

  uint16_t uStack_12;

  uint16_t local_10;

  uint16_t uStack_e;

  int local_c;

  int local_8;

  int local_4;

  

  FUN_00784af0(param_1 + 0x68);

  uVar1 = htonl(0);

  if ((((local_14 == 0) && (CONCAT22(uStack_e,local_10) == uVar1)) && (local_c == 0)) &&

     ((local_8 == 0 && (local_4 == 0)))) {

    FUN_007849d0();

    free((void *)0x0);

  }

  *param_2 = CONCAT22(uStack_12,local_14);

  param_2[1] = CONCAT22(uStack_e,local_10);

  param_2[2] = local_c;

  param_2[3] = local_8;

  param_2[4] = local_4;

  return;

}
