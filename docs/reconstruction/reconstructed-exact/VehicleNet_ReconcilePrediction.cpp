// =============================================================================
// VehicleNet_ReconcilePrediction
// -----------------------------------------------------------------------------
// Stable ID: aa_005f9f10
// Address:   0x005f9f10  (autoassault.exe, image base 0x400000)
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

void __fastcall VehicleNet_ReconcilePrediction(uint param_1)

{
  uint *puVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  uint32_t /* width from decompiler */ uVar7;
  uint32_t /* width from decompiler */ uVar8;
  char *pcVar9;
  uint *puVar10;
  int iStack_50;
  uint uStack_4c;
  uint local_48;
  uint uStack_44;
  uint uStack_40;
  uint32_t /* width from decompiler */ uStack_38;
  uint32_t /* width from decompiler */ uStack_34;
  uint32_t /* width from decompiler */ uStack_30;
  uint32_t /* width from decompiler */ uStack_2c;
  uint8_t auStack_28 [36];
  
  if (((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_1 + 0x60) != 0)) &&
     (*(int *)(param_1 + 0x50) != 0)) {
    local_48 = param_1;
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x50) + 0x1d4))();
    iVar2 = *(int *)(param_1 + 0x5c);
    if (*(char *)((int)piVar4 + 0x103) == '\0') {
      iVar5 = *(int *)(param_1 + 0x7c);
      piVar4[0x52] = iVar5;
      if (iVar5 < piVar4[0x51]) {
        piVar4[0x51] = iVar5;
      }
      if (*(int *)(*(int *)(piVar4[1] + 4) + 0xb0 + (int)piVar4) != 0) {
        uVar8 = 0;
        iVar5 = (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x210))(0);
        if (iVar5 == 0) {
          iVar5 = (**(code **)(**(int **)(*(int *)(piVar4[1] + 4) + 0xb0 + (int)piVar4) + 0x1d8))();
          *(uint8_t *)(iVar5 + 0x26c) = (uint8_t)iStack_50;
        }
        else {
          uVar7 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x80);
          (**(code **)(**(int **)(*(int *)(piVar4[1] + 4) + 0xb0 + (int)piVar4) + 0x1dc))(uVar7);
          FUN_00524680(uVar7);
          (**(code **)(**(int **)(*(int *)(piVar4[1] + 4) + 0xb0 + (int)piVar4) + 0x1dc))();
          FUN_00522f70();
          local_48 = (uint)*(byte *)(*(int *)(param_1 + 0x60) + 0x12a);
          iVar5 = (**(code **)(**(int **)(*(int *)(piVar4[1] + 4) + 0xb0 + (int)piVar4) + 0x1dc))();
          *(uint *)(iVar5 + 0x634) = *(uint *)(iVar5 + 0x634) | 1;
          *(uint *)(iVar5 + 0x6b4) = local_48;
          (**(code **)(**(int **)(*(int *)(piVar4[1] + 4) + 0xb0 + (int)piVar4) + 0x1dc))
                    (*(uint8_t *)(*(int *)(param_1 + 0x60) + 0x128));
          FUN_004c3700(uVar8);
          iVar5 = *(int *)(param_1 + 0xf0);
          if (-1 < iVar5) {
            (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x210))(0,iVar5);
            FUN_00521480(iVar5);
          }
          iVar5 = *(int *)(param_1 + 0xf4);
          if (-1 < iVar5) {
            (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x210))(0,iVar5);
            FUN_005214b0(iVar5);
          }
          pcVar9 = (char *)(param_1 + 0xbc);
          pcVar6 = pcVar9;
          do {
            cVar3 = *pcVar6;
            pcVar6 = pcVar6 + 1;
          } while (cVar3 != '\0');
          uStack_44 = (int)pcVar6 - (param_1 + 0xbd);
          if (uStack_44 != 0) {
            (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x210))(0,pcVar9);
            FUN_00521440(pcVar9);
          }
        }
      }
      (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x240))
                (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x10));
      (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x248))
                (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14));
      if (*(char *)((int)piVar4 + 0x103) == '\0') {
        cVar3 = (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x198))();
        if ((cVar3 == '\0') || (*(char *)(iVar2 + 0x8a) != '\0')) {
          cVar3 = (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x198))();
          if ((cVar3 == '\0') && (*(char *)(iVar2 + 0x8a) != '\0')) {
            (**(code **)(*piVar4 + 0x14))(1);
          }
        }
        else {
          (**(code **)(*piVar4 + 0x14))(0);
          Vehicle_ActivateEnterWorld();
        }
        puVar10 = (uint *)((int)piVar4 + *(int *)(piVar4[1] + 4) + 0x180);
        *puVar10 = *puVar10 ^
                   ((uint)*(byte *)(iVar2 + 0x8a) << 8 ^
                   *(uint *)((int)piVar4 + *(int *)(piVar4[1] + 4) + 0x180)) & 0x100;
        iVar5 = *(int *)(*(int *)(piVar4[1] + 4) + 0xb0 + (int)piVar4);
        if (iVar5 != 0) {
          *(uint *)(iVar5 + 0x17c) =
               *(uint *)(iVar5 + 0x17c) ^
               ((uint)*(byte *)(iVar2 + 0x8a) << 8 ^ *(uint *)(iVar5 + 0x17c)) & 0x100;
        }
      }
      uStack_30 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x6c);
      uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x68);
      uStack_38 = *(uint32_t /* width from decompiler */ *)(iVar2 + 100);
      uStack_2c = 0;
      FUN_00797170(auStack_28);
      Vehicle_setDrivingInputs
                (&uStack_38,auStack_28,&DAT_00d02830,&DAT_00d02830,0,0,1,
                 *(uint8_t *)(iVar2 + 0x8a),0);
      (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x294))
                (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x20));
      FUN_00512460(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c));
      uStack_4c = DAT_009dd1b0;
      uStack_40 = DAT_009dd1bc;
      iVar5 = piVar4[0x96];
      local_48 = DAT_009dd1b4;
      uStack_44 = DAT_009dd1b8;
      if (iVar5 != 0) {
        puVar10 = (uint *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x164 + iVar5);
        uStack_4c = *puVar10;
        local_48 = puVar10[1];
        uStack_44 = puVar10[2];
        uStack_40 = puVar10[3];
      }
      iVar5 = TFID_NotEquals(&uStack_4c,(void *)(iVar2 + 0x4e8));
      if ((char)iVar5 != '\0') {
        iVar5 = TFID_EqualsObjectId((void *)(iVar2 + 0x4e8),&DAT_009dd1b0);
        if (((char)iVar5 == '\0') && (*(int *)(iVar2 + 0x45c) != -1)) {
          VehicleNet_TriggerReplay(iVar2 + 0x458,&uStack_4c,0x158);
        }
        else {
          VehicleNet_PostCorrectionEvent(0,&uStack_4c,0);
        }
      }
      puVar10 = (uint *)(iVar2 + 0x920);
      iStack_50 = 0;
      do {
        uStack_44 = DAT_009dd1b8;
        uStack_40 = DAT_009dd1bc;
        iVar5 = *(int *)(iStack_50 + piVar4[0x98]);
        uStack_4c = DAT_009dd1b0;
        local_48 = DAT_009dd1b4;
        if (iVar5 != 0) {
          puVar1 = (uint *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x164 + iVar5);
          uStack_4c = *puVar1;
          local_48 = puVar1[1];
          uStack_44 = puVar1[2];
          uStack_40 = puVar1[3];
        }
        if (((uStack_4c != *puVar10) || (local_48 != puVar10[1])) ||
           ((char)uStack_44 != (char)puVar10[2])) {
          if ((((*puVar10 & puVar10[1]) == 0xffffffff) && ((char)puVar10[2] == '\0')) ||
             (puVar10[-0x23] == 0xffffffff)) {
            VehicleNet_PostCorrectionEvent(0,&uStack_4c,0);
          }
          else {
            VehicleNet_TriggerReplay(puVar10 + -0x24,&uStack_4c,0x188);
          }
        }
        puVar10 = puVar10 + 0x62;
        iStack_50 = iStack_50 + 4;
      } while (iStack_50 < 0xc);
      local_48 = DAT_009dd1b4;
      uStack_40 = DAT_009dd1bc;
      iVar5 = piVar4[0x99];
      uStack_4c = DAT_009dd1b0;
      uStack_44 = DAT_009dd1b8;
      if (iVar5 != 0) {
        puVar10 = (uint *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x164 + iVar5);
        uStack_4c = *puVar10;
        local_48 = puVar10[1];
        uStack_44 = puVar10[2];
        uStack_40 = puVar10[3];
      }
      if (((uStack_4c != *(uint *)(iVar2 + 0x798)) || (local_48 != *(uint *)(iVar2 + 0x79c))) ||
         ((char)uStack_44 != *(char *)(iVar2 + 0x7a0))) {
        if ((((*(uint *)(iVar2 + 0x798) & *(uint *)(iVar2 + 0x79c)) == 0xffffffff) &&
            (*(char *)(iVar2 + 0x7a0) == '\0')) || (*(int *)(iVar2 + 0x70c) == -1)) {
          VehicleNet_PostCorrectionEvent(0,&uStack_4c,0);
        }
        else {
          VehicleNet_TriggerReplay(iVar2 + 0x708,&uStack_4c,0x188);
        }
      }
      local_48 = DAT_009dd1b4;
      uStack_40 = DAT_009dd1bc;
      iVar5 = piVar4[0x9b];
      uStack_4c = DAT_009dd1b0;
      uStack_44 = DAT_009dd1b8;
      if (iVar5 != 0) {
        puVar10 = (uint *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x164 + iVar5);
        uStack_4c = *puVar10;
        local_48 = puVar10[1];
        uStack_44 = puVar10[2];
        uStack_40 = puVar10[3];
      }
      if (((uStack_4c != *(uint *)(iVar2 + 0x1e8)) || (local_48 != *(uint *)(iVar2 + 0x1ec))) ||
         ((char)uStack_44 != *(char *)(iVar2 + 0x1f0))) {
        if ((((*(uint *)(iVar2 + 0x1e8) & *(uint *)(iVar2 + 0x1ec)) != 0xffffffff) ||
            (*(char *)(iVar2 + 0x1f0) != '\0')) && (*(int *)(iVar2 + 0x15c) != -1)) {
          VehicleNet_TriggerReplay(iVar2 + 0x158,&uStack_4c,0xd8);
          FUN_005021d0(0);
          return;
        }
        VehicleNet_PostCorrectionEvent(0,&uStack_4c,0);
      }
      FUN_005021d0(0);
    }
  }
  return;
}
