// =============================================================================
// FUN_00629990
// -----------------------------------------------------------------------------
// Stable ID: aa_00629990
// Address:   0x00629990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00629990 @ 0x00629990
// Stable ID: aa_00629990
// Embedded strings (evidence for future rename):
//   - "TtNarrowPhase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×15, do×3, goto×3, while×3, return×1.
//  - Notable callees: rdtsc×2, FUN_00628920, FUN_006289b0, FUN_00629580, FUN_00629990.
//  - Strings: "TtNarrowPhase".
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

void __thiscall FUN_00629990(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint64_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  int *unaff_EBP;

  int *piVar6;

  float fVar7;

  float fVar8;

  uint8_t *local_1c;

  int local_18;

  uint8_t local_14 [8];

  float fStack_c;

  int local_8;

  int local_4;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtNarrowPhase";

    uVar1 = rdtsc();

    local_18 = (int)uVar1;

    DAT_00bc5644[1] = local_18;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_00629580();

  piVar6 = *(int **)(param_1 + 0x68);

  local_1c = local_14;

  iVar5 = *(int *)(param_1 + 0x6c);

  if (-1 < *(int *)(param_1 + 0x6c) + -1) {

    do {

      local_18 = iVar5;

      uVar2 = DAT_00aaaaa0;

      iVar5 = 0;

      if (piVar6[2] != 0) {

        *(uint32_t /* width from decompiler */ *)(local_1c + 4) = 0;

        if (piVar6[3] < 0) {

          *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) = 2;

          *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0x10) = uVar2;

          (**(code **)(*(int *)piVar6[2] + 0x10))

                    (*piVar6 + -0x10,piVar6[1] + -0x10,param_2,&local_1c);

          if ((piVar6[3] == -2) && (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) != 0)

             ) {

            iVar3 = 0;

            if (0 < unaff_EBP[1]) {

              pfVar4 = (float *)(*unaff_EBP + 0xc);

              do {

                if (*pfVar4 <= 0.0 && *pfVar4 != 0.0) goto LAB_00629b7b;

                iVar3 = iVar3 + 1;

                pfVar4 = pfVar4 + 0xc;

              } while (iVar3 < unaff_EBP[1]);

            }

LAB_00629b78:

            piVar6[3] = iVar5;

          }

        }

        else {

          iVar5 = *(int *)(param_1 + 0x20);

          fVar7 = (float)piVar6[3] * *(float *)(iVar5 + 0x248) + *(float *)(iVar5 + 0x244);

          *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x254) + 0xc) = 2;

          *(float *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0x10) = fVar7;

          (**(code **)(*(int *)piVar6[2] + 0x10))

                    (*piVar6 + -0x10,piVar6[1] + -0x10,param_2,&local_1c);

          if (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 0x254) + 0xc) == 0) {

LAB_00629ad1:

            piVar6[3] = piVar6[3] + 1;

            FUN_006289b0(param_2,piVar6,&stack0xffffffd4,

                         *(float *)(*(int *)(param_1 + 0x20) + 0x248) + fStack_c);

          }

          else {

            iVar5 = 0;

            if (0 < unaff_EBP[1]) {

              pfVar4 = (float *)(*unaff_EBP + 0xc);

              do {

                if (*pfVar4 <= fStack_c && fStack_c != *pfVar4) goto LAB_00629ad1;

                iVar5 = iVar5 + 1;

                pfVar4 = pfVar4 + 0xc;

                fVar7 = fStack_c;

              } while (iVar5 < unaff_EBP[1]);

            }

            if (0 < piVar6[3]) {

              iVar5 = piVar6[3] + -1;

              fVar8 = (float)iVar5 * *(float *)(*(int *)(param_1 + 0x20) + 0x248) +

                      *(float *)(*(int *)(param_1 + 0x20) + 0x244);

              FUN_00628920();

              if (fVar8 < fVar7) goto LAB_00629b78;

            }

          }

        }

LAB_00629b7b:

        (**(code **)(**(int **)(piVar6[2] + 8) + 0xc))

                  (*piVar6 + -0x10,piVar6[1] + -0x10,param_2,&stack0xffffffd4);

      }

      piVar6 = piVar6 + 4;

      iVar5 = local_18 + -1;

    } while (local_18 + -1 != 0);

    local_18 = 0;

  }

  piVar6 = DAT_00b05060;

  if ((local_4 * 0x30 == 0) || ((local_8 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] + local_4 * -0x30;

    piVar6[3] = piVar6[3] + local_4 * 0x30;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))();

  }

  if (-1 < (int)fStack_c) {

    (**(code **)(*DAT_00b05060 + 0x14))();

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
