// =============================================================================
// LogicUiEventQueue_Resize
// -----------------------------------------------------------------------------
// Purpose:  MSVC-style vector::resize(n, value) for Logic-UI event elements
//           (stride 0x138). Shrink via erase-range helper; grow via InsertN
//           at end with (n - size) copies of the stack value.
//
// Address:  0x00406840  (autoassault.exe, image base 0x400000)
// Body:     0x00406840–0x004068e7 (168 bytes)
// Stable:   aa_00406840
// System:   client-logic-ui / event queue
// Ghidra:   FUN_00406840
//
// ABI:      hybrid fastcall/thiscall
//           ECX = queue*
//           EAX = newCount (element count)
//           stack: 0x138-byte value POD by-value
//           return void; RET 0x138
//
// Exactness: CF mirrors raw + read_memory bytes; types cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W24-E seal).
// Twin plate: reconstructed-exact/FUN_00406840.cpp
// Related:  LogicUiEventQueue_InsertN (0x004076a0, W23-B);
//           LogicUiEventQueue_InsertOne_GrowPath (0x004068f0, W22-I).
// =============================================================================

#include <cstdint>

static constexpr std::uint32_t kStride = 0x138u;

// Erase / compact [first, last) toward first; rebind end; *outIt = first
extern "C" void* FUN_00407640(
    void* q, void* outIt, void* first, void* last);

// Insert-N (sealed W23-B)
extern "C" void __thiscall LogicUiEventQueue_InsertN(
    void* q, void* insertAt, std::uint32_t count, const void* valueSrc);

/* LogicUiEventQueue_Resize — resize to newCount; fill grown slots from value. */

void __fastcall LogicUiEventQueue_Resize(
    void* queue,
    std::uint32_t newCount,
    const void* value /* points at 0x138 stack POD */)
{
  std::uint8_t* base = static_cast<std::uint8_t*>(queue);
  std::uint8_t* begin = *reinterpret_cast<std::uint8_t**>(base + 4);
  std::uint8_t* end = *reinterpret_cast<std::uint8_t**>(base + 8);

  std::uint32_t size;
  if (begin == nullptr) {
    size = 0;
  } else {
    size = static_cast<std::uint32_t>(
        (end - begin) / static_cast<std::ptrdiff_t>(kStride));
  }

  if (newCount <= size) {
    if (begin != nullptr && newCount < size) {
      FUN_00407640(
          queue,
          const_cast<void*>(value),
          begin + newCount * kStride,
          end);
    }
    return;
  }

  std::uint32_t cur;
  if (begin == nullptr) {
    cur = 0;
  } else {
    cur = static_cast<std::uint32_t>(
        (end - begin) / static_cast<std::ptrdiff_t>(kStride));
  }
  LogicUiEventQueue_InsertN(queue, end, newCount - cur, value);
}
