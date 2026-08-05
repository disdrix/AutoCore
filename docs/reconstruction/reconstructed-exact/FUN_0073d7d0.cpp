// =============================================================================
// FUN_0073d7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d7d0
// Address:   0x0073d7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073d7d0 @ 0x0073d7d0
// Stable ID: aa_0073d7d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×6, while×2, return×2, do×1.
//  - Notable callees: FUN_00456e50, FUN_0073d7d0.
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

void __fastcall FUN_0073d7d0(int param_1)



{

  int *piVar1;

  int in_EAX;

  int *piVar2;

  

  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {

    piVar2 = *(int **)(in_EAX + 4);

    if (piVar2 != *(int **)(in_EAX + 8)) {

      while (*piVar2 != *(int *)(param_1 + 8)) {

        piVar2 = piVar2 + 5;

        if (piVar2 == *(int **)(in_EAX + 8)) {

          return;

        }

      }

      piVar1 = (int *)piVar2[3];

      piVar2 = (int *)piVar2[2];

      if (piVar2 != piVar1) {

        do {

          if (*piVar2 == param_1) break;

          piVar2 = piVar2 + 1;

        } while (piVar2 != piVar1);

        if (piVar2 != piVar1) {

          FUN_00456e50(piVar2);

        }

      }

    }

  }

  return;

}
