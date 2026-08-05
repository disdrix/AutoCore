// =============================================================================
// FUN_0055df40 — scaffold alias → ActionManager_UnregisterAndRelease_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055df40
// Address:   0x0055df40  (autoassault.exe, image base 0x400000)
// Body:      0x0055df40–0x0055df76 exclusive (54 B)
// System:    vehicle / world action lifecycle
// Generated: 2026-07-29 W23-P OWN-ONLY (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving; nested callees by Ghidra name.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Prefer: reconstructed-exact/ActionManager_UnregisterAndRelease_Inferred.cpp
// Legacy: Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_0055df40.cpp

#include <cstdint>

extern "C" void FUN_0062a410(void* manager, void* action);
extern "C" void __thiscall FUN_00628f10(void* host, void* action);

void __thiscall FUN_0055df40(void* manager /* ECX */, void* action /* [esp+4] */)
{
  FUN_0062a410(manager, action);

  // Decompiler residual: shows FUN_00628f10(action) only.
  // Bytes set ECX = *(action+0x10) before the call.
  void* host = *reinterpret_cast<void**>(reinterpret_cast<char*>(action) + 0x10);
  FUN_00628f10(host, action);

  int16_t* ref = reinterpret_cast<int16_t*>(reinterpret_cast<char*>(action) + 6);
  *ref = static_cast<int16_t>(*ref - 1);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(action) + 0x0C) = 0;

  if (*ref == 0) {
    using Vtbl0 = void(__thiscall*)(void* self, int flag);
    void** vtbl = *reinterpret_cast<void***>(action);
    reinterpret_cast<Vtbl0>(vtbl[0])(action, 1);
  }
}
