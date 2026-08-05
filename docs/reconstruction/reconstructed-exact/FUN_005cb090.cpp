// =============================================================================
// FUN_005cb090
// -----------------------------------------------------------------------------
// Stable ID: aa_005cb090
// Address:   0x005cb090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cb090 @ 0x005cb090
// Stable ID: aa_005cb090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_005c9a00×4, FUN_004ce940, FUN_005097b0, FUN_005cb090.
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

void __fastcall FUN_005cb090(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint16_t *puVar7;

  

  iVar2 = FUN_004ce940();

  iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xbc) + 4) + -0xbc + param_1) + 0x60))

                    ();

  if ((iVar3 != 0) && (iVar2 != 0)) {

    iVar2 = FUN_005c9a00();

    puVar7 = *(uint16_t **)(iVar2 + 4);

    iVar2 = FUN_005c9a00();

    if (puVar7 != *(uint16_t **)(iVar2 + 8)) {

      puVar6 = (uint32_t /* width from decompiler */ *)(puVar7 + 2);

      do {

        piVar4 = (int *)FUN_005097b0(*puVar7);

        if ((piVar4 == (int *)0x0) || (*piVar4 == -1)) {

          iVar2 = FUN_005c9a00();

          puVar1 = *(uint32_t /* width from decompiler */ **)(iVar2 + 8);

          if (puVar6 != puVar1) {

            puVar5 = puVar6;

            do {

              *(uint32_t /* width from decompiler */ *)(((int)puVar7 - (int)puVar6) + (int)puVar5) = *puVar5;

              puVar5 = puVar5 + 1;

            } while (puVar5 != puVar1);

          }

          *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -4;

        }

        else {

          puVar7 = puVar7 + 2;

          puVar6 = puVar6 + 1;

        }

        iVar2 = FUN_005c9a00();

      } while (puVar7 != *(uint16_t **)(iVar2 + 8));

    }

  }

  return;

}
