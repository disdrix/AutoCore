// =============================================================================
// FUN_0062a410 — scaffold alias → ActionManager_NotifyListenersAndCompact_Inferred
// Stable ID: aa_0062a410
// Address:   0x0062a410
// Sealed:    2026-07-29 W24-P
// Body:      52 B; cdecl manager, action; tail JMP FUN_005fff20 (EAX=manager+0x3c)
// =============================================================================

#include <cstdint>

extern "C" void FUN_005fff20(void);

void FUN_0062a410(void *manager, void *action)
{
  int32_t i = *reinterpret_cast<int32_t *>(reinterpret_cast<char *>(manager) + 0x40) - 1;
  void **base = *reinterpret_cast<void ***>(reinterpret_cast<char *>(manager) + 0x3c);

  while (i >= 0) {
    void *listener = base[static_cast<uint32_t>(i)];
    if (listener != nullptr) {
      void **vtbl = *reinterpret_cast<void ***>(listener);
      using Vfn = void(__thiscall *)(void *, void *);
      reinterpret_cast<Vfn>(vtbl[3])(listener, action);
    }
    --i;
  }

  // Decompiler residual: FUN_005fff20() — bytes require EAX = manager+0x3c
  FUN_005fff20();
}
