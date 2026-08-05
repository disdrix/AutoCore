// =============================================================================
// FUN_004f4870
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4870
// Address:   0x004f4870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __fastcall FUN_004f4870(int param_1)

{
  int *piVar1;
  char cVar2;
  uint32_t /* width from decompiler */ uVar3;
  char *pcVar4;
  uint uVar5;
  uint8_t *puVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  uint32_t /* width from decompiler */ *puVar10;
  uint32_t /* width from decompiler */ *puVar11;
  char cStack_235;
  int *piStack_230;
  uint8_t local_22c [4];
  char acStack_228 [2];
  uint32_t /* width from decompiler */ uStack_226;
  char acStack_124 [4];
  char acStack_120 [4];
  char acStack_11c [4];
  char acStack_118 [256];
  void *pvStack_18;
  void *pvStack_14;
  uint8_t *puStack_10;
  uint32_t /* width from decompiler */ uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009a2c8d;
  pvStack_14 = ExceptionList;
  local_22c = (uint8_t  [4])(param_1 + 0x40);
  ExceptionList = &pvStack_14;
  (**(code **)(*(int *)(param_1 + 0x40) + 4))();
  piStack_230 = operator_new(0x14c);
  uStack_c = 0;
  if (piStack_230 == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00764030();
  }
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = uVar3;
  uStack_c = 0xffffffff;
  _snprintf(acStack_120,0x104,"%S_key",
            *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) + 0x10);
  acStack_228[0] = '\0';
  acStack_228[1] = '\0';
  puVar10 = &uStack_226;
  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *(uint16_t *)puVar10 = 0;
  pcVar4 = acStack_120;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  uVar5 = (int)pcVar4 - (int)acStack_120;
  pcVar4 = local_22c + 3;
  do {
    pcVar9 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
  } while (*pcVar9 != '\0');
  pcVar9 = acStack_120;
  for (uVar8 = uVar5 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar4 = pcVar4 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar4 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar4 = pcVar4 + 1;
  }
  puVar10 = (uint32_t /* width from decompiler */ *)(local_22c + 3);
  do {
    puVar11 = puVar10;
    puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);
  } while (*(char *)((int)puVar11 + 1) != '\0');
  pcVar4 = acStack_228;
  *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a28904;
  uVar3 = 0xffffffff;
  *(uint8_t *)((int)puVar11 + 5) = DAT_00a28908;
  FUN_007b6a20(pcVar4,0xffffffff);
  cVar2 = FUN_007b6730(pcVar4,uVar3);
  if (cVar2 == '\0') {
    acStack_120[0] = s_generic_key_009cd13c[0];
    acStack_120[1] = s_generic_key_009cd13c[1];
    acStack_120[2] = s_generic_key_009cd13c[2];
    acStack_120[3] = s_generic_key_009cd13c[3];
    acStack_11c[0] = s_generic_key_009cd13c[4];
    acStack_11c[1] = s_generic_key_009cd13c[5];
    acStack_11c[2] = s_generic_key_009cd13c[6];
    acStack_11c[3] = s_generic_key_009cd13c[7];
    acStack_118[0] = s_generic_key_009cd13c[8];
    acStack_118[1] = s_generic_key_009cd13c[9];
    acStack_118[2] = s_generic_key_009cd13c[10];
    acStack_118[3] = s_generic_key_009cd13c[0xb];
    iVar7 = 0;
    do {
      pcVar4 = acStack_120 + iVar7;
      acStack_228[iVar7] = *pcVar4;
      iVar7 = iVar7 + 1;
    } while (*pcVar4 != '\0');
    puVar10 = (uint32_t /* width from decompiler */ *)(local_22c + 3);
    do {
      puVar11 = puVar10;
      puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar11 + 1);
    } while (*(char *)((int)puVar11 + 1) != '\0');
    *(uint32_t /* width from decompiler */ *)((int)puVar11 + 1) = DAT_00a28904;
    *(uint8_t *)((int)puVar11 + 5) = DAT_00a28908;
  }
  piVar1 = *(int **)(param_1 + 0x48);
  FUN_00989e00(&piStack_230,acStack_228);
  (**(code **)(*piVar1 + 0x5c))(&piStack_230);
  pcVar4 = acStack_124;
  iVar7 = (param_1 + 0x3dc) - (int)pcVar4;
  do {
    cVar2 = *pcVar4;
    pcVar4[iVar7] = cVar2;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  puVar6 = operator_new(0xc);
  *puVar6 = 1;
  *(int *)(puVar6 + 4) = *(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1;
  cStack_235 = (char)((uint)&stack0xfffffffc >> 0x18);
  *(uint8_t **)(*(int *)(param_1 + 0x48) + 0x78) = puVar6;
  if (cStack_235 != '\0') {
    (**(code **)(*piStack_230 + 0x18))(1);
  }
  ExceptionList = pvStack_18;
  return;
}
