// =============================================================================
// FUN_0058ede0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058ede0
// Address:   0x0058ede0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058ede0 @ 0x0058ede0
// Stable ID: aa_0058ede0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0058ede0.
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

void FUN_0058ede0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 8)) {

    piVar2 = *(int **)(param_2 + 8);

    do {

      piVar4 = *(int **)(param_2 + 4);

      uVar1 = *puVar3;

      if (piVar4 != piVar2) {

        do {

          (**(code **)(*(int *)(*(int *)(*(int *)(*piVar4 + 4) + 4) + 4 + *piVar4) + 0xe8))(uVar1);

          piVar2 = *(int **)(param_2 + 8);

          piVar4 = piVar4 + 1;

        } while (piVar4 != piVar2);

      }

      puVar3 = puVar3 + 1;

    } while (puVar3 != *(uint32_t /* width from decompiler */ **)(param_1 + 8));

  }

  return;

}
