// =============================================================================
// Gfx_PalVisibleBoundingShape_0099e6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099e6c0
// Address:   0x0099e6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_PalVisibleBoundingShape_0099e6c0 @ 0x0099e6c0
// Stable ID: aa_0099e6c0
// Embedded strings (evidence for future rename):
//   - "PalVisibleBoundingShape.fx"
//   - "SolidMatDiffuse"
//   - "SolidMatEmissive"
//   - "WireMatDiffuse"
//   - "WireMatEmissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×12, return×1.
//  - Notable callees: FUN_00752370×4, FUN_0096fff0×4, FUN_00457a00, FUN_0073d940, FUN_00749d10, FUN_009701d0, FUN_00989e00, FUN_0098ef00.
//  - Strings: "PalVisibleBoundingShape.fx"; "SolidMatDiffuse"; "SolidMatEmissive"; "WireMatDiffuse".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PalVisibleBoundingShape.fx"
 * Domain alias of FUN_0099e6c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __fastcall Gfx_PalVisibleBoundingShape_0099e6c0(int param_1)



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

  int local_68;

  uint8_t local_64 [4];

  uint8_t local_60 [4];

  uint8_t local_5c [4];

  uint8_t local_58 [4];

  uint8_t local_54 [48];

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  float local_18;

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2d4b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00989e00(&local_68,"PalVisibleBoundingShape.fx");

  piVar1 = (int *)(param_1 + 0x20);

  uVar4 = FUN_009701d0(&local_68);

  FUN_0098ef00(local_54);

  local_4 = 0;

  local_24 = DAT_00d1a6c0;

  local_20 = DAT_00d1a6c4;

  local_1c = DAT_00d1a6c8;

  local_18 = g_flOne;

  FUN_0098f2b0(200);

  uVar5 = FUN_00749d10(local_54);

  if (*piVar1 == 0) {

    local_68 = -1;

    piVar6 = &local_68;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_64,"SolidMatDiffuse");

  }

  if (*piVar6 < 0) {

    uVar7 = 0xffffffff;

  }

  else {

    uVar7 = FUN_0096fff0(piVar1,*piVar6);

  }

  if (*piVar1 == 0) {

    local_68 = -1;

    piVar6 = &local_68;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_60,"SolidMatEmissive");

  }

  if (*piVar6 < 0) {

    uVar8 = 0xffffffff;

  }

  else {

    uVar8 = FUN_0096fff0(piVar1,*piVar6);

  }

  if (*piVar1 == 0) {

    local_68 = -1;

    piVar6 = &local_68;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_5c,"WireMatDiffuse");

  }

  if (*piVar6 < 0) {

    uVar9 = 0xffffffff;

  }

  else {

    uVar9 = FUN_0096fff0(piVar1,*piVar6);

  }

  if (*piVar1 == 0) {

    local_68 = -1;

    piVar6 = &local_68;

  }

  else {

    piVar6 = (int *)FUN_00752370(local_58,"WireMatEmissive");

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

  local_4 = 0xffffffff;

  FUN_00457a00(local_54);

  ExceptionList = pvStack_10;

  return uVar4 | uVar5 | uVar7 | uVar8 | uVar9 | uVar10;

}
