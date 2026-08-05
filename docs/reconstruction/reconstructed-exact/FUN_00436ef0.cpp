// =============================================================================
// FUN_00436ef0  (Ghidra symbol twin of Mem_FillDwordN_FromSrc_EaxEcxEdx)
// -----------------------------------------------------------------------------
// Stable ID: aa_00436ef0
// Address:   0x00436ef0–0x00436f06  (autoassault.exe, image base 0x400000)
// Body:      23 B; bare RET
// System:    stl-helpers / POD fill
// Generated: 2026-07-23 scaffold; refined W34-D dual seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// Preferred name: Mem_FillDwordN_FromSrc_EaxEcxEdx
// Reject: Named_CalleeOf_Named_assManager_00436ef0
// =============================================================================

#include <cstdint>

// Retail register ABI: EAX=dest, ECX=count, EDX=src*; bare RET; leaf
// Portable semantic equivalent of the 23 B body:
extern "C" void FUN_00436ef0(int count /*ECX*/, uint32_t* src /*EDX*/,
                             uint32_t* dest /*EAX in*/)
{
  for (; count != 0; count = count - 1) {
    if (dest != nullptr) {
      *dest = *src;
    }
    dest = dest + 1;
  }
}
