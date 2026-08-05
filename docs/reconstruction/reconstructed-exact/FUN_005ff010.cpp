// =============================================================================
// FUN_005ff010
// -----------------------------------------------------------------------------
// Stable ID: aa_005ff010
// Address:   0x005ff010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ff010 @ 0x005ff010
// Stable ID: aa_005ff010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004ce940, FUN_005c9710, FUN_005c9780, FUN_005ca540, FUN_005ca5e0, FUN_005ff010, ROUND.
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

void __fastcall FUN_005ff010(int param_1)



{

  int iVar1;

  float10 fVar2;

  void *pvStack_c;

  void *pvStack_8;

  int iStack_4;

  

  if (*(char *)(param_1 + -0x3f) == '\0') {

    *(uint8_t *)(param_1 + -0x3f) = 1;

    iVar1 = FUN_004ce940();

    if (iVar1 != 0) {

      fVar2 = (float10)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc +

                                            param_1) + 0x180))();

      iStack_4 = (int)ROUND(fVar2);

      *(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x18 + param_1) = iStack_4;

      pvStack_c = (void *)0x0;

      pvStack_8 = (void *)0x0;

      FUN_005c9710(&pvStack_c);

      FUN_005c9780(&pvStack_8);

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0x154))();

      FUN_005ca540(pvStack_c,0);

      FUN_005ca5e0(pvStack_8,0);

      if (pvStack_c != (void *)0x0) {

        operator_delete__(pvStack_c);

      }

      pvStack_c = (void *)0x0;

      if (pvStack_8 != (void *)0x0) {

        operator_delete__(pvStack_8);

      }

    }

  }

  return;

}
