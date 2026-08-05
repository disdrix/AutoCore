// =============================================================================
// FUN_00518870
// -----------------------------------------------------------------------------
// Stable ID: aa_00518870
// Address:   0x00518870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00518870 @ 0x00518870
// Stable ID: aa_00518870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, while×2, do×1, return×1.
//  - Notable callees: FUN_00518870.
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

void __thiscall FUN_00518870(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(param_2 + 8)) {

    do {

      iVar4 = CVOGReaction_ResolveObjectTarget

                        (*(uint8_t *)(*(int *)(param_1 + 0xa4) + 0x7d),*puVar5,puVar5[1]);

      if ((iVar4 == 0) || ((0 < param_3 && (*(int *)(*(int *)(iVar4 + 0xa8) + 0x38) != param_3)))) {

        puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

        puVar2 = puVar5;

        puVar3 = puVar5;

        while (puVar3 = puVar3 + 4, puVar3 != puVar1) {

          *puVar2 = *puVar3;

          puVar2[1] = puVar3[1];

          puVar2[2] = puVar3[2];

          puVar2[3] = puVar3[3];

          puVar2 = puVar2 + 4;

        }

        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -0x10;

      }

      else {

        puVar5 = puVar5 + 4;

      }

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(param_2 + 8));

  }

  return;

}
