// =============================================================================
// FUN_0065adf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065adf0
// Address:   0x0065adf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065adf0 @ 0x0065adf0
// Stable ID: aa_0065adf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: while×2, if×2, return×2.
//  - Notable callees: FUN_00637f70, FUN_0065adf0.
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

uint __thiscall FUN_0065adf0(int *param_1,char *param_2)



{

  char *pcVar1;

  char cVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  char *pcVar7;

  uint uVar8;

  

  uVar5 = 0;

  cVar2 = *param_2;

  pcVar7 = param_2;

  while (cVar2 != '\0') {

    pcVar1 = pcVar7 + 1;

    pcVar7 = pcVar7 + 1;

    uVar5 = (int)cVar2 + uVar5 * 0x1f;

    cVar2 = *pcVar1;

  }

  iVar6 = *param_1;

  uVar3 = param_1[2];

  uVar8 = uVar3 & uVar5 & 0x7fffffff;

  uVar4 = *(uint *)(iVar6 + uVar8 * 4);

  while( true ) {

    if (uVar4 == 0xffffffff) {

      return param_1[2] + 1;

    }

    if ((uVar4 == (uVar5 & 0x7fffffff)) &&

       (iVar6 = FUN_00637f70(param_2,*(uint32_t /* width from decompiler */ *)(iVar6 + 4 + (uVar3 + uVar8) * 4)), iVar6 == 0))

    break;

    uVar3 = param_1[2];

    iVar6 = *param_1;

    uVar8 = uVar8 + 1 & uVar3;

    uVar4 = *(uint *)(iVar6 + uVar8 * 4);

  }

  return uVar8;

}
