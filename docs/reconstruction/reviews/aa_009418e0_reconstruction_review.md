# Reconstruction review: `aa_009418e0` Client_CastSkillFromQuickBarSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_009418e0` |
| **VA** | `0x009418e0` |
| **Canonical name** | `Client_CastSkillFromQuickBarSlot` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_009418e0_Client_CastSkillFromQuickBarSlot.md` | Authoritative decompile; skill flag branches; terminal `Client_RequestCastSkill` |
| Annotated low-level | `docs/reconstruction/raw/aa_009418e0_Client_CastSkillFromQuickBarSlot.annotated.md` | Scaffold copy of raw |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Client_CastSkillFromQuickBarSlot.cpp` | Clean CF port |
| Function record | `docs/reconstruction/functions/aa_009418e0_Client_CastSkillFromQuickBarSlot.md` | Partial scaffold |
| Callee clean | `docs/reconstruction/reconstructed-exact/Client_RequestCastSkill.cpp` | Arg handoff |
| System map | `docs/reconstruction/systems/skills-abilities.md` | Entry listing |

**Primary claims under review:**

1. Early outs: `FUN_0093b7f0() != 0`, skill lookup null
2. If `(skill+0x614 & 0x800) == 0`: resolve target TFID + aim from vehicle/selection chain; else if `(skill+0x614 & 0x20) == 0`: `FUN_0093bac0` and return
3. Fall-through `LAB_00941a89`: `Client_RequestCastSkill(skillId, tfid…, aim)`
4. Clean matches raw including `unaff_ESI` client base

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw capture | CF / flags / callees |
| Annotated | Annotated file | Confirm no silent CF edit |
| Clean C++ | reconstructed-exact | Parity check |
| RequestCastSkill signature surface | Callee clean | Arg count / order |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Match |
|---|---|
| Init invalid TFID seed + zeroed aim locals | **Yes** |
| Gate `FUN_0093b7f0` early return | **Yes** |
| Skill lookup vtable `+0x234(param_1)` | **Yes** |
| Branch on `skill+0x614 & 0x800` | **Yes** |
| Nested selection: entity `+0xa4` null vs non-null | **Yes** |
| Bit test `piVar1[0x5f] >> 5 & 1` → skip to RequestCast without aim fill | **Yes** |
| Else-if `skill+0x614 & 0x20 == 0` → `FUN_0093bac0` return | **Yes** |
| Terminal `Client_RequestCastSkill(param_1, iVar6, iVar5, iStack_1c, local_18, &uStack_34)` | **Yes** |

### 3.2 Type renames

`undefined4` → `uint32_t /* or float bits */` only. Labels (`LAB_00941a89`) preserved as goto target.

### 3.3 No invented logic

Clean does not modernize the dual flag tests into named enums, does not fix `unaff_ESI`, does not invent slot-index math (this unit takes a skill id `param_1`, not a slot index).

---

## 4. Discrepancies or improvements needed

Shared scaffold defects (not clean drift):

| Item | Severity | Notes |
|---|---|---|
| `unaff_ESI` as client | High for API | Same class of recovery hole as RequestCast `in_EAX` |
| Uninitialized `puVar4` if `0x800` path skipped then fall-through copies aim | Medium | When `(+0x614 & 0x800) != 0` and `(+0x614 & 0x20) != 0`, aim locals stay zeroed and TFID stays invalid-seed — intentional fallback before RequestCast |
| When `0x800` clear but selection bit fails → `goto LAB` without writing `uStack_34` from `puVar4` | Medium | Raw also jumps before `*puVar4` copy; clean matches (aim may be zeroed defaults) |
| Flag bits `0x800` / `0x20` unnamed | Doc | Correct to leave numeric until enum seal |
| Name “FromQuickBarSlot” vs arg = skill id | Naming | Body never reads a slot index; clean correctly does not invent one |

**No revision required** for clean-vs-raw fidelity.

---

## 5. What remains uncertain

1. Client base recovery (`unaff_ESI`).
2. Semantic names for `skill+0x614` bits `0x800` and `0x20`.
3. Identity of `FUN_0093b7f0` / `FUN_0093bac0` / vtable `+0x1a0` / `FUN_00404c90`.
4. Whether “quick bar slot” is only a caller-level concept (slot→skill id elsewhere).
5. Runtime path coverage for both flag arms.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean reproduces raw/annotated branches, flag masks, early returns, and the terminal RequestCastSkill handoff without modernization.

**Gaps:** Unrecovered client register; unnamed skill flags; no runtime seal; function name implies slot index the body does not use.

**Not needs-revision** for faithfulness.

---

## 7. Reviewer role statement

Faithfulness review of clean C++ against raw/annotated only. Does not certify flag semantics or retail port ABI.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Flag masks `0x800` / `0x20` preserved | **Pass** |
| Terminal RequestCastSkill args match raw | **Pass** |
| No invented slot-index logic | **Pass** |
| Client `this` recovered | **Open** |
| Verdict | **accept-with-gaps** |
