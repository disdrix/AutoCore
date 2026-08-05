# Reconstruction review: `aa_005327c0` CVOGReaction_GiveMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_005327c0` |
| **VA** | `0x005327c0` |
| **Canonical name** | `CVOGReaction_GiveMission` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_005327c0_CVOGReaction_GiveMission.md` | Authoritative Ghidra decompile; grant mission CF, hash inserts, toast path |
| Annotated low-level | `docs/reconstruction/raw/aa_005327c0_CVOGReaction_GiveMission.annotated.md` | Scaffold machine notes; pseudocode copy of raw |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGReaction_GiveMission.cpp` | Port-shaped rewrite of decompiler CF |
| Function record | `docs/reconstruction/functions/aa_005327c0_CVOGReaction_GiveMission.md` | Partial scaffold status; confidence table |
| System map | `docs/reconstruction/systems/missions-progression.md` | Caller graph: SearchAutoMissions → GiveMission → AddActiveObjective |
| Callee unit (context) | `raw/aa_00531b00_CVOGMission_AddActiveObjective.md` | Signature of `CVOGMission_AddActiveObjective` vs call site |

**Primary claims under review (clean must match low-level):**

1. Guard: mission table non-null → def lookup by `param_2` → def flag at `puVar3+0x4c` non-zero
2. Early reject if mission already on character hash `this+0x540`
3. Conditional “already completed / instance” rejects via hashes `+0x538` / `+0x53c` when short at def `+0x2b != -1`
4. Objective path: look up active objective hash `+0x548`; else `CVOGMission_AddActiveObjective(*piVar1)`; always `UnlockContinentObject` from objective `+0x120`
5. Mission insert path: `FUN_0053c360`, optional second insert, optional `FUN_00538b20`, alloc `0x30` node, copy, `FUN_0053c660` / `FUN_0052d8b0`, toast when short at def `+0x3e == 0`
6. Returns `1` on successful grant path / already-had-mission log path; `0` on outer failure

**Not re-authored:** No edits to raw, annotated, clean, function records, WORK_QUEUE, ACTIVE_WORK, or RESUME.

**Optional live re-decompile:** Not performed this session.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth for CF, callees, offsets |
| Annotated body | Annotated § pseudocode | Confirm no material CF delta vs raw |
| Clean body | `CVOGReaction_GiveMission.cpp` | Line-by-line fidelity to raw/annotated |
| Function record status | Function record | “Partial scaffold”; overall Partial |
| System map offsets | `missions-progression.md` | Character hashes `+0x538/53c/540`; grant role |
| AddActiveObjective signature | Sibling raw | Call-arity tension (documented under residual) |

No runtime / CE / differential. No instruction-byte body seal.

---

## 3. Confirmed points

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Raw / annotated | Clean | Match |
|---|---|---|---|
| Outer triple guard | table / lookup / `+0x4c` | Same | **Yes** |
| `FUN_00547920(1)` then conditional `0` | Present | Present | **Yes** |
| Already-active mission (`+0x540`) early skip of grant body | Nested `if (pvVar4 == 0)` | Same | **Yes** |
| Completed/instance dual reject | Two `WeaponAllowsKillXpBonus` + hash checks | Same | **Yes** |
| Objective add vs “Already had objective” log | Present | Present | **Yes** |
| `UnlockContinentObject` | Always after objective branch | Same | **Yes** |
| Mission insert / toast / sound | Present | Present | **Yes** |
| Return `1` / `0` | Present | Present | **Yes** |

### 3.2 Offsets and constants preserved

| Element | Value in raw | Clean |
|---|---|---|
| Active mission hash | `param_1+0x540` | Same |
| Active objective hash | `param_1+0x548` | Same |
| Completed / instance hashes | `+0x538` / `+0x53c` | Same |
| Def fields used | `+0x4c`, `+0x5a`, `+0x2b`, `+0x4f`, `+0x3e`, `+0x40`, `+0x53` (pointer-index form) | Same |
| Toast color / audio | `0xffeee3d8`, `"gen_give_quest"`, duration `0x1e` | Same |
| Alloc size | `operator_new(0x30)` | Same |
| Copy loop | 12 dwords from `local_1a0+0x18` | Same |

### 3.3 Typing delta only

Clean replaces `undefined4` with `uint32_t /* or float bits */` — scaffolding convention, not a CF change. Signature remains `__thiscall (void *param_1, uint param_2)` with return type widened from `undefined4` to `uint32_t` (same 32-bit return channel for `0`/`1`).

### 3.4 Function record honesty

Record correctly labels **Partial scaffold**, control flow **Probable**, runtime open. Does not claim sealed retail port.

### 3.5 Absences

Clean does not invent: clamps, modernized types for mission/objective structs, rewritten toast UI, or alternate return codes.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Scaffold whitespace / blank lines | Cosmetic | Clean mirrors annotated spacing; no semantic impact |
| Unresolved `FUN_*` / `DAT_*` | Expected for scaffold | Faithfulness OK; not refined |
| Call-site arity of `CVOGMission_AddActiveObjective` | Cross-unit decompile tension | Clean preserves raw single-arg call; sibling unit declares two params — see residual |
| Plate comment “inserts mission hash at char+0x540” | Doc | Insert is via `FUN_0053c360` / `FUN_0053c660`, not a direct store in this body — clean matches raw, not the prose abstraction |
| `CVOGCharacter_WeaponAllowsKillXpBonus` name in body | Naming | Inherited from raw symbol use; not introduced by clean |

**No revision required** for clean-vs-raw control-flow fidelity.

---

## 5. Residual uncertainty

1. True object types for `param_1` (character) and `puVar3` (mission def) — Probable only.
2. Semantic identity of many callees (`FUN_0053c360`, `FUN_00538a40`, `FUN_0053c660`, `FUN_0052d8b0`, `FUN_00547920`, toast helpers).
3. Whether decompiler collapsed `this` for `AddActiveObjective` (arity mismatch with sibling unit).
4. Meaning of `WeaponAllowsKillXpBonus` as a mode gate (appears repeatedly in mission code; name likely wrong for this use).
5. Toast path only when def short at `+0x3e == 0` — meaning of that field unsealed.
6. No runtime confirmation of grant, re-grant, or already-active paths.
7. Caller conventions elsewhere sometimes show single-arg `GiveMission` — thiscall recovery incomplete across corpus.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:**

- Clean C++ is a faithful scaffold of raw/annotated control flow, offsets, call order, return values, and side-effect structure.
- No invented branches, stores, or modernized mission logic.
- Function record status matches scaffold quality.

**Gaps (do not block acceptance of this scaffold as matching the filed decompile):**

- Heavy unresolved callee surface.
- Cross-unit signature tension on `AddActiveObjective`.
- No runtime / bit-for-bit verification.
- Annotated layer adds no independent CF recovery beyond raw.

**Not needs-revision:** Clean does not diverge from raw in a way that requires a rewrite for faithfulness.

**Not needs-more-evidence *for clean≡raw*:** Dual static sources (raw + annotated copy + clean) agree. Semantic seal of the mission system is out of scope for this review type.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Offsets / return codes match | **Pass** |
| No invented logic | **Pass** |
| Function record does not overclaim | **Pass** |
| Runtime / callee map complete | **Open** |
| Verdict | **accept-with-gaps** |
