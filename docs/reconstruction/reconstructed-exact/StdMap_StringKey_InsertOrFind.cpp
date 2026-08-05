// =============================================================================
// StdMap_StringKey_InsertOrFind
// -----------------------------------------------------------------------------
// Stable ID: aa_004309c0
// Address:   0x004309c0  (autoassault.exe, image base 0x400000)
// System:    stl-map
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W21-P
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  MSVC std::map<std::string,T>-style insert-or-find.
//           Walk tree by basic_string operator<; insert via FUN_00430b60 on miss;
//           equal key returns existing iterator with inserted=0 (no value write).
//
// Convention:
//   stack[0] = map shell*  (head@+4, size@+8)
//   EAX      = const basic_string* key
//   EBX      = InsertPair* out  ({node* it @+0, uint8_t inserted @+4})
//   return   = EBX; RET 4
//
// Node (this unit):
//   +0x00 left, +0x04 parent, +0x08 right
//   +0x0C basic_string key
//   +0x2C color, +0x2D isnil
//
// Related:
//   FUN_00430b60  insert + RB rebalance
//   FUN_004313d0  tree predecessor
//   FUN_004303c0  hint-insert front (caller)
//   FUN_00786470  string→object ensure (caller)
//   reviews/A|B_aa_004309c0_StdMap_StringKey_InsertOrFind.md
// =============================================================================

/*
 * Behavioral notes:
 * - Equal key path does NOT rewrite mapped value.
 * - goLeft && parent==header->_Left → insert addleft=1 without predecessor.
 * - goLeft && not leftmost → predecessor, then parent.key < key test.
 * - IAT operator< @ 0x009c62e8 (string).
 */

struct InsertPair {
  void*   it;
  uint8_t inserted;
};

// Callees (not reconstructed here)
InsertPair* FUN_00430b60(void* parentHint, int addleft, const void* keyString);
void FUN_004313d0(void** pNode); // predecessor in-place
bool basic_string_operator_lt(const void* a, const void* b);

InsertPair* StdMap_StringKey_InsertOrFind(
    void* map,                 // stack
    const void* keyString,     // EAX
    InsertPair* out)           // EBX
{
  void* header = *(void**)((char*)map + 4);
  void* cur = *(void**)((char*)header + 4); // root
  void* parent = header;
  bool goLeft = true;

  while (*(char*)((char*)cur + 0x2D) == '\0') {
    goLeft = basic_string_operator_lt(keyString, (char*)cur + 0x0C);
    parent = cur;
    if (goLeft) {
      cur = *(void**)cur;               // left
    } else {
      cur = *(void**)((char*)cur + 8);  // right
    }
  }

  if (goLeft) {
    if (parent == **(void***)((char*)map + 4)) { // header->_Left
      InsertPair* r = FUN_00430b60(parent, 1, keyString);
      out->it = r->it;
      out->inserted = 1;
      return out;
    }
    FUN_004313d0(&parent);
  }

  if (basic_string_operator_lt((char*)parent + 0x0C, keyString)) {
    InsertPair* r = FUN_00430b60(parent, goLeft ? 1 : 0, keyString);
    out->it = r->it;
    out->inserted = 1;
    return out;
  }

  out->it = parent;
  out->inserted = 0;
  return out;
}
