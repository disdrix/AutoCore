// =============================================================================
// Object_WriteComposedMatrix
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b5c0
// Address:   0x0044b5c0 – 0x0044b60f (autoassault.exe, image base 0x400000)
// System:    graphics / xform
// Generated: 2026-07-29 W22-C dual seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of sealed control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
// Resolve primary object's matrix at +0x40 (rebuild via FUN_009730e0 if flags@+0xbc
// bit1 set). Optionally refresh companion transform (FUN_00972e50 if bit0 set).
// Compose into outMatrix via FUN_00412d40. Return outMatrix.
//
// ABI: cdecl stack outMatrix; ECX=primary; EDI=companion; ret; EAX=out.
// Caller: Bounds_AccumulateTransformedLocal @ 0x0074c9eb.

#include <cstdint>

struct ObjectLike;

extern "C" float* FUN_009730e0(ObjectLike* self /*fastcall/this*/);
extern "C" ObjectLike* FUN_00972e50(ObjectLike* self);
extern "C" void FUN_00412d40(float* out, void* left, void* right);

// cdecl + ECX + EDI live-in
extern "C" float* Object_WriteComposedMatrix(
    ObjectLike* primary,   // ECX
    float* outMatrix,      // stack0
    ObjectLike* companion) // EDI
{
  auto* p = reinterpret_cast<uint8_t*>(primary);
  float* matA;
  if (((*reinterpret_cast<uint32_t*>(p + 0xbc) >> 1) & 1u) == 0)
    matA = reinterpret_cast<float*>(p + 0x40);
  else
    matA = FUN_009730e0(primary);

  auto* c = reinterpret_cast<uint8_t*>(companion);
  if ((*reinterpret_cast<uint8_t*>(c + 0xbc) & 1u) != 0) {
    ObjectLike* refreshed = FUN_00972e50(companion);
    FUN_00412d40(outMatrix, refreshed, matA);
  } else {
    FUN_00412d40(outMatrix, companion, matA);
  }
  return outMatrix;
}

extern "C" float* FUN_0044b5c0(ObjectLike* primary, float* outMatrix, ObjectLike* companion)
{
  return Object_WriteComposedMatrix(primary, outMatrix, companion);
}
