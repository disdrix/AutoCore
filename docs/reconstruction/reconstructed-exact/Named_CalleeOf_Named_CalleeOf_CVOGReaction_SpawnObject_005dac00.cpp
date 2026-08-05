// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_005dac00
// -----------------------------------------------------------------------------
// Stable ID: aa_005dac00
// Callee of Named_CalleeOf_CVOGReaction_SpawnObject
// Address:   0x005dac00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// SUPERSEDED 2026-07-29 W22-J: canonical name CVOGHBRecreateObject_RecreateOwner_Inferred
//   (see CVOGHBRecreateObject_RecreateOwner_Inferred.cpp). Scaffold chain name is misleading.
// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: __RTDynamicCast×2, CVOGPhysics_ApplyImpulseVector, FUN_0040d040, FUN_00418d10, FUN_004bcda0, FUN_004cd540, FUN_004e87d0, FUN_004e88e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_SpawnObject
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

void __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_005dac00(int param_1)



{

  byte *pbVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  

  if (*(int *)(param_1 + 0x18) != 0) {

    piVar4 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x18),0,

                                    &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                    &CVOGPhysicsBase::RTTI_Type_Descriptor,0);

    if ((piVar4 != (int *)0x0) && (piVar4[2] != 0)) {

      FUN_004bcda0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 0x160),

                   *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x18) + 0x164),0);

      (**(code **)(**(int **)(param_1 + 0x18) + 0x2a4))

                (*(uint32_t /* width from decompiler */ *)((*(int **)(param_1 + 0x18))[0x29] + 0xe4e8));

      puVar5 = (uint32_t /* width from decompiler */ *)

               __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),0,

                               &CVOGClonedObjectBase::RTTI_Type_Descriptor,

                               &CVOGGraphicsBase::RTTI_Type_Descriptor,0);

      (**(code **)(*(int *)(*(int *)(puVar5[1] + 4) + 4 + (int)puVar5) + 0xfc))();

      FUN_004e88e0(&uStack_20,*(int *)(puVar5[1] + 4) + 0x84 + (int)puVar5);

      FUN_004e87d0(&uStack_14,*(int *)(puVar5[1] + 4) + 0x94 + (int)puVar5);

      (**(code **)*puVar5)

                (1,uStack_20,uStack_1c,uStack_18,uStack_14,uStack_10,uStack_c,uStack_8,

                 *(uint8_t *)((int)puVar5 + 0xd));

      (**(code **)(*(int *)((int)puVar5 + *(int *)(puVar5[1] + 4) + 4) + 0xb8))

                (*(uint32_t /* width from decompiler */ *)((int)puVar5 + *(int *)(puVar5[1] + 4) + 0xbc));

      (**(code **)(*(int *)(*(int *)(puVar5[1] + 4) + 4 + (int)puVar5) + 0x100))();

      (**(code **)(*piVar4 + 0x10))();

      FUN_00560e90(piVar4[2],1);

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

      FUN_004cd540((int)piVar4 + *(int *)(piVar4[1] + 4) + 4,1);

    }

  }

  return;

}
