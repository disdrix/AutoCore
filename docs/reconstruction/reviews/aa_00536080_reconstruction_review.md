# Reconstruction review: `aa_00536080` CVOGCharacter_CompleteMissionObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536080` |
| **VA** | `0x00536080` |
| **Canonical name** | `CVOGCharacter_CompleteMissionObjectives` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` | Authoritative decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.annotated.md` | Scaffold copy |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CompleteMissionObjectives.cpp` | Clean scaffold |
| Function record | `docs/reconstruction/functions/aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` | Partial scaffold |
| System map | `docs/reconstruction/systems/missions-progression.md` | Bulk complete; objectives array `+0x13c` count `+0x130` |
| Callers (context) | `raw/aa_00536540_CVOGCharacter_CheckMissionPrerequisites.md` | Invokes with reason `1` |

**Primary claims (clean ≡ low-level):**

1. `__cdecl` static-style helper: `(uint uMissionID, reason)`
2. Lookup mission def via `FUN_0053fff0` + `CNDHash_LookupByKey`
3. Iterate `count = *(byte*)(def+0x130)` objectives from array at `def+0x13c`
4. Each: `CVOGReaction_CompleteObjective(obj+0x10 id, 0xffffffff, 0xffffffff, uReason)`
5. Return `1` if def found (even if count 0); `0` if not found

**Not re-authored.** No live re-decompile.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | Ground truth |
| Annotated | Annotated | No CF delta |
| Clean | `.cpp` | Fidelity (`undefined4` → `uint32_t` for reason) |
| System map | missions-progression | Offset corroboration |
| Prerequisites caller | Sibling raw | External call shape |

No runtime / CE. `CompleteObjective` body not in this unit pack.

---

## 3. Confirmed points

### 3.1 Clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Hash table get | `FUN_0053fff0` | Same | **Yes** |
| Null table / failed lookup → `0` | Present | Present | **Yes** |
| Byte count at `+0x130` | Present | Present | **Yes** |
| Array base `+0x13c`, stride 4 | Present | Present | **Yes** |
| Obj id at `*(obj* + 0x10)` | Present | Present | **Yes** |
| CompleteObjective args | `id, -1, -1, uReason` | Same | **Yes** |
| Success return `'\x01'` | Present | Present | **Yes** |

### 3.2 Convention

Raw `__cdecl` preserved in clean (not thiscall). Matches plate “static helper.”

### 3.3 Function record honesty

Partial scaffold; overall Partial — consistent.

### 3.4 Absences

No invented filtering of objectives, no early abort on CompleteObjective failure (return not checked), no direct hash mutation in this body.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Plate algorithm bullet “reason 0xffffffff” | Doc tension | Algorithm list says CompleteObjective with reason `0xffffffff`, but body passes **`uReason` as 4th arg** and hardcodes `0xffffffff` as 2nd/3rd. Clean matches body, not the ambiguous bullet. |
| CompleteObjective success ignored | Residual | Raw also ignores; clean correctly mirrors |
| Empty objective list still returns 1 | Behavior | Present in raw/clean; document for ports |

**No clean revision required** for raw fidelity.

---

## 5. Residual uncertainty

1. Semantics of CompleteObjective args 2–4 (`0xffffffff`, `0xffffffff`, `uReason`).
2. Whether count byte can exceed actual array length (no bounds beyond count).
3. What “complete all objectives” does to mission completed hash (lives in callee).
4. Why callers pass `uReason=1` from prerequisites path.
5. No runtime of bulk complete.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Small, clear CF; clean is a faithful scaffold of lookup + loop + returns.

**Gaps:** Callee semantics, plate wording on reason constants, no runtime.

**Not needs-revision:** Clean tracks the decompile body.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Offsets `+0x130`/`+0x13c` | **Pass** |
| Return 0/1 | **Pass** |
| CompleteObjective call shape | **Pass** |
| Callee sealed | **Open** |
| Verdict | **accept-with-gaps** |
