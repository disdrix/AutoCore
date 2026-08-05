// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject_007fb4a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb4a0
// Callee of Named_CalleeOf_Client_RecvDestroyObject
// Address:   0x007fb4a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvDestroyObject: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007fb4a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvDestroyObject
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Client_RecvDestroyObject_007fb4a0(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(code **)(in_EAX + 0xdd4) == (code *)0x0) {

    return 0;

  }

  uVar1 = (**(code **)(in_EAX + 0xdd4))(0x3f800000,0x3f600000,0x40000000);

  return uVar1;

}
