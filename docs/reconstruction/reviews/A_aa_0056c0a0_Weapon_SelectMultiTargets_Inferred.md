# Review A (reconstruction fidelity): `aa_0056c0a0` Weapon_SelectMultiTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056c0a0` |
| **VA** | `0x0056c0a0` |
| **Body** | `0x0056c0a0`–`0x0056c856` exclusive (**1974** B / `0x7B6`) |
| **Canonical name** | `Weapon_SelectMultiTargets_Inferred` |
| **Prior / alias** | `FUN_0056c0a0` |
| **Review date** | `2026-07-29` (W20-H OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` |
| **System** | combat / vehicle weapon targeting |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Virtual weapon multi-target selection** into list host `@this+0x13c`:

1. Gate owner / list / physics → **−1**.
2. `maxTargets` via `FUN_0056ac50`; clamp **>100** with `"WARNING Weaopn <%s> has invalid # of maxtargets(%d) set!"`.
3. Build aim basis (type **0xE** hardpoint path vs default).
4. Optional preferred target range-check via `CVOGPhysicsUtils_FindDistanceToTarget`.
5. Walk locked world list; filter; distance-order slots (cap maxTargets).
6. Merge secondary list metadata; commit slots (`FUN_0056eca0`); return **count**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056c0a0_FUN_0056c0a0.md` (+ W20-H append) |
| Annotated | `docs/reconstruction/raw/aa_0056c0a0_FUN_0056c0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weapon_SelectMultiTargets_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_0056c0a0.cpp` (line-faithful) |
| Function record | `docs/reconstruction/functions/aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` |
| Live decompile | ≡ raw CF spine |
| Entry/exit bytes | `read_memory` @ `0x0056c0a0` / `@0x0056c840` |
| String | `read_memory` @ `0x009d2fcc` full Weaopn message |
| Vtable | DATA `@ 0x009d3330` / `@ 0x009ddad8`; neighbor TryFire `@ 0x009d3320` |
| Distance helper dual | `aa_004e9aa0` FindDistanceToTarget |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / meta seal

| Claim | Evidence | Conf |
|---|---|---|
| Body **1974** B exclusive end `0056c856` | `get_function_by_address` | **High** |
| thiscall (`mov ebx,ecx` early) | entry bytes after frame setup | **High** |
| **`ret 8`** | exit `c2 08 00` @ end of body | **High** |
| SEH cookie `LAB_009a4d8e` | entry `68 8e 4d 9a 00` | **High** |
| Weaopn string imm path | log after maxTargets>100; text @ `0x009d2fcc` | **High** |
| Initial dist sentinel 2560.0f | `_DAT_009d2fc8` = `00 10 20 45` | **High** |
| `g_flOne` = 1.0f | `0x00a0f2a0` | **High** |
| Vtable-only callers | 2 DATA xrefs; no code callers | **High** |
| Decompile ≡ raw | side-by-side | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early −1 gates (owner/list/phys) | **Yes** |
| maxTargets clamp + Weaopn log | **Yes** |
| Type 0xE vs default aim basis | **Yes** |
| Preferred target distance seed | **Yes** |
| Locked-list walk + filters + insert | **Yes** |
| Commit `0056eca0` + return count | **Yes** |
| No invent fire/damage dispatch | **Yes** (not TryFire body) |

### Recovered CF (spine)

```c
// uint __thiscall Weapon_SelectMultiTargets(Weapon *this, List *locked, Object *preferred)
// ret 8
owner = OwnerAdj(this);
if (!owner || owner->IsInvalid() || !locked) { maybe ClearList(); return -1; }
if (!this->listHost@0x13c) return -1;
phys = owner->GetPhysics(); if (!phys || !phys->ok) return -1;
maxT = GetMaxTargets(this); if (maxT > 100) { Log(Weaopn...); maxT = 100; }
BuildAimBasis(...);
count = 0; best = 2560.f;
if (preferred valid && Dist(preferred) != 0) { slots[0] = NewSlot(preferred); count = 1; }
while (count != maxT) WalkList(locked) { filter; d = Dist(cand); insert/append by d; }
Unlock(locked);
MergeSecondaryList(this->listHost);
ClearListHostNodes();
for i in [0,count): Commit(slots[i]);
Destroy leftovers; return count;
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF spine | **High** | sealed three-rep |
| ABI thiscall + ret 8 | **High** | bytes |
| Weapon domain (Weaopn string + vtable) | **High** | |
| Uses FindDistanceToTarget | **High** | dualed callee |
| Product class / method English | **Low–Med** | `_Inferred` |
| Filter bit dictionary complete | **Partial** | bits observed, English open |
| Sort = full stable sort | **Partial** | insert-vs-best rule sealed; residual overlay |

---

## 6. Gaps

1. Product/RTTI class + exact virtual slot name.
2. Complete semantic map of flag filters / `FUN_005134e0`.
3. Typed full clean (scaffold holds line-faithful CF).
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept** — ABI, CF spine, string, vtable, distance helper sealed; product spelling residual only.
