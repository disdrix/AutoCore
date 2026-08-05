// =============================================================================
// FUN_00477a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00477a30
// Address:   0x00477a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477a30 @ 0x00477a30
// Stable ID: aa_00477a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00477a30.
//  - Return sites: 1.

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

void __fastcall FUN_00477a30(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  *(char *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) = (char)((uint)param_1 >> 8);

  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

  *(char *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) = (char)param_1;

  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

  return;

}
