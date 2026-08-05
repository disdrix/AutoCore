// =============================================================================
// UI_body_cb_paint_secondary
// -----------------------------------------------------------------------------
// Stable ID: aa_00900b30
// Address:   0x00900b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_body_cb_paint_secondary @ 0x00900b30
// Stable ID: aa_00900b30
// Embedded strings (evidence for future rename):
//   - "i_d_body_2d_cb_paint_primary.xml"
//   - "i_d_body_2d_cb_paint_secondary.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0078e2f0×2, FUN_00794090×2, FUN_008ff5a0, UI_body_cb_paint_secondary.
//  - Strings: "i_d_body_2d_cb_paint_primary.xml"; "i_d_body_2d_cb_paint_secondary.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_body_2d_cb_paint_secondary.xml"
 * Domain alias of FUN_00900b30 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall UI_body_cb_paint_secondary(int *param_1)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ba9de;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    pvVar2 = operator_new(0x938);

    uStack_4 = 0;

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_0078e2f0();

    }

    uStack_4 = 0xffffffff;

    param_1[0x1ed] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    pcVar5 = "i_d_body_2d_cb_paint_primary.xml";

    (**(code **)(*(int *)param_1[0x1ed] + 0x28))("i_d_body_2d_cb_paint_primary.xml");

    (**(code **)(*(int *)param_1[0x1ed] + 0x43c))();

    uVar4 = 0x9c4b;

    (**(code **)(*(int *)param_1[0x1ed] + 0x74))(0x9c4b);

    if (*(int *)(param_1[0x1ed] + 0x930) != 0) {

      FUN_00794090();

    }

    *(uint8_t *)(param_1[0x1ed] + 0x4fe) = 0;

    pvVar2 = operator_new(0x938);

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_0078e2f0(uVar4,pcVar5,pvVar2);

    }

    param_1[499] = iVar3;

    (**(code **)(*param_1 + 0xa8))(iVar3);

    (**(code **)(*(int *)param_1[499] + 0x28))("i_d_body_2d_cb_paint_secondary.xml");

    (**(code **)(*(int *)param_1[499] + 0x43c))();

    (**(code **)(*(int *)param_1[499] + 0x74))(0x9c4c);

    if (*(int *)(param_1[499] + 0x930) != 0) {

      FUN_00794090();

    }

    *(uint8_t *)(param_1[499] + 0x4fe) = 0;

    FUN_008ff5a0();

  }

  ExceptionList = pvStack_c;

  return;

}
