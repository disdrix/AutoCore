// =============================================================================
// Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_0092f190
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f190
// Callee of Named_Could_not_get_Palantir_desktop_window
// Address:   0x0092f190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Could_not_get_Palantir_desktop_window: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_00586a40×2, FUN_00586c30, FUN_005873a0, FUN_00587430, FUN_00587490, FUN_0092f190.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_Could_not_get_Palantir_desktop_window
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window_0092f190(int param_1,char param_2)



{

  void *pvVar1;

  bool bVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009abd25;

  local_c = ExceptionList;

  if (1 < *(byte *)(*(int *)(*(int *)(param_1 + 0xde8) + 0x28) + 0x799)) {

    if (param_2 != '\0') {

      ExceptionList = &local_c;

      if (DAT_00d1f094 == (void *)0x0) {

        ExceptionList = &local_c;

        pvVar1 = operator_new(0x44);

        local_4 = 0;

        if (pvVar1 == (void *)0x0) {

          DAT_00d1f094 = (void *)0x0;

        }

        else {

          DAT_00d1f094 = (void *)FUN_00587490(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe04) + 0xe894));

        }

      }

      local_4 = 0xffffffff;

      *(uint8_t *)(*(int *)(param_1 + 0xde8) + 0x1f8) = 1;

      FUN_00587430();

      FUN_00586a40(1);

      ExceptionList = local_c;

      return;

    }

    bVar2 = DAT_00d1f094 != (void *)0x0;

    ExceptionList = &local_c;

    *(uint8_t *)(*(int *)(param_1 + 0xde8) + 0x1f8) = 0;

    if (bVar2) {

      FUN_00586a40(0);

      FUN_00586c30();

      pvVar1 = DAT_00d1f094;

      if (DAT_00d1f094 != (void *)0x0) {

        FUN_005873a0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      DAT_00d1f094 = (void *)0x0;

    }

  }

  ExceptionList = local_c;

  return;

}
