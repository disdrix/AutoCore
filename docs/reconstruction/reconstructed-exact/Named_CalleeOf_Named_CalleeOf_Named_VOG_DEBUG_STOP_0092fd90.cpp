// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0092fd90
// -----------------------------------------------------------------------------
// Stable ID: aa_0092fd90
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0092fd90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CNDHash_LookupByKey, FUN_0092fd90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0092fd90(void)



{

  uint key;

  int in_EAX;

  void *pvVar1;

  

  key = (*(int **)(in_EAX + 0x4d0))[4];

  if (key != 0) {

    pvVar1 = CNDHash_LookupByKey(*(void **)(*(int *)(**(int **)(in_EAX + 0x4d0) + 0xe98) + 0x548),

                                 key);

    if ((pvVar1 != (void *)0x0) && (*(uint32_t /* width from decompiler */ **)((int)pvVar1 + 0x14c) != (uint32_t /* width from decompiler */ *)0x0)) {

      return **(uint32_t /* width from decompiler */ **)((int)pvVar1 + 0x14c);

    }

  }

  return 0;

}
