// =============================================================================
// FUN_00829ac0 — scaffold alias → UI_MissionJournal_ApplyStatusCompleteLabel_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ac0
// Address:   0x00829ac0  (autoassault.exe, image base 0x400000)
// W25-G: Prefer clean plate UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.cpp
// =============================================================================

// Scaffold retained for Ghidra-symbol lookup. Authoritative CF + ABI:
//   docs/reconstruction/reconstructed-exact/UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.cpp
//
// void FUN_00829ac0(void)
// {
//   // ESI = journal panel*; AL = complete flag
//   // store [ESI+0x4fd] = AL
//   // status = [ESI+0x50c]; if null return
//   // SetText vtbl+0x1d8: AL? "(complete)": null  with args (text,1,1)
//   // tail jmp vtbl+0x34c
// }

void FUN_00829ac0(void);
