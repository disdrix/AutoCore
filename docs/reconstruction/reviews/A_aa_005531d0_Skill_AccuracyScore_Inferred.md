# Review A (reconstruction fidelity): `aa_005531d0` Skill_AccuracyScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005531d0` |
| **VA** | `0x005531d0`–`0x00553239` |
| **Canonical name** | `Skill_AccuracyScore_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_005531d0_Skill_AccuracyScore_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** (ABI + CF + arg pack sealed; product name + cebao score product + second-site envelope open) |

---

## 1. Purpose

Skill **`__thiscall`** accuracy **score** helper consumed by `Skill_AccuracyHitCheck_Inferred`:

1. Start `attackerShortBonus = 0.0f`.
2. If `attacker != NULL` and `attacker->vtbl[+0x214]() != NULL`, re-fetch creature and set  
   `attackerShortBonus = (float)(int)FUN_004c4140(creature)`  
   where `004c4140` clamps `min(s16[+0x140], 200) + s16[+0x148]` into **[1, 250]**.
3. Call `Skill_NonCreatureCastAutoHit(bonus, 0.0f, skill.f32[+0x24], attacker, target, debugReasonOut)` (**cdecl**, 6 dwords).
4. Return **float** in **ST0** (pass-through from cebao).

Not hit/miss authority (parent does threshold); not damage authority.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005531d0_FUN_005531d0.md` (+ re-verify append) |
| Annotated | `docs/reconstruction/raw/aa_005531d0_Skill_AccuracyScore_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_AccuracyScore_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_005531d0_Skill_AccuracyScore_Inferred.md` |
| Live Ghidra | `decompile_function` `0x005531d0` / `0x004c4140` / `0x004ceba0` / `0x00553240`; `analyze_function_complete`; `get_function_xrefs` / `get_function_callers`; `get_assembly_context` body + sites `00553297`, `0082731b`; `read_memory` body + `DAT_00aaa7ac` |
| Parent dual | `reviews/A\|B_aa_00553240_Skill_AccuracyHitCheck_Inferred.md` |
| Callee dual | `reviews/A_aa_004ceba0_Skill_NonCreatureCastAutoHit.md` |

---

## 3. Signature (sealed)

```c
// __thiscall  ECX = skill runtime
// RET 0xC; returns float in ST0 (x87) — NOT void
float Skill_AccuracyScore_Inferred(
    void *skill,              // this — f32 accuracy @ +0x24
    void *attacker,           // entity*; NULL → bonus 0
    void *target,             // entity*; forwarded to cebao
    char *debugReasonOut);    // may be NULL; cebao reason strings
```

### ABI proof (assembly, not decompiler-only)

| Fact | Evidence |
|---|---|
| `this` = skill | `MOV EDI,ECX` then `MOV ECX,[EDI+0x24]` |
| Stack args attacker / target / debug | `ESI=[ESP+…]` first arg; loads of `[ESP+0x14]`/`[ESP+0x18]` before pack |
| Callee cleans 0xC | `RET 0xC` at `00553237` |
| Float return | No `FSTP` before ret; parent `FCOMIP` on ST0 after call |
| cebao cdecl 6×4 | Six `PUSH` then `ADD ESP,0x18` |

