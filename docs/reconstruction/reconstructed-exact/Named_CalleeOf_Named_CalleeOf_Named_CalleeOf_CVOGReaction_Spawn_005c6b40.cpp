// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Spawn_005c6b40
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6b40
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject (+1 other named callers)
// Address:   0x005c6b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_005130e0, FUN_005c6b40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Spawn_005c6b40(uint32_t /* width from decompiler */ *param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

            uint8_t param_5,uint8_t param_6,char param_7)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  uint8_t uVar3;

  char cVar4;

  

  *param_1 = &PTR_FUN_009d9fe8;

  param_1[4] = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2[1] + 4) + 0x164 + (int)param_2);

  param_1[6] = *puVar1;

  param_1[7] = puVar1[1];

  param_1[8] = puVar1[2];

  param_1[9] = puVar1[3];

  param_1[0xc] = *param_3;

  param_1[0xd] = param_3[1];

  param_1[0xe] = param_3[2];

  param_1[0xf] = param_3[3];

  param_1[0x10] = *param_4;

  param_1[0x11] = param_4[1];

  param_1[0x12] = param_4[2];

  param_1[0x13] = param_4[3];

  *(uint8_t *)((int)param_1 + 0x52) = param_6;

  *(uint8_t *)(param_1 + 0x14) = param_5;

  *(uint8_t *)((int)param_1 + 0x51) = 1;

  *(uint8_t *)((int)param_1 + 0x53) = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  *(byte *)(param_1 + 0x18) =

       (byte)(*(uint *)(*(int *)(param_2[1] + 4) + 0x180 + (int)param_2) >> 6) & 1;

  uVar3 = (**(code **)(*param_2 + 0x34))();

  *(uint8_t *)((int)param_1 + 0x61) = uVar3;

  *(uint8_t *)((int)param_1 + 0x62) = 0;

  *(uint8_t *)((int)param_1 + 99) = 1;

  *(bool *)(param_1 + 0x19) =

       *(int *)(*(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2) + 0x38) == 0x12;

  if (param_7 != '\0') {

    cVar4 = FUN_005130e0(1);

    if (cVar4 != '\0') {

      uVar3 = 1;

      goto LAB_005c6c30;

    }

  }

  uVar3 = 0;

LAB_005c6c30:

  *(uint8_t *)((int)param_1 + 0x65) = uVar3;

  *(uint8_t *)((int)param_1 + 0x66) = 1;

  uVar2 = *(uint *)(*(int *)(param_2[1] + 4) + 0x180 + (int)param_2);

  *(uint8_t *)((int)param_1 + 0x69) = 0;

  *(uint8_t *)((int)param_1 + 0x6a) = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0;

  *(byte *)((int)param_1 + 0x67) = (byte)(uVar2 >> 5) & 1;

  *(uint8_t *)(param_1 + 0x1a) = 1;

  *(uint8_t *)((int)param_2 + 0xf) = 1;

  return param_1;

}
