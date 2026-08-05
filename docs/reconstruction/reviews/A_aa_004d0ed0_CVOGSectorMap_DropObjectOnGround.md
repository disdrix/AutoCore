# Review A (reconstruction fidelity): `aa_004d0ed0` CVOGSectorMap_DropObjectOnGround

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d0ed0` |
| **VA** | `0x004d0ed0` |
| **Canonical name** | `CVOGSectorMap_DropObjectOnGround` |
| **Ghidra name** | `FUN_004d0ed0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d0ed0_CVOGSectorMap_DropObjectOnGround.md` |
| **System** | `inventory-transfer` / world drop |
| **Verdict** | **accept-with-gaps** — plate string + scatter math sealed; HB ctor residual |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Place an existing world/object pointer **onto the sector map ground**:

1. Null object → log `"trying to drop <NULL> ptr object on the ground"` and return.
2. Read placement pose from `float4* pos` → X=`pos[0]`, Z=`pos[2]`, W=`pos[3]` (Y rebuilt).
3. If `radius > 0` (`g_flZero < param_4`): **scatter** X and Z independently via two `CVOGReaction_RandomUnitScalar` draws.
4. Sample heightfield Y if `map+0xe4e0 != 0` via `FUN_005a58c0` (`Heightfield_SampleY`, dual-sealed) else Y=0; then `Y += DAT_00a0f298` (**0.5f**).
5. Write object local pose: `+0x80=X`, `+0x84=Y`, `+0x88=Z`, `+0x8c=W`.
6. `FUN_004024d0(object)` — finalize placement/transform.
7. If `startHbFlag != 0`: `operator_new(0x24)` → `FUN_005d8360` HB action (duration depends on `object+0xa8→+0x38 != 4`), enqueue on `map+0xe4ec`, `CVOGHBBase_Start`.

Callers: only `004d2750` and `004d2820` (credits/loot place paths).

---

## 2. ABI

```c
// __thiscall this = sector map*
void CVOGSectorMap_DropObjectOnGround(
    Map* this,
    Object* obj,          // null rejected
    const float* pos4,    // X,?,Z,W  — uses [0],[2],[3]
    float scatterRadius,  // 0 → no scatter
    char startHbFlag);    // non-zero → enqueue HB action
```

Decompiler call sites in parents often scramble trailing args (`unaff_*`); treat live parent asm as authority for radius/flag.

---

## 3. Scatter formula (SEALED)

`DAT_00aaa638` = **1/65536** ≈ 1.5259e-5 (ushort → unit).  
`_DAT_009cc4a8` = **2/65536** ≈ 3.0518e-5.

```
u = (float)next_u16(rng)                 // 0..65535
axis' = axis + (u * radius * (2/65536) - radius)
      = axis + radius * (2*u/65536 - 1)
```

Resulting offset ∈ **[-radius, +radius)** approximately (endpoint at 65535 nearly +radius). Applied to **X and Z** only.

---

## 4. Height

| Case | Y |
|---|---|
| `map+0xe4e0 == 0` | `0.0 + 0.5` |
| else | `Heightfield_SampleY(X,Z) + 0.5` |

`DAT_00a0f298 = 0.5f` confirmed via `read_memory`.

---

## 5. HB duration hack

```
duration = (defType != 4) ? (7200000 + 0xff938290) : 7200000
// 0xff938290 == -7000000 signed → duration 200000 when type!=4
// type==4 → 7200000
```

Exact product meaning of type 4 / durations residual.

---

## 6. Confidence

| Claim | Confidence |
|---|---|
| Null log plate string | **Confirmed** |
| Scatter X/Z with radius | **Confirmed** |
| Float constants 2/65536, 0.5 | **Confirmed** (`read_memory`) |
| Heightfield sample optional | **Confirmed** |
| Optional HB enqueue/start | **Confirmed** |
| HB duration product semantics | **Medium** |
| Full pose quaternion use of W | **Medium** |

---

## 7. Gaps

1. `FUN_004024d0` not dualed here.
2. `FUN_005d8360` HB ctor class name residual.
3. Parent call-site arg recovery for radius/flag (decompiler unaff).

**Verdict:** **accept-with-gaps**.
