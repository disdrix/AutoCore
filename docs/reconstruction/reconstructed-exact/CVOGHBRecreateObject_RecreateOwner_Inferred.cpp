// =============================================================================
// CVOGHBRecreateObject_RecreateOwner_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005dac00
// Address:   0x005dac00  (autoassault.exe, image base 0x400000)
// Body:      0x005dac00 – 0x005dae45 (582 B, inclusive RET)
// System:    combat / world-object lifecycle (recreate HB)
// Generated: 2026-07-29 W22-J dual seal (decompile + read_memory; no disassemble_bytes)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Owner recreate body for CVOGHBRecreateObject. Called from
//   CVOGHBRecreateObject_OnHeartBeat (when transform helper reports local_12c==0)
//   and FUN_004cd4e0 (RTTI recreate HB + flag). Rebinds phys/gfx, clears soft
//   flag bit0 @ layout+0x181, applies zero impulse, optional SetPhysBodyType
//   soft request, tail FUN_004cd540.
//
// ABI: __thiscall; ECX = CVOGHBBase* / CVOGHBRecreateObject*; plain RET; void.
// Ghidra: FUN_005dac00. Former scaffold chain name misleading.
//

void __thiscall CVOGHBRecreateObject_RecreateOwner_Inferred(int pHB)
{
  byte *pbFlag;
  int typeId;
  char softReady;
  int *pPhys;
  undefined4 *pGfx;
  undefined4 v244;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;

  if (*(int *)(pHB + 0x18) != 0) {
    pPhys = (int *)__RTDynamicCast(*(int *)(pHB + 0x18), 0,
                                    &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                                    &CVOGPhysicsBase::RTTI_Type_Descriptor, 0);
    if ((pPhys != (int *)0x0) && (pPhys[2] != 0)) {
      FUN_004bcda0(*(undefined4 *)(*(int *)(pHB + 0x18) + 0x160),
                   *(undefined4 *)(*(int *)(pHB + 0x18) + 0x164), 0);
      (**(code **)(**(int **)(pHB + 0x18) + 0x2a4))
                (*(undefined4 *)((*(int **)(pHB + 0x18))[0x29] + 0xe4e8));
      pGfx = (undefined4 *)
               __RTDynamicCast(*(undefined4 *)(pHB + 0x18), 0,
                               &CVOGClonedObjectBase::RTTI_Type_Descriptor,
                               &CVOGGraphicsBase::RTTI_Type_Descriptor, 0);
      (**(code **)(*(int *)(*(int *)(pGfx[1] + 4) + 4 + (int)pGfx) + 0xfc))();
      FUN_004e88e0(&uStack_20, *(int *)(pGfx[1] + 4) + 0x84 + (int)pGfx);
      FUN_004e87d0(&uStack_14, *(int *)(pGfx[1] + 4) + 0x94 + (int)pGfx);
      (**(code **)*pGfx)
                (1, uStack_20, uStack_1c, uStack_18, uStack_14, uStack_10, uStack_c, uStack_8,
                 *(undefined1 *)((int)pGfx + 0xd));
      (**(code **)(*(int *)((int)pGfx + *(int *)(pGfx[1] + 4) + 4) + 0xb8))
                (*(undefined4 *)((int)pGfx + *(int *)(pGfx[1] + 4) + 0xbc));
      (**(code **)(*(int *)(*(int *)(pGfx[1] + 4) + 4 + (int)pGfx) + 0x100))();
      (**(code **)(*pPhys + 0x10))();
      FUN_00560e90(pPhys[2], 1);
      pbFlag = (byte *)(*(int *)(pPhys[1] + 4) + 0x181 + (int)pPhys);
      *pbFlag = *pbFlag & 0xfe;
      softReady = FUN_00418d10();
      if (softReady == '\0') {
        FUN_0053d970(0);
      }
      CVOGPhysics_ApplyImpulseVector(&DAT_00bc5670);
      FUN_0040d040(&DAT_00bc5670);
      typeId = *(int *)(*(int *)(pPhys[1] + 4) + 4 + (int)pPhys);
      v244 = (**(code **)(*(int *)(*(int *)(pPhys[1] + 4) + 4 + (int)pPhys) + 0x244))();
      (**(code **)(typeId + 0x240))(v244);
      typeId = *(int *)(*(int *)(*(int *)(pPhys[1] + 4) + 0xac + (int)pPhys) + 0x38);
      if ((typeId != 0x12) && (typeId != 0x14)) {
        FUN_00516a00(1);
      }
      FUN_004cd540((int)pPhys + *(int *)(pPhys[1] + 4) + 4, 1);
    }
  }
  return;
}
