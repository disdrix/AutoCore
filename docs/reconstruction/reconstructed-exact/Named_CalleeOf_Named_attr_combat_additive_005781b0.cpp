// =============================================================================
// Named_CalleeOf_Named_attr_combat_additive_005781b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005781b0
// Callee of Named_attr_combat_additive (+6 other named callers)
// Address:   0x005781b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_attr_combat_additive: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_attr_combat_additive (+6 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: do×6, while×6, for×4, if×1, return×1.
//  - Notable callees: FUN_005781b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_attr_combat_additive (+6 other named callers)
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

void Named_CalleeOf_Named_attr_combat_additive_005781b0(int param_1,char *param_2,char *param_3,char param_4)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  char *pcVar4;

  uint uVar5;

  uint16_t *puVar6;

  uint16_t *puVar7;

  

  puVar6 = (uint16_t *)(param_1 + -1);

  pcVar2 = param_2;

  if (param_4 == '\0') {

    do {

      pcVar4 = (char *)((int)puVar6 + 1);

      puVar6 = (uint16_t *)((int)puVar6 + 1);

    } while (*pcVar4 != '\0');

    *puVar6 = DAT_00a393e4;

  }

  else {

    do {

      puVar7 = puVar6;

      puVar6 = (uint16_t *)((int)puVar7 + 1);

    } while (*(char *)((int)puVar7 + 1) != '\0');

    *(uint16_t *)((int)puVar7 + 1) = DAT_00a6bfac;

    *(uint8_t *)((int)puVar7 + 3) = DAT_00a6bfae;

  }

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  uVar3 = (int)pcVar2 - (int)param_2;

  pcVar2 = (char *)(param_1 + -1);

  do {

    pcVar4 = pcVar2 + 1;

    pcVar2 = pcVar2 + 1;

  } while (*pcVar4 != '\0');

  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)param_2;

    param_2 = param_2 + 4;

    pcVar2 = pcVar2 + 4;

  }

  for (uVar3 = uVar3 & 3; pcVar4 = param_3, uVar3 != 0; uVar3 = uVar3 - 1) {

    *pcVar2 = *param_2;

    param_2 = param_2 + 1;

    pcVar2 = pcVar2 + 1;

  }

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  uVar3 = (int)pcVar4 - (int)param_3;

  pcVar2 = (char *)(param_1 + -1);

  do {

    pcVar4 = pcVar2 + 1;

    pcVar2 = pcVar2 + 1;

  } while (*pcVar4 != '\0');

  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)param_3;

    param_3 = param_3 + 4;

    pcVar2 = pcVar2 + 4;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *pcVar2 = *param_3;

    param_3 = param_3 + 1;

    pcVar2 = pcVar2 + 1;

  }

  return;

}
