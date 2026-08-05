// =============================================================================
// FUN_00524890
// -----------------------------------------------------------------------------
// Stable ID: aa_00524890
// Address:   0x00524890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00524890 @ 0x00524890
// Stable ID: aa_00524890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_004bc180, FUN_00524890.
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

void __thiscall FUN_00524890(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  

  if (*(int *)(param_1 + -0xb50) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xb50) + 4) + 4) + 4 +

                         *(int *)(param_1 + -0xb50)) + 0x2a4))(param_2);

  }

  if (*(int *)(param_1 + -0xe4) != 0) {

    (**(code **)(**(int **)(param_1 + -0xe4) + 8))(param_2);

  }

  iVar1 = *(int *)(*(int *)(param_1 + -0xd9c) + 4);

  iVar1 = CVOGReaction_ResolveObjectTarget

                    (*(uint8_t *)(iVar1 + -0xc34 + param_1),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + -0xc3c),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + -0xc38 + param_1));

  if (iVar1 == 0) {

    iVar1 = 0;

    if (param_1 != 0xda0) {

      iVar1 = *(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c + param_1;

    }

    FUN_004bc180(iVar1);

  }

  piVar2 = (int *)(param_1 + -0x7c0);

  iVar1 = 8;

  do {

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 0x2a4))(param_2);

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  piVar2 = (int *)**(int **)(param_1 + -0xd8);

  if (piVar2 != *(int **)(param_1 + -0xd8)) {

    do {

      (**(code **)(*(int *)piVar2[2] + 0x2a4))(param_2);

      piVar2 = (int *)*piVar2;

    } while (piVar2 != (int *)*(int *)(param_1 + -0xd8));

  }

  return;

}
