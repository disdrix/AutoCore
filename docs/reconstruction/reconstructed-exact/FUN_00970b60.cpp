// =============================================================================
// FUN_00970b60 / SideHost_PushKeyFlag1_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00970b60
// Address:   0x00970b60–0x00970b95  (autoassault.exe, image base 0x400000)
// System:    Side-host optional path
// Dual:      W33-N 2026-07-29
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Clean twin of SideHost_PushKeyFlag1_Inferred.cpp (Ghidra name).

#include <cstdint>

struct PodU32U8 {
  uint32_t key;
  uint8_t  flag;
};

struct GuardedVectorHeader;

extern "C" void GuardedVector_PushBackLocked_Stride2_U32U8(
    const PodU32U8* value,
    GuardedVectorHeader* container);

// Retail: ECX=keyHolder; stack host*; RET 4. Decompiler void surface is incomplete.
extern "C" void FUN_00970b60(void* keyHolder /*ECX*/, void* host /*stack*/)
{
  PodU32U8 pod;
  pod.key  = *reinterpret_cast<const uint32_t*>(keyHolder);
  pod.flag = 1;
  auto* vec = reinterpret_cast<GuardedVectorHeader*>(
      reinterpret_cast<uint8_t*>(host) + 0xAC);
  GuardedVector_PushBackLocked_Stride2_U32U8(&pod, vec);
}
