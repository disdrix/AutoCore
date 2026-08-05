// =============================================================================
// FUN_006815c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006815c0
// Address:   0x006815c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006815c0 @ 0x006815c0
// Stable ID: aa_006815c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: for×4, if×2, return×1.
//  - Notable callees: FUN_006815c0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006815c0(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a99b8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009e9728;

  *(uint8_t *)(param_1 + 1) = *(uint8_t *)(param_2 + 4);

  param_1[2] = 0;

  param_1[3] = 0;

  uVar3 = *(uint *)(param_2 + 0x10);

  param_1[4] = uVar3;

  param_1[5] = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  local_4 = 0;

  if (uVar3 != 0) {

    puVar1 = operator_new__(uVar3);

    uVar3 = param_1[4];

    param_1[2] = puVar1;

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar1 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar1 = puVar1 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  }

  if (param_1[5] != 0) {

    puVar1 = operator_new__(param_1[5]);

    uVar3 = param_1[5];

    param_1[3] = puVar1;

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xc);

    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar1 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar1 = puVar1 + 1;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  }

  ExceptionList = local_c;

  return param_1;

}
