// =============================================================================
// FUN_00646df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00646df0
// Address:   0x00646df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646df0 @ 0x00646df0
// Stable ID: aa_00646df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: switch×1, goto×1, if×1, return×1.
//  - Notable callees: FUN_005f3090×23, FUN_005f3070×4, FUN_005f3050×2, FUN_005f30b0×2, FUN_005f2d40, FUN_005f2f60, FUN_005f31e0, FUN_006380d0.
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

bool __fastcall FUN_00646df0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t local_5;

  undefined *local_4;

  

  switch(in_EAX) {

  case 1:

    FUN_005f2f60(param_1);

    break;

  case 3:

    FUN_005f3070(&local_4);

    *(uint8_t *)param_1 = local_4._0_1_;

    break;

  case 4:

    FUN_005f3070(&local_4);

    *(uint8_t *)param_1 = local_4._0_1_;

    break;

  case 5:

    FUN_005f3050(param_1);

    break;

  case 6:

    FUN_005f3050(param_1);

    break;

  case 7:

    FUN_005f3070(param_1);

    break;

  case 8:

    FUN_005f3070(param_1);

    break;

  case 9:

    FUN_005f30b0(param_1);

    break;

  case 10:

    FUN_005f30b0(param_1);

    break;

  case 0xb:

    FUN_005f3090(param_1);

    break;

  case 0xc:

  case 0xd:

    puVar6 = param_1 + 3;

    puVar5 = param_1 + 2;

    puVar4 = param_1 + 1;

    FUN_005f3090(param_1);

    goto LAB_00646eb5;

  case 0xe:

  case 0xf:

    FUN_006380d0(param_1,0,0x30);

    puVar4 = param_1 + 2;

    puVar6 = param_1 + 1;

    FUN_005f3090(param_1);

    FUN_005f3090(puVar6);

    FUN_005f3090(puVar4);

    puVar4 = param_1 + 6;

    puVar6 = param_1 + 5;

    FUN_005f3090(param_1 + 4);

    FUN_005f3090(puVar6);

    FUN_005f3090(puVar4);

    puVar6 = param_1 + 10;

    puVar5 = param_1 + 9;

    puVar4 = param_1 + 8;

LAB_00646eb5:

    FUN_005f3090(puVar4);

    FUN_005f3090(puVar5);

    FUN_005f3090(puVar6);

    break;

  case 0x10:

    puVar4 = param_1 + 2;

    puVar6 = param_1 + 1;

    FUN_005f3090(param_1);

    FUN_005f3090(puVar6);

    FUN_005f3090(puVar4);

    puVar4 = param_1 + 6;

    puVar6 = param_1 + 5;

    FUN_005f3090(param_1 + 4);

    FUN_005f3090(puVar6);

    FUN_005f3090(puVar4);

    puVar4 = param_1 + 10;

    puVar6 = param_1 + 9;

    FUN_005f3090(param_1 + 8);

    FUN_005f3090(puVar6);

    FUN_005f3090(puVar4);

    puVar4 = param_1 + 0xe;

    puVar6 = param_1 + 0xd;

    FUN_005f3090(param_1 + 0xc);

    FUN_005f3090(puVar6);

    FUN_005f3090(puVar4);

    param_1[0xb] = 0;

    param_1[7] = 0;

    param_1[3] = 0;

    param_1[0xf] = g_flOne;

    break;

  case 0x12:

    DAT_00d02c6c = DAT_00d02c6c + 1;

    local_4 = &DAT_00d02c70;

    FUN_005f31e0(&local_4);

    uVar2 = (**(code **)(*unaff_EBX + 4))(local_4);

    *param_1 = uVar2;

    piVar1 = (int *)(local_4 + -4);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

  }

  pcVar3 = (char *)FUN_005f2d40(&local_5);

  return *pcVar3 == '\0';

}
