// READABILITY (auto CF):
//  - Body size: small (~20 insn).
//  - Control: counter gate, dec, conditional +0xC clear, always queue.
//  - Notable callees: FUN_005169c0×3, Skill_QueueDeferredCastId×1.
//  - Return sites: 1 (AL = was-counter-live).

// =============================================================================
// Skill_ClearActiveCastCounterAndQueueId
// -----------------------------------------------------------------------------
// Stable ID: aa_00517b90
// Address:   0x00517b90  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 scaffold; residual strengthen 2026-07-29 (asm CF)
// Exactness: Behavior-preserving rewrite of decompiler + asm control flow.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (sealed 2026-07-29 residual):
 * - thiscall-shaped: ECX = owner (lazy slot ptr at +0x64 via FUN_005169c0);
 *   stack arg nSkillId; RET 4.
 * - slot+0x10: busy/active-cast refcount — DECREMENT if >= 1 (not force-zero).
 * - slot+0xC: zeroed only when counter hits 0 after decrement.
 * - Always queues nSkillId via Skill_QueueDeferredCastId with slot as this.
 * - Returns char 1 if counter was live at entry, else 0.
 * - Known callers (4) ignore return; use for side effects only.
 * - FUN_005169c0 is leave-FUN (no product rename this unit).
 *
 * Readability pass:
 * - Prefer asm where decompiler mis-attributed third FUN_005169c0 args.
 */

/* Skill_ClearActiveCastCounterAndQueueId(this, nSkillId)
   Parameters:
     this    - owner with FUN_005169c0 lazy 0x14 slot at +0x64
     nSkillId - skill id pushed onto deferred cast ring
   Algorithm: if counter>=1 decrement (+ clear +0xC at 0); always queue id.
   Returns: char 1 if counter was nonzero/live at entry. */

extern "C" void *__fastcall FUN_005169c0(void *self);
extern "C" void __thiscall Skill_QueueDeferredCastId(void *slot, int *pSkillId);

char __thiscall Skill_ClearActiveCastCounterAndQueueId(void *self, int nSkillId)
{
  char wasLive;
  void *slot;
  int counter;

  wasLive = '\0';
  slot = FUN_005169c0(self);
  if (*(int *)((char *)slot + 0x10) >= 1) {
    slot = FUN_005169c0(self);
    counter = *(int *)((char *)slot + 0x10);
    if (counter != 0) {
      counter = counter - 1;
      *(int *)((char *)slot + 0x10) = counter;
      if (counter == 0) {
        *(unsigned int *)((char *)slot + 0xc) = 0;
      }
    }
    wasLive = '\x01';
  }
  slot = FUN_005169c0(self);
  Skill_QueueDeferredCastId(slot, &nSkillId);
  return wasLive;
}
