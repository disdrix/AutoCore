// =============================================================================
// StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406220
// Address:   0x00406220  (autoassault.exe, image base 0x400000)
// Body:      0x00406220–0x00406298 exclusive (120 B / 0x78); ret 0; pad CC
// System:    util / container (std::vector elem stride 0x28)
// Generated: 2026-08-04 WQ9H-C dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00406220
// =============================================================================
//
// PURPOSE:
//   MSVC-style vector::push_back for 0x28-byte POD elements.
//   Fast path: construct one element at end when size < capacity.
//   Slow path: insert-one + rebind (may realloc) at end via dualed 0x00406de0.
//
// ABI (sealed from bytes + caller sites):
//   EAX  = vector*  (begin@+4, end@+8, capEnd@+0xC)
//   ECX  = const T* value (pointer to 0x28 POD)
//   ret  = none (plain C3); no stack formals
//
// CALLEES:
//   FUN_00409d40 — ConstructN for elem 0x28 (undualed residual; WQ9H-B owns)
//   FUN_00406de0 — StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred (WQ9G-H)
//
// CALLERS (2):
//   FUN_00933480 @ 0x009335fb — EAX=*(ESI+0xc80)+0x68; ECX=&local_0x28
//   FUN_00976900 @ 0x00976b7c — EAX=ESI+0x68; ECX=&parsed element
//
// TWIN:
//   aa_004062a0 StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred (stride 0xC)
// =============================================================================

#include <cstdint>

// ConstructN: dest*, count; value packing per bytes (phantom pushes + add esp,0x10).
// Owned residual WQ9H-B.
extern "C" void FUN_00409d40(/*stack*/ void* dest, /*stack*/ int count);

// Insert-one rebind (dualed WQ9G-H). EDI=vec; stack out**/where*/value*; ret 0xC.
extern "C" void** StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred(
    void* vec /*EDI*/,
    void** outIt,
    void* where,
    const void* value);

// Customcc cannot be expressed portably; register contract documented in plate.

extern "C" void StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred(
    void* vec /*EAX*/,
    const void* value /*ECX*/)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);

  if (begin != 0) {
    unsigned size =
        static_cast<unsigned>(
            (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) /
            0x28);
    unsigned capacity =
        static_cast<unsigned>(
            (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 0xc) - begin) /
            0x28);
    if (size < capacity) {
      int end = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8);
      // Bytes: push value*; push vec; push 1; push end; call FUN_00409d40; add esp,16
      FUN_00409d40(reinterpret_cast<void*>(end), 1);
      *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) = end + 0x28;
      return;
    }
  }

  // Grow / empty: insert-one at end. Out-iterator rebound then discarded.
  void* outScratch = const_cast<void*>(value);
  void* end = *reinterpret_cast<void**>(reinterpret_cast<char*>(vec) + 8);
  // Bytes: mov edi,eax (vec); push value; push end; lea out; push out; call 00406de0
  StdVector_InsertOne_RebindIt_Elem0x28_Via408050_Inferred(
      vec, &outScratch, end, value);
}
