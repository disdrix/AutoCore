// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0049be30
// -----------------------------------------------------------------------------
// Stable ID: aa_0049be30
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x0049be30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: for×2, return×1.
//  - Notable callees: FUN_0049be30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0049be30(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar2 = param_2;

  puVar3 = param_1;

  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  param_1[0xf] = param_2[0xf];

  param_1[0x10] = param_2[0x10];

  param_1[0x11] = param_2[0x11];

  param_1[0x12] = param_2[0x12];

  param_1[0x13] = param_2[0x13];

  param_1[0x14] = param_2[0x14];

  param_1[0x15] = param_2[0x15];

  param_1[0x16] = param_2[0x16];

  param_1[0x17] = param_2[0x17];

  param_1[0x18] = param_2[0x18];

  param_1[0x19] = param_2[0x19];

  param_1[0x1a] = param_2[0x1a];

  param_1[0x1b] = param_2[0x1b];

  param_1[0x1c] = param_2[0x1c];

  param_1[0x1d] = param_2[0x1d];

  param_1[0x1e] = param_2[0x1e];

  param_1[0x1f] = param_2[0x1f];

  param_1[0x20] = param_2[0x20];

  param_1[0x21] = param_2[0x21];

  param_1[0x22] = param_2[0x22];

  *(uint16_t *)(param_1 + 0x23) = *(uint16_t *)(param_2 + 0x23);

  param_1[0x24] = param_2[0x24];

  param_1[0x25] = param_2[0x25];

  param_1[0x26] = param_2[0x26];

  param_1[0x27] = param_2[0x27];

  puVar2 = param_2 + 0x28;

  puVar3 = param_1 + 0x28;

  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  param_1[0x37] = param_2[0x37];

  param_1[0x38] = param_2[0x38];

  param_1[0x39] = param_2[0x39];

  param_1[0x3a] = param_2[0x3a];

  param_1[0x3b] = param_2[0x3b];

  param_1[0x3c] = param_2[0x3c];

  param_1[0x3d] = param_2[0x3d];

  param_1[0x3e] = param_2[0x3e];

  param_1[0x3f] = param_2[0x3f];

  param_1[0x40] = param_2[0x40];

  param_1[0x41] = param_2[0x41];

  param_1[0x42] = param_2[0x42];

  param_1[0x43] = param_2[0x43];

  param_1[0x44] = param_2[0x44];

  param_1[0x45] = param_2[0x45];

  return;

}
