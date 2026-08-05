// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00758460
// -----------------------------------------------------------------------------
// Stable ID: aa_00758460
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00758460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×9, goto×2, switch×2, for×2, return×1.
//  - Notable callees: block×4, FUN_00440070×2, FUN_004400c0×2, FUN_00440450×2, FUN_00757050×2, FUN_004148e0, FUN_00440560, FUN_00758460.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x007584fe) */

/* WARNING: Removing unreachable block (ram,0x00758507) */

/* WARNING: Removing unreachable block (ram,0x00758be1) */

/* WARNING: Removing unreachable block (ram,0x00758bef) */



uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_VOG_DEBUG_STOP_00758460(int param_1,float param_2,float param_3,float param_4,float param_5,int *param_6,

            uint param_7,uint32_t /* width from decompiler */ param_8,int param_9,int *param_10,uint32_t /* width from decompiler */ param_11,

            uint32_t /* width from decompiler */ param_12)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  float fVar8;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1c31;

  pvStack_c = ExceptionList;

  if ((char)((uint)param_8 >> 0x18) != -1) {

    param_9 = 1;

  }

  local_4 = 0;

  ExceptionList = &pvStack_c;

  FUN_004148e0(param_12);

  iVar2 = *param_6;

  if (iVar2 != 0) {

    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

    if (*(int *)(iVar2 + 8) == 1) {

      (**(code **)(*(int *)(iVar2 + 4) + 4))();

    }

  }

  iVar2 = *param_6;

  fStack_c4 = 0.0;

  fStack_d0 = 0.0;

  fStack_c8 = 0.0;

  fStack_cc = 0.0;

  piVar7 = (int *)0x0;

  if (iVar2 == 0) goto switchD_00758631_caseD_30;

  iVar6 = *(int *)(iVar2 + 0x1c);

  iVar2 = *(int *)(iVar2 + 0x20);

  if (param_10 != (int *)0x0) {

    iVar2 = param_10[3] - param_10[1];

    iVar6 = param_10[2] - *param_10;

  }

  switch(param_7 & 7) {

  case 0:

switchD_0075857a_caseD_0:

    fStack_d0 = g_flOne;

    break;

  case 1:

    fStack_d0 = (param_4 - param_2) / (float)iVar6;

    break;

  case 2:

    fStack_c4 = (g_flOne / (float)iVar6) * param_2;

    fStack_d0 = (g_flOne / (float)iVar6) * param_4;

    break;

  case 4:

    fStack_d0 = (param_4 - param_2) * (float)iVar2;

    fVar8 = (param_5 - param_3) * (float)iVar6;

    if (fStack_d0 <= fVar8) goto switchD_0075857a_caseD_0;

    fStack_d0 = fStack_d0 / fVar8;

  }

  piVar7 = param_10;

  switch(param_7 & 0x70) {

  case 0x10:

    fStack_cc = (param_5 - param_3) / (float)iVar2;

    break;

  case 0x20:

    fStack_c8 = (g_flOne / (float)iVar2) * param_3;

    fStack_cc = (g_flOne / (float)iVar2) * param_5;

    break;

  case 0x40:

    fVar8 = (param_4 - param_2) * (float)iVar2;

    fStack_cc = (param_5 - param_3) * (float)iVar6;

    if (fVar8 < fStack_cc) {

      fStack_cc = fStack_cc / fVar8;

      break;

    }

  case 0:

    fStack_cc = g_flOne;

  }

switchD_00758631_caseD_30:

  if (param_9 == 1) {

    uVar3 = FUN_00440560(param_1 + 0x68);

    FUN_00440450(uVar3);

  }

  else {

    FUN_00440450(param_1 + 4);

  }

  if (piVar7 == (int *)0x0) {

    FUN_00757050(param_1,4);

  }

  else {

    iVar6 = FUN_00440070(fStack_c4);

    iVar4 = FUN_004400c0(fStack_d0);

    iVar2 = FUN_00440070(fStack_c8);

    iVar5 = FUN_004400c0(fStack_cc);

    for (; iVar1 = iVar6, iVar2 <= iVar5 + -1; iVar2 = iVar2 + 1) {

      for (; iVar1 <= iVar4 + -1; iVar1 = iVar1 + 1) {

        FUN_00757050(param_1,4);

      }

    }

  }

  local_4 = 1;

  FUN_0096efd0();

  ExceptionList = pvStack_c;

  return 0;

}
