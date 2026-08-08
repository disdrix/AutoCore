// =============================================================================
// StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406e70
// Address:   0x00406e70  (autoassault.exe, image base 0x400000)
// Body:      0x00406e70–0x00406ed8 (104 B / 0x68); ret 0x0C; pad CC to 0x00406ee0
// System:    util / container (std::vector POD stride 0xC)
// Generated: 2026-08-04 WQ9G-I dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00406e70
// =============================================================================
//
// PURPOSE:
//   Insert exactly one 12-byte POD element into an MSVC-style vector, then rebind
//   an out-iterator so it remains valid after a possible reallocation of begin.
//
// ABI (customcc — sealed from bytes C2 0C 00 + parent FUN_004062a0):
//   EDI        = vector*  (begin@+4, end@+8, capEnd@+0xC)
//   stack arg0 = T** outIt
//   stack arg1 = T*  insert position (push_back passes end)
//   stack arg2 = const T* value (12-byte POD source)
//   return     = EAX = outIt; ret 0x0C
//
// CALLEE:
//   FUN_004082f0 = InsertN / grow engine for elem-0xC (count forced to 1)
//
// SIBLINGS (tree-neighborhood residual leaves, depth-4 WQ9G):
//   0x00406de0 InsertOne elem 0x28 (WQ9G-H)
//   0x00406e50 Ufill elem 0x28     (WQ9G-H)
//   0x00406ee0 Ufill elem 0xC      (this partition pair)
//
// PARENT:
//   FUN_004062a0 push_back: fast path construct-1 at end when capacity remains;
//   else this unit with where = end.
// =============================================================================

#include <cstdint>

struct Pod12 {
  uint32_t d0, d1, d2;
};

struct VecPod12 {
  void* _unused0;   // +0
  Pod12* begin;     // +4
  Pod12* end;       // +8
  Pod12* capEnd;    // +0xC
};

// InsertN residual (undualed here): thiscall ECX=vec; stack where, count, value*
extern "C" void FUN_004082f0(
    /*ECX*/ VecPod12* vec,
    Pod12* where,
    uint32_t count,
    const Pod12* value);

// Customcc cannot be expressed portably; document register contract in plate.
// Body mirrors recovered CF with explicit vec parameter for readability.

extern "C" Pod12** StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred(
    VecPod12* vec /*EDI*/,
    Pod12** outIt,
    Pod12* where,
    const Pod12* value)
{
  Pod12* begin = vec->begin;
  int index;
  if (begin == nullptr ||
      (static_cast<int>(reinterpret_cast<char*>(vec->end) -
                        reinterpret_cast<char*>(begin)) / 12) == 0) {
    index = 0;
  } else {
    index = static_cast<int>(reinterpret_cast<char*>(where) -
                             reinterpret_cast<char*>(begin)) /
            12;
  }

  // Bytes: push value; push 1; push where; mov ecx,edi; call FUN_004082f0
  FUN_004082f0(vec, where, 1, value);

  *outIt = reinterpret_cast<Pod12*>(
      reinterpret_cast<char*>(vec->begin) + index * 12);
  return outIt; // EAX = outIt; ret 0x0C
}
