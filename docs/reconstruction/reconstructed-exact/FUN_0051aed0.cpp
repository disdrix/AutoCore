// =============================================================================
// FUN_0051aed0
// -----------------------------------------------------------------------------
// Stable ID: aa_0051aed0
// Address:   0x0051aed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051aed0 @ 0x0051aed0
// Stable ID: aa_0051aed0
// Embedded strings (evidence for future rename):
//   - "generic_pickup"
//   - "generic_pickup_enhanced"
//   - "generic_pickup_gadget"
//   - "generic_pickup_commidity"
//   - "generic_pickup_tinkering_kit"
//   - "generic_pickup_money"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×10, switch×2, goto×1, return×1.
//  - Notable callees: FUN_009700f0×3, NDSpecialFX_LoadFromScriptName×3, FUN_004b8dc0×2, Client_GetMissionCompleteAudioTable, FUN_004b7e50, FUN_00519d20, FUN_0051aed0, FUN_0096f660.
//  - Strings: "generic_pickup"; "generic_pickup_enhanced"; "generic_pickup_gadget"; "generic_pickup_commidity".
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

void __thiscall FUN_0051aed0(int *param_1,char param_2,char param_3)



{

  short sVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint uVar5;

  void *pvVar6;

  char *pcVar7;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  iVar2 = (**(code **)(*param_1 + 0x1cc))();

  if (iVar2 != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0xfc))();

  }

  if ((param_3 == '\0') && (*(int *)(param_1[0x2a] + 0x38) != 4)) {

    switch(*(int *)(param_1[0x2a] + 0x38)) {

    default:

      iVar3 = (**(code **)(*param_1 + 0x60))();

      if (iVar3 == 0) {

        pcVar7 = "generic_pickup";

      }

      else {

        pcVar7 = "generic_pickup_enhanced";

      }

      break;

    case 8:

      pcVar7 = "generic_pickup_gadget";

      break;

    case 0x1a:

      pcVar7 = "generic_pickup_commidity";

      break;

    case 0x32:

      pcVar7 = "generic_pickup_tinkering_kit";

      break;

    case 0x42:

      pcVar7 = "generic_pickup_money";

    }

    pvVar4 = NDSpecialFX_LoadFromScriptName(pcVar7,4,0);

    if (*(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f4) != 0x10) goto LAB_0051afbb;

    pcVar7 = "generic_pickup_trick_material";

  }

  else {

    pcVar7 = "generic_pickup_quest";

  }

  pvVar4 = NDSpecialFX_LoadFromScriptName(pcVar7,4,0);

LAB_0051afbb:

  sVar1 = *(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4b8);

  pvVar6 = (void *)0x0;

  if (1 < sVar1) {

    switch(sVar1) {

    default:

      pcVar7 = "generic_pickup_rare";

      break;

    case 3:

      pcVar7 = "generic_pickup_ultra_rare";

      break;

    case 4:

      pcVar7 = "generic_pickup_artifact";

      break;

    case 5:

      pcVar7 = "generic_pickup_xeno_artifact";

    }

    pvVar6 = NDSpecialFX_LoadFromScriptName(pcVar7,4,0);

  }

  if (pvVar4 != (void *)0x0) {

    if (pvVar6 != (void *)0x0) {

      FUN_004b8dc0(1,0);

      (**(code **)(*param_1 + 0xf8))(pvVar6,1,0);

    }

    FUN_004b8dc0(1,0);

    (**(code **)(*param_1 + 0xf8))(pvVar4,1,0);

    iVar3 = Client_GetMissionCompleteAudioTable();

    if ((*(char *)(iVar3 + 600) != '\0') && (param_2 != '\0')) {

      FUN_004b7e50(0,0,0,0,0,0);

    }

  }

  if (((*(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f4) == 8) && (iVar2 != 0)) &&

     (*(int *)(iVar2 + 8) != 0)) {

    iVar2 = param_1[0x32];

    fStack_10 = 0.0;

    fStack_c = 0.0;

    fStack_8 = 0.0;

    fStack_4 = g_flOne;

    if (iVar2 < 0) {

      iVar2 = 0;

    }

    uVar5 = FUN_00519d20(iVar2);

    fStack_10 = (float)(uVar5 >> 0x10 & 0xff) * DAT_00aaa7a8;

    fStack_c = (float)(uVar5 >> 8 & 0xff) * DAT_00aaa7a8;

    fStack_8 = (float)(uVar5 & 0xff) * DAT_00aaa7a8;

    fStack_4 = g_flOne;

    FUN_009700f0("MatAmbient",&fStack_10);

    FUN_009700f0("MatDiffuse",&fStack_10);

    FUN_009700f0("MatEmissive",&fStack_10);

    FUN_0096f660();

  }

  return;

}
