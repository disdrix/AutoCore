// =============================================================================
// FUN_009873a0
// -----------------------------------------------------------------------------
// Stable ID: aa_009873a0
// Address:   0x009873a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009873a0 @ 0x009873a0
// Stable ID: aa_009873a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, while×5, do×4, return×4, for×1.
//  - Notable callees: FUN_0044ff40×8, FUN_009873a0.
//  - Return sites: 4.

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

void FUN_009873a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  char in_AL;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_ESI;

  

  uVar1 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

  if ((char)param_3 == '\0') {

    if (in_AL == '\0') {

      FUN_0044ff40(&param_3,uVar1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),&param_1,&LAB_0044fdb0);

      puVar3 = param_3;

      FUN_0044ff40(&param_3,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),

                   &param_2,&LAB_0044fdb0);

      puVar2 = param_3;

      for (; puVar3 != puVar2; puVar3 = puVar3 + -1) {

        (**(code **)(*(int *)puVar3[-1] + 8))();

      }

    }

    else {

      FUN_0044ff40(&param_3,uVar1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),&param_1,&LAB_0044fdb0);

      puVar3 = param_3;

      if (param_3 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10)) {

        do {

          (**(code **)(*(int *)puVar3[-1] + 8))();

          puVar3 = puVar3 + -1;

        } while (puVar3 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10));

      }

      FUN_0044ff40(&param_3,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),

                   &param_2,&LAB_0044fdb0);

      puVar2 = param_3;

      puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x14);

      if (puVar3 != param_3) {

        do {

          (**(code **)(*(int *)puVar3[-1] + 8))();

          puVar3 = puVar3 + -1;

        } while (puVar3 != puVar2);

        return;

      }

    }

  }

  else if (in_AL == '\0') {

    FUN_0044ff40(&param_3,uVar1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),&param_1,&LAB_0044fdb0);

    FUN_0044ff40(&param_1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),

                 &param_2,&LAB_0044fdb0);

    puVar3 = param_1;

    puVar2 = param_3;

    if (param_3 != param_1) {

      while (puVar2 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x14)) {

        (**(code **)(*(int *)*puVar2 + 8))();

        puVar2 = puVar2 + 1;

        if (puVar2 == puVar3) {

          return;

        }

      }

    }

  }

  else {

    FUN_0044ff40(&param_3,uVar1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),&param_1,&LAB_0044fdb0);

    puVar3 = param_3;

    if (param_3 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x14)) {

      do {

        (**(code **)(*(int *)*puVar3 + 8))();

        puVar3 = puVar3 + 1;

      } while (puVar3 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x14));

    }

    FUN_0044ff40(&param_3,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14),

                 &param_2,&LAB_0044fdb0);

    puVar2 = param_3;

    puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x10);

    if (puVar3 != param_3) {

      do {

        (**(code **)(*(int *)*puVar3 + 8))();

        puVar3 = puVar3 + 1;

      } while (puVar3 != puVar2);

      return;

    }

  }

  return;

}
