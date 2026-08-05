// =============================================================================
// FUN_00786610
// -----------------------------------------------------------------------------
// Stable ID: aa_00786610
// Address:   0x00786610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00786610 @ 0x00786610
// Stable ID: aa_00786610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, for×1.
//  - Notable callees: FUN_00786610×2, FUN_0042a780.
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

void __fastcall FUN_00786610(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ace4c;

  pvStack_c = ExceptionList;

  local_4 = 1;

  for (puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10); puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

      puVar2 = puVar2 + 1) {

    pvVar1 = (void *)*puVar2;

    if (pvVar1 != (void *)0x0) {

      ExceptionList = &pvStack_c;

      FUN_00786610();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

  }

  if (*(void **)(param_1 + 4) != (void *)0x0) {

    ExceptionList = &pvStack_c;

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  ExceptionList = &pvStack_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  local_4 = 0;

  FUN_0042a780(local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0x20),*(uint32_t /* width from decompiler */ **)(param_1 + 0x20));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x20));

}
