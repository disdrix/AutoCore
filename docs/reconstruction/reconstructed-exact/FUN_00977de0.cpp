// =============================================================================
// FUN_00977de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00977de0
// Address:   0x00977de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00977de0 @ 0x00977de0
// Stable ID: aa_00977de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: OffsetViewportOrgEx×2, SelectClipRgn×2, SetViewportOrgEx×2, CreateRectRgn, DeleteObject, FUN_00977de0.
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

void __thiscall FUN_00977de0(int param_1,int param_2)



{

  int *piVar1;

  HDC pHVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  HRGN hrgn;

  int *piVar8;

  tagPOINT *lppt;

  LPPOINT lppt_00;

  tagPOINT tStack_8;

  

  piVar8 = (int *)**(int **)(param_1 + 0x38);

  if (piVar8 != *(int **)(param_1 + 0x38)) {

    do {

      piVar1 = (int *)piVar8[2];

      iVar3 = (**(code **)(*piVar1 + 0x30))();

      if (iVar3 != 0) {

        piVar4 = (int *)(**(code **)(*piVar1 + 0x14))();

        piVar5 = (int *)(**(code **)(*piVar1 + 0x14))();

        iVar3 = (**(code **)(*piVar1 + 0x14))();

        iVar6 = (**(code **)(*piVar1 + 0x28))();

        iVar6 = iVar6 + *(int *)(iVar3 + 4);

        iVar3 = (**(code **)(*piVar1 + 0x24))();

        iVar3 = iVar3 + *piVar4;

        iVar7 = (**(code **)(*piVar1 + 0x14))();

        hrgn = CreateRectRgn(*piVar5,*(int *)(iVar7 + 4),iVar3,iVar6);

        SelectClipRgn(*(HDC *)(param_2 + 0x14),hrgn);

        DeleteObject(hrgn);

        pHVar2 = *(HDC *)(param_2 + 0x14);

        tStack_8.x = 0;

        tStack_8.y = 0;

        piVar4 = (int *)(**(code **)(*piVar1 + 0x14))();

        lppt = &tStack_8;

        iVar3 = (**(code **)(*piVar1 + 0x14))();

        SetViewportOrgEx(pHVar2,*piVar4,*(int *)(iVar3 + 4),lppt);

        pHVar2 = *(HDC *)(param_2 + 0x14);

        piVar4 = (int *)(**(code **)(*piVar1 + 0x44))();

        lppt_00 = (LPPOINT)0x0;

        iVar3 = (**(code **)(*piVar1 + 0x44))();

        OffsetViewportOrgEx(pHVar2,*piVar4,*(int *)(iVar3 + 4),lppt_00);

        (**(code **)(*piVar1 + 100))(param_2);

        SelectClipRgn(*(HDC *)(param_2 + 0x14),(HRGN)0x0);

        SetViewportOrgEx(*(HDC *)(param_2 + 0x14),tStack_8.x,tStack_8.y,(LPPOINT)0x0);

        OffsetViewportOrgEx(*(HDC *)(param_2 + 0x14),0,0,(LPPOINT)0x0);

      }

      piVar8 = (int *)*piVar8;

    } while (piVar8 != (int *)*(int *)(param_1 + 0x38));

  }

  return;

}
