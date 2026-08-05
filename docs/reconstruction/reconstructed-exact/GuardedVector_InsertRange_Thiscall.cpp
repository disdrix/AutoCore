// =============================================================================
// GuardedVector_InsertRange_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_005441d0
// Address:   0x005441d0–0x00544587  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005441d0
// System:    STL / guarded ring-deque container
// Dual:      W32-I 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ECX = dest container; 7 stack formals; RET 0x1C.
// Inserts [first, last) at absolute insert_at using shorter-side policy.
// Room via GuardedVector_PushFront_Thiscall / PushBack_Thiscall (W31-I).
// Assign via FUN_0043ec50 (forward) / FUN_0043ebb0 (backward).
// Sole known caller FUN_00545190: empty dest + full source range at 0.
// Name is structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void**   slots;     // +0x04
  uint32_t capacity;  // +0x08  pages
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
};

// W31-I sealed thiscall push pair (ECX=container; stack value*; RET 4).
extern "C" void GuardedVector_PushFront_Thiscall(GuardedVectorHeader* c /*ECX*/,
                                                 const uint32_t* value);
extern "C" void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* c /*ECX*/,
                                                const uint32_t* value);

// Ring assign helpers (unowned): write *dst = *src for [from,to) with page wrap;
// store ending iterator pair into *out.
extern "C" void FUN_0043ec50(int* outPair,
                             GuardedVectorHeader* fromC, uint32_t fromIdx,
                             GuardedVectorHeader* toC, uint32_t toIdx,
                             GuardedVectorHeader* dstC, uint32_t dstIdx);
extern "C" void FUN_0043ebb0(int* outPair,
                             GuardedVectorHeader* fromC, uint32_t fromIdx,
                             GuardedVectorHeader* toC, uint32_t toIdx,
                             GuardedVectorHeader* dstC, uint32_t dstIdx);

// Map absolute index → element* (page = idx>>2 wrap capacity; slot = pages[page] + (idx&3)).
static inline uint32_t* MapSlot(GuardedVectorHeader* c, uint32_t absIdx)
{
  uint32_t page = absIdx >> 2;
  if (c->capacity <= page) {
    page -= c->capacity;
  }
  return reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(c->slots[page]) + ((absIdx & 3u) * 4u));
}

// Retail: ECX=dest; 7 stack formals; RET 0x1C.
// Decompiler shape uses (dest, scratch, insert_at, firstC, firstIdx, lastC, lastIdx).
void GuardedVector_InsertRange_Thiscall(
    GuardedVectorHeader* dest /*ECX*/,
    uint32_t /*scratch_or_out*/,
    uint32_t insert_at,
    GuardedVectorHeader* firstC,
    uint32_t firstIdx,
    GuardedVectorHeader* lastC,
    uint32_t lastIdx
    /* + 7th stack residual from some callers */)
{
  const uint32_t prefix =
      insert_at - static_cast<uint32_t>(dest->begin);
  const uint32_t suffix =
      static_cast<uint32_t>(dest->size) - prefix;
  const uint32_t n = lastIdx - firstIdx;

  int outPair[2];

  if (prefix < suffix) {
    // Front-biased: make room with push_front.
    if (prefix < n) {
      uint32_t u = firstIdx + (n - prefix);
      while (firstC != lastC || firstIdx != u) {
        --u;
        GuardedVector_PushFront_Thiscall(dest, MapSlot(firstC, u));
      }
      uint32_t left = prefix;
      while (left != 0) {
        const uint32_t abs =
            static_cast<uint32_t>(dest->begin) + (n - 1u);
        GuardedVector_PushFront_Thiscall(dest, MapSlot(dest, abs));
        --left;
      }
      FUN_0043ec50(outPair, firstC, firstIdx + (n - prefix), lastC, lastIdx,
                   dest, static_cast<uint32_t>(dest->begin) + n);
      return;
    }
    uint32_t left = n;
    while (left != 0) {
      const uint32_t abs =
          static_cast<uint32_t>(dest->begin) + (n - 1u);
      GuardedVector_PushFront_Thiscall(dest, MapSlot(dest, abs));
      --left;
    }
    {
      const int32_t base = dest->begin + static_cast<int32_t>(n);
      int scratchPair[2];
      FUN_0043ec50(scratchPair, dest,
                   static_cast<uint32_t>(base + static_cast<int32_t>(n)),
                   dest,
                   static_cast<uint32_t>(base + static_cast<int32_t>(prefix)),
                   dest, static_cast<uint32_t>(base));
    }
    // fall through: assign source range at insert hole
    {
      const int32_t hole =
          dest->begin + static_cast<int32_t>(prefix);
      FUN_0043ec50(outPair, firstC, firstIdx, lastC, lastIdx, dest,
                   static_cast<uint32_t>(hole));
    }
    return;
  }

  // Back-biased: make room with push_back.
  if (suffix < n) {
    uint32_t u = firstIdx + suffix;
    for (; firstC != lastC || u != lastIdx; ++u) {
      GuardedVector_PushBack_Thiscall(dest, MapSlot(firstC, u));
    }
    for (uint32_t i = 0; i < suffix; ++i) {
      const uint32_t abs =
          static_cast<uint32_t>(dest->begin) + prefix + i;
      GuardedVector_PushBack_Thiscall(dest, MapSlot(dest, abs));
    }
    FUN_0043ec50(outPair, firstC, firstIdx, firstC, firstIdx + suffix, dest,
                 static_cast<uint32_t>(dest->begin) + prefix);
    return;
  }

  for (uint32_t i = 0; i < n; ++i) {
    const uint32_t abs = static_cast<uint32_t>(dest->begin) +
                         (i - n) + suffix + prefix;
    GuardedVector_PushBack_Thiscall(dest, MapSlot(dest, abs));
  }
  {
    const int32_t hole =
        dest->begin + static_cast<int32_t>(prefix);
    int scratchPair[2];
    FUN_0043ebb0(scratchPair, dest, static_cast<uint32_t>(hole), dest,
                 static_cast<uint32_t>(hole + static_cast<int32_t>(suffix) - static_cast<int32_t>(n)),
                 dest,
                 static_cast<uint32_t>(hole + static_cast<int32_t>(suffix)));
    FUN_0043ec50(outPair, firstC, firstIdx, lastC, lastIdx, dest,
                 static_cast<uint32_t>(hole));
  }
}
