// =============================================================================
// FUN_0079cec0
// -----------------------------------------------------------------------------
// Stable ID: aa_0079cec0
// Address:   0x0079cec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079cec0 @ 0x0079cec0
// Stable ID: aa_0079cec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0079cec0.
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

int FUN_0079cec0(char *param_1)



{

  char *pcVar1;

  int iVar2;

  char unaff_BP;

  int *unaff_ESI;

  int iVar3;

  int unaff_retaddr;

  

  pcVar1 = param_1;

  param_1 = (char *)((uint)param_1 & 0xffffff00);

  (**(code **)(*unaff_ESI + 4))(&param_1,1);

  iVar3 = 0;

  if ((((unaff_BP != '\0') && (iVar3 = 0, unaff_BP != '\r')) && (unaff_BP != '\n')) &&

     (0 < unaff_retaddr + -2)) {

    *pcVar1 = unaff_BP;

    iVar3 = 1;

    (**(code **)(*unaff_ESI + 4))(&stack0xfffffffc,1);

    unaff_BP = '\0';

  }

  pcVar1[iVar3] = '\0';

  if (unaff_BP == '\r') {

    iVar2 = (**(code **)(*unaff_ESI + 0x1c))();

    (**(code **)(*unaff_ESI + 0x24))(iVar2 + 1);

  }

  return iVar3;

}
