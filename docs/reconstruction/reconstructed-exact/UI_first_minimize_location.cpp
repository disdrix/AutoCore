// =============================================================================
// UI_first_minimize_location
// -----------------------------------------------------------------------------
// Stable ID: aa_008dca00
// Address:   0x008dca00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_first_minimize_location @ 0x008dca00
// Stable ID: aa_008dca00
// Embedded strings (evidence for future rename):
//   - "i_d_first_2d_wnd_minimize_location.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007ab7f0, FUN_007b5dd0, UI_first_minimize_location.
//  - Strings: "i_d_first_2d_wnd_minimize_location.xml".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_first_2d_wnd_minimize_location.xml"
 * Domain alias of FUN_008dca00 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_first_minimize_location(int *param_1)



{

  int iVar1;

  int *piVar2;

  void *pvVar3;

  int *piVar4;

  uint8_t *puVar5;

  uint8_t local_14 [4];

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b39cf;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_007ab7f0();

  puVar5 = local_14;

  piVar2 = (int *)(**(code **)(*param_1 + 0x120))(puVar5,1,0);

  iVar1 = piVar2[1];

  param_1[0x147] = *piVar2;

  param_1[0x148] = iVar1;

  pvVar3 = operator_new(0x488);

  uStack_10 = 0;

  if (pvVar3 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_007b5dd0(pvVar3,0);

  }

  uStack_10 = 0xffffffff;

  (**(code **)(*piVar2 + 0x28))("i_d_first_2d_wnd_minimize_location.xml");

  piVar4 = (int *)(**(code **)(*piVar2 + 0x120))(&stack0xffffffdc,1,0);

  iVar1 = piVar4[1];

  param_1[0x149] = *piVar4;

  param_1[0x14a] = iVar1;

  (**(code **)*piVar2)(1);

  if ((char)param_1[0x146] != '\0') {

    (**(code **)(*param_1 + 0x110))(param_1 + 0x149);

    ExceptionList = puVar5;

    return;

  }

  (**(code **)(*param_1 + 0x110))(param_1 + 0x147);

  ExceptionList = puVar5;

  return;

}
