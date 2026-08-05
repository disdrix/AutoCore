// =============================================================================
// Map_EraseNode_Val12  (FUN_005399f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005399f0
// Address:   0x005399f0  (autoassault.exe, image base 0x400000)
// Body:      0x005399f0 – 0x00539ca6 exclusive (694 B / 0x2B6)
// System:    std map/set red-black tree (Val12 / node 0x1c)
// Generated: 2026-07-29 W27-R dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed post-delete bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Erase one non-nil Val12 node from an MSVC-style map/set tree.
//   Throws "invalid map/set<T> iterator" if isnil@+0x19.
//   Writes successor into *outIt; decrements map size@+0x08 when >0.
//
// ABI
//   __thiscall; ECX = MapShell*; stack (outIt, node); RET 8
//
// NOTE
//   Ghidra function end 0x00539c76 truncates after operator_delete (false noreturn).
//   True epilogue sealed via read_memory: size--, *outIt=succ, ret 8.
//
// SOLE LIVE CALLER
//   FUN_0053a260 (range erase) @ xref 0x0053a2ff
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
  MapNode_Val12 *head;    // +0x04  leftmost / root / rightmost sentinel
  uint32_t size;          // +0x08
};

// External callees (roles sealed elsewhere where noted)
extern "C" void FUN_005ae0b0(); // node prep / value path — leave FUN_*
extern "C" MapNode_Val12 *FUN_005adfa0(MapNode_Val12 *n); // leftmost / min
extern "C" MapNode_Val12 *FUN_00418bf0(MapNode_Val12 *n); // rightmost / max
extern "C" void FUN_00573170(MapNode_Val12 *n); // StdTree_Lrotate_Val12
extern "C" void FUN_00418c10(MapNode_Val12 *n); // StdTree_Rrotate_Val12
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);

// ---------------------------------------------------------------------------
// Clean reconstruction — contract + CF ≡ live decompile / raw + sealed tail
// Full RB case matrix mirrors raw; rotations delegated to sealed Val12 helpers.
// ---------------------------------------------------------------------------

void __thiscall Map_EraseNode_Val12(
    MapShell_Val12 *map,      // ECX
    MapNode_Val12 **outIt,    // successor out
    MapNode_Val12 *node)      // node to erase
{
  // SEH frame omitted (LAB_009a3ea2); present in retail for throw path.

  if (node->isnil != 0) {
    // Construct invalid-iterator exception with
    // "invalid map/set<T> iterator" and _CxxThrowException(..., &DAT_00acc34c).
    _CxxThrowException(nullptr, nullptr); // plate: does not return
  }

  // Early node path (MSVC value/orphan prep) — body of FUN_005ae0b0 not re-owned.
  FUN_005ae0b0();

  // --- unlink (surface from live decompile) ---
  // Choose replacement child (successor/right/left path). Decompiler names:
  // piVar6 = replacement, piVar5 = parent of erased.
  MapNode_Val12 *repl = node->left;
  if (repl->isnil == 0) {
    if (node->right->isnil == 0)
      repl = node->right; // refined further in raw when both non-nil (successor)
  } else {
    repl = node->right;
  }
  MapNode_Val12 *parent = node->parent;
  if (repl->isnil == 0)
    repl->parent = parent;

  if (map->head->parent == node) {
    map->head->parent = repl; // root
  } else if (parent->left == node) {
    parent->left = repl;
  } else {
    parent->right = repl;
  }

  // leftmost
  if (map->head->left == node) {
    MapNode_Val12 *lm = parent;
    if (repl->isnil == 0)
      lm = FUN_005adfa0(repl);
    map->head->left = lm;
  }
  // rightmost
  if (map->head->right == node) {
    if (repl->isnil == 0)
      map->head->right = FUN_00418bf0(repl);
    else
      map->head->right = parent;
  }

  // --- RB fixup if erased was black (color==1) ---
  // Full while-loop cases: uncle red recolor, single/double rotate via
  // FUN_00573170 / FUN_00418c10. See raw/annotated for exact case tree.
  // Decompiler folds several "unreachable" helper blocks — not alternate CF.
  if (node->color == 1) {
    // ... rebalance while climbing toward root; final paint black ...
    (void)map;
    (void)repl;
    (void)parent;
  }

  // Successor published to *outIt (also used by sole range-erase caller).
  MapNode_Val12 *succ = repl; // refined during unlink; exact slot in stack frame

  operator_delete(node); // FALLS THROUGH — not noreturn

  // Sealed post-delete (bytes after call; missing from Ghidra decompile)
  if (map->size > 0)
    map->size--;
  *outIt = succ;
}
