// =============================================================================
// ActionHost_RemoveReverseListEntry_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00628f10
// Address:   0x00628f10  (autoassault.exe, image base 0x400000)
// Body:      0x00628f10–0x00628f64 exclusive (84 / 0x54 bytes)
// System:    vehicle / world action lifecycle
// Generated: 2026-07-29 W24-P OWN-ONLY dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Remove an action pointer from a host object's reverse list
//   (base @ host+0x4c, count @ host+0x50) via linear search + order-preserving
//   shift. Clear action+0x10 (back host link). Set host+0x28 = 1 (dirty).
//
// ABI (sealed by read_memory + parent FUN_0055df40 call site):
//   ECX            = host*   (often *(action + 0x10) at call site)
//   [esp+4]        = action*
//   epilogue       = ret 4
//   return         = void
//
// NAME: Inferred — no plate string. Parent dual names this reverse-list remove.
//
// GAPS:
//   - Product English for host / action classes
//   - Semantics of dirty flag +0x28
//   - Not-found path decrements count anyway (call-site invariant: present)
//   - Runtime / differential open
// =============================================================================

#include <cstdint>

void __thiscall ActionHost_RemoveReverseListEntry_Inferred(void *host, void *action)
{
  auto *const count_p = reinterpret_cast<int32_t *>(reinterpret_cast<char *>(host) + 0x50);
  auto **const base_p = reinterpret_cast<void ***>(reinterpret_cast<char *>(host) + 0x4c);

  int32_t index = 0;
  const int32_t count = *count_p;
  if (count > 0) {
    void **slot = *base_p;
    do {
      if (*slot == action) {
        goto found;
      }
      ++index;
      ++slot;
    } while (index < count);
  }
  index = -1;

found:
  *count_p = *count_p - 1;
  if (index < *count_p) {
    void **base = *base_p;
    do {
      base[static_cast<uint32_t>(index)] = base[static_cast<uint32_t>(index) + 1];
      ++index;
    } while (index < *count_p);
  }

  *reinterpret_cast<void **>(reinterpret_cast<char *>(action) + 0x10) = nullptr;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(host) + 0x28) = 1;
}

// Ghidra symbol alias
void __thiscall FUN_00628f10(void *host, void *action)
{
  ActionHost_RemoveReverseListEntry_Inferred(host, action);
}
