// =============================================================================
// StdVector_UninitializedCopy_Elem12_Inferred  (FUN_0040a590)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a590
// Address:   0x0040a590–0x0040a5f4 inclusive (101 B / 0x65)
// System:    MSVC-style uninitialized_copy for vector elem stride 0x0C
// Dual A/B:  2026-08-05 WQ9K-J
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Copy half-open POD range [src_begin, src_end) into dest with stride 0x0C,
//   returning the advanced destination end. Element leaf is dualed
//   StdVector_PodCopyElement_Elem12_Inferred (0x00409f50).
//
// ABI
//   ECX = src_end; stack: src_begin, dest; EAX out = dest_end; plain RET.
//   (Decompiler "__thiscall" is free helper — not a vector member this.)
//   Callers often push 4 dwords + ADD ESP,0x10; this body reads only 2 stack args.
//
// Callers
//   FUN_004082f0 (InsertN Elem12) @ 0x004084ea, 0x0040854e
//   FUN_00409b40 thin trampoline @ 0x00409b50
// Twin stride 0x28: StdVector_UninitializedCopy_Elem0x28_Inferred (0x0040a520)
// =============================================================================

#include <cstdint>

// Element leaf (dualed WQ9J-A) — EAX dest, ECX src
extern "C" void StdVector_PodCopyElement_Elem12_Inferred(
    /*EAX*/ void* dest,
    /*ECX*/ const void* src);

extern "C" void* StdVector_UninitializedCopy_Elem12_Inferred(
    /*ECX*/ const void* src_end,
    /*stack*/ const void* src_begin,
    /*stack*/ void* dest)
{
  // SEH frame present in retail (LAB_009bd0a0); omitted in port-level rewrite.
  const unsigned char* src = static_cast<const unsigned char*>(src_begin);
  const unsigned char* const end = static_cast<const unsigned char*>(src_end);
  unsigned char* out = static_cast<unsigned char*>(dest);

  while (src != end) {
    StdVector_PodCopyElement_Elem12_Inferred(out, src);
    src += 0x0C;
    out += 0x0C;
  }
  return out;
}

// Ghidra placeholder twin: FUN_0040a590.cpp
