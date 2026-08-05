// =============================================================================
// FUN_0041d860
// -----------------------------------------------------------------------------
// Stable ID: aa_0041d860
// Address:   0x0041d860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041d860 @ 0x0041d860
// Stable ID: aa_0041d860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0041c140, FUN_0041d860.
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

uint32_t /* width from decompiler */ *

FUN_0041d860(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t *param_4,

            uint8_t param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd7d1;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar1 = operator_new(0x24);

  local_8 = 1;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = param_1;

    puVar1[1] = param_2;

    puVar1[2] = param_3;

    *(uint8_t *)(puVar1 + 3) = *param_4;

    FUN_0041c140(param_4 + 4);

    *(uint8_t *)(puVar1 + 8) = param_5;

    *(uint8_t *)((int)puVar1 + 0x21) = 0;

  }

  ExceptionList = local_10;

  return puVar1;

}
