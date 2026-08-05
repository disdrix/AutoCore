// =============================================================================
// FUN_0062ccf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062ccf0
// Address:   0x0062ccf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062ccf0 @ 0x0062ccf0
// Stable ID: aa_0062ccf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_0062ccf0.
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

void __thiscall FUN_0062ccf0(int *param_1,int param_2,int param_3,int *param_4)



{

  uint *puVar1;

  uint uVar2;

  uint *puVar3;

  int iVar4;

  uint *puVar5;

  int iVar6;

  

  puVar5 = (uint *)*param_1;

  puVar1 = puVar5 + param_1[1] * 2;

  iVar6 = 0;

  puVar3 = puVar5;

  for (; puVar5 < puVar1; puVar5 = puVar5 + 2) {

    uVar2 = *(uint *)(*param_4 + puVar5[1] * 4);

    if (-1 < (int)uVar2) {

      *puVar3 = *puVar5;

      puVar3[1] = puVar5[1];

      puVar3[1] = uVar2;

      *(int *)(*(int *)(&DAT_00af4e30 + ((*puVar3 & 1) + param_3 * 2) * 4) + uVar2 * 0x1c + param_2)

           = iVar6;

      puVar3 = puVar3 + 2;

      iVar6 = iVar6 + 1;

    }

  }

  if ((int)(param_1[2] & 0x7fffffffU) < iVar6) {

    iVar4 = (param_1[2] & 0x7fffffffU) * 2;

    if (iVar4 <= iVar6) {

      iVar4 = iVar6;

    }

    FUN_005b3300(param_1,iVar4,8);

  }

  param_1[1] = iVar6;

  return;

}
