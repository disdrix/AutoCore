// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxGeometryPiece_0099a6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099a6b0
// Callee of Named_CalleeOf_Named_gfxGeometryPiece (+1 other named callers)
// Address:   0x0099a6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_gfxGeometryPiece (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×9, for×2, return×1.
//  - Notable callees: FUN_00414aa0×2, FUN_00414cd0, FUN_00447ea0, FUN_00746520, FUN_00986a60, FUN_00999960, FUN_0099a6b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxGeometryPiece (+1 other named callers)
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

int __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxGeometryPiece_0099a6b0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1a5e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_10 = (uint32_t /* width from decompiler */ *)FUN_00414cd0();

  iVar6 = 0;

  local_4 = 0;

  if (local_10 != (uint32_t /* width from decompiler */ *)0x0) {

    iVar6 = FUN_00999960();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  FUN_00447ea0();

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x34);

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  if (*(int *)(param_1 + 0x10) != 0) {

    iVar3 = FUN_00986a60(DAT_00d1f634,iVar6,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 4));

    if ((-1 < iVar3) && (*(int *)(param_1 + 0x10) != 0)) {

      local_10 = (uint32_t /* width from decompiler */ *)

                 FUN_00746520(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14),*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),4);

      if (local_10 != (uint32_t /* width from decompiler */ *)0x0) {

        piVar1 = *(int **)(iVar6 + 0x10);

        if (piVar1 != (int *)0x0) {

          piVar2 = (int *)*piVar1;

          local_14 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0x18);

          if (piVar2 != (int *)0x0) {

            iVar3 = (**(code **)(*piVar2 + 0x2c))

                              (piVar2,piVar1[2] * *(int *)(iVar6 + 0x14),piVar1[2] * (int)local_14,

                               &local_14,0x800);

            if (-1 < iVar3) {

              piVar1[4] = piVar1[4] + 1;

              if (local_14 != (uint32_t /* width from decompiler */ *)0x0) {

                uVar4 = *(int *)(*(int *)(param_1 + 0x10) + 8) * *(int *)(param_1 + 0x18);

                puVar7 = local_10;

                puVar8 = local_14;

                for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

                  *puVar8 = *puVar7;

                  puVar7 = puVar7 + 1;

                  puVar8 = puVar8 + 1;

                }

                for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

                  *(uint8_t *)puVar8 = *(uint8_t *)puVar7;

                  puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

                  puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

                }

              }

            }

          }

        }

        FUN_00414aa0();

        FUN_00414aa0();

        iVar3 = DAT_00d1f614;

        if (DAT_00d1f614 != 0) {

          *(int *)(DAT_00d1f614 + 0x388) =

               *(int *)(DAT_00d1f614 + 0x388) +

               *(int *)(*(int *)(param_1 + 0x10) + 8) * *(int *)(param_1 + 0x18);

          piVar1 = (int *)(iVar3 + 0x338);

          *piVar1 = *piVar1 + *(int *)(param_1 + 0x18);

          piVar1 = (int *)(iVar3 + 0x334);

          *piVar1 = *piVar1 + 1;

        }

      }

    }

  }

  *(uint32_t /* width from decompiler */ *)(iVar6 + 0x1c) = param_2;

  ExceptionList = local_c;

  return iVar6;

}
