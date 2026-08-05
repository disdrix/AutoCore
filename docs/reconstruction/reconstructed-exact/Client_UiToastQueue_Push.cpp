// =============================================================================
// Client_UiToastQueue_Push
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c5c0
// Address:   0x0040c5c0  (autoassault.exe, image base 0x400000)
// System:    missions-progression (shared UI toast queue)
// Generated: 2026-07-29 dual seal from live Ghidra decompile + read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Push one POD toast element (sizeof 0x98) onto a growable queue.
//   Fast path: in-place copy at end when size < capacity.
//   Slow path: grow/realloc via FUN_0040c720 / FUN_00403980.
//
//   Does NOT format text, play audio, or mutate mission state.
//   Callers (GiveMission, CompleteObjective, craft success, progress Action, …)
//   pack the element then call with:
//     ECX = *(*(character+4)+4 + character + 0xA8) + 0xE8C8
//
// ABI: __thiscall, one stack arg, ret 4.
// Queue: begin@+4, end@+8, capacity_end@+0xC.
// =============================================================================

#include <cstdint>

// Unresolved callees (keep FUN_* until their duals rename):
extern "C" void FUN_00404670(void* dst, int count, void* src);
extern "C" void __thiscall FUN_0040c720(void* queue, void** outIt, void* insertPos,
                                        void* srcElement);

struct ToastQueue {
  std::uint32_t unused0;  // not touched by this VA
  std::uint8_t* begin;    // +0x04
  std::uint8_t* end;      // +0x08
  std::uint8_t* cap_end;  // +0x0C
};

// Element is opaque POD of stride 0x98 (caller-owned field layout).
static constexpr std::size_t kToastElementStride = 0x98;

void __thiscall Client_UiToastQueue_Push(ToastQueue* self, void* pElement)
{
  std::uint8_t* begin = self->begin;
  if (begin != nullptr) {
    const std::size_t size =
        static_cast<std::size_t>(self->end - begin) / kToastElementStride;
    const std::size_t cap =
        static_cast<std::size_t>(self->cap_end - begin) / kToastElementStride;
    if (size < cap) {
      std::uint8_t* slot = self->end;
      FUN_00404670(slot, 1, pElement);
      self->end = slot + kToastElementStride;
      return;
    }
  }

  void* outIt = nullptr;
  FUN_0040c720(self, &outIt, self->end, pElement);
}

// Legacy Ghidra export name
void __thiscall FUN_0040c5c0(ToastQueue* self, void* pElement)
{
  Client_UiToastQueue_Push(self, pElement);
}
