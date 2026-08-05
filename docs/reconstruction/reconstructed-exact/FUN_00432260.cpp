// =============================================================================
// FUN_00432260
// -----------------------------------------------------------------------------
// Stable ID: aa_00432260
// Address:   0x00432260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00432260 @ 0x00432260
// Stable ID: aa_00432260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: for×9, if×7, return×1.
//  - Notable callees: free×2, malloc×2, FUN_00432260, FUN_004323e0.
//  - Return sites: 1.

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

void FUN_00432260(int param_1,char param_2,char param_3,char param_4)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x30);

  puVar1 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x30);

  for (iVar2 = 0x5f; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar1 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar1 = puVar1 + 1;

  }

  FUN_004323e0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),*(uint16_t *)(param_1 + 0x16),

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x40));

  if (((param_2 == '\0') || (*(uint32_t /* width from decompiler */ **)(in_EAX + 4) == (uint32_t /* width from decompiler */ *)0x0)) ||

     (*(uint32_t /* width from decompiler */ **)(param_1 + 4) == (uint32_t /* width from decompiler */ *)0x0)) {

    if (((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x28) != 0)) &&

       ((puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0x28), puVar5 != (uint32_t /* width from decompiler */ *)0x0 &&

        ((*(int *)(in_EAX + 4) != 0 && (*(int *)(in_EAX + 0x28) != 0)))))) {

      uVar4 = *(int *)(in_EAX + 0x28) * 4;

      if (0x3ff < uVar4) {

        uVar4 = 0x400;

      }

      puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 4) + 0x28);

      for (uVar4 = uVar4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar1 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar1 = puVar1 + 1;

      }

      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {

        *(uint8_t *)puVar1 = *(uint8_t *)puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

      }

      *(uint8_t *)(in_EAX + 0x1a1) = 0;

    }

  }

  else {

    uVar3 = *(int *)(in_EAX + 0x1c) + *(int *)(in_EAX + 0x28) * 4 + *(int *)(in_EAX + 8);

    puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

    puVar1 = *(uint32_t /* width from decompiler */ **)(in_EAX + 4);

    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar1 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar1 = puVar1 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  }

  uVar4 = *(int *)(in_EAX + 0x10) * *(int *)(in_EAX + 0xc);

  if ((param_3 != '\0') && (*(int *)(param_1 + 0x1ac) != 0)) {

    if (*(void **)(in_EAX + 0x1ac) != (void *)0x0) {

      free(*(void **)(in_EAX + 0x1ac));

    }

    puVar1 = malloc(uVar4);

    *(uint32_t /* width from decompiler */ **)(in_EAX + 0x1ac) = puVar1;

    puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1ac);

    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar1 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar1 = puVar1 + 1;

    }

    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  }

  if ((param_4 != '\0') && (*(int *)(param_1 + 0x1b0) != 0)) {

    if (*(void **)(in_EAX + 0x1b0) != (void *)0x0) {

      free(*(void **)(in_EAX + 0x1b0));

    }

    puVar1 = malloc(uVar4);

    *(uint32_t /* width from decompiler */ **)(in_EAX + 0x1b0) = puVar1;

    puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1b0);

    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar1 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar1 = puVar1 + 1;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)puVar5;

      puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  }

  return;

}
