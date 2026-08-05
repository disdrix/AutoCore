// =============================================================================
// FUN_00555050
// -----------------------------------------------------------------------------
// Stable ID: aa_00555050
// Address:   0x00555050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00555050 @ 0x00555050
// Stable ID: aa_00555050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_00553d20×9, FUN_00553f50×2, FUN_004b73c0, FUN_004b8dc0, FUN_00555050.
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

void __fastcall FUN_00555050(int param_1)



{

  uint8_t uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  iVar5 = 0;

  do {

    if (iVar5 < 1) {

      iVar4 = *(int *)(param_1 + 0x17c);

    }

    else {

      iVar4 = *(int *)(param_1 + 0x180);

    }

    if (iVar4 != 0) {

      if (*(int *)(iVar4 + 0x434) != 0) {

        if ((*(int *)(iVar4 + 0x438) - *(int *)(iVar4 + 0x434)) / 0x134 != 0) {

          iVar2 = FUN_00553d20(0);

          if (iVar2 != 0) {

            iVar2 = FUN_00553d20(0);

            uVar1 = *(uint8_t *)(iVar2 + 0xb);

            uVar7 = 0x3f800000;

            uVar3 = FUN_00553d20(1);

            FUN_00553f50(uVar1,uVar3,uVar7);

            fVar6 = g_flOne - *(float *)(iVar4 + 0x554);

            iVar2 = FUN_00553d20(0);

            *(float *)(iVar2 + 0x38) = fVar6;

          }

          iVar2 = FUN_00553d20(0);

          if (iVar2 != 0) {

            iVar2 = FUN_00553d20(0);

            uVar1 = *(uint8_t *)(iVar2 + 0xb);

            uVar7 = 0x3f800000;

            uVar3 = FUN_00553d20(1);

            FUN_00553f50(uVar1,uVar3,uVar7);

            uVar3 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x554);

            iVar4 = FUN_00553d20(0);

            *(uint32_t /* width from decompiler */ *)(iVar4 + 0x38) = uVar3;

          }

        }

      }

      iVar4 = FUN_00553d20(1);

      if ((iVar4 != 0) && (*(int *)(param_1 + 0x188) != 0)) {

        FUN_004b73c0(*(int *)(*(int *)(*(int *)(param_1 + 0x188) + 4) + 4) + 4 +

                     *(int *)(param_1 + 0x188));

        FUN_004b8dc0(1,0);

        *(float *)(iVar4 + 0x38) = g_flOne;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

      }

    }

    iVar5 = iVar5 + 1;

  } while (iVar5 < 2);

  return;

}
