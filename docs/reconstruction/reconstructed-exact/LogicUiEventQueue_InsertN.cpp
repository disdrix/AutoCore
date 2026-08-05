// =============================================================================
// LogicUiEventQueue_InsertN
// -----------------------------------------------------------------------------
// Purpose:  MSVC-style vector insert-N for Logic-UI event elements (stride 0x138).
//           Construct value, grow or shift, fill count copies at insertAt.
//
// Address:  0x004076a0  (autoassault.exe, image base 0x400000)
// Body:     0x004076a0–0x00407991 (754 bytes)
// Stable:   aa_004076a0
// System:   client-logic-ui / event queue
// Ghidra:   FUN_004076a0
//
// ABI:      __thiscall  void LogicUiEventQueue_InsertN(Queue*, void* at, uint32_t n, const void* val)
//           ECX=queue; Stack insertAt, count, valueSrc; RET 0xC
//
// Exactness: CF mirrors raw + read_memory bytes; types cleaned (no bare undefined4).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W23-B seal).
// Twin plate: reconstructed-exact/FUN_004076a0.cpp
// =============================================================================

#include <cstdint>
#include <cstring>

// External helpers (roles from CF usage; dual residual unless sealed elsewhere)
extern "C" {
  void __thiscall FUN_00408880(void* dest, const void* src);           // POD copy 0x138
  void FUN_00418130(void);                                              // throw vector too long
  int __fastcall FUN_004059c0(void* queue /*ECX size context*/);        // exact grow floor helper
  void* __cdecl operator_new(std::uint32_t size);
  void __cdecl operator_delete(void* p);
  std::uint32_t __thiscall FUN_00409a70(void* q, void* first, void* last, void* dest);
  std::uint32_t __thiscall FUN_00406970(void* q, void* dest, std::uint32_t count, void* value);
  void FUN_00409a90(void* first, void* last, void* value);              // mid patch / assign range
  void FUN_00409ac0(void* first, void* mid, void* last);                // mid shift helper
}

// Max elements for stride 0x138: address-of DAT used as integer 0x00D20D20
static constexpr std::uint32_t kMaxElements_0x138 = 0x00D20D20u;
static constexpr std::uint32_t kStride = 0x138u;

struct LogicUiEventQueue {
  // +0x00 unused in this unit
  std::uint8_t* begin;     // +0x04
  std::uint8_t* end;       // +0x08
  std::uint8_t* cap_end;   // +0x0C
};

/* LogicUiEventQueue_InsertN — insert `count` copies of `valueSrc` before `insertAt`.

   Parameters:
     queue:     vector shell (begin/end/cap_end)
     insertAt:  position iterator (byte pointer into buffer)
     count:     number of elements to insert (0 = no-op after construct)
     valueSrc:  POD source; copied into 0x138 stack temp first

   Growth:
     if capacity < size+count: newCap = min-safe 1.5x or exact size+count;
     relocate [begin,at) + fill count + [at,end); delete old; rebind.

   Returns: void */

void __thiscall LogicUiEventQueue_InsertN(
    LogicUiEventQueue* queue,
    std::uint8_t* insertAt,
    std::uint32_t count,
    const void* valueSrc)
{
  std::uint8_t valueBuf[kStride];
  std::uint32_t capacity;
  int size;
  void* newBuf;
  std::uint32_t destCursor;
  std::uint8_t* oldBegin;
  int oldSize;
  std::uint8_t* endPtr;
  int tailBytes;
  std::uint32_t insertBytes;
  std::uint8_t* shiftFrom;
  std::uint32_t newEnd;

  // SEH frame omitted (ExceptionList / LAB_009be300) — CF-equivalent body below.

  FUN_00408880(valueBuf, valueSrc);

  if (queue->begin == nullptr) {
    capacity = 0;
  } else {
    capacity = static_cast<std::uint32_t>((queue->cap_end - queue->begin) / static_cast<int>(kStride));
  }

  if (count == 0) {
    return;
  }

  if (queue->begin == nullptr) {
    size = 0;
  } else {
    size = static_cast<int>((queue->end - queue->begin) / static_cast<int>(kStride));
  }

  if (static_cast<std::uint32_t>(static_cast<int>(kMaxElements_0x138) - size) < count) {
    FUN_00418130();
    // noreturn in retail; decompiler may fall through with clobbered ECX
  }

  if (queue->begin == nullptr) {
    size = 0;
  } else {
    size = static_cast<int>((queue->end - queue->begin) / static_cast<int>(kStride));
  }

  if (capacity < static_cast<std::uint32_t>(size) + count) {
    // 1.5x grow when (max - (cap>>1)) >= cap, else reset to 0 then exact-need path
    if (static_cast<int>(kMaxElements_0x138) - static_cast<int>(capacity >> 1) < static_cast<int>(capacity)) {
      capacity = 0;
    } else {
      capacity = capacity + (capacity >> 1);
    }

    if (queue->begin == nullptr) {
      size = 0;
    } else {
      size = static_cast<int>((queue->end - queue->begin) / static_cast<int>(kStride));
    }

    if (capacity < static_cast<std::uint32_t>(size) + count) {
      size = FUN_004059c0(queue);
      capacity = static_cast<std::uint32_t>(size) + count;
    }

    capacity = capacity * kStride;
    newBuf = operator_new(capacity);

    destCursor = FUN_00409a70(queue, queue->begin, insertAt, newBuf);
    destCursor = FUN_00406970(queue, reinterpret_cast<void*>(destCursor), count, valueBuf);
    FUN_00409a70(queue, insertAt, queue->end, reinterpret_cast<void*>(destCursor));

    oldBegin = queue->begin;
    if (oldBegin == nullptr) {
      oldSize = 0;
    } else {
      oldSize = static_cast<int>((queue->end - oldBegin) / static_cast<int>(kStride));
    }
    if (oldBegin != nullptr) {
      operator_delete(oldBegin);
    }

    queue->cap_end = static_cast<std::uint8_t*>(newBuf) + capacity;
    queue->end = static_cast<std::uint8_t*>(newBuf) + (count + static_cast<std::uint32_t>(oldSize)) * kStride;
    queue->begin = static_cast<std::uint8_t*>(newBuf);
    return;
  }

  endPtr = queue->end;
  tailBytes = static_cast<int>(endPtr - insertAt);
  if (static_cast<std::uint32_t>(tailBytes / static_cast<int>(kStride)) < count) {
    insertBytes = count * kStride;
    FUN_00409a70(queue, insertAt, endPtr, insertAt + insertBytes);
    FUN_00406970(
        queue,
        queue->end,
        count - static_cast<std::uint32_t>((queue->end - insertAt) / static_cast<int>(kStride)),
        valueBuf);
    queue->end = queue->end + insertBytes;
    FUN_00409a90(insertAt, queue->end - insertBytes, valueBuf);
    return;
  }

  insertBytes = count * kStride;
  shiftFrom = endPtr - static_cast<int>(count * kStride);
  newEnd = FUN_00409a70(queue, shiftFrom, endPtr, endPtr);
  queue->end = reinterpret_cast<std::uint8_t*>(newEnd);
  FUN_00409ac0(insertAt, shiftFrom, endPtr);
  FUN_00409a90(insertAt, insertAt + insertBytes, valueBuf);
}
