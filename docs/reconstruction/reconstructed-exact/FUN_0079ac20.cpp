// =============================================================================
// FUN_0079ac20
// -----------------------------------------------------------------------------
// Stable ID: aa_0079ac20
// Address:   0x0079ac20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079ac20 @ 0x0079ac20
// Stable ID: aa_0079ac20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT44, FUN_0079ac20, QueryPerformanceCounter.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0079ac20(void)



{

  uint uVar1;

  uint uVar2;

  int iVar4;

  char *unaff_ESI;

  uint uVar3;

  

  QueryPerformanceCounter((LARGE_INTEGER *)(unaff_ESI + 0x18));

  uVar1 = (((LARGE_INTEGER *)(unaff_ESI + 0x18))->s).LowPart;

  uVar2 = *(uint *)(unaff_ESI + 0x10);

  uVar3 = *(uint *)(unaff_ESI + 0x10);

  iVar4 = *(int *)(unaff_ESI + 0x14);

  *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x1c);

  *(uint *)(unaff_ESI + 0x10) = uVar1;

  *(float *)(unaff_ESI + 4) =

       (float)CONCAT44((*(int *)(unaff_ESI + 0x1c) - iVar4) - (uint)(uVar1 < uVar2),uVar1 - uVar3) *

       _DAT_00afa270;

  if (*unaff_ESI != '\0') {

    *(float *)(unaff_ESI + 8) = *(float *)(unaff_ESI + 8) - *(float *)(unaff_ESI + 4);

    return;

  }

  *(float *)(unaff_ESI + 8) = *(float *)(unaff_ESI + 4) + *(float *)(unaff_ESI + 8);

  return;

}
