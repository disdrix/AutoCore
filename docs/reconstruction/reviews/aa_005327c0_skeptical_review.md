# Skeptical / adversarial review: `CVOGReaction_GiveMission` @ `0x005327c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005327c0` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | Grant-mission unit and claims in plate comments / system map |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** Claims that survive are those that survived attack, not restatement of the plate comment.

---

## 1. Inspected artifacts

### Primary unit artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_005327c0_CVOGReaction_GiveMission.md` | Immutable decompile |
| `docs/reconstruction/raw/aa_005327c0_CVOGReaction_GiveMission.annotated.md` | Scaffold notes (no independent recovery) |
| `docs/reconstruction/reconstructed-exact/CVOGReaction_GiveMission.cpp` | Clean scaffold |
| `docs/reconstruction/functions/aa_005327c0_CVOGReaction_GiveMission.md` | Status: Partial scaffold |
| `docs/reconstruction/systems/missions-progression.md` | System role / data-flow claims |

### Cross-check / attack surfaces

| Path | Why |
|------|-----|
| `raw/aa_00531b00_CVOGMission_AddActiveObjective.md` | Call arity vs sibling signature |
| `raw/aa_00532b60_CVOGCharacter_SearchAutoMissions.md` (via grep/system map) | Caller of GiveMission |
| `raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` | Parallel use of `+0x538`/`+0x53c` and `WeaponAllowsKillXpBonus` |
| Sibling mission units | Shared hash layout narrative |

**Not performed:** Fresh Ghidra re-decompile, CE grant exercise, callee body recovery for `FUN_0053c360` / insert helpers.

---

## 2. Evidence used

### A. Authoritative body (raw)

Mechanical structure from decompile alone:

1. Triple AND gate before any grant work (table, def, def-byte flag).
2. Nested early-outs for already-active mission, completed-set conflicts, and failed outer gates.
3. Objective activation attempt always followed by `UnlockContinentObject` using objective field `+0x120`.
4. Mission node construction: allocate `0x30`, optional 12-dword copy, two insert-related callees, optional UI toast/sound.
5. Returns `0` or `1` only (no other success codes in body).

### B. Plate / system claims under attack

- “Grant mission + toast”
- “inserts mission hash at char+0x540, objective at +0x548”
- “Server mirror: GiveMission reaction + OnMissionStateChanged (logic vars type 11)”
- “Does NOT open volume gates by itself”

### C. Negative evidence

- Annotated is a spaced copy of raw — not independent confirmation.
- Most callees still `FUN_*`.
- No runtime of toast, re-grant, or unlock side effects.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — Function grants a mission to the character

| Sub-claim | Attack result |
|-----------|----------------|
| Body performs work when def valid and not already active | **Not broken** (CF) |
| “Grant” = retail server authority | **BROKEN as client-only static claim** — this is client EXE decompile; server mirror is plate prose without body evidence |
| Always shows toast | **Falsified** — toast only when `*(short*)(puVar3+0x3e)==0` after insert path |

### Claim 2 — Active mission tracked at `char+0x540`, objectives at `+0x548`

| Sub-claim | Attack result |
|-----------|----------------|
| Lookups use `param_1+0x540` and `+0x548` | **Not broken** |
| This function directly writes those hash roots | **Overstated** — inserts go through `FUN_0053c360` / `FUN_0053c660` / `AddActiveObjective` / `FUN_0053c460` chain; root pointers themselves are not assigned in-body |
| Offsets are Confirmed class layout | **Probable only** — consistent with system map + sibling units, not struct-proven |

### Claim 3 — `CVOGMission_AddActiveObjective` is always called with correct arity

| Sub-claim | Attack result |
|-----------|----------------|
| Call as decompiled: `AddActiveObjective(*piVar1)` | Present in raw/clean |
| Matches sibling `__thiscall (param_1, param_2)` | **BROKEN as sealed signature** — sibling requires two integers; call site shows one explicit arg. Either thiscall `this` is hidden/wrong, or one unit’s signature is mis-recovered |

**Severity:** High for porting the call edge; low for “some activation helper is invoked with objective pointer material.”

### Claim 4 — `WeaponAllowsKillXpBonus` is a weapon XP check here

| Sub-claim | Attack result |
|-----------|----------------|
| Name as semantic description of the gate | **Very likely wrong** — used as binary mode switch for which completed hash (`+0x538` vs `+0x53c`) matters, same pattern as `HasCompletedMission` |
| Gate exists and branches | **Not broken** |

