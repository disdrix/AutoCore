// =============================================================================
// FUN_00910460
// -----------------------------------------------------------------------------
// Stable ID: aa_00910460
// Address:   0x00910460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00910460 @ 0x00910460
// Stable ID: aa_00910460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0040d4f0, FUN_0074d750, FUN_0074ed90, FUN_009103d0, FUN_00910460.
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

void __fastcall FUN_00910460(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b045b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_009103d0();

  pvVar1 = operator_new(0x5c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0074d750();

  }

  local_4 = 0xffffffff;

  (&DAT_00d09a4c)[param_1 * 4] = uVar2;

  pvVar1 = operator_new(0x14);

  local_4 = 1;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0040d4f0();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(&DAT_00d09a50 + param_1 * 0x10) = uVar2;

  pvVar1 = operator_new(0x78);

  local_4 = 2;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_0074ed90();

  }

  *(uint32_t /* width from decompiler */ *)(&DAT_00d09a54 + param_1 * 0x10) = uVar2;

  (&DAT_00d09a58)[param_1 * 4] = 0;

  ExceptionList = local_c;

  return;

}
