// =============================================================================
// Skill_QueueDeferredCastId
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d3b0
// Address:   0x0051d3b0 – 0x0051d424  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-29 dual residual (asm-sealed; prior 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler + live asm. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - thiscall: ECX = cast-slot (0x14 block from FUN_005169c0), not outer owner.
 * - Stack: uint32_t *pSkillId; epilogue RET 4.
 * - Container is MSVC deque-shaped: map[+4], mapsize[+8], off[+0xC], size[+0x10].
 * - Blocks are 0x10 bytes = 4 dwords; index uses >>2 and &3.
 * - Grow: FUN_0051c3b0(this, 1) when (off+size)&3==0 and mapsize<=(size+4)>>2.
 * - Overflow path of grow throws "deque<T> too long" (FUN_0051b5f0).
 * - Sole caller: Skill_ClearActiveCastCounterAndQueueId @ 0x00517bd4.
 * - Does not execute/validate cast or touch network.
 */

/* leave-FUN: map grow / deque reallocate */
void __thiscall FUN_0051c3b0(void *pSlot, unsigned int nMinGrow);

void *__cdecl operator_new(unsigned int cb);

void __thiscall Skill_QueueDeferredCastId(void *pSlot, unsigned int *pSkillId)
{
  unsigned int size;
  unsigned int off;
  unsigned int mapsize;
  unsigned int linear;
  unsigned int block;
  unsigned int *map;
  unsigned int *elem;
  void *newBlock;

  size = *(unsigned int *)((char *)pSlot + 0x10);
  off = *(unsigned int *)((char *)pSlot + 0x0C);

  if (((off + size) & 3U) == 0) {
    if (*(unsigned int *)((char *)pSlot + 0x08) <= ((size + 4U) >> 2)) {
      FUN_0051c3b0(pSlot, 1);
    }
  }

  mapsize = *(unsigned int *)((char *)pSlot + 0x08);
  linear = *(unsigned int *)((char *)pSlot + 0x0C)
         + *(unsigned int *)((char *)pSlot + 0x10);
  block = linear >> 2;
  if (mapsize <= block) {
    block = block - mapsize;
  }

  map = *(unsigned int **)((char *)pSlot + 0x04);
  if (*(int *)((char *)map + block * 4) == 0) {
    newBlock = operator_new(0x10);
    *(void **)((char *)map + block * 4) = newBlock;
  }

  elem = (unsigned int *)(*(unsigned int *)((char *)map + block * 4)
                          + (linear & 3) * 4);
  if (elem != 0) {
    *elem = *pSkillId;
  }

  *(unsigned int *)((char *)pSlot + 0x10) =
      *(unsigned int *)((char *)pSlot + 0x10) + 1;
}
