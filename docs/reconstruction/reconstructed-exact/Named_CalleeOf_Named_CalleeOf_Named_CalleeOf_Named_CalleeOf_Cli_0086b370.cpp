// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0086b370
// -----------------------------------------------------------------------------
// Stable ID: aa_0086b370
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
// Address:   0x0086b370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0086a210, FUN_0086a900, FUN_0086b370.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0086b370(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_0086a210();

  local_4 = 0x9018;

  if (DAT_00d1b4bc != (int *)0x0) {

    cVar1 = (**(code **)(*DAT_00d1b4bc + 8))();

    if (cVar1 != '\0') {

      (**(code **)(*DAT_00d1b4bc + 0x18))(0xffffffff,&local_4,4,0);

    }

  }

  FUN_0086a900(0xffffffff,0xffffffff);

  return;

}
