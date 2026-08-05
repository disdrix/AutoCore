# Reconstruction review: `aa_0052aa20` CVOGCharacter_HasCompletedMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052aa20` |
| **VA** | `0x0052aa20` |
| **Canonical name** | `CVOGCharacter_HasCompletedMission` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` | Authoritative decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.annotated.md` | Scaffold copy |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGCharacter_HasCompletedMission.cpp` | Clean scaffold |
| Function record | `docs/reconstruction/functions/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` | Partial scaffold |
| System map | `docs/reconstruction/systems/missions-progression.md` | Completed hashes `+0x538` / instance `+0x53c` |
| Caller unit | `raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` | Prereq use of this function |

**Primary claims (clean ≡ low-level):**

1. If continent/context pointer at entity chain `+0xa8` is null → simple lookup on `this+0x538`
2. Else complex path: global mission table lookup + continent field `+0xfc` compare + mode gate + `+0x538` / `+0x53c` lookups
3. Returns bool true/false only

**Not re-authored.** No live re-decompile.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | Ground truth |
| Annotated | Annotated | Confirm no CF delta |
| Clean | `.cpp` | Fidelity |
| System map | missions-progression | Hash offset corroboration |
| Requirements checker call | Sibling raw | External use as prereq predicate |

No runtime / CE.

---

## 3. Confirmed points

### 3.1 Clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Fast path: null context → lookup `+0x538` | Present | Present | **Yes** |
| `FUN_0053fff0` mission table | Present | Present | **Yes** |
| Compound condition with continent `+0xfc` | Present | Present | **Yes** |
| `WeaponAllowsKillXpBonus` gates | Present (×2) | Present | **Yes** |
| Instance hash `+0x53c` path | Present | Present | **Yes** |
| Final `return false` | Present | Present | **Yes** |

### 3.2 Offsets

| Slot | Role in plate | In body |
|---|---|---|
| `this+0x538` | completed-mission hash | **Yes** |
| `this+0x53c` | instance-completed hash | **Yes** |
| Entity-relative `+0xa8` | context / continent object | **Yes** (null vs non-null branch) |
| Mission def / object `+0xfc` | continent match field | **Yes** |

### 3.3 Typing

`undefined4*` → `uint32_t /* or float bits */ *` only. Signature `bool __thiscall (void *this, uint missionId)` preserved.

### 3.4 Function record

Partial scaffold; Probable CF — honest.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Compound condition readability | Doc | Decompiler nested `||||` / `&&` is hard; clean keeps it (good for fidelity, bad for maintainers) |
| `WeaponAllowsKillXpBonus` name | Naming | Inherited; not a clean bug |
| No annotated expansion of boolean cases | Gap | Annotated does not simplify truth table |

**No clean CF revision required** for faithfulness.

---

## 5. Residual uncertainty

1. Exact object at entity `+0xa8` (continent? instance? world?).
2. Meaning of mission object field `+0xfc` (continent id claim is Probable).
3. Semantic meaning of the mode flag function.
4. Whether fast path is “not in instance” or “context not loaded.”
5. Full boolean expansion of the long compound condition (short-circuit order matters for side-effecting calls).
6. Runtime confirmation of completed vs instance-completed.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean is a faithful scaffold of the decompiled boolean lookup CF and hash offsets.

**Gaps:** Opaque mode gate name, continent object typing, no truth-table annotation, no runtime.

**Not needs-revision:** No clean/raw mismatch.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Hash offsets match | **Pass** |
| No invented branches | **Pass** |
| Runtime / semantics sealed | **Open** |
| Verdict | **accept-with-gaps** |
