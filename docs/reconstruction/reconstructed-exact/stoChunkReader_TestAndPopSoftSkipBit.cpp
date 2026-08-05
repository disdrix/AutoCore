// =============================================================================
// stoChunkReader_TestAndPopSoftSkipBit
// -----------------------------------------------------------------------------
// Stable ID: aa_00767570
// Address:   0x00767570–0x007675BD  (autoassault.exe, image base 0x400000)
// System:    storage / arda2 stoChunk
// Generated: 2026-07-23 scaffold as FUN_00767570;
//            dual A/B seal 2026-08-04 (W38-I)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Peer of stoChunkReader_SoftSkipIfBitSet @ 0x00767120 (test-only, ECX).
 * - This unit: test bit (size-1), then shrink bitset size to size-1 (pop).
 * - Retail ABI: EDI = view (size@+0, bitset_base@+8); plain RET; AL = prior bit.
 * - Sole callee: FUN_004362c0 (bitset resize; EAX=newSize, stack fill arg).
 * - Single caller: FUN_00765740 (gfxBody unserialize) @ 0x00765C96; return ignored.
 * - Name is Inferred (soft-skip family); product English open.
 */

#include <cstdint>

// Soft-skip bitset view embedded at stoChunkReader (layout matches SoftSkipIfBitSet).
struct StoSoftSkipView {
  uint32_t size;       // +0  bit count / id
  uint32_t unused_4;   // +4
  uint32_t bitset;     // +8  base pointer (or absolute base for word array)
};

// External (not owned): resize bitset size to newSize (EAX), fill/arg on stack.
// Retail thiscall: ECX=this, EAX=newSize, stack param fill.
extern "C" void __thiscall FUN_004362c0(StoSoftSkipView* self, uint32_t fillArg);

// Clean explicit signature. Retail: EDI=view, plain RET, AL=bool.
bool stoChunkReader_TestAndPopSoftSkipBit(StoSoftSkipView* view /*EDI*/)
{
  uint32_t size = view->size;
  if (size == 0) {
    return false;
  }

  uint32_t base = view->bitset;
  uint32_t low = 0;
  if (size != 0) {
    base += (size >> 5) * 4u;
    low = size & 0x1fu;
  }

  uint32_t idx = low - 1u;
  uint32_t word =
      *reinterpret_cast<uint32_t*>(base + ((idx >> 5) * 4u));
  uint32_t mask = 1u << (idx & 0x1fu);
  bool wasSet = (word & mask) != 0u;

  // Retail: PUSH 0; LEA EAX,[size-1]; MOV ECX,EDI; CALL FUN_004362c0
  FUN_004362c0(view, /*fillArg*/ 0); // newSize passed in EAX = size-1

  return wasSet;
}

// Note: the clean plate documents EAX=size-1; a faithful register-level call
// would set EAX before the call. AutoCore ports should call a typed
// ResizeSoftSkipBitset(view, size - 1) helper when FUN_004362c0 is sealed.
