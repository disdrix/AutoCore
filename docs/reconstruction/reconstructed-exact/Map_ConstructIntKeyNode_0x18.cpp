// =============================================================================
// Map_ConstructIntKeyNode_0x18
// -----------------------------------------------------------------------------
// Stable ID: aa_006173a0
// Address:   0x006173a0–0x006173de  (autoassault.exe, image base 0x400000)
// System:    std map/set node construction (int-key 0x18 family)
// Generated: 2026-07-29 W18-L dual A/B seal; supersedes scaffold FUN_006173a0.cpp
// Exactness: Behavior-preserving rewrite of decompiler + body bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Allocate and initialize one MSVC-style red-black tree node of size 0x18:
//   left/parent/right links, int key + int mapped, color byte, isnil=0.
//   Shared by Map_InsertNodeAndRebalance_IntKey and sibling insert cores.
//
// ABI: __stdcall five stack args; RET 0x14; returns MapNode18* in EAX (0 on OOM).
// Sole callee: operator_new.
//
// Dual: reviews/A|B_aa_006173a0_Map_ConstructIntKeyNode_0x18.md
// =============================================================================

#include <cstdint>
#include <new>

struct MapNode18 {
  MapNode18* left;     // +0x00
  MapNode18* parent;   // +0x04
  MapNode18* right;    // +0x08
  std::int32_t key;    // +0x0C
  std::int32_t mapped; // +0x10
  std::uint8_t color;  // +0x14  0=red, 1=black (convention from insert cores)
  std::uint8_t isnil;  // +0x15  0 = real node
  // +0x16..0x17 pad → size 0x18
};

struct IntPair {
  std::int32_t key;
  std::int32_t mapped;
};

// Ghidra: operator_new @ 0x00489892
extern "C" void* operator_new(std::size_t size);

extern "C" MapNode18* Map_ConstructIntKeyNode_0x18(
    MapNode18* left,
    MapNode18* parent,
    MapNode18* right,
    const IntPair* value,
    std::uint8_t color)
{
  MapNode18* node = static_cast<MapNode18*>(operator_new(0x18));
  if (node != nullptr) {
    node->left   = left;
    node->right  = right;
    node->parent = parent;
    node->key    = value->key;
    node->mapped = value->mapped;
    node->color  = color;
    node->isnil  = 0;
  }
  return node;
}

// Scaffold alias body (same CF):
// void FUN_006173a0(...) { ... operator_new(0x18); stores; }  // return in EAX
