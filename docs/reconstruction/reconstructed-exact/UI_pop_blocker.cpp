// =============================================================================
// UI_pop_blocker
// -----------------------------------------------------------------------------
// Stable ID: aa_0082d2b0
// Address:   0x0082d2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_pop_blocker @ 0x0082d2b0
// Stable ID: aa_0082d2b0
// Embedded strings (evidence for future rename):
//   - "i_d_pop_2d_wnd_blocker.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00416920, FUN_007b5dd0, UI_pop_blocker.
//  - Strings: "i_d_pop_2d_wnd_blocker.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_pop_2d_wnd_blocker.xml"
 * Domain alias of FUN_0082d2b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_pop_blocker(int *param_1)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b3381;

  local_c = ExceptionList;

  piVar3 = (int *)0x0;

  if (param_1[0x130] != 0) {

    ExceptionList = &local_c;

    (**(code **)(*param_1 + 0x450))();

    pvVar1 = operator_new(0x34);

    uStack_4 = 0;

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_00416920(pvVar1);

    }

    uStack_4 = 0xffffffff;

    param_1[0x14d] = iVar2;

    param_1[0x1a] = 0;

    param_1[0x1d] = 0;

    if (param_1[0x1c] < 0) {

      param_1[0x1c] = 0;

    }

    param_1[0x129] = 0;

    if (param_1[0x14e] != 0) {

      (**(code **)(*param_1 + 0xbc))(param_1[0x14e]);

    }

    pvVar1 = operator_new(0x488);

    uStack_4 = 1;

    if (pvVar1 != (void *)0x0) {

      piVar3 = (int *)FUN_007b5dd0(pvVar1,0);

    }

    uStack_4 = 0xffffffff;

    (**(code **)(*param_1 + 0xa8))(piVar3);

    (**(code **)(*piVar3 + 0x28))("i_d_pop_2d_wnd_blocker.xml");

    (**(code **)(*piVar3 + 0x74))(70000);

    param_1[0x1a] = param_1[0x1a] + 1;

    iVar2 = param_1[0x1a];

    param_1[0x14e] = (int)piVar3;

    param_1[0x1d] = (int)(float)-iVar2;

    if (param_1[0x1c] < iVar2) {

      param_1[0x1c] = iVar2;

    }

    (**(code **)(*param_1 + 0x3f4))(1);

  }

  ExceptionList = local_c;

  return;

}
