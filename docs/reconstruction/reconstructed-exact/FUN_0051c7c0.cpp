// =============================================================================
// FUN_0051c7c0  (scaffold alias — prefer Map_EraseRange.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051c7c0
// Address:   0x0051c7c0–0x0051c873
// Canonical: Map_EraseRange
// Generated: 2026-08-04 WQ9D-H — upgraded from 2026-07-23 scaffold
// =============================================================================

// See Map_EraseRange.cpp for named clean plate.
// Ghidra surface kept for FUN_* coverage paths.

void __thiscall FUN_0051c7c0(
    int param_1,
    unsigned int* param_2,
    int* param_3,
    int* param_4)
{
  // Full: if first==*head && last==head → FUN_0051bbc0(root); reset; size=0; *out=*head
  // Partial: successor(isnil@+0x29) + FUN_0051cb40(Map_EraseNode) loop; *out=first
  // ABI: thiscall; ret 0x0c. Body 180 B.
  (void)param_1;
  (void)param_2;
  (void)param_3;
  (void)param_4;
}
