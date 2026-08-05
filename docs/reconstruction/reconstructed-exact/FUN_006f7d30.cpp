// =============================================================================
// FUN_006f7d30
// -----------------------------------------------------------------------------
// Stable ID: aa_006f7d30
// Address:   0x006f7d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f7d30 @ 0x006f7d30
// Stable ID: aa_006f7d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006f7d30.
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

void FUN_006f7d30(void)



{

  uint in_EAX;

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint *unaff_EDI;

  

  uVar1 = (int)in_EAX >> 4;

  uVar3 = ~(uVar1 >> 3) & 1;

  uVar4 = ~(uVar1 >> 2) & 1;

  uVar1 = ~(uVar1 >> 1) & 1;

  if ((in_EAX & 0xf) == 0) {

    iVar2 = uVar4 + uVar1 * 2;

  }

  else if ((in_EAX & 0xf) == 1) {

    iVar2 = uVar3 + 4 + uVar1 * 2;

  }

  else {

    iVar2 = uVar3 + 8 + uVar4 * 2;

  }

  iVar2 = 1 << ((byte)(iVar2 << 1) & 0x1f);

  if ((*unaff_EDI & iVar2 * 2) == 0) {

    *unaff_EDI = *unaff_EDI + iVar2;

  }

  return;

}
