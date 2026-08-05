// =============================================================================
// Named_CalleeOf_CVOGTacArc_UpdateMesh_0056a680
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a680
// Callee of CVOGTacArc_UpdateMesh
// Address:   0x0056a680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGTacArc_UpdateMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_0040dab0, FUN_0056a680.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGTacArc_UpdateMesh
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_CVOGTacArc_UpdateMesh_0056a680(int param_1,char param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fVar5;

  float fVar6;

  

  if ((param_2 == '\0') &&

     (piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1), piVar1 != (int *)0x0

     )) {

    iVar2 = (**(code **)(*piVar1 + 0x214))();

    if (iVar2 != 0) {

      iVar2 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x214)

              )();

      if (*(float *)(iVar2 + 0x1e8) != g_flOne) {

        iVar2 = *(int *)(param_1 + 0xd0);

        iVar3 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) +

                            0x214))();

        fVar5 = *(float *)(iVar3 + 0x1e8) * (float)iVar2;

        if (0.0 <= fVar5) {

          fVar6 = fVar5 + g_flMissionXpRoundBias;

        }

        else {

          fVar6 = fVar5 - g_flMissionXpRoundBias;

        }

        if (500 < (int)fVar6) {

          uVar4 = FUN_0040dab0(fVar5);

          return uVar4;

        }

        return 500;

      }

    }

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0);

}
