// =============================================================================
// FUN_00833160
// -----------------------------------------------------------------------------
// Stable ID: aa_00833160
// Address:   0x00833160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00833160 @ 0x00833160
// Stable ID: aa_00833160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0040cf90×2, FUN_00416160×2, FUN_00416240, FUN_00833160.
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

uint32_t /* width from decompiler */ FUN_00833160(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *unaff_ESI;

  int *unaff_EDI;

  uint8_t local_d0 [204];

  

  if (unaff_EDI == (int *)0x0) {

    return 0;

  }

  iVar3 = unaff_ESI[0x142];

  unaff_ESI[0x142] = unaff_EDI[0x142];

  unaff_EDI[0x142] = iVar3;

  iVar3 = unaff_ESI[0x143];

  unaff_ESI[0x143] = unaff_EDI[0x143];

  unaff_EDI[0x143] = iVar3;

  iVar3 = unaff_ESI[0x175];

  unaff_ESI[0x175] = unaff_EDI[0x175];

  unaff_EDI[0x175] = iVar3;

  iVar3 = unaff_ESI[0xa6];

  unaff_ESI[0xa6] = unaff_EDI[0xa6];

  unaff_EDI[0xa6] = iVar3;

  iVar3 = unaff_ESI[0x13f];

  *(char *)(unaff_ESI + 0x13f) = (char)unaff_EDI[0x13f];

  *(char *)(unaff_EDI + 0x13f) = (char)iVar3;

  *(char *)(unaff_ESI + 0x13f) = (char)unaff_EDI[0x174];

  *(char *)(unaff_EDI + 0x174) = (char)unaff_ESI[0x174];

  *(char *)(unaff_ESI + 0x13f) = (char)unaff_EDI[0x177];

  *(char *)(unaff_EDI + 0x177) = (char)unaff_ESI[0x177];

  iVar3 = unaff_ESI[0x2f];

  *(char *)(unaff_ESI + 0x2f) = (char)unaff_EDI[0x2f];

  *(char *)(unaff_EDI + 0x2f) = (char)iVar3;

  FUN_00416240(unaff_ESI + 0x144);

  FUN_00416160(unaff_EDI + 0x144);

  FUN_00416160(local_d0);

  iVar3 = unaff_ESI[0x178];

  iVar4 = unaff_ESI[0x179];

  iVar1 = unaff_ESI[0x17a];

  iVar2 = unaff_ESI[0x17b];

  unaff_ESI[0x178] = unaff_EDI[0x178];

  unaff_ESI[0x179] = unaff_EDI[0x179];

  unaff_ESI[0x17a] = unaff_EDI[0x17a];

  unaff_ESI[0x17b] = unaff_EDI[0x17b];

  unaff_EDI[0x178] = iVar3;

  unaff_EDI[0x179] = iVar4;

  unaff_EDI[0x17a] = iVar1;

  unaff_EDI[0x17b] = iVar2;

  iVar3 = unaff_ESI[0x140];

  iVar4 = unaff_ESI[0x141];

  unaff_ESI[0x140] = unaff_EDI[0x140];

  unaff_ESI[0x141] = unaff_EDI[0x141];

  unaff_EDI[0x140] = iVar3;

  unaff_EDI[0x141] = iVar4;

  iVar3 = (**(code **)(*unaff_ESI + 0x1a0))();

  if (iVar3 != 0) {

    iVar3 = (**(code **)(*unaff_EDI + 0x1a0))();

    if (iVar3 != 0) {

      iVar3 = (**(code **)(*unaff_EDI + 0x1a0))();

      iVar3 = *(int *)(iVar3 + 8);

      iVar4 = (**(code **)(*unaff_ESI + 0x1a0))();

      iVar4 = *(int *)(iVar4 + 8);

      (**(code **)(*unaff_EDI + 0x1a0))();

      FUN_0040cf90(iVar4 + 0x90);

      (**(code **)(*unaff_ESI + 0x1a0))();

      FUN_0040cf90(iVar3 + 0x90);

    }

  }

  (**(code **)(*unaff_EDI + 0x3bc))();

  (**(code **)(*unaff_ESI + 0x3bc))();

  return 1;

}
