// =============================================================================
// Gfx_PalDiffMap
// -----------------------------------------------------------------------------
// Stable ID: aa_0073cb70
// Address:   0x0073cb70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_PalDiffMap @ 0x0073cb70
// Stable ID: aa_0073cb70
// Embedded strings (evidence for future rename):
//   - "PalDiffMap.fx"
//   - "DiffuseMap"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_004367f0, FUN_00457a00, Gfx_PalDiffMap, FUN_00748960, FUN_00749d10, FUN_00752310, FUN_00764030, FUN_007647c0.
//  - Strings: "PalDiffMap.fx"; "DiffuseMap".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PalDiffMap.fx"
 * Domain alias of FUN_0073cb70 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Gfx_PalDiffMap(void)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  void **ppvVar4;

  int *piVar5;

  int unaff_EDI;

  void *local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint8_t local_54 [48];

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  float local_18;

  void *pvStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2fcf;

  local_c = ExceptionList;

  piVar5 = (int *)0x0;

  if (*(int *)(unaff_EDI + 0x4c) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(unaff_EDI + 0x50) - *(int *)(unaff_EDI + 0x4c) >> 2;

  }

  uVar1 = *(uint *)(unaff_EDI + 0x44);

  if (uVar1 < uVar2) {

    uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x4c) + uVar1 * 4);

    *(uint *)(unaff_EDI + 0x44) = uVar1 + 1;

    return uVar3;

  }

  ExceptionList = &local_c;

  local_60 = operator_new(0x14c);

  local_4 = 0;

  if (local_60 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00764030();

  }

  local_4 = 0xffffffff;

  local_60 = operator_new(0xc4);

  local_4 = 1;

  if (local_60 != (void *)0x0) {

    piVar5 = (int *)FUN_00748960();

  }

  local_4 = 0xffffffff;

  FUN_00989e00(&local_60,"PalDiffMap.fx");

  FUN_009701d0(&local_60);

  ppvVar4 = &local_60;

  if (piVar5[8] == 0) {

    local_60 = (void *)0xffffffff;

  }

  else {

    ppvVar4 = (void **)FUN_00752310(ppvVar4,"DiffuseMap");

  }

  local_60 = *ppvVar4;

  if (-1 < (int)local_60) {

    local_4 = 2;

    local_5c = 0x10;

    local_58 = 0x10;

    FUN_0096f0e0(0x16,&local_5c,1,1,1,0);

    FUN_00970060(local_60,0);

    local_4 = 0xffffffff;

    FUN_0096efd0();

  }

  FUN_0098ef00(local_54);

  local_4 = 3;

  local_20 = DAT_00d1a6c4;

  local_24 = DAT_00d1a6c0;

  local_1c = DAT_00d1a6c8;

  local_18 = g_flMultiKillCountBlend;

  FUN_0098f2b0(200);

  FUN_00749d10(local_54);

  (**(code **)(*piVar5 + 0x5c))();

  FUN_007647c0(piVar5);

  FUN_004367f0(*(int *)(unaff_EDI + 0x44) + 1,0);

  *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x4c) + *(int *)(unaff_EDI + 0x44) * 4) = uVar3;

  *(int *)(unaff_EDI + 0x44) = *(int *)(unaff_EDI + 0x44) + 1;

  local_4 = 0xffffffff;

  FUN_00457a00(local_54);

  ExceptionList = pvStack_10;

  return uVar3;

}