### Claim 5 — UnlockContinentObject opens map/volume gates

| Sub-claim | Attack result |
|-----------|----------------|
| Function is called with objective `+0x120` value | **Not broken** |
| Plate: “Does NOT open volume gates by itself” | **Neither confirmed nor falsified** — body only shows the call; effect is in callee |
| Type-11 logic-var story | **Narrative only** in plate; no type-11 constant in body |

### Claim 6 — Clean is a refined reconstruction

| Sub-claim | Attack result |
|-----------|----------------|
| Behavior-preserving CF copy | **Not broken** |
| “Exact” / ready-to-port refined unit | **Overclaim vs function record** — record says Partial scaffold; clean is type-token rename of decompiler output |

### Claim 7 — Outer return `0` means “requirements failed”

| Sub-claim | Attack result |
|-----------|----------------|
| Return `0` when table/def/flag fail or already active early branch not entered | **Not broken** as CF |
| Distinct error taxonomy | **No** — many failure modes collapse to `0`; already-had-mission after partial work returns `1` |

---

## 4. Alternate interpretations

### Minimal hard-to-attack reading

```
if mission_def_lookup(missionId) valid and enabled:
  maybe toggle UI/state helpers
  if not already in active-mission hash:
    maybe reject if completed/instance sets conflict
    try activate primary objective or log duplicate objective
    unlock continent object id from objective
    if still not in active-mission hash:
      insert mission state nodes; maybe toast/sound
    else log already-had-mission
    return success
return fail
```

### Competing stories not ruled out

1. Client prediction / UI-only grant vs full mission authority.
2. `+0x3e` short gates toast vs “silent grant” for auto-missions.
3. `WeaponAllowsKillXpBonus` = client/server, PvE/PvP, or instance-mode flag mis-named by prior RE.

---

## 5. What was confirmed despite skepticism

1. Nested control-flow shape and return `0`/`1`.
2. Use of character-relative hashes at `+0x538`, `+0x53c`, `+0x540`, `+0x548` for lookups in this body.
3. Objective activation attempt + unlock call ordering.
4. Optional toast/audio path with literal `"Received Mission"` / `"gen_give_quest"`.
5. Clean ≡ raw CF (scaffold fidelity).
6. Function record correctly does **not** claim completion.

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Callee map for insert / unlock / toast helpers | Yes for behavioral port |
| R2 | `AddActiveObjective` arity / `this` | Yes for call edge |
| R3 | True meaning of `WeaponAllowsKillXpBonus` | Yes for completed-set policy |
| R4 | Mission def field meanings (`+0x2b`, `+0x3e`, `+0x4c`, `+0x5a`) | Yes |
| R5 | Server mirror / type-11 plate claims | Yes for system narrative |
| R6 | Runtime re-grant / already-active paths | Yes |
| R7 | Annotated independence (none) | Mild for CF; high for “reviewed twice” |

---

## 7. Concrete checks performed

1. Re-derived outer/inner branch structure from raw alone.
2. Compared clean to raw for invented/missing calls (none material).
3. Cross-checked system-map hash offsets vs body loads.
4. Compared GiveMission call of `AddActiveObjective` to sibling unit signature.
5. Attacked plate “always toast” and “direct hash insert” claims.
6. Correlated `WeaponAllowsKillXpBonus` dual-hash pattern with `HasCompletedMission`.
7. Confirmed function record “Partial scaffold” vs any “verified complete” language (none overclaiming completeness).

**Not done:** re-decompile, CE, callee recovery.

---

## 8. Verdict

### **`needs-more-evidence`**

**Why not accept-with-gaps (for *interpretation package*):**  
Clean fidelity is fine, but the interpretation package (server mirror, volume gates, named insert semantics, weapon-XP gate, sealed call arity) is largely unproven or partially falsified. Accepting the package would launder plate prose.

**Why not needs-revision:**  
No evidence that the filed raw CF is wrong; clean matches it. Revision would mean refining types/names/callee map, not rewriting a broken CF.

**Bar for stronger verdict:**

1. Resolve `AddActiveObjective` call convention against assembly or multi-caller sites.
2. Rename or re-decompile `WeaponAllowsKillXpBonus` with actual body evidence.
3. Map `FUN_0053c360` / `FUN_0053c660` / unlock callee to concrete hash inserts.
4. Demote server/type-11 plate claims until packet or server evidence exists.
5. Optional runtime: grant once, re-grant, toast vs silent path.

**Final verdict: `needs-more-evidence`**
