// =============================================================================
// FUN_00440ab0  — twin of StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00440ab0
// Address:   0x00440ab0  (autoassault.exe, image base 0x400000)
// Wave:      MEGA-130 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite; left-walk from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct StdTreeNode_Isnil3D {
  StdTreeNode_Isnil3D* left;    // +0x00
  StdTreeNode_Isnil3D* parent;  // +0x04
  StdTreeNode_Isnil3D* right;   // +0x08
  // value @ +0x0C; isnil @ +0x3D
};

struct StdTreeHost_Shell {
  uint32_t _pad0;
  StdTreeNode_Isnil3D* head;
  uint32_t size;
};

extern "C" void StdTree_Node_DestroyVal0C_Via40770_Inferred(StdTreeNode_Isnil3D* node /*EAX*/);
extern "C" void __cdecl operator_delete(void* p);

// ECX = tree host; stack = node*; RET 4; void.
extern "C" void __fastcall FUN_00440ab0(StdTreeHost_Shell* tree_host,
                                        StdTreeNode_Isnil3D* node)
{
  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x3d) != 0) {
    return;
  }

  for (;;) {
    StdTreeNode_Isnil3D* right =
        *reinterpret_cast<StdTreeNode_Isnil3D**>(reinterpret_cast<char*>(node) + 8);
    FUN_00440ab0(tree_host, right);

    StdTreeNode_Isnil3D* left =
        *reinterpret_cast<StdTreeNode_Isnil3D**>(reinterpret_cast<char*>(node) + 0);

    StdTree_Node_DestroyVal0C_Via40770_Inferred(node);
    operator_delete(node);
    node = left;

    if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x3d) != 0) {
      break;
    }
  }
}
