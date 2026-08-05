// =============================================================================
// RefCountedPtr_DefaultCtor_Inferred  (FUN_0096ef70)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ef70
// Address:   0x0096ef70–0x0096ef78  (autoassault.exe, image base 0x400000)
// Body size: 9 bytes
// System:    shared util — refcounted handle default construction
// Generated: 2026-07-23 scaffold as FUN_0096ef70; dual A/B seal 2026-07-29 (W25-N)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Null-initialize a 4-byte refcounted handle: *this = 0.
//   Peer dtor FUN_0096efd0 (not dual-owned here) releases payload via
//   refcount at payload+8 and release vfunc at *(payload+4)+8.
//
// ABI (retail)
//   ECX = handle*  (__fastcall / thiscall single-ptr)
//   no stack formals; ret (not ret N)
//   return: this* in EAX (decomp void understates)
//
// BYTES
//   8B C1                 mov eax, ecx
//   C7 00 00 00 00 00     mov dword ptr [eax], 0
//   C3                    ret
//
// CALLERS (~62): CVOGTacArc_ctor (×2), paint, graphics loaders, asset/UI paths
//

#include <cstdint>

void* RefCountedPtr_DefaultCtor_Inferred(void** self /*ECX*/)
{
  *self = nullptr;
  return self;
}

// Legacy Ghidra name — see FUN_0096ef70.cpp
// void FUN_0096ef70(undefined4* param_1); // understates return this
