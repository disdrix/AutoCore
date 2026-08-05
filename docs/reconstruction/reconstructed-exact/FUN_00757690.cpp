// =============================================================================
// FUN_00757690
// -----------------------------------------------------------------------------
// Stable ID: aa_00757690
// Address:   0x00757690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00757690 @ 0x00757690
// Stable ID: aa_00757690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00440450×2, FUN_004148e0, FUN_00440230, FUN_00440560, FUN_00757050, FUN_00757690.
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

uint32_t /* width from decompiler */ FUN_00757690(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  uint32_t /* width from decompiler */ local_7c;

  uint8_t local_78;

  uint8_t local_77;

  uint8_t local_76;

  int local_74;

  uint32_t /* width from decompiler */ local_70;

  float fStack_6c;

  float fStack_68;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  float fStack_54;

  float fStack_50;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  float fStack_3c;

  float fStack_38;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  float fStack_24;

  float fStack_20;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b1bae;

  pvStack_c = ExceptionList;

  fVar4 = (float)*param_2;

  fVar5 = (float)param_2[1];

  fVar6 = (float)param_2[2];

  fVar7 = (float)param_2[3];

  if ((char)((uint)param_3 >> 0x18) != -1) {

    param_4 = 1;

  }

  local_7c = 0;

  local_78 = 0;

  local_77 = 0;

  local_76 = 0;

  local_74 = 0;

  local_70 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  FUN_004148e0(param_5);

  iVar2 = *(int *)(unaff_EDI + 0x44);

  if (iVar2 != 0) {

    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;

    if (*(int *)(iVar2 + 8) == 1) {

      (**(code **)(*(int *)(iVar2 + 4) + 4))();

    }

  }

  if (local_74 != 0) {

    piVar1 = (int *)(local_74 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(local_74 + 4) + 8))();

    }

  }

  uStack_44 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x188);

  uStack_28 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18c);

  uStack_5c = 0;

  uStack_58 = 0;

  uStack_60 = param_3;

  uStack_40 = 0;

  uStack_48 = param_3;

  uStack_30 = param_3;

  uStack_14 = 0;

  uStack_18 = param_3;

  local_74 = iVar2;

  fStack_6c = fVar4;

  fStack_68 = fVar5;

  fStack_54 = fVar6;

  fStack_50 = fVar5;

  fStack_3c = fVar6;

  fStack_38 = fVar7;

  uStack_2c = uStack_44;

  fStack_24 = fVar4;

  fStack_20 = fVar7;

  uStack_10 = uStack_28;

  if (param_4 == 1) {

    uVar3 = FUN_00440560(param_1 + 0x68);

    FUN_00440450(uVar3);

  }

  else {

    FUN_00440450(param_1 + 4);

  }

  FUN_00757050(param_1,4);

  local_4 = 0xffffffff;

  FUN_00440230(&local_7c);

  ExceptionList = pvStack_c;

  return 0;

}
