// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, goto×4, switch×1.
//  - Notable callees: FUN_007a6de0×10, FUN_00571b60×4, FUN_007fdfb0×3, Client_GetMissionCompleteAudioTable×2, Client_PlayNamedInterfaceSound×2, FUN_00571010×2, FUN_00571b80×2, FUN_00933310×2.
//  - Strings: "BUG: Tinkering kit or Target Object not found."; "Gadget Slots available"; "now has"; "Tinkering successful".
//  - Return sites: 4.

// =============================================================================
// Inv_BUG_Item_to_tinker_not_found_Server_thinks_it_wo_0080d570
// -----------------------------------------------------------------------------
// Stable ID: aa_0080d570
// Address:   0x0080d570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "BUG: Item to tinker not found. Server thinks it worked."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_BUG_Item_to_tinker_not_found_Server_thinks_it_wo_0080d570(int param_1)



{

  char cVar1;

  short sVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ uVar13;

  uint32_t /* width from decompiler */ uVar14;

  uint32_t /* width from decompiler */ uVar15;

  char acStack_100 [256];

  

  if (*(int *)(unaff_ESI + 0xe98) == 0) {

    return;

  }

  if (*(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250) == 0) {

    return;

  }

  FUN_007a69d0();

  piVar3 = (int *)FUN_00571010(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

  if (piVar3 == (int *)0x0) {

    piVar3 = (int *)FUN_00571010(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

  }

  piVar4 = (int *)CVOGReaction_ResolveObjectTarget

                            (1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c));

  if ((piVar3 == (int *)0x0) || (piVar4 == (int *)0x0)) {

    pcVar10 = "BUG: Tinkering kit or Target Object not found.";

LAB_0080d8f7:

    uVar12 = 0;

    uVar11 = 1;

    uVar9 = 0xffffffff;

    uVar7 = FUN_007a6de0(pcVar10,0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar7,uVar9,uVar11,uVar12);

    return;

  }

  iVar5 = (**(code **)(*piVar4 + 0x200))();

  if (iVar5 == 0) {

    pcVar10 = "BUG: Tinkering Kit object could not be cast as TinkeringKit type.";

    goto LAB_0080d8f7;

  }

  if (*(char *)(param_1 + 0x2c) != '\0') {

    iVar8 = *piVar3;

    iVar6 = (**(code **)(iVar8 + 0x8c))();

    (**(code **)(iVar8 + 0x90))(iVar6 + 1);

    sVar2 = *(short *)(*(int *)(piVar3[0x2a] + 0x3c) + 0x4b4);

    uVar7 = FUN_007a6de0("Gadget Slots available",0xffffffff);

    iVar8 = (int)sVar2;

    uVar9 = FUN_007a6de0(&DAT_00a7d1f0,0xffffffff);

    sVar2 = (**(code **)(*piVar3 + 0x8c))(uVar9,iVar8,uVar7);

    iVar8 = (int)sVar2;

    uVar7 = FUN_007a6de0("now has",0xffffffff);

    uVar7 = (**(code **)(*piVar3 + 0x15c))(uVar7,iVar8);

    uVar9 = FUN_007a6de0("Tinkering successful",0xffffffff);

    sprintf(acStack_100,"%s! %s %s %i %s %i %s.",uVar9,uVar7);

    uVar15 = 0;

    uVar14 = 0x1e;

    uVar13 = 0;

    uVar12 = 0;

    uVar11 = 0xffffffff;

    uVar9 = 0xffffffff;

    uVar7 = 0;

    pcVar10 = "tinker_success";

    Client_GetMissionCompleteAudioTable("tinker_success",0,0xffffffff,0xffffffff,0,0,0x1e,0);

    Client_PlayNamedInterfaceSound(pcVar10,uVar7,uVar9,uVar11,uVar12,uVar13,uVar14,uVar15);

    uVar11 = 0;

    uVar9 = 1;

    uVar7 = 0xffffffff;

    pcVar10 = acStack_100;

    goto LAB_0080d826;

  }

  uVar15 = 0;

  uVar14 = 0x1e;

  uVar13 = 0;

  uVar12 = 0;

  uVar11 = 0xffffffff;

  uVar9 = 0xffffffff;

  uVar7 = 0;

  pcVar10 = "tinker_fail";

  Client_GetMissionCompleteAudioTable("tinker_fail",0,0xffffffff,0xffffffff,0,0,0x1e,0);

  Client_PlayNamedInterfaceSound(pcVar10,uVar7,uVar9,uVar11,uVar12,uVar13,uVar14,uVar15);

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28)) {

  case 1:

    uVar11 = 0;

    uVar9 = 1;

    uVar7 = 0xffffffff;

    pcVar10 = (char *)FUN_007a6de0("BUG: Tinkering kit not found. Server thinks it worked.",

                                   0xffffffff);

    break;

  case 2:

    uVar11 = 0;

    uVar9 = 1;

    uVar7 = 0xffffffff;

    pcVar10 = (char *)FUN_007a6de0("BUG: Item to tinker not found. Server thinks it worked.",

                                   0xffffffff);

    break;

  case 3:

    uVar11 = 0;

    uVar9 = 1;

    uVar7 = 0xffffffff;

    pcVar10 = (char *)FUN_007a6de0("No available slots to open on this item.",0xffffffff);

    break;

  case 4:

    uVar11 = 0;

    uVar9 = 1;

    uVar7 = 0xffffffff;

    if (*(char *)(param_1 + 0x2d) == '\0') {

      pcVar10 = (char *)FUN_007a6de0("Tinkering failed on this item.",0xffffffff);

      break;

    }

    uVar12 = FUN_007a6de0("Catastrophic failure! Item and Tinkering Kit destroyed!",0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar12,uVar7,uVar9,uVar11);

    cVar1 = FUN_00571b60(piVar3);

    if ((cVar1 != '\0') || (cVar1 = FUN_00571b60(piVar3), cVar1 != '\0')) {

      FUN_00571b80(piVar3,1,1);

    }

    FUN_00933310(unaff_ESI,1,0,0xffffffff,0xffffffff);

  default:

    goto switchD_0080d668_default;

  }

LAB_0080d826:

  FUN_007fdfb0(unaff_ESI,pcVar10,uVar7,uVar9,uVar11);

switchD_0080d668_default:

  cVar1 = FUN_00571b60(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

  if (cVar1 == '\0') {

    cVar1 = FUN_00571b60(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

    if (cVar1 == '\0') goto LAB_0080d8be;

    iVar8 = *(int *)(*(int *)(iVar5 + 4) + 4);

  }

  else {

    iVar8 = *(int *)(*(int *)(iVar5 + 4) + 4);

  }

  FUN_00571b80(iVar8 + 4 + iVar5,1,0);

LAB_0080d8be:

  FUN_00933310(unaff_ESI,1,0,0xffffffff,0xffffffff);

  Client_RefreshOpenMissionUiWindows(unaff_ESI);

  return;

}
