// =============================================================================
// FUN_008035c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008035c0
// Address:   0x008035c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008035c0 @ 0x008035c0
// Stable ID: aa_008035c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: DrawTextExA×2, FillRect×2, GetStockObject×2, SelectObject×2, SetBkMode×2, SetMapMode×2, SetTextColor×2, FUN_008033e0.
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

void __thiscall FUN_008035c0(int *param_1,int param_2)



{

  HDC pHVar1;

  uint uVar2;

  int iVar3;

  HBRUSH pHVar4;

  int iVar5;

  HGDIOBJ h;

  COLORREF color;

  int iVar6;

  RECT RStack_20;

  RECT RStack_10;

  

  iVar3 = (**(code **)(*param_1 + 0x58))();

  if (iVar3 == 2) {

    RStack_20.right = param_1[1];

    RStack_20.bottom = param_1[2];

    pHVar1 = *(HDC *)(param_2 + 0x14);

    RStack_20.left = 0;

    RStack_20.top = 0;

    pHVar4 = GetStockObject(4);

    FillRect(pHVar1,&RStack_20,pHVar4);

    RStack_10.right = param_1[9];

    RStack_10.bottom = param_1[10];

    pHVar1 = *(HDC *)(param_2 + 0x14);

    RStack_10.left = 0;

    RStack_10.top = 0;

    pHVar4 = GetStockObject(4);

    FillRect(pHVar1,&RStack_10,pHVar4);

  }

  if (param_1[0x4f] != 0) {

    iVar3 = SetMapMode(*(HDC *)(param_2 + 0x14),1);

    pHVar1 = *(HDC *)(param_2 + 0x14);

    iVar5 = (**(code **)(*param_1 + 0x58))();

    iVar5 = SetBkMode(pHVar1,iVar5);

    h = SelectObject(*(HDC *)(param_2 + 0x14),(HGDIOBJ)param_1[0x4d]);

    color = SetTextColor(*(HDC *)(param_2 + 0x14),param_1[0x4e]);

    if (param_1[0x51] != 0) {

      uVar2 = param_1[0x50];

      RStack_20.top = 0;

      RStack_20.left = 0;

      RStack_20.right = (**(code **)(*param_1 + 0x24))();

      RStack_20.bottom = (**(code **)(*param_1 + 0x28))();

      DrawTextExA(*(HDC *)(param_2 + 0x14),(LPSTR)(param_1 + 0xd),param_1[0x4f],&RStack_20,

                  uVar2 | 0x410,(LPDRAWTEXTPARAMS)(param_1 + 0x52));

      uVar2 = param_1[0x50];

      param_1[0x58] = RStack_20.right;

      param_1[0x59] = RStack_20.bottom;

      RStack_20.top = 0;

      RStack_20.left = 0;

      RStack_20.right = (**(code **)(*param_1 + 0x24))();

      RStack_20.bottom = (**(code **)(*param_1 + 0x28))();

      DrawTextExA(*(HDC *)(param_2 + 0x14),(LPSTR)(param_1 + 0xd),param_1[0x4f],&RStack_20,

                  uVar2 | 0x400,(LPDRAWTEXTPARAMS)(param_1 + 0x52));

      param_1[0x5a] = RStack_20.right;

      param_1[0x5b] = RStack_20.bottom;

      param_1[0x51] = 0;

    }

    iVar6 = (**(code **)(*param_1 + 0x30))();

    if (iVar6 != 0) {

      FUN_008033e0();

    }

    SetMapMode(*(HDC *)(param_2 + 0x14),iVar3);

    SetTextColor(*(HDC *)(param_2 + 0x14),color);

    SetBkMode(*(HDC *)(param_2 + 0x14),iVar5);

    SelectObject(*(HDC *)(param_2 + 0x14),h);

  }

  return;

}
