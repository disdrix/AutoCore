# Review A (reconstruction fidelity): `aa_0053eb90` VehicleNet_SoftPoseIntegrate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053eb90` |
| **VA** | `0x0053eb90` |
| **Canonical name** | `VehicleNet_SoftPoseIntegrate_Inferred` (was `FUN_0053eb90`) |
| **Ghidra symbol** | `FUN_0053eb90` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053eb90_VehicleNet_SoftPoseIntegrate_Inferred.md` |
| **System** | `input-drive-control` / vehicle ghost soft-pose |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** — integrate math + age gate sealed; call-site dt arg order residual |

---

## 1. Purpose

Advance the entity **soft pose buffer** (`entity+0x28`) by one dead-reckon step:

1. **Age gate** (when `param_3 == 0`): if `g_dwClientTickMs - entity+0x14 > 0x18ff` (**6399** ms) → return **0** (stale).
2. Ensure buffer via `FUN_0053e020` into `entity+0x28`.
3. **Quaternion step:** half-ω (`buf.ω.xyz * 0.5` via `DAT_00a0f298 = 0.5`) × quaternion product form; store **normalized** quat into `buf+0x10`.
4. **Position Euler:** `buf.pos += buf.linVel * param_2` (dt).
5. Return **1** on success.

Does **not** write the live rigid body — buffer only. Sibling consumer: soft path of `FUN_0053eec0`; periodic catch-up `FUN_0053f1f0`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0053eb90` |
| Raw | `raw/aa_0053eb90_FUN_0053eb90.md` |
| Verified parent | `physics/verified/fn_0053eec0_networkApply.md` §6 |
| Constants | `read_memory` `DAT_00a0f298` → **0.5** |

---

## 3. Signature

```c
// __thiscall: ECX = entity
uint __thiscall SoftPoseIntegrate(Entity* this, float dt /*param_2*/, float flag /*param_3*/);
// returns 0 = skipped (stale), 1 = advanced
```

### Age gate

```
if (flag == 0.0f && (g_dwClientTickMs - *(int*)(this+0x14)) > 0x18ff)
  return 0;
```

### Integrate (buffer at this+0x28)

```
hx,hy,hz = ω.xyz * 0.5
q' = normalize(q + (ω⊗q)*dt)   // decomp expands cross/product terms
pos += linVel * dt
```

### Call-site arg order caveat (from verified)

| Site | Decompile call | Notes |
|---|---|---|
| `FUN_0053f1f0` | `Integrate(dt, 0)` | first float is **dt** — confirmed useful |
| `FUN_0053eec0` | `Integrate(0, param_6)` after `param_6==0` early-out | stack order residual vs intent |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Age gate 6399 ms when flag 0 | **High** |
| ½ω from DAT_00a0f298 | **High** (0.5) |
| pos += v·dt; quat normalize | **High** |
| Live body write | **None** (falsified) |
| Exact stack order at every site | **Medium** residual |

**Verdict:** **accept-with-gaps**
