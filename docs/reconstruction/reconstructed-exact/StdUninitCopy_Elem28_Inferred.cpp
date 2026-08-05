// =============================================================================
// StdUninitCopy_Elem28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a350
// Address:   0x0046a350–0x0046a372 exclusive (34 B / 0x22, autoassault.exe base 0x400000)
// System:    MSVC-style trivial uninitialized_copy for POD elem size 0x1c
// Generated: 2026-07-29 W36-P dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + register ABI. Bytes win over decompiler.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0046a350
// =============================================================================
//
// PURPOSE:
//   Copy [src_begin, src_end) into dst for trivially copyable 0x1c elements
//   (7 dwords via REP MOVSD). Used by StdVector_InsertN_Elem28_ValueEdx_Inferred
//   (W34-Q) on grow / in-place arms. Null dst skips stores but still advances.
//
// ABI (bytes):
//   EAX = dst begin (in) / dst end (out)
//   EDX = src begin
//   EBX = src end
//   bare RET (C3); preserves ESI, EDI across body (pushed/popped)
// =============================================================================

#include <cstdint>

struct Elem28 {
  uint32_t w[7]; // 0x1c — float-or-dword lanes; POD either way
};

// Retail register ABI (not a standard __fastcall of one pointer):
//   in:  EAX=dst, EDX=src_begin, EBX=src_end
//   out: EAX=dst_end
extern "C" Elem28* StdUninitCopy_Elem28_Inferred(
    Elem28* dst,
    const Elem28* src_begin,
    const Elem28* src_end)
{
  if (src_begin == src_end) {
    return dst;
  }

  do {
    if (dst != nullptr) {
      // retail: MOV ECX,7; MOV ESI,EDX; MOV EDI,EAX; REP MOVSD
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
extern "C" Elem28* FUN_0046a350(
    Elem28* dst,
    const Elem28* src_begin,
    const Elem28* src_end)
{
  return StdUninitCopy_Elem28_Inferred(dst, src_begin, src_end);
}
