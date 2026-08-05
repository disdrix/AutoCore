// =============================================================================
// FUN_004ea350
// -----------------------------------------------------------------------------
// Stable ID: aa_004ea350
// Address:   0x004ea350  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */
FUN_004ea350(int param_1,float *param_2,float param_3,uint32_t /* width from decompiler */ param_4,int param_5,
            uint32_t /* width from decompiler */ param_6)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  uint32_t /* width from decompiler */ *puVar4;
  uint32_t /* width from decompiler */ *puVar5;
  int *piVar6;
  int iVar7;
  uint32_t /* width from decompiler */ *puStack_a24;
  uint32_t /* width from decompiler */ uStack_a20;
  uint32_t /* width from decompiler */ *puStack_a1c;
  int iStack_a18;
  int *piStack_a14;
  int iStack_a10;
  int *local_a0c;
  uint32_t /* width from decompiler */ *puStack_a04;
  uint32_t /* width from decompiler */ uStack_a00;
  uint8_t auStack_9f9 [9];
  float local_9f0;
  float local_9ec;
  float local_9e8;
  float local_9e4;
  float local_9e0;
  float local_9dc;
  float local_9d8;
  float local_9d4;
  uint8_t auStack_9d0 [12];
  uint8_t auStack_9c4 [4];
  uint8_t auStack_9c0 [4];
  uint8_t auStack_9bc [4];
  uint32_t /* width from decompiler */ uStack_9b8;
  uint32_t /* width from decompiler */ *puStack_9b4;
  uint32_t /* width from decompiler */ local_9b0;
  float local_990;
  float local_98c;
  float local_988;
  float local_984;
  float local_980;
  float local_97c;
  float local_978;
  float local_974;
  float fStack_968;
  float fStack_964;
  float fStack_960;
  float fStack_95c;
  undefined **ppuStack_958;
  uint8_t uStack_954;
  uint8_t *puStack_950;
  int iStack_94c;
  uint32_t /* width from decompiler */ uStack_948;
  uint8_t auStack_944 [268];
  int iStack_838;
  uint32_t /* width from decompiler */ *puStack_834;
  uint8_t *local_830;
  uint32_t /* width from decompiler */ local_82c;
  uint32_t /* width from decompiler */ local_828;
  uint8_t local_824 [2048];
  void *pvStack_24;
  void *pvStack_1c;
  uint8_t *puStack_18;
  uint32_t /* width from decompiler */ local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a271c;
  pvStack_1c = ExceptionList;
  if (param_5 == 1) {
    ExceptionList = &pvStack_1c;
    FUN_0058e0b0();
    local_984 = param_2[3];
    local_990 = *param_2 - param_3;
    local_98c = param_2[1] - param_3;
    local_988 = param_2[2] - param_3;
    local_9b0 = param_6;
    local_980 = *param_2 + param_3;
    local_97c = param_2[1] + param_3;
    local_978 = param_2[2] + param_3;
    local_14 = 5;
    local_974 = local_984;
    piStack_a14 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(0x90,0x2c);
    *(uint16_t *)(piStack_a14 + 1) = 0x90;
    pvStack_1c._0_1_ = 6;
    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00581220(&uStack_9b8);
    pvStack_1c._0_1_ = 5;
    FUN_0055ff20(puVar4);
    puStack_a1c = (uint32_t /* width from decompiler */ *)FUN_0058d9c0();
    *(uint8_t *)((int)puStack_a1c + 0x29) = 1;
    puStack_a1c[1] = puStack_a1c;
    *puStack_a1c = puStack_a1c;
    puStack_a1c[2] = puStack_a1c;
    iStack_a18 = 0;
    pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,7);
    FUN_004ead30(puVar4[0x21]);
    iStack_a10 = 0;
    if (0 < (int)puVar4[0x21]) {
      do {
        iVar7 = *(int *)(*(int *)(puVar4[0x20] + iStack_a10 * 4) + 0x20);
        if (((iVar7 != 0) && (FUN_0040afb0(&piStack_a14,1), piStack_a14 != (int *)0x0)) &&
           (puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*piStack_a14 + 0x1c8))(), puStack_a24 = puVar5,
           puVar5 != (uint32_t /* width from decompiler */ *)0x0)) {
          piVar2 = (int *)(iVar7 + 0xc);
          if (((piVar2 != (int *)0x0) && (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)) &&
             (iVar7 = (**(code **)(*piVar2 + 0x14))(), iVar7 == 10)) {
            piVar2 = (int *)FUN_004cba00(auStack_9c4,*(int *)(puVar5[1] + 4) + 0x164 + (int)puVar5);
            if ((uint32_t /* width from decompiler */ *)*piVar2 != puStack_a1c) goto LAB_004eab7b;
            puVar5 = (uint32_t /* width from decompiler */ *)FUN_004cc400(*(int *)(puVar5[1] + 4) + 0x164 + (int)puVar5);
            *puVar5 = 1;
          }
          FUN_004eae00(&puStack_a24);
        }
