// =============================================================================
// FUN_00405c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00405c80
// Address:   0x00405c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00405c80 @ 0x00405c80
// Stable ID: aa_00405c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00405c80, FUN_004069b0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00405c80; evidence only — no invented semantics):
//  - Entry: `void FUN_00405c80(void)`.
//  - Calls: FUN_004069b0(*(*(in_EAX + 4) + 4)).
//  - Returns (1 site(s)): `void`.




/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_00405c80(void)



{

  int in_EAX;

  

  FUN_004069b0(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 4) + 4));

  *(int *)(*(int *)(in_EAX + 4) + 4) = *(int *)(in_EAX + 4);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(in_EAX + 4) = *(uint32_t /* width from decompiler */ *)(in_EAX + 4);

  *(int *)(*(int *)(in_EAX + 4) + 8) = *(int *)(in_EAX + 4);

  return;

}
