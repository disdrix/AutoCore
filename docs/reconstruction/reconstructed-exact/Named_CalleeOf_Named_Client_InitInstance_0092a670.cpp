// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_0092a670
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a670
// Callee of Named_Client_InitInstance
// Address:   0x0092a670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0092a670.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_Client_InitInstance_0092a670(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  param_1[0x47] = 0;

  param_1[0x48] = 0;

  param_1[0x49] = 0;

  uVar1 = DAT_00aaa690;

  *param_1 = param_2;

  *(uint8_t *)(param_1 + 1) = 1;

  *(uint8_t *)((int)param_1 + 5) = 1;

  *(uint8_t *)((int)param_1 + 6) = 1;

  param_1[5] = uVar1;

  uVar1 = DAT_00aaa6fc;

  param_1[3] = 0;

  param_1[4] = 0;

  *(uint8_t *)((int)param_1 + 7) = 0;

  *(uint8_t *)((int)param_1 + 9) = 0;

  *(uint8_t *)((int)param_1 + 0xb) = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  *(uint8_t *)((int)param_1 + 10) = 0;

  param_1[0x45] = 0xffffffff;

  param_1[0x44] = 0xffffffff;

  puVar3 = param_1 + 6;

  for (iVar2 = 0x3e; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  param_1[6] = 0xffffffff;

  param_1[8] = 0xffffffff;

  param_1[9] = 0xffffffff;

  param_1[0x15] = 0;

  param_1[0x20] = 0;

  param_1[0x2b] = 0;

  param_1[10] = 0;

  *(uint8_t *)(param_1 + 0x40) = 0;

  *(uint8_t *)((int)param_1 + 0x101) = 0;

  *(uint8_t *)((int)param_1 + 0x102) = 0;

  param_1[0x41] = uVar1;

  param_1[0x42] = 0xffffffff;

  param_1[0x43] = 0xffffffff;

  return param_1;

}
