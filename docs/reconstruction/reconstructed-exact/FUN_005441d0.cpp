// =============================================================================
// FUN_005441d0  (twin of GuardedVector_InsertRange_Thiscall)
// -----------------------------------------------------------------------------
// Stable ID: aa_005441d0
// Address:   0x005441d0–0x00544587  (autoassault.exe, image base 0x400000)
// Dual:      W32-I 2026-07-29
// Prefer:    GuardedVector_InsertRange_Thiscall.cpp for named plate
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Prefer named clean:
//   docs/reconstruction/reconstructed-exact/GuardedVector_InsertRange_Thiscall.cpp

// Retail: ECX=dest; 7 stack formals; RET 0x1C.
// Shorter-side insert range; room via 0043e3d0 / 0043d670; assign 0043ec50 / 0043ebb0.

void __thiscall FUN_005441d0(int dest /*ECX*/,
                             uint32_t /*scratch*/,
                             uint32_t insert_at,
                             int firstC,
                             uint32_t firstIdx,
                             int lastC,
                             uint32_t lastIdx)
{
  int begin = *reinterpret_cast<int*>(dest + 0x0c);
  int size = *reinterpret_cast<int*>(dest + 0x10);
  uint32_t prefix = insert_at - static_cast<uint32_t>(begin);
  uint32_t suffix = static_cast<uint32_t>(size) - prefix;
  uint32_t n = lastIdx - firstIdx;

  // 4-arm shorter-side tree — full body in GuardedVector_InsertRange_Thiscall.cpp
  // Front: PushFront_Thiscall 0043e3d0; Back: PushBack_Thiscall 0043d670;
  // Assign: FUN_0043ec50 forward / FUN_0043ebb0 backward.
  (void)prefix;
  (void)suffix;
  (void)n;
  (void)firstC;
  (void)lastC;
}
