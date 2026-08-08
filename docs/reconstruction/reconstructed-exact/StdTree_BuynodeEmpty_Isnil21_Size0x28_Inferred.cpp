// =============================================================================
// StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred  (FUN_004088f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004088f0
// Address:   0x004088f0–0x00408979 inclusive (138 B / 0x8A); exclusive end 0x0040897a
// System:    MSVC std::_Tree empty-node buy — size 0x28, isnil@+0x21
// Generated: 2026-08-04 WQ9H-I dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate one red-black tree node (size 0x28) with zeroed links, color=1,
//   isnil=0. Shared by tree/map head-sentinel constructors (4 callers): they
//   store the pointer as _Myhead, set isnil=1, and wire left/parent/right to self.
//
// ABI: cdecl; no args; RET 0; EAX = node* | null.
// Twin empty-head (isnil29/size0x30): FUN_00408a30 (WQ9H-J).
// Full value buynode peer (size0x28): FUN_00408990 (WQ9H-J).
//
// Dual: reviews/A|B_aa_004088f0_StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred.md

#include <cstdint>
#include <cstddef>

struct NodeIsnil21_Size28 {
  NodeIsnil21_Size28* left;    // +0x00
  NodeIsnil21_Size28* parent;  // +0x04
  NodeIsnil21_Size28* right;   // +0x08
  std::uint8_t value[0x14];    // +0x0C .. +0x1F  (Val20 region; product open)
  std::uint8_t color;          // +0x20  (this unit: 1)
  std::uint8_t isnil;          // +0x21  (this unit: 0; head ctors set 1)
  // pad to 0x28
};

// CRT
extern "C" void* operator_new(std::size_t size);

// cdecl RET 0; EAX = node*
extern "C" NodeIsnil21_Size28* StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred(void)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bc6c0).
  auto* node = static_cast<NodeIsnil21_Size28*>(operator_new(0x28));
  if (node != nullptr) {
    node->left = nullptr;
    node->parent = nullptr;
    node->right = nullptr;
    node->color = 1;
    node->isnil = 0;
  }
  return node;
}

// Scaffold alias
extern "C" NodeIsnil21_Size28* FUN_004088f0(void)
{
  return StdTree_BuynodeEmpty_Isnil21_Size0x28_Inferred();
}
