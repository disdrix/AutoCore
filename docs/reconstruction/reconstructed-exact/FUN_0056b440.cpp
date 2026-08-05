// =============================================================================
// FUN_0056b440
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b440
// Address:   0x0056b440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b440 @ 0x0056b440
// Stable ID: aa_0056b440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_004ce940, FUN_0056b440, FUN_005c9710, FUN_005c9780, FUN_005ca540, FUN_005ca5e0.
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

void __fastcall FUN_0056b440(int param_1)



{

  int iVar1;

  void *pvStack_8;

  void *pvStack_4;

  

  if (*(char *)(param_1 + -0xaf) == '\0') {

    *(uint8_t *)(param_1 + -0xaf) = 1;

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) + 0x60))();

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) + 0x80))();

    iVar1 = FUN_004ce940();

    if (iVar1 != 0) {

      iVar1 = (**(code **)(*(int *)(param_1 + -0x150) + 100))();

      if (iVar1 < 1) {

        iVar1 = 1;

      }

      *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x88 + param_1) = iVar1;

      pvStack_8 = (void *)0x0;

      pvStack_4 = (void *)0x0;

      FUN_005c9710(&pvStack_8);

      FUN_005c9780(&pvStack_4);

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) + 0x154))()

      ;

      FUN_005ca540(pvStack_8,0);

      FUN_005ca5e0(pvStack_4,0);

      if (pvStack_8 != (void *)0x0) {

        operator_delete__(pvStack_8);

      }

      pvStack_8 = (void *)0x0;

      if (pvStack_4 != (void *)0x0) {

        operator_delete__(pvStack_4);

      }

    }

  }

  return;

}
