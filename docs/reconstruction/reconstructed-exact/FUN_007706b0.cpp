// =============================================================================
// FUN_007706b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007706b0
// Address:   0x007706b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007706b0 @ 0x007706b0
// Stable ID: aa_007706b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×2, do×1.
//  - Notable callees: FUN_007706b0.
//  - Return sites: 2.

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

int FUN_007706b0(void)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int *piVar4;

  uint uVar5;

  int *unaff_ESI;

  

  iVar1 = *unaff_ESI;

  if (iVar1 == 0) {

    return 0;

  }

  iVar2 = 0;

  if (0 < iVar1) {

    piVar4 = (int *)unaff_ESI[3];

    do {

      if (*piVar4 != 0) break;

      iVar2 = iVar2 + 1;

      piVar4 = piVar4 + 1;

    } while (iVar2 < iVar1);

  }

  uVar5 = *(uint *)(unaff_ESI[3] + iVar2 * 4);

  iVar2 = iVar2 * 0x1c;

  uVar3 = uVar5 & 1;

  while (uVar3 == 0) {

    uVar3 = uVar5 & 0xf;

    iVar2 = iVar2 + *(int *)(&DAT_00a23b60 + uVar3 * 4);

    uVar5 = uVar5 >> 4;

  }

  return iVar2;

}
