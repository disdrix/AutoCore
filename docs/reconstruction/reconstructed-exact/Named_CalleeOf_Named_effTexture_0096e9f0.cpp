// =============================================================================
// Named_CalleeOf_Named_effTexture_0096e9f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096e9f0
// Callee of Named_effTexture
// Address:   0x0096e9f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effTexture: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0043f120, FUN_0096bbb0, FUN_0096cad0, FUN_0096e9f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effTexture
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_effTexture_0096e9f0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = FUN_0043f120();

  if (iVar1 == 0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_0096bbb0();

  }

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    iVar1 = FUN_0096cad0(param_1);

    if (iVar1 < 0) {

      (**(code **)*puVar2)();

      return (uint32_t /* width from decompiler */ *)0x0;

    }

  }

  return puVar2;

}
