// =============================================================================
// FUN_0065ad30
// -----------------------------------------------------------------------------
// Stable ID: aa_0065ad30
// Address:   0x0065ad30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065ad30 @ 0x0065ad30
// Stable ID: aa_0065ad30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: while×2, if×2, goto×1, return×1.
//  - Notable callees: FUN_00637f70, FUN_0065ad30, FUN_0065af30.
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

void __thiscall FUN_0065ad30(int *param_1,char *param_2,uint32_t /* width from decompiler */ param_3)



{

  char *pcVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  char *pcVar6;

  uint uVar7;

  

  uVar4 = 0;

  cVar2 = *param_2;

  pcVar6 = param_2;

  while (cVar2 != '\0') {

    pcVar1 = pcVar6 + 1;

    pcVar6 = pcVar6 + 1;

    uVar4 = (int)cVar2 + uVar4 * 0x1f;

    cVar2 = *pcVar1;

  }

  uVar4 = uVar4 & 0x7fffffff;

  if (param_1[2] < param_1[1] * 2) {

    FUN_0065af30(param_1[2] * 2 + 2);

  }

  uVar3 = param_1[2];

  uVar7 = uVar3 & uVar4;

  iVar5 = *(int *)(*param_1 + uVar7 * 4);

  while (iVar5 != -1) {

    if ((*(uint *)(*param_1 + uVar7 * 4) == uVar4) &&

       (iVar5 = FUN_00637f70(param_2,*(uint32_t /* width from decompiler */ *)(*param_1 + 4 + (uVar3 + uVar7) * 4)),

       iVar5 == 0)) goto LAB_0065adbf;

    uVar3 = param_1[2];

    uVar7 = uVar7 + 1 & uVar3;

    iVar5 = *(int *)(*param_1 + uVar7 * 4);

  }

  param_1[1] = param_1[1] + 1;

LAB_0065adbf:

  *(uint *)(*param_1 + uVar7 * 4) = uVar4;

  *(char **)(*param_1 + 4 + (param_1[2] + uVar7) * 4) = param_2;

  *(uint32_t /* width from decompiler */ *)(*param_1 + (uVar7 + 2 + param_1[2] * 2) * 4) = param_3;

  return;

}
