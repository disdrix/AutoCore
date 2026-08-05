// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_008034c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008034c0
// Callee of Named_CalleeOf_Named_Client_InitInstance
// Address:   0x008034c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_008034c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Client_InitInstance
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_008034c0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *param_1 = &PTR_LAB_00a7f894;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 1;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 1;

  param_1[0xc] = 4;

  *param_1 = &PTR_FUN_00a7fff4;

  param_1[0x4f] = 0;

  param_1[0x4d] = 0;

  puVar2 = param_1 + 0xd;

  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  param_1[0x4e] = 0xffffff;

  param_1[0x51] = 1;

  param_1[0x52] = 0;

  param_1[0x53] = 0;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0x52] = 0x14;

  param_1[0x50] = 0x800;

  param_1[0x57] = 0;

  param_1[0x58] = 0;

  param_1[0x59] = 0;

  param_1[0x5a] = 0;

  param_1[0x5b] = 0;

  return param_1;

}
