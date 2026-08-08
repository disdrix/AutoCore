// =============================================================================
// FUN_0051de80  (scaffold twin of SkillCNDHash_CompleteDtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051de80
// Address:   0x0051de80–0x0051deea inclusive (107 B / 0x6B)
// Wave:      2026-08-04 WQ9G-A OWN dual A/B
// Named:     reconstructed-exact/SkillCNDHash_CompleteDtor_Inferred.cpp
// Exactness: Behavior-preserving rewrite; thiscall + soft-lock + teardown order sealed.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_004cba60(void *self);
extern "C" void __fastcall FUN_0059c8a0(void *host);
extern "C" void FUN_007a4480(int level, const char *msg);

// ECX=this; bare RET; void
extern "C" void __thiscall FUN_0051de80(void *self)
{
  // SEH frame LAB_009a371b omitted

  *reinterpret_cast<void **>(self) = reinterpret_cast<void *>(0x009ce1b8); // PTR_FUN_009ce1b8

  if (*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(self) + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }

  FUN_004cba60(self);
  FUN_0059c8a0(reinterpret_cast<char *>(self) + 0x20);
}
