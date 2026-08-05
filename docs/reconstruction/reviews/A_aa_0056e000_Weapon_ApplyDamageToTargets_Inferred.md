# Review A (reconstruction fidelity): `aa_0056e000` Weapon_ApplyDamageToTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056e000` |
| **VA** | `0x0056e000` |
| **Canonical name** | `Weapon_ApplyDamageToTargets_Inferred` (was `FUN_0056e000`) |
| **Ghidra symbol** | `FUN_0056e000` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056e000_Weapon_ApplyDamageToTargets_Inferred.md` |
| **System** | combat / vehicle weapon |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Per-target damage application** for a resolved hit list (vtable worker; sibling of `Weapon_TryFireResolveHits_Inferred` @ `0x0056c860`).

1. Load source id at weapon adjustor **`+0xB0`**; **return 0** if null.
2. Loop `i ∈ [0, count)` over `targets[i]` (skip nulls):
   - **Falloff**: if `this+0xE0 != 0` and target body via **`vtbl+0x1C8`** exists:  
     - `i==0`: store world anchor pos.  
     - `i>0`: `scale = 1.05f − ||pos_i − pos_0|| / *(float*)(this+0xE0)`.  
     - else scale stays **1.0**.
   - **Damage base** = target **`vtbl+0x4C`**(attacker adj, `this+0x124`, `this+0x130`, fixed flags, out-struct).
   - `dmg = (int)(base * scale)`.
   - **`dmg < 1`**: if residual out-flags set, pack report → **`FUN_0056ff00`**.
   - **else**: crit roll (`CVOGReaction_RandomUnitScalar` + **`FUN_004cf080`**); if mult &gt; 1, scale dmg; if host `+0xA8` present: maybe set target `+0xCC=4` when `FUN_0056add0` ∈ {1,5}; report via `FUN_0056ff00`; if def `+0x52C > 0`, construct **`CVOGHBBase`** (`FUN_006335b0`, duration **500**), enqueue + start.
3. **Return 1** (also when count is 0).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056e000_FUN_0056e000.md` |
| Annotated | `docs/reconstruction/raw/aa_0056e000_FUN_0056e000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0056e000.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056e000_FUN_0056e000.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0056e000` (2026-07-29) |
| Complete analysis | Ghidra `analyze_function_complete` — worker; 2 DATA xrefs |
| Bytes | Entry SEH + `and esp,-16`; early exit **`C2 08 00`**; success **`B0 01 … C2 08 00`** |
| Constant | `_DAT_009d3364` = `66 66 86 3F` ≈ **1.05f** |
| Body range | `0x0056e000` – `0x0056e4d1` |
| Vtables | `@ 0x009d331c`, `@ 0x009ddac4` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall(weapon*, uint count, Object** targets)`; **ret 8** | **Confirmed** | `C2 08 00`; two stack formals |
| Source id adj `+0xB0` null → return 0 | **Confirmed** | early path + bytes |
| Loop over pointer array `targets[i]` | **Confirmed** | body |
| Falloff only when `this+0xE0 != 0` | **Confirmed** | body |
| Intercept constant **1.05f** | **Confirmed** | `read_memory` @ `0x009d3364` |
| First target anchors; later scale by distance | **Confirmed** | body |
| Damage via target `vtbl+0x4C` | **Confirmed** | body |
| Crit when mult &gt; 1 then ROUND scale | **Confirmed** | body |
| Hit report `FUN_0056ff00` (miss residual + hit) | **Confirmed** | two call sites |
| HB action path duration 500 + def `+0x52C` | **Confirmed** | body |
| Return 1 on success path | **Confirmed** | `B0 01` |
| Vtable-only entry | **Confirmed** | DATA xrefs only |
| `local_5c` vector cleanup always runs | **Falsified** under current decompile — never filled |
| Product RTTI name | **Open** | structural `_Inferred` |
| Exact `vtbl+0x4C` / `FUN_004cf080` English | **Open** | callee duals |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null source → 0 | Yes |
| Per-target null skip | Yes |
| Falloff 1.05 − dist/range | Yes |
| vtbl+0x4C base × scale | Yes |
| dmg&lt;1 residual report | Yes |
| Crit path + host path | Yes |
| HB alloc/enqueue/start | Yes |
| Return 1 | Yes |
| Preserve dead local_5c cleanup | Yes (faithful) |

### Falloff (sealed math)

```
// _DAT_009d3364 == 1.05f
if (i == 0) anchor = worldPos(target);
else scale = 1.05f - length(worldPos(target) - anchor) / *(float*)(weapon + 0xE0);
dmg = (int)(baseDmg * scale);
```

---

## 5. Callers / callees

| Kind | Site / symbol |
|---|---|
| Callers | virtual via `@0x009d331c`, `@0x009ddac4` |
| Callees | `FUN_0056ff00`, `CVOGReaction_RandomUnitScalar`, `FUN_004cf080`, `FUN_0056add0`, `FUN_006335b0`, `CVOGHBList_Enqueue`, `CVOGHBBase_Start`, `FUN_004da2e0`, `FUN_0056eb20`, new/delete; target `+0x1C8`, `+0x4C` |
| Sibling | `Weapon_TryFireResolveHits_Inferred` (`0x0056c860`) |

---

## 6. Gaps / open

1. Product class / second vtable identity at `0x009ddac4`.
2. Full damage vtbl argument English (`vtbl+0x4C`).
3. Crit formula body in `FUN_004cf080` (callee dual).
4. Whether original source ever filled `local_5c` (lost write vs dead).
5. Runtime / bit-exact image diff.

**Verdict:** **accept-with-gaps**
