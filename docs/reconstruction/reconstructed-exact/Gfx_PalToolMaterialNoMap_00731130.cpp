// =============================================================================
// Gfx_PalToolMaterialNoMap_00731130
// -----------------------------------------------------------------------------
// Stable ID: aa_00731130
// Address:   0x00731130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_PalToolMaterialNoMap_00731130 @ 0x00731130
// Stable ID: aa_00731130
// Embedded strings (evidence for future rename):
//   - "PalToolMaterialNoMap.fx"
//   - "MatDiffuse"
//   - "MatAmbient"
//   - "MatSpecular"
//   - "MatEmissive"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×24, return×1.
//  - Notable callees: FUN_00752370×8, FUN_0096fff0×8, FUN_004246a0×2, FUN_00730b50×2, FUN_0073d940×2, FUN_009701d0×2, FUN_00989e00×2, Gfx_PalToolMaterialNoMap_00731130.
//  - Strings: "PalToolMaterialNoMap.fx"; "MatDiffuse"; "MatAmbient"; "MatSpecular".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PalToolMaterialNoMap.fx"
 * Domain alias of FUN_00731130 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint Gfx_PalToolMaterialNoMap_00731130(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint uVar3;

  int *piVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  uint uVar14;

  uint uVar15;

  uint uVar16;

  uint uVar17;

  int *piVar18;

  int local_4;

  

  FUN_00989e00(&local_4,"PalToolMaterialNoMap.fx");

  piVar18 = (int *)(param_1 + 0x34);

  uVar3 = FUN_009701d0(&local_4);

  if (*piVar18 == 0) {

    local_4 = -1;

    piVar4 = &local_4;

  }

  else {

    piVar4 = (int *)FUN_00752370(&local_4,"MatDiffuse");

  }

  uVar8 = 0xffffffff;

  if (*piVar4 < 0) {

    uVar5 = 0xffffffff;

  }

  else {

    uVar5 = FUN_0096fff0(piVar18,*piVar4);

  }

  piVar4 = &local_4;

  if (*piVar18 == 0) {

    local_4 = -1;

  }

  else {

    piVar4 = (int *)FUN_00752370(piVar4,"MatAmbient");

  }

  if (*piVar4 < 0) {

    uVar6 = 0xffffffff;

  }

  else {

    uVar6 = FUN_0096fff0(piVar18,*piVar4);

  }

  if (*piVar18 == 0) {

    local_4 = -1;

    piVar4 = &local_4;

  }

  else {

    piVar4 = (int *)FUN_00752370(&local_4,"MatSpecular");

  }

  if (*piVar4 < 0) {

    uVar7 = 0xffffffff;

  }

  else {

    uVar7 = FUN_0096fff0(piVar18,*piVar4);

  }

  piVar4 = &local_4;

  if (*piVar18 == 0) {

    local_4 = -1;

  }

  else {

    piVar4 = (int *)FUN_00752370(piVar4,"MatEmissive");

  }

  if (-1 < *piVar4) {

    uVar8 = FUN_0096fff0(piVar18,*piVar4);

  }

  uVar9 = FUN_004246a0();

  piVar4 = (int *)FUN_0073d940(*piVar18);

  if (piVar4 != (int *)0x0) {

    piVar4[1] = piVar4[1] + 1;

    if (piVar4[1] == 1) {

      (**(code **)(*piVar4 + 4))();

    }

    piVar2 = (int *)*piVar18;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *piVar18 = (int)piVar4;

  }

  uVar10 = FUN_00730b50(param_1,0);

  FUN_00989e00(&local_4,"PalToolMaterialNoMap.fx");

  piVar4 = (int *)(param_1 + 0x3c);

  uVar11 = FUN_009701d0(&local_4);

  piVar18 = &local_4;

  if (*piVar4 == 0) {

    local_4 = -1;

  }

  else {

    piVar18 = (int *)FUN_00752370(piVar18,"MatDiffuse");

  }

  if (*piVar18 < 0) {

    uVar12 = 0xffffffff;

  }

  else {

    uVar12 = FUN_0096fff0(piVar4,*piVar18);

  }

  if (*piVar4 == 0) {

    local_4 = -1;

    piVar18 = &local_4;

  }

  else {

    piVar18 = (int *)FUN_00752370(&local_4,"MatAmbient");

  }

  if (*piVar18 < 0) {

    uVar13 = 0xffffffff;

  }

  else {

    uVar13 = FUN_0096fff0(piVar4,*piVar18);

  }

  piVar18 = &local_4;

  if (*piVar4 == 0) {

    local_4 = -1;

  }

  else {

    piVar18 = (int *)FUN_00752370(piVar18,"MatSpecular");

  }

  if (*piVar18 < 0) {

    uVar14 = 0xffffffff;

  }

  else {

    uVar14 = FUN_0096fff0(piVar4,*piVar18);

  }

  if (*piVar4 == 0) {

    local_4 = -1;

    piVar18 = &local_4;

  }

  else {

    piVar18 = (int *)FUN_00752370(&local_4,"MatEmissive");

  }

  if (*piVar18 < 0) {

    uVar15 = 0xffffffff;

  }

  else {

    uVar15 = FUN_0096fff0(piVar4,*piVar18);

  }

  uVar16 = FUN_004246a0();

  piVar18 = (int *)FUN_0073d940(*piVar4);

  if (piVar18 != (int *)0x0) {

    piVar18[1] = piVar18[1] + 1;

    if (piVar18[1] == 1) {

      (**(code **)(*piVar18 + 4))();

    }

    piVar2 = (int *)*piVar4;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *piVar4 = (int)piVar18;

  }

  uVar17 = FUN_00730b50(param_1,1);

  return uVar17 | uVar3 | uVar5 | uVar6 | uVar7 | uVar9 | uVar8 | uVar10 | uVar11 | uVar12 | uVar13

                  | uVar14 | uVar16 | uVar15;

}
