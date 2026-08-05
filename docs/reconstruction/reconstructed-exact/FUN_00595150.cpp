// =============================================================================
// FUN_00595150
// -----------------------------------------------------------------------------
// Stable ID: aa_00595150
// Address:   0x00595150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00595150 @ 0x00595150
// Stable ID: aa_00595150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_00594030, FUN_00595150, FUN_00787350.
//  - Return sites: 5.

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

void __fastcall FUN_00595150(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a5a3a;

  pvStack_c = ExceptionList;

  local_4 = 4;

  ExceptionList = &pvStack_c;

  FUN_00594030();

  if (*(void **)(param_1 + 0x278) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x278));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x278) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x27c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x280) = 0;

  if (*(void **)(param_1 + 0x268) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x268));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x268) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x26c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x270) = 0;

  if (*(void **)(param_1 + 0x1c4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x1c4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1cc) = 0;

  local_4 = local_4 & 0xffffff00;

  FUN_00787350();

  if (*(void **)(param_1 + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  ExceptionList = pvStack_c;

  return;

}
