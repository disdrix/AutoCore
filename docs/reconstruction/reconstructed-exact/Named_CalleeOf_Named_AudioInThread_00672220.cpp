// =============================================================================
// Named_CalleeOf_Named_AudioInThread_00672220
// -----------------------------------------------------------------------------
// Stable ID: aa_00672220
// Callee of Named_AudioInThread
// Address:   0x00672220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_AudioInThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: for×10, if×7, while×1, return×1.
//  - Notable callees: FUN_00672130×2, FUN_00673ac0×2, FUN_00671bb0, FUN_00672220, FUN_006802d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_AudioInThread
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_AudioInThread_00672220(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *local_c;

  uint local_8;

  uint32_t /* width from decompiler */ *puStack_4;

  

  iVar1 = *(int *)(param_1 + 0x968);

  local_8 = 0;

  local_c = (uint32_t /* width from decompiler */ *)0x0;

  if (iVar1 != 0) {

    uVar5 = *(int *)(param_1 + 0x164) - iVar1;

    puVar8 = param_2;

    puVar3 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1);

    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *puVar3 = *puVar8;

      puVar8 = puVar8 + 1;

      puVar3 = puVar3 + 1;

    }

    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint8_t *)puVar3 = *(uint8_t *)puVar8;

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

    (**(code **)(**(int **)(param_1 + 0x15c) + 8))

              (param_1 + 0x168,*(uint32_t /* width from decompiler */ *)(param_1 + 0x160),&local_c);

    cVar2 = FUN_00672130();

    if (cVar2 != '\0') {

      FUN_00671bb0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x160),local_c);

    }

    if (*(char *)(param_1 + 0x96e) != '\0') {

      puStack_4 = operator_new__(*(uint *)(param_1 + 0x164));

      uVar6 = *(uint *)(param_1 + 0x164);

      puVar8 = param_2;

      puVar3 = puStack_4;

      for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar3 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar3 = puVar3 + 1;

      }

      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar8;

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

      FUN_00673ac0(&puStack_4);

    }

    local_8 = *(uint *)(param_1 + 0x968);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x968) = 0;

  }

  uVar5 = *(int *)(param_1 + 0x164) + local_8;

  uVar6 = local_8;

  while (uVar5 < param_3) {

    local_8 = uVar6;

    (**(code **)(**(int **)(param_1 + 0x15c) + 8))

              ((uint8_t *)((int)param_2 + uVar6),*(uint32_t /* width from decompiler */ *)(param_1 + 0x160),&local_c);

    cVar2 = FUN_00672130();

    if (cVar2 != '\0') {

      puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x160);

      puStack_4 = local_c;

      puVar3 = operator_new(8);

      if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar3 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        *puVar3 = 0;

        puVar3[1] = 0;

      }

      puVar4 = operator_new__((uint)puStack_4);

      *(char *)puVar3 = (char)puStack_4;

      uVar6 = (uint)puStack_4 >> 2;

      puVar3[1] = puVar4;

      for (; uVar6 != 0; uVar6 = uVar6 - 1) {

        *puVar4 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar4 = puVar4 + 1;

      }

      for (uVar6 = (uint)puStack_4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint8_t *)puVar4 = *(uint8_t *)puVar8;

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      }

      FUN_006802d0(4,puVar3);

      uVar6 = local_8;

    }

    if (*(char *)(param_1 + 0x96e) != '\0') {

      puStack_4 = operator_new__(*(uint *)(param_1 + 0x164));

      uVar5 = *(uint *)(param_1 + 0x164);

      puVar8 = param_2;

      puVar3 = puStack_4;

      for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

        *puVar3 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar3 = puVar3 + 1;

      }

      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar8;

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

      FUN_00673ac0(&puStack_4);

    }

    uVar6 = uVar6 + *(int *)(param_1 + 0x164);

    uVar5 = *(int *)(param_1 + 0x164) + uVar6;

  }

  if (uVar6 < param_3) {

    param_3 = param_3 - uVar6;

    *(uint *)(param_1 + 0x968) = param_3;

    puVar8 = (uint32_t /* width from decompiler */ *)(uVar6 + (int)param_2);

    puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x168);

    for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar3 = *puVar8;

      puVar8 = puVar8 + 1;

      puVar3 = puVar3 + 1;

    }

    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {

      *(uint8_t *)puVar3 = *(uint8_t *)puVar8;

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

  }

  return 0;

}
