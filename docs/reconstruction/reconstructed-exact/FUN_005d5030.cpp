// =============================================================================
// FUN_005d5030
// -----------------------------------------------------------------------------
// Stable ID: aa_005d5030
// Address:   0x005d5030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d5030 @ 0x005d5030
// Stable ID: aa_005d5030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1.
//  - Notable callees: FUN_00513f90, FUN_005d5030.
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

void __thiscall FUN_005d5030(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  

  FUN_00513f90(param_2);

  if ((char)param_2 == '\0') {

    iVar1 = *(int *)(param_1 + -0xdc);

    iVar3 = *(int *)(iVar1 + 4) + param_1;

    if (*(int *)(*(int *)(iVar3 + -0x34) + 0x38) == 3) {

      if ((*(uint *)(iVar3 + 0xa0) >> 0x12 & 1) == 0) {

        (**(code **)(*(int *)(param_1 + -0xa0) + 8))();

        return;

      }

    }

    else {

      if ((*(uint *)(iVar3 + 0xa0) >> 3 & 1) == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = 2;

        (**(code **)(*(int *)(*(int *)(iVar1 + 4) + -0xdc + param_1) + 0x1b4))(1);

      }

      else {

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = 1;

        (**(code **)(*(int *)(*(int *)(iVar1 + 4) + -0xdc + param_1) + 0x1b4))(0);

      }

      iVar3 = *(int *)(param_1 + -0xd8);

      if (iVar3 != 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28) = 0x10;

        if (*(int *)(param_1 + -0xd4) != 0) {

          for (uVar4 = 0; uVar2 = (**(code **)(**(int **)(param_1 + -0xd4) + 0x4c))(), uVar4 < uVar2

              ; uVar4 = uVar4 + 1) {

            iVar3 = (**(code **)(**(int **)(param_1 + -0xd4) + 0x50))();

            (**(code **)(**(int **)(iVar3 + uVar4 * 4) + 8))(4);

          }

        }

      }

    }

  }

  return;

}
