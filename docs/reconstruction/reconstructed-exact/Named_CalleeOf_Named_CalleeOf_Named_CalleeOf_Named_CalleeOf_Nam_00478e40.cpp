// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00478e40
// -----------------------------------------------------------------------------
// Stable ID: aa_00478e40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x00478e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×8, for×6, return×4.
//  - Notable callees: FUN_00478e40.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00478e40(int param_1)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  iVar1 = *(int *)(param_1 + 0x1c);

  if (*(int *)(iVar1 + 0x2c) == 0) {

    iVar2 = (**(code **)(param_1 + 0x20))

                      (*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),

                       1 << ((byte)*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c) & 0x1f),1);

    *(int *)(iVar1 + 0x2c) = iVar2;

    if (iVar2 == 0) {

      return 1;

    }

  }

  if (*(int *)(iVar1 + 0x20) == 0) {

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24) = 0;

    *(int *)(iVar1 + 0x20) = 1 << ((byte)*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c) & 0x1f);

  }

  uVar5 = in_EAX - *(int *)(param_1 + 0x10);

  uVar3 = *(uint *)(iVar1 + 0x20);

  if (uVar3 <= uVar5) {

    puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) - uVar3);

    puVar7 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x2c);

    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    }

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20);

    return 0;

  }

  uVar3 = uVar3 - *(int *)(iVar1 + 0x28);

  if (uVar5 < uVar3) {

    uVar3 = uVar5;

  }

  puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) - uVar5);

  puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x28));

  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *puVar7 = *puVar6;

    puVar6 = puVar6 + 1;

    puVar7 = puVar7 + 1;

  }

  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

    puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

  }

  uVar5 = uVar5 - uVar3;

  if (uVar5 != 0) {

    puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) - uVar5);

    puVar7 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x2c);

    for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

    for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    }

    *(uint *)(iVar1 + 0x28) = uVar5;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20);

    return 0;

  }

  *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + uVar3;

  if (*(uint *)(iVar1 + 0x28) == *(uint *)(iVar1 + 0x20)) {

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28) = 0;

  }

  if (*(uint *)(iVar1 + 0x24) < *(uint *)(iVar1 + 0x20)) {

    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) + uVar3;

  }

  return 0;

}
