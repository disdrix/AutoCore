// =============================================================================
// CLoadNode_WaitAssPreloadKeyRing_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6ad0
// Address:   0x005c6ad0–0x005c6b3e  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_005c6ad0
// System:    CLoadNode stage cooperative wait + AssPreloader key ring
// Dual:      W36-F 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: __thiscall; ECX = CLoadNode/wait host; stack GuardedVector* ring;
//             RET 0x4; EAX = 0 ready / 3 wait-yield.
// Host +0x54 = coop counter (budget band 1..6); +0x5c = key-ring cursor.
// Name structural Inferred from CLoadNode::_init* parents + sealed AssPreloader.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  int32_t  capacity; // +0x08
  int32_t  begin;    // +0x0c
  int32_t  size;     // +0x10
};

struct CLoadNodeWaitHost {
  uint8_t  _pad00[0x54];
  int32_t  coop_counter; // +0x54
  uint8_t  _pad58[4];
  uint32_t ring_cursor;  // +0x5c
};

extern "C" uint8_t* DAT_00d1f050;

extern "C" uint32_t AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(
    void* preloader /*ECX*/, GuardedVectorHeader* source);
extern "C" uint8_t AssPreloader_ProcessKeyRingStep_Inferred(
    GuardedVectorHeader* ring, char* progress_flag, uint32_t* cursor);

uint32_t __thiscall CLoadNode_WaitAssPreloadKeyRing_Inferred(
    CLoadNodeWaitHost* host,
    GuardedVectorHeader* ring)
{
  if (ring->size == 0) {
    host->coop_counter = 0;
    return 0;
  }

  int32_t c = host->coop_counter;
  if (c < 1 || c > 6) {
    if (c > 6) {
      host->coop_counter = 0;
    }
    void* preloader = *reinterpret_cast<void**>(DAT_00d1f050 + 0x6c);
    if (preloader != nullptr) {
      AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(preloader, ring);
    }
  }

  char progress_flag = 1;
  uint8_t done = AssPreloader_ProcessKeyRingStep_Inferred(
      ring, &progress_flag, &host->ring_cursor);

  if (done == 0) {
    host->coop_counter = host->coop_counter + 1;
    return 3; // stage wait
  }

  host->coop_counter = 0;
  return 0; // ready
}
