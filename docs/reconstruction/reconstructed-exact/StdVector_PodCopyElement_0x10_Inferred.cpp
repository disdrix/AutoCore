// =============================================================================
// StdVector_PodCopyElement_0x10_Inferred  (FUN_00409f70)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409f70
// Address:   0x00409f70–0x00409f8a inclusive (27 B / 0x1B)
// System:    MSVC-style POD element copy for vector elem stride 0x10
// Dual A/B:  2026-08-05 R10-023
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Null-safe POD copy of one 16-byte (4-dword) element. Leaf used by
//   ConstructN (0x00409e20) and range uninit_copy (0x0040a670) for the
//   Elem0x10 vector family (parent dual MEGA-044 / partition interaction-activation).
//
// ABI
//   Register: EAX = dest T*, ECX = src const T*; no stack args; plain RET.
//   Do NOT merge with PodCopy 0x28 (00409f30) which uses EAX/EDX and 10 dwords.
//   Same ABI family as Elem12 PodCopy (00409f50): EAX dest / ECX src.
//
// Callers
//   FUN_00409e20 StdVector_ConstructN_Elem0x10_Inferred @ 0x00409e58
//   FUN_0040a670 (uninit_copy / copy-range step +0x10) @ 0x0040a6a8
// =============================================================================

#include <cstdint>
#include <cstring>

// Machine: TEST EAX,EAX; JZ done;
//          MOV EDX,[ECX];    MOV [EAX],EDX;
//          MOV EDX,[ECX+4];  MOV [EAX+4],EDX;
//          MOV EDX,[ECX+8];  MOV [EAX+8],EDX;
//          MOV ECX,[ECX+0xC]; MOV [EAX+0xC],ECX; RET
extern "C" void StdVector_PodCopyElement_0x10_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src)
{
  if (dest == nullptr)
    return;

  // 4 dwords = 0x10 bytes; source/dest treated as POD.
  std::memcpy(dest, src, 0x10);
}

// Ghidra placeholder twin: FUN_00409f70.cpp
