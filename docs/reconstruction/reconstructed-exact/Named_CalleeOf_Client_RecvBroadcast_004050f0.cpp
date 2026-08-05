// =============================================================================
// Named_CalleeOf_Client_RecvBroadcast_004050f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004050f0
// Callee of Client_RecvBroadcast
// Address:   0x004050f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004050f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvBroadcast
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

void __fastcall Named_CalleeOf_Client_RecvBroadcast_004050f0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = 0;

  *(uint8_t *)((int)param_1 + 0x26) = 0xff;

  *(uint8_t *)((int)param_1 + 0x25) = 0xff;

  *(uint8_t *)(param_1 + 9) = 0xff;

  *(uint8_t *)((int)param_1 + 0x27) = 0xff;

  param_1[0x17] = 0;

  return;

}
