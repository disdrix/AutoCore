// =============================================================================
// FUN_004063a0 — clean twin of CNDHash_Ctor_00a2c2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004063a0
// Address:   0x004063a0–0x0040641c  (125 B)
// Dual A/B:  2026-08-04 WQ9H-D
// Prefer named source: CNDHash_Ctor_00a2c2b0.cpp
// =============================================================================

#include <cstdint>

extern void *PTR_FUN_00a2c2b0;
extern void CNDHash_AllocBucketTable_00a2c2e4(/* ESI */ void *hash);

// ABI: CL=log2; stack self; ret 4; EAX=self (not standard thiscall)
void *FUN_004063a0(std::uint8_t log2 /*CL*/, void *self /*stack*/)
{
  auto *p = reinterpret_cast<std::uint32_t *>(self);

  p[0] = reinterpret_cast<std::uint32_t>(&PTR_FUN_00a2c2b0);
  p[2] = 1u << (log2 & 0x1f);
  p[1] = 0;
  p[3] = 0;
  p[4] = 0;
  p[5] = 0;
  p[6] = 0;
  *reinterpret_cast<std::uint8_t *>(p + 7) = log2;
  *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(self) + 0x1d) = 0;
  p[8] = 0;
  // +0x24 not written
  p[10] = 0;
  p[11] = 0;
  p[12] = 0;

  CNDHash_AllocBucketTable_00a2c2e4(self);
  return self;
}
