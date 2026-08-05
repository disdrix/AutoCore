// =============================================================================
// SideHost_PushKeyFlag1_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00970b60
// Address:   0x00970b60–0x00970b95  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00970b60
// System:    Side-host optional path (NDResource cache+0x6c host)
// Dual:      W33-N 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: thiscall ECX = keyHolder*; stack host*; RET 0x4.
// Builds PodU32U8{key=*ecx, flag=1} then locked push to host+0xAC.
// Bit-twin of SideHost_PushKeyFlag0_Inferred (00970b20) with imm flag 1.
// Sole caller: NDResourceCache_LookupOrCreate after alt-provider miss.
// =============================================================================

#include <cstdint>

struct PodU32U8 {
  uint32_t key;
  uint8_t  flag;
};

struct GuardedVectorHeader; // layout sealed W31-J / W32-N

// Unowned: W32-N — EDI=container, stack value*, RET 4
extern "C" void GuardedVector_PushBackLocked_Stride2_U32U8(
    const PodU32U8* value /*stack*/,
    GuardedVectorHeader* container /*EDI*/);

// Retail: ECX=keyHolder; stack host*; RET 4
extern "C" void SideHost_PushKeyFlag1_Inferred(
    void* keyHolder /*ECX*/,
    void* host /*stack*/)
{
  PodU32U8 pod;
  pod.key  = *reinterpret_cast<const uint32_t*>(keyHolder);
  pod.flag = 1;

  // Retail: MOV EDI, host; ADD EDI, 0xAC; PUSH &pod; CALL 0x0043e7f0
  auto* vec = reinterpret_cast<GuardedVectorHeader*>(
      reinterpret_cast<uint8_t*>(host) + 0xAC);
  GuardedVector_PushBackLocked_Stride2_U32U8(&pod, vec);
}
