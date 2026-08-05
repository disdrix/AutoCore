// =============================================================================
// FUN_0040cb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0040cb10
// Address:   0x0040cb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040cb10 @ 0x0040cb10
// Stable ID: aa_0040cb10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040cb10.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040cb10; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_0040cb10(int *param_1)`.
//  - Returns (1 site(s)): `void`.
//  - Sparse CF in raw; see body.




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

void __fastcall FUN_0040cb10(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint8_t local_8 [8];

  

  puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x140))(local_8,1,param_1[0x8a]);

  (**(code **)(*param_1 + 400))(param_1,0,0,*puVar1,puVar1[1]);

  return;

}
