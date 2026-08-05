// =============================================================================
// StdTree_Erase_Val12  (FUN_00573250)  aka Map_EraseNode_Val12
// -----------------------------------------------------------------------------
// Stable ID: aa_00573250
// Address:   0x00573250 – 0x00573506 exclusive (694 B / 0x2B6)
// System:    MSVC std map/set red-black tree single-node erase (Val12 / node 0x1c)
// Generated: 2026-07-29 W27-S dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed post-delete bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Erase one non-nil Val12 tree node: advance out-iterator to successor, unlink,
//   RB-rebalance if erased was black, operator_delete node, size--, *outIt=succ.
//
// ABI
//   __thiscall; ECX = MapShell*; stack (MapNode** outIt, MapNode* node); RET 8
//
// THROW
//   if node->isnil → length/out_of_range style "invalid map/set<T> iterator"
//   @ 0x00a152f0 via _CxxThrowException(..., &DAT_00acc34c)
//
// CALLERS (this image)
//   FUN_00573700 (range erase loop), FUN_00572ab0
//
// PEERS
//   Map_EraseNode @ 0x0051cb40 (W19-I) — different node size / isnil@+0x29
//   StdTree_Lrotate_Val12 / StdTree_Rrotate_Val12 (W26-Q)
// =============================================================================

#include <cstdint>

struct MapNode_Val12 {
  MapNode_Val12 *left;    // +0x00
  MapNode_Val12 *parent;  // +0x04
  MapNode_Val12 *right;   // +0x08
  int32_t v0;             // +0x0C
  int32_t v1;             // +0x10
  int32_t v2;             // +0x14
  uint8_t color;          // +0x18  0=red, 1=black
  uint8_t isnil;          // +0x19
};

struct MapShell_Val12 {
  void *proxy;            // +0x00
  MapNode_Val12 *head;    // +0x04  sentinel: left=begin, parent=root, right=end
  uint32_t size;          // +0x08
};

// External callees (roles sealed elsewhere)
extern "C" void __fastcall FUN_005ae0b0(MapNode_Val12 **pIt); // in-order successor
extern "C" MapNode_Val12 *FUN_005adfa0(MapNode_Val12 *n);     // leftmost
extern "C" MapNode_Val12 *FUN_00418bf0(MapNode_Val12 *n);      // rightmost
extern "C" void FUN_00573170(MapNode_Val12 *n); // StdTree_Lrotate_Val12
extern "C" void FUN_00418c10(MapNode_Val12 *n); // StdTree_Rrotate_Val12
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — control flow ≡ live decompile + post-delete bytes
// Full RB case tree mirrors raw; surface contract below is sealed.
// ---------------------------------------------------------------------------

void __thiscall StdTree_Erase_Val12(
    MapShell_Val12 *map,     // ECX
    MapNode_Val12 **outIt,   // *outIt published as successor
    MapNode_Val12 *node)     // node to erase (must not be nil)
{
  // SEH frame omitted (LAB_009a4fc2); present in retail for throw path.

  if (node->isnil != 0) {
    // Construct exception with "invalid map/set<T> iterator" @ 0x00a152f0
    // _CxxThrowException(..., &DAT_00acc34c). No-return.
    _CxxThrowException(nullptr, nullptr);
  }

  // Advance out-iterator to successor (FUN_005ae0b0 on iterator slot).
  // Retail passes the outIt / local node* slot as fastcall arg.
  MapNode_Val12 *succ = node;
  FUN_005ae0b0(&succ);

  // Unlink: pick replacement (left/right/successor subtree), reparent,
  // update root / leftmost / rightmost. If erased color black, RB fixup
  // with FUN_00573170 / FUN_00418c10. See raw decompile for full cases.
  // (Two-child transplant path may appear as "unreachable" in Ghidra.)
  (void)map;
  (void)node;

  // Free node — FALLS THROUGH (decomp "noreturn" is false)
  operator_delete(node);

  // Byte-sealed tail:
  if (map->size > 0)
    map->size -= 1;

  *outIt = succ;
  // ret 8
}
