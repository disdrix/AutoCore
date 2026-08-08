// =============================================================================
// Map_FreeSubtree_Isnil15_B
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bed0
// Address:   0x0051bed0–0x0051bf05 exclusive (53 B; autoassault.exe base 0x400000)
// System:    STL map/set (MSVC red-black free-subtree; isnil@+0x15)
// Generated: 2026-08-04 WQ9G-D OWN dual A/B seal
// Exactness: Behavior-preserving rewrite. Bytes correct left-walk; decompiler plate
//            omits it (false-noreturn on operator_delete). Not modernization.
//            Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0051bed0.cpp scaffold.
// Dual: reviews/A|B_aa_0051bed0_Map_FreeSubtree_Isnil15_B.md
// =============================================================================
//
// PURPOSE:
//   Free a non-nil MSVC red-black map subtree for the isnil@+0x15 family.
//   Sole external caller is dualed Map_EraseRange_Isnil15_B full-clear path
//   (passes head->parent = root). Twin CF: Map_FreeSubtree_Isnil15
//   @ 0x0051be50 (different VA / callers — do not alias).
//
// ABI: stack node*; RET 4; ECX threaded unused.
// =============================================================================

#include <cstdint>

extern "C" void operator_delete(void* p);

void Map_FreeSubtree_Isnil15_B(void* param_1 /* node* */)
{
  void* node = param_1;

  if (*reinterpret_cast<std::uint8_t*>(
          reinterpret_cast<char*>(node) + 0x15) != 0)
    return;

  for (;;) {
    /* recurse right child @ +8 */
    Map_FreeSubtree_Isnil15_B(*reinterpret_cast<void**>(
        reinterpret_cast<char*>(node) + 8));
    {
      void* left = *reinterpret_cast<void**>(node); /* left @ +0 */
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<std::uint8_t*>(
            reinterpret_cast<char*>(node) + 0x15) != 0)
      break;
  }
}
