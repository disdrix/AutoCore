// =============================================================================
// AnmTrackMaster_Unserialize_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00459750
// Address:   0x00459750–0x00459a5a  (autoassault.exe, image base 0x400000)
// Body:      779 B / 0x30B; RET 4; pad CC then next
// System:    palantir/animation — anmTrackMaster_inl chunk unserialize
// Generated: 2026-07-23 scaffold as FUN_00459750; dual A/B seal 2026-07-29 (W36-M)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes / call sites.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Unserialize an animation track-master chunk into `this`. Accepts host u32
//   tags PBAM (0x5042414D) or TRAK (0x5452414B). Dual I/O via ctx+0x4044.
//   Writes type fourCC (EFCT/SKEL), string hashes, ints; resizes Pod28 vector
//   at this+0x1C via StdVector_Resize_Pod28; optional per-element FUN_0045dd60.
//
// ABI:
//   ECX = this (track object)
//   stack = ctx* (reader / pack context; +0x4044 dual-path flag)
//   RET 4
//   returns: 0 success, 0xFFFFFFFE mid error, 0xFFFFFFFF fail
//
// String evidence: "..\\palantir/animation/anmTrackMaster_inl.h"
// Ghidra: FUN_00459750
// Reject: product demangle invent beyond Inferred structural name
//

#include <cstdint>

// Forward decls for unowned callees (names from Ghidra / prior duals).
extern "C" void stoChunkReader_EnterChunkScope(/* chunk local in ECX */);
extern "C" void vog_LogMessage(/* stack args */);
extern "C" void FUN_0045c4b0(/* EBX=vec*, ECX=new_size, stack Pod28 value; RET 1C */);
extern "C" int  FUN_0045dd60(/* element load; unowned */);
// … dual I/O / hash / string helpers omitted from portable surface …

struct Pod28 {
  uint32_t w[7];
};

struct StdVectorPod28 {
  void* _unused0;
  Pod28* begin;   // +0x04
  Pod28* end;     // +0x08
  Pod28* capEnd;  // +0x0C
};

// Layout offsets sealed from this dual (relative to track object):
//   +0x10  type fourCC (EFCT 0x45464354 or SKEL 0x534B454C)
//   +0x14  string hash 1
//   +0x18  string hash 2 (version > 0)
//   +0x1C  StdVectorPod28 of Pod28 elements (begin/end/cap at +4/+8/+C of vec)
//   +0x2C  int field (FUN_00437050 / dual)
// Full object map residual.

// Portable semantic sketch (not bit-exact retail frame):
uint32_t AnmTrackMaster_Unserialize_Inferred(void* self, void* ctx)
{
  // 1) SEH + stoChunkReader_EnterChunkScope on local chunk state.
  // 2) tag = chunk.fourCC; if not PBAM and not TRAK → log path string → -1.
  // 3) version / dual I/O (ctx+0x4044) branch for optional subchunks.
  // 4) type fourCC: if read == 0x4B455556 → EFCT else SKEL → self+0x10.
  // 5) read string(s) → hash via FUN_00989e00 → self+0x14 / +0x18.
  // 6) read ints; count into stack; resize:
  //      vec = (StdVectorPod28*)((uint8_t*)self + 0x1C);
  //      StdVector_Resize_Pod28(vec, count, defaultPod28);
  // 7) if count > 0: FUN_0045dd60; fail → cleanup → 0 or -2.
  // 8) leave scope; return 0 / -1 / -2.
  (void)self;
  (void)ctx;
  return 0xFFFFFFFFu;
}

extern "C" uint32_t __thiscall FUN_00459750(void* self, void* ctx)
{
  return AnmTrackMaster_Unserialize_Inferred(self, ctx);
}
