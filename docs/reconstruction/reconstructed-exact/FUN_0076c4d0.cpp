// =============================================================================
// FUN_0076c4d0  — twin of RdtscTimer_StampAndArm_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c4d0
// Address:   0x0076c4d0  (autoassault.exe, image base 0x400000)
// Body:      0x0076c4d0 – 0x0076c4f1 exclusive (33 B / 0x21)
// Wave:      WQ9L-D OWN-ONLY dual 2026-08-05
// See:       RdtscTimer_StampAndArm_Inferred.cpp for full plate + semantics.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall RdtscTimer_StampAndArm_Inferred(void *timer);

extern "C" void __fastcall FUN_0076c4d0(void *timer)
{
  // ECX = timer*; RDTSC → +0x08/+0x0C; byte +0x18 = 1; bare RET
  RdtscTimer_StampAndArm_Inferred(timer);
}

// Exact control-flow twin (inline shape for diff against decompile):
// void __fastcall FUN_0076c4d0(int param_1) {
//   undefined8 uVar1 = rdtsc();
//   *(int*)(param_1 + 8) = (int)uVar1;
//   *(int*)(param_1 + 0xc) = (int)((ulonglong)uVar1 >> 0x20);
//   *(undefined1*)(param_1 + 0x18) = 1;
// }
