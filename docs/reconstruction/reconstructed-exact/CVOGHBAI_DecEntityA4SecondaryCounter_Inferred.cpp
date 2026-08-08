// =============================================================================
// CVOGHBAI_DecEntityA4SecondaryCounter_Inferred
// -----------------------------------------------------------------------------
// Purpose:  HBAI leaf — if this->entity(+0x18) and entity->counters(+0xA4)
//           are live, call entity->vtbl[+0x214]() and decrement one secondary
//           counter on the A4 block:
//             related+0x250 == 0 → counters[+0x18]--
//             related+0x250 != 0 → counters[+0x1c]--
//
// Context:  Virtual on CVOGHBAICreatureBase family (slot after OnHeartBeat).
//           CVOGHBAIDriver park override FUN_005d73a0 zeros drive axes /
//           handbrake / weapons, pushes axes, then tail-JMPs here.
//
// Address:  0x005cc560 – 0x005cc5ad (78 B / 0x4E); pad CC before 0x005cc5b0
// Stable:   aa_005cc560
// System:   input-drive-control / npc-ai / HBAI entity counters
// Ghidra:   FUN_005cc560
//
// Convention: MSVC __thiscall
//   this  HBAI subclass*
//   void  plain ret via shared thunk 0x005081e0 (C3)
//
// Dual A/B: 2026-08-05 MEGA-093 accept-with-gaps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Product English for +0xA4 / +0x250 / vtbl+0x214: OPEN → _Inferred.
// =============================================================================

#include <stdint.h>

typedef int *(__thiscall *Entity_Vtbl214_t)(void *entity);

void __thiscall CVOGHBAI_DecEntityA4SecondaryCounter_Inferred(void *self)
{
  int *entity;
  int *counters;
  int *related;
  void **entity_vtbl;

  entity = *(int **)((char *)self + 0x18);
  if (entity == 0) {
    return;
  }

  /* entity[+0xA4] — decomp piVar1[0x29] */
  counters = *(int **)((char *)entity + 0xA4);
  if (counters == 0) {
    return;
  }

  entity_vtbl = *(void ***)entity;
  related = ((Entity_Vtbl214_t)entity_vtbl[0x214 / 4])(entity);
  if (related == 0) {
    return;
  }

  if (*(int *)((char *)related + 0x250) == 0) {
    *(int *)((char *)counters + 0x18) -= 1;
  } else {
    *(int *)((char *)counters + 0x1c) -= 1;
  }
}
