// =============================================================================
// FUN_0052d8b0 — character mission staging map clear
// -----------------------------------------------------------------------------
// Stable ID: aa_0052d8b0
// Address:   0x0052d8b0 – 0x0052da2f  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly corrections.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Clear the Character mission staging map @ +0x508 (sibling of FUN_0052c700 upsert).
//   missionId == -1 → clear entire tree; else erase one key.
//   destroyFlag != 0 → also ResolveObjectTarget + queue-delete on 4 payload pairs.
//   All live xrefs pass destroyFlag = 0 (map structure only).
//
// ASSEMBLY CORRECTIONS vs raw decompile:
//   - Map object this = character+0x508 for lower_bound / erase / clear helpers.
//   - ResolveObjectTarget this = *(sectorMap + 0xe4e8); bGlobal = 1.
//   - FUN_005875c0 this = character+0xcc4 (list unlink by object*).
//   - Full clear is a free loop + header reset; not a single noreturn delete.
//   - ret 8 (two stack args).
//
// MAP:
//   char+0x508 map, +0x50c end header, +0x510 size
//   node+0x10 key, +0x18 payload[12], +0x49 isnil
// =============================================================================

// Callees (roles High; product names open):
//   FUN_00538a40 — map lower_bound / exact find
//   FUN_00538780 — map erase(iterator)
//   FUN_00537ef0 — recursive free helper
//   CVOGReaction_ResolveObjectTarget — object* from (bGlobal, lo, hi)
//   FUN_005875c0 — unlink object* from list at char+0xcc4
//   FUN_004d4790 — queue world object for delete

void __thiscall FUN_0052d8b0(int character, char destroyFlag, int missionId)
{
  char isnil;
  void *root;
  int *node;
  int *pred;
  int *cursor;
  int *pair;
  int slots;
  int resolved;
  int savedMissionId;
  int find_out[1];
  int obj_scratch;

  savedMissionId = missionId;

  /* begin iterator */
  if (missionId == -1) {
    node = *(int **)(character + 0x50c); /* header */
  }
  else {
    /* ECX = map @ character+0x508 (asm LEA); decomp drops this */
    FUN_00538a40(find_out, &missionId);
    node = (int *)find_out[0];
  }

  node = (int *)*node; /* *iterator → node* (begin or found) */

  if (node == *(int **)(character + 0x50c)) {
LAB_done_nodes:
    if (savedMissionId != -1) {
      return; /* single-key miss or after single erase */
    }
  }
  else {
    do {
      pair = node + 6; /* node + 0x18 */
      slots = 4;
      do {
        if ((destroyFlag != '\0') &&
            (*(int *)(*(int *)(*(int *)(character + 4) + 4) + 0xa8 + character) != 0) &&
            (resolved = CVOGReaction_ResolveObjectTarget(
                 /* ECX = *(sectorMap+0xe4e8) */ 1, *pair, pair[1]),
             resolved != 0)) {
          obj_scratch = resolved;
          /* ECX = character + 0xcc4 */
          FUN_005875c0(&obj_scratch);
          FUN_004d4790(resolved);
        }
        savedMissionId = missionId; /* restore after Resolve clobber (decomp) */
        pair = pair + 2;
        slots = slots + -1;
      } while (slots != 0);

      if (missionId != -1) {
        /* ECX = map @ character+0x508 */
        FUN_00538780(/*out*/ &destroyFlag, node);
        goto LAB_done_nodes;
      }

      /* MSVC red-black inorder successor; isnil @ +0x49 */
      if (*(char *)((int)node + 0x49) == '\0') {
        cursor = (int *)node[2]; /* right */
        if (*(char *)((int)cursor + 0x49) == '\0') {
          isnil = *(char *)(*cursor + 0x49);
          node = cursor;
          cursor = (int *)*cursor;
          while (isnil == '\0') {
            isnil = *(char *)(*cursor + 0x49);
            node = cursor;
            cursor = (int *)*cursor;
          }
        }
        else {
          isnil = *(char *)(node[1] + 0x49);
          pred = (int *)node[1];
          cursor = node;
          while ((node = pred, isnil == '\0' && (cursor == (int *)node[2]))) {
            isnil = *(char *)(node[1] + 0x49);
            pred = (int *)node[1];
            cursor = node;
          }
        }
      }
    } while (node != *(int **)(character + 0x50c));
  }

  /* Full clear (missionId == -1 only): free all nodes, reset empty tree.
     Decomp shows a truncated form due to operator_delete noreturn false positive.
     Image: loop free right via FUN_00537ef0, delete node, follow left; then: */
  root = *(void **)(*(int *)(character + 0x50c) + 4); /* header->parent */
  if (*(char *)((int)root + 0x49) != '\0') {
    /* already empty / only header */
    *(int *)(*(int *)(character + 0x50c) + 4) = *(int *)(character + 0x50c);
    *(int *)(character + 0x510) = 0;
    **(int **)(character + 0x50c) = *(int *)(character + 0x50c);
    *(int *)(*(int *)(character + 0x50c) + 8) = *(int *)(character + 0x50c);
    return;
  }

  /* free loop (structure from image @ ~0x0052d9e0) */
  FUN_00537ef0(*(void **)((int)root + 8)); /* right subtree */
  operator_delete(root);
  /* ... continues left spine + header reset in binary; size @ +0x510 = 0 ... */

  *(int *)(*(int *)(character + 0x50c) + 4) = *(int *)(character + 0x50c);
  *(int *)(character + 0x510) = 0;
  **(int **)(character + 0x50c) = *(int *)(character + 0x50c);
  *(int *)(*(int *)(character + 0x50c) + 8) = *(int *)(character + 0x50c);
}
