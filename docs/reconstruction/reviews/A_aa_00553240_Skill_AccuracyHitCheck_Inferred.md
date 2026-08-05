# Review A (reconstruction fidelity): `aa_00553240` Skill_AccuracyHitCheck_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553240` |
| **VA** | `0x00553240`–`0x005532ce` |
| **Canonical name** | `Skill_AccuracyHitCheck_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_00553240_Skill_AccuracyHitCheck_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** (role + CF + ABI + constants sealed; product name + score-formula internals open) |

---

## 1. Purpose

Skill **`__thiscall`** accuracy **hit/miss** helper used on the ApplyEffects combat path (and a multi-target damage helper):

1. Read `skill+0x24` (`f32` accuracy).
2. If accuracy **`== -1.0f`** (`DAT_00aaa668`) → **auto-hit** (return **1**), no roll.
3. Else compute score via `FUN_005531d0` (→ `FUN_004ceba0` / `Skill_NonCreatureCastAutoHit`) with a zeroed ~0x400-byte debug reason buffer.
4. Compare: **miss** if `score <= (roll % 100) * 0.01f` (`DAT_00a0f718`); else **hit**.
5. On miss: optional `*outMissFlag = 1` when out-ptr non-null; return **0**. On hit: return **1**.

Not damage authority; boolean gate only. Parent `Skill_ApplyEffectsOnTarget_Inferred` enables this when `skill+0x624` bit0 set.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00553240_FUN_00553240.md` (+ re-verify append) |
| Annotated | `docs/reconstruction/raw/aa_00553240_Skill_AccuracyHitCheck_Inferred.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_AccuracyHitCheck_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00553240_Skill_AccuracyHitCheck_Inferred.md` |
| Live Ghidra | `decompile_function` `0x00553240` / `0x005531d0` / `0x004ceba0` / callers; `get_function_xrefs` / `get_function_callers`; `get_assembly_context` call sites `00553982`, `0058c9ac`; `read_memory` `DAT_00aaa668`, `DAT_00a0f718`; `analyze_function_complete`; pcode basic range |
| Scratch | `tmp/a_00553240.md` |
| Parent dual | `reviews/A\|B_aa_005538a0_Skill_ApplyEffectsOnTarget_Inferred.md` |

---

## 3. Signature (sealed)

```c
// __thiscall  ECX = skill runtime
// returns AL: 1 = hit, 0 = miss  (high bytes may carry junk from prior EAX / roll/100)
unsigned int Skill_AccuracyHitCheck_Inferred(
    void *skill,              // this — f32 accuracy @ +0x24
    void *attacker,           // caster / attacker entity*
    void *target,             // target entity*
    unsigned short roll,      // RNG ushort (slice first word or table entry)
    unsigned char *outMissFlagOptional); // may be NULL; set to 1 on miss only
```

### ABI proof (assembly, not decompiler-only)

| Site | ECX (this) | Stack push order (first→last = near→far) |
|---|---|---|
| `0x00553982` ApplyEffects | `MOV ECX,ESI` skill | `PUSH 0` out; `PUSH EDX` roll; `PUSH EBX` target; `PUSH EBP` caster → call |
| `0x0058c9ac` FUN_0058c850 | `MOV ECX,EDI` skill | `PUSH &local_c5`; `PUSH ECX` roll; `PUSH EBX` target; `PUSH ESI` attacker → call |

