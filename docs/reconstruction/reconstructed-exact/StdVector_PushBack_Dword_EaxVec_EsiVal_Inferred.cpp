// =============================================================================
// StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00411180
// Address:   0x00411180  (autoassault.exe, image base 0x400000)
// System:    container util (cross-cutting; journal consumer)
// Dual:      WQ7R-D 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler + image bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   MSVC-style vector<uint32_t>::push_back with register ABI:
//     EAX = vector* (triad at +4/+8/+0xc)
//     ESI = const uint32_t* value
//   Fast path: store *value at end, end += 4, when size < capacity.
//   Slow path: FUN_0040b6d0 grow/insert (owned WQ7R-E).
//   Distinct from Vector_PushDword @ 0x004149d0 (thiscall ECX + RET 4).

#include <cstdint>

struct StdVectorDword {
  uint32_t _pad0;       // +0x00
  uint32_t* begin;      // +0x04
  uint32_t* end;        // +0x08
  uint32_t* cap_end;    // +0x0c
};

// Grow helper — dual-owned elsewhere (WQ7R-E aa_0040b6d0).
extern "C" void FUN_0040b6d0(uint32_t* end, const uint32_t* value);

// Customcall: EAX=vec, ESI=value*, bare RET (no stack args).
extern "C" void StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred(
    StdVectorDword* vec /*EAX*/,
    const uint32_t* value /*ESI*/)
{
  uint32_t* begin = vec->begin;
  uint32_t size = 0;
  if (begin != nullptr) {
    size = static_cast<uint32_t>(vec->end - begin);
  }

  if (begin != nullptr) {
    uint32_t cap = static_cast<uint32_t>(vec->cap_end - begin);
    if (size < cap) {
      uint32_t* end = vec->end;
      *end = *value;
      vec->end = end + 1;
      return;
    }
  }

  // Image: PUSH EBX; PUSH ESI; PUSH end; LEA EBX,[ESP+0x10]; CALL 0x0040b6d0
  FUN_0040b6d0(vec->end, value);
}
