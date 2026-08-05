// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005169c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005169c0
// Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
// Address:   0x005169c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005169c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
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

void * __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_005169c0(int param_1)



{

  void *pvVar1;

  

  if (*(int *)(param_1 + 100) == 0) {

    pvVar1 = operator_new(0x14);

    if (pvVar1 != (void *)0x0) {

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x10) = 0;

      *(void **)(param_1 + 100) = pvVar1;

      return pvVar1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  }

  return *(void **)(param_1 + 100);

}
