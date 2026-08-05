// =============================================================================
// FUN_00752310
// -----------------------------------------------------------------------------
// Stable ID: aa_00752310
// Address:   0x00752310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752310 @ 0x00752310
// Stable ID: aa_00752310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00752310.
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

void __thiscall FUN_00752310(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar2 = *(int *)(param_1 + 8);

  iVar4 = -1;

  if (((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) &&

     (iVar2 = (**(code **)(**(int **)(iVar2 + 0xc) + 0x28))(*(int **)(iVar2 + 0xc),0,param_3),

     iVar2 != 0)) {

    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x18);

    iVar3 = 0;

    if (0 < iVar1) {

      while (iVar4 = iVar3, *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x10) + iVar3 * 8) != iVar2) {

        iVar3 = iVar3 + 1;

        if (iVar1 <= iVar3) {

          *param_2 = -1;

          return;

        }

      }

    }

  }

  *param_2 = iVar4;

  return;

}
