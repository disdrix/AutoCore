# Reconstruction review: `aa_0054c570` CVOGReaction_ResolveSkillTargets

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054c570` |
| **VA** | `0x0054c570` |
| **Canonical name** | `CVOGReaction_ResolveSkillTargets` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_0054c570_CVOGReaction_ResolveSkillTargets.md` | Authoritative decompile + plate algorithm |
| Annotated low-level | `docs/reconstruction/raw/aa_0054c570_CVOGReaction_ResolveSkillTargets.annotated.md` | Scaffold |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGReaction_ResolveSkillTargets.cpp` | Clean CF |
| Function record | `docs/reconstruction/functions/aa_0054c570_CVOGReaction_ResolveSkillTargets.md` | Partial scaffold |
| System map | `docs/reconstruction/systems/skills-abilities.md` | Role “Resolve targets” |
| Related name | `Skill_SetRankAndReevaluate` @ plate `FUN_005535a0` | Callee identity in clean |

**Primary claims under review (clean vs low-level):**

1. Optional init `FUN_0054b2c0` when `DAT_00b04724 == 0`
2. Lookup `FUN_00418890(local, &pSkillData)`; if node `== DAT_00b04738` return null
3. Else `operator_new(0x630)`, `FUN_0054f3c0` write pointer, copy `0x18c` dwords from `node+0x10`
4. `Skill_SetRankAndReevaluate(this, uSkillID, unaff_DI)`; return buffer
5. SEH/`ExceptionList` scaffolding preserved

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | CF, sizes, callees |
| Annotated | Annotated | Parity |
| Clean | reconstructed-exact | Faithfulness |
| Size cross-check | Arithmetic | `0x18c * 4 = 0x630` |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Match |
|---|---|
| ExceptionList frame setup | **Yes** |
| Lazy init flag `DAT_00b04724` | **Yes** |
| Map/lookup `FUN_00418890` | **Yes** |
| End-iterator / miss → return `0` | **Yes** |
| Alloc `0x630`, ctor-like `FUN_0054f3c0` | **Yes** |
| Dword copy loop count `0x18c` | **Yes** |
| `Skill_SetRankAndReevaluate(this, uSkillID, unaff_DI)` | **Yes** (raw plate still said `FUN_005535a0`; clean uses session name — **same VA family as plate note**) |
| Return new buffer vs null | **Yes** |

### 3.2 Size consistency

`0x18c` dwords × 4 bytes = `0x630` bytes. Clean preserves both constants; they are mutually consistent.

### 3.3 Type renames

`undefined4*` → `uint32_t*`. No algorithmic modernization (still manual copy loop, not `memcpy`).

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Plate title “Resolve targets” vs body (template clone + rank reevaluate) | High for *docs* | Clean keeps canonical symbol name; does not invent target-list logic that is not in body — correct fidelity |
| `unaff_DI` rank arg | High for ABI | Preserved hole |
| `FUN_0054f3c0` called without using `operator_new` pointer as obvious `this` in decompile | Medium | Raw same; possible in-place new / side channel — clean mirrors |
| Null alloc path still runs copy from `this==0` | Medium | Raw same crash-parity |
| SEH labels (`LAB_009a4637`) | Low | Preserved |

**No revision required** for clean-vs-raw CF fidelity.

**Note on callee rename:** Clean uses `Skill_SetRankAndReevaluate` where raw comment says `FUN_005535a0`. Topic extraction maps `005535a0` → `Skill_SetRankAndReevaluate`. Acceptable named substitution **if** VA matches; not re-verified via Ghidra this session — residual gap only.

---

## 5. What remains uncertain

1. True function purpose (skill instance materialize vs “targets”).
2. Map key type of `pSkillData` / `uSkillID` (plate types are guesses).
3. Meaning of null return (“already cached” plate vs end iterator).
4. `unaff_DI` real rank source.
5. Callers in reaction cast pipeline.

---

## 6. Verdict

### **accept-with-gaps**

Clean reproduces raw control flow, sizes, copy, and rank reevaluate call without inventing a target-list resolver that the body does not implement.

**Gaps:** misleading canonical name/plate algorithm; unrecovered rank register; no runtime; callee rename not re-decompiled this session.

**Not needs-revision** for raw CF parity.

---

## 7. Reviewer role statement

Faithfulness of clean to low-level structure. Does **not** endorse the name “ResolveSkillTargets” as a description of the body.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Alloc/copy sizes consistent | **Pass** |
| No invented target-list logic | **Pass** |
| Name/plate describe body | **Fail** (naming layer) |
| Rank arg sealed | **Open** |
| Verdict | **accept-with-gaps** |
