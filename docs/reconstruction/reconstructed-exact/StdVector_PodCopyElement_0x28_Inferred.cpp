// =============================================================================
// StdVector_PodCopyElement_0x28_Inferred  (FUN_00409f30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409f30
// Address:   0x00409f30–0x00409f43 inclusive (20 B / 0x14)
// System:    MSVC-style POD element copy for vector elem stride 0x28
// Dual A/B:  2026-08-05 WQ9I-B
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Null-safe POD copy of one 0x28-byte (10-dword) element. Leaf used by
//   ConstructN (0x00409d40) and range-copy (0x0040a520) for the elem-0x28 family.
//
// ABI
//   Register: EAX = dest T*, EDX = src const T*; no stack args; plain RET.
//   (MSVC leaf convention matching REP MOVSD helpers; not stack-thiscall.)
//
// Callers
//   FUN_00409d40 StdVector_ConstructN_Elem0x28_Inferred @ 0x00409d78
//   FUN_0040a520 (uninit_copy / copy-range step +0x28) @ 0x0040a558
// =============================================================================

#include <cstdint>
#include <cstring>

// Machine: PUSH EDI; MOV EDI,EAX; TEST EDI,EDI; JZ done;
//          PUSH ESI; MOV ECX,10; MOV ESI,EDX; REP MOVSD; POP ESI; POP EDI; RET
extern "C" void StdVector_PodCopyElement_0x28_Inferred(
    /*EAX*/ void* dest,
    /*EDX*/ const void* src)
{
  if (dest == nullptr)
    return;

  // 10 dwords = 0x28 bytes; source/dest treated as POD.
  std::memcpy(dest, src, 0x28);
}

// Ghidra placeholder twin: FUN_00409f30.cpp
