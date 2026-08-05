// =============================================================================
// FUN_008aa560  /  MissionDialog_ClearResponseButtonSlots_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa560
// Address:   0x008aa560  (autoassault.exe, image base 0x400000)
// System:    missions-progression / mission dialog chrome
// Wave:      WQ7R-C (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Body: 0x008aa560–0x008aa5a6 exclusive (70 B / 0x46)
// ABI: EBX = dialog host*; no stack args; RET
// =============================================================================

// PURPOSE: Clear 8 response-button TFID pairs (+0x518) and destroy 8 widgets
// (+0x708) via host vtbl+0xBC. Sole caller: Mission_i_d_npc_2d_btn_response_xml
// (FUN_008ac110) pre-rebuild wipe.

void FUN_008aa560(void)
{
  int iVar1;
  int *unaff_EBX; /* EBX = mission dialog host* */
  int iVar2;
  int *piVar3;
  int *piVar4;

  piVar3 = unaff_EBX + 0x1c2; /* dialog+0x708 widget bank */
  piVar4 = unaff_EBX + 0x146; /* dialog+0x518 TFID pair bank */
  iVar2 = 8;
  do {
    iVar1 = *piVar3;
    *piVar4 = -1;
    piVar4[1] = -1;
    if (iVar1 != 0) {
      (**(void (**)(int))(*unaff_EBX + 0xbc))(iVar1);
      *piVar3 = 0;
    }
    piVar4 = piVar4 + 2;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}
