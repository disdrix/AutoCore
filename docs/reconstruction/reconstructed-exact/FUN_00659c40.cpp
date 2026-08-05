// =============================================================================
// FUN_00659c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00659c40
// Address:   0x00659c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00659c40 @ 0x00659c40
// Stable ID: aa_00659c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_005b3300, FUN_00659c40.
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

void __thiscall FUN_00659c40(int *param_1,int param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint8_t *puVar5;

  int iVar6;

  

  iVar6 = param_3[1];

  iVar1 = param_1[1] + iVar6;

  iVar2 = param_1[1] - param_2;

  if ((int)(param_1[2] & 0x7fffffffU) < iVar1) {

    iVar3 = (param_1[2] & 0x7fffffffU) * 2;

    if (iVar3 <= iVar1) {

      iVar3 = iVar1;

    }

    FUN_005b3300(param_1,iVar3,1);

  }

  iVar3 = *param_1;

  iVar4 = iVar3 + iVar6 + param_2;

  if (-1 < iVar2 + -1) {

    puVar5 = (uint8_t *)(iVar2 + -1 + iVar4);

    do {

      *puVar5 = puVar5[(iVar3 + param_2) - iVar4];

      puVar5 = puVar5 + -1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  iVar2 = *param_3;

  iVar3 = *param_1;

  if (-1 < iVar6 + -1) {

    puVar5 = (uint8_t *)(iVar6 + -1 + iVar3 + param_2);

    do {

      *puVar5 = puVar5[iVar2 - (iVar3 + param_2)];

      puVar5 = puVar5 + -1;

      iVar6 = iVar6 + -1;

    } while (iVar6 != 0);

  }

  param_1[1] = iVar1;

  return;

}
