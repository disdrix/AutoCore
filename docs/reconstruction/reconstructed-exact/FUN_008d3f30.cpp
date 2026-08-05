// =============================================================================
// FUN_008d3f30
// -----------------------------------------------------------------------------
// Stable ID: aa_008d3f30
// Address:   0x008d3f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d3f30 @ 0x008d3f30
// Stable ID: aa_008d3f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_008cfa00×3, FUN_008d19f0×2, FUN_008d1c70×2, CVOGReaction_RandomUnitScalar, FUN_00424830, FUN_00524ad0, FUN_008d2650, FUN_008d2b10.
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

void __fastcall FUN_008d3f30(int param_1)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  

  FUN_008d7f80();

  if ((*(int *)(param_1 + 0x544) != 0) && (*(int *)(*(int *)(param_1 + 0x544) + 0x48) != 0)) {

    iVar1 = *(int *)(param_1 + 0x5a4) +

            (*(int *)(param_1 + 0x5ac) + *(int *)(param_1 + 0x5a8) * 4) * 2;

    if (*(char *)(iVar1 + 0x5c3 + param_1) == '\0') {

      FUN_008d1c70();

      FUN_008d19f0();

    }

    else {

      *(uint8_t *)(iVar1 + 0x5c3 + param_1) = 0;

      FUN_00524ad0();

      FUN_008d1c70();

      if ((*(int *)(param_1 + 0x8e0) != 0) &&

         (1 < (uint)(*(int *)(param_1 + 0x8e4) - *(int *)(param_1 + 0x8e0) >> 2))) {

        CVOGReaction_RandomUnitScalar();

        if (*(int *)(param_1 + 0x8e0) == 0) {

          uVar3 = 0;

        }

        else {

          uVar3 = *(int *)(param_1 + 0x8e4) - *(int *)(param_1 + 0x8e0) >> 2;

        }

        uVar2 = FUN_00424830();

        FUN_008d2650(uVar2 % uVar3 - *(int *)(param_1 + 0x824));

      }

      FUN_008d19f0();

      FUN_008d2b10();

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x544) + 4) + 4) + 4 +

                         *(int *)(param_1 + 0x544)) + 0xb8))

              (*(float *)(param_1 + 0x5b0) + DAT_00aaaa1c);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x544) + 0x48) + 0x10))(3);

    (**(code **)(**(int **)(*(int *)(param_1 + 0x544) + 0x48) + 0x34))();

    iVar1 = *(int *)(param_1 + 0x568);

    if (iVar1 == 0) {

      FUN_008d3a70();

    }

    else {

      if (iVar1 == 1) {

        FUN_008d3c90();

        FUN_008cfa00(param_1);

        return;

      }

      if (iVar1 == 2) {

        FUN_008d3b30();

        FUN_008cfa00(param_1);

        return;

      }

    }

    FUN_008cfa00(param_1);

  }

  return;

}
