// =============================================================================
// FUN_004dc030
// -----------------------------------------------------------------------------
// Stable ID: aa_004dc030
// Address:   0x004dc030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004dc030 @ 0x004dc030
// Stable ID: aa_004dc030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×9, goto×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00418700×4, FUN_004bae00×2, CONCAT31, FUN_00404840, FUN_004bb970, FUN_004dc030, FUN_004e80c0.
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

void __thiscall

FUN_004dc030(int param_1,int param_2,int param_3,int param_4,uint *param_5,int param_6)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  *param_5 = 0;

  param_5[1] = 0;

  iVar4 = *(int *)(param_1 + 0xe908);

  if (iVar4 != *(int *)(param_1 + 0xe90c)) {

    do {

      if (*(int *)(iVar4 + 0xc0) != 0) {

        iVar3 = *(int *)(iVar4 + 0xc0);

        FUN_004bb970(CONCAT31((int3)((uint)iVar3 >> 8),*(uint8_t *)(iVar3 + 0x168)),

                     *(uint32_t /* width from decompiler */ *)(iVar3 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164));

      }

      iVar4 = iVar4 + 200;

    } while (iVar4 != *(int *)(param_1 + 0xe90c));

  }

  local_4 = 0;

  piVar2 = (int *)FUN_004bae00(1,&local_4);

  local_8 = piVar2;

  if (piVar2 != (int *)0x0) {

    do {

      local_8 = piVar2;

      (**(code **)(*piVar2 + 0x144))();

      iVar4 = *(int *)(piVar2[0x2a] + 0x38);

      if (iVar4 == 0x1e) {

        iVar4 = *(int *)(param_3 + 4);

        iVar3 = FUN_00418700(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&local_8);

LAB_004dc151:

        FUN_00404840(1);

        *(int *)(iVar4 + 4) = iVar3;

        **(int **)(iVar3 + 4) = iVar3;

      }

      else {

        if (iVar4 == 1) {

          iVar4 = *(int *)(param_2 + 4);

          iVar3 = FUN_00418700(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&local_8);

          goto LAB_004dc151;

        }

        if (iVar4 != 0x3c) {

          iVar4 = *(int *)(param_4 + 4);

          iVar3 = FUN_00418700(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&local_8);

          goto LAB_004dc151;

        }

        if (param_6 != 0) {

          iVar4 = *(int *)(param_6 + 4);

          iVar3 = FUN_00418700(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&local_8);

          goto LAB_004dc151;

        }

      }

      uVar1 = piVar2[0x59];

      if (((int)param_5[1] <= (int)uVar1) &&

         (((int)param_5[1] < (int)uVar1 || (*param_5 < (uint)piVar2[0x58])))) {

        *param_5 = piVar2[0x58];

        param_5[1] = uVar1;

      }

      piVar2 = (int *)FUN_004bae00(1,&local_4);

    } while (piVar2 != (int *)0x0);

    local_8 = (int *)0x0;

  }

  if (param_6 != 0) {

    FUN_004e80c0(param_5);

  }

  return;

}
