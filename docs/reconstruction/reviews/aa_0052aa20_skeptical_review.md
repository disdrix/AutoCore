# Skeptical / adversarial review: `CVOGCharacter_HasCompletedMission` @ `0x0052aa20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052aa20` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Completed-mission predicate interpretation |
| **Verdict** | **needs-more-evidence** |

---

## 1. Inspected artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` | Authoritative decompile |
| `docs/reconstruction/raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.annotated.md` | Scaffold copy |
| `docs/reconstruction/reconstructed-exact/CVOGCharacter_HasCompletedMission.cpp` | Clean |
| `docs/reconstruction/functions/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` | Status |
| `docs/reconstruction/systems/missions-progression.md` | Hash layout claims |
| `raw/aa_005462b0_…` / `raw/aa_005327c0_…` | Shared mode gate + hash usage |

**Not performed:** Assembly of the compound condition; CE completed-mission inject; callee body of `WeaponAllowsKillXpBonus`.

---

## 2. Evidence used

### A. Body (raw)

Two-phase structure:

1. **Fast path:** if entity-relative pointer at `+0xa8` is 0 → `return lookup(this+0x538, id) != null`.
2. **Slow path:** interact with global mission table (`FUN_0053fff0`), compare something at `+0xfc`, call mode flag twice, consult `+0x538` and/or `+0x53c`.

### B. Plate claim

> True if missionId is in completed-mission hash (char+0x538) or instance-completed (+0x53c) with continent match.

### C. Cross-unit

GiveMission and HasCompletedMission both treat `WeaponAllowsKillXpBonus` as a switch between `+0x538` and `+0x53c` policies — strengthens “mode flag,” weakens “weapon XP” naming.

---

## 3. Attack results

### Claim 1 — Simple OR of two hashes

| Sub-claim | Attack result |
|-----------|----------------|
| Always true if either hash hits | **Falsified** — fast path never touches `+0x53c`; slow path gates `+0x53c` on mode flag; long compound condition can force `+0x538` true only under failure of table/continent/mode conditions |
| Plate “or instance-completed” | **Oversimplified** |

### Claim 2 — Continent match is required

| Sub-claim | Attack result |
|-----------|----------------|
| `+0xfc` compared between looked-up mission object and context object | **Not broken** as a comparison existing in CF |
| Field is continent id | **Unproven** (name is story) |
| Match required for all true returns | **Falsified** — fast path has no `+0xfc` compare; some true returns from `+0x538` under the big condition when continent/table checks *fail* |

### Claim 3 — `WeaponAllowsKillXpBonus` describes the gate

| Sub-claim | Attack result |
|-----------|----------------|
| Literal weapon/XP meaning | **Attack succeeds against name** — no weapon math in this function; dual use as mode selector across mission units |
| Binary side effect / return used as branch | **Not broken** |

### Claim 4 — Function is pure / side-effect free

| Sub-claim | Attack result |
|-----------|----------------|
| No stores in body | **Not broken** |
| Callees pure | **Unknown** — `WeaponAllowsKillXpBonus` and hash lookup may have side effects; not proven pure |

### Claim 5 — Fast path null `+0xa8` means “not in instance world”

| Sub-claim | Attack result |
|-----------|----------------|
| Null → only global completed hash | **Not broken** as CF |
| Semantic “not instanced” | **Unproven** — could be unloaded continent, pre-init, or different subsystem |

### Claim 6 — Clean / annotated seal the unit

| Sub-claim | Attack result |
|-----------|----------------|
| Clean ≡ raw | **Not broken** |
| Annotated adds machine-level recovery | **Fails** — spaced copy only |
| Ready for parity tests without further RE | **Overclaim** |

---

## 4. Alternate interpretations

### Minimal reading

```
bool HasCompletedMission(Character* c, uint id) {
  if (get_context(c) == null)
    return hash_has(c->completed_538, id);
  // else: combination of def-table presence, field 0xfc equality,
  // mode flag, completed_538, instance_53c
}
```

### Competing stories for mode flag

1. Instance vs open-world progression bit  
2. Client authority / “full character” vs limited  
3. Actually weapon-related in other modes (unlikely here)  
4. Mis-applied Ghidra name from another vtable slot  

None selected by this body alone.

---

## 5. Confirmed despite skepticism

1. Two top-level shapes: null-context fast path vs non-null slow path.  
2. Lookups on `+0x538` and conditionally `+0x53c`.  
3. Involvement of global mission table and a `+0xfc` integer compare on slow path.  
4. Bool return only.  
5. Used as prereq oracle from CheckMissionRequirements.  
6. Clean matches raw CF.

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Full boolean truth table of slow path | **Yes** |
| R2 | Identity of `+0xa8` object | **Yes** |
| R3 | Identity of `+0xfc` | **Yes** for “continent” word |
| R4 | Mode flag real function | **Yes** |
| R5 | Side effects in callees | Medium |
| R6 | Runtime completed-set population | **Yes** for port parity |

---

## 7. Concrete checks performed

1. Split fast vs slow path from raw without plate.  
2. Attacked “simple OR of two hashes” plate summary.  
3. Noted true returns that do **not** require continent match.  
4. Correlated mode-flag dual-hash pattern with GiveMission.  
5. Verified clean introduces no CF changes.  
6. Confirmed annotated is not independent evidence.

---

## 8. Verdict

### **`needs-more-evidence`**

**Why:** Core plate simplification (completed OR instance + continent) does not survive full CF attack. Body is coherent but under-specified; mode flag and `+0xfc`/`+0xa8` identities are open.

**Why not needs-revision:** No clear internal contradiction that forces a clean rewrite; clean tracks decompile. Revision of *comments/names* is desirable but the decompile CF itself is not shown wrong.

**Why not accept-with-gaps (package):** Accepting the plate wording as sealed would mis-state when instance hash and continent apply.

**Bar for stronger verdict:**

1. Expand slow-path truth table (preferably with short-circuit call order).  
2. Type the `+0xa8` object and `+0xfc` field from producers/consumers.  
3. Re-symbol or decompile the mode flag function.  
4. Runtime: mark mission complete in each hash; observe predicate under null/non-null context.

**Final verdict: `needs-more-evidence`**
