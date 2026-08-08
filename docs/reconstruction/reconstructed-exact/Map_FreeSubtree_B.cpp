// =============================================================================
// Map_FreeSubtree_B
// -----------------------------------------------------------------------------
// Stable ID: aa_0051be90
// Address:   0x0051be90–0x0051bec5  (53 B; autoassault.exe base 0x400000)
// System:    STL map/set (MSVC red-black free-subtree; isnil@+0x29)
// Generated: 2026-08-04 WQ9E-I OWN dual A/B seal
// Exactness: Behavior-preserving rewrite. Bytes correct left-walk; decompiler plate
//            omits it (false-noreturn on operator_delete). Not modernization.
//            Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0051be90.cpp scaffold.
// Dual: reviews/A|B_aa_0051be90_Map_FreeSubtree_B.md
// =============================================================================
//
// PURPOSE:
//   Free a non-nil MSVC red-black map subtree for the large-node family
//   (isnil@+0x29). Sole external caller is Map_EraseRange_B full-clear path
//   (passes head->parent = root). Discriminates Map_EraseRange_B from
//   Map_EraseRange (which uses FUN_0051bbc0).
//
// ABI: stack node*; RET 4; ECX threaded unused.
// Twin CF: MapFloatTfid_FreeSubtree_Isnil29_Inferred @ 0x0058da00; FUN_0051bbc0.
// =============================================================================

#include <cstdint>

extern "C" void operator_delete(void* p);

void Map_FreeSubtree_B(void* param_1 /* node* */)
{
  void* node = param_1;

  if (*reinterpret_cast<std::uint8_t*>(
          reinterpret_cast<char*>(node) + 0x29) != 0)
    return;

  for (;;) {
    /* recurse right child @ +8 */
    Map_FreeSubtree_B(*reinterpret_cast<void**>(
        reinterpret_cast<char*>(node) + 8));
    {
      void* left = *reinterpret_cast<void**>(node); /* left @ +0 */
      operator_delete(node);
      node = left;
    }
    if (*reinterpret_cast<std::uint8_t*>(
            reinterpret_cast<char*>(node) + 0x29) != 0)
      break;
  }
}
