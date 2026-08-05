// =============================================================================
// FUN_00426ff0
// -----------------------------------------------------------------------------
// Stable ID: aa_00426ff0
// Address:   0x00426ff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00426ff0 @ 0x00426ff0
// Stable ID: aa_00426ff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00426ff0.
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

void __fastcall FUN_00426ff0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  *in_EAX = *param_1;

  in_EAX[1] = param_1[1];

  in_EAX[2] = param_1[2];

  in_EAX[3] = param_1[3];

  in_EAX[4] = param_1[4];

  in_EAX[5] = param_1[5];

  in_EAX[6] = param_1[6];

  in_EAX[7] = param_1[7];

  in_EAX[8] = param_1[8];

  in_EAX[9] = param_1[9];

  in_EAX[10] = param_1[10];

  return;

}
