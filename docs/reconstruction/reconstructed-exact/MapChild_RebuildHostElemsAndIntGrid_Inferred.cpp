// =============================================================================
// MapChild_RebuildHostElemsAndIntGrid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004ac100
// Address:   0x004ac100–0x004ac215 exclusive (277 B / 0x115, autoassault.exe base 0x400000)
// System:    map-child rebuild of host 0x28-elem array + int tile grid
// Generated: 2026-07-29 W31-L dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving rewrite; bytes supersede decompiler on ABI/calls.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004ac100
// =============================================================================
//
// PURPOSE:
//   Orchestrate spatial-table rebuild for the map-child object (0x3fc-sized,
//   allocated via FUN_004ad730 in FUN_004d9cd0; linked at map+0xe4f8):
//     1) Guard required field @ +0x3d8; else VOG_DEBUG_STOP + return 0.
//     2) Rebuild host cookie-vector of 0x28-elems via FUN_004941b0
//        (host = *(mapCtx+0xe898), mapCtx = *(this+0x340)).
//     3) dimX/dimY = signed /16 of extents @ +0x10 / +0x14 → +0x384 / +0x388.
//     4) delete[] / new[] / zero int grid @ +0x38c (dimX*dimY dwords).
//     5) FUN_004abd00(this); FUN_004aa300(this); FUN_004930b0(*(mapCtx+0xe894)).
//     6) DAT_00b03631 ? FUN_005c0f40(this) : FUN_005bf720(); sync DAT_00b03632; return 1.
//
// ABI:
//   __thiscall; ECX=mapChild; unused stack formal cleaned with RET 4; returns AL 0/1.
//
// NOTE:
//   Reject Named_VOG_DEBUG_STOP_004ac100 — string is fail-guard only.
//   Decompile omits host load into ECX for FUN_004941b0 and thiscall for callees.
// =============================================================================

#include <cstdint>

extern "C" void FUN_007a4480(int a, const char* msg);
extern "C" void __thiscall FUN_004941b0(void* host, void* mapCtx);
extern "C" void operator_delete[](void* p);
extern "C" void* operator_new[](unsigned size);
extern "C" void __thiscall FUN_004abd00(void* self);
extern "C" void __thiscall FUN_004aa300(void* self);
extern "C" void __thiscall FUN_004930b0(void* arg);
extern "C" void __thiscall FUN_005c0f40(void* self);
extern "C" void FUN_005bf720(void);

extern "C" unsigned char DAT_00b03631;
extern "C" unsigned char DAT_00b03632;

static inline int signed_div16(int x)
{
  return (x + ((x >> 31) & 0xf)) >> 4;
}

// Machine: uint8_t __thiscall FUN_004ac100(void* self /*, unused stack */)
extern "C" uint8_t __thiscall MapChild_RebuildHostElemsAndIntGrid_Inferred(
    void* self,
    int /* unused_stack_arg */)
{
  auto* s = reinterpret_cast<uint8_t*>(self);

  if (*reinterpret_cast<int*>(s + 0x3d8) == 0) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    return 0;
  }

  void* mapCtx = *reinterpret_cast<void**>(s + 0x340);
  void* host = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(mapCtx) + 0xe898);
  FUN_004941b0(host, mapCtx);

  const int dimX = signed_div16(*reinterpret_cast<int*>(s + 0x10));
  const int dimY = signed_div16(*reinterpret_cast<int*>(s + 0x14));
  *reinterpret_cast<int*>(s + 0x384) = dimX;
  *reinterpret_cast<int*>(s + 0x388) = dimY;

  void* oldGrid = *reinterpret_cast<void**>(s + 0x38c);
  if (oldGrid != nullptr) {
    operator_delete[](oldGrid);
  }
  *reinterpret_cast<void**>(s + 0x38c) = nullptr;

  const unsigned byteCount = static_cast<unsigned>(dimX) * static_cast<unsigned>(dimY) * 4u;
  auto* grid = reinterpret_cast<uint32_t*>(operator_new[](byteCount));
  *reinterpret_cast<uint32_t**>(s + 0x38c) = grid;

  // Machine zero: rep stosd (dwords) + rep stosb (byte remainder)
  const unsigned dwords = byteCount >> 2;
  const unsigned rem = byteCount & 3u;
  for (unsigned i = 0; i < dwords; ++i) {
    grid[i] = 0;
  }
  auto* tail = reinterpret_cast<uint8_t*>(grid + dwords);
  for (unsigned i = 0; i < rem; ++i) {
    tail[i] = 0;
  }

  FUN_004abd00(self);
  FUN_004aa300(self);
  FUN_004930b0(*reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(mapCtx) + 0xe894));

  if (DAT_00b03631 != 0) {
    FUN_005c0f40(self);
  } else {
    FUN_005bf720();
  }
  DAT_00b03632 = DAT_00b03631;
  return 1;
}
