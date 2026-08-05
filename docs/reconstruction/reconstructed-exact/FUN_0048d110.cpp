// =============================================================================
// FUN_0048d110
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d110
// Address:   0x0048d110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d110 @ 0x0048d110
// Stable ID: aa_0048d110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×2, while×1.
//  - Notable callees: FUN_0048d0a0×2, CONCAT31, FUN_0048a940, FUN_0048aa20, FUN_0048af60, FUN_0048cca0, FUN_0048cea0, FUN_0048d110.
//  - Return sites: 3.

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

char * __thiscall FUN_0048d110(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *extraout_ECX;

  uint32_t /* width from decompiler */ *puVar7;

  

  iVar5 = FUN_0048af60();

  uVar4 = param_4;

  pcVar6 = (char *)FUN_0048cea0(param_2,param_4);

  puVar7 = (uint32_t /* width from decompiler */ *)0x0;

  if (param_3 != 0) {

    FUN_0048cca0(pcVar6,uVar4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *extraout_ECX;

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = extraout_ECX[1];

    puVar7 = extraout_ECX;

  }

  if (((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) || (*pcVar6 != '<')) {

    if (iVar5 != 0) {

      FUN_0048d0a0(10,pcVar6,puVar7,uVar4);

    }

    return (char *)0x0;

  }

  FUN_0048a940(&DAT_00a1419b,0);

  while (pcVar2 = pcVar6 + 1, pcVar2 != (char *)0x0) {

    cVar1 = *pcVar2;

    if (cVar1 == '\0') goto LAB_0048d1a1;

    if (cVar1 == '>') goto LAB_0048d1a6;

    uVar3 = (uint)param_4 >> 8;

    param_4 = CONCAT31((int3)uVar3,cVar1);

    FUN_0048aa20(&param_4,1);

    pcVar6 = pcVar2;

  }

  if (iVar5 != 0) {

    FUN_0048d0a0(10,0,0,uVar4);

  }

LAB_0048d1a1:

  if (*pcVar2 != '>') {

    return pcVar2;

  }

LAB_0048d1a6:

  return pcVar6 + 2;

}
