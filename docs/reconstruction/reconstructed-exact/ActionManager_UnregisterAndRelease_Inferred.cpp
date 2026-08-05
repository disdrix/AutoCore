// =============================================================================
// ActionManager_UnregisterAndRelease_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0055df40
// Address:   0x0055df40  (autoassault.exe, image base 0x400000)
// Body:      0x0055df40–0x0055df76 exclusive (54 / 0x36 bytes)
// System:    vehicle / world action lifecycle
// Generated: 2026-07-29 W23-P OWN-ONLY dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Unregister an action object from the world/action manager, remove it from
//   its reverse host list, clear the "registered" dword at action+0xC, and
//   release one COM-style short refcount at action+6 (destroy via vtbl[0](1)
//   when the count hits zero).
//
// ABI (sealed by read_memory):
//   ECX            = ActionManager*  (often *(world + 0xe4a4))
//   [esp+4]        = ActionObject*
//   epilogue       = ret 4
//   return         = void
//
// NAME: Inferred — no plate string in body. Parent duals describe "unregister
//   action from world/action list". Scaffold alias Named_CalleeOf_…SERVER_GOT_GIGO
//   is misleading parent-seed noise.
//
// GAPS:
//   - Product English for manager / action classes
//   - Dual of nested FUN_0062a410 / FUN_00628f10 / FUN_005fff20 (not owned)
//   - Runtime / differential open
// =============================================================================

#include <cstdint>

// Nested (not dual-owned here):
//   FUN_0062a410(manager, action) — walk manager+0x3c listeners; (*vtbl+0xC)(action)
//   FUN_00628f10(host, action)    — thiscall; host = *(action+0x10); shrink-remove

extern "C" void FUN_0062a410(void* manager, void* action);
extern "C" void __thiscall FUN_00628f10(void* host, void* action);

void __thiscall ActionManager_UnregisterAndRelease_Inferred(void* manager, void* action)
{
  FUN_0062a410(manager, action);

  // Bytes: mov ecx, [action+0x10]; push action; call FUN_00628f10
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

// Ghidra symbol alias
void __thiscall FUN_0055df40(void* manager, void* action)
{
  ActionManager_UnregisterAndRelease_Inferred(manager, action);
}
