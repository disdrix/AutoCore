// =============================================================================
// Named_CalleeOf_CVOGSpawnPoint_CreateCreature_0053d970
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d970
// Callee of CVOGSpawnPoint_CreateCreature (+3 other named callers)
// Address:   0x0053d970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGSpawnPoint_CreateCreature (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0053d970, FUN_005d4440.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGSpawnPoint_CreateCreature (+3 other named callers)
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

void __fastcall Named_CalleeOf_CVOGSpawnPoint_CreateCreature_0053d970(int param_1)



{

  int iVar1;

  bool bVar2;

  

  iVar1 = *(int *)(param_1 + 8);

  if (iVar1 != 0) {

    if ((*(char *)(iVar1 + 0x40) == '\0') || (*(int *)(iVar1 + 8) == 0)) {

      bVar2 = true;

    }

    else {

      bVar2 = false;

    }

    if (bVar2) {

      FUN_005d4440();

      return;

    }

  }

  return;

}
