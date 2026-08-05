// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004365e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004365e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x004365e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00410490, FUN_004365e0, block.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody
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

/* WARNING: Removing unreachable block (ram,0x004365ed) */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004365e0(uint *param_1,uint param_2)



{

  uint *puVar1;

  uint uVar2;

  uint uVar3;

  

  uVar2 = param_2;

  uVar3 = param_2 + 0x1f >> 5;

  if ((param_1[2] != 0) && (uVar3 < (uint)((int)(param_1[3] - param_1[2]) >> 2))) {

    FUN_00410490(&param_2,param_1[2] + uVar3 * 4,param_1[3]);

  }

  *param_1 = uVar2;

  uVar2 = uVar2 & 0x1f;

  if (uVar2 != 0) {

    puVar1 = (uint *)((param_1[2] - 4) + uVar3 * 4);

    *puVar1 = *puVar1 & (1 << (sbyte)uVar2) - 1U;

  }

  return;

}
