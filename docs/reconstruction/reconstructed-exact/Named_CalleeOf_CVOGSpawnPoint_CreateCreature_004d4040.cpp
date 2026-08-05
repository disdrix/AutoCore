// =============================================================================
// Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004d4040
// -----------------------------------------------------------------------------
// Stable ID: aa_004d4040
// Callee of CVOGSpawnPoint_CreateCreature
// Address:   0x004d4040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, while×1.
//  - Notable callees: FUN_0053fff0×4, CVOGReaction_ResolveObjectTarget×2, FUN_00411900×2, FUN_00418d70×2, FUN_004bc180×2, FUN_00512160×2, FUN_00402c40, FUN_004c0340.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of CVOGSpawnPoint_CreateCreature
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

void __thiscall

Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004d4040(void *param_1,void *param_2,uint param_3,uint param_4,uint param_5,uint param_6)



{

  int iVar1;

  bool bVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ uVar10;

  void *pvVar11;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = (int)param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2079;

  local_c = ExceptionList;

  if (((param_2 != (void *)0x0) &&

      (iVar7 = *(int *)(*(int *)((int)param_2 + 4) + 4), iVar5 = iVar7 + (int)param_2,

      *(int *)(*(int *)(*(int *)(iVar7 + 0xac + (int)param_2) + 0x3c) + 0x4e0) == 1)) &&

     ((*(uint *)(iVar5 + 0x3c) & *(uint *)(iVar5 + 0x40)) == 0xffffffff)) {

    ExceptionList = &local_c;

    if ((param_5 & param_6) == 0xffffffff) {

      bVar2 = false;

      param_2 = (void *)0x0;

      ExceptionList = &local_c;

      FUN_0053fff0();

      FUN_00402c40();

      FUN_0053fff0();

      iVar5 = FUN_00411900(&param_2);

      while (iVar5 != 0) {

        iVar7 = *(int *)(*(int *)(iVar3 + 4) + 4);

        if ((*(int *)(iVar5 + 0x88) == *(int *)(*(int *)(iVar7 + 0xac + iVar3) + 0x34)) &&

           (*(int *)(iVar5 + 0xfc) == *(int *)(*(int *)(iVar7 + iVar3 + 0xa8) + 0xfc))) {

          bVar2 = true;

          break;

        }

        FUN_0053fff0();

        iVar5 = FUN_00411900(&param_2);

      }

      piVar6 = (int *)FUN_0053fff0();

      *(uint8_t *)(*piVar6 + 0x1d) = 0;

      if (!bVar2) {

        ExceptionList = local_c;

        return;

      }

    }

    if ((param_3 & param_4) == 0xffffffff) {

      param_3 = *(uint *)((int)param_1 + 0xe6d8);

      param_4 = *(uint *)((int)param_1 + 0xe6dc);

      *(uint *)((int)param_1 + 0xe6d8) = param_3 + 1;

      *(uint *)((int)param_1 + 0xe6dc) = param_4 + (0xfffffffe < param_3);

    }

    uVar4 = param_3;

    if ((param_5 & param_6) == 0xffffffff) {

      param_5 = *(uint *)((int)param_1 + 0xe6d8);

      param_6 = *(uint *)((int)param_1 + 0xe6dc);

      *(uint *)((int)param_1 + 0xe6d8) = param_5 + 1;

      *(uint *)((int)param_1 + 0xe6dc) = param_6 + (0xfffffffe < param_5);

    }

    piVar6 = (int *)0x0;

    iVar5 = CVOGReaction_ResolveObjectTarget(0,param_3,param_4);

    if ((iVar5 == 0) && (iVar5 = CVOGReaction_ResolveObjectTarget(0,param_5,param_6), iVar5 == 0)) {

      param_2 = operator_new(0x270);

      local_4 = 0;

      if (param_2 != (void *)0x0) {

        piVar6 = (int *)FUN_0057b0e0();

      }

      local_4 = 0xffffffff;

      pvVar11 = param_1;

      iVar5 = (**(code **)(*piVar6 + 8))(DAT_00b04850,param_1,1);

      if (iVar5 == 0) {

        FUN_00512160(uVar4,unaff_retaddr,0);

        (**(code **)(*piVar6 + 0x218))(param_1);

        *(uint8_t *)((int)piVar6 + 0x1d1) = 0x25;

        FUN_00418d70(&stack0xffffffdc);

        FUN_004bc180(piVar6);

        local_c = operator_new(0x350);

        if (local_c == (void *)0x0) {

          iVar5 = 0;

        }

        else {

          iVar5 = FUN_005dbfa0(1);

        }

        iVar7 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 8))

                          (DAT_00bc5684,param_1,1);

        if (iVar7 != 0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5))(1);

          ExceptionList = pvVar11;

          return;

        }

        FUN_00512160(local_c,puStack_8,0);

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x218))(param_1);

        *(uint8_t *)(iVar5 + 0xde) = 0;

        *(uint8_t *)(iVar5 + 0xdc) = 0;

        *(uint8_t *)(iVar5 + 0xdf) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x15c) = 0xffffffff;

        FUN_005dc5f0(1);

        iVar1 = *(int *)(*(int *)(iVar5 + 4) + 4) + iVar5;

        iVar7 = iVar1 + 0x94;

        uVar10 = 1;

        iVar8 = iVar1 + 0x84;

        uVar9 = (**(code **)(*(int *)(iVar1 + 4) + 0x1cc))(iVar8,iVar7,1);

        FUN_004c0340(uVar9,iVar8,iVar7,uVar10);

        FUN_00418d70(&stack0xffffffe8);

        FUN_004bc180(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

        iVar7 = *(int *)(*(int *)(iVar3 + 4) + 4);

        *(uint32_t /* width from decompiler */ *)(iVar7 + 0x3c + iVar3) = uStack_10;

        *(void **)(iVar7 + 0x40 + iVar3) = local_c;

        *(int *)(iVar3 + 0x220) = piVar6[0x58];

        *(int *)(iVar3 + 0x224) = piVar6[0x59];

        iVar7 = *(int *)(*(int *)(iVar5 + 4) + 4);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x218) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x164 + iVar5);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x21c) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x168 + iVar5);

        ExceptionList = pvVar11;

        return;

      }

      (**(code **)*piVar6)(1);

    }

  }

  ExceptionList = local_c;

  return;

}
