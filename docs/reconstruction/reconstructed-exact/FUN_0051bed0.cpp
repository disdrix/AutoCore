// =============================================================================
// FUN_0051bed0  (scaffold alias — see Map_FreeSubtree_Isnil15_B.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bed0
// Address:   0x0051bed0  (autoassault.exe, image base 0x400000)
// System:    STL map/set free-subtree (isnil@+0x15)
// Generated: 2026-08-04 WQ9G-D — scaffold kept as FUN_* twin of named clean
// Exactness: Behavior-preserving. Prefer Map_FreeSubtree_Isnil15_B.cpp for named port.
// Dual: reviews/A|B_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md
// =============================================================================

#include <cstdint>

extern "C" void operator_delete(void* p);

void FUN_0051bed0(void* param_1)
{
  void* node = param_1;

  if (*reinterpret_cast<std::uint8_t*>(
          reinterpret_cast<char*>(node) + 0x15) != 0)
    return;

  for (;;) {
    FUN_0051bed0(*reinterpret_cast<void**>(
        reinterpret_cast<char*>(node) + 8));
    {
      void* left = *reinterpret_cast<void**>(node);
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<std::uint8_t*>(
            reinterpret_cast<char*>(node) + 0x15) != 0)
      break;
  }
}
