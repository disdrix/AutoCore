// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00445880
// -----------------------------------------------------------------------------
// Stable ID: aa_00445880
// Callee of Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00445880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00445880, FUN_00447660.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_effDeviceEffect
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

void Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00445880(void)



{

  int in_EAX;

  uint8_t local_4 [4];

  

  FUN_00447660(local_4,**(uint32_t /* width from decompiler */ **)(in_EAX + 4),*(uint32_t /* width from decompiler */ **)(in_EAX + 4));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(in_EAX + 4));

}
