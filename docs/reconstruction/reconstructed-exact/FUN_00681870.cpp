// =============================================================================
// FUN_00681870
// -----------------------------------------------------------------------------
// Stable ID: aa_00681870
// Address:   0x00681870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00681870 @ 0x00681870
// Stable ID: aa_00681870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: for×4, return×3, if×2.
//  - Notable callees: FUN_00681870.
//  - Return sites: 3.

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

char __thiscall

FUN_00681870(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3,uint32_t /* width from decompiler */ *param_4,uint param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  

  if (*(char *)(param_1 + 4) != '\0') {

    return '\x06';

  }

  if ((param_3 != 0) && (param_5 != 0)) {

    puVar1 = operator_new__(param_3);

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar1;

    *(uint *)(param_1 + 0x10) = param_3;

    for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar1 = *param_2;

      param_2 = param_2 + 1;

      puVar1 = puVar1 + 1;

    }

    for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)param_2;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

    puVar1 = operator_new__(param_5);

    uVar2 = param_5 >> 2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xc) = puVar1;

    *(uint *)(param_1 + 0x14) = param_5;

    for (; uVar2 != 0; uVar2 = uVar2 - 1) {

      *puVar1 = *param_4;

      param_4 = param_4 + 1;

      puVar1 = puVar1 + 1;

    }

    for (param_5 = param_5 & 3; param_5 != 0; param_5 = param_5 - 1) {

      *(uint8_t *)puVar1 = *(uint8_t *)param_4;

      param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + 1);

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

    *(uint8_t *)(param_1 + 4) = 1;

    return '\0';

  }

  return (param_3 != 0) + '\x01';

}
