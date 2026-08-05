// =============================================================================
// Gfx_PalToolMaterialNoMap_0099eb60
// -----------------------------------------------------------------------------
// Stable ID: aa_0099eb60
// Address:   0x0099eb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_PalToolMaterialNoMap_0099eb60 @ 0x0099eb60
// Stable ID: aa_0099eb60
// Embedded strings (evidence for future rename):
//   - "PalToolMaterialNoMap.fx"
//   - "DepthBias"
//   - "MatDiffuse"
//   - "MatSpecular"
//   - "MatEmissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×12, return×2.
//  - Notable callees: FUN_00752370×3, FUN_0096fff0×3, FUN_00442640, FUN_0046b7c0, FUN_0073d940, FUN_00749d10, FUN_009701d0, FUN_00989e00.
//  - Strings: "PalToolMaterialNoMap.fx"; "DepthBias"; "MatDiffuse"; "MatSpecular".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PalToolMaterialNoMap.fx"
 * Domain alias of FUN_0099eb60 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Gfx_PalToolMaterialNoMap_0099eb60(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int local_34;

  float local_30;

  uint8_t local_2c [4];

  uint8_t local_28 [4];

  uint8_t local_24 [4];

  undefined **local_20 [2];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2d65;

  pvStack_c = ExceptionList;

  if ((_DAT_00d21854 & 1) == 0) {

    _DAT_00d21854 = _DAT_00d21854 | 1;

    _DAT_00d21844 = g_flOne;

    _DAT_00d21848 = g_flOne;

    _DAT_00d2184c = g_flOne;

    _DAT_00d21850 = g_flOne;

  }

  ExceptionList = &pvStack_c;

  FUN_00989e00(&local_34,"PalToolMaterialNoMap.fx");

  piVar5 = (int *)(param_1 + 0x20);

  FUN_009701d0(&local_34);

  local_30 = g_flMsToSeconds_Inferred;

  FUN_00442640("DepthBias",&local_30);

  if (*piVar5 == 0) {

    local_34 = -1;

    piVar3 = &local_34;

  }

  else {

    piVar3 = (int *)FUN_00752370(local_2c,"MatDiffuse");

  }

  if (-1 < *piVar3) {

    FUN_0096fff0(piVar5,*piVar3);

  }

  if (*piVar5 == 0) {

    local_34 = -1;

    piVar3 = &local_34;

  }

  else {

    piVar3 = (int *)FUN_00752370(local_28,"MatSpecular");

  }

  if (-1 < *piVar3) {

    FUN_0096fff0(piVar5,*piVar3);

  }

  if (*piVar5 == 0) {

    local_34 = -1;

    piVar3 = &local_34;

  }

  else {

    piVar3 = (int *)FUN_00752370(local_24,"MatEmissive");

  }

  if (-1 < *piVar3) {

    FUN_0096fff0(piVar5,*piVar3);

  }

  piVar3 = (int *)FUN_0073d940(*piVar5);

  if (piVar3 != (int *)0x0) {

    piVar3[1] = piVar3[1] + 1;

    if (piVar3[1] == 1) {

      (**(code **)(*piVar3 + 4))();

    }

    piVar2 = (int *)*piVar5;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *piVar5 = (int)piVar3;

  }

  local_20[0] = &PTR_LAB_00aa6c6c;

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 1;

  FUN_0046b7c0();

  uVar4 = FUN_00749d10(local_20);

  if (local_18 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  ExceptionList = pvStack_c;

  return uVar4;

}
