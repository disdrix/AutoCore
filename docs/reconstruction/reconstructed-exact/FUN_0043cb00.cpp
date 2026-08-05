// =============================================================================
// FUN_0043cb00  (twin of GuardedVector_InsertN)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043cb00
// Address:   0x0043cb00–0x0043cdfe  (autoassault.exe, image base 0x400000)
// Dual:      W29-A 2026-07-29
// Prefer:    GuardedVector_InsertN.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Prefer named clean: docs/reconstruction/reconstructed-exact/GuardedVector_InsertN.cpp

// Retail: ECX=N; stack (container, seed, insert_at, fill*); RET 0x10.
// Decompiler may label __thiscall; ECX is count, not container.

void FUN_0043cb00(uint32_t n /*ECX*/, int container /*stack+4*/, int /*seed*/,
                  int insert_at, uint32_t* fill)
{
  int begin = *reinterpret_cast<int*>(container + 0x0c);
  int size = *reinterpret_cast<int*>(container + 0x10);
  uint32_t prefix = static_cast<uint32_t>(insert_at - begin);
  uint32_t suffix = static_cast<uint32_t>(size) - prefix;

  // 4-arm shorter-side tree — full body in GuardedVector_InsertN.cpp
  // Front: FUN_0043ce10; Back: FUN_0043c830; Fill: FUN_0043cef0;
  // Move: FUN_0043d390 / FUN_0043d300. SEH cleanup: 0040d980 / 0043df70.
  (void)n;
  (void)prefix;
  (void)suffix;
  (void)fill;
}
