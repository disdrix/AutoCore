// =============================================================================
// FUN_007953b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007953b0
// Address:   0x007953b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007953b0 @ 0x007953b0
// Stable ID: aa_007953b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, goto×3, return×2, switch×1.
//  - Notable callees: FUN_007944a0×2, FUN_007949d0×2, FUN_00794850, FUN_007950e0, FUN_007953b0, FUN_007a7f30.
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

uint __thiscall FUN_007953b0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint uVar1;

  int iVar2;

  uint8_t auStack_8 [8];

  

  uVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((char)uVar1 == '\0') {

    return uVar1 & 0xffffff00;

  }

  if ((*(char *)((int)param_1 + 0xc2) == '\0') || (*(char *)((int)param_1 + 0x489) != '\0'))

  goto LAB_007954b6;

  *(char *)(param_1 + 0x125) = (char)param_2;

  switch(param_2) {

  case 0x23:

    param_1[0x46] = 0;

    iVar2 = FUN_007944a0();

    param_1[0x124] = iVar2;

    param_1[0x47] = iVar2;

    (**(code **)(*param_1 + 0x140))(auStack_8,1);

    if (param_1[0x83] != 0) {

      iVar2 = param_1[0x124];

LAB_007954a6:

      FUN_007950e0(param_1,iVar2);

    }

    break;

  case 0x24:

    param_1[0x46] = 0;

    param_1[0x124] = 0;

    FUN_007949d0();

    break;

  case 0x25:

    if (0 < param_1[0x124]) {

      iVar2 = param_1[0x124] + -1;

      param_1[0x124] = iVar2;

      goto LAB_007954a6;

    }

    break;

  case 0x27:

    iVar2 = FUN_007944a0();

    if (param_1[0x124] < iVar2) {

      iVar2 = param_1[0x124] + 1;

      param_1[0x124] = iVar2;

      if (param_1[0x83] != 0) goto LAB_007954a6;

    }

    break;

  case 0x2e:

    FUN_00794850(param_1,param_1[0x124]);

    FUN_007949d0();

  }

  (**(code **)(*param_1 + 0x34c))();

LAB_007954b6:

  uVar1 = FUN_007a7f30(param_2,param_3);

  return uVar1;

}
