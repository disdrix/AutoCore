// =============================================================================
// StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred  (aa_00440ab0)
// -----------------------------------------------------------------------------
// Address:   0x00440ab0  (autoassault.exe, image base 0x400000)
// Wave:      MEGA-130 OWN-ONLY dual 2026-08-05
// System:    skills-abilities / gfxUIWindow tree shell @ +0x04
// Exactness: Behavior-preserving rewrite from live decompile + full-body
//            read_memory. Left-walk uses bytes (decompiler false-noreturn
//            collapsed it after operator_delete).
// Bit-for-bit vs retail EXE: DEFERRED.
// Partition alias: StdTree_ClearShell_At04 (call-site role, not full clear).
// =============================================================================

#include <cstdint>

// Node family: isnil @ +0x3D; value object embedded @ +0x0C.
struct StdTreeNode_Isnil3D {
  StdTreeNode_Isnil3D* left;    // +0x00
  StdTreeNode_Isnil3D* parent;  // +0x04
  StdTreeNode_Isnil3D* right;   // +0x08
  // value object starts at +0x0C (destroyed via FUN_00442720)
  // ...
  // isnil at +0x3D (0 = real node)
};

// Tree host shell (head @ +0x04, size @ +0x08 in erase/gfxUIWindow shells).
// ECX is threaded only; body does not load host fields.
struct StdTreeHost_Shell {
  uint32_t _pad0;
  StdTreeNode_Isnil3D* head;  // +0x04 (typical for At04 / erase shells)
  uint32_t size;              // +0x08
};

// 0x00442720 — trampoline: destroy value at node+0x0C via FUN_00440770.
// ABI: EAX = node on entry; bare RET; not dualled here.
extern "C" void StdTree_Node_DestroyVal0C_Via40770_Inferred(StdTreeNode_Isnil3D* node /*EAX*/);

extern "C" void __cdecl operator_delete(void* p);

// ECX = tree host (threaded; unused in body loads). Stack = subtree root.
// Callee cleans 4 bytes (RET 4). void.
// For each node on the left spine of the given root:
//   free right subtree recursively, destroy value @ +0x0C, operator_delete,
//   advance left. Stops at isnil@+0x3D sentinel.
// Does NOT reset head/size — callers perform empty-sentinel fixup.
extern "C" void __fastcall StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred(
    StdTreeHost_Shell* tree_host,
    StdTreeNode_Isnil3D* node)
{
  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x3d) != 0) {
    return;
  }

  for (;;) {
    StdTreeNode_Isnil3D* right =
        *reinterpret_cast<StdTreeNode_Isnil3D**>(reinterpret_cast<char*>(node) + 8);
    StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred(tree_host, right);

    StdTreeNode_Isnil3D* left =
        *reinterpret_cast<StdTreeNode_Isnil3D**>(reinterpret_cast<char*>(node) + 0);

    // Bytes: MOV EAX, EDI; CALL 0x00442720
    StdTree_Node_DestroyVal0C_Via40770_Inferred(node);

    operator_delete(node);
    node = left;

    if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(node) + 0x3d) != 0) {
      break;
    }
  }
}

// Ghidra / scaffold alias (same ABI)
extern "C" void __fastcall FUN_00440ab0(StdTreeHost_Shell* tree_host,
                                        StdTreeNode_Isnil3D* node)
{
  StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred(tree_host, node);
}
