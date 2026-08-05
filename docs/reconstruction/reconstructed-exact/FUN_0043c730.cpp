// =============================================================================
// FUN_0043c730  (alias → GuardedVector_CopyAssign)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c730
// Address:   0x0043c730–0x0043c7d6  (autoassault.exe, image base 0x400000)
// System:    STL / guarded container
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W26-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// Named clean: docs/reconstruction/reconstructed-exact/GuardedVector_CopyAssign.cpp
// This twin keeps the Ghidra symbol for tooling that keys on FUN_*.

#include <cstdint>

extern "C" void FUN_0040d9c0(void);
extern "C" void FUN_0043ce90(void);
extern "C" int* FUN_0043c8c0(int* out, uint32_t a, int b, uint32_t dest, int dest_end);
extern "C" void FUN_0043cec0(uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                             uint32_t e, uint32_t f, uint32_t g);

// Retail register ABI: EAX=source, EDI=dest; no stack formals; void.
// Decompiler form uses in_EAX / unaff_EDI — modeled as locals filled by caller.
void FUN_0043c730(void)
{
  uint32_t uVar1;
  int iVar2;
  int in_EAX;      // source — retail EAX
  int unaff_EDI;   // dest   — retail EDI
  uint32_t local_8;
  uint32_t local_4;

  if (unaff_EDI != in_EAX) {
    if (*(uint32_t*)(in_EAX + 0x10) == 0) {
      FUN_0040d9c0();
      return;
    }
    uVar1 = *(uint32_t*)(unaff_EDI + 0x10);
    iVar2 = *(int*)(in_EAX + 0x0c);
    if (*(uint32_t*)(in_EAX + 0x10) <= uVar1) {
      FUN_0043ce90();
      FUN_0043c8c0(reinterpret_cast<int*>(&local_8), local_8, static_cast<int>(local_4),
                   static_cast<uint32_t>(unaff_EDI),
                   *(int*)(unaff_EDI + 0x10) + *(int*)(unaff_EDI + 0x0c));
      return;
    }
    FUN_0043ce90();
    FUN_0043cec0(static_cast<uint32_t>(unaff_EDI), static_cast<uint32_t>(unaff_EDI),
                 static_cast<uint32_t>(*(int*)(unaff_EDI + 0x10) + *(int*)(unaff_EDI + 0x0c)),
                 static_cast<uint32_t>(in_EAX),
                 static_cast<uint32_t>(iVar2 + static_cast<int>(uVar1)),
                 static_cast<uint32_t>(in_EAX),
                 static_cast<uint32_t>(*(int*)(in_EAX + 0x10) + *(int*)(in_EAX + 0x0c)));
  }
}
