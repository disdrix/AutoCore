// =============================================================================
// FUN_007aa3e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007aa3e0
// Address:   0x007aa3e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007aa3e0 @ 0x007aa3e0
// Stable ID: aa_007aa3e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_007aa3e0.
//  - Return sites: 3.

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

void FUN_007aa3e0(void)



{

  int iVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  int *unaff_EDI;

  

  iVar2 = *in_EAX;

  if ((iVar2 < 0x280) || (iVar3 = in_EAX[1], iVar3 < 0x1e0)) {

    *unaff_EDI = DAT_00a1e888;

    unaff_EDI[1] = DAT_00a1e88c;

    return;

  }

  iVar1 = iVar2 * 3;

  if (iVar3 * 4 < iVar1) {

    iVar2 = (iVar3 * 4) / 3;

  }

  else {

    iVar3 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;

  }

  if ((iVar2 < 0x641) && (iVar3 < 0x4b1)) {

    unaff_EDI[1] = iVar3;

    *unaff_EDI = iVar2;

    return;

  }

  *unaff_EDI = DAT_00a1e8a8;

  unaff_EDI[1] = DAT_00a1e8ac;

  return;

}
