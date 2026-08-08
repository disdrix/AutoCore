// =============================================================================
// FUN_005190c0  — twin of Object_EnsureIntKeyMapAt0x15c_Inferred
// Stable ID: aa_005190c0 | VA: 0x005190c0
// See: Object_EnsureIntKeyMapAt0x15c_Inferred.cpp
// =============================================================================

#include <cstdint>

struct TreeNode_Isnil15 {
  TreeNode_Isnil15 *left;
  TreeNode_Isnil15 *parent;
  TreeNode_Isnil15 *right;
  std::uint8_t is_nil_pad[5];
  std::uint8_t is_nil; // +0x15
};

struct IntKeyMapHeader_0C {
  std::uint32_t unused0;
  TreeNode_Isnil15 *myhead;
  std::uint32_t size;
};

extern "C" void *operator_new(std::uint32_t size);
extern "C" TreeNode_Isnil15 *FUN_0040f400(void);

extern "C" IntKeyMapHeader_0C *__fastcall FUN_005190c0(void *host /* ECX */)
{
  IntKeyMapHeader_0C **slot =
      reinterpret_cast<IntKeyMapHeader_0C **>(
          reinterpret_cast<char *>(host) + 0x15c);

  if (*slot == nullptr) {
    auto *map = static_cast<IntKeyMapHeader_0C *>(operator_new(0x0C));
    if (map == nullptr) {
      *slot = nullptr;
    } else {
      TreeNode_Isnil15 *sentinel = FUN_0040f400();
      map->myhead = sentinel;
      sentinel->is_nil = 1;
      sentinel->parent = sentinel;
      sentinel->left = sentinel;
      sentinel->right = sentinel;
      map->size = 0;
      *slot = map;
    }
  }
  return *slot;
}
