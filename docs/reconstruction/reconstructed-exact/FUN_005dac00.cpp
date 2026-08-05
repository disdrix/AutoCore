// =============================================================================
// FUN_005dac00  (twin of CVOGHBRecreateObject_RecreateOwner_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005dac00
// Address:   0x005dac00  (autoassault.exe, image base 0x400000)
// Body:      0x005dac00 – 0x005dae45 (582 B)
// System:    combat / world-object lifecycle (recreate HB)
// Generated: 2026-07-29 W22-J dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named twin: CVOGHBRecreateObject_RecreateOwner_Inferred.cpp
// =============================================================================

void __thiscall FUN_005dac00(int param_1)
{
  byte *pbVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;

  if (*(int *)(param_1 + 0x18) != 0) {
    piVar4 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x18), 0,
                                    &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGPhysicsBase::RTTI_Type_Descriptor, 0);
    if ((piVar4 != (int *)0x0) && (piVar4[2] != 0)) {
      FUN_004bcda0(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x160),
                   *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x164), 0);
      (**(code **)(**(int **)(param_1 + 0x18) + 0x2a4))
                (*(undefined4 *)((*(int **)(param_1 + 0x18))[0x29] + 0xe4e8));
      puVar5 = (undefined4 *)
               __RTDynamicCast(*(undefined4 *)(param_1 + 0x18), 0,
                               &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                               &CVOGGraphicsBase::RTTI_Type_Descriptor, 0);
      (**(code **)(*(int *)(*(int *)(puVar5[1] + 4) + 4 + (int)puVar5) + 0xfc))();
      FUN_004e88e0(&uStack_20, *(int *)(puVar5[1] + 4) + 0x84 + (int)puVar5);
      FUN_004e87d0(&uStack_14, *(int *)(puVar5[1] + 4) + 0x94 + (int)puVar5);
      (**(code **)*puVar5)
                (1, uStack_20, uStack_1c, uStack_18, uStack_14, uStack_10, uStack_c, uStack_8,
                 *(undefined1 *)((int)puVar5 + 0xd));
      (**(code **)(*(int *)((int)puVar5 + *(int *)(puVar5[1] + 4) + 4) + 0xb8))
                (*(undefined4 *)((int)puVar5 + *(int *)(puVar5[1] + 4) + 0xbc));
      (**(code **)(*(int *)(*(int *)(puVar5[1] + 4) + 4 + (int)puVar5) + 0x100))();
      (**(code **)(*piVar4 + 0x10))();
      FUN_00560e90(piVar4[2], 1);
      pbVar1 = (byte *)(*(int *)(piVar4[1] + 4) + 0x181 + (int)piVar4);
      *pbVar1 = *pbVar1 & 0xfe;
      cVar3 = FUN_00418d10();
      if (cVar3 == '\0') {
        FUN_0053d970(0);
      }
      CVOGPhysics_ApplyImpulseVector(&DAT_00bc5670);
      FUN_0040d040(&DAT_00bc5670);
      iVar2 = *(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4);
      uVar6 = (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x244))();
      (**(code **)(iVar2 + 0x240))(uVar6);
      iVar2 = *(int *)(*(int *)(*(int *)(piVar4[1] + 4) + 0xac + (int)piVar4) + 0x38);
      if ((iVar2 != 0x12) && (iVar2 != 0x14)) {
        FUN_00516a00(1);
      }
      FUN_004cd540((int)piVar4 + *(int *)(piVar4[1] + 4) + 4, 1);
    }
  }
  return;
}
