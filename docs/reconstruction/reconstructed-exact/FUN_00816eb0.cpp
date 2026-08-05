// =============================================================================
// FUN_00816eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00816eb0
// Address:   0x00816eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00816eb0 @ 0x00816eb0
// Stable ID: aa_00816eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00816eb0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00816eb0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  

  piVar1 = *(int **)(param_2 + 0x714);

  piVar2 = (int *)*piVar1;

  if (piVar2 != piVar1) {

    do {

      if (*(int *)(piVar2[2] + 4) == *(int *)(param_2 + 0x70c)) {

        return *(uint32_t /* width from decompiler */ *)piVar2[2];

      }

      piVar2 = (int *)*piVar2;

    } while (piVar2 != piVar1);

  }

  return 0;

}
