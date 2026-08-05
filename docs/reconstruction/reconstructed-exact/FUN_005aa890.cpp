// =============================================================================
// FUN_005aa890
// -----------------------------------------------------------------------------
// Stable ID: aa_005aa890
// Address:   0x005aa890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005aa890 @ 0x005aa890
// Stable ID: aa_005aa890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_005aa890, FUN_005ac0d0, FUN_005ac550.
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

uint32_t /* width from decompiler */ __fastcall FUN_005aa890(int param_1)



{

  void *pvVar1;

  int *piVar2;

  int *piVar3;

  int local_4;

  

  piVar2 = *(int **)(param_1 + 0x510c);

  piVar3 = (int *)*piVar2;

  local_4 = param_1;

  if (piVar3 != piVar2) {

    do {

      pvVar1 = (void *)piVar3[10];

      if (pvVar1 != (void *)0x0) {

        FUN_005ac0d0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      piVar3[10] = 0;

      FUN_005ac550(&local_4,piVar3);

      piVar2 = *(int **)(param_1 + 0x510c);

      piVar3 = (int *)*piVar2;

    } while (piVar3 != piVar2);

  }

  return CONCAT31((int3)((uint)piVar2 >> 8),1);

}
