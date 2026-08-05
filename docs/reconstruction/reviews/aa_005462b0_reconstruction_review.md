# Reconstruction review: `aa_005462b0` CVOGCharacter_CheckMissionRequirements

| Field | Value |
|---|---|
| **Stable ID** | `aa_005462b0` |
| **VA** | `0x005462b0` |
| **Canonical name** | `CVOGCharacter_CheckMissionRequirements` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` | Authoritative decompile; requirement cascade |
| Annotated low-level | `docs/reconstruction/raw/aa_005462b0_CVOGCharacter_CheckMissionRequirements.annotated.md` | Scaffold copy of raw |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CheckMissionRequirements.cpp` | Clean scaffold |
| Function record | `docs/reconstruction/functions/aa_005462b0_CVOGCharacter_CheckMissionRequirements.md` | Partial scaffold status |
| System map | `docs/reconstruction/systems/missions-progression.md` | Field offset table; caller SearchAutoMissions |
| Callee unit | `raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` | Prereq completion lookup |

**Primary claims under review (clean ≡ low-level):**

1. Race / faction fail → `-1`
2. Min level / max level fail → `-1`
3. Currency fail → `-1`
4. Flag check fail → `-1`
5. Up to 4 prereq IDs at `this+0x9c`; accumulate AND/OR completion flags; apply rules at `+0x124` / `+0x120`
6. Returns `-1`, `0`, or first blocking prereq id (`uStack_8`)

**Not re-authored.** No live re-decompile this session.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw capture | Ground truth CF |
| Annotated | Annotated file | No CF delta |
| Clean | `.cpp` | Fidelity map |
| Plate field list | Raw header comments | Offset inventory vs body |
| System map | `missions-progression.md` | Corroborate offsets / role |
| HasCompletedMission | Sibling raw | Callee used in prereq loop |

No runtime / CE.

---

## 3. Confirmed points

### 3.1 Clean ≡ raw control flow

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Race/faction combined if | Present | Present | **Yes** |
| Min level vtable `+0x27c` | Present | Present | **Yes** |
| Max level (`>0` enables) | Present | Present | **Yes** |
| Currency `FUN_0052ada0` | Present | Present | **Yes** |
| Flag `FUN_005405e0` | Present | Present | **Yes** |
| 4-slot prereq loop | Present | Present | **Yes** |
| Prereq rule matrix `+0x124`/`+0x120` | Present | Present | **Yes** |
| Returns `-1` / `0` / `uStack_8` | Present | Present | **Yes** |

### 3.2 Offsets preserved

| Field (plate) | Offset | In body |
|---|---|---|
| Race | `+0x90` | **Yes** (`this`) |
| Faction | `+0x92` | **Yes** |
| Min level | `+0x94` | **Yes** |
| Max level | `+0x98` | **Yes** |
| Prereq array | `+0x9c` (4× uint) | **Yes** |
| Currency id/threshold | `+0x104` / `+0x108` | **Yes** |
| Flag id | `+0x118` | **Yes** |
| Prereq rule ints | `+0x120` / `+0x124` | **Yes** |

### 3.3 Parameter usage preserved (including unused)

Raw signature:

```c
int __thiscall CVOGCharacter_CheckMissionRequirements(void *this, int *pMissionDef, int *pCharacter)
```

- `this_00 = pMissionDef` then passed to `HasCompletedMission`.
- `pCharacter` is **never referenced** in raw, annotated, or clean — clean correctly preserves that unused parameter.
- Race/faction character bytes loaded through the **`pMissionDef` pointer chain**, not `pCharacter`.

This is a decompiler naming issue, not a clean fidelity error. Clean must mirror raw’s actual loads.

### 3.4 Function record honesty

**Partial scaffold**; runtime open — consistent with artifact quality.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Parameter names vs usage | **High for interpretation**, none for clean≡raw | Plate names `this` as character context and `pMissionDef` as mission def, but body uses `this+0x90…` as mission fields and `pMissionDef` as the object passed to `HasCompletedMission` / race chain base. Clean inherits the misnames. |
| `pCharacter` unused | Doc | Should not be “fixed” in clean without assembly proof of a third arg |
| Prereq rule logic density | Residual | CF preserved; semantic labels (AND/OR/require-all) not refined in clean |
| `FUN_0052ada0` / `FUN_005405e0` | Expected | Unresolved |

**No clean rewrite required** for mechanical fidelity to the filed decompile.

---

## 5. Residual uncertainty

1. True identity of `this` vs first stack/register arg (mission def vs character) — **critical for ports**.
2. Exact parenthesization / object at race chain: `pMissionDef[1]+4` … `+0xac` … `+0x3c` … `+0x532/+0x531`.
3. Vtable slot `+0x27c` as GetLevel — Probable from plate only.
4. Prereq flags `+0x120`/`+0x124` semantics (require-all vs require-any inverted by `+0x124`).
5. Currency and flag helper semantics.
6. Why `pCharacter` appears in signature if unused (decompiler artifact vs real ABI).
7. No runtime of fail codes `-1` vs prereq id return.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean reproduces the decompiled requirement cascade, offsets, prereq accumulation, and return set without inventing logic.

**Gaps:** Misnamed parameters and unused `pCharacter` are inherited; callee helpers and prereq rule meanings unsealed; no runtime.

**Not needs-revision (for faithfulness):** Changing parameter names in clean would be an *interpretation* upgrade, not a fix of clean-vs-raw mismatch — and would need stronger evidence than this review alone.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Offsets match | **Pass** |
| Return codes match | **Pass** |
| No invented checks | **Pass** |
| Signature naming sealed | **Open** (gap) |
| Verdict | **accept-with-gaps** |
