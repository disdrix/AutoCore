// =============================================================================
// FUN_006383e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006383e0
// Address:   0x006383e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006383e0 @ 0x006383e0
// Stable ID: aa_006383e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_006383e0.
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

void __thiscall

FUN_006383e0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)



{

  byte bVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  

  DAT_00d02c78 = *param_1;

  piVar3 = param_1 + 3;

  uVar4 = 4;

  do {

    iVar5 = *(int *)(uVar4 + 0xd02c74) + piVar3[-2];

    *(int *)((int)&DAT_00d02c78 + uVar4) = iVar5;

    iVar5 = iVar5 + piVar3[-1];

    *(int *)((int)&DAT_00d02c7c + uVar4) = iVar5;

    iVar5 = iVar5 + *piVar3;

    *(int *)(((int)&DAT_00d02c78 - (int)param_1) + (int)piVar3) = iVar5;

    iVar5 = iVar5 + piVar3[1];

    *(int *)(((int)&DAT_00d02c7c - (int)param_1) + (int)piVar3) = iVar5;

    *(int *)(((int)&DAT_00d02c80 - (int)param_1) + (int)piVar3) = piVar3[2] + iVar5;

    uVar4 = uVar4 + 0x14;

    piVar3 = piVar3 + 5;

  } while (uVar4 < 0x400);

  for (iVar5 = param_4 + param_6 * 4; iVar5 != param_4; iVar5 = iVar5 + -4) {

    iVar2 = *(int *)(iVar5 + -4);

    bVar1 = *(byte *)(iVar2 * param_3 + param_2);

    (&DAT_00d02c78)[bVar1] = (&DAT_00d02c78)[bVar1] + -1;

    *(int *)(param_5 + (&DAT_00d02c78)[bVar1] * 4) = iVar2;

  }

  return;

}
