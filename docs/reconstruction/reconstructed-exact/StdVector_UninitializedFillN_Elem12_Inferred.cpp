// =============================================================================
// StdVector_UninitializedFillN_Elem12_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406ee0
// Address:   0x00406ee0  (autoassault.exe, image base 0x400000)
// Body:      0x00406ee0–0x00406efd (29 B / 0x1d); ret 4; pad CC to 0x00406f00
// System:    util / container (std::vector uninitialized_fill_n, POD stride 0xC)
// Generated: 2026-08-04 WQ9G-I dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00406ee0
// =============================================================================
//
// PURPOSE:
//   uninitialized_fill_n for 12-byte POD vector elements: construct `count`
//   copies of `value` starting at `dest`, return end pointer dest+count*0xC.
//
// ABI (customcc — sealed from bytes C2 04 00 + parent FUN_004082f0 call sites):
//   EDI        = T* dest
//   ESI        = int count
//   stack arg0 = const T* value
//   return     = EAX = dest + count*0xC; ret 4
//
// CALLEE:
//   FUN_00409db0 construct-N: ECX=value*, stack dest + count; loop copies via
//   FUN_00409f50 (3-dword POD assign; advance dest by 0xC each iter).
//
// PARENT:
//   FUN_004082f0 InsertN: after uninit-copy of prefix into new/hole buffer,
//   calls this to plant N template copies, then uninit-copies the suffix.
//
// SIBLINGS:
//   0x00406e50 Ufill elem 0x28; 0x00406e70 InsertOne elem 0xC (pair).
// =============================================================================

#include <cstdint>

struct Pod12 {
  uint32_t d0, d1, d2;
};

// Construct-N residual: ECX=value*, stack dest + count (cdecl formals + phantoms)
extern "C" void FUN_00409db0(Pod12* dest, int count /*, ECX = const Pod12* value */);

extern "C" Pod12* StdVector_UninitializedFillN_Elem12_Inferred(
    Pod12* dest /*EDI*/,
    int count /*ESI*/,
    const Pod12* value /*stack*/)
{
  // Bytes: push value; push ecx; mov ecx,value; push count; push dest;
  //        call FUN_00409db0; add esp,0x10
  FUN_00409db0(dest, count);

  // lea edx,[esi+esi*2]; lea eax,[edi+edx*4]  → dest + count*12
  return reinterpret_cast<Pod12*>(reinterpret_cast<char*>(dest) + count * 12);
}
