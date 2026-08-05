// =============================================================================
// Gfx_PalDiffMap_0073cd70
// -----------------------------------------------------------------------------
// Stable ID: aa_0073cd70
// Address:   0x0073cd70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_PalDiffMap_0073cd70 @ 0x0073cd70
// Stable ID: aa_0073cd70
// Embedded strings (evidence for future rename):
//   - "PalDiffMap.fx"
//   - "DiffuseMap"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_004367f0, Gfx_PalDiffMap_0073cd70, FUN_00748960, FUN_00749d10, FUN_00752310, FUN_00764030, FUN_007647c0, FUN_0076f5f0.
//  - Strings: "PalDiffMap.fx"; "DiffuseMap".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PalDiffMap.fx"
 * Domain alias of FUN_0073cd70 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Gfx_PalDiffMap_0073cd70(void)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  uint uVar4;

  void **ppvVar5;

  int *piVar6;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_6c;

  void *local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  uint8_t local_50 [8];

  void *pvStack_48;

  float local_3c;

  float local_38;

  float local_34;

  void *local_30;

  float local_2c;

  float local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2fff;

  local_c = ExceptionList;

  piVar6 = (int *)0x0;

  if (*(int *)(unaff_EDI + 0x38) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = *(int *)(unaff_EDI + 0x3c) - *(int *)(unaff_EDI + 0x38) >> 2;

  }

  uVar1 = *(uint *)(unaff_EDI + 0x30);

  if (uVar1 < uVar4) {

    uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x38) + uVar1 * 4);

    *(uint *)(unaff_EDI + 0x30) = uVar1 + 1;

    return uVar2;

  }

  ExceptionList = &local_c;

  local_68 = operator_new(0x14c);

  local_4 = 0;

  if (local_68 == (void *)0x0) {

    local_6c = 0;

  }

  else {

    local_6c = FUN_00764030();

  }

  local_4 = 0xffffffff;

  local_68 = operator_new(0xc4);

  local_4 = 1;

  if (local_68 != (void *)0x0) {

    piVar6 = (int *)FUN_00748960();

  }

  local_4 = 0xffffffff;

  FUN_00989e00(&local_68,"PalDiffMap.fx");

  FUN_009701d0(&local_68);

  ppvVar5 = &local_68;

  if (piVar6[8] == 0) {

    local_68 = (void *)0xffffffff;

  }

  else {

    ppvVar5 = (void **)FUN_00752310(ppvVar5,"DiffuseMap");

  }

  pvVar3 = *ppvVar5;

  if (-1 < (int)pvVar3) {

    local_4 = 2;

    local_68 = (void *)0x10;

    local_64 = 2.24208e-44;

    FUN_0096f0e0(0x16,&local_68,1,1,1,0);

    FUN_00970060(pvVar3,0);

    local_4 = 0xffffffff;

    FUN_0096efd0();

  }

  FUN_00982040();

  local_4 = 3;

  local_68 = DAT_00afe03c;

  local_64 = DAT_00afe040;

  local_60 = DAT_00afe044;

  FUN_0076f5f0(&local_68,&local_68);

  local_5c = (float)local_68 * DAT_00aaab88;

  local_58 = local_64 * DAT_00aaab88;

  local_54 = local_60 * DAT_00aaab88;

  local_18 = DAT_00aaab84;

  local_20 = g_flMultiKillCountBlend;

  local_1c = DAT_00aaab80;

  local_30 = local_68;

  local_2c = local_64;

  local_28 = local_60;

  local_24 = DAT_00a10e78;

  local_3c = local_5c;

  local_38 = local_58;

  local_34 = local_54;

  FUN_00982100(0x24);

  FUN_00749d10(local_50);

  (**(code **)(*piVar6 + 0x5c))();

  FUN_007647c0(piVar6);

  FUN_004367f0(*(int *)(unaff_EDI + 0x30) + 1,0);

  *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x38) + *(int *)(unaff_EDI + 0x30) * 4) = local_6c;

  *(int *)(unaff_EDI + 0x30) = *(int *)(unaff_EDI + 0x30) + 1;

  if (pvStack_48 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvStack_48);

  }

  ExceptionList = local_c;

  return local_6c;

}
