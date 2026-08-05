// =============================================================================
// Named_CalleeOf_Named_gfxDevice_0096c8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096c8e0
// Callee of Named_gfxDevice (+1 other named callers)
// Address:   0x0096c8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxDevice: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxDevice (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×19, return×1.
//  - Notable callees: FUN_0096c730×4, FUN_0096c810×3, FUN_0096bb20, FUN_0096c8e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxDevice (+1 other named callers)
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

void __fastcall Named_CalleeOf_Named_gfxDevice_0096c8e0(int param_1)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  

  if (*(int *)(param_1 + 0x10) != 0) {

    uVar1 = *(uint *)(param_1 + 0x2c);

    if ((uVar1 & 0x1000) == 0) {

      if (*(int *)(param_1 + 0x14) == 0) {

        if ((uVar1 & 0xf) == 2) {

          iVar4 = FUN_0096c730();

          iVar3 = DAT_00d1f614;

          if (DAT_00d1f614 != 0) {

            *(int *)(DAT_00d1f614 + 0x3a0) = *(int *)(DAT_00d1f614 + 0x3a0) - iVar4;

            *(int *)(iVar3 + 0x358) = *(int *)(iVar3 + 0x358) + -1;

          }

        }

        else if ((uVar1 & 0xf) == 4) {

          iVar4 = FUN_0096c730();

          iVar3 = DAT_00d1f614;

          if (DAT_00d1f614 != 0) {

            *(int *)(DAT_00d1f614 + 0x3a8) = *(int *)(DAT_00d1f614 + 0x3a8) - iVar4;

            *(int *)(iVar3 + 0x360) = *(int *)(iVar3 + 0x360) + -1;

          }

        }

        else {

          iVar4 = FUN_0096c730();

          iVar3 = DAT_00d1f614;

          if (DAT_00d1f614 != 0) {

            *(int *)(DAT_00d1f614 + 0x398) = *(int *)(DAT_00d1f614 + 0x398) - iVar4;

            *(int *)(iVar3 + 0x350) = *(int *)(iVar3 + 0x350) + -1;

          }

        }

      }

      else {

        if (DAT_00d1f614 != 0) {

          *(int *)(DAT_00d1f614 + 0x364) = *(int *)(DAT_00d1f614 + 0x364) + -1;

        }

        iVar4 = FUN_0096c730();

        iVar3 = DAT_00d1f614;

        if (DAT_00d1f614 != 0) {

          *(int *)(DAT_00d1f614 + 0x3ac) = *(int *)(DAT_00d1f614 + 0x3ac) - iVar4;

        }

        if ((*(int *)(param_1 + 0x18) != 0) && (iVar3 != 0)) {

          *(int *)(iVar3 + 0x368) = *(int *)(iVar3 + 0x368) + -1;

          iVar4 = FUN_0096bb20();

          *(int *)(iVar3 + 0x3b0) = *(int *)(iVar3 + 0x3b0) - iVar4;

        }

      }

    }

    else if ((uVar1 & 0xf) == 2) {

      iVar4 = FUN_0096c810(param_1);

      iVar3 = DAT_00d1f614;

      if (DAT_00d1f614 != 0) {

        *(int *)(DAT_00d1f614 + 0x39c) = *(int *)(DAT_00d1f614 + 0x39c) - iVar4;

        *(int *)(iVar3 + 0x354) = *(int *)(iVar3 + 0x354) + -1;

      }

    }

    else if ((uVar1 & 0xf) == 4) {

      iVar4 = FUN_0096c810(param_1);

      iVar3 = DAT_00d1f614;

      if (DAT_00d1f614 != 0) {

        *(int *)(DAT_00d1f614 + 0x3a4) = *(int *)(DAT_00d1f614 + 0x3a4) - iVar4;

        *(int *)(iVar3 + 0x35c) = *(int *)(iVar3 + 0x35c) + -1;

      }

    }

    else {

      iVar4 = FUN_0096c810(param_1);

      iVar3 = DAT_00d1f614;

      if (DAT_00d1f614 != 0) {

        *(int *)(DAT_00d1f614 + 0x394) = *(int *)(DAT_00d1f614 + 0x394) - iVar4;

        *(int *)(iVar3 + 0x34c) = *(int *)(iVar3 + 0x34c) + -1;

      }

    }

  }

  piVar2 = *(int **)(param_1 + 0x10);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 8))(piVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  piVar2 = *(int **)(param_1 + 0x14);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 8))(piVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  piVar2 = *(int **)(param_1 + 0x18);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 8))(piVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  return;

}
