// =============================================================================
// FUN_006963f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006963f0
// Address:   0x006963f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006963f0 @ 0x006963f0
// Stable ID: aa_006963f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_006919f0, FUN_006954f0, FUN_00695f60, FUN_006963f0, FUN_006a1100.
//  - Return sites: 3.

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

void __fastcall FUN_006963f0(int param_1)



{

  void *pvVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aa9b1;

  local_c = ExceptionList;

  pvVar1 = *(void **)(param_1 + 0x30);

  local_4 = 2;

  if (pvVar1 != (void *)0x0) {

    ExceptionList = &local_c;

    FUN_006a1100();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  local_4 = 1;

  FUN_006919f0();

  if (*(int *)(param_1 + 0x1c) != 0) {

    FUN_00695f60(*(int *)(param_1 + 0x1c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),param_1 + 0x18,param_1);

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x1c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  FUN_006954f0();

  ExceptionList = local_c;

  return;

}
