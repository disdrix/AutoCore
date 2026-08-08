// =============================================================================
// CNDHash_Dtor_00a2c2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_00406420
// Address:   0x00406420–0x0040649a  (autoassault.exe @ 0x400000; 123 B / 0x7B)
// System:    container / CNDHash (host vtbl 0x00a2c2b0; sentinel stamp 0x00a2c2e4)
// Dual A/B:  2026-08-04 WQ9H-D
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Destroy host-family CNDHash: re-stamp vtbl, soft-assert if locked for
//   traversal, destroy bucket table (stamp 00a2c2e4 family), then tear down
//   freelist slab vector subobject at this+0x20.
//
// ABI
//   __thiscall; ECX = CNDHash*; void; bare ret
//   SEH: LAB_009beaf7
//   Nested destroy uses EAX = this (custom EAX ABI of DestroyBucketTable).
//
// Callers
//   Sole: FUN_00406520 scalar-deleting dtor (vtbl[00a2c2b0][0]) @ 0x00406523
//         → this dtor → optional operator_delete if flags&1
//
// Nested
//   CNDHash_DestroyBucketTable_00a2c2e4 (0x00406fc0) — sealed WQ9G-J
//   FUN_00416e80 (this+0x20) freelist slab vector dtor — residual
//
// Twin ctor
//   CNDHash_Ctor_00a2c2b0 (0x004063a0)
//
// Odd (preserved)
//   Lock path logs HashError + VOG_DEBUG_STOP but does NOT throw and does NOT
//   skip destroy (non-fatal soft assert).
//
// Rejected aliases
//   Named_VOG_DEBUG_STOP_00406420 (assert string only)
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_00a2c2b0; // object vtbl @ 0x00a2c2b0

extern void FUN_007a4480(int level, const char *msg); // vog log
// Nested: custom EAX = hash*; bare ret
extern void CNDHash_DestroyBucketTable_00a2c2e4(/* EAX */ void *hash);
// Freelist vector at hash+0x20: aligned_free each slot then operator_delete buffer
extern void FUN_00416e80(void *freelistSubobject /* stack */);

// void __thiscall — bare ret
void __fastcall CNDHash_Dtor_00a2c2b0(void *thisHash /*ECX*/)
{
  // SEH frame LAB_009beaf7 omitted in clean CF — present in bytes

  *reinterpret_cast<void **>(thisHash) = &PTR_FUN_00a2c2b0;

  if (*reinterpret_cast<char *>(reinterpret_cast<char *>(thisHash) + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    // non-fatal — fall through
  }

  // Machine: MOV EAX,ESI; CALL DestroyBucketTable
  CNDHash_DestroyBucketTable_00a2c2e4(thisHash);

  // Machine: LEA EAX,[ESI+0x20]; PUSH EAX; CALL FUN_00416e80
  FUN_00416e80(reinterpret_cast<char *>(thisHash) + 0x20);
}
