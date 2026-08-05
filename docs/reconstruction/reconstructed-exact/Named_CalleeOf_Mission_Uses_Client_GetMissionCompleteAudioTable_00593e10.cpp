// =============================================================================
// Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00593e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00593e10
// Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x00593e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×17, for×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004d2d60×3, FUN_00561450×3, FUN_005b8340×3, FUN_00593e10, FUN_00597e00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_Client_GetMissionCompleteAudioTable
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

void __thiscall Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_00593e10(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  uint8_t *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  

  if ((char)param_3 != '\0') {

    *(byte *)(param_1 + 0x90e) = *(byte *)(param_1 + 0x90e) | 1;

  }

  FUN_005b8340();

  for (iVar6 = *(int *)(param_1 + 0x6b0); iVar6 != param_1 + 0x3bc; iVar6 = *(int *)(iVar6 + 0x2f4))

  {

    FUN_005b8340();

  }

  FUN_005b8340();

  if ((*(int *)(param_1 + 0x914) != 0) &&

     (puVar1 = *(uint8_t **)(*(int *)(param_1 + 0x914) + 0x78), puVar1 != (uint8_t *)0x0)) {

    *puVar1 = 9;

    *(int *)(*(int *)(*(int *)(param_1 + 0x914) + 0x78) + 4) = param_1;

  }

  iVar6 = *(int *)(param_1 + 0x260);

  if (iVar6 != 0) {

    if (*(int *)(iVar6 + 8) == 0) {

      FUN_004d2d60(iVar6);

    }

    else {

      FUN_00561450(&param_3,iVar6);

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x260);

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x260) = 0;

  }

  if ((*(int *)(param_1 + 0x268) != 0) &&

     (param_3 = *(int *)(param_1 + 0x26c) - *(int *)(param_1 + 0x268) >> 2, param_3 != 0)) {

    for (uVar5 = 0;

        (iVar6 = *(int *)(param_1 + 0x268), iVar6 != 0 &&

        (uVar5 < (uint)(*(int *)(param_1 + 0x26c) - iVar6 >> 2))); uVar5 = uVar5 + 1) {

      uStack_24 = *(uint32_t /* width from decompiler */ *)(iVar6 + uVar5 * 4);

      uStack_28 = 0;

      FUN_00597e00(&uStack_28);

    }

    if (*(void **)(param_1 + 0x268) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0x268));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x268) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x26c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x270) = 0;

  }

  iVar6 = *(int *)(param_1 + 0xa4);

  if (iVar6 != 0) {

    if (*(int *)(iVar6 + 8) == 0) {

      FUN_004d2d60(iVar6);

    }

    else {

      FUN_00561450(&param_3,iVar6);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  }

  if (((*(byte *)(param_1 + 0x90d) & 4) != 0) && (*(int *)(param_1 + 0x50) != 0)) {

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x5c) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x5c))(1);

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x54);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x58);

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

    iVar6 = 0;

    if (0 < *(int *)(*(int *)(param_1 + 0x50) + 0xc)) {

      do {

        iVar3 = *(int *)(*(int *)(param_1 + 0x50) + 8);

        iVar4 = *(int *)(iVar3 + iVar6 * 4);

        if (iVar4 != 0) {

          if (*(int *)(iVar4 + 8) == 0) {

            FUN_004d2d60(iVar4);

          }

          else {

            FUN_00561450(&param_3,*(uint32_t /* width from decompiler */ *)(iVar3 + iVar6 * 4));

          }

        }

        iVar6 = iVar6 + 1;

      } while (iVar6 < *(int *)(*(int *)(param_1 + 0x50) + 0xc));

    }

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x50) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x50))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  return;

}
