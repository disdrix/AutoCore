// =============================================================================
// FUN_005ebcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ebcf0
// Address:   0x005ebcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ebcf0 @ 0x005ebcf0
// Stable ID: aa_005ebcf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00580b60×2, FUN_005ebcf0.
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

void __thiscall FUN_005ebcf0(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  

  if (*param_2 != 0) {

    iVar5 = *(int *)(param_1 + 0xc4) + -1;

    if (-1 < iVar5) {

      puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc0) + 4 + iVar5 * 8);

      do {

        if ((int *)*puVar4 == param_2) {

          FUN_00580b60(param_2,1);

          piVar1 = *(int **)(*(int *)(param_1 + 0xc0) + iVar5 * 8);

          if (piVar1 != (int *)0x0) {

            (**(code **)(*piVar1 + 0x14))();

          }

          *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;

          iVar2 = *(int *)(param_1 + 0xc4);

          iVar3 = *(int *)(param_1 + 0xc0);

          *(uint32_t /* width from decompiler */ *)(iVar3 + iVar5 * 8) = *(uint32_t /* width from decompiler */ *)(iVar3 + iVar2 * 8);

          *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar5 * 8) = *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar2 * 8);

          return;

        }

        iVar5 = iVar5 + -1;

        puVar4 = puVar4 + -2;

      } while (-1 < iVar5);

    }

    FUN_00580b60(param_2,(uint)param_2 & 0xffffff00);

  }

  return;

}
