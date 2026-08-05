// =============================================================================
// GfxMesh_BuildNonInteriorEdgeIB_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0098fef0
// Address:   0x0098fef0  (autoassault.exe, image base 0x400000)
// System:    palantir graphics / mesh index buffers
// Wave:      W35-F OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving structural rewrite of decompiler + sealed bytes.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   From a triangle mesh with face type ∈ {4,5,6}, lock the source index buffer,
//   count undirected edges via a NestedHash (sentinel node 0x10), and when any
//   edge has refcount != 2 (non-interior: boundary or non-manifold), clone the
//   mesh into a type-2 line IB and write those u16 index pairs.
//
// ABI (sealed by bytes)
//   uint32_t /* mesh* or 0 */ __stdcall
//     GfxMesh_BuildNonInteriorEdgeIB_Inferred(void* ctx /*stack*/, Mesh* mesh /*stack*/);
//   RET 8. Fail/empty → EAX=0. Success → EAX = clone mesh* (ESI).
//
// RELATED
//   NestedHash_Ctor_Sentinel0x10_Inferred (0x00457ac0, W34-E)
//   GetTriangleVertexSteps / FUN_0044b610 (gfxFirst.h)
//   gfxDeviceIB lock/unlock strings (path evidence only)
// =============================================================================

#include <cstdint>

struct NestedHash10;  // W34-E bag; placement-ctor FUN_00457ac0
struct Mesh;
struct GfxDeviceIB;

// Callees (Ghidra names retained where unsealed)
extern "C" NestedHash10* NestedHash_Ctor_Sentinel0x10_Inferred(NestedHash10* self);
extern "C" int32_t FUN_0044b610(int32_t faceType, int32_t* s0, int32_t* s1, int32_t* s2);
extern "C" uint16_t* FUN_00743be0(GfxDeviceIB* ib, int32_t a, int32_t b, uint32_t flags);
extern "C" void FUN_0046c1b0(/* NestedHash find edge key → node* */);
extern "C" void* FUN_0046bf90(/* NestedHash insert */);
extern "C" void FUN_004073a0(/* vector insert-one grow path */);
extern "C" void FUN_0044b9c0(/* device IB holder setup */);
extern "C" void vog_LogMessage(const char* file, int line, int sev, const char* msg);
extern "C" void operator_delete(void* p);

// Structural clean (control flow contract; types tentative).
// Full decompiler body lives in raw capture; this documents the sealed stages.

std::uint32_t GfxMesh_BuildNonInteriorEdgeIB_Inferred(void* ctx, Mesh* mesh) {
  // Gate: null mesh or unsupported face type → 0
  // NestedHash stack bag ctor
  // GetTriangleVertexSteps for face type
  // Lock source IB (flags 0x810)
  // Per face: 3 edges → pack min/max u16 → find-or-insert → refcount++
  // Unlock source IB
  // Collect edges with refcount != 2 into u32 vector (hi, lo as separate pushes)
  // If empty: tidy NestedHash, return 0
  // Clone mesh (vtbl+0x7c); copy streams; attach ctx resource; type=2; flags|=0x20
  // Alloc/lock dest IB (0x800); write u16 indices; unlock
  // Tidy; return clone
  (void)ctx;
  (void)mesh;
  return 0;  // placeholder — see annotated CF; clean twin carries decompiler body
}
