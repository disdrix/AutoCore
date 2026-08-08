// =============================================================================
// StdVector_UninitCopyTrampoline_Elem0x28_Inferred  (FUN_00409ae0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409ae0
// Address:   0x00409ae0–0x00409afa inclusive (27 B / 0x1b)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-05 WQ9K-A OWN dual A/B seal
// Exactness: Byte-corrected ABI rewrite. Decompiler omits 2nd stack arg / RET 8;
//            disassemble_function + read_memory authoritative.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Thin ABI trampoline into dualed StdVector_UninitializedCopy_Elem0x28_Inferred
//   (0x0040a520). Reorders InsertN grow-site registers (ECX=this, EDX=dest,
//   stack begin/end) into free-helper layout (ECX=end, stack begin+dest).
//   Used only by FUN_00408050 reallocate path (prefix + suffix uninit_copy).
//
// ABI
//   ECX = host/vector this (forwarded but unused by target body)
//   EDX = dest
//   stack: src_begin, src_end
//   EAX = advanced dest_end from 0040a520
//   RET 8
//
// Twin / peers (do not merge)
//   StdVector_UninitializedCopy_Elem0x28_Inferred @ 0x0040a520 (real worker)
//   Direct InsertN sites also call 0040a520 without this trampoline
//   Elem12 range twin 0040a590 (different stride)
// =============================================================================

#include <cstdint>

// Dualed WQ9J-A — ECX=src_end; stack begin,dest; EAX=dest_end; plain RET
extern "C" void *StdVector_UninitializedCopy_Elem0x28_Inferred(
    /*ECX*/ const void *src_end,
    /*stack*/ const void *src_begin,
    /*stack*/ void *dest);

// ECX=host_unused; EDX=dest; stack begin,end; EAX=dest_end; RET 8
extern "C" void *__fastcall StdVector_UninitCopyTrampoline_Elem0x28_Inferred(
    void * /*ECX*/ host_unused,
    void * /*EDX*/ dest,
    const void *src_begin,
    const void *src_end)
{
  (void)host_unused;
  // Machine pushes 4 dwords then ADD ESP,0x10; target reads only begin+dest.
  // Extra slots: re-pushed begin + host this (ignored by 0040a520 body).
  return StdVector_UninitializedCopy_Elem0x28_Inferred(
      /*ECX*/ src_end,
      /*stack*/ src_begin,
      /*stack*/ dest);
}

// Ghidra placeholder twin: FUN_00409ae0.cpp
