# Reconstruction review: `aa_0051a790` Skill_LocalCastValidate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a790` |
| **VA** | `0x0051a790` |
| **Canonical name** | `Skill_LocalCastValidate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_0051a790_Skill_LocalCastValidate.md` | Authoritative decompile; eSkillResponses returns |
| Annotated low-level | `docs/reconstruction/raw/aa_0051a790_Skill_LocalCastValidate.annotated.md` | Scaffold copy; plate param names |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Skill_LocalCastValidate.cpp` | Clean CF |
| Function record | `docs/reconstruction/functions/aa_0051a790_Skill_LocalCastValidate.md` | Partial scaffold |
| Callers | `Client_RequestCastSkill.cpp`, `Client_QuickBarActivateSkillSlot.cpp` | Call-site arg pattern |
| Topic extraction | `docs/topic-extractions/skill-cast.md` | Response code list |

**Primary claims under review:**

1. Early rejects: `this+0xb4 & 2` → `5`; vehicle/power gates → `3`; busy path → `6`
2. When skill formal non-null: power `4`, recharge/casting `7`, other codes `10/0xb/0xc`, else `Skill_LocalRangeTargetCheck`
3. Return `0` success when checks pass / skill formal null after gates
4. Clean matches raw including `_bSkipBusyCheck` decompiler name and plate comment mismatch

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw body | Raw capture | Return codes, branches, vtable offsets |
| Annotated | Annotated | Confirm scaffold parity |
| Clean | reconstructed-exact | Faithfulness |
| Call sites | RequestCast / QuickBarActivate | How formals are passed (`0`, `(char)skill`, `0`) |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Return / stage | Match |
|---|---|
| `5` on `this+0xb4 & 2` | **Yes** |
| Vtable `+0x198` / `+0x210` power/vehicle gates → `3` | **Yes** |
| `(char)pCaster == 0` busy / mode gate → `5` or `6` | **Yes** |
| `_bSkipBusyCheck != 0` skill checks | **Yes** |
| Active binding `TFID_NotEquals` invalid path | **Yes** |
| Power `4`, casting/CD `7`, codes `10`, `0xb`, `0xc` | **Yes** |
| `Skill_LocalRangeTargetCheck` at `LAB_0051a94e` | **Yes** |
| Final `return 0` | **Yes** |

### 3.2 Plate vs body naming

Plate lists `(pCaster, bSkipBusyCheck, pSkill)` but body uses:

- `(char)pCaster` as a **boolean-like** busy-skip gate
- `_bSkipBusyCheck` as a **skill object pointer** (`+0x5fc`, `+0x628`, `+0x5e8`, `+0x615`, `+0x614`, `+0x8`)

Clean **preserves** this decompiler naming (including `_bSkipBusyCheck`) rather than inventing a corrected prototype. That is correct for a fidelity pass: do not silently “fix” signature without assembly evidence.

### 3.3 Type renames

`undefined1` → `uint8_t` for stack binding buffer. No logic modernization.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Plate parameter names contradict body roles | High for *docs* | Clean matches body; plate comment is wrong relative to offsets used |
| Callers pass `(char)skill` | High for ABI | Faithful reproduction of decompile call graph; not a clean-only bug |
| `_bSkipBusyCheck` undeclared formal name | Medium | Ghidra artifact retained in clean (compiles only as decompile-shaped pseudocode) |
| `unaff_retaddr` into LocalRangeTargetCheck | Medium | Preserved hole |
| `pSkill` formal unused in body | Medium | Dead formal in decompile surface |
| “VERIFIED error codes via FormatFailureMessage” | Meta | Claim in plate; this unit body does not call FormatFailureMessage |

**No revision required** for clean-vs-raw **text** fidelity. Signature recovery is open work beyond this review’s edit scope.

---

## 5. What remains uncertain

1. True C++ prototype (order and types of skill vs skip-busy).
2. Full eSkillResponses enum mapping (which string for each code).
3. Meaning of `this+0xb4` bits `2` and `8`, mode `0x14`.
4. Vtable `+0x198/+0x210/+0x19c` identities.
5. When callers intend skip-busy vs full check (they pass `0` for the busy-related formal).
6. Runtime confirmation of each reject code.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean reproduces every return path and helper call from raw/annotated without inventing a “fixed” signature that assembly has not sealed.

**Gaps:** Prototype naming is decompiler-corrupted at all layers; plate comments mislabel formals; no runtime matrix of response codes.

**Not needs-revision** for raw parity (would be a *new* reconstruction pass with assembly, not a clean-vs-raw fix).

---

## 7. Reviewer role statement

Faithfulness of clean to low-level only. Explicitly does **not** endorse plate parameter names as correct retail ABI.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Return codes preserved | **Pass** |
| No invented modern validation API | **Pass** |
| Plate formal names correct | **Fail** (plate; not clean drift) |
| Call-site ABI sealed | **Open** |
| Verdict | **accept-with-gaps** |
