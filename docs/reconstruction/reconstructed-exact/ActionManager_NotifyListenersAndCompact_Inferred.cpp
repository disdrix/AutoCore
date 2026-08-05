// =============================================================================
// ActionManager_NotifyListenersAndCompact_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0062a410
// Address:   0x0062a410  (autoassault.exe, image base 0x400000)
// Body:      0x0062a410–0x0062a444 exclusive (52 / 0x34 bytes)
// System:    vehicle / world action lifecycle
// Generated: 2026-07-29 W24-P OWN-ONLY dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Notify every non-null listener in the action-manager table at
//   manager+0x3c[0..count@+0x40), invoking listener->vtbl[+0xC](action)
//   (thiscall, ECX=listener). Then tail-call FUN_005fff20 with EAX =
//   manager+0x3c to compact null slots out of that pointer vector.
//
// ABI (sealed by read_memory + parent call site FUN_0055df40):
//   [esp+4]        = manager*
//   [esp+8]        = action*
//   convention     = cdecl (caller ADD ESP, 8)
//   epilogue       = JMP FUN_005fff20 (no local ret); EAX = manager+0x3c
//   return         = void
//
// NAME: Inferred — no plate string. Parent dual describes notify of
//   manager+0x3c listeners during unregister.
//
// GAPS:
//   - Product English for manager / listener classes
//   - Dual of nested FUN_005fff20 (not owned)
//   - Runtime / differential open
// =============================================================================

#include <cstdint>

// Nested (not dual-owned here):
//   FUN_005fff20 — uses EAX as PtrVec* {base*, count@+4}; strip nulls; RET
//   Decompiler shows FUN_005fff20() with no args (residual).
extern "C" void FUN_005fff20(void);

struct PtrVec {
  void **base;     // manager+0x3c
  int32_t count;   // manager+0x40
};

using ListenerNotifyVfunc = void(__thiscall *)(void *listener, void *action);

// Retail: compact is a tail JMP with EAX=vec. Documented as call for readability;
// stack args remain for the original cdecl caller to clean (ADD ESP, 8).
// Port note: invoke FUN_005fff20 with EAX preset to vec, or inline compact.
static void compact_ptr_vec_tail(PtrVec * /*vec*/)
{
  FUN_005fff20();
}

void ActionManager_NotifyListenersAndCompact_Inferred(void *manager, void *action)
{
  auto *const vec = reinterpret_cast<PtrVec *>(reinterpret_cast<char *>(manager) + 0x3c);
  int32_t i = vec->count - 1;

  while (i >= 0) {
    void *listener = vec->base[static_cast<uint32_t>(i)];
    if (listener != nullptr) {
      void **vtbl = *reinterpret_cast<void ***>(listener);
      // vtbl entry at +0xC == index 3
      reinterpret_cast<ListenerNotifyVfunc>(vtbl[3])(listener, action);
    }
    --i;
  }

  // Bytes: mov eax, edi /*vec*/; pop edi; pop esi; jmp FUN_005fff20
  // Implicit: EAX must equal vec when entering FUN_005fff20.
  compact_ptr_vec_tail(vec);
}

// Ghidra symbol alias
void FUN_0062a410(void *manager, void *action)
{
  ActionManager_NotifyListenersAndCompact_Inferred(manager, action);
}
