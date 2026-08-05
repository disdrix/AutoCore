// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069e2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069e2c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069e2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~172 non-empty decompiler lines.
//  - Control keywords: if×17, do×3, while×3, return×1.
//  - Notable callees: FUN_0069e2c0, FUN_006a2530, FUN_006a2580, FUN_006a26c0, SQRT.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069e2c0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,int param_4)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float *pfVar6;

  float *pfVar7;

  int iVar8;

  int *piVar9;

  float local_a8;

  float local_a4;

  float local_a0;

  float local_9c;

  float local_98;

  float local_94;

  float local_90;

  float local_8c;

  float local_88;

  float local_84;

  float local_80;

  int *local_7c;

  float local_78;

  int local_74;

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_34;

  float local_30;

  float local_28;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_4;

  

  if (((*(int *)(param_1 + 0x38) == 1) && (*(int *)(param_1 + 0x74) != 0)) && (0 < param_4)) {

    local_7c = (int *)(param_3 + 8);

    local_74 = param_4;

    do {

      piVar9 = (int *)local_7c[-1];

      if (piVar9 != (int *)*local_7c) {

        do {

          iVar1 = *piVar9;

          FUN_006a2530(&local_18);

          local_64 = 0.0;

          local_68 = 0.0;

          local_6c = 0.0;

          local_78 = -1.0;

          local_a0 = 0.0;

          local_a4 = 0.0;

          local_a8 = 0.0;

          iVar8 = 0;

          pfVar7 = (float *)&DAT_00af55e4;

          do {

            if ((&DAT_00d08f10)[iVar8] != '\0') {

              local_8c = pfVar7[-1];

              local_88 = *pfVar7;

              local_84 = pfVar7[1];

              if (pfVar7[0xb] == g_flZero) {

                pfVar6 = &local_8c;

              }

              else {

                pfVar6 = &local_48;

                local_48 = local_8c - *(float *)(iVar1 + 4);

                local_44 = local_88 - *(float *)(iVar1 + 8);

                local_40 = local_84 - *(float *)(iVar1 + 0xc);

              }

              local_9c = *pfVar6;

              local_98 = pfVar6[1];

              local_94 = pfVar6[2];

              fVar5 = g_flOne / SQRT(local_9c * local_9c + local_98 * local_98 + local_94 * local_94

                                    );

              local_9c = local_9c * fVar5;

              local_98 = local_98 * fVar5;

              fVar5 = local_9c * *(float *)(iVar1 + 0x1c) +

                      local_98 * *(float *)(iVar1 + 0x20) +

                      fVar5 * local_94 * *(float *)(iVar1 + 0x24);

              if (local_78 <= fVar5) {

                local_78 = fVar5;

                local_6c = local_8c;

                local_68 = local_88;

                local_64 = local_84;

              }

              if (fVar5 < g_flZero) {

                fVar5 = g_flZero;

              }

              local_80 = (g_flOne - *(float *)(param_1 + 0x70)) * fVar5 + *(float *)(param_1 + 0x70)

              ;

              if ((*(byte *)(param_1 + 0x74) & 1) != 0) {

                local_3c = *(float *)(param_1 + 0x60);

                local_60 = pfVar7[5] * *(float *)(param_1 + 0x48);

                local_34 = *(float *)(param_1 + 0x68);

                local_5c = pfVar7[6] * *(float *)(param_1 + 0x4c);

                local_58 = pfVar7[7] * *(float *)(param_1 + 0x50);

                fVar5 = g_flOne;

                if (pfVar7[0xb] != g_flZero) {

                  fVar2 = local_84 - *(float *)(iVar1 + 0xc);

                  fVar4 = local_88 - *(float *)(iVar1 + 8);

                  fVar3 = local_8c - *(float *)(iVar1 + 4);

                  local_70 = (float)(((int)(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3) >> 1) +

                                    0x1fc00000);

                  local_90 = (local_70 * pfVar7[0xe] + pfVar7[0xd]) * local_70 + pfVar7[0xc];

                  if (local_90 != g_flZero) {

                    fVar5 = g_flOne / local_90;

                  }

                }

                local_4 = local_10 * pfVar7[4] * local_80;

                local_30 = local_18 * pfVar7[2] * local_80 + local_60;

                local_28 = local_4 + local_58;

                local_54 = local_30 * fVar5;

                local_50 = (local_14 * pfVar7[3] * local_80 + local_5c) * fVar5;

                local_20 = local_50 + *(float *)(param_1 + 100);

                local_1c = fVar5 * local_28 + local_34;

                local_a8 = local_30 * fVar5 + local_3c + local_a8;

                local_a4 = local_20 + local_a4;

                local_a0 = local_1c + local_a0;

              }

            }

            pfVar7 = pfVar7 + 0x10;

            iVar8 = iVar8 + 1;

          } while ((int)pfVar7 < 0xaf57e4);

          if (g_flZero <= local_a8) {

            if (g_flOne < local_a8) {

              local_a8 = 1.0;

            }

          }

          else {

            local_a8 = 0.0;

          }

          if (g_flZero <= local_a4) {

            if (g_flOne < local_a4) {

              local_a4 = 1.0;

            }

          }

          else {

            local_a4 = 0.0;

          }

          if (g_flZero <= local_a0) {

            if (g_flOne < local_a0) {

              local_a0 = 1.0;

            }

          }

          else {

            local_a0 = 0.0;

          }

          if ((*(byte *)(param_1 + 0x74) & 1) != 0) {

            FUN_006a2580(&local_a8,0);

          }

          if ((*(byte *)(param_1 + 0x74) & 2) != 0) {

            FUN_006a26c0(param_2,&local_6c,*(uint32_t /* width from decompiler */ *)(param_1 + 0x70));

          }

          piVar9 = piVar9 + 1;

        } while (piVar9 != (int *)*local_7c);

      }

      local_7c = local_7c + 4;

      local_74 = local_74 + -1;

    } while (local_74 != 0);

  }

  return;

}
