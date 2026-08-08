// =============================================================================
// Object_EnsureIntKeyMapAt0x15c_Inferred  (Ghidra: FUN_005190c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005190c0
// Address:   0x005190c0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / object map ensure (req aggregate)
// Generated: 2026-08-04 WQ9R-E dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Lazy-ensure an empty int-key tree/map header at host+0x15C.
//   Used by skill/item requirement aggregation (FUN_0052d450) and UI gate
//   (FUN_0089a260) with Map_LowerBoundFindByIntKey + FUN_0040ed60 inserts.
//
// ABI:
//   __fastcall / __thiscall: ECX = host*. Returns map* in EAX.
//   Body 0x005190c0..0x00519146 exclusive (134 B). SEH LAB_009a363c.
//   Epilogue: ADD ESP,0x10; RET (C3).
//
// MAP HOST (0xC):
//   +0x00  not written by this unit
//   +0x04  myhead (sentinel TreeNode*)
//   +0x08  size (0 after create)
//
// SENTINEL (FUN_0040f400 → new 0x18):
//   left/parent/right self-linked; is_nil at +0x15 = 1 after ensure.
//
// TEARDOWN: Object_SharedBase_Dtor (0x00518ec0) frees host+0x15C.
// =============================================================================

#include <cstdint>

struct TreeNode_Isnil15 {
  TreeNode_Isnil15 *left;    // +0x00
  TreeNode_Isnil15 *parent;  // +0x04
  TreeNode_Isnil15 *right;   // +0x08
  // +0x0C..+0x13 payload / color
  // +0x14 color-ish (FUN_0040f400 stamps +0x14)
  std::uint8_t is_nil;       // +0x15  (ensure forces 1)
};

struct IntKeyMapHeader_0C {
  std::uint32_t unused0;     // +0x00 not written here
  TreeNode_Isnil15 *myhead;  // +0x04
  std::uint32_t size;        // +0x08
};

// External (not owned by this dual):
extern "C" void *operator_new(std::uint32_t size);
extern "C" TreeNode_Isnil15 *FUN_0040f400(void); // alloc 0x18 sentinel skeleton

extern "C" IntKeyMapHeader_0C *__fastcall
Object_EnsureIntKeyMapAt0x15c_Inferred(void *host /* ECX */)
{
  IntKeyMapHeader_0C **slot =
      reinterpret_cast<IntKeyMapHeader_0C **>(
          reinterpret_cast<char *>(host) + 0x15c);

  if (*slot == nullptr) {
    // SEH frame active around new (LAB_009a363c)
    auto *map = static_cast<IntKeyMapHeader_0C *>(operator_new(0x0C));
    if (map == nullptr) {
      *slot = nullptr;
    } else {
      TreeNode_Isnil15 *sentinel = FUN_0040f400();
      map->myhead = sentinel;
      sentinel->is_nil = 1;
      // self-link parent / left / right to sentinel
      sentinel->parent = sentinel;
      sentinel->left = sentinel;
      sentinel->right = sentinel;
      map->size = 0;
      *slot = map;
    }
  }
  return *slot;
}

// Ghidra twin name
extern "C" IntKeyMapHeader_0C *__fastcall FUN_005190c0(void *host)
{
  return Object_EnsureIntKeyMapAt0x15c_Inferred(host);
}
