// =============================================================================
// StdVector_UninitializedFillN_Elem0x10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00407000
// Address:   0x00407000  (autoassault.exe, image base 0x400000)
// Body:      0x00407000–0x0040701d (29 B / 0x1d); ret 4; pad CC to 0x00407020
// System:    util / container (std::vector uninitialized_fill_n, POD stride 0x10)
// Generated: 2026-08-05 R10-007 dual seal (raw + live decompile + disasm + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-05).
// Ghidra:    FUN_00407000
// =============================================================================
//
// PURPOSE:
//   uninitialized_fill_n for 16-byte POD vector elements: construct `count`
//   copies of `value` starting at `dest`, return end pointer dest+count*0x10.
//
// ABI (customcc — sealed from bytes C2 04 00 + parent FUN_00408640 call sites):
//   EDI        = T* dest
//   ESI        = int count
//   stack arg0 = const T* value
//   return     = EAX = dest + count*0x10; ret 4
//
// CALLEE:
//   FUN_00409e20 / StdVector_ConstructN_Elem0x10_Inferred (dualed MEGA-044):
//   ECX=value*, stack dest + count; SEH; loop PodCopy 4 dwords via FUN_00409f70;
//   advance dest by 0x10 each iter; cdecl RET (wrapper cleans add esp,0x10).
//
// PARENT:
//   FUN_00408640 / StdVector_InsertN_Elem0x10_Inferred (dualed): after uninit-copy
//   of prefix into new/hole buffer, calls this to plant N template copies, then
//   uninit-copies the suffix. Sites @ 0x00408746 (realloc) and 0x0040880c (in-place).
//
// SIBLINGS:
//   0x00406e50 Ufill elem 0x28; 0x00406ee0 Ufill elem 0xC; construct-N 0x00409e20.
// =============================================================================

#include <cstdint>

struct Pod16 {
  uint32_t d0, d1, d2, d3;
};

// Construct-N dualed: ECX=value*, stack dest + count (cdecl formals + phantoms)
extern "C" void FUN_00409e20(Pod16* dest, int count /*, ECX = const Pod16* value */);

extern "C" Pod16* StdVector_UninitializedFillN_Elem0x10_Inferred(
    Pod16* dest /*EDI*/,
    int count /*ESI*/,
    const Pod16* value /*stack*/)
{
  // Bytes: push value; push ecx; mov ecx,value; push count; push dest;
  //        call FUN_00409e20; add esp,0x10
  (void)value; // ECX formal into construct-N (register); stack value used as template source
  FUN_00409e20(dest, count);

  // mov eax,esi; shl eax,4; add eax,edi  → dest + count*0x10
  return reinterpret_cast<Pod16*>(reinterpret_cast<char*>(dest) + count * 0x10);
}
