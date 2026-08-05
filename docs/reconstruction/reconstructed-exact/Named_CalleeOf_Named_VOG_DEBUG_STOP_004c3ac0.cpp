// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004c3ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3ac0
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x004c3ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004c3ac0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

int __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_004c3ac0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  if ((*(byte *)(iVar1 + 0xb8 + param_1) & 7) == 0) {

    return param_1 + 0x240;

  }

  if (*(int *)(param_1 + 8) != 0) {

    return *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;

  }

  return iVar1 + param_1 + 0x84;

}
