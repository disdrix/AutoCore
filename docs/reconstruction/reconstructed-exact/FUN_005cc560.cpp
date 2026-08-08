// =============================================================================
// FUN_005cc560  (twin of CVOGHBAI_DecEntityA4SecondaryCounter_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005cc560
// Address:   0x005cc560 – 0x005cc5ad  (autoassault.exe, image base 0x400000)
// System:    input-drive-control / npc-ai / HBAI entity counters
// Generated: 2026-08-05 MEGA-093 (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler + live bytes CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Decrement one secondary counter on entity(+0x18)->block(+0xA4) after
//   resolving related via entity vtbl+0x214, branched on related+0x250.
//   Tail target of Driver axis-park FUN_005d73a0; also vtbl method on
//   CreatureBase / Character / Mine / Bot / WalkingCreatureTurreted.

#include <stdint.h>

typedef int *(__thiscall *Entity_Vtbl214_t)(void *entity);

void __thiscall FUN_005cc560(void *self)
{
  int *entity;
  int *counters;
  int *related;
  void **entity_vtbl;

  entity = *(int **)((char *)self + 0x18);
  if (entity == 0) {
    return;
  }

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
