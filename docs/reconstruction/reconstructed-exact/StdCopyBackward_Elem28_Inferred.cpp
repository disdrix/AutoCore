// =============================================================================
// StdCopyBackward_Elem28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a240
// Address:   0x0046a240–0x0046a25d  (autoassault.exe, image base 0x400000)
// Body:      30 B / 0x1E; bare RET; pad CC then FUN_0046a260 @ 0x0046a260
// System:    stl-helpers / POD copy_backward (elem 0x1c)
// Generated: 2026-07-23 scaffold as FUN_0046a240; dual A/B seal 2026-07-29 (W35-L)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   MSVC-style std::copy_backward for POD elements of size 0x1c (7 dwords).
//   Walks exclusive ends backward one element at a time and copies with
//   REP MOVSD. Required for overlapping mid-insert shifts in vector insert-n.
//
// ABI (register — not thiscall/stdcall):
//   EAX = dest_end* (exclusive; walks backward)
//   EDX = src_end*  (exclusive; walks backward)
//   EBX = src_begin* (stop condition)
//   ECX clobbered (REP count)
//   bare ret (no stack formals)
//
// Parents: FUN_0045cd30, FUN_00466ea0, FUN_00469f50 (elem-28 insert-n mid arms).
// Sibling: FUN_0046a260 (uninit fill-n next symbol).
//
// Ghidra: FUN_0046a240
// Reject: Named_CalleeOf_*anmTrackMast_0046a240
//

#include <cstdint>

struct Elem28 {
  uint32_t w[7];
};

// Register ABI cannot be expressed portably; document contract in comment.
// Portable semantic equivalent:
void StdCopyBackward_Elem28_Inferred(Elem28* dest_end, Elem28* src_end,
                                     const Elem28* src_begin)
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

// Scaffold / Ghidra alias
extern "C" void FUN_0046a240(Elem28* dest_end /*EAX*/, Elem28* src_end /*EDX*/,
                             const Elem28* src_begin /*EBX*/)
{
  StdCopyBackward_Elem28_Inferred(dest_end, src_end, src_begin);
}
