# Review B (skeptical / adversarial): `aa_004d3ef0` CVOGMission_EvalActiveObjectiveInteractState

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3ef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d3ef0_CVOGMission_EvalActiveObjectiveInteractState.md` |
| **Verdict** | **needs-more-evidence** on type-3 / field names; **accept** on return CF |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Return 4 means “not related” | **Falsified by plate/body** — 4 is fallthrough when **no pending objective hit**; 0 is the “wrong target / filter fail” path |
| 2 | Checks **active** mission hash only | **Falsified** — pending hash `+0x55c`, not active mission `+0x540` |
| 3 | Type 3 is proven “continent objective” | **Unproven** — magic 3 + field compare only |
| 4 | Empty evaluator array means incomplete | **Falsified** — empty jumps to complete code **8** |
| 5 | Walks all objectives always | **Partial** — returns early on first pending hit branch (does not merge multi-obj) |
| 6 | Plate “ready for turn-in” sealed | **Probable story** — CF says all evals true; UI meaning external |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Codes 0/4/5/8 exist | High | Wrong icon matrix |
| Pending +0x55c | High | Looking at wrong journal set |
| First matching pending objective wins | High | Multi-obj missions mis-iconed |
| Type-3 filter semantics | Tentative | False 0 on valid targets |
| Param_1/2/3 role names | Probable | Wrong object wiring |

---

## 3. Cross-check against raw

```
for each mission objective:
  pendingState = lookup(char+0x55c, objId)
  if pendingState:
    if no evaluators: code = 8
    else:
      allOk = true; related = true
      for each eval:
        if vcall+0x50()==3 && eval+0x18 != targetContinentId: related=false
        if !vcall+0xc(char, pendingState): allOk=false
      return related ? (allOk?8:5) : 0
return 4
```

Clean preserves. Note inner hash walk after type probe may be dead work for match (id already known) — decompiler artifact.

---

## 4. Surviving contract for AutoCore

```
EvalActiveObjectiveInteractState(missionDef, targetObject, character) -> {0,4,5,8}
  scan mission objectives against character pending set
  8 = pending + all requirement evals true (or no evals)
  5 = pending + some req false
  0 = pending but target filter failed
  4 = no pending objective for this mission on this pass
```

Do not map 4 to “unrelated mission” without outer caller context.

---

## 5. Open questions

1. Seal evaluator type enum and continent fields.
2. Callers mapping codes → icons / cursor.
3. Multi-objective missions: which objective “wins.”
4. Live interact icon capture for pending complete vs incomplete.

**Verdict:** Accept return-code CF; attack plate “4 = active only” simplification and type-3 naming.