Both sites: **skill thiscall** + `(attacker, target, roll, out?)`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function exists @ `0x00553240`–`~0x005532ce` | **Confirmed** | pcode BB max `005532ce`; next named skill unit `0x005532e0` |
| Skill `__thiscall` (ECX skill) | **Confirmed** | assembly both sites; `skill+0x24` load |
| Exactly **2** call xrefs | **Confirmed** | `00553982`, `0058c9ac` |
| Callers: ApplyEffects + `FUN_0058c850` | **Confirmed** | `get_function_callers` |
| `skill+0x24` f32 accuracy | **High** | body; forwarded into `FUN_005531d0` → `FUN_004ceba0` third float |
| Sentinel **`-1.0f`** = skip roll / auto-hit | **Confirmed** | `DAT_00aaa668` = `00 00 80 bf`; `if (f != -1)` gate |
| `DAT_00a0f718` = **0.01f** | **Confirmed** | `0a d7 23 3c` |
| Threshold `(roll % 100) * 0.01f` | **Confirmed** | body; range effectively **0.00–0.99** |
| Miss: `score <= threshold` → return 0 | **Confirmed** | strict `<=` |
| Hit: return 1 | **Confirmed** | `CONCAT31(...,1)` / AL=1 |
| Optional out-flag set **1** on miss only | **Confirmed** | null-checked; ApplyEffects passes **0** |
| Sole direct callee `FUN_005531d0` | **Confirmed** | score producer |
| Score chain → `FUN_004ceba0` (`Skill_NonCreatureCastAutoHit`) | **High** | 531d0 body; naming registry for 004ceba0 |
| Debug buffer ~0x400 bytes zeroed for reason string | **High** | STOSD-style clear; filled by cebao strings ("No Attacker", AutoHit, …) |
| `roll / 100` **not** used in hit decision | **Confirmed** | only `% 100`; `/100` leaks high return bytes |
| Product C++ name | Inferred | no string/RTTI on unit |
| Exact score math inside 004ceba0 | Out of unit | residual of score helper |

---

## 5. Control flow (clean ≡ raw)

```
acc = *(f32*)(skill+0x24)
zero debugBuf[0x400]
if acc == -1.0f:
    return 1                          // auto-hit bypass
score = FUN_005531d0(attacker, target, &debugBuf)   // this=skill
if score <= (roll % 100) * 0.01f:
    if outMissFlagOptional: *outMissFlagOptional = 1
    return 0                          // miss
return 1                              // hit
```

| Stage | Match |
|---|---|
| Sentinel auto-hit | **Yes** |
| Score call before compare | **Yes** |
| Miss out-flag + return 0 | **Yes** |
| Hit return 1 | **Yes** |
| No invented damage / net send | **Yes** |

---

## 6. Call-graph contract

| Caller | Call site | Args / gate |
|---|---|---|
| `Skill_ApplyEffectsOnTarget_Inferred` | `0x00553982` | Only if `skill+0x624 & 1`; `roll = *(u16*)FUN_0058ab60(seed)`; **out=null**; miss → floater in parent |
| `FUN_0058c850` | `0x0058c9ac` | Multi-target loop; `roll` from table `param_5[(i%600)*2]`; **out=&local_c5**; first iteration `local_c4<1` **skips** accuracy (always proceeds) |

**Callees:**

| Address | Role |
|---|---|
| `0x005531d0` | Score wrapper (attacker short bonus + `skill+0x24` → `FUN_004ceba0`) |

---

## 7. Offsets / constants

| Symbol / off | Value / role |
|---|---|
| skill+0x24 | `f32` accuracy; **-1.0** disables roll |
| `DAT_00aaa668` | `-1.0f` sentinel |
| `DAT_00a0f718` | `0.01f` percent→fraction scale |
| roll | `u16`; only **`% 100`** matters for threshold |

---

## 8. Gaps (acceptable)

1. Product C++ name — keep `_Inferred`.
2. Full score formula / entity stat offsets inside `FUN_004ceba0` / `FUN_005531d0` (owned residual units).
3. Semantic of `FUN_0058c850` product name and table layout (out of unit).
4. Whether retail roll domain is always 0–99 vs wider ushort with modulo.
5. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps** — ABI, sentinel, threshold formula, return contract, and both call sites sealed from decompile + assembly context.

---

## Checklist

| Check | Result |
|---|---|
| Exists as function | **Pass** |
| 2 xrefs / 2 callers | **Pass** |
| thiscall skill ECX | **Pass** (assembly) |
| Return 1 hit / 0 miss | **Pass** |
| Clean matches CF | **Pass** |
| Dual B counterpart | **Pass** |
| Verdict | **accept-with-gaps** |
