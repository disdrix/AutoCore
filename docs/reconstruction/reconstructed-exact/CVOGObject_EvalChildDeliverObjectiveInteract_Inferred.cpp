// =============================================================================
// CVOGObject_EvalChildDeliverObjectiveInteract_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3ba0
// Address:   0x004d3ba0 - 0x004d3ee2  (autoassault.exe, image base 0x400000)
// Size:      835 bytes (0x343)
// System:    interaction-activation / missions interact glue
// Generated: 2026-08-05 MEGA-069 OWN dual (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: OPEN (no Launcher).
//
// ABI (sealed by disassemble_function + read_memory + parent call sites):
//   __thiscall, ECX = host (parent this/EDI), two stack args, RET 8 (C2 08 00).
//   ECX is LIVE: used as this+0xe4e8 for CVOGReaction_ResolveObjectTarget.
//   Contrast sibling 004d2e50 where parent MOV ECX is dead.
//
// Returns (AL):
//   0 — no qualifying deliver target / empty child vector / type gate fail
//   4 — matching world object action present but action+0x138 == 0
//   5 — matching action with requirements that fail (type-3 continent or pred)
//   8 — matching action with all requirements satisfied (or empty req vector)
//
// Sole parent: CVOGObject_EvalInteractStateFromChildren (0x004d7640)
//   on child type 0x25; max-aggregated with 004d2e50 and 004d5aa0 when state < 6.
//
// Ghidra: FUN_004d3ba0
// Retires: Named_VOG_DEBUG_STOP_004d3ba0 (VOG_DEBUG_STOP is hash-lock diagnostic only)
// =============================================================================

// External callees (names as dualed / Ghidra)
// void*  FUN_0040fb90();                              // local list ctor
// void   FUN_00403430(void* list);                    // list dtor
// void*  FUN_004e0eb0();                              // empty-vector fallback
// void*  CVOGReaction_ResolveObjectTarget(void* mgr, uint a, uint b); // 0x004bae70
// void*  CNDHash_LookupByKey(void* hash, uint key);   // 0x005b0920
// void   FUN_007a4480(int, const char*);              // HashError / VOG_DEBUG_STOP
// void   operator_delete(void*);                      // 0x00489822

