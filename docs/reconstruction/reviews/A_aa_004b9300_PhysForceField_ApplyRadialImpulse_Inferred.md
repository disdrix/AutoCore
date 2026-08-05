# Review A (reconstruction fidelity): `aa_004b9300` PhysForceField_ApplyRadialImpulse_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b9300` |
| **VA** | `0x004b9300` |
| **Canonical name (Ghidra)** | `FUN_004b9300` |
| **Proposed name** | `PhysForceField_ApplyRadialImpulse_Inferred` (**High** role; product English absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_004b9300` — mis-chain; not audio |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004b9300_PhysForceField_ApplyRadialImpulse_Inferred.md` |
| **System** | `physics` / radial force / explosion impulse |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Apply a parameterized radial (or directed) impulse field** from a force-action object (`this`) onto nearby physics objects, then optionally queue a follow-up force record for certain action types.

### Gates

1. `this+0x2c` (physics world / utils ctx) ≠ 0 — outer gate for whole body
2. Primary radial path also needs `this+0x60` (force params*) ≠ 0
3. Target object: stack `param_2`, else `this+0x10`; null → return
4. Target flag: `(obj[+0x17c] >> 5) & 1` must be set (`param_2[0x5f]` bit 5) — else return

### Primary path (`+0x60` present)

1. Load base direction from params: `params[+0x10/+0x14/+0x18]` → vec3, w=0
2. `physHost = target->vtbl[+0x1c8]()`; if `physHost[+8] ≠ 0`:
   - Center = `Object_GetWorldPositionPtr` (`00404c90`) on that host
   - If `params[+0x24]` char ≠ 0: transform direction by target orient via `Object_GetWorldOrientQuatPtr` (`00404a20`) + `Math_QuatTransformPoint` (`004e8bf0`) with identity-ish `DAT_00b03700`
3. Scale direction by `params[8]` (float at params `+0x20`)
4. `CVOGPhysicsUtils_GetObjectsInArea(this+0x2c, center, *params /*radius*/, outList, mode=2, filter=1)` — sphere-ish mode
5. For each hit where `node[+0x40] == 0` (not filtered-out):
   - Position from def physics `+0xb0` (or alternate offset path if `node[2]==0`)
   - Distance; if `dist > eps` (`_DAT_009cb2b4` = float bits `0x34000000` ≈ 2⁻²³): normalize dir to target; else default unit Y
   - Falloff scalar from `params[10]` (**int-as-float**):
     - `1` (`1.4013e-45`): linear `(1 - dist/radius) * strength`
     - `2` (`2.8026e-45`): quadratic `strength * (1 - dist/radius)²`
     - else: constant `strength` (`params[1]`)
   - Impulse = `( (1 - blend)*unitDir + blend*baseDir ) * falloff` where blend = `params[8]`
   - If `params[+0x25]`: scale by `1/mass` from `*(def+0x3c)+0x2c`
   - Ready gates `FUN_005070d0` / vtbl+0x40; optional second ready; apply via **`(*(phys+0x3c))->vtbl[+0x5c](&impulse)`** (physics apply-impulse path; related `CVOGPhysics_ApplyImpulseVector` family)
6. Allocate `0x40` record (params ptr, dir, center, flags), push `FUN_004eae00`, free list `FUN_00691630`

### Secondary path (types 1 / 0x10 / 0x11)

When `this+0x28 ∈ {1, 0x10, 0x11}` and target non-null:

- Resolve TFID from `target[+0x40..+0x4c]` via `Object_ResolveFromTFID`
- Dual vtbl `+0x144` on resolved + target
- Build nested `0x40` + `0x30` param pod (defaults from globals `DAT_00aaa7ac`, `DAT_00a0f6a4`, `DAT_00b03700..0c`, `DAT_00a0f298`), copy resolved object fields `+0x80..+0x8c`, flag byte 1, push `FUN_004eae00`

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004b9300` |
| Raw / annotated / clean | `aa_004b9300` three-rep |
| Function record | `docs/reconstruction/functions/aa_004b9300_FUN_004b9300.md` |
| Epsilon | `read_memory` `0x009cb2b4` → `00 00 00 34` |
| GetObjectsInArea | `A_aa_004ea350_CVOGPhysicsUtils_GetObjectsInArea.md` (caller listed) |
| Quat transform | `A_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md` |
| Position / orient getters | `A_aa_00404c90`, `A_aa_00404a20` |

**This pass:** live decompile; 2 xrefs; memory epsilon. **Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature

```c
// thiscall: ECX = force / explosion action object
// Stack: optional target object* (null → this+0x10)
void __thiscall PhysForceField_ApplyRadialImpulse_Inferred(
    void *forceAction,   // ECX
    void *targetObj);    // Stack[0x4], optional
```

SEH (`LAB_009a156f`).

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_00404c90` | World position ptr |
| `FUN_00404a20` | World orient quat ptr |
| `FUN_004e8bf0` | Quat transform point |
| `FUN_004ea350` | GetObjectsInArea (mode 2, filter 1) |
| `FUN_005070d0` / `FUN_005070b0` | Physics readiness |
| `FUN_004eae00` | Queue force record |
| `FUN_00691630` | Free area result list |
| `Object_ResolveFromTFID` | Secondary path resolve |
| `operator_new` | 0x40 / 0x30 records |

Callers (2): `FUN_004b9af0`, `FUN_00518590`.

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| World + params gates | Yes |
| Target + flag bit 5 | Yes |
| Center / optional orient | Yes |
| GetObjectsInArea mode 2 filter 1 | Yes |
| Linear / quadratic / constant falloff | Yes |
| Mass scale optional | Yes |
| Impulse apply + queue record | Yes |
| Type 1/0x10/0x11 secondary queue | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Radial area impulse applicator | **High** | GetObjectsInArea + falloff math |
| `+0x60` = force params (radius, strength, dir, blend, modes) | **High** | all field uses |
| Falloff mode int 1/2 as float bits | **High** | decompiler float compare to 1/2 ulp patterns |
| Mode 2 = sphere-ish query | **High** | dual on `004ea350` |
| Scaffold audio alias wrong | **High** | no audio callees |
| Product class / reaction name | **Tentative** | `_Inferred` |
| Exact vtbl English for +0x5c apply | **Probable** | matches phys impulse family |
| Secondary path “attach to target TFID” English | **Probable** | layout + ResolveFromTFID |

---

## 7. Gaps / open

1. Product name of force-action class (`this` layout full seal).
2. Who owns queued `0x40` records from `004eae00`.
3. Full meaning of action type codes `0x10` / `0x11` vs `1`.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — impulse CF High; product names Tentative.
