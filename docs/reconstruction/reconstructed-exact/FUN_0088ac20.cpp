// =============================================================================
// FUN_0088ac20
// -----------------------------------------------------------------------------
// Stable ID: aa_0088ac20
// Address:   0x0088ac20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088ac20 @ 0x0088ac20
// Stable ID: aa_0088ac20
// Embedded strings (evidence for future rename):
//   - "i_d_sc_2d_wnd_summon_frame.xml"
//   - "i_d_sc_2d_wnd_summon_gauge_health.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0088ac20, FUN_0097ffa0, UI_CooldownGaugeWidget_ctor.
//  - Strings: "i_d_sc_2d_wnd_summon_frame.xml"; "i_d_sc_2d_wnd_summon_gauge_health.xml".
//  - Return sites: 1.

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

void FUN_0088ac20(void)



{

  int *this;

  int *piVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  int *piStack_40;

  int *piStack_3c;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b595c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  (**(code **)(*unaff_ESI + 0x404))();

  piStack_3c = (int *)0x88ac58;

  this = operator_new(0x4bc);

  if (this == (int *)0x0) {

    piVar1 = (int *)0x0;

  }

  else {

    piStack_3c = (int *)0x88ac70;

    piVar1 = UI_CooldownGaugeWidget_ctor(this);

  }

  piStack_3c = (int *)0x88ac8b;

  (**(code **)(*unaff_ESI + 0xa8))();

  piStack_3c = (int *)0xa54064;

  piStack_40 = (int *)0x88ac99;

  (**(code **)(s_i_d_sc_2d_wnd_summon_icon_xml_00a5408c._0_4_ + 0x28))();

  piStack_40 = (int *)0x0;

  (**(code **)(*this + 0x3b0))();

  (**(code **)(*piVar1 + 0x24))(1);

  pvVar2 = operator_new(0x4f8);

  if (pvVar2 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_0097ffa0(pvVar2);

  }

  (**(code **)(*unaff_ESI + 0xa8))();

  (**(code **)(*piStack_3c + 0x28))();

  (**(code **)(*piStack_40 + 0x3b0))();

  (**(code **)(*unaff_ESI + 0x404))(&piStack_40);

  *unaff_EDI = "i_d_sc_2d_wnd_summon_frame.xml";

  unaff_EDI[1] = 0xffffffff;

  unaff_EDI[2] = 0x3f800000;

  unaff_EDI[3] = "i_d_sc_2d_wnd_summon_gauge_health.xml";

  unaff_EDI[4] = uVar3;

  unaff_EDI[5] = pvVar2;

  ExceptionList = piStack_40;

  return;

}
