# Review B (skeptical / adversarial): `aa_006508d0` CVOGHBMissionEscort_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_006508d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ7R-H) |
| **Counterpart** | `reviews/A_aa_006508d0_CVOGHBMissionEscort_OnHeartBeat.md` |
| **Scratch** | `tmp/a_006508d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is `CVOGHBOutpost` (string "outpost" nearby) | RTTI is **MissionEscort**; Outpost RTTI separate @`0x00af5134`; string is adjacent litter | **Falsified as Outpost** |
| 2 | This is Patrol HB | Next vtable block is Patrol (`COL 0x00ab1ee4` → `CVOGHBMissionPatrol`); this block is Escort | **Falsified** |
| 3 | Static call graph empty ⇒ dead code | Invoked via TryFire virtual; DATA bind live | **Falsified as dead** |
| 4 | Always CompleteObjective | Only `bComplete` arm; lost fails; else reschedules | **Overstated** |
| 5 | FailMission always drains | This site **does** call `FUN_005307e0` (unlike Patrol_Fn3) | **Sealed drain YES** |
| 6 | force=1 means skip all validation | Matches CompleteObjective dual force flag; exact skip set is sibling unit | **Probable / not overclaimed** |
| 7 | DAT_00af514c is a period ms timer | TryFire dual: value **16** is **EHBStatus Remove**, not combat period | **Sealed as status** |
| 8 | Name needs `_Inferred` | RTTI + OnHeartBeat slot are High | **Name accepted** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Escort OnHeartBeat identity | **High** | Wrong HB class port |
| Complete / Fail arm polarity | **High** | AutoCore escort ends wrong |
| Drain after fail | **High** | Stuck end-quest list / active mission |
| TFID scan match modes | **Probable** | Wrong target reacquire |
| Distance thresholds product | **Tentative** | Too-tight/loose fail |
| Runtime | **Open** | |

---

## 3. Surviving contract for AutoCore

```
OnHeartBeat(escortHb, &status) -> &status
  char = dyn_cast_character(owner)
  if !char: status = Remove(16); return
  node = activeObjectives(char+0x548).lookup(missionKey)
  target = resolve_escort_tfid(hb)   // may scan char TFID list
  if lost(node/target/range):
    if node: FailMission(missionId); HandleEndQuest()
    if target: mark_destroy(target)
    status = Remove(16); return
  if in_complete_zone(...):
    CompleteObjective(missionKey, -1, -1, force=1)
    maybe mark_destroy(target)
  else:
    RescheduleAfterFire(hb)
  status = Remove(16)  // or leave as reschedule path sets
  return &status
```

---

## 4. Gaps that block full accept

1. Field dictionary for escort max distance + complete-zone object pair.
2. Confirm Ghidra `CVOGHBBase` field overlay vs true Escort subclass layout size.
3. Runtime escort fail/complete capture.

**Verdict:** **accept-with-gaps**.
