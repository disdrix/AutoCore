// =============================================================================
// FUN_00470570
// -----------------------------------------------------------------------------
// Stable ID: aa_00470570
// Address:   0x00470570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470570 @ 0x00470570
// Stable ID: aa_00470570
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0046f900, FUN_0046fc80, FUN_0046feb0, FUN_0046ff50, FUN_00470570.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00470570(uint8_t param_1)



{

  uint64_t uVar1;

  int in_EAX;

  int unaff_ESI;

  

  uVar1 = _DAT_00aaa780;

  if ((unaff_ESI != 0) && (in_EAX != 0)) {

    *(byte *)(in_EAX + 9) = *(byte *)(in_EAX + 9) | 8;

    *(uint8_t *)(in_EAX + 0x2c) = param_1;

    FUN_0046feb0(uVar1);

    FUN_0046ff50();

    FUN_0046fc80();

    FUN_0046f900(_DAT_00aaa748,_DAT_00aaa750,_DAT_00aaa758,_DAT_00aaa760,_DAT_00aaa768,_DAT_00aaa770

                 ,_DAT_00a10e30,_DAT_00aaa778);

  }

  return;

}
