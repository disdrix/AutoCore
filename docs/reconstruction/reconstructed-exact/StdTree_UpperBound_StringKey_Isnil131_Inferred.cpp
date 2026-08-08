// =============================================================================
// StdTree_UpperBound_StringKey_Isnil131_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00403d60
// Address:   0x00403d60–0x00403da6  (71 B / 0x47)  autoassault.exe base 0x400000
// System:    skills-abilities / shared client::stdtree (isnil@+0x131 string-key map)
// Generated: 2026-08-05 R10-020 OWN dual (scaffold FUN_00403d60 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * PURPOSE
 *   MSVC ordered-tree upper_bound for maps whose nodes carry:
 *     +0x00 left, +0x04 parent, +0x08 right,
 *     +0x0C std::string key,
 *     +0x131 isnil (0 = live node).
 *
 *   Returns first node with key < node.key (strictly greater than key), or head/end().
 *
 * ABI (assembly-sealed)
 *   EAX  = map*   (_Myhead at map+4; end() == head)
 *   stack = const std::string* key
 *   EAX out = node* candidate
 *   RET 4
 *
 * Callee: std::operator<(string,string) via IAT 0x009c62e8 (cdecl ADD ESP,8).
 *   Push order: node.key then key → operator<(key, node.key).
 *
 * Callers (2 UNCONDITIONAL_CALL):
 *   FUN_00957820 @ 0x0095797a / 0x00957c6b — slash help range [lb, ub)
 *     pairs with twin lower_bound 0x00403c60, then iterator++ 0x00404000.
 *
 * Family:
 *   twin lower_bound StdTree_LowerBound_StringKey_Isnil131_Inferred 0x00403c60
 *   StdTree_IteratorIncrement_Isnil131 0x00404000
 *   StdTree_EraseAndRebalance_Isnil131_* / StdMap_EraseRange_Isnil131_*
 *
 * Distinct from:
 *   lower_bound twin 0x00403c60  (operator<(node.key, key); true→right)
 *   Map_LowerBoundFindByCharKey 0x00402210  (isnil@+0x21, char key, thiscall RET 8)
 *   Map_LowerBoundFindByIntKey / isnil31 peers
 */

#include <stdint.h>

/* Opaque map shell: only +4 (_Myhead) used here. */
/* Node: left@0 parent@4 right@8 string@0xC isnil@0x131. */

typedef struct StdTreeNode_Isnil131 {
  struct StdTreeNode_Isnil131 *left;    /* +0x00 */
  struct StdTreeNode_Isnil131 *parent;  /* +0x04 */
  struct StdTreeNode_Isnil131 *right;   /* +0x08 */
  /* +0x0C: std::string key (MSVC SSO layout; not modeled field-by-field) */
  /* ... payload ... */
  /* +0x131: char isnil */
} StdTreeNode_Isnil131;

typedef struct StdTreeMap_Isnil131 {
  uint32_t _pad0;                       /* +0x00 (allocator / empty-base gap) */
  StdTreeNode_Isnil131 *_Myhead;        /* +0x04 */
} StdTreeMap_Isnil131;

/* Declared only for readability — body calls IAT operator<. */
extern int __cdecl std_string_operator_less(const void *a, const void *b);

/*
 * Register convention: map in EAX on entry (not ECX thiscall).
 * Modeled as first parameter for C readability; port must match EAX-in.
 */
StdTreeNode_Isnil131 *StdTree_UpperBound_StringKey_Isnil131_Inferred(
    StdTreeMap_Isnil131 *map /*EAX*/,
    const void *key /*stack std::string* */)
{
  StdTreeNode_Isnil131 *head;
  StdTreeNode_Isnil131 *cur;
  StdTreeNode_Isnil131 *cand;
  const char *key_bytes;

  head = map->_Myhead;
  cur  = head->parent;                  /* root */
  cand = head;                          /* end() */

  if (*(const char *)((const char *)cur + 0x131) != '\0') {
    return cand;
  }

  do {
    key_bytes = (const char *)cur + 0x0C;
    /* operator<(key, node.key) — true → cand=cur, go left (upper_bound) */
    if (std_string_operator_less(key, key_bytes)) {
      cand = cur;
      cur  = cur->left;
    } else {
      cur  = cur->right;
    }
  } while (*(const char *)((const char *)cur + 0x131) == '\0');

  return cand;
}
