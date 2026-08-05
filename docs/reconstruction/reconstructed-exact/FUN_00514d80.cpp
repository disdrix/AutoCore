// =============================================================================
// FUN_00514d80
// -----------------------------------------------------------------------------
// Stable ID: aa_00514d80
// Address:   0x00514d80–0x00514df3  (116 B / 0x74)
// System:    client-fx / type-0xF stop + event-variant reload
// Generated: 2026-07-29 W28-H (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte corrections.
// Bit-for-bit vs retail EXE: DEFERRED.
// Named alias: Object_StopTypeF_ReloadEventVariant_Inferred.cpp
// =============================================================================

#include <stdint.h>

extern uint8_t __fastcall FUN_004ba0a0(void *fx);
extern void __fastcall FUN_004eb3b0(void *linked_host);
extern void *__thiscall FUN_004a16d0(
    void *catalog_host, uint32_t event_id, uint32_t mode, int slot);

void __thiscall FUN_00514d80(void *self)
{
  char *base = (char *)self;
  void **it  = *(void ***)(base + 0x124);
  void **end = *(void ***)(base + 0x128);
  void *linked;
  void *fx;
  void **vtbl;

  if (it != end) {
    do {
      void *entry = *it;
      if (*(int *)((char *)entry + 0x28) == 0x0F) {
        FUN_004ba0a0(entry);
      }
      it = (void **)((char *)it + 4);
    } while (it != *(void ***)(base + 0x128));
  }

  linked = *(void **)(base + 0xA8);
  FUN_004eb3b0(linked);
  if (*(void **)((char *)linked + 0x88) != 0) {
    FUN_004eb3b0(linked);
    fx = FUN_004a16d0(*(void **)((char *)linked + 0x88), 0x0Fu, 1u, -1);
    if (fx != 0) {
      vtbl = *(void ***)self;
      ((void (__thiscall *)(void *, void *, int, int))vtbl[0xF8 / 4])(
          self, fx, 1, 0);
    }
  }
}