LAB_004eab7b:
        iStack_a10 = iStack_a10 + 1;
      } while (iStack_a10 < (int)puVar4[0x21]);
    }
    FUN_00560020(puVar4);
    *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1;
    if (*(short *)((int)puVar4 + 6) == 0) {
      (**(code **)*puVar4)(1);
    }
    pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,5);
    FUN_004cbaa0(&piStack_a14,*puStack_a1c,puStack_a1c);
                    /* WARNING: Subroutine does not return */
    operator_delete(puStack_a1c);
  }
  if (param_5 == 2) {
    ExceptionList = &pvStack_1c;
    piStack_a14 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(0x10,0x22);
    *(uint16_t *)(piStack_a14 + 1) = 0x10;
    pvStack_1c = (void *)0x0;
    puVar4 = (uint32_t /* width from decompiler */ *)FUN_006c7fa0(param_3);
    pvStack_1c = (void *)0xffffffff;
    FUN_005eb8d0();
    fStack_968 = *param_2;
    fStack_964 = param_2[1];
    fStack_960 = param_2[2];
    fStack_95c = param_2[3];
    uStack_9b8 = param_6;
    pvStack_1c = (void *)0x1;
    puStack_9b4 = puVar4;
    puStack_a1c = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x2c);
    *(uint16_t *)(puStack_a1c + 1) = 0xd0;
    pvStack_24._0_1_ = 2;
    puVar5 = (uint32_t /* width from decompiler */ *)FUN_005ebec0(auStack_9c0);
    *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1;
    pvStack_24._0_1_ = 1;
    if (*(short *)((int)puVar4 + 6) == 0) {
      (**(code **)*puVar4)(1);
    }
    puStack_950 = auStack_944;
    ppuStack_958 = &PTR_FUN_009ccbb4;
    uStack_948 = 0x80000010;
    iStack_94c = 0;
    uStack_954 = 0;
    pvStack_24._0_1_ = 3;
    FUN_00560c90(puVar5 + 3,&ppuStack_958,0);
    puStack_a24 = (uint32_t /* width from decompiler */ *)FUN_0058d9c0();
    *(uint8_t *)((int)puStack_a24 + 0x29) = 1;
    puStack_a24[1] = puStack_a24;
    *puStack_a24 = puStack_a24;
    puStack_a24[2] = puStack_a24;
    uStack_a20 = 0;
    pvStack_24 = (void *)CONCAT31(pvStack_24._1_3_,4);
    FUN_004ead30(iStack_94c);
    iStack_a18 = 0;
    if (0 < iStack_94c) {
      piStack_a14 = (int *)0x0;
      do {
        piVar2 = *(int **)(puStack_950 + (int)piStack_a14);
        if ((piVar2 == (int *)0x0) || (piVar2 == puVar5 + 3)) {
          piVar2 = *(int **)(puStack_950 + (int)(piStack_a14 + 2));
        }
        if ((piVar2 != (int *)0x0) && (piVar2 != puVar5 + 3)) {
          piVar6 = (int *)FUN_0040afb0(&local_9d4,1);
          if (((int *)*piVar6 != (int *)0x0) &&
             (iVar7 = (**(code **)(*(int *)*piVar6 + 0x1c8))(), iVar7 != 0)) {
            if (((int *)*piVar2 != (int *)0x0) &&
               (iVar3 = (**(code **)(*(int *)*piVar2 + 0x14))(), iVar3 == 10)) {
              piVar2 = (int *)FUN_004cba00(auStack_9d0,
                                           *(int *)(*(int *)(iVar7 + 4) + 4) + 0x164 + iVar7);
              if ((uint32_t /* width from decompiler */ *)*piVar2 != puStack_a24) goto LAB_004ea8fa;
              puVar4 = (uint32_t /* width from decompiler */ *)FUN_004cc400(*(int *)(*(int *)(iVar7 + 4) + 4) + 0x164 + iVar7)
              ;
              *puVar4 = 1;
            }
            FUN_004eae00(&stack0xfffff5d4);
          }
        }
LAB_004ea8fa:
        iStack_a18 = iStack_a18 + 1;
        piStack_a14 = piStack_a14 + 4;
      } while (iStack_a18 < iStack_94c);
    }
    *(short *)((int)puVar5 + 6) = *(short *)((int)puVar5 + 6) + -1;
    if (*(short *)((int)puVar5 + 6) == 0) {
      (**(code **)*puVar5)(1);
    }
    pvStack_24 = (void *)CONCAT31(pvStack_24._1_3_,3);
    FUN_004cbaa0(&puStack_a1c,*puStack_a24,puStack_a24);
                    /* WARNING: Subroutine does not return */
    operator_delete(puStack_a24);
  }
  local_a0c = DAT_00d1f040;
  ExceptionList = &pvStack_1c;
  FUN_0076cf00("CVOGPhysicsUtils::GetObjectsInArea::aabb");
  local_9e4 = param_2[3];
  local_9f0 = *param_2 - param_3;
  local_9ec = param_2[1] - param_3;
  local_9e8 = param_2[2] - param_3;
  local_830 = local_824;
  local_9e0 = *param_2 + param_3;
  local_9dc = param_2[1] + param_3;
  local_9d8 = param_2[2] + param_3;
  local_82c = 0;
  local_828 = 0x80000100;
  local_14 = 9;
  local_9d4 = local_9e4;
  (**(code **)(**(int **)(*(int *)(param_1 + 0xe4a4) + 0xc4) + 0x24))(&local_9f0,&local_830);
  if (*(int *)(*(int *)(param_1 + 0xe4a4) + 0xd0) == 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
    pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,8);
    if (-1 < (int)local_830) {
      (**(code **)(*DAT_00b05060 + 0x14))(iStack_838,(int)local_830 * 8,0x12);
    }
    pvStack_1c = (void *)0xffffffff;
    FUN_0076cef0();
    ExceptionList = pvStack_24;
    return 0;
  }
  puStack_a04 = (uint32_t /* width from decompiler */ *)FUN_0058d9c0();
  *(uint8_t *)((int)puStack_a04 + 0x29) = 1;
  puStack_a04[1] = puStack_a04;
  *puStack_a04 = puStack_a04;
  puStack_a04[2] = puStack_a04;
  uStack_a00 = 0;
  pvStack_1c._0_1_ = 10;
  if (-1 < (int)puStack_834 + -1) {
    local_a0c = (int *)(iStack_838 + 4);
    puStack_a24 = puStack_834;
    do {
      if (*local_a0c == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *local_a0c + -0x10;
      }
      pcVar1 = (char *)FUN_006c6c50(auStack_9f9,*(uint32_t /* width from decompiler */ *)(iVar7 + 0x1c),param_6);
      if ((*pcVar1 != '\0') && (iVar7 = *(int *)(iVar7 + 0x20), iVar7 != 0)) {
        piVar2 = (int *)FUN_0040afb0(auStack_9c0,1);
        if (((int *)*piVar2 != (int *)0x0) &&
           (iVar3 = (**(code **)(*(int *)*piVar2 + 0x1c8))(), iStack_a10 = iVar3, iVar3 != 0)) {
          piVar2 = (int *)(iVar7 + 0xc);
          if (((piVar2 != (int *)0x0) && (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)) &&
             (iVar7 = (**(code **)(*piVar2 + 0x14))(), iVar7 == 10)) {
            piVar2 = (int *)FUN_004cba00(auStack_9bc,
                                         *(int *)(*(int *)(iVar3 + 4) + 4) + 0x164 + iVar3);
            if ((uint32_t /* width from decompiler */ *)*piVar2 != puStack_a04) goto LAB_004ea612;
            puVar4 = (uint32_t /* width from decompiler */ *)FUN_004cc400(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x164 + iVar3);
            *puVar4 = 1;
          }
          FUN_004eae00(&iStack_a10);
        }
      }
LAB_004ea612:
      local_a0c = local_a0c + 2;
      puStack_a24 = (uint32_t /* width from decompiler */ *)((int)puStack_a24 + -1);
    } while (puStack_a24 != (uint32_t /* width from decompiler */ *)0x0);
    puStack_a24 = (uint32_t /* width from decompiler */ *)0x0;
  }
  pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,9);
  FUN_004cbaa0(&puStack_a24,*puStack_a04,puStack_a04);
                    /* WARNING: Subroutine does not return */
  operator_delete(puStack_a04);
}
