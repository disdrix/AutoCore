// =============================================================================
// FUN_0073e720
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e720
// Address:   0x0073e720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073e720 @ 0x0073e720
// Stable ID: aa_0073e720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_0073e720.
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

uint32_t /* width from decompiler */ __fastcall FUN_0073e720(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int *piVar2;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_4;

  

  piVar2 = *(int **)(unaff_EDI + 4);

  local_4 = param_1;

  if (piVar2 == *(int **)(unaff_EDI + 8)) {

    return **(uint32_t /* width from decompiler */ **)(unaff_EDI + 4);

  }

  do {

    if (*piVar2 == 2) {

      iVar1 = (**(code **)(*(int *)piVar2[1] + 0x1c))((int *)piVar2[1],&local_4,4,0);

      if (iVar1 != 0) {

        return **(uint32_t /* width from decompiler */ **)(unaff_EDI + 4);

      }

      *piVar2 = 3;

      *(int **)(unaff_EDI + 4) = piVar2;

    }

    piVar2 = piVar2 + 2;

    if ((int *)(unaff_EDI + 0x28) < piVar2) {

      piVar2 = (int *)(unaff_EDI + 0x10);

    }

  } while (piVar2 != *(int **)(unaff_EDI + 8));

  return **(uint32_t /* width from decompiler */ **)(unaff_EDI + 4);

}
