// =============================================================================
// FUN_00988b50
// -----------------------------------------------------------------------------
// Stable ID: aa_00988b50
// Address:   0x00988b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00988b50 @ 0x00988b50
// Stable ID: aa_00988b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0044b8b0×4, FUN_0044b8f0, FUN_00988b50.
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

uint32_t /* width from decompiler */ __fastcall

FUN_00988b50(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4,int param_5)



{

  int *piVar1;

  int *piVar2;

  short *in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint uVar6;

  short *psVar7;

  short *local_4;

  

  piVar1 = *(int **)(param_3 + 0x10);

  if ((piVar1 != (int *)0x0) && (param_4 != 0)) {

    if ((int)in_EAX < 1) {

      in_EAX = (short *)(*(int *)(param_3 + 0x1c) - param_2);

    }

    local_4 = in_EAX;

    if ((int)in_EAX < 1) {

      local_4 = (short *)(*(int *)(param_3 + 0x1c) - param_2);

    }

    piVar2 = (int *)*piVar1;

    if (((piVar2 != (int *)0x0) &&

        (iVar3 = (**(code **)(*piVar2 + 0x2c))

                           (piVar2,piVar1[4] * (*(int *)(param_3 + 0x18) + param_2),

                            piVar1[4] * (int)local_4,&local_4,0x800), psVar7 = local_4, -1 < iVar3))

       && (piVar1[3] = piVar1[3] + 1, local_4 != (short *)0x0)) {

      if ((int)*(short **)(param_4 + 0x1c) < (int)in_EAX) {

        in_EAX = *(short **)(param_4 + 0x1c);

      }

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0044b8f0(0,in_EAX,0x810);

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        if (param_5 == 0) {

          uVar5 = *(int *)(param_3 + 0x14) * (int)in_EAX;

          for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

            *(uint32_t /* width from decompiler */ *)psVar7 = *puVar4;

            puVar4 = puVar4 + 1;

            psVar7 = psVar7 + 2;

          }

          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

            *(uint8_t *)psVar7 = *(uint8_t *)puVar4;

            puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

            psVar7 = (short *)((int)psVar7 + 1);

          }

        }

        else if (0 < (int)in_EAX) {

          iVar3 = (int)puVar4 - (int)psVar7;

          do {

            *psVar7 = *(short *)(iVar3 + (int)psVar7) + (short)param_5;

            psVar7 = psVar7 + 1;

            in_EAX = (short *)((int)in_EAX + -1);

          } while (in_EAX != (short *)0x0);

        }

        FUN_0044b8b0();

        FUN_0044b8b0();

        return 0;

      }

      FUN_0044b8b0();

    }

    FUN_0044b8b0();

  }

  return 0xffffffff;

}
