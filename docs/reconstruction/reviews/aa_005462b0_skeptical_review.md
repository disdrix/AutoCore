# Skeptical / adversarial review: `CVOGCharacter_CheckMissionRequirements` @ `0x005462b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005462b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Requirement checker interpretation, parameter roles, prereq matrix |
| **Verdict** | **needs-revision** |

**Generic approval is insufficient.** Parameter naming in the current package is actively misleading relative to body dataflow.

---

## 1. Inspected artifacts

| Path | Role |
|------|------|
| `docs/reconstruction/raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` | Authoritative decompile |
| `docs/reconstruction/raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.annotated.md` | Scaffold (no independent recovery) |
| `docs/reconstruction/reconstructed-exact/CVOGCharacter_CheckMissionRequirements.cpp` | Clean (inherits names) |
| `docs/reconstruction/functions/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` | Partial scaffold |
| `docs/reconstruction/systems/missions-progression.md` | Offset table / flow |
| `docs/reconstruction/raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` | Callee expects character `this` |
| Call-site context | `SearchAutoMissions` pattern: `CheckMissionRequirements(this_00, this, unaff_ESI)` in sibling raw |

**Not performed:** Assembly of prologue / register thiscall layout; live requirement tests.

---

## 2. Evidence used

### A. Body dataflow (decisive)

```c
// Mission-like fields loaded from `this`:
*(ushort *)((int)this + 0x90)  // race
*(ushort *)((int)this + 0x92)  // faction
*(int *)((int)this + 0x94)     // min level
// ... +0x98, +0x104, +0x108, +0x118, +0x9c, +0x120, +0x124

// Character race/faction bytes loaded via chain rooted at `pMissionDef`:
*(byte *)(... pMissionDef ... + 0x532)
*(byte *)(... pMissionDef ... + 0x531)

// Prereq completion:
this_00 = pMissionDef;
CVOGCharacter_HasCompletedMission(this_00, *puVar6);

// `pCharacter` never used.
```

### B. Callee expectation

`HasCompletedMission(void *this, uint missionId)` uses `this+0x538` / `+0x53c` completed hashes — character-relative. Therefore the first argument to that call must be a **character**, which in this body is **`pMissionDef` (the parameter)**, not `this`.

### C. Plate comments (under attack)

Plate claims checks of “mission +0x90 vs character +0x532” — **field offsets match**, but **which parameter is mission vs character is inverted relative to the C names**.

---

## 3. Attack results

### Claim 1 — Signature names are trustworthy

| Sub-claim | Attack result |
|-----------|----------------|
| `this` is CVOGCharacter | **Falsified by field usage** — `this` holds mission def fields (`+0x90`…`+0x124`) matching system-map mission layout |
| `pMissionDef` is mission definition | **Falsified by usage** — used as character base for race chain and `HasCompletedMission` |
| `pCharacter` is the character | **Falsified / vacant** — never loaded |
| Name `CVOGCharacter_CheckMissionRequirements` implies character thiscall | **Misleading** — body is mission-def this + character as explicit arg (decompiler-named wrong) |

**Severity: Critical for ports and for any AutoCore C# mirror that binds parameters by these names.**

### Claim 2 — Race/faction comparison is correctly understood

| Sub-claim | Attack result |
|-----------|----------------|
| Offsets `+0x90`/`+0x92` vs char `+0x532`/`+0x531` | **Not broken** as plate offsets |
| `0xffff` = unrestricted | **Not broken** |
| Pointer chain to character is fully typed | **Open** — multi-level entity-relative chain still opaque |

### Claim 3 — Level checks use character level from vtable `+0x27c`

| Sub-claim | Attack result |
|-----------|----------------|
| Virtual call through object derived from `pMissionDef` chain | **Not broken** as CF |
| Slot is GetLevel | **Probable only** (plate); not sealed |
| Max level `0` disables max check | **Not broken** (`0 < max` guard) |

### Claim 4 — Prereq matrix is “up to 4 completed missions, all required”

