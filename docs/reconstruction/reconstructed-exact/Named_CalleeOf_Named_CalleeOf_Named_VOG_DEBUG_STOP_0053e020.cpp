// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0053e020
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e020
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0053e020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0053e020.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0053e020(void)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = operator_new(0x40);

  fVar1 = g_flOne;

  puVar2[3] = 0;

  puVar2[2] = 0;

  puVar2[1] = 0;

  *puVar2 = 0;

  puVar2[7] = 0;

  puVar2[6] = 0;

  puVar2[5] = 0;

  puVar2[4] = 0;

  puVar2[7] = fVar1;

  puVar2[0xb] = 0;

  puVar2[10] = 0;

  puVar2[9] = 0;

  puVar2[8] = 0;

  puVar2[0xf] = 0;

  puVar2[0xe] = 0;

  puVar2[0xd] = 0;

  puVar2[0xc] = 0;

  return;

}
