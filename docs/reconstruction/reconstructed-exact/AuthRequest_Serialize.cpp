// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00480af0×2, AuthRequest_Serialize, FUN_00439810, FUN_0044cbd0, FUN_00480b50.
//  - Return sites: 1.

// =============================================================================
// AuthRequest_Serialize
// -----------------------------------------------------------------------------
// Stable ID: aa_0071e460
// Address:   0x0071e460  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

uint32_t /* width from decompiler */ __fastcall AuthRequest_Serialize(int param_1)



{

  FUN_0044cbd0();

  FUN_00480af0();

  FUN_00480af0();

  FUN_00439810();

  FUN_00480b50(param_1 + 0x34);

  return 0;

}
