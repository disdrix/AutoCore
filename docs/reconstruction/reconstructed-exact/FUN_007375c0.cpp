// =============================================================================
// FUN_007375c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007375c0
// Address:   0x007375c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007375c0 @ 0x007375c0
// Stable ID: aa_007375c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, return×1.
//  - Notable callees: FUN_007375c0, FUN_00748260.
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

void __fastcall FUN_007375c0(int param_1)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  

  piVar2 = *(int **)(param_1 + 200);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 200) = 0;

  }

  iVar3 = *(int *)(param_1 + 0xd4);

  if (iVar3 != *(int *)(param_1 + 0xd8)) {

    do {

      piVar2 = *(int **)(iVar3 + 4);

      if (piVar2 != (int *)0x0) {

        piVar1 = piVar2 + 1;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar2 + 8))();

        }

        *(uint32_t /* width from decompiler */ *)(iVar3 + 4) = 0;

      }

      iVar3 = iVar3 + 8;

    } while (iVar3 != *(int *)(param_1 + 0xd8));

  }

  piVar2 = *(int **)(param_1 + 0xe4);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

  }

  FUN_00748260();

  piVar2 = *(int **)(param_1 + 0x20);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0;

  return;

}
