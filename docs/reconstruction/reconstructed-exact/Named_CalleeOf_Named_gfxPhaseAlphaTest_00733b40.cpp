// =============================================================================
// Named_CalleeOf_Named_gfxPhaseAlphaTest_00733b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00733b40
// Callee of Named_gfxPhaseAlphaTest
// Address:   0x00733b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxPhaseAlphaTest: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, do×2, while×2.
//  - Notable callees: FUN_0074f320×4, FUN_0074f360×3, FUN_0074fca0×3, FUN_0043b7d0×2, FUN_00733b40, FUN_0074dfd0, FUN_0074f200, FUN_0074fba0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_gfxPhaseAlphaTest
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxPhaseAlphaTest_00733b40(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  int iVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int iVar12;

  int *local_24;

  int local_20;

  

  iVar4 = DAT_00d1a54c;

  iVar9 = 0;

  if ((*(int *)(param_1 + 0xc) == 0) ||

     (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2 == 0)) {

    return 0;

  }

  if ((DAT_00d1a54c != 0) && (cVar8 = FUN_0074dfd0(DAT_00d1a54c), cVar8 != '\0')) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(iVar4 + 0x3c);

    piVar2 = (int *)puVar1[0x36];

    local_20 = 0;

    FUN_0074fca0(2);

    FUN_0074f320(0);

    FUN_0074fca0(2);

    FUN_0074f320(0);

    local_24 = *(int **)(param_1 + 0xc);

    piVar3 = *(int **)(param_1 + 0x10);

    if (local_24 != piVar3) {

      do {

        puVar11 = (uint32_t /* width from decompiler */ *)*local_24;

        if (((-1 < *(int *)(puVar11[2] + 0x24 + (int)piVar2 * 4)) && (puVar11[3] != 0)) &&

           ((*(uint *)(puVar11[3] + 0x1c) & puVar1[0x38]) == 0)) {

          iVar4 = puVar11[1];

          piVar5 = (int *)*puVar11;

          piVar6 = *(int **)(iVar4 + 8);

          cVar8 = (**(code **)(*piVar5 + 0x1c))();

          if (cVar8 != '\0') {

            (**(code **)(*piVar5 + 0xc))(puVar11);

            FUN_0043b7d0(3);

            if (local_20 != iVar4) {

              if ((piVar6 != local_24) || (puVar11[2] != iVar9)) {

                iVar9 = puVar11[2];

                FUN_0074fba0(iVar9);

                FUN_0074fca0(2);

                local_24 = piVar6;

              }

              FUN_0074f200(*(uint32_t /* width from decompiler */ *)(iVar4 + 0xc));

              FUN_0043b7d0(2);

              iVar7 = *(int *)(iVar9 + 0x24);

              if (((*(byte *)(*(int *)(iVar9 + 200) + iVar7 * 0x24 + 0x21) & 0x80) == 0) &&

                 (iVar12 = 0, 0 < iVar7)) {

                iVar10 = 0;

                do {

                  if ((*(byte *)(*(int *)(iVar9 + 200) + iVar10 + 0x20) & 3) != 0) {

                    FUN_0074f320(iVar12);

                  }

                  iVar12 = iVar12 + 1;

                  iVar10 = iVar10 + 0x24;

                  puVar11 = puVar1;

                } while (iVar12 < iVar7);

              }

              FUN_0074f320(iVar7);

              local_20 = iVar4;

            }

            (**(code **)(*piVar2 + 8))(puVar11);

          }

        }

        local_24 = local_24 + 1;

      } while (local_24 != piVar3);

      if (local_20 != 0) {

        FUN_0074f360();

      }

    }

    FUN_0074f360();

    FUN_0074f360();

    return 0;

  }

  return 1;

}
