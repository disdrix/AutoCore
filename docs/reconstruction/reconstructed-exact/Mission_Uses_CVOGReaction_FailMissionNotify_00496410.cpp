// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_0074b580×2, CONCAT31, CVOGReaction_FailMissionNotify, FUN_00410420, FUN_00496410, FUN_0074b8f0, FUN_0074ba00, FUN_00787f90.
//  - Return sites: 1.

// =============================================================================
// Mission_Uses_CVOGReaction_FailMissionNotify_00496410
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "CVOGReaction_FailMissionNotify"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_00496410 clean capture (not modernized).
//
// Address:  0x00496410  (autoassault.exe, image base 0x400000)
// Stable:   aa_00496410
// Stable ID: aa_00496410
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_00496410_*.md
//           Original Ghidra symbol: FUN_00496410
//
// Exactness: Body mirrors reconstructed-exact/FUN_00496410*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_CVOGReaction_FailMissionNotify_00496410
// -----------------------------------------------------------------------------
// Stable ID: aa_00496410
// Address:   0x00496410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "CVOGReaction_FailMissionNotify"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint8_t __thiscall Mission_Uses_CVOGReaction_FailMissionNotify_00496410(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int *piVar5;

  char *pcVar6;

  char cVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint8_t local_171;

  int iStack_15c;

  float fStack_158;

  float fStack_154;

  float fStack_150;

  float fStack_14c;

  float fStack_148;

  float fStack_144;

  uint32_t /* width from decompiler */ auStack_140 [5];

  float fStack_12c;

  float fStack_128;

  float fStack_124;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009a0c97;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_00972cc0();

  FUN_0074ba00();

  local_14 = 0;

  FUN_0074b8f0(param_2,param_3);

  FUN_00410420(0,0);

  piVar10 = *(int **)(param_1 + 0xac);

  piVar4 = *(int **)(param_1 + 0xb0);

  local_171 = 0;

  for (; piVar10 != piVar4; piVar10 = piVar10 + 1) {

    piVar5 = (int *)*piVar10;

    iVar8 = (**(code **)(*piVar5 + 0xc))();

    fVar1 = *(float *)(iVar8 + 0x90);

    fVar2 = *(float *)(iVar8 + 0x94);

    fVar3 = *(float *)(iVar8 + 0x98);

    puVar9 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar5 + 0x48))();

    puVar11 = auStack_140;

    for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {

      *puVar11 = *puVar9;

      puVar9 = puVar9 + 1;

      puVar11 = puVar11 + 1;

    }

    fStack_154 = fStack_128 + fVar2;

    fStack_150 = fStack_124 + fVar3;

    fStack_148 = fStack_11c + fVar2;

    fStack_158 = fStack_12c + fVar1;

    fStack_144 = fStack_118 + fVar3;

    fStack_14c = fStack_120 + fVar1;

    local_14 = CONCAT31(local_14._1_3_,1);

    cVar7 = FUN_00787f90(param_2,param_3,&fStack_158,&fStack_14c);

    if ((((cVar7 != '\0') && (pcVar6 = (char *)piVar5[0x1e], pcVar6 != (char *)0x0)) &&

        (*pcVar6 == '\x01')) && (*(int *)(pcVar6 + 4) != 0)) {

      iStack_15c = *(int *)(pcVar6 + 4);

      CVOGReaction_FailMissionNotify(&iStack_15c);

      local_171 = 1;

    }

    local_14 = local_14 & 0xffffff00;

    FUN_0074b580();

  }

  local_14 = 0xffffffff;

  FUN_0074b580();

  ExceptionList = pvStack_1c;

  return local_171;

}
