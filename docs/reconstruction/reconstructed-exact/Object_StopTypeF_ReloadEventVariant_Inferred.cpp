// =============================================================================
// Object_StopTypeF_ReloadEventVariant_Inferred  (named alias of FUN_00514d80)
// -----------------------------------------------------------------------------
// Stable ID: aa_00514d80
// Address:   0x00514d80–0x00514df3  (116 B / 0x74)
// Dual A/B:  2026-07-29 accept (W28-H)
// Authoritative clean twin: FUN_00514d80.cpp
// =============================================================================

/*
 * Stop all primary-vector FX with type code +0x28 == 0x0F via StopFinalize,
 * Ensure linked host (+0xA8) catalog, LoadEventVariant(0xF,1,-1), then
 * virtual this->vtbl[+0xF8](fx, 1, 0).
 *
 * thiscall impl (plain ret). Public MI thunk FUN_00581500 vb-adjusts this and ret 4.
 */

#include <stdint.h>

extern uint8_t __fastcall NDSpecialFX_StopFinalize_Inferred(void *fx);
extern void __fastcall FUN_004eb3b0(void *linked_host);
extern void *__thiscall FxMaster_LoadEventVariant_Inferred(
    void *catalog_host, uint32_t event_id, uint32_t mode, int slot);

void __thiscall Object_StopTypeF_ReloadEventVariant_Inferred(void *self)
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
        NDSpecialFX_StopFinalize_Inferred(entry);
      }
      it = (void **)((char *)it + 4);
    } while (it != *(void ***)(base + 0x128));
  }

  linked = *(void **)(base + 0xA8);
  FUN_004eb3b0(linked);
  if (*(void **)((char *)linked + 0x88) != 0) {
    FUN_004eb3b0(linked);
    fx = FxMaster_LoadEventVariant_Inferred(
        *(void **)((char *)linked + 0x88), 0x0Fu, 1u, -1);
    if (fx != 0) {
      vtbl = *(void ***)self;
      ((void (__thiscall *)(void *, void *, int, int))vtbl[0xF8 / 4])(
          self, fx, 1, 0);
    }
  }
}
