// =============================================================================
// FUN_00402da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00402da0
// Address:   0x00402da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00402da0 @ 0x00402da0
// Stable ID: aa_00402da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00402da0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00402da0; evidence only — no invented semantics):
//  - Entry: `void __thiscall FUN_00402da0(undefined4 *param_1,undefined4 *param_2)`.
//  - Returns (1 site(s)): `void`.
//  - Assign `in_EAX = *param_1`.




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

void __thiscall FUN_00402da0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  *in_EAX = *param_1;

  in_EAX[1] = param_1[1];

  in_EAX[2] = param_1[2];

  in_EAX[3] = param_1[3];

  in_EAX[4] = *param_2;

  return;

}
