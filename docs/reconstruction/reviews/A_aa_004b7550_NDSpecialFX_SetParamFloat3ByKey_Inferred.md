# Review A (reconstruction fidelity): `aa_004b7550` NDSpecialFX_SetParamFloat3ByKey_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7550` |
| **VA** | `0x004b7550` |
| **Canonical name (Ghidra)** | `FUN_004b7550` |
| **Proposed name** | `NDSpecialFX_SetParamFloat3ByKey_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_CVOGCharacter_LevelUp_004b7550` — one parent only; **too narrow** |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004b7550_NDSpecialFX_SetParamFloat3ByKey_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX param map |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Write a **float3 parameter** into the FX object's **int-keyed map** at `this+0x224` / end header `this+0x228`:

1. `Map_LowerBoundFindByIntKey(this+0x224, &iter, &key, …)` where **key** is the second stack arg (`stack0x00000008` / `Stack[0x8]`).
2. If `iter == end` (`this+0x228`): no-op return.
3. Else payload `entry = *(iter+0x10)`:
   - `entry+0x14..+0x1c` ← `vec[0..2]`
   - scale: `v[i] *= *(float*)(entry + 0x8 + 4*i)` for i=0,1,2 (per-axis scales at `+8/+c/+10`)
   - **`*(u8*)(entry+0x20) = 0`** — state byte cleared (marks entry “raw / needs resolve”; `004b75d0` treats `0` as skip-until-ready gate in several modes)

**Not** a free-function float packer: multi-domain **thiscall** on the FX host (weapon fire, water FX, level-up, drive, combat).

---

## 2. Signature (decompiler gap sealed)

Ghidra shows only `(this, float*)` but uses `stack0x00000008` as the map key. Call sites:

```c
FUN_004b7550(&local_c, 1);  // key=1
FUN_004b7550(&local_c, 2);  // key=2
// … keys 3,4 likewise in Weapon_FireHelper / FUN_0056a9e0
```

**Sealed signature:**

```c
void __thiscall NDSpecialFX_SetParamFloat3ByKey_Inferred(
    void *fx,        // ECX
    float *vec3,     // Stack[0x4] — only [0..2] written
    int key);        // Stack[0x8] — int map key
```

Note: weapon paths often alias a single float into a 3-float stack slot (broadcast / only X meaningful for scalar fields).

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `batch_decompile` + `analyze_function_complete` @ `0x004b7550` |
| Raw / clean | `raw/aa_004b7550_*`, `reconstructed-exact/FUN_004b7550.cpp` |
| Callers | 24 xrefs / 9 functions: `0056d160`, `0056a9e0`, `005a8a90` (UpdateWaterFX), `005a9400`, `005d9af0`, `00531330`, `00524710`, `0056bce0`, `005a8f90` |
| Callee | `Map_LowerBoundFindByIntKey` only |

---

## 4. Entry layout (from this + `004b75d0` peer)

| Offset | Role | Confidence |
|---|---|---|
| `entry+0x4` | Mode / type int (0,1,4,5,6 in update switch) | **High** (update switch) |
| `entry+0x8/+c/+10` | Per-axis scale floats | **High** (this fn multiplies) |
| `entry+0x14/+18/+1c` | Computed / stored float3 | **High** |
| `entry+0x20` | State byte (0=raw/set; 1/2 used in update) | **High** |
| `entry+0x24` | Hardpoint / bone id (`-1` = host default) | **High** (`004b75d0`) |

Map tree at `fx+0x224`, header/end at `fx+0x228` — fits NDSpecialFX **0x240** object size from parse path.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| lower_bound by int key on `+0x224` | Yes (key via stack) |
| miss → return | Yes |
| hit → write float3, scale, state=0 | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall; key is 2nd stack arg | **High** | `stack0x00000008` + call sites |
| Map at `+0x224` / end `+0x228` | **High** | decompile |
| Per-axis scale then store | **High** | explicit muls |
| State `+0x20 = 0` after set | **High** | |
| Multi-domain (not LevelUp-only) | **High** | 9 callers incl. water FX / weapons |
| Product name | **Tentative** | `_Inferred` |
| Whether `vec3[1]/[2]` always meaningful for scalar keys | **Partial** | weapon packs re-use 4-byte local |

---

## 7. Gaps / open

1. Full key→semantic table (keys 1–4 in weapon path are heat/fire scalars; water FX uses keys 1–2 for splash vectors — not a global enum dual).
2. `Map_LowerBoundFindByIntKey` iterator layout residual (node `+0x10` → payload) — consistent with codebase map helpers.
3. Decompiler `unaff_ESI` noise on map call — ignore for CF.

**Verdict:** **accept-with-gaps**
