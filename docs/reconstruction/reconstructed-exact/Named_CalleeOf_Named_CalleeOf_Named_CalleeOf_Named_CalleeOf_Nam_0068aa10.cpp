// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068aa10
// -----------------------------------------------------------------------------
// Stable ID: aa_0068aa10
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068aa10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: FUN_006890c0, FUN_0068aa10, FUN_0068ac5d.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068aa10(int *param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  int *local_18;

  uint8_t *local_14;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009aa232;

  pvStack_10 = ExceptionList;

  local_14 = &stack0xffffff98;

  ExceptionList = &pvStack_10;

  *param_1 = *param_2;

  param_1[1] = param_2[1];

  param_1[2] = param_2[2];

  param_1[3] = param_2[3];

  param_1[4] = param_2[4];

  param_1[5] = param_2[5];

  param_1[6] = param_2[6];

  param_1[7] = param_2[7];

  param_1[8] = param_2[8];

  param_1[9] = param_2[9];

  param_1[10] = param_2[10];

  param_1[0xb] = param_2[0xb];

  param_1[0xc] = param_2[0xc];

  param_1[0xe] = param_2[0xe];

  param_1[0xf] = param_2[0xf];

  param_1[0x10] = param_2[0x10];

  *(char *)(param_1 + 0x11) = (char)param_2[0x11];

  *(uint8_t *)((int)param_1 + 0x45) = *(uint8_t *)((int)param_2 + 0x45);

  param_1[0x12] = param_2[0x12];

  param_1[0x13] = param_2[0x13];

  param_1[0x14] = param_2[0x14];

  param_1[0x15] = param_2[0x15];

  param_1[0x16] = param_2[0x16];

  param_1[0x17] = param_2[0x17];

  *(short *)(param_1 + 0x18) = (short)param_2[0x18];

  param_1[0x19] = param_2[0x19];

  iVar5 = param_1[0xe];

  *(char *)(param_1 + 0x1a) = (char)param_2[0x1a];

  *(uint8_t *)((int)param_1 + 0x69) = *(uint8_t *)((int)param_2 + 0x69);

  iVar6 = *(int *)(iVar5 + 4);

  local_8 = 0;

  local_18 = param_1;

  if ((iVar6 == 0) ||

     ((uint)(*(int *)(iVar5 + 0xc) - iVar6 >> 2) <= (uint)(*(int *)(iVar5 + 8) - iVar6 >> 2))) {

    FUN_006890c0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,&local_18);

  }

  else {

    puVar4 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8);

    puVar3 = puVar4;

    for (iVar6 = 1; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar3 = param_1;

      puVar3 = puVar3 + 1;

    }

    *(uint32_t /* width from decompiler */ **)(iVar5 + 8) = puVar4 + 1;

    local_14 = &stack0xffffff98;

  }

  piVar2 = (int *)param_1[0xc];

  piVar7 = param_2 + 0x1b;

  piVar8 = param_1 + 0x1b;

  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {

    *piVar8 = *piVar7;

    piVar7 = piVar7 + 1;

    piVar8 = piVar8 + 1;

  }

  *piVar2 = *piVar2 + 1;

  puVar4 = operator_new(0x14);

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar4 = 0;

    puVar4[3] = 0;

    puVar4[2] = 0;

    puVar4[1] = 0;

    puVar4[4] = 0x3f800000;

  }

  param_1[0xd] = (int)puVar4;

  *puVar4 = param_2;

  iVar5 = *param_2;

  iVar6 = param_1[0xd];

  *(uint32_t /* width from decompiler */ *)(iVar6 + 4) = *(uint32_t /* width from decompiler */ *)(iVar5 + 4);

  *(uint32_t /* width from decompiler */ *)(iVar6 + 8) = *(uint32_t /* width from decompiler */ *)(iVar5 + 8);

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc);

  if (param_2[0xd] == 0) {

    uVar1 = *(uint32_t /* width from decompiler */ *)(*param_2 + 0x14);

  }

  else {

    uVar1 = *(uint32_t /* width from decompiler */ *)(param_2[0xd] + 0x10);

  }

  *(uint32_t /* width from decompiler */ *)(param_1[0xd] + 0x10) = uVar1;

  DAT_00d08e58 = DAT_00d08e58 + 1;

  FUN_0068ac5d();

  return;

}
