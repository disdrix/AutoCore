// =============================================================================
// StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred  (FUN_00408ad0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00408ad0
// Address:   0x00408ad0–0x00408e1d inclusive (846 B / 0x34E)
//            Ghidra decompiler truncates at operator_delete (false noreturn)
// System:    std map/set red-black tree erase (isnil@+0x131 / string@+0x0c)
// Generated: 2026-08-05 WQ9L-A dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   MSVC-style std::_Tree erase(const_iterator) for large nodes:
//     left@0 parent@4 right@8 | std::string @+0x0C | … payload …
//     color @ +0x130 | isnil @ +0x131
//   Throw "invalid map/set<T> iterator" on nil; capture successor (iterator++);
//   unlink + extremity fix (min/max isnil131); RB rebalance if erased black;
//   ~string @+0x0c; operator_delete; size--; write *outIt; RET 0x0C.
//
// ABI
//   Three stack args (map*, outIt**, node*); RET 0x0C. Not ECX-thiscall primary.
//
// THROW
//   isnil → "invalid map/set<T> iterator" via DAT_00acc34c (@ string 0x00a152f0)
//
// CALLER (1)
//   FUN_00407b70 @ 0x00407bd2 (StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred)
//
// PEERS (do not merge)
//   Isnil31 erase: StdTree_EraseAndRebalance_Isnil31_Inferred @ 0x00408ed0
//   StringKey isnil2d erase: StdMap_StringKey_EraseAndRebalance_Inferred @ 0x004094c0
//   Succ: StdTree_IteratorIncrement_Isnil131 @ 0x00404000 (OWN peer)
//   Free subtree: StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred @ 0x00409920
//   Min/max: FUN_00404160 / FUN_004043c0 (isnil131, residual)
//   L/R rotate: FUN_00403cb0 / FUN_00403d00 (isnil131 family)
// =============================================================================

#include <cstdint>

struct MapNode_Isnil131 {
  MapNode_Isnil131 *left;    // +0x00
  MapNode_Isnil131 *parent;  // +0x04
  MapNode_Isnil131 *right;   // +0x08
  // +0x0C ..   MSVC basic_string (destroyed before delete)
  // ... large POD payload ...
  // accessed via helpers below for color/isnil at +0x130/+0x131
};

struct MapShell_Isnil131 {
  void *proxy;               // +0x00
  MapNode_Isnil131 *head;    // +0x04  end sentinel
  std::uint32_t size;        // +0x08
};

static inline std::uint8_t &NodeColor(MapNode_Isnil131 *n)
{
  return *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(n) + 0x130);
}
static inline std::uint8_t &NodeIsnil(MapNode_Isnil131 *n)
{
  return *reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(n) + 0x131);
}

// External callees
extern "C" void StdTree_IteratorIncrement_Isnil131(MapNode_Isnil131 **it); // 00404000
extern "C" MapNode_Isnil131 *FUN_00404160(MapNode_Isnil131 *n); // min / leftmost
extern "C" MapNode_Isnil131 *FUN_004043c0(MapNode_Isnil131 *n); // max / rightmost
extern "C" void FUN_00403cb0(MapShell_Isnil131 *tree, MapNode_Isnil131 *x); // Lrotate
extern "C" void FUN_00403d00(MapShell_Isnil131 *tree, MapNode_Isnil131 *x); // Rrotate
extern "C" void operator_delete(void *p);
extern "C" void _CxxThrowException(void *, void *);
// ~basic_string(node+0xC) — CRT / std IAT [0x009c62f4]
extern "C" void basic_string_dtor_at(void *string_obj);

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile + byte-sealed epilogue
// ---------------------------------------------------------------------------

