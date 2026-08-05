// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_00812360
// -----------------------------------------------------------------------------
// Stable ID: aa_00812360
// Callee of Client_PacketDispatch
// Address:   0x00812360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×11, return×6, goto×1.
//  - Notable callees: FUN_0053dd40×2, CONCAT31, CVOGReaction_ResolveObjectTarget, CVOGReaction_TeleportTarget, FUN_00404c30, FUN_00404dc0, FUN_00418d10, FUN_00496750.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void __fastcall Named_CalleeOf_Client_PacketDispatch_00812360(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int *piVar3;

  int *piVar4;

  void *this;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t auStack_60 [12];

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ *puStack_48;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_4c = CONCAT31((int3)((uint)param_2 >> 8),*(uint8_t *)(in_EAX + 0x98));

  puStack_48 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x90);

  uStack_50 = 0x812391;

  iVar2 = CVOGReaction_ResolveObjectTarget();

  if (iVar2 != 0) {

LAB_0081261a:

    puStack_48 = (uint32_t /* width from decompiler */ *)0x812624;

    FUN_00811e00();

    return;

  }

  if (*(char *)(in_EAX + 0x98) == '\0') {

    puStack_48 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x94);

    uStack_4c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x90);

    uStack_50 = 0x8123d6;

    iVar2 = FUN_004e23d0();

    piVar3 = (int *)0x0;

    if (iVar2 != 0) {

      piVar3 = *(int **)(iVar2 + 0xc);

    }

    if (piVar3 != (int *)0x0) {

      piVar4 = (int *)(**(code **)(*piVar3 + 0x1cc))();

      cVar1 = (**(code **)(*piVar3 + 0x198))();

      if ((cVar1 != '\0') || (piVar4[2] == 0)) {

        (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0xfc))();

        cVar1 = (**(code **)(*piVar3 + 0x198))();

        if (cVar1 == '\0') {

          iVar2 = (**(code **)(*piVar3 + 0x1d0))();

          if (iVar2 != 0) {

            (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x10c))();

            return;

          }

          iVar2 = (**(code **)(*piVar3 + 0x1c8))();

          if (iVar2 != 0) {

            FUN_0053dd40();

          }

          iVar2 = *(int *)(piVar4[1] + 4);

          puVar6 = (uint32_t /* width from decompiler */ *)*piVar4;

          puStack_48 = &uStack_20;

          uStack_4c = 0x81258c;

          puVar5 = (uint32_t /* width from decompiler */ *)FUN_004e87d0();

          uStack_54 = *puVar5;

          uStack_50 = puVar5[1];

          uStack_4c = puVar5[2];

          puStack_48 = (uint32_t /* width from decompiler */ *)puVar5[3];

          FUN_004e88e0(auStack_60,(int)piVar4 + iVar2 + 0x84);

          (*(code *)*puVar6)(1);

          (**(code **)(*(int *)((int)piVar4 + *(int *)(piVar4[1] + 4) + 4) + 0xb8))

                    (*(uint32_t /* width from decompiler */ *)((int)piVar4 + *(int *)(piVar4[1] + 4) + 0xbc));

          (**(code **)(*piVar4 + 0x20))();

          (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x100))();

          return;

        }

        iVar2 = (**(code **)(*piVar3 + 0x1c8))();

        if (iVar2 == 0) {

          return;

        }

        uStack_20 = *(uint32_t /* width from decompiler */ *)(in_EAX + 100);

        uStack_1c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x68);

        uStack_18 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x6c);

        uStack_14 = 0;

        (**(code **)(*piVar3 + 0x1c8))();

        cVar1 = FUN_00418d10();

        if (cVar1 == '\0') {

          puVar6 = &uStack_20;

          puStack_48 = (uint32_t /* width from decompiler */ *)0x8124bd;

          this = (void *)(**(code **)(*piVar3 + 0x1c8))();

          puStack_48 = (uint32_t /* width from decompiler */ *)0x8124c4;

          CVOGReaction_TeleportTarget(this,puVar6);

          iVar2 = (**(code **)(*piVar3 + 0x1c8))();

          if (*(int *)(iVar2 + 8) == 0) {

            puStack_48 = (uint32_t /* width from decompiler */ *)0x8124f7;

            FUN_00404c30();

          }

          else {

            (**(code **)(*piVar3 + 0x1c8))();

            puStack_48 = (uint32_t /* width from decompiler */ *)0x8124eb;

            FUN_00404dc0();

          }

        }

        (**(code **)(*piVar3 + 0x1c8))();

        FUN_0053dd40();

        puStack_48 = (uint32_t /* width from decompiler */ *)0x812520;

        FUN_00496750();

        return;

      }

      goto LAB_0081261a;

    }

  }

  puStack_48 = (uint32_t /* width from decompiler */ *)param_3;

  uStack_4c = 0x81260e;

  FUN_008120d0();

  return;

}
