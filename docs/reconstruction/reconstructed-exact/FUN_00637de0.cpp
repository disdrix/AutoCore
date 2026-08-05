// =============================================================================
// FUN_00637de0 — shared Requirement progress toast Action (vtbl+0x20)
// -----------------------------------------------------------------------------
// Stable ID: aa_00637de0
// Address:   0x00637de0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler + body-byte checks.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_00637de0_*, B_aa_00637de0_*, a_00637de0.md
// =============================================================================
//
// PURPOSE:
//   Shared requirement virtual at vtbl+0x20. RecvObjectiveState (0x00809460)
//   calls this for each progress-mask bit after S2C 0x2071 slot writes.
//   Fills a short progress string via vtbl+0x1c (often trampoline 0x00637dd0
//   → SlotAction at +0x18) and enqueues a 0x98-byte toast element.
//
//   Skips when req type dword at +0x0c is 7 or 8 (Probable: Km / TimePlayed).
//   Does not mutate slots, CompleteObjective, or EvaluatePendingObjectives.
//
// CONSTANTS (read_memory 2026-07-29):
//   0x00a10e74  float 2.0   (decomp name g_flLevelUpUiBase_Inferred — shared misnomer)
//   0x00aaa68c  float 1.5   (DAT_00aaa68c)
//   color       0xffeee3d8
//
// CALLEE:
//   FUN_0040c5c0 — growable toast/floater queue push (element size 0x98).
//   this = *(*(X+4) + character + 0xA8) + 0xE8C8  (owning class open)
// =============================================================================

void __thiscall FUN_00637de0(int *req, uint32_t character, int *stateNode)
{
  uint8_t textBuf[112];
  uint32_t color;
  float scaleA;
  uint32_t scaleB_bits;
  uint32_t zeroField;
  int entityIdLo;
  int entityIdHi;

  /* req[+0x0c] = requirement type dword */
  if ((req[3] != 8) && (req[3] != 7)) {
    entityIdLo = 0xffffffff;
    textBuf[0] = 0;

    /* vtbl+0x1c: fill progress string (≤ 0x7f chars). Often trampoline → +0x18 SlotAction. */
    (**(code **)(*req + 0x1c))(character, stateNode, textBuf, 0x7f);

    color = 0xffeee3d8;
    scaleA = g_flLevelUpUiBase_Inferred;   /* 2.0f @ 0x00a10e74 */
    zeroField = 0;
    scaleB_bits = DAT_00aaa68c;            /* 1.5f @ 0x00aaa68c */

    if ((stateNode == (int *)0x0) || (*stateNode == 0)) {
      entityIdLo = -1;
      entityIdHi = -1;
    }
    else {
      entityIdLo = *(int *)(*stateNode + 0x10);
      entityIdHi = entityIdLo >> 0x1f;     /* CDQ sign-extend to int64 */
    }

    /* Enqueue 0x98-byte toast element (string + color/scale/id trailer).
       Ghidra drops thiscall ECX = toast queue. */
    FUN_0040c5c0(&stack0xffffff58);
  }
  return;
}