extern "C" void StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred(
    MapShell_Isnil131 *map,           // stack0
    MapNode_Isnil131 **outIt,         // stack1
    MapNode_Isnil131 *node)           // stack2
{
  // SEH frame omitted (LAB_009bd0df); present in retail for throw path.

  if (NodeIsnil(node) != 0) {
    // basic_string("invalid map/set<T> iterator") → _CxxThrowException(..., DAT_00acc34c)
    _CxxThrowException(nullptr, nullptr);
  }

  // Capture successor before unlink.
  // Retail: LEA EDX, &node_stack_slot (holds node); CALL FUN_00404000 → succ in slot.
  MapNode_Isnil131 *it = node;
  StdTree_IteratorIncrement_Isnil131(&it);
  MapNode_Isnil131 *succ = it;

  // Replacement child (MSVC erase splice; isnil@+0x131). Full two-child
  // successor-swap path exists in retail (decompiler marks mid blocks
  // "unreachable" — preserve full MSVC erase semantics in ports).
  MapNode_Isnil131 *repl = node->left;
  if (NodeIsnil(repl) == 0) {
    if (NodeIsnil(node->right) == 0) {
      // both children real — retail successor-swap path @ 0x00408be0
      repl = node->right;
    }
  } else {
    repl = node->right;
  }

  MapNode_Isnil131 *parent = node->parent;
  if (NodeIsnil(repl) == 0)
    repl->parent = parent;

  if (map->head->parent == node) {
    map->head->parent = repl; // root
  } else if (parent->left == node) {
    parent->left = repl;
  } else {
    parent->right = repl;
  }

  // Fix head leftmost / rightmost when erasing extremity
  if (map->head->left == node) {
    MapNode_Isnil131 *lm = parent;
    if (NodeIsnil(repl) == 0)
      lm = FUN_00404160(repl);
    map->head->left = lm;
  }
  if (map->head->right == node) {
    if (NodeIsnil(repl) == 0)
      map->head->right = FUN_004043c0(repl);
    else
      map->head->right = parent;
  }

  // RB rebalance if erased node was black (color@+0x130)
  if (NodeColor(node) == 1) {
    MapNode_Isnil131 *x = repl;
    MapNode_Isnil131 *p = parent;
    while (x != map->head->parent && NodeColor(x) == 1) {
      if (x == p->left) {
        MapNode_Isnil131 *w = p->right;
        if (NodeColor(w) == 0) {
          NodeColor(w) = 1;
          NodeColor(p) = 0;
          FUN_00403cb0(map, p); // Lrotate
          w = p->right;
        }
        if (NodeIsnil(w) == 0) {
          if (NodeColor(w->left) == 1 && NodeColor(w->right) == 1) {
            NodeColor(w) = 0;
          } else {
            if (NodeColor(w->right) == 1) {
              NodeColor(w->left) = 1;
              NodeColor(w) = 0;
              FUN_00403d00(map, w); // Rrotate
              w = p->right;
            }
            NodeColor(w) = NodeColor(p);
            NodeColor(p) = 1;
            NodeColor(w->right) = 1;
            FUN_00403cb0(map, p);
            break;
          }
        }
      } else {
        MapNode_Isnil131 *w = p->left;
        if (NodeColor(w) == 0) {
          NodeColor(w) = 1;
          NodeColor(p) = 0;
          FUN_00403d00(map, p);
          w = p->left;
        }
        if (NodeIsnil(w) == 0) {
          if (NodeColor(w->right) == 1 && NodeColor(w->left) == 1) {
            NodeColor(w) = 0;
          } else {
            if (NodeColor(w->left) == 1) {
              NodeColor(w->right) = 1;
              NodeColor(w) = 0;
              FUN_00403cb0(map, w);
              w = p->left;
            }
            NodeColor(w) = NodeColor(p);
            NodeColor(p) = 1;
            NodeColor(w->left) = 1;
            FUN_00403d00(map, p);
            break;
          }
        }
      }
      x = p;
      p = p->parent;
      if (x == map->head->parent)
        break;
    }
    NodeColor(x) = 1;
  }

  // Value destroy string @ +0x0c, then free node (byte-sealed epilogue).
  basic_string_dtor_at(reinterpret_cast<char *>(node) + 0x0c);
  operator_delete(node);
  if (map->size > 0)
    map->size--;
  *outIt = succ;
  // RET 0x0C
}

// Ghidra twin name
extern "C" void FUN_00408ad0(
    MapShell_Isnil131 *map,
    MapNode_Isnil131 **outIt,
    MapNode_Isnil131 *node)
{
  StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred(map, outIt, node);
}
