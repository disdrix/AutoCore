// =============================================================================
// FUN_0040e1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040e1e0
// Address:   0x0040e1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040e1e0 @ 0x0040e1e0
// Stable ID: aa_0040e1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: DeleteCriticalSection×2, FUN_0040e490×2, FUN_0040e1e0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040e1e0; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_0040e1e0(undefined4 *param_1)`.
//  - Loops: while (puVar1 != 0x0).
//  - Calls: FUN_0040e490(param_1).
//  - Writes: *param_1 = &PTR_FUN_00a39350; param_1[3] = 0.
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

void __fastcall FUN_0040e1e0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  *param_1 = &PTR_FUN_00a39350;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_0040e490(param_1);

  while (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)*puVar1)(1);

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_0040e490(param_1);

  }

  param_1[3] = 0;

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 10));

  return;

}
