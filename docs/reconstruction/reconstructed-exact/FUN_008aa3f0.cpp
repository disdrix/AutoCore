// =============================================================================
// FUN_008aa3f0 — Dialog_SelectRewardSlot (product alias, tentative)
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa3f0
// Address:   0x008aa3f0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual A/B refine from live Ghidra + prologue bytes
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A|B_aa_008aa3f0_Dialog_SelectRewardSlot.md  (accept-with-gaps)
// =============================================================================

// PURPOSE:
//   Select mission-dialog reward slot `slotIndex`:
//     1) Copy 8-byte TFID from dialog+0x558[slot] into selected pair +0x578/+0x57c.
//     2) Apply unselected style (dialog+0x594) to all four widgets at +0x698.
//     3) Apply selected style (dialog+0x5a4) to the chosen slot widget.
//     4) Clear choose-reward hint widget +0x708 with empty DAT_00a1419b.
//
// ABI (sealed):
//   EAX = dialog UI host (not ECX thiscall).
//   stack arg0 = slot index (0..3 expected; no clamp in body).
//
// Callers (sealed):
//   FUN_008aa760 @ 0x008aa968 — auto-select slot 0 when count==1 && turn-in.
//   FUN_008aec40 @ 0x008aed23 — click controlId 0x9c42..0x9c45 → slot = id-0x9c42.

// External: empty C-string used to clear multi-reward hint text.
extern char DAT_00a1419b[];  // first byte 0x00

void FUN_008aa3f0(int slotIndex)
{
  // Register this on entry (Ghidra: in_EAX). Callers MOV EAX, dialog before CALL.
  int dialog;  // = EAX at entry
  int remaining;
  unsigned int *widgetCursor;

  // --- Commit selection TFID (lo/hi) from per-slot table ---
  *(unsigned int *)(dialog + 0x578) =
      *(unsigned int *)(dialog + 0x558 + slotIndex * 8);
  *(unsigned int *)(dialog + 0x57c) =
      *(unsigned int *)(dialog + 0x55c + slotIndex * 8);

  // --- All four reward chrome widgets → unselected style ---
  widgetCursor = (unsigned int *)(dialog + 0x698);
  remaining = 4;
  do {
    // vtbl+0x158(0, unselectedStyle); vtbl+0x34c() refresh
    (**(void (**)(int, int))(*(int *)*widgetCursor + 0x158))(0, dialog + 0x594);
    (**(void (**)(void))(*(int *)*widgetCursor + 0x34c))();
    widgetCursor = widgetCursor + 1;  // stride 4
    remaining = remaining - 1;
  } while (remaining != 0);

  // --- Chosen slot widget → selected style ---
  (**(void (**)(int, int))(**(int **)(dialog + 0x698 + slotIndex * 4) + 0x158))(
      0, dialog + 0x5a4);
  (**(void (**)(void))(**(int **)(dialog + 0x698 + slotIndex * 4) + 0x34c))();

  // --- Clear "You must choose a reward item first" hint ---
  if (*(int **)(dialog + 0x708) != (int *)0) {
    (**(void (**)(char *))(**(int **)(dialog + 0x708) + 0x308))(&DAT_00a1419b);
  }
  return;
}
