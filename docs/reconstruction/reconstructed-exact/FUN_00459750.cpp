// =============================================================================
// FUN_00459750 — twin of AnmTrackMaster_Unserialize_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00459750
// Address:   0x00459750–0x00459a5a  (autoassault.exe, image base 0x400000)
// Body:      779 B / 0x30B; RET 4
// System:    palantir/animation — anmTrackMaster_inl chunk unserialize
// Generated: scaffold 2026-07-23; dual A/B seal 2026-07-29 (W36-M)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed sites.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// Canonical name: AnmTrackMaster_Unserialize_Inferred
// See: AnmTrackMaster_Unserialize_Inferred.cpp
//
// ABI: ECX=this, stack ctx*; RET 4; returns 0 / -2 / -1
//

#include <cstdint>

// Host fourCC constants (LE file bytes = reverse ASCII of name)
static constexpr uint32_t kTag_PBAM = 0x5042414Du; // file "MABP"
static constexpr uint32_t kTag_TRAK = 0x5452414Bu; // file "KART"
static constexpr uint32_t kType_EFCT = 0x45464354u;
static constexpr uint32_t kType_SKEL = 0x534B454Cu;
static constexpr uint32_t kTypeSelectImm = 0x4B455556u;
static constexpr uint32_t kTypeSelectMask = 0x0E0501F8u;

struct Pod28 {
  uint32_t w[7];
};

// External callees (unowned / prior duals) — names from Ghidra.
extern "C" void stoChunkReader_EnterChunkScope();
extern "C" void vog_LogMessage();
extern "C" void FUN_0045c4b0(); // StdVector_Resize_Pod28 — EBX=vec, ECX=n, stack value; RET 1C
extern "C" int  FUN_0045dd60();
extern "C" void FUN_00769e40();
// … dual I/O / string / hash helpers: FUN_00436f10, FUN_00437050, FUN_0076a200,
//   FUN_007689e0, FUN_00768760, FUN_007684e0, FUN_00468aa0, FUN_0044c370,
//   FUN_0044c340, FUN_00989e00, basic_string ctor/dtor …

// Decompiler-faithful control-flow sketch (not a drop-in compile unit for the
// full 779 B frame; sealed contracts documented in dual A/B + raw append).
extern "C" uint32_t __thiscall FUN_00459750(int* self, int* ctx)
{
  // SEH + EnterChunkScope populates local tag/version/owns_scope.
  // if (tag != PBAM && tag != TRAK) { vog_LogMessage(anmTrackMaster_inl.h); → -1 }
  // dual I/O via ctx[0x4044/4]; version gates; optional subchunks
  // self[4] = (read == kTypeSelectImm) ? kType_EFCT : kType_SKEL;
  //   retail: SUB/NEG/SBB/AND kTypeSelectMask / ADD kType_EFCT
  // hashes → self[5], self[6]; ints; count
  // EBX = self + 0x1C/4; ECX = count; stack Pod28 value; FUN_0045c4b0()
  // if (count > 0) { if (FUN_0045dd60()==0) return 0; }
  // cleanup; return 0 / 0xFFFFFFFE / 0xFFFFFFFF
  (void)self;
  (void)ctx;
  (void)kTag_PBAM;
  (void)kTag_TRAK;
  (void)kType_EFCT;
  (void)kType_SKEL;
  (void)kTypeSelectImm;
  (void)kTypeSelectMask;
  return 0xFFFFFFFFu;
}
