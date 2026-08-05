// =============================================================================
// FUN_008da110
// -----------------------------------------------------------------------------
// Stable ID: aa_008da110
// Address:   0x008da110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008da110 @ 0x008da110
// Stable ID: aa_008da110
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×8, goto×4, return×4.
//  - Notable callees: FUN_008da110.
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

uint32_t /* width from decompiler */ __thiscall FUN_008da110(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  uint8_t auStack_8 [8];

  

  piVar4 = (int *)param_1[0x150];

  if ((piVar4 == (int *)0x0) || (cVar1 = (**(code **)(*piVar4 + 0xd8))(), cVar1 == '\0')) {

LAB_008da185:

    if ((param_1[0x151] == 0) ||

       (cVar1 = (**(code **)(*(int *)param_1[0x151] + 0xd8))(), cVar1 == '\0')) goto LAB_008da1a6;

  }

  else {

    if (param_1[0x151] == 0) goto LAB_008da1a6;

    cVar1 = (**(code **)(*(int *)param_1[0x151] + 0xd8))();

    if (cVar1 == '\0') goto LAB_008da185;

    if ((param_1[0x145] == 0) ||

       (iVar2 = (**(code **)(*(int *)param_1[0x145] + 0x120))(auStack_8,1,1),

       DAT_00d1d870 <= *(int *)(iVar2 + 4))) goto LAB_008da1a6;

  }

  piVar4 = (int *)param_1[0x151];

LAB_008da1a6:

  if ((piVar4 != (int *)0x0) && (cVar1 = (**(code **)(*piVar4 + 0xd8))(), cVar1 != '\0')) {

    if ((short)((uint)param_2 >> 0x10) < 1) {

      (**(code **)(*piVar4 + 0x45c))(0x3f800000);

      return 1;

    }

    (**(code **)(*piVar4 + 0x45c))(0xbf800000);

    return 1;

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_1[0x12e] != 0)) {

    uVar3 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))(param_2,param_3);

    return uVar3;

  }

  return 0;

}
