// =============================================================================
// BitStream_GrowForBits
// -----------------------------------------------------------------------------
// Purpose:  Grow BitStream write buffer so it can accept `extraBits` more bits
//           beyond current bit capacity (+0x30). Computes a new byte size with
//           +0x5DC (1500) slack, reallocates when the stream owns its buffer,
//           and updates bit capacities to NewSize*8. Returns 1 on realloc
//           success, 0 on failure (sets error flag +0x1c).
//
// Address:  0x0042b450  (autoassault.exe, image base 0x400000)
// Stable:   aa_0042b450
// System:   network-bitstream
// Generated: 2026-07-29 W22-D dual A/B seal
// Exactness: CF ≡ bytes (read_memory). Decompiler missing shift parens fixed in
//            comments; AL bool returns used instead of CONCAT31 / mask artifacts.
// Bit-for-bit / runtime / diff: DEFERRED.
// Dual reviews:
//   reviews/A_aa_0042b450_BitStream_GrowForBits.md
//   reviews/B_aa_0042b450_BitStream_GrowForBits.md
// =============================================================================
//
// Signature (behavior):
//   bool GrowForBits(BitStream* this /*EDI*/, int extraBits /*ECX*/);
//   // decompiler surface: uint __fastcall FUN_0042b450(int param_1)
//   // with unaff_EDI = this
//
// Key offsets (BitStream this):
//   +0x0c  void* buffer
//   +0x10  size in bytes (allocated/tracked)
//   +0x14  char ownsBuffer (must be non-zero to realloc)
//   +0x1c  char errorFlag (set 1 on fail)
//   +0x2c  bit capacity mirror
//   +0x30  bit capacity (write limit)
//
// Formula (byte-sealed):
//   NewSize = ((extraBits + bitCap + 7) >> 3) + 0x5DC
//
// Callees: realloc (IAT 0x009C650C)
// Callers: BitStream_writeBits, BitStream_writeFlag, writeString family, etc.
// =============================================================================

#include <cstdint>
#include <cstdlib>

// Minimal layout for documentation; not a full TNL BitStream.
struct BitStream_GrowView {
  // ...
  // +0x0c:
  void* buffer;
  // +0x10:
  uint32_t byteSize;
  // +0x14:
  char ownsBuffer;
  // ...
  // +0x1c:
  char errorFlag;
  // ...
  // +0x2c:
  int bitCapMirror;
  // +0x30:
  int bitCap;
};

// ABI: EDI=this, ECX=extraBits, AL=success. Not a real MSVC thiscall (ECX=this).
extern "C" uint8_t BitStream_GrowForBits(int extraBits /*ECX*/, BitStream_GrowView* self /*EDI*/)
{
  // Bytes: lea esi, [ecx+eax+7]; shr esi, 3; add esi, 0x5DC
  // (NOT C precedence of the decompiler's unparenthesized ">> 3")
  uint32_t newSize =
      (static_cast<uint32_t>(extraBits + self->bitCap + 7) >> 3) + 0x5DCu;

  if (self->byteSize < newSize) {
    if (self->ownsBuffer != 0) {
      self->byteSize = newSize;
      // Image: push newSize; push buffer; call [IAT realloc]; no NULL check
      self->buffer = std::realloc(self->buffer, newSize);
      int bits = static_cast<int>(newSize * 8u);
      self->bitCapMirror = bits;
      self->bitCap = bits;
      return 1;
    }
    // !owns → fail (stamp byteSize below)
    self->byteSize = newSize;
  } else {
    // byteSize already >= newSize → still fail (defensive edge)
    self->byteSize = newSize;
  }

  self->errorFlag = 1;
  return 0;
}

// Ghidra symbol twin lives in FUN_0042b450.cpp (scaffold surface).
