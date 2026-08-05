// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068f520
// -----------------------------------------------------------------------------
// Stable ID: aa_0068f520
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068f520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~211 non-empty decompiler lines.
//  - Control keywords: if×18, do×12, while×12, return×1.
//  - Notable callees: FUN_0068f520, _eh_vector_constructor_iterator_.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068f520(char *param_1,ushort param_2,uint param_3)



{

  int *piVar1;

  uint *puVar2;

  void *pvVar3;

  int iVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  uint *puVar8;

  uint uVar9;

  int iVar10;

  int *piVar11;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa57b;

  local_c = ExceptionList;

  puVar8 = (uint *)0x0;

  if ((((param_3 != 0) && (*(int *)(param_1 + 0x10) != 0)) && (*(int *)(param_1 + 4) != 0)) &&

     (*(int *)(param_1 + 0x14) != 0)) {

    uVar9 = (uint)param_2;

    ExceptionList = &local_c;

    *(ushort *)(param_1 + 0x28) = param_2;

    puVar2 = operator_new__(uVar9 * 0x44 + 4);

    local_4 = 0;

    if (puVar2 != (uint *)0x0) {

      puVar8 = puVar2 + 1;

      *puVar2 = uVar9;

      _eh_vector_constructor_iterator_(puVar8,0x44,uVar9,FUN_0068e7e0,FUN_0068e800);

    }

    local_4 = 0xffffffff;

    *(uint **)(param_1 + 0x2c) = puVar8;

    if (param_2 != 0) {

      local_10 = 0;

      _param_2 = 0;

      piVar11 = (int *)(param_3 + 4);

      param_3 = uVar9;

      do {

        iVar10 = *(int *)(param_1 + 0x2c) + _param_2;

        if (*piVar11 == 0) {

          uVar9 = 0;

        }

        else {

          uVar9 = piVar11[1] - *piVar11 >> 2;

        }

        *(short *)(iVar10 + 0xc) = (short)uVar9;

        pvVar3 = operator_new__((uVar9 & 0xffff) << 2);

        *(void **)(iVar10 + 0x20) = pvVar3;

        iVar4 = 0;

        if (*(short *)(iVar10 + 0xc) != 0) {

          do {

            piVar1 = (int *)(*piVar11 + iVar4 * 4);

            *(uint *)(*(int *)(iVar10 + 0x20) + iVar4 * 4) =

                 ((uint)*(byte *)(*piVar1 + 0x40) * (uint)*(ushort *)(param_1 + 8) +

                 (uint)*(byte *)(*piVar1 + 0x10)) * 0x40 +

                 *(int *)(*(int *)(param_1 + 0x10) + local_10);

            iVar4 = iVar4 + 1;

          } while (iVar4 < (int)(uint)*(ushort *)(iVar10 + 0xc));

        }

        if (param_1[1] != '\0') {

          pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) * 0xc);

          iVar4 = 0;

          *(void **)(iVar10 + 0x40) = pvVar3;

          if (*(short *)(iVar10 + 0xc) != 0) {

            iVar7 = 0;

            do {

              iVar6 = *(int *)(*piVar11 + iVar4 * 4);

              pfVar5 = (float *)(*(int *)(iVar10 + 0x40) + iVar7);

              *pfVar5 = -*(float *)(iVar6 + 4);

              pfVar5[1] = *(float *)(iVar6 + 0xc);

              pfVar5[2] = *(float *)(iVar6 + 8);

              iVar4 = iVar4 + 1;

              iVar7 = iVar7 + 0xc;

            } while (iVar4 < (int)(uint)*(ushort *)(iVar10 + 0xc));

          }

          pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) << 2);

          iVar4 = 0;

          *(void **)(iVar10 + 0x34) = pvVar3;

          if (*(short *)(iVar10 + 0xc) != 0) {

            do {

              iVar7 = iVar4 * 4;

              iVar4 = iVar4 + 1;

              *(float *)(iVar7 + *(int *)(iVar10 + 0x34)) =

                   g_flOne - *(float *)(*(int *)(*piVar11 + iVar7) + 0x44);

            } while (iVar4 < (int)(uint)*(ushort *)(iVar10 + 0xc));

          }

          pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc));

          *(void **)(iVar10 + 0x38) = pvVar3;

          if (*(short *)(iVar10 + 0xc) != 0) {

            iVar4 = 0;

            do {

              *(char *)(iVar4 + *(int *)(iVar10 + 0x38)) =

                   (char)((ulonglong)*(byte *)(*(int *)(*piVar11 + iVar4 * 4) + 0x48) %

                         (ulonglong)(longlong)(int)(uint)*(byte *)(*(int *)(param_1 + 4) + 0x2c)) +

                   *(char *)(*(int *)(param_1 + 4) + 0x28);

              iVar4 = iVar4 + 1;

            } while (iVar4 < (int)(uint)*(ushort *)(iVar10 + 0xc));

          }

        }

        pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) * 0xc);

        uVar9 = 0;

        *(void **)(iVar10 + 0x18) = pvVar3;

        if (*(short *)(iVar10 + 0xc) != 0) {

          iVar4 = 0;

          do {

            iVar7 = *(int *)(*piVar11 + uVar9 * 4);

            pfVar5 = (float *)(*(int *)(iVar10 + 0x18) + iVar4);

            *pfVar5 = -*(float *)(iVar7 + 4);

            pfVar5[1] = *(float *)(iVar7 + 0xc);

            pfVar5[2] = *(float *)(iVar7 + 8);

            uVar9 = uVar9 + 1;

            iVar4 = iVar4 + 0xc;

          } while (uVar9 < *(ushort *)(iVar10 + 0xc));

        }

        pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc));

        *(void **)(iVar10 + 0x10) = pvVar3;

        uVar9 = 0;

        if (*(short *)(iVar10 + 0xc) != 0) {

          do {

            *(uint8_t *)(uVar9 + *(int *)(iVar10 + 0x10)) =

                 *(uint8_t *)(*(int *)(*piVar11 + uVar9 * 4) + 0x40);

            uVar9 = uVar9 + 1;

          } while (uVar9 < *(ushort *)(iVar10 + 0xc));

        }

        pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc));

        uVar9 = 0;

        *(void **)(iVar10 + 0x14) = pvVar3;

        if (*(short *)(iVar10 + 0xc) != 0) {

          do {

            iVar4 = *(int *)(*piVar11 + uVar9 * 4);

            *(char *)(uVar9 + *(int *)(iVar10 + 0x14)) =

                 *(char *)(iVar4 + 0x40) * param_1[8] + *(char *)(iVar4 + 0x10);

            uVar9 = uVar9 + 1;

          } while (uVar9 < *(ushort *)(iVar10 + 0xc));

        }

        pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) << 2);

        *(void **)(iVar10 + 0x1c) = pvVar3;

        if (*(short *)(iVar10 + 0xc) != 0) {

          uVar9 = 0;

          do {

            *(uint *)(uVar9 * 4 + *(int *)(iVar10 + 0x1c)) =

                 (uint)*(byte *)(*(int *)(*piVar11 + uVar9 * 4) + 0x40) * 0x20 +

                 *(int *)(param_1 + 0x14);

            uVar9 = uVar9 + 1;

          } while (uVar9 < *(ushort *)(iVar10 + 0xc));

        }

        pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) << 2);

        uVar9 = 0;

        *(void **)(iVar10 + 0x24) = pvVar3;

        if (*(short *)(iVar10 + 0xc) != 0) {

          do {

            *(uint32_t /* width from decompiler */ *)(uVar9 * 4 + *(int *)(iVar10 + 0x24)) =

                 *(uint32_t /* width from decompiler */ *)(*(int *)(*piVar11 + uVar9 * 4) + 0x14);

            uVar9 = uVar9 + 1;

          } while (uVar9 < *(ushort *)(iVar10 + 0xc));

        }

        if (*param_1 == '\0') {

          pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) * 0xc);

          uVar9 = 0;

          *(void **)(iVar10 + 0x28) = pvVar3;

          if (*(short *)(iVar10 + 0xc) != 0) {

            iVar4 = 0;

            do {

              iVar7 = *(int *)(*piVar11 + uVar9 * 4);

              pfVar5 = (float *)(*(int *)(iVar10 + 0x28) + iVar4);

              *pfVar5 = -*(float *)(iVar7 + 0x1c);

              pfVar5[1] = *(float *)(iVar7 + 0x24);

              pfVar5[2] = *(float *)(iVar7 + 0x20);

              uVar9 = uVar9 + 1;

              iVar4 = iVar4 + 0xc;

            } while (uVar9 < *(ushort *)(iVar10 + 0xc));

          }

          if (*param_1 == '\0') {

            pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) * 0xc);

            *(void **)(iVar10 + 0x30) = pvVar3;

            pvVar3 = operator_new__((uint)*(ushort *)(iVar10 + 0xc) * 0xc);

            uVar9 = 0;

            *(void **)(iVar10 + 0x2c) = pvVar3;

            if (*(short *)(iVar10 + 0xc) != 0) {

              iVar4 = 0;

              do {

                iVar7 = *(int *)(*piVar11 + uVar9 * 4);

                iVar6 = *(int *)(iVar10 + 0x30);

                *(float *)(iVar6 + iVar4) = -*(float *)(iVar7 + 0x28);

                iVar6 = iVar6 + iVar4;

                *(uint32_t /* width from decompiler */ *)(iVar6 + 4) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x30);

                *(uint32_t /* width from decompiler */ *)(iVar6 + 8) = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x2c);

                iVar7 = *(int *)(*piVar11 + uVar9 * 4);

                pfVar5 = (float *)(*(int *)(iVar10 + 0x2c) + iVar4);

                *pfVar5 = -*(float *)(iVar7 + 0x34);

                pfVar5[1] = *(float *)(iVar7 + 0x3c);

                pfVar5[2] = *(float *)(iVar7 + 0x38);

                uVar9 = uVar9 + 1;

                iVar4 = iVar4 + 0xc;

              } while (uVar9 < *(ushort *)(iVar10 + 0xc));

            }

          }

        }

        _param_2 = _param_2 + 0x44;

        local_10 = local_10 + 4;

        piVar11 = piVar11 + 4;

        param_3 = param_3 - 1;

      } while (param_3 != 0);

    }

  }

  ExceptionList = local_c;

  return;

}
