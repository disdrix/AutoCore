# Review A (reconstruction fidelity): `aa_004cef70` Combat_ComputeCritChance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cef70` |
| **VA** | `0x004cef70`–`0x004cf07c` |
| **Canonical name** | `Combat_ComputeCritChance_Inferred` |
| **Ghidra name** | `FUN_004cef70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-A) |
| **Counterpart** | `reviews/B_aa_004cef70_Combat_ComputeCritChance_Inferred.md` |
| **System** | combat-crit |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callees `004c4dd0`/`004c3140`/`004c3120` decompiled for field slots |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Compute crit **chance** (float ST0) for `(attacker, target)`:

1. `level = attacker.vtbl[+0x27c]()`.
2. Base: if no skill bind (`vtbl+0x214==0`) → `level*0.001*0.25+0.05`; else `FUN_004c4dd0(bind)`.
3. Add attacker bind bonus (`FUN_004c3140`, +0x1dc with flag 1).
4. Subtract target bind resist (`FUN_004c3120`, slot by target `+0x1d4` probe).
5. Floor negative → `0.05`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cef70_FUN_004cef70.md` (+ W22-A append) |
| Annotated | `docs/reconstruction/raw/aa_004cef70_FUN_004cef70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Combat_ComputeCritChance_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cef70.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cef70_FUN_004cef70.md` |
| Callers | `Combat_RollCritMultiplier_Inferred`, `FUN_00838e20` |
| Live | decompile ≡ raw; full 268 B body hex; constants sealed |

---

## 3. Signature (sealed)

```c
// cdecl; ST0 return
float Combat_ComputeCritChance_Inferred(void *attacker, void *target);
```

| Formal | Source | Conf |
|---|---|---|
| attacker | stack +0x4 → ESI | **High** |
| target | stack +0x8 → EDI; nullable | **High** |
| Return | ST0 chance | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
level = vcall(attacker, +0x27c)
flagT = target ? (vcall(target,+0x1d4)!=0) : 0
vcall(attacker, +0x1d4)   // discarded
if vcall(attacker,+0x214)==0:
  chance = level * 0.001 * 0.25 + 0.05
else:
  chance = FUN_004c4dd0(vcall(+0x214))
if bind: chance += FUN_004c3140(bind,1)
if target.bind: chance -= FUN_004c3120(bind, flagT)
if chance < 0: chance = 0.05
return chance
```

| Stage | Match | Conf |
|---|---|---|
| Level via +0x27c | **Yes** | **High** |
| Fallback mulss chain | **Yes** | **High** |
| Bind → 004c4dd0 | **Yes** | **High** |
| +bonus / −resist | **Yes** | **High** |
| Floor 0.05 | **Yes** | **High** |
| cdecl ST0 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body (268 B) in raw append. Key immediates:

| Constant | VA | Value |
|---|---|---|
| ms→s | `0x00a0f72c` | `0.001` |
| scale | `0x00a0f704` | `0.25` |
| floor/base add | `0x009cbf80` | `0.05` |

Callee rel32 from body targets: `FUN_004c4dd0`, `FUN_004c3140`, `FUN_004c3120`.

---

## 6. Confidence / gaps

| Claim | Conf |
|---|---|
| Chance formula + CF | **High** |
| Combat consumer contract | **High** |
| Product English name | **Probable** |
| `FUN_004c4dd0` full formula | **Open** (not owned) |
| Attacker `+0x1d4` side effect | **Open** |
| UI caller full semantics | **Open** |

**Verdict: accept-with-gaps** — chance kernel sealed for port with mult sibling; skill-table base dual residual.
