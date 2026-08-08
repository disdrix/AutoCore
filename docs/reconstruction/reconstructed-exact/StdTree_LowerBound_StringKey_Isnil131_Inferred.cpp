// =============================================================================
// StdTree_LowerBound_StringKey_Isnil131_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00403c60
// Address:   0x00403c60–0x00403ca6  (71 B / 0x47)  autoassault.exe base 0x400000
// System:    skills-abilities / shared client::stdtree (isnil@+0x131 string-key map)
// Generated: 2026-08-05 MEGA-041 OWN dual (scaffold 2026-07-23 retired Named_CalleeOf_*)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * PURPOSE
 *   MSVC ordered-tree lower_bound for maps whose nodes carry:
 *     +0x00 left, +0x04 parent, +0x08 right,
 *     +0x0C std::string key,
 *     +0x131 isnil (0 = live node).
 *
 * ABI (assembly-sealed)
 *   EAX  = map*   (_Myhead at map+4; end() == head)
 *   stack = const std::string* key
 *   EAX out = node* candidate (first !(node.key < key), or head)
 *   RET 4
 *
 * Callee: std::operator<(string,string) via IAT 0x009c62e8 (cdecl ADD ESP,8).
 *
 * Callers (3 UNCONDITIONAL_CALL):
 *   FUN_0093bd10 @ 0x0093bdfa  — slash-command dispatch (LEA EAX,[client+4])
 *   FUN_00957820 @ 0x0095798a / 0x00957c7b — slash help range [lb, ub]
 *
 * Family:
 *   twin upper_bound FUN_00403d60
 *   StdTree_IteratorIncrement_Isnil131 0x00404000
 *   StdTree_EraseAndRebalance_Isnil131_* / StdMap_EraseRange_Isnil131_*
 *
 * Distinct from:
 *   Map_LowerBoundFindByCharKey 0x00402210  (isnil@+0x21, char key, thiscall RET 8)
 *   Map_LowerBoundFindByIntKey / isnil31 lower_bound peers
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
StdTreeNode_Isnil131 *StdTree_LowerBound_StringKey_Isnil131_Inferred(
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
    /* operator<(node.key, *key) — true → go right */
    if (std_string_operator_less(key_bytes, key)) {
      cur = cur->right;
    } else {
      cand = cur;
      cur  = cur->left;
    }
  } while (*(const char *)((const char *)cur + 0x131) == '\0');

  return cand;
}
