// =============================================================================
// StdVector_PodCopyElement_Elem12_Inferred  (FUN_00409f50)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409f50
// Address:   0x00409f50–0x00409f64 inclusive (21 B / 0x15)
// System:    MSVC-style POD element copy for vector elem stride 0x0C
// Dual A/B:  2026-08-05 WQ9J-A
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Null-safe POD copy of one 12-byte (3-dword) element. Leaf used by
//   ConstructN (0x00409db0) and range-copy (0x0040a590) for the Elem12 family.
//
// ABI
//   Register: EAX = dest T*, ECX = src const T*; no stack args; plain RET.
//   Do NOT merge with PodCopy 0x28 (00409f30) which uses EAX/EDX and 10 dwords.
//
// Callers
//   FUN_00409db0 StdVector_ConstructN_Elem12_Inferred @ 0x00409de8
//   FUN_0040a590 (uninit_copy / copy-range step +0x0C) @ 0x0040a5c8
// =============================================================================

#include <cstdint>
#include <cstring>

// Machine: TEST EAX,EAX; JZ done;
//          MOV EDX,[ECX]; MOV [EAX],EDX;
//          MOV EDX,[ECX+4]; MOV [EAX+4],EDX;
//          MOV ECX,[ECX+8]; MOV [EAX+8],ECX; RET
extern "C" void StdVector_PodCopyElement_Elem12_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src)
{
  if (dest == nullptr)
    return;

  // 3 dwords = 0x0C bytes; source/dest treated as POD.
  std::memcpy(dest, src, 0x0C);
}

// Ghidra placeholder twin: FUN_00409f50.cpp
