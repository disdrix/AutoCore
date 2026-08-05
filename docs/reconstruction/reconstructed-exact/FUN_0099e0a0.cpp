// =============================================================================
// FUN_0099e0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099e0a0
// Address:   0x0099e0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099e0a0 @ 0x0099e0a0
// Stable ID: aa_0099e0a0
// Embedded strings (evidence for future rename):
//   - "PalVisibleBoundingShape.fx"
//   - "SolidMatDiffuse"
//   - "SolidMatEmissive"
//   - "WireMatDiffuse"
//   - "WireMatEmissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×14, return×3.
//  - Notable callees: FUN_00752370×4, FUN_0096fff0×4, FUN_0073d940, FUN_00749d10, FUN_009701d0, FUN_00987a00, FUN_00987a90, FUN_00989e00.
//  - Strings: "PalVisibleBoundingShape.fx"; "SolidMatDiffuse"; "SolidMatEmissive"; "WireMatDiffuse".
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

uint __fastcall FUN_0099e0a0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  uint uVar4;

  uint uVar5;

  int *piVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  int local_70;

  uint8_t local_6c [4];

  uint8_t local_68 [4];

  uint8_t local_64 [4];

  uint8_t local_60 [4];

  float local_5c;

  float local_58;

  float local_54;

  uint8_t local_50 [8];

  void *pvStack_48;

  void *local_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  float local_1c;

  float local_18;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2d11;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00989e00(&local_70,"PalVisibleBoundingShape.fx");

  piVar1 = (int *)(param_1 + 0x20);

  uVar4 = FUN_009701d0(&local_70);

  FUN_00987a00();

  local_4 = 0;

  local_24 = DAT_00d1a6c8;

  local_54 = g_flOne;

  local_2c = DAT_00d1a6c0;

  local_28 = DAT_00d1a6c4;

  local_5c = g_flOne;

  local_58 = g_flOne;

  local_18 = g_flOne;

  local_20 = g_flOne;

  local_1c = g_flOne;

  FUN_00987a90();

  uVar5 = FUN_00749d10(local_50);

  if (*piVar1 == 0) {

    local_70 = -1;

    piVar6 = &local_70;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_6c,"SolidMatDiffuse");

  }

  if (*piVar6 < 0) {

    uVar7 = 0xffffffff;

  }

  else {

    uVar7 = FUN_0096fff0(piVar1,*piVar6);

  }

  if (*piVar1 == 0) {

    local_70 = -1;

    piVar6 = &local_70;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_68,"SolidMatEmissive");

  }

  if (*piVar6 < 0) {

    uVar8 = 0xffffffff;

  }

  else {

    uVar8 = FUN_0096fff0(piVar1,*piVar6);

  }

  if (*piVar1 == 0) {

    local_70 = -1;

    piVar6 = &local_70;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_64,"WireMatDiffuse");

  }

  if (*piVar6 < 0) {

    uVar9 = 0xffffffff;

  }

  else {

    uVar9 = FUN_0096fff0(piVar1,*piVar6);

  }

  if (*piVar1 == 0) {

    local_70 = -1;

    piVar6 = &local_70;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_60,"WireMatEmissive");

  }

  if (*piVar6 < 0) {

    uVar10 = 0xffffffff;

  }

  else {

    uVar10 = FUN_0096fff0(piVar1,*piVar6);

  }

  piVar6 = (int *)FUN_0073d940(*piVar1);

  if (piVar6 != (int *)0x0) {

    piVar6[1] = piVar6[1] + 1;

    if (piVar6[1] == 1) {

      (**(code **)(*piVar6 + 4))();

    }

    piVar3 = (int *)*piVar1;

    if (piVar3 != (int *)0x0) {

      piVar2 = piVar3 + 1;

      *piVar2 = *piVar2 + -1;

      if (*piVar2 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    *piVar1 = (int)piVar6;

  }

  if (local_38 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_38);

  }

  local_38 = (void *)0x0;

  uStack_34 = 0;

  uStack_30 = 0;

  if (pvStack_48 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(pvStack_48);

  }

  ExceptionList = pvStack_c;

  return uVar4 | uVar5 | uVar7 | uVar8 | uVar9 | uVar10;

}
