// =============================================================================
// FUN_00408990
// -----------------------------------------------------------------------------
// Stable ID: aa_00408990
// Address:   0x00408990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00408990 @ 0x00408990
// Stable ID: aa_00408990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00408990, FUN_004099b0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x00408990; evidence only — no invented semantics):
//  - Entry: `void * FUN_00408990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4, undef...`.
//  - Branches: if (pvVar1 != 0x0).
//  - Calls: operator_new(0x28); FUN_004099b0(param_1,param_2,param_3,param_4,param_5).
//  - Returns (1 site(s)): `pvVar1`.




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

void * FUN_00408990(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                   uint32_t /* width from decompiler */ param_5)



{

  void *pvVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc6b1;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  pvVar1 = operator_new(0x28);

  local_8 = 1;

  if (pvVar1 != (void *)0x0) {

    FUN_004099b0(param_1,param_2,param_3,param_4,param_5);

  }

  ExceptionList = local_10;

  return pvVar1;

}
