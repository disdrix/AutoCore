// =============================================================================
// RdtscTimer_StampAndArm_Inferred  (FUN_0076c4d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076c4d0
// Address:   0x0076c4d0  (autoassault.exe, image base 0x400000)
// Body:      0x0076c4d0 – 0x0076c4f1 exclusive (33 B / 0x21)
// System:    timer subobject stamp (HostBase +0x10; UI/vehicle nested)
// Generated: 2026-08-05 WQ9L-D dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
//            Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Leaf helper: read CPU timestamp counter (RDTSC), write the 64-bit value
//   into a timer subobject at +0x08 (low) / +0x0C (high), and set the armed
//   flag at +0x18 = 1. Used after FUN_0076c500 period init (HostBase ctor) and
//   from CWndVehicle nested teardown paths that pass nested+0x10.
//
// ABI:
//   ECX = timer subobject*. No stack formals. Bare RET (C3). void.
//
// CALLEES:
//   (none — RDTSC intrinsic only)
//
// CALLERS (sample of ~90 xrefs):
//   FUN_0076c500, HostBase_DefaultCtor (0x007560d0),
//   CWndVehicle_CompleteDtor (0x00834520),
//   CWndVehicle_DerivedTeardown_EDI (0x00833d50), many UI/drive sites
//
// PEERS:
//   Init: FUN_0076c500 (period setup then calls this)
//   Thunk: thunk_FUN_0076c4d0 @ 0x0076c5c0
//
// ODD BEHAVIOR (preserve):
//   Spills RDTSC through stack (SUB ESP,8) even though EAX/EDX already hold
//   the value — exact retail sequence.
// =============================================================================

#include <cstdint>

// Machine: ECX = timer*. Intrinsic RDTSC (EAX:EDX).
extern "C" void __fastcall RdtscTimer_StampAndArm_Inferred(void *timer)
{
  // SUB ESP, 8; RDTSC; MOV [ESP],EAX; MOV [ESP+4],EDX;
  // MOV EAX,[ESP]; MOV EDX,[ESP+4]
  uint32_t lo, hi;
#if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
  // Portable stand-in for the sealed RDTSC; ports may use __rdtsc.
  unsigned __int64 t = __rdtsc();
  lo = static_cast<uint32_t>(t);
  hi = static_cast<uint32_t>(t >> 32);
#else
  // Non-MSVC: leave as opaque; reconstruction documents the retail ops.
  lo = 0;
  hi = 0;
  (void)lo;
  (void)hi;
  // Retail always executes RDTSC; this branch is documentation-only.
#endif

  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(timer) + 0x08) = lo;
  *reinterpret_cast<uint32_t *>(reinterpret_cast<char *>(timer) + 0x0C) = hi;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(timer) + 0x18) = 1;
  // ADD ESP, 8; RET
}

// Ghidra twin name
extern "C" void __fastcall FUN_0076c4d0(void *timer)
{
  RdtscTimer_StampAndArm_Inferred(timer);
}
