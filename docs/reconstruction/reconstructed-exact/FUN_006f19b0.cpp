// =============================================================================
// FUN_006f19b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f19b0
// Address:   0x006f19b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f19b0 @ 0x006f19b0
// Stable ID: aa_006f19b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_005b3300, FUN_006f19b0.
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

void __thiscall FUN_006f19b0(int *param_1,int param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  iVar5 = param_3[1];

  iVar1 = param_1[1] + iVar5;

  iVar3 = param_1[1] - param_2;

  if ((int)(param_1[2] & 0x7fffffffU) < iVar1) {

    iVar4 = (param_1[2] & 0x7fffffffU) * 2;

    if (iVar4 <= iVar1) {

      iVar4 = iVar1;

    }

    FUN_005b3300(param_1,iVar4,4);

  }

  iVar2 = *param_1;

  iVar4 = iVar2 + (iVar5 + param_2) * 4;

  if (-1 < iVar3 + -1) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar4 + (iVar3 + -1) * 4);

    do {

      *puVar6 = *(uint32_t /* width from decompiler */ *)(((iVar2 + param_2 * 4) - iVar4) + (int)puVar6);

      puVar6 = puVar6 + -1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  iVar3 = *param_3;

  iVar4 = *param_1 + param_2 * 4;

  if (iVar5 + -1 < 0) {

    param_1[1] = iVar1;

    return;

  }

  puVar6 = (uint32_t /* width from decompiler */ *)(iVar4 + (iVar5 + -1) * 4);

  do {

    *puVar6 = *(uint32_t /* width from decompiler */ *)((iVar3 - iVar4) + (int)puVar6);

    puVar6 = puVar6 + -1;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  param_1[1] = iVar1;

  return;

}
