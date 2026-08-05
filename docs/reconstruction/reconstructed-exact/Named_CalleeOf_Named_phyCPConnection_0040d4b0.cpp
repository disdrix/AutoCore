// =============================================================================
// Named_CalleeOf_Named_phyCPConnection_0040d4b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040d4b0
// Callee of Named_phyCPConnection (+3 other named callers)
// Address:   0x0040d4b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_phyCPConnection: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_phyCPConnection (+3 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_0040d4b0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_phyCPConnection (+3 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_phyCPConnection_0040d4b0(int *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (*param_1 == 0) {

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(*param_1 + 0xc);

  puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

  while( true ) {

    if (puVar2 == puVar1) {

      return (uint32_t /* width from decompiler */ *)0x0;

    }

    if (*(int *)(puVar2[2] + 8) == param_2) break;

    puVar2 = (uint32_t /* width from decompiler */ *)*puVar2;

  }

  return puVar2 + 2;

}
