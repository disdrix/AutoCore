// =============================================================================
// CNDHash_Ctor_00a2c2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004063a0
// Address:   0x004063a0–0x0040641c  (autoassault.exe @ 0x400000; 125 B / 0x7D)
// System:    container / CNDHash (host vtbl 0x00a2c2b0; sentinel stamp 0x00a2c2e4)
// Dual A/B:  2026-08-04 WQ9H-D
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Construct host-family CNDHash in a pre-allocated 0x34-byte block.
//   Installs vtbl PTR_FUN_00a2c2b0, seeds log2 / provisional bucket count,
//   clears lock and list fields, then allocates empty bucket table (stamp
//   00a2c2e4 sentinels; +0x08 COUNT → MASK).
//
// ABI (MACHINE — not standard thiscall)
//   CL     = uint8_t log2
//   stack  = CNDHash* self  (4-byte slot)
//   return = EAX = self
//   epilogue ret 4
//   SEH: LAB_009bdae2
//   Nested alloc keeps ESI=self (custom ESI ABI of AllocBucketTable).
//
// Callers
//   Sole: FUN_0093e7e0 @ 0x0093e8eb
//         operator_new(0x34) → PUSH eax; MOV CL,2; CALL → store host+0x3084
//
// Nested
//   CNDHash_AllocBucketTable_00a2c2e4 (0x00406f20) — sealed WQ9G-J
//
// Twin dtor
//   CNDHash_Dtor_00a2c2b0 (0x00406420)
//
// Odd (preserved)
//   this+0x24 is NOT written by the ctor (byte gap after freelist +0x20).
//
// Rejected aliases
//   Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_004063a0
//   Ghidra __thiscall(byte log2, this*) role-swap — this is NOT in ECX
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_00a2c2b0; // object vtbl @ 0x00a2c2b0

// Nested: custom ESI = hash*; bare ret / noreturn throw on bad log2
extern void CNDHash_AllocBucketTable_00a2c2e4(/* ESI */ void *hash);

// Register ABI: CL = log2; stack self; ret 4; EAX = self.
// Parameter order models stack slot after CL for readability of the stack arg.
void *CNDHash_Ctor_00a2c2b0(std::uint8_t log2 /*CL*/, void *self /*stack*/)
{
  auto *p = reinterpret_cast<std::uint32_t *>(self);

  // SEH frame LAB_009bdae2 omitted in clean CF — present in bytes

  p[0] = reinterpret_cast<std::uint32_t>(&PTR_FUN_00a2c2b0); // +0x00 vtbl
  p[2] = 1u << (log2 & 0x1f);                                 // +0x08 provisional COUNT
  p[1] = 0;                                                   // +0x04
  p[3] = 0;                                                   // +0x0c live count
  p[4] = 0;                                                   // +0x10 bucket table*
  p[5] = 0;                                                   // +0x14 ordered head
  p[6] = 0;                                                   // +0x18 ordered tail
  *reinterpret_cast<std::uint8_t *>(p + 7) = log2;            // +0x1c
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(self) + 0x1d) = 0; // lock
  p[8] = 0;                                                   // +0x20 freelist area
  // +0x24 intentionally NOT written (odd; preserve)
  p[10] = 0;                                                  // +0x28
  p[11] = 0;                                                  // +0x2c
  p[12] = 0;                                                  // +0x30

  // Machine: ESI = self; CALL CNDHash_AllocBucketTable_00a2c2e4
  CNDHash_AllocBucketTable_00a2c2e4(self);

  return self; // EAX = self; ret 4
}
