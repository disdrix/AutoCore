# Skeptical / adversarial review: `CVOGReaction_CompleteObjective` @ `0x00533f90`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533f90` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | Complete/advance objective unit and claims in plate / system map / XP.md |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** Claims that survive are those that survived attack, not restatement of the plate comment.

---

## 1. Inspected artifacts

### Primary unit artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_00533f90_CVOGReaction_CompleteObjective.md` | Immutable decompile |
| `docs/reconstruction/raw/aa_00533f90_CVOGReaction_CompleteObjective.annotated.md` | Notes (System missions-progression) |
| `docs/reconstruction/reconstructed-exact/CVOGReaction_CompleteObjective.cpp` | Human-refined clean |
| `docs/reconstruction/functions/aa_00533f90_CVOGReaction_CompleteObjective.md` | Status: Human-refined |
| `docs/reconstruction/systems/missions-progression.md` | System role |

### Cross-check / attack surfaces

| Path | Why |
|------|-----|
| `docs/missionState.md` | Hash layout, `0x2070` force complete, dialog turn-in |
| `docs/XP.md` | Mission XP only on final; AddExperience non-kill |
| `raw/aa_00536080_*` | Bulk complete call arity vs thiscall |
| `raw/aa_00533c30_*` | AddExperience callee |
| `raw/aa_005327c0_*` | GiveMission chain |

**Not performed:** Fresh Ghidra re-decompile, CE complete/advance exercise, callee body recovery for insert/retire helpers.

---

## 2. Evidence used

### A. Authoritative body (raw)

Mechanical structure:

1. Hash lookup of objective; optional GiveMission chain on miss.
2. Pending requirement vtable walk with force bypass.
3. Hard split advance vs final on sequence vs count.
4. Final rewards gated on completed-hash miss.
5. UI + dual completed-hash maintenance + auto-mission search.
6. Returns only `0` or `1`.

### B. Plate / system claims under attack

- “Finish or advance an objective/mission on the local character”
- Active hash at “char+0x152” (plate) vs byte `+0x548`
- Dialog turn-in runs locally — do not also send `0x2070`
- Final: XP/credits/medals/inventory “local player only”
- Advance: skill/attrib only, no XP/credits

### C. Negative evidence

- Many callees still `FUN_*`.
- Annotated is not independent recovery of CF.
- No runtime of advance, final, force, or re-complete.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — Function advances or completes an objective

| Sub-claim | Attack result |
|-----------|----------------|
| Body branches on sequence vs count-1 | **Not broken** |
| Advance never calls `AddExperience` | **Not broken** (no call on advance path) |
| Final always awards XP | **Overstated** — final rewards only if completed-hash lookup is null; already-completed skip reward block |

### Claim 2 — Active objectives at `char+0x152`

| Sub-claim | Attack result |
|-----------|----------------|
| Decompiler uses `param_1[0x152]` | **Not broken** |
| Byte offset is `0x152` | **Falsified** — `int*` index → `0x152*4 = 0x548` |
| Clean maps to `+0x548` | **Not broken** (corrects plate ambiguity) |

### Claim 3 — “Local player only” for rewards

| Sub-claim | Attack result |
|-----------|----------------|
| Inventory rewards under flag `+0x7e != 0` | **Not broken** |
| XP/credits also gated by same flag | **Falsified as blanket claim** — XP/credits run in final block without that flag check; only inventory (and later SearchAutoMissions) check `+0x7e` |
| Missing-obj path: non-local early out | **Plate may be wrong** — raw returns `0` when flag **is** set; GiveMission chain runs when flag is **clear**. Competing interpretation: flag means local, and local cannot synthesize GiveMission from bare complete |

### Claim 4 — `forceComplete` skips all validation

| Sub-claim | Attack result |
|-----------|----------------|
| Skips individual req eval failures | **Not broken** |
| Skips min-pass gate | **Not broken** when force non-zero |
| Skips mission def / hash existence | **Falsified** — null def still returns 0 |

### Claim 5 — Dialog turn-in must not send `0x2070`

