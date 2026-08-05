// =============================================================================
// FUN_004ec8b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ec8b0
// Address:   0x004ec8b0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ FUN_004ec8b0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint32_t /* width from decompiler */ uVar6;
  uint uVar7;
  char *pcVar8;
  uint32_t /* width from decompiler */ *puVar9;
  uint32_t /* width from decompiler */ in_stack_00000018;
  uint32_t /* width from decompiler */ uStack_3bc;
  int iStack_3b8;
  uint32_t /* width from decompiler */ uStack_3b4;
  uint32_t /* width from decompiler */ uStack_3b0;
  uint32_t /* width from decompiler */ uStack_3ac;
  uint32_t /* width from decompiler */ uStack_3a8;
  uint32_t /* width from decompiler */ uStack_3a4;
  uint32_t /* width from decompiler */ uStack_3a0;
  uint32_t /* width from decompiler */ uStack_39c;
  uint32_t /* width from decompiler */ uStack_398;
  uint32_t /* width from decompiler */ uStack_394;
  uint8_t auStack_38c [12];
  float fStack_380;
  float fStack_37c;
  float fStack_378;
  float fStack_374;
  uint8_t auStack_33c [3];
  char cStack_339;
  char local_338 [4];
  char local_334 [4];
  char local_330 [4];
  char local_32c [4];
  char local_328 [2];
  char local_326;
  char cStack_231;
  char local_230 [6];
  char local_22a [257];
  uint32_t /* width from decompiler */ uStack_129;
  void *pvStack_20;
  void *local_1c;
  uint8_t *puStack_18;
  uint32_t /* width from decompiler */ uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a2867;
  local_1c = ExceptionList;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)&uStack_129 + (1 - (int)param_1)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  puVar9 = &uStack_129;
  do {
    pcVar2 = (char *)((int)puVar9 + 1);
    puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);
  } while (*pcVar2 != '\0');
  *puVar9 = DAT_009cb318;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)(local_230 + -(int)param_1)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = &cStack_231;
  do {
    pcVar8 = pcVar2;
    pcVar2 = pcVar8 + 1;
  } while (pcVar8[1] != '\0');
  *(uint32_t /* width from decompiler */ *)(pcVar8 + 1) = s__cache_009ccf18._0_4_;
  *(uint16_t *)(pcVar8 + 5) = s__cache_009ccf18._4_2_;
  pcVar8[7] = s__cache_009ccf18[6];
  local_330 = (char  [4])s____physics_planes__00a95ff8._8_4_;
  local_334 = (char  [4])s____physics_planes__00a95ff8._4_4_;
  local_338 = (char  [4])s____physics_planes__00a95ff8._0_4_;
  local_326 = s____physics_planes__00a95ff8[0x12];
  local_328 = (char  [2])s____physics_planes__00a95ff8._16_2_;
  local_32c = (char  [4])s____physics_planes__00a95ff8._12_4_;
  pcVar2 = local_230;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar3 = (int)pcVar2 - (int)local_230;
  pcVar2 = &cStack_339;
  do {
    pcVar8 = pcVar2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (*pcVar8 != '\0');
  pcVar8 = local_230;
  for (uVar7 = uVar3 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar2 = pcVar2 + 1;
  }
  iVar5 = (int)&uStack_129 + 1;
  ExceptionList = &local_1c;
  FUN_007b6a20(iVar5);
  piVar4 = (int *)FUN_007b7420(iVar5);
  if (piVar4 == (int *)0x0) {
    ExceptionList = local_1c;
    return 0;
  }
  iVar5 = (**(code **)(*piVar4 + 0x1c))();
  if (iVar5 == 0) {
    (**(code **)*piVar4)(1);
    FUN_007a4480(1,"Rigid body of object \'%s\' is zero length",param_1);
    ExceptionList = pvStack_20;
    return 0;
  }
  fStack_380 = g_flOne;
  fStack_37c = g_flOne;
  fStack_378 = g_flOne;
  fStack_374 = g_flOne;
  iVar5 = piVar4[1];
  uStack_3ac = 0;
  uVar6 = (**(code **)(*piVar4 + 0x1c))();
  FUN_005f3120(iVar5,uVar6);
  uStack_14 = 0;
  puVar9 = (uint32_t /* width from decompiler */ *)FUN_005f3740(auStack_38c,&fStack_380);
  (**(code **)*piVar4)(1);
  if (puVar9 != (uint32_t /* width from decompiler */ *)0x0) {
    iStack_3b8 = puVar9[1];
    if (iStack_3b8 * 4 < 0x801) {
      if (iStack_3b8 != 0) {
        uStack_3b4 = 0x10;
        uStack_3bc = *puVar9;
        FUN_007a4480(0xffffffff,"$$$$$$New TK cache:%s [%d]\n",auStack_33c,iStack_3b8);
        uStack_3a8 = 0;
        uStack_3a4 = 0;
        uStack_3a0 = 0x80000000;
        uStack_39c = 0;
        uStack_398 = 0;
        uStack_394 = 0x80000000;
        puStack_18 = (uint8_t *)CONCAT31(puStack_18._1_3_,1);
        FUN_006ba870(&uStack_3bc,&uStack_3a8,in_stack_00000018);
        iStack_3b8 = uStack_3a4;
        uStack_3b4 = 0x10;
        uStack_3bc = uStack_3a8;
        FUN_004f34b0();
                    /* WARNING: Subroutine does not return */
        operator_delete(puVar9);
      }
      FUN_007a4480(1,"Rigid body of object \'%s\' is empty or corrupt",param_1);
    }
    else {
      FUN_007a4480(1,"Rigid body of object \'%s\' had too many vertices - max is %d",param_1,0x200);
    }
    FUN_004f34b0();
                    /* WARNING: Subroutine does not return */
    operator_delete(puVar9);
  }
  puStack_18 = (uint8_t *)0xffffffff;
  FUN_005f3160();
  ExceptionList = pvStack_20;
  return uStack_3b0;
}
