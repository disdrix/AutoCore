// =============================================================================
// FUN_00520dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00520dc0
// Address:   0x00520dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00520dc0 @ 0x00520dc0
// Stable ID: aa_00520dc0
// Embedded strings (evidence for future rename):
//   - "CVOGCharacter::CleanupDraggingObject"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, goto×2.
//  - Notable callees: FUN_005714e0×2, FUN_00571620×2, FUN_00786990×2, FUN_004fabc0, FUN_00502e90, FUN_00520dc0, FUN_00786a00.
//  - Strings: "CVOGCharacter::CleanupDraggingObject".
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

uint32_t /* width from decompiler */ __fastcall FUN_00520dc0(int param_1)



{

  int *piVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint local_18;

  uint local_14;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a37f7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00786a00("CVOGCharacter::CleanupDraggingObject");

  piVar1 = *(int **)(param_1 + 0xcd0);

  local_4 = 0;

  if (piVar1 == (int *)0x0) {

    local_4 = 0xffffffff;

    FUN_00786990();

    ExceptionList = local_c;

    return 0;

  }

  local_14 = local_14 & 0xffffff00;

  local_18 = local_18 & 0xffffff00;

  cVar2 = FUN_005714e0(piVar1,&local_14,&local_18,1,0xffffffff);

  if (cVar2 != '\0') {

    uVar3 = (**(code **)(*piVar1 + 0x25c))();

    cVar2 = FUN_00571620(piVar1,local_14,local_18,uVar3);

    if (cVar2 != '\0') goto LAB_00520f0a;

  }

  cVar2 = FUN_005714e0(piVar1,&local_14,&local_18,1,0xffffffff);

  if (cVar2 != '\0') {

    uVar3 = (**(code **)(*piVar1 + 0x25c))();

    cVar2 = FUN_00571620(piVar1,local_14,local_18,uVar3);

    if (cVar2 != '\0') goto LAB_00520f0a;

  }

  iStack_10 = 0;

  iVar4 = FUN_004fabc0(piVar1,&iStack_10);

  if ((iStack_10 == 0) &&

     ((((iVar4 == 0 || (iVar4 == 1)) || (iVar4 == 10)) || ((iVar4 == 0xd || (iVar4 == 0xf)))))) {

    FUN_00502e90(piVar1);

  }

LAB_00520f0a:

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcd0) = 0;

  local_4 = 0xffffffff;

  FUN_00786990();

  ExceptionList = local_c;

  return 1;

}
