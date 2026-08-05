// =============================================================================
// FUN_005742f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005742f0
// Address:   0x005742f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005742f0 @ 0x005742f0
// Stable ID: aa_005742f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: return×6, if×5.
//  - Notable callees: FUN_00573dc0, FUN_00573e20, FUN_005742f0, FUN_005743e0, FUN_00574650.
//  - Return sites: 6.

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

void __fastcall FUN_005742f0(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5047;

  local_c = ExceptionList;

  local_4 = 3;

  ExceptionList = &local_c;

  FUN_00573dc0();

  FUN_00573e20();

  if (*(void **)(param_1 + 0x38) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x38));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  FUN_00574650(0,0);

  FUN_005743e0(0,0,0);

  if (*(void **)(param_1 + 0x38) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x38));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  if (*(void **)(param_1 + 0x28) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x28));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  if (*(void **)(param_1 + 0x18) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x18));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  if (*(void **)(param_1 + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  ExceptionList = local_c;

  return;

}
