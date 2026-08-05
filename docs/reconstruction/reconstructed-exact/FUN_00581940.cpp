// =============================================================================
// FUN_00581940
// -----------------------------------------------------------------------------
// Stable ID: aa_00581940
// Address:   0x00581940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581940 @ 0x00581940
// Stable ID: aa_00581940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004a0470, FUN_004a1620, FUN_004a2670, FUN_004a6390, FUN_00581940.
//  - Return sites: 2.

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

void __fastcall FUN_00581940(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a53ab;

  local_c = ExceptionList;

  pvVar1 = *(void **)(param_1 + 0x14);

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_004a2670();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  pvVar1 = operator_new(8);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_004a1620();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = uVar2;

  FUN_004a6390(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18));

  if (DAT_00b0420c == '\0') {

    FUN_004a0470(1,1);

  }

  ExceptionList = local_c;

  return;

}
