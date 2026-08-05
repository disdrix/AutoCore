// =============================================================================
// StdUninitCopy_Pod28
// -----------------------------------------------------------------------------
// Stable ID: aa_0045f360
// Address:   0x0045f360–0x0045f3AC exclusive (76 B / 0x4C, autoassault.exe base 0x400000)
// System:    MSVC-style trivial uninitialized_copy for POD elem size 0x1c
// Generated: 2026-07-29 W35-K dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + register ABI. Bytes win over decompiler void.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0045f360
// =============================================================================
//
// PURPOSE:
//   Copy [src_begin, src_end) into dst for trivially copyable 0x1c elements
//   (7 dwords). Used by StdVector_InsertN_Pod28 (W34-P) on grow / in-place arms.
//   Null dst skips stores but still advances (cursor math).
//
// ABI (bytes):
//   EAX = dst begin (in) / dst end (out)
//   ECX = src begin
//   EDI = src end (live-in; caller-owned)
//   bare RET (C3); preserves ESI, EBX
// =============================================================================

#include <cstdint>

struct Pod28 {
  uint32_t w[7]; // 0x1c — float-or-dword lanes; POD either way
};

// Retail register ABI (not a standard __fastcall of one pointer):
//   in:  EAX=dst, ECX=src_begin, EDI=src_end
//   out: EAX=dst_end
extern "C" Pod28* StdUninitCopy_Pod28(Pod28* dst, const Pod28* src_begin, const Pod28* src_end)
{
  if (src_begin == src_end) {
    return dst;
  }

  do {
    if (dst != nullptr) {
      dst->w[0] = src_begin->w[0];
      dst->w[1] = src_begin->w[1];
      dst->w[2] = src_begin->w[2];
      dst->w[3] = src_begin->w[3];
      dst->w[4] = src_begin->w[4];
      dst->w[5] = src_begin->w[5];
      dst->w[6] = src_begin->w[6];
    }
    ++src_begin;
    ++dst;
  } while (src_begin != src_end);

  return dst;
}

// Ghidra-name alias (same body; register formals are the retail contract)
extern "C" Pod28* FUN_0045f360(Pod28* dst, const Pod28* src_begin, const Pod28* src_end)
{
  return StdUninitCopy_Pod28(dst, src_begin, src_end);
}
