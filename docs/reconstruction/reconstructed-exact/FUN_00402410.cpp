// =============================================================================
// FUN_00402410
// -----------------------------------------------------------------------------
// Stable ID: aa_00402410
// Address:   0x00402410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00402410 @ 0x00402410
// Stable ID: aa_00402410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00402410, FUN_00404490, FUN_0040fb90.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00402410; evidence only — no invented semantics):
//  - Entry: `int FUN_00402410(int param_1,int param_2)`.
//  - Calls: FUN_0040fb90(); FUN_00404490(param_1,**(param_1 + 4),**(param_2 + ...).
//  - Returns (1 site(s)): `param_1`.
//  - Assign `local_8 = 0xffffffff`.
//  - Assign `local_10 = ExceptionList`.
//  - Assign `local_8 = 0`.




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

int FUN_00402410(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd220;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  uVar1 = FUN_0040fb90();

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  local_8 = 0;

  FUN_00404490(param_1,**(uint32_t /* width from decompiler */ **)(param_1 + 4),**(uint32_t /* width from decompiler */ **)(param_2 + 4),

               *(uint32_t /* width from decompiler */ **)(param_2 + 4));

  ExceptionList = local_10;

  return param_1;

}
