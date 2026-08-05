// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, goto×1.
//  - Notable callees: FUN_007a4480×2, ABS, CWndVehicle, FUN_0040cf90, FUN_0040d1a0, FUN_0076f5f0, FUN_00833a90, FUN_0099b8b0.
//  - Strings: "no body found to set lookat in CWndVehicle(%s)".
//  - Return sites: 3.

// =============================================================================
// Drive_no_body_found_to_set_lookat_in_CWndVehicle_s
// -----------------------------------------------------------------------------
// Stable ID: aa_00833a90
// Address:   0x00833a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "no body found to set lookat in CWndVehicle(%s)"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Drive_no_body_found_to_set_lookat_in_CWndVehicle_s(void)



{

  int *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  float10 fVar4;

  float10 fVar5;

  float fStack_50;

  uint8_t *puStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint8_t *puStack_44;

  char *pcStack_40;

  float fStack_30;

  float fStack_2c;

  uint8_t auStack_28 [4];

  uint8_t auStack_24 [8];

  float fStack_1c;

  

  iVar1 = (**(code **)(*in_EAX + 0x1a0))();

  if (iVar1 == 0) {

    pcStack_40 = (char *)0x0;

    puStack_44 = (uint8_t *)0x833ac0;

    FUN_007a4480();

    return;

  }

  if (in_EAX[0x142] == 0) {

    piVar3 = (int *)(**(code **)(*in_EAX + 0x290))();

  }

  else {

    piVar3 = *(int **)(in_EAX[0x142] + 0x48);

  }

  if (piVar3 == (int *)0x0) {

    pcStack_40 = "no body found to set lookat in CWndVehicle(%s)";

    puStack_44 = (uint8_t *)0x0;

    uStack_48 = 0x833b06;

    FUN_007a4480();

    return;

  }

  pcStack_40 = (char *)0x833b19;

  puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar3 + 0x48))();

  pcStack_40 = (char *)0x833b22;

  iVar1 = (**(code **)(*piVar3 + 0x48))();

  fStack_2c = ABS(*(float *)(iVar1 + 0xc));

  pcStack_40 = (char *)0x1;

  puStack_44 = auStack_28;

  fStack_30 = g_flLevelUpUiBase_Inferred;

  uStack_48 = 0x833b4a;

  piVar3 = (int *)(**(code **)(*in_EAX + 0x140))();

  uStack_48 = 1;

  puStack_4c = auStack_24;

  fStack_50 = 1.2051746e-38;

  iVar1 = (**(code **)(*in_EAX + 0x140))();

  fStack_50 = 1.4013e-45;

  if (*(int *)(iVar1 + 4) < *piVar3) {

    piVar3 = (int *)(**(code **)(*in_EAX + 0x140))();

    iVar1 = (**(code **)(*in_EAX + 0x140))(&pcStack_40,1);

    iVar1 = *piVar3 / *(int *)(iVar1 + 4);

  }

  else {

    piVar3 = (int *)(**(code **)(*in_EAX + 0x140))(&fStack_2c);

    iVar1 = (**(code **)(*in_EAX + 0x140))(&pcStack_40,1);

    if (*(int *)(iVar1 + 4) <= *piVar3) goto LAB_00833bee;

    piVar3 = (int *)(**(code **)(*in_EAX + 0x140))(&stack0xffffffc4,1);

    iVar1 = (**(code **)(*in_EAX + 0x140))(&fStack_50,1);

    iVar1 = *(int *)(iVar1 + 4) / *piVar3;

  }

  fStack_50 = (float)iVar1 * g_flLevelUpUiBase_Inferred;

LAB_00833bee:

  uStack_48 = *puVar2;

  fVar4 = (float10)fStack_50 * (float10)(float)puStack_4c + (float10)fStack_1c;

  fVar5 = (float10)fcos((float10)(float)in_EAX[0x176] * (float10)DAT_00a27c54);

  puStack_44 = (uint8_t *)(float)(fVar5 * fVar4 + (float10)(float)puVar2[1]);

  fVar5 = (float10)fsin((float10)(float)in_EAX[0x176] * (float10)DAT_00a27c54);

  pcStack_40 = (char *)(float)((float10)(float)puVar2[2] - fVar5 * fVar4);

  FUN_0076f5f0(&stack0xffffffc4,&stack0xffffffc4);

  FUN_0099b8b0(&stack0xffffffc4,&DAT_00afdfc8);

  (**(code **)(*in_EAX + 0x1a0))();

  FUN_0040cf90(&uStack_48);

  FUN_0040d1a0(&fStack_30);

  return;

}
