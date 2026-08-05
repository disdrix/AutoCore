// =============================================================================
// FUN_00884210
// -----------------------------------------------------------------------------
// Stable ID: aa_00884210
// Address:   0x00884210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00884210 @ 0x00884210
// Stable ID: aa_00884210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00522e90×2, SCARRY4×2, CARRY4, CONCAT44, FUN_00884210.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00884210(int param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint64_t uVar7;

  longlong lVar8;

  float fVar9;

  

  if (*(int *)(param_1 + 0x590) != 0) {

    if ((*(int *)(param_1 + 0x510) == 0) || (DAT_00d1b6d8 == 0)) {

      (**(code **)(**(int **)(param_1 + 0x590) + 0x3b0))(0);

    }

    else {

      uVar7 = FUN_00522e90();

      iVar3 = (int)((ulonglong)uVar7 >> 0x20);

      lVar8 = FUN_00522e90();

      iVar4 = (int)((ulonglong)lVar8 >> 0x20);

      iVar5 = (uint)uVar7 + (uint)lVar8;

      uVar1 = (uint)CARRY4((uint)uVar7,(uint)lVar8);

      iVar2 = iVar3 + iVar4;

      iVar6 = iVar2 + uVar1;

      if ((iVar6 < 0) ||

         ((iVar6 == 0 || SCARRY4(iVar3,iVar4) != SCARRY4(iVar2,uVar1) && (iVar5 == 0)))) {

        fVar9 = 0.0;

      }

      else {

        fVar9 = (float)((float10)lVar8 / (float10)CONCAT44(iVar6,iVar5));

        if (fVar9 <= (float)_DAT_00aaa5f0) {

          fVar9 = DAT_00a10e78;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x590) + 0x3b0))(fVar9);

      (**(code **)(**(int **)(param_1 + 0x590) + 0x15c))(1,&stack0x00000000);

    }

    (**(code **)(**(int **)(param_1 + 0x590) + 0x34c))();

  }

  return;

}