| Sub-claim | Attack result |
|-----------|----------------|
| Present in plate / missionState | Narrative / prior RE |
| Proven by this body alone | **Not proven** — body has no packet send for complete; claim is architectural from other units |

### Claim 6 — Clean is port-ready sealed reconstruction

| Sub-claim | Attack result |
|-----------|----------------|
| CF-faithful refined comments | **Not broken** |
| Ready-to-port with all callees typed | **Overclaim** — FUN_* surface large; record correctly says open |

### Claim 7 — Skill/attrib helpers named correctly

| Sub-claim | Attack result |
|-----------|----------------|
| Calls exist with `+0x6ce` / `+0x6cc` inputs | **Not broken** |
| Names match pools written | **Unproven** — possible swap of skill vs attrib pool vs grant fields |

---

## 4. Alternate interpretations

### Minimal hard-to-attack reading

```
lookup active objective by id
if missing:
  if flag_7e: return fail
  else maybe GiveMission(parent) from objective def
evaluate pending requirements (force may bypass)
if not last sequence:
  activate next objective; skill/attrib; dirty; return ok
if mission not already completed:
  skill/attrib; XP; credits; medals; maybe inventory
UI toast if primary local entity
ensure completed hashes; retire active; maybe pending re-eval
if flag_7e: SearchAutoMissions
dirty; return ok
```

### Competing stories not ruled out

1. Client prediction / UI-only complete vs full authority.
2. Flag `+0x7e` = local player, AI, or “authority for side effects” with inverted missing-obj policy.
3. GiveMission chain is for remote/party mirror, not solo local play.
4. `pCompletedOrNext` dual use (completed hit vs next-obj hit) could confuse readers into thinking advance checks completed set.

---

## 5. What was confirmed despite skepticism

1. Advance vs final sequence split and goto dirty-only on advance.
2. No `AddExperience` on advance path.
3. Final XP uses non-kill path + mission bias global.
4. Hash dword indices consistent with missionState byte offsets ×4.
5. Clean ≡ raw CF (refined fidelity).
6. Function record does not claim bit-for-bit or runtime seal.

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Callee map for insert / retire / min-pass / medal helpers | Yes for behavioral port |
| R2 | Flag `+0x7e` polarity and missing-obj policy | Yes |
| R3 | Skill vs attribute pool naming | Yes for point economy |
| R4 | Reward table `this[0x14c]` layout | Yes for inventory rewards |
| R5 | Dialog / `0x2070` protocol story | Yes for netcode |
| R6 | Runtime advance / re-complete / force paths | Yes |
| R7 | EvaluatePendingObjectives float-cast args | Mild (ABI slot reuse) |

---

## 7. Concrete checks performed

1. Re-derived advance/final and reward gates from raw alone.
2. Compared clean to raw for invented/missing calls (none material).
3. Cross-checked hash dword indices against missionState byte offsets.
4. Attacked “local only” for XP/credits vs inventory.
5. Attacked plate `+0x152` as byte offset.
6. Correlated mission XP claims with XP.md and final-only call site.
7. Confirmed function record does not claim completion/runtime seal.

**Not done:** re-decompile, CE, callee recovery.

---

## 8. Verdict

### **`needs-more-evidence`**

**Why not accept-with-gaps (for *interpretation package*):**  
Clean fidelity is strong, but several plate/system claims (local-only rewards, missing-obj non-local story, sealed skill/attrib naming, protocol “don’t send 0x2070”) are partially falsified or external. Accepting the full narrative package would launder uncertain prose.

**Why not needs-revision:**  
No evidence that filed raw CF is wrong; clean matches it. Revision means deeper callee/flag recovery, not rewriting a broken CF.

**Bar for stronger verdict:**

1. Resolve `+0x7e` with multi-caller / assembly context.
2. Map `FUN_0053c360` / `FUN_00538b20` / `FUN_00538bd0` / `FUN_0059d880`.
3. Confirm skill/attrib helper bodies vs pools.
4. Runtime: advance, final, force=1, already-completed re-entry.
5. Keep protocol claims tied to packet handlers, not this unit alone.

**Final verdict: `needs-more-evidence`**
