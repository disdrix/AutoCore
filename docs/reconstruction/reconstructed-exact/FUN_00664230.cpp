// =============================================================================
// FUN_00664230
// -----------------------------------------------------------------------------
// Stable ID: aa_00664230
// Address:   0x00664230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00664230 @ 0x00664230
// Stable ID: aa_00664230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_005b3300, FUN_005b3370, FUN_00638060, FUN_006380a0, FUN_00664230.
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

void __thiscall FUN_00664230(int *param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  uint uVar6;

  int iVar7;

  

  iVar2 = param_1[1] - 1;

  if (-1 < iVar2) {

    piVar5 = (int *)(*param_1 + 4 + iVar2 * 8);

    do {

      if (param_2 == *piVar5) {

        return;

      }

      iVar2 = iVar2 + -1;

      piVar5 = piVar5 + -2;

    } while (-1 < iVar2);

  }

  if (param_1[1] == (param_1[2] & 0x7fffffffU)) {

    FUN_005b3370(param_1,8);

  }

  iVar2 = param_1[1];

  iVar1 = *param_1;

  *(int *)(iVar1 + iVar2 * 8) = param_2;

  *(int *)(iVar1 + 4 + iVar2 * 8) = param_2;

  param_1[1] = param_1[1] + 1;

  if (param_3 == 0) {

    param_3 = FUN_00638060(param_2);

    param_3 = param_3 + 1;

  }

  uVar6 = param_3 - 1U & 0xfffffffc;

  iVar1 = param_1[4];

  iVar7 = uVar6 + 4;

  iVar2 = uVar6 + 0x10 + iVar1;

  if ((int)(param_1[5] & 0x7fffffffU) < iVar2) {

    iVar3 = (param_1[5] & 0x7fffffffU) * 2;

    if (iVar3 <= iVar2) {

      iVar3 = iVar2;

    }

    FUN_005b3300(param_1 + 3,iVar3,1);

  }

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1[3] + iVar1);

  param_1[4] = iVar2;

  *puVar4 = 0;

  puVar4[1] = param_2;

  puVar4[2] = iVar7;

  FUN_006380a0(puVar4 + 3,param_2,iVar7);

  return;

}