Push order into `004ceba0` (first pushed = last arg):  
`debug`, `target`, `attacker`, `skillAcc`, `0`, `bonus` → call.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists @ `0x005531d0`–`~0x00553239` | **Confirmed** | body + next skill unit `0x00553240` |
| Skill `__thiscall` (ECX skill) | **Confirmed** | asm; parent MOV ECX skill |
| Exactly **2** call xrefs | **Confirmed** | `00553297`, `0082731b` |
| Named caller = AccuracyHitCheck only | **Confirmed** | `get_function_callers` |
| Second site exists, no function envelope | **Confirmed** | xref without function |
| Return float ST0 | **Confirmed** | asm + parent FPU use |
| Decompiler `void` is wrong | **Confirmed** | completeness warning |
| Null attacker → bonus 0 | **Confirmed** | `TEST ESI` / `JZ` |
| Null creature (vtbl+0x214) → bonus 0 | **Confirmed** | `TEST EAX` / `JZ` |
| Bonus = `(float)(int)FUN_004c4140(creature)` | **Confirmed** | `MOVSX` + `CVTSI2SS` |
| `004c4140` clamp [1,250] from +0x140/+0x148 | **High** | sibling decompile; residual unit |
| Literal second float **0** to cebao | **Confirmed** | `PUSH 0` |
| Third float = `skill+0x24` | **Confirmed** | `MOV ECX,[EDI+0x24]` + push |
| Forwards attacker/target/debug unchanged | **Confirmed** | push pack |
| Sole score product = `004ceba0` | **Confirmed** | single non-vfunc call |
| Product C++ name | Inferred | no string/RTTI |
| Full cebao score formula | Out of unit | sibling dual partial |
| Creature offset English names | Open | residual |

---

## 5. Control flow (clean ≡ raw)

```
bonus = 0.0f
if attacker != null:
    c = attacker.vtbl[+0x214]()
    if c != null:
        c = attacker.vtbl[+0x214]()
        bonus = (float)(int)FUN_004c4140(c)   // [1..250] short clamp
return Skill_NonCreatureCastAutoHit(
    bonus, 0.0f, skill.f32[+0x24], attacker, target, debugOut)
```

| Stage | Match |
|---|---|
| Zero default bonus | **Yes** |
| Double vfunc+0x214 check-then-use | **Yes** |
| Short→float conversion | **Yes** |
| Six-arg pack + skill+0x24 | **Yes** |
| No invented hit/miss / roll | **Yes** |

---

## 6. Call-graph contract

| Caller | Call site | Notes |
|---|---|---|
| `Skill_AccuracyHitCheck_Inferred` | `0x00553297` | After -1.0 auto-hit skip; score ≤ (roll%100)*0.01 → miss |
| unnamed @ `0x0082731b` | `0x0082731b` | `ECX=EDI` skill; after return `FLD 100.0f` (`DAT_00aaa7ac`=`42c80000`) × score → int (display) |

**Callees:**

| Address | Role |
|---|---|
| vtbl+0x214 | creature / animate probe |
| `0x004c4140` | attacker short-stat clamp |
| `0x004ceba0` | `Skill_NonCreatureCastAutoHit` |

---

## 7. Offsets / constants

| Symbol / off | Value / role |
|---|---|
| skill+0x24 | f32 skill accuracy forwarded to cebao |
| creature+0x140 | s16 base (cap 200 in 004c4140) |
| creature+0x148 | s16 bonus addend |
| clamp range | result **1..250** (0xFA) |
| literal | second cebao float always **0** |
| `DAT_00aaa7ac` (2nd site) | **100.0f** display scale (out of unit but supports 0..1 score) |

---

## 8. Gaps (acceptable)

1. Product C++ name — keep `_Inferred`.
2. Full score composition inside `Skill_NonCreatureCastAutoHit` / entity+0x260 / level gates (sibling residual).
3. Whether cebao **uses** the third float (`skill+0x24`) vs only attacker bonus path (decompiler of cebao does not clearly consume it).
4. English names for +0x140/+0x148 and vtbl+0x214.
5. Product identity of code at `0x0082731b` (no Ghidra function).
6. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps** — wrapper ABI, bonus gate, and cebao argument pack sealed from body assembly + parent dual.

---

## Checklist

| Check | Result |
|---|---|
| Exists as function | **Pass** |
| 2 xrefs | **Pass** |
| thiscall skill ECX + RET 0xC | **Pass** (assembly) |
| Float ST0 return | **Pass** |
| Clean matches CF | **Pass** |
| Dual B counterpart | **Pass** |
| Verdict | **accept-with-gaps** |
