# Reconstruction review: `aa_00550300` Skill_ResolveTargetList

| Field | Value |
|---|---|
| **Stable ID** | `aa_00550300` |
| **VA** | `0x00550300` |
| **Canonical name** | `Skill_ResolveTargetList` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00550300_Skill_ResolveTargetList.md` | Authoritative decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_00550300_Skill_ResolveTargetList.annotated.md` | Human refine: signature, flags, CF |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Skill_ResolveTargetList.cpp` | Clean CF |
| Function record | `docs/reconstruction/functions/aa_00550300_Skill_ResolveTargetList.md` | Summary / confidence |
| Caller clean | `reconstructed-exact/CVOGReaction_CastSkillOnTarget.cpp` | Resolve when no list; flag→13/14 map |
| Topic | `docs/topic-extractions/skill-cast.md` | Target list role in cast graph |

**Primary claims under review:**

1. Wipe 100 TFID slots to invalid sentinel, then resolve optional primary.
2. `*outFlags |= 1` no-target; `|= 2` out-of-range; return count.
3. Vehicle remap for object types `0x12`/`0x14`; range helper `FUN_0058c0a0`.
4. Conditional `Skill_GatherTargetsInArea` from `skill+0x624` mode bits.
5. Clean matches raw control flow without inventing modern targeting API.

**Not re-authored.** Live re-decompile / assembly not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw body | Raw capture | Full CF, offsets, returns |
| Annotated | Annotated | Param roles, flag labels |
| Clean | reconstructed-exact | Faithfulness |
| CastSkillOnTarget flag map | Caller clean + reviews | outFlags → 0xd/0xe |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Match |
|---|---|
| 100-slot invalid fill (`DAT_009d1ca8..`) | **Yes** |
| Primary-present test `(lo&hi)==-1 && global==0` | **Yes** |
| `ResolveObjectTarget` + `FUN_0054ff00` | **Yes** |
| Null path: bit0 self-pos vs `outFlags\|=1` | **Yes** |
| Type `0x12`/`0x14` vehicle remap | **Yes** |
| Range zero → `outFlags\|=2` → no-primary | **Yes** |
| Primary TFID write `obj[0x58..0x5b]` count=1 | **Yes** |
| Nested pos vs `obj[0x20..0x23]` | **Yes** |
| Mode `+0x624` branch + Gather call | **Yes** |
| Return `(int)local_32` count | **Yes** |
| `-1.0f` (`0xbf800000`) full-area path | **Yes** |

### 3.2 Type / naming renames

`undefined4` → `uint32_t`; formals given working names in annotated/clean. No modernization of gather API.

### 3.3 Does not return eSkillResponses

Body returns count only. Caller maps flags to 13/14. Clean does not invent response codes — **correct**.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `FUN_0054ff00` / `FUN_0058c0a0` unnamed | Medium | Preserved |
| outFlags bit labels INFERRED | Medium | Bits real; names Probable |
| `param_8` unused | Low | Preserved hole |
| CastSkillOnTarget clean call packing may not match 10-arg surface | High for *caller* unit | This unit’s formals follow raw; do not seal caller ABI from this review alone |
| Vehicle remap pointer math fragile | Medium | Faithful to raw |

**No revision required** for clean-vs-raw fidelity of this unit.

---

## 5. What remains uncertain

1. Exact gather / range helper identities.
2. Whether invalid TFID global equals other sentinels (`9CDF88` / `9cbf68`).
3. Full `skill+0x624` targeting enum.
4. Assembly seal of `thiscall` + stack order at CastSkillOnTarget call site.
5. Runtime multi-target counts vs `skill+0xde`.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean reproduces wipe → resolve → range → optional gather → count return without inventing eSkillResponses or a modern target selector.

**Gaps:** Helper names, flag label semantics, caller packing seal, runtime.

**Not needs-revision** for raw parity.

---

## 7. Reviewer role statement

Faithfulness of clean to low-level only. Does not endorse INFERRED flag names as sealed retail enums.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Count return preserved | **Pass** |
| outFlags bit ops preserved | **Pass** |
| No invented 13/14 return | **Pass** |
| Gather ABI sealed | **Open** |
| Verdict | **accept-with-gaps** |
