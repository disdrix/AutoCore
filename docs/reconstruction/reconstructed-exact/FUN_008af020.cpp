// =============================================================================
// FUN_008af020  (proposed: Client_MissionDialog_PrimaryButtonClose — Probable)
// -----------------------------------------------------------------------------
// Stable ID: aa_008af020
// Address:   0x008af020  (autoassault.exe, image base 0x400000)
// Body:      0x008af020 – 0x008af056
// System:    missions-progression
// Generated: 2026-07-23 scaffold; dual A/B refine 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler + asm. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Thin mission-dialog primary-context close path (sibling of FUN_008aec40
//   success/close tail at LAB_008aef8f family).
//   1) Client_MissionDialogHandleButton(dialog, context=0)
//   2) if success: FUN_007fca10 → visible dialog vtbl+0x440 FlushPreparedResponse
//   3) if dialog+0x648 == 2: FUN_007fef20(client, index=0x13, open=1, flag=0)
//   Always returns 1 (AL).
//
// Calling convention (asm):
//   ESI = mission dialog object (parent @ 0x008af060: mov esi, ecx when msg==0x0D).
//   Parent DATA: vtbl 0x00a4a870 = class base 0x00a4a51c + 0x354.
//
// Dual A/B:
//   reviews/A_aa_008af020_Client_MissionDialog_PrimaryButtonClose.md
//   reviews/B_aa_008af020_Client_MissionDialog_PrimaryButtonClose.md

char __cdecl Client_MissionDialogHandleButton(int *pDialogContext, int /*iButtonIndex_unused*/);
void FUN_007fca10(void);  // EBX = client host (DAT_00d1a840) at call site
void __thiscall FUN_007fef20(int *client, int dialogIndex, char openNotToggleClose, char flag);

extern int DAT_00d1a840;  // client singleton

// ESI must be dialog on entry (parent sets it). Returns 1.
unsigned char FUN_008af020(/* ESI: int *dialog */)
{
  // Register state: ESI = dialog (unaff_ESI in decompiler).
  int *dialog_esi; /* ESI — set by parent; not a formal param */

  // 6A 00; 8B C6; E8 …  → context 0, dialog in EAX for HandleButton
  char ok = Client_MissionDialogHandleButton((int *)0x0, 0);
  if (ok == '\0') {
    return 1;
  }

  // BB 40 A8 D1 00; E8 … FUN_007fca10  (EBX = &client / DAT_00d1a840)
  FUN_007fca10();

  // 83 BE 48 06 00 00 02  → [ESI+0x648] == 2
  if (*(int *)((char *)dialog_esi + 0x648) == 2) {
    // 6A 00; 6A 01; 6A 13; B9 40 A8 D1 00; E8 … FUN_007fef20
    FUN_007fef20((int *)&DAT_00d1a840, 0x13, 1, 0);
  }

  return 1;
}
