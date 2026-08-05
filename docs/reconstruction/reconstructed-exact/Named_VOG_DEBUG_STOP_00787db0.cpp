// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, return×2.
//  - Notable callees: FUN_00787db0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00787db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00787db0
// Address:   0x00787db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_00787db0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint *param_3,char param_4)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  uVar3 = *param_3;

  uVar1 = param_1[0x401];

  iVar5 = 0;

  if (param_1[0x403] != 0) {

    uVar1 = uVar1 + param_1[0x403];

  }

  *param_3 = uVar1;

  if (param_4 == '\0') {

    if ((int)uVar3 < (int)uVar1) {

      FUN_007a4480(0,"VOG_DEBUG_STOP");

      return;

    }

    puVar2 = (uint32_t /* width from decompiler */ *)*param_2;

  }

  else {

    puVar2 = operator_new__(uVar1);

  }

  uVar3 = param_1[0x403];

  if (uVar3 != 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)param_1[0x402];

    puVar6 = puVar2;

    for (uVar1 = uVar3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

      *puVar6 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar6 = puVar6 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar6 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

    }

    iVar5 = param_1[0x403];

  }

  uVar3 = param_1[0x401];

  puVar4 = (uint32_t /* width from decompiler */ *)(iVar5 + (int)puVar2);

  for (uVar1 = uVar3 >> 2; param_1 = param_1 + 1, uVar1 != 0; uVar1 = uVar1 - 1) {

    *puVar4 = *param_1;

    puVar4 = puVar4 + 1;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint8_t *)puVar4 = *(uint8_t *)param_1;

    param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  *param_2 = puVar2;

  return;

}
