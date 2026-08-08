// =============================================================================
// CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2e50
// Address:   0x004d2e50 - 0x004d319e  (autoassault.exe, image base 0x400000)
// Size:      847 bytes (0x34F)
// System:    interaction-activation / missions interact glue
// Generated: 2026-08-05 MEGA-068 OWN dual (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: OPEN (no Launcher).
//
// ABI (sealed by disassemble_function + read_memory + parent call sites):
//   __stdcall, two stack args, RET 8 (C2 08 00) at three exits.
//   Parent CVOGObject_EvalInteractStateFromChildren loads ECX before CALL;
//   this body does not use ECX as this.
//
// Returns (AL):
//   0 — no matching interact state
//   3 — completed-mission residual flag after child mission-id walk
//   6 — offerable/active interact (mission[+0x169] == 0)
//   7 — offerable/active interact (mission[+0x169] != 0)
//
// Ghidra: FUN_004d2e50
// Retires: Named_VOG_DEBUG_STOP_004d2e50 / Mission_VOG_DEBUG_STOP_004d2e50
//          (VOG_DEBUG_STOP is hash-lock diagnostic only)
// =============================================================================

// External callees (names as dualed / Ghidra)
// void*  FUN_0053fff0();  // Mission_EnsureRegionMissions host @ DAT_00b041fc
// bool   CVOGCharacter_HasCompletedMission(void* character, unsigned missionId);
// int    CVOGCharacter_CheckMissionRequirements(void* missionDef, void* character);
// void   FUN_00547920(int);
// void   FUN_00402c40(void* hash);  // TraversalLock set +0x1d
// void   FUN_007a4480(int, const char*);

char CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred(
    int child_reaction,
    int *character)
{
  unsigned mission_id;
  unsigned *filter_end;
  bool completed_flag;
  bool has_completed;
  int *host_ptr;
  unsigned *active_mission;
  void *completed_mission;
  int node;
  unsigned *filter_it;
  unsigned idx;
  int walk_count;
  int walk_node;
  /* decompiler residual on CheckMissionRequirements third arg — asm is thiscall + 1 stack */

  completed_flag = false;

  /* ---- Path A: child mission-id vector [+0x244, +0x248) ---- */
  if ((*(int *)(child_reaction + 0x244) != 0) &&
      (*(int *)(child_reaction + 0x248) - *(int *)(child_reaction + 0x244) >> 2 != 0)) {
    idx = 0;
    while ((node = *(int *)(child_reaction + 0x244), node != 0 &&
           (idx < (unsigned)(*(int *)(child_reaction + 0x248) - node >> 2)))) {
      int id_off = idx * 4;
      mission_id = *(unsigned *)(node + id_off);
      host_ptr = (int *)FUN_0053fff0();
      node = *host_ptr;
      if (node == 0) {
        active_mission = (unsigned *)0x0;
LAB_active_or_completed:
        has_completed = CVOGCharacter_HasCompletedMission(
            character, *(unsigned *)(*(int *)(child_reaction + 0x244) + id_off));
        if (!has_completed) goto LAB_try_active_req;
        mission_id = *(unsigned *)(*(int *)(child_reaction + 0x244) + id_off);
        /* character completed-mission hash @ +0x538 */
        node = *(int *)(*(int *)(*(int *)(character[0x14e] + 0x10) +
                                (*(unsigned *)(character[0x14e] + 8) & mission_id) * 4) + 4);
        if (node == 0) {
LAB_completed_null:
          completed_mission = (void *)0x0;
        } else {
          do {
            if (mission_id == *(unsigned *)(node + 0x10)) {
              if (node == 0) goto LAB_completed_null;
              completed_mission = *(void **)(node + 8);
              goto LAB_completed_found;
            }
            node = *(int *)(node + 0xc);
          } while (node != 0);
          completed_mission = (void *)0x0;
        }
LAB_completed_found:
        if ((*(short *)((int)completed_mission + 0xac) == 0) ||
            (node = CVOGCharacter_CheckMissionRequirements(completed_mission, character),
             node != 0))
          goto LAB_next_id;
        completed_flag = true;
        idx = idx + 1;
      } else {
        /* hash lookup mission_id in region host */
        node = *(int *)(*(int *)(*(int *)(node + 0x10) + (*(unsigned *)(node + 8) & mission_id) * 4) + 4);
        if (node == 0) {
LAB_active_null:
          active_mission = (unsigned *)0x0;
        } else {
          do {
            if (mission_id == *(unsigned *)(node + 0x10)) {
              if (node == 0) goto LAB_active_null;
              active_mission = *(unsigned **)(node + 8);
              goto LAB_active_found;
            }
            node = *(int *)(node + 0xc);
          } while (node != 0);
          active_mission = (unsigned *)0x0;
        }
LAB_active_found:
        /* short[+0xac] == -1 → treat as active-tracked mission */
        if ((active_mission == (unsigned *)0x0) || ((short)active_mission[0x2b] != -1))
          goto LAB_active_or_completed;
LAB_try_active_req:
        if ((active_mission != (unsigned *)0x0) &&
            (node = CVOGCharacter_CheckMissionRequirements(active_mission, character),
             node == 0))
          goto LAB_return_6_7;
LAB_next_id:
        idx = idx + 1;
      }
    }
LAB_return_flag:
    if (!completed_flag) {
      return '\0';
    }
    return '\x03';
  }

  /* ---- Path B: child byte-filter vector [+0x234, +0x238) ---- */
  if ((*(int *)(child_reaction + 0x234) != 0) &&
      (*(int *)(child_reaction + 0x238) - *(int *)(child_reaction + 0x234) >> 2 != 0)) {
    node = character[0x150]; /* hash @ character+0x540 */
    walk_count = 0;
    walk_node = 0;
    if (*(char *)(node + 0x1d) != '\0') {
      FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(unsigned char *)(node + 0x1d) = 1;
    do {
      node = character[0x150];
      if (*(char *)(node + 0x1d) == '\0') {
        FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
      }
      if (walk_node == 0) {
        walk_node = *(int *)(node + 0x14);
      } else {
        walk_node = *(int *)(walk_node + 0x14);
      }
      if (walk_node == 0) {
        node = 0;
      } else {
        node = *(int *)(walk_node + 8);
      }
      if (node == 0) {
        *(unsigned char *)(character[0x150] + 0x1d) = 0;
        node = 0;
        FUN_0053fff0();
        FUN_00402c40();
        while (1) {
          host_ptr = (int *)FUN_0053fff0();
          walk_node = *host_ptr;
          if (*(char *)(walk_node + 0x1d) == '\0') {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
          }
          if (node == 0) {
            node = *(int *)(walk_node + 0x14);
          } else {
            node = *(int *)(node + 0x14);
          }
          if (node == 0) {
            active_mission = (unsigned *)0x0;
          } else {
            active_mission = *(unsigned **)(node + 8);
          }
          if (active_mission == (unsigned *)0x0) break;
          filter_end = *(unsigned **)(child_reaction + 0x238);
          filter_it = *(unsigned **)(child_reaction + 0x234);
          if (filter_it != filter_end) {
            do {
              if (*filter_it == (unsigned)*(unsigned char *)((int)active_mission + 0x86)) break;
              filter_it = filter_it + 1;
            } while (filter_it != filter_end);
            if ((filter_it != filter_end) &&
                (walk_node = CVOGCharacter_CheckMissionRequirements(active_mission, character),
                 walk_node == 0)) {
              completed_flag = CVOGCharacter_HasCompletedMission(character, *active_mission);
              if (!completed_flag) {
                host_ptr = (int *)FUN_0053fff0();
                *(unsigned char *)(*host_ptr + 0x1d) = 0;
LAB_return_6_7:
                FUN_00547920(0);
                return (*(char *)((int)active_mission + 0x169) != '\0') + '\x06';
              }
              completed_flag = true;
            }
          }
        }
        host_ptr = (int *)FUN_0053fff0();
        *(unsigned char *)(*host_ptr + 0x1d) = 0;
        goto LAB_return_flag;
      }
    } while ((*(short *)(node + 0xac) == 0) || (walk_count = walk_count + 1, walk_count < 8));
    *(unsigned char *)(character[0x150] + 0x1d) = 0;
  }
  return '\0';
}
