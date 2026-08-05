// =============================================================================
// FUN_008c7700
// -----------------------------------------------------------------------------
// Stable ID: aa_008c7700
// Address:   0x008c7700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c7700 @ 0x008c7700
// Stable ID: aa_008c7700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×13, goto×6, return×4, switch×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_004027f0, FUN_00755ab0, FUN_008c7700.
//  - Return sites: 4.

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

void FUN_008c7700(int *param_1,int param_2)



{

  ushort uVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  float unaff_ESI;

  int unaff_EDI;

  float fVar6;

  float local_5c;

  int local_58;

  int local_54;

  int local_50;

  int local_4c;

  uint8_t auStack_40 [4];

  uint8_t auStack_3c [4];

  uint8_t auStack_38 [16];

  uint8_t auStack_28 [4];

  uint8_t auStack_24 [4];

  uint8_t auStack_20 [4];

  uint8_t auStack_1c [12];

  uint8_t auStack_10 [12];

  

  if (param_1 == (int *)0x0) {

    return;

  }

  if (*(int *)(unaff_EDI + 0x54c) == 0) {

    return;

  }

  if (*param_1 == 0) {

    return;

  }

  switch(param_2) {

  case 0:

  case 1:

    if (*(int *)(unaff_EDI + 0x55c) != 0) {

      iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x55c) + 0x120))(&local_58,1,0);

      unaff_ESI = (float)*(int *)(iVar5 + 4);

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x55c) + 0x120))(&local_54,1,0);

      iVar5 = *piVar4;

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x55c) + 0x140))(&local_58,1);

      param_1[1] = (int)(float)(*piVar4 / 2 + iVar5);

LAB_008c78d8:

      param_1[2] = (int)local_5c;

      param_1[3] = 0;

    }

    break;

  case 2:

    if (*(int *)(unaff_EDI + 0x564) != 0) {

      iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x564) + 0x120))(auStack_38,1,0);

      unaff_ESI = (float)*(int *)(iVar5 + 4);

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x564) + 0x120))(auStack_3c,1,0);

      iVar5 = *piVar4;

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x564) + 0x140))(auStack_40,1);

      param_1[1] = (int)(float)(*piVar4 / 2 + iVar5);

      goto LAB_008c78d8;

    }

    break;

  case 3:

    if (*(int *)(unaff_EDI + 0x574) != 0) {

      iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x574) + 0x120))(auStack_20,1,0);

      unaff_ESI = (float)*(int *)(iVar5 + 4);

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x574) + 0x120))(auStack_24,1,0);

      iVar5 = *piVar4;

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x574) + 0x140))(auStack_28,1);

      param_1[1] = (int)(float)(*piVar4 / 2 + iVar5);

      goto LAB_008c78d8;

    }

    break;

  default:

    if (*(int *)(unaff_EDI + 0x2a4) != 0) {

      (**(code **)(**(int **)(unaff_EDI + 0x2a4) + 4))(param_1 + 4,&local_50);

      local_5c = (float)local_4c;

      param_1[1] = (int)(float)local_50;

      goto LAB_008c78d8;

    }

  }

  param_1[10] = param_1[0x15];

  param_1[0xb] = param_1[0x16];

  param_1[0xc] = 0;

  piVar4 = DAT_00d1b8f0;

  if (param_2 != 4) {

    param_1[1] = (int)((float)param_1[0x13] + (float)param_1[1]);

    param_1[2] = (int)((float)param_1[0x14] + (float)param_1[2]);

    piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x54c) + 0x120))(auStack_10,1,0);

    param_1[1] = (int)((float)param_1[1] - (float)*piVar4);

    iVar5 = (**(code **)(**(int **)(unaff_EDI + 0x54c) + 0x120))(auStack_1c,1,0);

    param_1[2] = (int)((float)param_1[2] - (float)*(int *)(iVar5 + 4));

    goto LAB_008c7ac4;

  }

  iVar5 = 0;

  local_4c = 0;

  local_58 = 0;

  local_54 = 0;

  if ((((DAT_00d1b8f0 == (int *)0x0) ||

       (cVar3 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar3 == '\0')) || (piVar4[0x199] == 0)) ||

     (cVar3 = (**(code **)(*(int *)piVar4[0x199] + 0x3d8))(), cVar3 == '\0')) {

    iVar2 = *(int *)(unaff_EDI + 0x53c);

LAB_008c79b5:

    if (iVar2 != 0) {

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x53c) + 0x120))(auStack_10,1,1);

      iVar5 = *piVar4;

      local_58 = piVar4[1];

      piVar4 = (int *)(**(code **)(**(int **)(unaff_EDI + 0x53c) + 0x140))(auStack_1c,1);

      goto LAB_008c79ec;

    }

  }

  else {

    iVar2 = piVar4[0x199];

    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x568) == 0)) {

      iVar2 = *(int *)(unaff_EDI + 0x53c);

      goto LAB_008c79b5;

    }

    piVar4 = (int *)(**(code **)(**(int **)(iVar2 + 0x568) + 0x120))(auStack_10,1,1);

    local_58 = piVar4[1];

    iVar5 = *piVar4;

    piVar4 = (int *)(**(code **)(**(int **)((int)unaff_ESI + 0x568) + 0x140))(auStack_1c,1);

LAB_008c79ec:

    local_58 = *piVar4;

    local_54 = piVar4[1];

  }

  fVar6 = g_flOne / (float)param_1[7];

  param_1[10] = (int)(fVar6 * ((float)(iVar5 + local_58 / 2) - (float)param_1[1]));

  param_1[0xb] = (int)(fVar6 * ((float)(local_4c + local_54 / 2) - (float)param_1[2]));

  param_1[0xc] = 0;

LAB_008c7ac4:

  if ((param_1[0x12] & 0x3fffffffU) != 0x3fcb8608) {

    piVar4 = (int *)FUN_00755ab0(auStack_10);

    param_1[1] = (int)((float)param_1[1] - (float)(*piVar4 / 2));

  }

  iVar5 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar5 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + *(int *)(iVar5 + 0xc) * 2);

  *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + 1;

  param_1[1] = (int)((DAT_00a110d8 - (float)((uint)uVar1 % 0xc9) * g_flMultiKillCountBlend) +

                    (float)param_1[1]);

  FUN_004027f0(*(int *)(unaff_EDI + 0x54c) + 0x488);

  return;

}
