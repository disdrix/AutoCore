// =============================================================================
// FUN_008285a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008285a0
// Address:   0x008285a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008285a0 @ 0x008285a0
// Stable ID: aa_008285a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: FUN_00826780, FUN_008285a0, FUN_0085d970.
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

uint32_t /* width from decompiler */ FUN_008285a0(void)



{

  int iVar1;

  bool bVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int *unaff_ESI;

  uint8_t local_104 [260];

  

  if (in_EAX == 0) {

    return 0;

  }

  if (((unaff_ESI[0x152] == 2) &&

      (iVar1 = *(int *)(*(int *)(in_EAX + 0xa8) + 0x34), unaff_ESI[0x154] == iVar1)) &&

     (unaff_ESI[0x155] == iVar1 >> 0x1f)) {

    bVar2 = false;

  }

  else {

    bVar2 = true;

  }

  unaff_ESI[0x152] = 2;

  iVar1 = *(int *)(*(int *)(in_EAX + 0xa8) + 0x34);

  unaff_ESI[0x154] = iVar1;

  unaff_ESI[0x155] = iVar1 >> 0x1f;

  unaff_ESI[0x157] = unaff_ESI[0x140] + unaff_ESI[0x141] * 10;

  unaff_ESI[0x156] = 0;

  CVOGCharacter_SetQuickBarItem

            (DAT_00d1b6d8,(char)unaff_ESI[0x141] * '\n' + (char)unaff_ESI[0x140],unaff_ESI[0x154],

             unaff_ESI[0x155]);

  CVOGCharacter_SetQuickBarSkill

            (DAT_00d1b6d8,(char)unaff_ESI[0x141] * '\n' + (char)unaff_ESI[0x140],-1);

  if ((bVar2) && ((char)unaff_ESI[0x13f] != '\0')) {

    FUN_00826780(0);

  }

  *(uint8_t *)((int)unaff_ESI + 0x4fe) = 0;

  if ((int *)unaff_ESI[0x15f] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x15f] + 4))(1);

  }

  if (unaff_ESI[0x159] != 0) {

    FUN_0085d970();

    iVar1 = *(int *)unaff_ESI[0x159];

    uVar3 = (**(code **)(iVar1 + 0x2c8))(0);

    (**(code **)(iVar1 + 0x50))(local_104,uVar3);

    (**(code **)(*(int *)unaff_ESI[0x159] + 0x15c))(0,&DAT_00afdf0c);

    (**(code **)(*(int *)unaff_ESI[0x159] + 0x34c))();

  }

  if ((int *)unaff_ESI[0x15d] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x15d] + 0x1d8))(0,1,1);

    (**(code **)(*(int *)unaff_ESI[0x15d] + 0x34c))();

  }

  if ((int *)unaff_ESI[0x15e] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x15e] + 0x1d8))(0,1,1);

    (**(code **)(*(int *)unaff_ESI[0x15e] + 0x34c))();

  }

  (**(code **)(*unaff_ESI + 0x448))();

  return 1;

}
