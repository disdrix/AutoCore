// =============================================================================
// FUN_009674b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009674b0
// Address:   0x009674b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009674b0 @ 0x009674b0
// Stable ID: aa_009674b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: for×4, return×1.
//  - Notable callees: FUN_0044c3c0×8, FUN_00746d00×8, FUN_00967060×7, FUN_00414b60, FUN_009674b0.
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



uint FUN_009674b0(void)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b085e;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_0044c3c0(0,0);

  uRam00000004 = DAT_00a242f8;

  uRam00000008 = DAT_00a242fc;

  uRam0000000c = DAT_00a24300;

  FUN_00746d00();

  uVar1 = FUN_00967060(unaff_EBX);

  FUN_0044c3c0(0,0);

  uRam00000004 = DAT_00a242f8;

  uRam00000008 = DAT_00a242fc;

  uRam0000000c = DAT_00a24300;

  FUN_00746d00();

  FUN_0044c3c0(0,0);

  uRam00000004 = DAT_00a24308;

  uRam00000008 = DAT_00a2430c;

  uRam0000000c = DAT_00a24310;

  FUN_00746d00();

  uVar2 = FUN_00967060(unaff_EBX);

  FUN_0044c3c0(0,0);

  _DAT_00000000 = DAT_00a24314;

  uRam00000004 = DAT_00a24318;

  uRam00000008 = DAT_00a2431c;

  uRam0000000c = DAT_00a24320;

  uRam00000010 = DAT_00a24324;

  uRam00000014 = DAT_00a24328;

  FUN_00746d00();

  uVar3 = FUN_00967060(unaff_EBX);

  FUN_0044c3c0(0,0);

  puVar9 = &DAT_00a2432c;

  puVar10 = (uint32_t /* width from decompiler */ *)0x0;

  for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar10 = *puVar9;

    puVar9 = puVar9 + 1;

    puVar10 = puVar10 + 1;

  }

  FUN_00746d00();

  uVar4 = FUN_00967060(unaff_EBX);

  FUN_0044c3c0(0,0);

  puVar9 = &DAT_00a2434c;

  puVar10 = (uint32_t /* width from decompiler */ *)0x0;

  for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar10 = *puVar9;

    puVar9 = puVar9 + 1;

    puVar10 = puVar10 + 1;

  }

  FUN_00746d00();

  uVar5 = FUN_00967060(unaff_EBX);

  FUN_0044c3c0(0,0);

  puVar9 = &DAT_00a24374;

  puVar10 = (uint32_t /* width from decompiler */ *)0x0;

  for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar10 = *puVar9;

    puVar9 = puVar9 + 1;

    puVar10 = puVar10 + 1;

  }

  FUN_00746d00();

  uVar6 = FUN_00967060(unaff_EBX);

  FUN_0044c3c0(0,0);

  puVar9 = &DAT_00a243a4;

  puVar10 = (uint32_t /* width from decompiler */ *)0x0;

  for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {

    *puVar10 = *puVar9;

    puVar9 = puVar9 + 1;

    puVar10 = puVar10 + 1;

  }

  FUN_00746d00();

  uVar7 = FUN_00967060(unaff_EBX);

  FUN_00414b60();

  ExceptionList = local_c;

  return uVar7 | uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6;

}
