// =============================================================================
// FUN_00908880
// -----------------------------------------------------------------------------
// Stable ID: aa_00908880
// Address:   0x00908880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00908880 @ 0x00908880
// Stable ID: aa_00908880
// Embedded strings (evidence for future rename):
//   - "i_d_ah_2d_cb_generic_sort.xml"
//   - "Rarity"
//   - "Currrent Bid"
//   - "Buyout Price"
//   - "Time Left"
//   - "Seller"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~340 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, switch×1, goto×1.
//  - Notable callees: FUN_007a69d0×36, FUN_007a6de0×36, FUN_0078e2f0, FUN_00794090, FUN_00908880.
//  - Strings: "i_d_ah_2d_cb_generic_sort.xml"; "Rarity"; "Currrent Bid"; "Buyout Price".
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

void __thiscall FUN_00908880(int *param_1,int *param_2)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ unaff_EDI;

  undefined *puVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  void *pvStack_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009bac0d;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*param_1 == 0) {

    ExceptionList = &pvStack_c;

    pvVar1 = operator_new(0x938);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_0078e2f0();

    }

    local_4 = 0xffffffff;

    *param_1 = iVar2;

    (**(code **)(*param_2 + 0xa8))(iVar2);

    (**(code **)(*(int *)*param_1 + 0x28))("i_d_ah_2d_cb_generic_sort.xml");

    (**(code **)(*(int *)*param_1 + 0x74))(0x9c56);

    (**(code **)(*(int *)*param_1 + 0x43c))();

    *(uint8_t *)(*param_1 + 0x4fe) = 0;

    if (*(int *)(*param_1 + 0x930) != 0) {

      FUN_00794090();

    }

  }

  param_2[0x1e6] = -1;

  param_2[0x1e7] = -1;

  param_2[0x1e8] = -1;

  param_2[0x1e9] = -1;

  param_2[0x1ea] = -1;

  param_2[0x1eb] = -1;

  param_2[0x1ec] = -1;

  param_2[0x1ed] = -1;

  param_2[0x1ee] = -1;

  param_2[0x1ef] = -1;

  param_2[0x1f0] = -1;

  param_2[0x1f1] = -1;

  param_2[0x1f2] = -1;

  param_2[499] = -1;

  param_2[500] = -1;

  param_2[0x1f5] = -1;

  param_2[0x1f6] = -1;

  iVar2 = (**(code **)(*(int *)*param_1 + 0x46c))();

  if (iVar2 != -1) {

    (**(code **)(*(int *)*param_1 + 0x46c))();

  }

  (**(code **)(*(int *)*param_1 + 0x450))();

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  puVar6 = &DAT_00a2d820;

  FUN_007a69d0(&DAT_00a2d820,0xffffffff);

  iVar3 = FUN_007a6de0(puVar6,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))();

  param_2[0x1e6] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  pcVar5 = "Rarity";

  FUN_007a69d0("Rarity",0xffffffff);

  uVar7 = FUN_007a6de0(pcVar5,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

  param_2[0x1e7] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  puVar4 = &DAT_00a31c6c;

  FUN_007a69d0(&DAT_00a31c6c,0xffffffff);

  uVar7 = FUN_007a6de0(puVar4,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

  param_2[0x1e8] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  pcVar5 = "Currrent Bid";

  FUN_007a69d0("Currrent Bid",0xffffffff);

  uVar7 = FUN_007a6de0(pcVar5,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

  param_2[0x1e9] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  pcVar5 = "Buyout Price";

  FUN_007a69d0("Buyout Price",0xffffffff);

  uVar7 = FUN_007a6de0(pcVar5,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

  param_2[0x1ea] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  pcVar5 = "Time Left";

  FUN_007a69d0("Time Left",0xffffffff);

  pvVar1 = (void *)FUN_007a6de0(pcVar5,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))();

  param_2[0x1eb] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  pcVar5 = "Seller";

  FUN_007a69d0("Seller",0xffffffff);

  uVar7 = FUN_007a6de0(pcVar5,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

  param_2[0x1ec] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  pcVar5 = "High Bidder";

  FUN_007a69d0("High Bidder",0xffffffff);

  uVar7 = FUN_007a6de0(pcVar5,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

  param_2[0x1ed] = iVar2;

  iVar2 = *(int *)*param_1;

  uVar7 = 0xffffffff;

  pcVar5 = "Gadgets";

  FUN_007a69d0("Gadgets",0xffffffff);

  uVar7 = FUN_007a6de0(pcVar5,uVar7);

  iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

  param_2[0x1ee] = iVar2;

  switch(unaff_EDI) {

  case 10:

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Power";

    FUN_007a69d0("Power",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1ef] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Power Recharge";

    FUN_007a69d0("Power Recharge",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f0] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    puVar4 = &DAT_00a31a8c;

    FUN_007a69d0(&DAT_00a31a8c,0xffffffff);

    uVar7 = FUN_007a6de0(puVar4,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f1] = iVar2;

    iVar2 = *(int *)*param_1;

    pcVar5 = "Heat Dissipation";

    goto LAB_00908f10;

  case 0xc:

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    puVar4 = &DAT_00a31c20;

    FUN_007a69d0(&DAT_00a31c20,0xffffffff);

    uVar7 = FUN_007a6de0(puVar4,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1ef] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Penetration";

    FUN_007a69d0("Penetration",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f0] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Refire Rate";

    FUN_007a69d0("Refire Rate",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f1] = iVar2;

    iVar2 = *(int *)*param_1;

    pcVar5 = "Accuracy";

LAB_00908f10:

    uVar7 = 0xffffffff;

    FUN_007a69d0(pcVar5,0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f2] = iVar2;

    break;

  case 0xe:

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Number of Wheels";

    FUN_007a69d0("Number of Wheels",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1ef] = iVar2;

    uVar7 = 0xffffffff;

    if (DAT_00d1b24f == '\0') {

      iVar2 = *(int *)*param_1;

      puVar4 = &DAT_00a31af0;

      FUN_007a69d0(&DAT_00a31af0);

      uVar7 = FUN_007a6de0(puVar4,uVar7);

      iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

      param_2[0x1f0] = iVar2;

      iVar2 = *(int *)*param_1;

      pcVar5 = "Boosted MPH";

    }

    else {

      iVar2 = *(int *)*param_1;

      puVar4 = &DAT_00a31adc;

      FUN_007a69d0(&DAT_00a31adc,0xffffffff);

      uVar7 = FUN_007a6de0(puVar4,uVar7);

      iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

      param_2[0x1f0] = iVar2;

      iVar2 = *(int *)*param_1;

      pcVar5 = "Boosted KM/H";

    }

    uVar7 = 0xffffffff;

    FUN_007a69d0(pcVar5,0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f1] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Weight";

    FUN_007a69d0("Weight",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f2] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Number of Cargo Pages";

    FUN_007a69d0("Number of Cargo Pages",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[499] = iVar2;

    break;

  case 0x10:

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Best on Pavement";

    FUN_007a69d0("Best on Pavement",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1ef] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Best on Grass";

    FUN_007a69d0("Best on Grass",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f0] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Best on Gravel";

    FUN_007a69d0("Best on Gravel",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f1] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Best on Mud";

    FUN_007a69d0("Best on Mud",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f2] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Best on Snow";

    FUN_007a69d0("Best on Snow",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[499] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Best on Sand";

    FUN_007a69d0("Best on Sand",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[500] = iVar2;

    break;

  case 0x1c:

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Defense Bonus";

    FUN_007a69d0("Defense Bonus",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1ef] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "HP Bonus";

    FUN_007a69d0("HP Bonus",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f0] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Deflection";

    FUN_007a69d0("Deflection",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f1] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Physical Resistance";

    FUN_007a69d0("Physical Resistance",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f2] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Fire Resistance";

    FUN_007a69d0("Fire Resistance",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[499] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Corrosive Resistance";

    FUN_007a69d0("Corrosive Resistance",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[500] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Contamination Resistance";

    FUN_007a69d0("Contamination Resistance",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f5] = iVar2;

    iVar2 = *(int *)*param_1;

    uVar7 = 0xffffffff;

    pcVar5 = "Energy Resistance";

    FUN_007a69d0("Energy Resistance",0xffffffff);

    uVar7 = FUN_007a6de0(pcVar5,uVar7);

    iVar2 = (**(code **)(iVar2 + 0x448))(uVar7);

    param_2[0x1f6] = iVar2;

  }

  if (iVar3 != -1) {

    (**(code **)(*(int *)*param_1 + 0x460))(iVar3);

    ExceptionList = pvVar1;

    return;

  }

  (**(code **)(*(int *)*param_1 + 0x460))(0);

  ExceptionList = pvVar1;

  return;

}
