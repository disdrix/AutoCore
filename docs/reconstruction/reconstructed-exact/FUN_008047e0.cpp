// =============================================================================
// FUN_008047e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008047e0
// Address:   0x008047e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008047e0 @ 0x008047e0
// Stable ID: aa_008047e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FillRect×3, FUN_008047e0, FrameRect, GetStockObject.
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

void __thiscall FUN_008047e0(int *param_1,int param_2)



{

  float fVar1;

  HBRUSH hbr;

  int iVar2;

  int iVar3;

  float fVar4;

  RECT local_20;

  RECT local_10;

  

  local_10.right = *(LONG *)(param_2 + 4);

  local_10.bottom = *(LONG *)(param_2 + 8);

  local_10.left = 0;

  local_10.top = 0;

  hbr = GetStockObject(4);

  FillRect(*(HDC *)(param_2 + 0x14),&local_10,hbr);

  local_20.left = 0;

  local_20.top = 0;

  local_20.right = (**(code **)(*param_1 + 0x24))();

  local_20.bottom = (**(code **)(*param_1 + 0x28))();

  FrameRect(*(HDC *)(param_2 + 0x14),&local_20,(HBRUSH)param_1[0x11]);

  if (param_1[0x10] == 0) {

    fVar1 = (float)param_1[0xf];

    iVar3 = (**(code **)(*param_1 + 0x24))();

    fVar4 = 0.0;

    if ((float)param_1[0xd] < 0.0) {

      fVar4 = 0.0 - (float)param_1[0xd];

    }

    local_20.right = (LONG)(((fVar4 + fVar1) / ((float)param_1[0xe] + fVar4)) * (float)iVar3);

    FillRect(*(HDC *)(param_2 + 0x14),&local_20,(HBRUSH)param_1[0x11]);

  }

  else if (param_1[0x10] == 1) {

    fVar1 = (float)param_1[0xf];

    iVar3 = param_1[0x12];

    iVar2 = (**(code **)(*param_1 + 0x24))();

    fVar4 = 0.0;

    if ((float)param_1[0xd] < 0.0) {

      fVar4 = 0.0 - (float)param_1[0xd];

    }

    local_20.left =

         (LONG)(((fVar4 + fVar1) / ((float)param_1[0xe] + fVar4)) *

                ((float)((iVar2 - iVar3) + -1) - g_flOne) + g_flOne);

    local_20.right = iVar3 + local_20.left;

    FillRect(*(HDC *)(param_2 + 0x14),&local_20,(HBRUSH)param_1[0x11]);

    return;

  }

  return;

}
