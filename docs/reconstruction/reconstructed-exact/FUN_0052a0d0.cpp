// =============================================================================
// FUN_0052a0d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a0d0
// Address:   0x0052a0d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052a0d0 @ 0x0052a0d0
// Stable ID: aa_0052a0d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, goto×2, while×2, return×1.
//  - Notable callees: FUN_0052a0d0, strncat.
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

void __thiscall FUN_0052a0d0(int param_1,int param_2,char *param_3,size_t param_4)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  int local_8;

  

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x55c) + 0x10) +

                           (*(uint *)(*(int *)(param_1 + 0x55c) + 8) & *(uint *)(param_2 + 0x10)) *

                           4) + 4);

  uVar3 = 0;

  if (iVar1 == 0) {

LAB_0052a116:

    local_8 = 0;

  }

  else {

    do {

      if (*(uint *)(param_2 + 0x10) == *(uint *)(iVar1 + 0x10)) {

        if (iVar1 == 0) goto LAB_0052a116;

        local_8 = *(int *)(iVar1 + 8);

        goto LAB_0052a123;

      }

      iVar1 = *(int *)(iVar1 + 0xc);

    } while (iVar1 != 0);

    local_8 = 0;

  }

LAB_0052a123:

  if (local_8 != 0) {

    if (*(int *)(param_2 + 0x158) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = *(int *)(param_2 + 0x15c) - *(int *)(param_2 + 0x158) >> 2;

    }

    if (uVar2 != 0) {

      do {

        iVar1 = (**(code **)(**(int **)(*(int *)(param_2 + 0x158) + uVar3 * 4) + 0x1c))

                          (param_1,local_8,param_3,param_4);

        if ((0 < iVar1) && (param_4 = param_4 - iVar1, uVar3 < uVar2 - 1)) {

          strncat(param_3,"\n",param_4);

          param_4 = param_4 - 1;

        }

        uVar3 = uVar3 + 1;

      } while (uVar3 < uVar2);

    }

  }

  return;

}
