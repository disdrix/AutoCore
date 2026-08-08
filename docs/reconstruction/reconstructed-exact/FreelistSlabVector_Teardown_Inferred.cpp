// =============================================================================
// FreelistSlabVector_Teardown_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00416e80
// Address:   0x00416e80  (autoassault.exe, image base 0x400000)
// Body:      0x00416e80–0x00416ef6 inclusive (119 B / 0x77); ret 4; pad CC
// System:    container / CNDHash freelist slab pointer vector
// Generated: 2026-08-05 WQ9I-A dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-05).
// Ghidra:    FUN_00416e80
// =============================================================================
//
// PURPOSE:
//   Tear down the freelist slab pointer vector nested in CNDHash-family
//   objects at hash+0x20 (when called with freelist subobject as stack arg):
//     for each slot in [begin, end): _aligned_free(*slot)
//     if begin: operator_delete(begin)  // RETURNS
//     begin = end = capacity_end = null
//   Does NOT touch freelist head at subobject +0x00 (nodes already
//   reclaimed by DestroyBucketTable / FreeBuckets).
//
// ABI (sealed from read_memory — decompiler shows void + noreturn delete):
//   stack arg0 = freelist subobject*
//   return     = void; stdcall ret 4 (C2 04 00)
//
// LAYOUT (relative freelist base):
//   +0x08 void** begin;  +0x0c void** end;  +0x10 void** capacity_end
//
// CALLEES:
//   _aligned_free (IAT 0x009c6578); operator_delete
//
// PARENTS:
//   FUN_00406420 CNDHash_Dtor_00a2c2b0 (WQ9H-D): PUSH this+0x20
//   sibling hash dtors 00413850 / 004157f0 / 004169a0; wrapper 00416c30
//
// TWIN:
//   0x0059c8a0 FreelistSlabVector_dtor — same CF, __thiscall bare ret
// =============================================================================

#include <cstdint>

extern "C" void _aligned_free(void* p);
extern "C" void operator_delete(void* p);

struct FreelistSlabVector_Inferred {
  void* head_or_other;   // +0x00 not touched by this teardown
  void* field04;         // +0x04 often unwritten by CNDHash ctor
  void** begin;          // +0x08 array of aligned slab pointers
  void** end;            // +0x0c
  void** capacity_end;   // +0x10
};

// stdcall: stack freelist*; ret 4
extern "C" void FreelistSlabVector_Teardown_Inferred(FreelistSlabVector_Inferred* fl)
{
  // SEH frame present in binary (LAB_009bc71b); omitted from clean CF body.

  void** it = fl->begin;
  void** end = fl->end;
  while (it != end) {
    _aligned_free(*it);
    ++it; // stride 4 (pointer elements)
  }

  if (fl->begin != nullptr) {
    // Decompiler warns "does not return" — false; falls through to zeros.
    operator_delete(fl->begin);
  }

  // ALWAYS zero triad (null-begin path included)
  fl->begin = nullptr;
  fl->end = nullptr;
  fl->capacity_end = nullptr;
}
