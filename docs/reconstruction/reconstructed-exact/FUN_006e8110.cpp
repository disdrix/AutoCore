// =============================================================================
// FUN_006e8110
// -----------------------------------------------------------------------------
// Stable ID: aa_006e8110
// Address:   0x006e8110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e8110 @ 0x006e8110
// Stable ID: aa_006e8110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: while×2, return×1.
//  - Notable callees: FUN_006e8110.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_006e8110(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  param_1[2] = param_4;

  *param_1 = &PTR_LAB_00a0e858;

  puVar3 = (uint32_t /* width from decompiler */ *)param_2[3];

  puVar2 = param_2;

  while (puVar1 = puVar3, puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = puVar1;

    puVar3 = (uint32_t /* width from decompiler */ *)puVar1[3];

  }

  param_1[3] = puVar2;

  puVar3 = (uint32_t /* width from decompiler */ *)param_3[3];

  puVar2 = param_3;

  while (puVar1 = puVar3, puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = puVar1;

    puVar3 = (uint32_t /* width from decompiler */ *)puVar1[3];

  }

  param_1[4] = puVar2;

  uVar4 = (**(code **)(*(int *)*param_2 + 0x14))();

  param_1[7] = uVar4;

  uVar4 = (**(code **)(*(int *)*param_3 + 0x14))();

  param_1[8] = uVar4;

  return param_1;

}
