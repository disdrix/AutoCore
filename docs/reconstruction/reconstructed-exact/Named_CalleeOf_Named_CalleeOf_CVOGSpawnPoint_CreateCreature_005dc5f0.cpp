// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005dc5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005dc5f0
// Callee of Named_CalleeOf_CVOGSpawnPoint_CreateCreature
// Address:   0x005dc5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_CreateCreature: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: CVOGHBBase_Start, FUN_005081d0, FUN_005dc5f0, FUN_005de1b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSpawnPoint_CreateCreature
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateCreature_005dc5f0(int param_1,char param_2)



{

  CVOGHBBase *this;

  

  if (param_2 != *(char *)(param_1 + 0x160)) {

    this = *(CVOGHBBase **)(param_1 + 0xd8);

    *(char *)(param_1 + 0x160) = param_2;

    if (param_2 == '\0') {

      if (this != (CVOGHBBase *)0x0) {

        FUN_005081d0();

        return;

      }

    }

    else {

      if (this != (CVOGHBBase *)0x0) {

        CVOGHBBase_Start(this);

      }

      if (*(char *)(param_1 + 0x18b) != '\0') {

        FUN_005de1b0(0,0,0,0,0);

      }

    }

  }

  return;

}
