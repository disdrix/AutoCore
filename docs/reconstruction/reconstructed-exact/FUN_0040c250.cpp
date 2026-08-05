// =============================================================================
// FUN_0040c250
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c250
// Address:   0x0040c250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040c250 @ 0x0040c250
// Stable ID: aa_0040c250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0040c250.
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

void __thiscall

FUN_0040c250(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ *param_5,uint8_t param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *param_1 = param_2;

  param_1[2] = param_4;

  param_1[1] = param_3;

  puVar2 = param_1 + 3;

  for (iVar1 = 0x61; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *param_5;

    param_5 = param_5 + 1;

    puVar2 = puVar2 + 1;

  }

  *(uint8_t *)(param_1 + 100) = param_6;

  *(uint8_t *)((int)param_1 + 0x191) = 0;

  return;

}
