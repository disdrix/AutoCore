// =============================================================================
// FUN_0046a240 — twin of StdCopyBackward_Elem28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a240
// Address:   0x0046a240–0x0046a25d  (autoassault.exe, image base 0x400000)
// Body:      30 B / 0x1E; bare RET
// System:    stl-helpers / POD copy_backward (elem 0x1c)
// Generated: scaffold 2026-07-23; dual A/B seal 2026-07-29 (W35-L)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Canonical name: StdCopyBackward_Elem28_Inferred
// See: StdCopyBackward_Elem28_Inferred.cpp
//
// ABI: EAX=dest_end*, EDX=src_end*, EBX=src_begin*; bare RET; leaf
//

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

extern "C" void FUN_0046a240(Elem28* dest_end /*EAX*/, Elem28* src_end /*EDX*/,
                             const Elem28* src_begin /*EBX*/)
{
  while (src_begin != src_end) {
    src_end = src_end - 1;
    dest_end = dest_end - 1;
    dest_end->w[0] = src_end->w[0];
    dest_end->w[1] = src_end->w[1];
    dest_end->w[2] = src_end->w[2];
    dest_end->w[3] = src_end->w[3];
    dest_end->w[4] = src_end->w[4];
    dest_end->w[5] = src_end->w[5];
    dest_end->w[6] = src_end->w[6];
  }
}
