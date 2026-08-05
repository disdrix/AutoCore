# Review A (reconstruction fidelity): `aa_0091d460` Client_Input_ApplyRandomUpPhysicsKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091d460` |
| **VA** | `0x0091d460`–`0x0091d655` |
| **Canonical name** | `Client_Input_ApplyRandomUpPhysicsKick_Inferred` (prior scaffold `FUN_0091d460` / `Named_CalleeOf_Client_Input_DriveControlTick_0091d460`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (clean ≡ raw ≡ live decompile/asm CF) |
| **Counterpart** | `reviews/B_aa_0091d460_Client_Input_ApplyRandomUpPhysicsKick_Inferred.md` |
| **System** | `input-drive-control` (secondary same-tick path of `Client_Input_DriveControlTick`) |
| **Dual status** | **Present** (OWN-ONLY dual A/B create) |
| **Verdict** | **accept-with-gaps** — gates, RNG→dir formula, mass×12 scale, physics apply thiscall sealed; product action name / `FUN_00404cb0` vfunc English open |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `disassemble_function` + `read_memory` on constants + `get_function_callers` / `analyze_function_complete`. Prefer decompile/`read_memory`; full-function disasm only for ECX/this and wrap threshold. Own VA only. No ledgers.

---

## 1. Purpose

Edge-triggered **client vehicle physics kick** from `Client_Input_DriveControlTick`:

1. Resolve local vehicle `entity = *(DAT_00d1b6d8 + 0x250)`.
2. Gate: entity ≠ 0, `entity+0x8` (physics host) ≠ 0, `entity+0x101 == 0` (drive not suppressed).
3. Gate: component-chain vfunc **`+0x198`** returns **0** (false) — else no-op.
4. Build float4 direction base **`(0, 1, 0, 0)`** from `DAT_00afda50…5c`.
5. Draw **two** u16 samples from the shared RNG table (`CALL 0x007a4330`, Ghidra name `CVOGReaction_RandomUnitScalar` — returns table host; **does not** return a unit scalar by itself).
6. Map each u16 → **≈ [−0.3, +0.3]** via `(float)u16 * DAT_00aaaaf0 − g_flOverheatCoolFrac` with `DAT_00aaaaf0 ≈ 0.6/65535`, `g_flOverheatCoolFrac = 0.3` @ `0x00a0f714`.
7. Assign randoms to **X** and **Z**; keep **Y = 1**, **W = 0**.
8. Normalize **(X,Y,Z)** (W not in length; stays 0).
9. Scale by **`(1 / mass) * 12`** where `mass = *(*(entity+0x8)+0x3c)+0x2c` (zero mass → zero scale).
10. Apply via **`FUN_00404cb0`** with **`this = *(entity+0x8)`** (ECX live across SSE math) and stack arg **`&float4`**. Sibling of `CVOGPhysics_ApplyImpulseVector` (`vtbl+0x50`); this path uses **`vtbl+0x5c`**.

**Calling convention:** no stack args; epilogue plain **`RET`**. Not a thiscall on the vehicle — globals + local entity load.

**Sole caller:** `Client_Input_DriveControlTick` @ `0x009223b0` (xref `0x00923646`), under held+edge ActionMap pair `DAT_00d1be2e` / `DAT_00d1be2f` with rate gate (`DAT_00d1b6d8[0x1ad] > 0` **or** `GetTickCount` delta **> 5000** vs `_DAT_00d1f0c8`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0091d460_FUN_0091d460.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0091d460_FUN_0091d460.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_ApplyRandomUpPhysicsKick_Inferred.cpp` (+ scaffold `FUN_0091d460.cpp` / Named plate) |
| Function record | `docs/reconstruction/functions/aa_0091d460_Client_Input_ApplyRandomUpPhysicsKick_Inferred.md` |
| Live decompile | `force_decompile` / `decompile_function` @ `0x0091d460` — **≡** 2026-07-23 raw CF |
| Live asm | `disassemble_function` full body — ECX=`entity+8` into `FUN_00404cb0`; wrap `CMP [rng+0xc], 0x100000` |
| Constants | `read_memory` `0x00aaaaf0`, `0x00aaaad0`, `0x00afda50`×16, `0x00a0f714`, `0x00a0f2a0` |
| Callers | `get_function_callers` → only `Client_Input_DriveControlTick` |
| Sibling apply | Live decompile `CVOGPhysics_ApplyImpulseVector` `0x0040d260` (same ready-gate shell; **vtbl+0x50**) vs `FUN_00404cb0` **vtbl+0x5c** |
| Parent context | raw `aa_009223b0` call site block (owned only as caller CF; not re-dualed) |

**Not performed:** Launcher, runtime golden, bit-exact binary diff, ActionMap display-name bind for `DAT_00d1be2e`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller DriveControlTick | **High** | callers API + single xref |
| Entity load `*(DAT_00d1b6d8+0x250)` | **High** | decompile ≡ asm `MOV ESI,[EAX+0x250]` |
| Gates: entity, `+8`, `+0x101==0` | **High** | early-out to epilogue |
| vfunc `+0x198` must return 0 | **High CF**; product role open | same component-chain idiom as other client entity queries |
| Base dir `(0,1,0,0)` from `DAT_00afda50` | **High** | `read_memory` 0,1,0,0 |
| Two independent RNG u16 draws | **High** | two `CALL 0x007a4330` + index++ |
| Ring wrap when index ≥ `0x100000` | **High** | asm `CMP …,0x100000` / `JL`; decompiler `0xfffff < idx` equivalent |
| Map u16 → [−0.3,+0.3] via scale×u16 − 0.3 | **High** | scale LE `349a1937` ≈ 0.6/65535; cool LE `9a99993e` = 0.3 |
| Randoms overwrite X and Z; Y stays 1 | **High** | first store → `ESP+0x10`; second stays in XMM then → Z after normalize |
| Length over **xyz only**; W→0 | **High** | asm length uses x,y,z; w mul keeps 0 |
| Mass at `body+0x2c`; scale `(1/m)*12` | **High** | `DAT_00aaaad0` = **12.0** (`00004041`); zero-mass → zero |
| `FUN_00404cb0` thiscall: ECX=`*(entity+8)`, arg=`&vec` | **High** | asm: `MOV ECX,[ESI+8]` then only SSE until `PUSH`/`CALL` — ECX preserved |
| Apply is **not** `ApplyImpulseVector` | **High** | different vtbl slot (`+0x5c` vs `+0x50`) |
| Product English name (hop / boost / unstick) | **Open** | no string in body; bind name via ActionMap residual |
| `g_flOverheatCoolFrac` name as semantic “overheat” | **Low name / High value** | shared **0.3** constant; here = random half-range |
| `CVOGReaction_RandomUnitScalar` product name | **Low name / High CF role** | returns RNG host; unit map is **at this site** |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Entity + physics + drive-enable gates | **Yes** |
| vfunc `+0x198` false gate | **Yes** |
| Base float4 copy | **Yes** |
| RNG draw ×2 + wrap + unit map | **Yes** |
| Normalize + mass×12 scale | **Yes** (asm does normalize then scale; decompiler fuses multiplies) |
| `FUN_00404cb0(&vec)` | **Yes** |
| No drive-axis writes (`+0x614/+0x618/+0x61c`) | **Yes** — physics kick only |

### 4.1 Formula (sealed)

```
entity = *(DAT_00d1b6d8 + 0x250)
require entity && *(entity+8) && *(u8*)(entity+0x101)==0
require vfunc_0x198(component_chain(entity)) == 0

dir = (0, 1, 0, 0)                     // DAT_00afda50 block
rx  = u16_a * DAT_00aaaaf0 - 0.3f      // → ≈ [-0.3, 0.3]
rz  = u16_b * DAT_00aaaaf0 - 0.3f
v   = (rx, 1, rz)                      // w unused in length
inv = (||v||==0) ? 0 : 1/||v||
mass = *(*(entity+8)+0x3c)+0x2c
s   = (mass==0) ? 0 : (1/mass) * 12.0f
vec = (rx,1,rz,0) * inv * s
FUN_00404cb0(physics=*(entity+8), &vec)  // body vtbl+0x5c
```

### 4.2 Parent edge gate (caller CF; not owned body)

```
if DAT_00d1be2e && DAT_00d1be2f:
  DAT_00d1be2f = 0
  if DAT_00d1b6d8[0x1ad] > 0 OR (GetTickCount() - _DAT_00d1f0c8) > 5000:
    _DAT_00d1f0c8 = GetTickCount()
    FUN_0091d460()
```

---

## 5. Layout / constants

### Entity (body-backed here)

| Offset | Type | Role |
|-------:|------|------|
| `+0x04` | ptr | component chain base for vfunc `+0x198` |
| `+0x08` | ptr | physics host (`this` for `FUN_00404cb0`; `+0x3c` → body) |
| `+0x101` | u8 | drive-suppressed (must be 0) |

### Body

| Offset | Type | Role |
|-------:|------|------|
| `+0x2c` | f32 | mass (or mass-like scale); 0 → null kick |

### Constants (`read_memory` this pass)

| Symbol | Addr | LE | Value | Role |
|--------|------|-----|-------|------|
| `DAT_00aaaaf0` | `0x00aaaaf0` | `34 9a 19 37` | ≈ **9.1554e-6** (≈ **0.6/65535**) | u16 → [0, ~0.6] |
| `g_flOverheatCoolFrac` | `0x00a0f714` | `9a 99 99 3e` | **0.3** | center randoms to ±0.3 |
| `DAT_00aaaad0` | `0x00aaaad0` | `00 00 40 41` | **12.0** | kick magnitude factor |
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** | inv length / inv mass |
| `DAT_00afda50` | `0x00afda50` | 16B | **(0,1,0,0)** | base up direction float4 |

### RNG host (from call sites)

| Offset | Role |
|-------:|------|
| `+0x08` | `uint16_t*` table base |
| `+0x0c` | index (wrap ≥ `0x100000`) |

---

## 6. Naming

| Name | Status |
|------|--------|
| `Client_Input_ApplyRandomUpPhysicsKick_Inferred` | **Probable** — CF + sole DriveControlTick edge caller; `_Inferred` until ActionMap/product string |
| Prior `FUN_0091d460` / Named_CalleeOf_… | Scaffold only |

---

## 7. Open residuals (OWN-ONLY)

1. Product / bind English name for `DAT_00d1be2e` edge action.
2. `FUN_00404cb0` vfunc `+0x5c` English (impulse vs velocity delta) — leave to its VA.
3. vfunc `+0x198` product meaning (boolean state that blocks kick).
4. Runtime golden: mass scale + random distribution feel.
5. Whether `body+0x2c` is mass vs another inertia scalar (layout name).

---

## 8. Dual process note

OWN-ONLY dual A/B on `0x0091d460`. Three-rep refined (annotated + clean + function record; raw append-only live stamp). No WORK_QUEUE / RESUME / matrix / ledger edits.
