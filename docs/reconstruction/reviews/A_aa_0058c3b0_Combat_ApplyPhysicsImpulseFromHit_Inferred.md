# Review A (reconstruction fidelity): `aa_0058c3b0` Combat_ApplyPhysicsImpulseFromHit_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058c3b0` |
| **VA** | `0x0058c3b0` |
| **Canonical name (Ghidra)** | `FUN_0058c3b0` |
| **Proposed name** | `Combat_ApplyPhysicsImpulseFromHit_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | (none) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_0058c3b0_Combat_ApplyPhysicsImpulseFromHit_Inferred.md` |
| **System** | `combat` / physics impulse on hit |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Apply a scaled physics impulse to a target from a combat hit**, using `CVOGPhysicsBase` components (RTTI-sealed) and world-position delta.

Called from `Client_Combat_ApplyHit_Inferred` (`0x004d78e0`) on type-**3** targets when host flag / damage gates allow, and from two other combat sites (`00618270`, `0061b6f0`).

### Control flow

1. `attackerPhys = dynamic_cast<CVOGPhysicsBase*>(attacker)` (`__RTDynamicCast` RTTI **High**).
2. If `target == null` → return.
3. Attacker orient: if cast ok, `vtbl+0x1a0` → 4 floats; else zeros.
4. Resolve target physics:
   * Type **0x0e** (vehicle): cast target → `CVOGPhysicsBase`.
   * Else: try `target->vtbl+0x214()` → phys pointer @ `+0x250`; else cast target; optional early-out if linked character TFID resolves with flag `char+0x6b9 != 0` (immune/skip — **Probable**).
5. If no phys → return.
6. Gate: `phys[2] != 0` and `FUN_00418d10()==0` and `FUN_0040d080()==0`.
7. Direction:
   * `Object_GetWorldPositionPtr` target pose.
   * If attacker orient magnitude² ≤ eps (`_DAT_009d4d38`, overlapping global — **Tentative** value): use forward from `FUN_00404a20` + `FUN_004e8a40`.
   * Else: normalize (targetPos − attackerOrient) when mag > eps.
8. Scale direction by `param_3` (damage-derived scale from parent); add vertical boost `ABS(param_3) * DAT_00af3284` (`1.0f` — **High** `read_memory`).
9. Multiply by `FUN_00404d10()` scalar (mass/global factor — **Probable**).
10. `phys->vtbl+0x40()` prep; accumulate impulse origin with `param_4` offsets at rigid body `+0x70..`; `FUN_0058d980(dir, point)` apply.

**Not** HP/shield apply (`004d78e0` body), not multi-target walk, not floater enqueue.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0058c3b0` |
| Callers | `get_function_callers` → `004d78e0`, `00618270`, `0061b6f0` |
| Parent dual | `A_aa_004d78e0_*` impulse arm |
| Constants | `read_memory` `0x00af3284` = `1.0f`; `0x009d4d38` overlap caution |
| RTTI | `CVOGPhysicsBase`, `CVOGCharacter`, `CVOGClonedObjectBase` in body |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0058c3b0` |
| Function record | `docs/reconstruction/functions/aa_0058c3b0_FUN_0058c3b0.md` |

**This pass:** live decompile; callers; RTTI; constant read. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
void Combat_ApplyPhysicsImpulseFromHit_Inferred(
    void *attacker,     // param_1 — cast to CVOGPhysicsBase
    int *target,        // param_2 — object*
    float scale,        // param_3 — impulse scale (damage-derived)
    float *add_point);  // param_4 — 4-float offset added to body contact
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `__RTDynamicCast` → `CVOGPhysicsBase` / `CVOGCharacter` | Type gates |
| `vtbl+0x1a0` / `+0x214` / phys `+0x40` | Orient / component / prep |
| `Object_ResolveFromTFID` / `TFID_NotEquals` | Character link skip path |
| `FUN_00404c90` | World position |
| `FUN_00404a20` / `FUN_004e8a40` | Forward when orient ~0 |
| `FUN_00404d10` | Impulse scalar |
| `FUN_00418d10` / `FUN_0040d080` | Pre-impulse gates |
| `FUN_0058d980` | Apply impulse at point |

| Caller | Role |
|---|---|
| `0x004d78e0` | Hit apply type-3 impulse |
| `0x00618270` / `0x0061b6f0` | Other combat impulse sites |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| RTTI attacker/target phys | Yes |
| Type 0xe vs character-link branch | Yes |
| Direction normalize + scale | Yes |
| `0058d980` apply | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Combat hit → physics impulse | **High** | parent + RTTI |
| `CVOGPhysicsBase` cast | **High** | named RTTI |
| Scale param is damage-derived | **Probable** | parent dual context |
| `DAT_00af3284 == 1.0f` | **High** | memory |
| Eps at `009d4d38` exact float | **Tentative** | overlapping symbol |
| Product name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Product names of gate helpers `00418d10` / `0040d080` / `0058d980`.
2. Exact eps constant (symbol overlap).
3. Runtime impulse magnitude capture not run.

**Verdict:** **accept-with-gaps** — impulse CF + RTTI High.
