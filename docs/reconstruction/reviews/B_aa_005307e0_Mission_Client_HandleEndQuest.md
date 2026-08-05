# Review B (skeptical / adversarial): `aa_005307e0` Mission_Client_HandleEndQuest

| Field | Value |
|---|---|
| **Stable ID** | `aa_005307e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual after RecvFailMission) |
| **Counterpart** | `reviews/A_aa_005307e0_Mission_Client_HandleEndQuest.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Verdict** | **accept-with-gaps** — teardown drain sealed; complete-only / always-drain / XP claims falsified |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Awards XP/credits itself | No `ComputeObjective*` / money add; presentation + hash teardown only | **Falsified** |
| 2 | Mission-complete UX only | Toast stem is **`"Failed"`**; complete path uses CompleteObjective `"Completed"` / `mission_complete_3` | **Falsified as complete-only** |
| 3 | Server-only | Client audio, toast, LogicUI, local hash free-list | **Falsified** |
| 4 | Same as FailMission kernel | FailMission only pushes vector + dirty bit; this unit erases hashes and shows toast | **Falsified (complementary)** |
| 5 | Always called after every FailMission | Patrol_Fn3 / Kill_Precheck / `0060e800` skip this unit | **Falsified** |
| 6 | Enqueues end-quest ids | Only drains `+0x564`; Notify owns push | **Falsified** |
| 7 | Removes only `+0x540` | Body also removes **`+0x544`**, objectives `+0x548`, pending `+0x55c`, blob `+0x530` | **Understated if only 540** |
| 8 | `this` unknown / not character | All four sites load character into ECX | **Sealed character thiscall** |
| 9 | Prior dual: “mission complete audio” primary product | Audio key is generic `gen_end_quest`; toast is Failed | **Corrected — not complete celebration** |
| 10 | LogicUI opcodes fully mapped | Values `0xd` / `0x30` sealed; product names open | **Overstated if claimed named** |
| 11 | `+0xd6c` means “failed mode” | Also gates GiveCredits floater; cleared at end of drain | **Overstated exclusive fail English** |
| 12 | Empty vector is no-op free | Still zeros vector triple + `+0xd6c/+0xd68` | **Attacked — always clears flags** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Character ECX + vector drain | **High** | Stuck active mission after S2C fail |
| Dual remove `+0x540/+0x544` | **High** | Ghost journal / duplicate grant |
| Objective strip `+0x548` / pending `+0x55c` | **High** CF | Orphan objectives |
| Blob destroy `+0x530` | **High** CF | Stale mission state blob |
| `"Failed"` toast + `gen_end_quest` | **High** | Wrong client fail feedback |
| Toast gate (`local` + `bVar4\|\|d6c==0`) | **High** | Silent fail or spam |
| LogicUI `0xd` / `0x30` product names | **Tentative** | Wrong journal refresh wire |
| `+0xd6c` product English | **Tentative** | Wrong suppress semantics |
| Skill type `0xe` product | **Tentative** | Mis-port skill scan |
| `FUN_004de9f0` / `FUN_0052d8b0` English | **Probable/Tentative** | Incomplete end state |
| Always-on after FailMission | **None** (false) | Implement drain only on Recv path wrongly |
| XP ownership | **None** (not here) | Double-award if ported into drain |

---

## 3. Cross-check against raw / live decompile / callers

Surviving facts after attack:

- Large multi-loop body (~276 clean lines) ≡ live decompile CF.
- RecvFailMission order **FailMission → this** is image-sealed (`0x0080b111` then `0x0080b11c`).
- HB `FUN_006508d0` same order when fail arm trips.
- EvaluatePendingObjectives calls this **after** CompleteObjective batch — drain only, not fail apply.
- Fourth site `0x0088640d`: `FailMission(DAT_00d1b6d8)` then `FUN_005307e0(DAT_00d1b6d8)`; containing function unbound in Ghidra.
- Clean scaffold does not invent reward math; residual FUN_* callees remain.

---

## 4. Surviving contract for AutoCore

```
// Character thiscall. Drains end-quest id vector filled by FailMissionNotify etc.
HandleEndQuest(char):
  i = 0
  loop:
    vec = char+0x564..+0x56c   // u32 begin/end/cap
    if empty or i >= count:
      free(begin); begin=end=cap=0
      char+0xd6c = 0; char+0xd68 = 0
      return
    missionId = begin[i]
    def = activeHash(char+0x540).find(missionId)  // payload
    if def:
      hash_remove(char+0x540, missionId)
      hash_remove(char+0x544, missionId)
      for each objective id on def (+0x130 / +0x13c):
        if char+0xd6c == 1:
          // optional skill type 0xe / positive float → LogicUI 0x30 + flag
        destroy_if_live(char+0x55c, objId)
        hash_remove(char+0x548, objId)
      hash_destroy_value(char+0x530, missionId)
      if local_player && (flag || char+0xd6c == 0):
        LogicUI type 0xd (missionId)
        toast "Failed " + title(def)
        play gen_end_quest
      FUN_004de9f0(); FUN_0052d8b0(char, 0, -1)
    i++

DO NOT implement in this unit:
  - FailMission push / dirty bit 0x10
  - XP / credits / medals / cargo strip
  - C2S or S2C 0x20B2
  - "Completed" / mission_complete_3 celebration (CompleteObjective)

CALLER ownership:
  - RecvFailMission / HB fail / site 0088640d: FailMission then this
  - EvaluatePendingObjectives: CompleteObjective* then this (drain)
  - Some FailMission callers never drain here
```

---

## 5. Contradictions / doc debt

| Source | Statement | This review |
|---|---|---|
| Prior A (2026-07-23) “mission complete audio” framing | Primary complete UX | **Corrected:** Failed toast + gen_end_quest; complete elsewhere |
| RecvFailMission dual “FUN_005307e0 dual unit open” | Gap | **This residual closes dual as unit** |
| FailMission dual “full toast in 005307e0” | Caller-owned | **Confirmed** for draining callers |
| `Documentation/MISSION_SYSTEM.md` “CleanupPendingState” | Name | Alias OK; prefer HandleEndQuest / drain role |
| Named_VOG_DEBUG_STOP alias | String-only scaffold | Debug lock strings only — not product |

---

## 6. Open questions

1. Writers of `char+0xd6c` / meaning vs credits floater.
2. LogicUI `0xd` / `0x30` consumer product names.
3. Skill class `0xe` identity.
4. Bound name for caller `0x0088640d`.
5. Runtime fail presentation timing vs journal UI refresh (`RecvFailMission` vtbl tail).

**Verdict:** Accept drain + dual-hash + Failed presentation contract; reject complete-only / always-drain / XP ownership. **accept-with-gaps** on UI English + `+0xd6c` + runtime.
