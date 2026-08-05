# Reconstruction review: `aa_00553650` Skill_ValidateTargetForSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553650` |
| **VA** | `0x00553650` |
| **Canonical name** | `Skill_ValidateTargetForSkill` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00553650_Skill_ValidateTargetForSkill.md` | Authoritative decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_00553650_Skill_ValidateTargetForSkill.annotated.md` | Plate + scaffold |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Skill_ValidateTargetForSkill.cpp` | Clean CF |
| Function record | `docs/reconstruction/functions/aa_00553650_Skill_ValidateTargetForSkill.md` | Partial scaffold |
| System map | `docs/reconstruction/systems/skills-abilities.md` | “Target legality” role claim |

**Primary claims under review:**

1. Load handler from `this+0x5f0`; call vtable `+0x44(pSkill, this)`
2. If handler result `!= 1`: queue `FUN_004e2600` feedback; return value with low byte `1`
3. If handler result `== 1`: return `0`
4. Clean matches body; plate comment polarity called out as comment-only mismatch

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw body | Raw capture | Branch polarity, callees |
| Annotated | Annotated | Same body + plate text |
| Clean | reconstructed-exact | Faithfulness |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Init `pvStack_18 = 0` | Yes | Yes | **Yes** |
| Handler call `**(this+0x5f0)+0x44` | `(pSkill, this)` | Same | **Yes** |
| `iVar1 != 1` → store `pSkill`, `FUN_004e2600`, return concat low `1` | Yes | Yes | **Yes** |
| Else return `0` | Yes | Yes | **Yes** |
| `pTarget` formal used | **No** | **No** | **Yes** (dead in both) |

### 3.2 Type renames

`undefined4` → `uint32_t` for `FUN_004e2600` result. `CONCAT31` retained (decompiler-shaped return).

### 3.3 Plate comment vs body (documented, not “fixed”)

Plate: *“returns 1 if valid, 0 if rejected.”*

Body: handler `== 1` → function returns `0`; handler `!= 1` → function returns `1` (after feedback).

Clean correctly follows **body**, not the plate sentence. That is the right fidelity choice.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Plate return polarity opposite body | High for *docs* | Clean should not flip body to match plate without asm |
| `pTarget` unused | Medium | Name `ValidateTargetForSkill(skill, targetObj)` overclaims; `pTarget` never passed to handler |
| Handler args are `(pSkill, this)` not `(target)` | Medium | “Target” may be `this` (skill object?) — naming of `this` vs formals unresolved |
| `CONCAT31(..., 1)` | Low | Decompiler construction for byte return in wider register |

**No revision required** for clean-vs-raw fidelity.

---

## 5. What remains uncertain

1. Which object is `this` (skill runtime vs target vs manager).
2. Handler at `+0x5f0` type and meaning of return `1`.
3. Whether public API polarity is “0=ok” (matching LocalCastValidate) — body suggests function return `0` when handler says `1`.
4. What `FUN_004e2600` / `LAB_005532e0` display.
5. Callers and how they interpret the return.

---

## 6. Verdict

### **accept-with-gaps**

Clean matches raw body including inverted-vs-plate polarity and dead `pTarget`. Scaffold quality is honest.

**Gaps:** semantic naming, plate lie, handler identity, no callers sealed in this pack.

**Not needs-revision** for raw parity.

---

## 7. Reviewer role statement

Faithfulness review only. Treats plate “1 if valid” as **incorrect relative to body** until proven otherwise.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Return polarity matches body | **Pass** |
| Dead `pTarget` preserved | **Pass** |
| Plate polarity correct | **Fail** (plate) |
| Handler identity sealed | **Open** |
| Verdict | **accept-with-gaps** |
