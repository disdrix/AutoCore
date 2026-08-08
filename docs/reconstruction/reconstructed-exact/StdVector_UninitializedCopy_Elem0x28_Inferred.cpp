// =============================================================================
// StdVector_UninitializedCopy_Elem0x28_Inferred  (FUN_0040a520)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a520
// Address:   0x0040a520–0x0040a584 inclusive (101 B / 0x65)
// System:    MSVC-style uninitialized_copy for vector elem stride 0x28
// Dual A/B:  2026-08-05 WQ9J-A
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Copy half-open POD range [src_begin, src_end) into dest with stride 0x28,
//   returning the advanced destination end. Element leaf is dualed
//   StdVector_PodCopyElement_0x28_Inferred (0x00409f30).
//
// ABI
//   ECX = src_end; stack: src_begin, dest; EAX out = dest_end; plain RET.
//   (Decompiler "__thiscall" is free helper — not a vector member this.)
//   Callers often push 4 dwords + ADD ESP,0x10; this body reads only 2 stack args.
//
// Callers
//   FUN_00408050 (InsertN / reallocate) @ 0x0040824c, 0x004082b3
//   FUN_00409ae0 thin trampoline @ 0x00409af0
// =============================================================================

#include <cstdint>

// Element leaf (dualed WQ9I-B)
extern "C" void StdVector_PodCopyElement_0x28_Inferred(
    /*EAX*/ void* dest,
    /*EDX*/ const void* src);

extern "C" void* StdVector_UninitializedCopy_Elem0x28_Inferred(
    /*ECX*/ const void* src_end,
    /*stack*/ const void* src_begin,
    /*stack*/ void* dest)
{
  // SEH frame present in retail (LAB_009bd0b0); omitted in port-level rewrite.
  const unsigned char* src = static_cast<const unsigned char*>(src_begin);
  const unsigned char* const end = static_cast<const unsigned char*>(src_end);
  unsigned char* out = static_cast<unsigned char*>(dest);

  while (src != end) {
    StdVector_PodCopyElement_0x28_Inferred(out, src);
    src += 0x28;
    out += 0x28;
  }
  return out;
}

// Ghidra placeholder twin: FUN_0040a520.cpp
