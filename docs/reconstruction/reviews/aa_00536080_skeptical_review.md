# Skeptical / adversarial review: `CVOGCharacter_CompleteMissionObjectives` @ `0x00536080`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536080` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Bulk complete-objectives helper interpretation |
| **Verdict** | **needs-more-evidence** |

---

## 1. Inspected artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` | Authoritative decompile |
| `docs/reconstruction/raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.annotated.md` | Scaffold copy |
| `docs/reconstruction/reconstructed-exact/CVOGCharacter_CompleteMissionObjectives.cpp` | Clean |
| `docs/reconstruction/functions/aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` | Status |
| `docs/reconstruction/systems/missions-progression.md` | Role claim |
| `raw/aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` | Caller with reason `1` |

**Not performed:** Decompile of `CVOGReaction_CompleteObjective`; runtime bulk complete; array layout proof beyond this loop.

---

## 2. Evidence used

### A. Body

```c
// pseudocode shape
table = FUN_0053fff0();
if (*table && (def = lookup(*table, id))) {
  for i in 0 .. byte(def+0x130)-1:
    CompleteObjective(*( *(def+0x13c)[i] + 0x10 ), -1, -1, uReason);
  return 1;
}
return 0;
```

### B. Plate claims under attack

- “Completes all objectives for a given mission”
- Algorithm bullet implying reason constant `0xffffffff` for CompleteObjective
- Returns 1 if completed, 0 if not found

---

## 3. Attack results

### Claim 1 — Function completes the mission

| Sub-claim | Attack result |
|-----------|----------------|
| Directly marks mission complete / moves to completed hash | **Not shown** — body only calls per-objective CompleteObjective; mission-level completion is callee side effect if any |
| “CompleteMissionObjectives” name implies mission done | **Name inflation risk** — may only force objectives; mission wrap-up unknown here |

### Claim 2 — All objectives always completed successfully

| Sub-claim | Attack result |
|-----------|----------------|
| Loop visits every index in `0..count-1` | **Not broken** |
| Each CompleteObjective succeeds | **Unproven** — return ignored |
| Count field trusted | **Trust decompile** — no alternate length check |

### Claim 3 — Reason parameter is `0xffffffff`

| Sub-claim | Attack result |
|-----------|----------------|
| Plate algorithm line “with reason 0xffffffff” | **Contradicted by body** — 2nd/3rd args are `0xffffffff`; **4th is `uReason`** (callers use `1` from prerequisites) |
| Clean matches body | **Yes** — plate bullet is the weak link |

### Claim 4 — Return 1 means objectives were completed

| Sub-claim | Attack result |
|-----------|----------------|
| Return 1 iff def found | **Not broken** |
| Return 1 implies count>0 work done | **Falsified** — count 0 still returns 1 |
| Return 0 only “not found” | **Not broken** |

### Claim 5 — `__cdecl` static on CVOGCharacter

| Sub-claim | Attack result |
|-----------|----------------|
| No `this` in signature | **Not broken** in decompile |
| Class membership / static | **Naming only** — could be free function with plate name |

### Claim 6 — System map “bulk complete” is sealed end-to-end

| Sub-claim | Attack result |
|-----------|----------------|
| This unit is a bulk loop | **Not broken** |
| Full progression effect sealed | **Fails** without CompleteObjective + reward/UI path |

---

## 4. Alternate interpretations

1. **Force-fail/succeed objectives for auto-chain** (prerequisites path reason `1`) rather than player “turn-in.”  
2. **Admin / script complete** helper.  
3. **Silent bulk** with reason distinguishing reward grant vs no-reward.

None ruled out.

---

## 5. Confirmed despite skepticism

1. Mission def lookup via shared `FUN_0053fff0` table.  
2. Objectives count byte `+0x130`, pointer array `+0x13c`.  
3. Per-objective id at `+0x10` on objective object.  
4. Four-arg CompleteObjective call with two `0xffffffff` immediates + pass-through reason.  
5. Binary return found/not-found (not per-objective status).  
6. Clean ≡ raw.

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | CompleteObjective semantics / args | **Yes** |
| R2 | Meaning of `uReason` values (e.g. `1`) | **Yes** |
| R3 | Whether mission completed hash is updated | **Yes** for name |
| R4 | Empty list success meaning | Medium |
| R5 | Array element type | Medium |
| R6 | Runtime | **Yes** |

---

## 7. Concrete checks performed

1. Mapped loop bounds and pointer arithmetic from raw.  
2. Compared plate “reason 0xffffffff” to actual 4-arg call — found mismatch.  
3. Checked return on zero-count path.  
4. Noted ignored CompleteObjective results.  
5. Correlated caller reason `1` from prerequisites unit.  
6. Verified clean did not invent filtering or status aggregation.

---

## 8. Verdict

### **`needs-more-evidence`**

**Why:** Unit is a thin loop; almost all behavioral meaning lives in `CompleteObjective` and reason codes. Plate oversells “mission completed” and misstates where `0xffffffff` applies.

**Why not needs-revision:** Filed clean matches raw; no CF bug to rewrite. Plate comments should be tightened when artifacts are refined (out of scope for this review’s file edits).

**Bar for stronger verdict:**

1. Capture/decompile `CVOGReaction_CompleteObjective`.  
2. Enumerate `uReason` values from callers.  
3. Observe completed-hash / UI after bulk complete.  
4. Fix plate algorithm wording (reason vs fixed -1 args).

**Final verdict: `needs-more-evidence`**
