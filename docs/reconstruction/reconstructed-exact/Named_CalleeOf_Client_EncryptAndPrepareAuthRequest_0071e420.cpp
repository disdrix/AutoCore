// =============================================================================
// Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0071e420
// -----------------------------------------------------------------------------
// Stable ID: aa_0071e420
// Callee of Client_EncryptAndPrepareAuthRequest (+1 other named callers)
// Address:   0x0071e420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_EncryptAndPrepareAuthRequest: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_EncryptAndPrepareAuthRequest (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00718c10, FUN_0071e420.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_EncryptAndPrepareAuthRequest (+1 other named callers)
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

void Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0071e420(void)



{

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  FUN_00718c10(0,0);

  *unaff_ESI = &PTR_FUN_00aa9954;

  unaff_ESI[4] = 0;

  unaff_ESI[5] = 0;

  unaff_ESI[6] = 0;

  *(uint16_t *)(unaff_ESI + 7) = 0;

  *(uint32_t /* width from decompiler */ *)((int)unaff_ESI + 0x1e) = 0;

  *(uint32_t /* width from decompiler */ *)((int)unaff_ESI + 0x22) = 0;

  *(uint32_t /* width from decompiler */ *)((int)unaff_ESI + 0x26) = 0;

  *(uint32_t /* width from decompiler */ *)((int)unaff_ESI + 0x2a) = 0;

  unaff_ESI[0xc] = 0;

  *(uint16_t *)(unaff_ESI + 0xd) = 0;

  return;

}
