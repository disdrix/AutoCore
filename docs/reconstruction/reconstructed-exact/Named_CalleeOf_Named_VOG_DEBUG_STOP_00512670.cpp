// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00512670
// -----------------------------------------------------------------------------
// Stable ID: aa_00512670
// Callee of Named_VOG_DEBUG_STOP (+7 other named callers)
// Address:   0x00512670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00512670.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+7 other named callers)
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_00512670(int param_1)



{

  uint *puVar1;

  int iVar2;

  int *piVar3;

  

  *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) | 0x20000;

  piVar3 = (int *)(param_1 + 0xac);

  iVar2 = *(int *)(param_1 + 0xac);

  while (iVar2 != 0) {

    iVar2 = *piVar3;

    puVar1 = (uint *)(iVar2 + 0x17c);

    *puVar1 = *puVar1 | 0x20000;

    piVar3 = (int *)(iVar2 + 0xac);

    iVar2 = *piVar3;

  }

  return;

}
