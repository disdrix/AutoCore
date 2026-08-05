// =============================================================================
// FUN_005cae70
// -----------------------------------------------------------------------------
// Stable ID: aa_005cae70
// Address:   0x005cae70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cae70 @ 0x005cae70
// Stable ID: aa_005cae70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: CONCAT22, CONCAT31, FUN_00404d70, FUN_004f1e20, FUN_005cae70.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_005cae70(int param_1,uint32_t /* width from decompiler */ param_2)



{

  short sVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar2 = FUN_00404d70(param_2);

  if (iVar2 == 0) {

    return 0;

  }

  iVar3 = *(int *)(iVar2 + 0x3c);

  if (iVar3 == 0) {

    FUN_004f1e20(0,1);

    iVar3 = *(int *)(iVar2 + 0x3c);

    if (iVar3 == 0) {

      return 0;

    }

  }

  iVar4 = *(int *)(*(int *)(param_1 + -0x10c) + 4);

  iVar2 = iVar4 + -0x10c + param_1;

  iVar4 = (int)*(short *)(iVar4 + -0x22 + param_1) + (int)*(short *)(iVar4 + -0x24 + param_1);

  if (0x50 < iVar4) {

    iVar4 = 0x50;

  }

  sVar1 = *(short *)(iVar3 + 0x3f0);

  iVar3 = CONCAT22((short)((uint)iVar3 >> 0x10),sVar1);

  if ((short)iVar4 < sVar1) {

    if (0x50 < sVar1) {

      *(uint16_t *)(iVar2 + 0xea) = 0x50;

      return 1;

    }

    iVar3 = (int)sVar1;

    *(short *)(iVar2 + 0xea) = sVar1;

  }

  return CONCAT31((int3)((uint)iVar3 >> 8),1);

}