char CVOGObject_EvalChildDeliverObjectiveInteract_Inferred(
    void *this_host,
    int child_reaction,
    int character)
{
  int npc_obj;
  bool continent_ok;
  bool pred_ok;
  char pred_result;
  unsigned *pair_begin;
  int *resolved;
  unsigned best_u;
  int hash_entry;
  int action;
  int *req_it;
  int req_type;
  void *lookup_entry;
  unsigned *hash_obj;
  byte best;
  int walk_node;
  /* local list: head @ local_14, count @ local_10; SEH frame present */

  best = 0;
  /* SEH: local_4 = -1; puStack_8 = &LAB_009a2059; ExceptionList = &frame */

  /* list ctor */
  /* local_14 = FUN_0040fb90(); local_10 = 0; */

  pair_begin = *(unsigned **)(child_reaction + 0x1d8);
  /* SEH state = 0 */
  if ((pair_begin != 0) &&
      (*(int *)(child_reaction + 0x1dc) - (int)pair_begin >> 3 != 0)) {
    if ((pair_begin == 0) ||
        (*(int *)(child_reaction + 0x1dc) - (int)pair_begin >> 3 == 0)) {
      pair_begin = (unsigned *)FUN_004e0eb0();
    }
    /* this_host+0xe4e8 is reaction manager; stdcall args: 0, pair[0], pair[1] */
    resolved = (int *)CVOGReaction_ResolveObjectTarget(
        *(void **)((char *)this_host + 0xe4e8),
        pair_begin[0],
        pair_begin[1]);
    if (resolved != 0) {
      /* vcall resolved->vtbl[+0x124](&local_list) fills list; count in local_10 */
      (**(void (**)(void *))(*resolved + 0x124))(/* &local_list */);
      if (/* local_10 != 0 */ 1) {
        npc_obj = *(int *)(*(int *)/*local_14*/ 0 + 8);
        if (*(int *)(*(int *)(npc_obj + 0xa8) + 0x38) == 0x12) {
          /* ---- locked traverse character object hash @ +0x540 ---- */
          {
            int hash = *(int *)(character + 0x540);
            walk_node = 0;
            if (*(char *)(hash + 0x1d) != '\0') {
              FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
              FUN_007a4480(0, "VOG_DEBUG_STOP");
            }
            *(unsigned char *)(hash + 0x1d) = 1;
          }

LAB_traverse:
          do {
            do {
              do {
                {
                  int hash = *(int *)(character + 0x540);
                  if (*(char *)(hash + 0x1d) == '\0') {
                    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
                    FUN_007a4480(0, "VOG_DEBUG_STOP");
                  }
                  if (walk_node == 0) {
                    walk_node = *(int *)(hash + 0x14);
                    if (walk_node == 0) goto LAB_null_obj;
                    hash_obj = *(unsigned **)(walk_node + 8);
                  } else {
                    walk_node = *(int *)(walk_node + 0x14);
                    if (walk_node == 0) {
LAB_null_obj:
                      hash_obj = 0;
                    } else {
                      hash_obj = *(unsigned **)(walk_node + 8);
                    }
                  }
                }
                if (hash_obj == 0) {
                  /* unlock + free resolved list + return best */
                  *(unsigned char *)(*(int *)(character + 0x540) + 0x1d) = 0;
                  /* free list nodes via operator_delete loop; dtor head */
                  return (char)best;
                }
                /* character+0x530 bucket walk by *hash_obj key */
                {
                  int table = *(int *)(character + 0x530);
                  hash_entry = *(int *)(*(int *)(*(int *)(table + 0x10) +
                      (*(unsigned *)(table + 8) & *hash_obj) * 4) + 4);
                  if (hash_entry == 0) {
                    hash_entry = 0;
                  } else {
                    do {
                      if (*hash_obj == *(unsigned *)(hash_entry + 0x10)) {
                        if (hash_entry == 0) {
                          hash_entry = 0;
                          break;
                        }
                        hash_entry = *(int *)(hash_entry + 8);
                        break;
                      }
                      hash_entry = *(int *)(hash_entry + 0xc);
                    } while (hash_entry != 0);
                    if (hash_entry == 0)
                      hash_entry = 0;
                  }
                }
              } while (hash_entry == 0);

              best_u = *(unsigned *)(hash_entry + 0x20);
              if (best_u == 0xffffffff)
                best_u = hash_obj[0x22]; /* +0x88 */
            } while (best_u != *(unsigned *)(*(int *)(npc_obj + 0xa8) + 0x34));

            best_u = *(unsigned *)(hash_entry + 0x24);
            if (best_u == 0xffffffff)
              best_u = hash_obj[0x3f]; /* +0xfc */
          } while ((best_u != *(unsigned *)(*(int *)(npc_obj + 0xa4) + 0xfc)) ||
                   ((unsigned char)hash_obj[0x4c] /* +0x130 */ == 0) ||
                   (action = *(int *)((hash_obj[0x4f] /* +0x13c */ - 4) +
                                      (unsigned)(unsigned char)hash_obj[0x4c] * 4),
                    action == 0));

          if (*(int *)(action + 0x138) == 0) {
            if (best < 5)
              best = 4;
            goto LAB_traverse;
          }

          req_it = *(int **)(action + 0x158);
          pred_ok = true;
          continent_ok = true;
          if (req_it != *(int **)(action + 0x15c)) {
            do {
              req_type = (**(int (**)(void))(*(int *)*req_it + 0x50))();
              if ((req_type == 3) &&
                  (*(int *)(*req_it + 0x18) !=
                   *(int *)(*(int *)(npc_obj + 0xa8) + 0x34))) {
                continent_ok = false;
              }
              lookup_entry = CNDHash_LookupByKey(
                  *(void **)(character + 0x55c),
                  *(unsigned *)(action + 0x10));
              if ((lookup_entry == 0) ||
                  (pred_result = (**(char (**)(int, void *))(*(int *)*req_it + 0xc))(
                       character, lookup_entry),
                   pred_result == '\0')) {
                pred_ok = false;
              }
              req_it = req_it + 1;
            } while (req_it != *(int **)(action + 0x15c));
            if ((!continent_ok) || (!pred_ok)) {
              if (best < 6)
                best = 5;
              goto LAB_traverse;
            }
          }
          if (best < 9)
            best = 8;
          goto LAB_traverse;
        }
      }
    }
  }

  /* early fail: dtor list, return 0 */
  FUN_00403430(/* &local_list */);
  return 0;
}