| Sub-claim | Attack result |
|-----------|----------------|
| Loop of 4 slots, skip `0xffffffff` | **Not broken** |
| Tracks AND-all (`pMissionDef` reused as bool accumulator), OR-any (`bStack_9`), first fail id (`uStack_8`) | **Not broken** as mechanics |
| Simple “all prereqs must be complete → pass” | **Falsified as complete story** — rules at `+0x124` / `+0x120` invert/alter outcomes; can return prereq id or `-1` depending on branch |
| Plate return summary exhaustive | **Incomplete** — behavior is a small state machine, not one rule |

### Claim 5 — Currency / flag helpers are sealed

| Sub-claim | Attack result |
|-----------|----------------|
| Called with def fields | **Not broken** |
| Semantics of `FUN_0052ada0` / `FUN_005405e0` | **Unproven** |

### Claim 6 — Clean reconstruction is port-ready

| Sub-claim | Attack result |
|-----------|----------------|
| CF matches decompile | **Not broken** |
| Safe to bind by parameter names | **BROKEN** — binding `this` as character would invert mission vs character |

---

## 4. Alternate interpretations

### Preferred rebind (still Probable until asm)

```
// Conceptual — names corrected relative to body:
int CheckMissionRequirements(MissionDef* mission /*this*/,
                             Character* character /*param currently named pMissionDef*/,
                             /* unused? */ void* unused /*pCharacter*/);
```

### Why decompiler may have done this

MSVC thiscall + extra args; Ghidra named from partial plate/heuristic. `pCharacter` may be a phantom third arg or a real unused ABI slot.

### Competing prereq stories

| `+0x124` | `+0x120` | Effect sketch from CF |
|----------|----------|------------------------|
| 0 | 0 | Fail if not all complete **and** (no-any? `bStack_9==0`) → return first fail id |
| 0 | nonzero | Different fail combination |
| nonzero | * | Opposite polarity branch returning `-1` |

Full truth table needs careful boolean expansion + tests — not sealed here.

---

## 5. Confirmed despite skepticism

1. Ordered fail cascade: race/faction → min level → max level → currency → flag → prereqs.
2. Mission field offsets in body match system-map mission-def table.
3. Character race/faction byte offsets `+0x532`/`+0x531` appear as claimed.
4. Prereq completion delegated to `HasCompletedMission`.
5. Return set includes `-1`, `0`, and a prereq mission id.
6. Clean faithfully copies the decompile (including the bad names).

---

## 6. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | Formal ABI: which register/stack slot is mission vs character | **Yes** |
| R2 | Whether `pCharacter` exists in real ABI | **Yes** for signature |
| R3 | Full prereq truth table for `+0x120/+0x124` | **Yes** for auto-award parity |
| R4 | Level vtable identity | Mild–medium |
| R5 | Currency/flag helpers | Medium |
| R6 | Call-site arg order confirmation across all callers | **Yes** |

---

## 7. Concrete checks performed

1. Traced every load base (`this` vs `pMissionDef` vs `pCharacter`).
2. Matched `HasCompletedMission` callee `this` requirement to actual argument.
3. Compared plate names to body — found inversion.
4. Expanded prereq loop flag mechanics (AND/OR/first-fail).
5. Verified clean did not “fix” names away from raw (fidelity OK; interpretation not).
6. Cross-checked system-map mission offsets against `this+…` loads.

**Not done:** prologue disassembly; live matrix of prereq flags.

---

## 8. Verdict

### **`needs-revision`**

**Why needs-revision (interpretation package / naming layer):**  
The current signature and plate wording invite a **wrong port binding** (character as `this`, mission as second arg). Body evidence inverts those roles. Leaving names as-is is not a harmless gap; it is a defect in the reconstruction package’s public interface story.

**What to revise (without claiming this review rewrote files):**

1. Rename parameters in annotated + clean + function record to match dataflow (e.g. `missionDef` this, `character` explicit).
2. Document or remove `pCharacter` after ABI check.
3. Expand prereq `+0x120/+0x124` into an explicit truth table in annotated notes.
4. Re-verify call sites (`SearchAutoMissions`, others) against the corrected ABI.

**Why not needs-more-evidence alone:**  
There is already enough body evidence to **reject** the current parameter naming. More evidence is still needed for prereq rule seal and helpers, but the naming issue is past “unknown” into “contradicted.”

**Why not accept-with-gaps:**  
Gaps usually mean missing depth; here a core claim (who is `this`) fails adversarial check.

**Final verdict: `needs-revision`**
