// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_LoadVogIniConfig_007a6910
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6910
// Callee of Named_CalleeOf_Client_LoadVogIniConfig
// Address:   0x007a6910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_LoadVogIniConfig: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, for×2, return×1.
//  - Notable callees: FUN_007a6910.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_LoadVogIniConfig
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Client_LoadVogIniConfig_007a6910(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  int iVar6;

  uint *puVar7;

  

  *param_1 = &PTR_FUN_00a96f88;

  param_1[0xb] = 0;

  param_1[0x30] = 0;

  param_1[0x2f] = 1;

  *(uint8_t *)(param_1 + 0x31) = 0x2c;

  puVar7 = param_1 + 0x1b;

  iVar6 = 10;

  do {

    *puVar7 = 0x100;

    puVar1 = operator_new__(0x100);

    uVar4 = *puVar7;

    puVar7[-0x1a] = (uint)puVar1;

    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar1 = 0;

      puVar1 = puVar1 + 1;

    }

    puVar7 = puVar7 + 1;

    iVar6 = iVar6 + -1;

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar1 = 0;

      puVar1 = (uint32_t /* width from decompiler */ *)((int)puVar1 + 1);

    }

  } while (iVar6 != 0);

  puVar1 = param_1 + 0x16;

  puVar2 = param_1 + 0x25;

  iVar6 = 5;

  do {

    iVar5 = 2;

    do {

      puVar2[-0x19] = 0;

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

    iVar6 = iVar6 + -1;

  } while (iVar6 != 0);

  return param_1;

}
