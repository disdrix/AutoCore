# Review A (reconstruction fidelity): `aa_00598650` VehicleAction_applyAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_00598650` |
| **VA** | `0x00598650` |
| **Canonical name** | `VehicleAction_applyAction` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00598650_VehicleAction_applyAction.md` |
| **System** | `input-drive-control` |
| **Verdict** | accept-with-gaps |

---

## 1. Purpose

Per-substep AA custom vehicle driver layered over Havok 2.3 `hkVehicleFramework` (vtbl slot **+0x14** of VehicleAction `0x009d54c4`). Identity strings `VehicleAction::applyAction` / `VehicleAction::havok code`. Signature: `__thiscall(this=VehicleAction*, param_2={dt, throttleInput})`. **Orchestration order (authoritative):** (1) idle/dead early-outs (data+0x7e, entity+0x103, bit1 base+0x180, idle **>0x77A1 ms**, base+0x18); (2) body state==6 early-out; (3) profile scopes; (4) **tickSubsystems(this+0x40)** first (framework preUpdate + 7 children + postTick); (5) **anti-sink** scan wheels stride **0xC0** min **wheel+0xB0**, if <0 raise chassis Y by -minComp; (6) **stage-1 steer ramp** `entity+0x618` → **VA+0x24** → wheelsDesc **+0x1c** (rate **VA+0x20 * dt * {1|2}**, clamp [-1,1]); (7) mode **0x02** (data+0x4ce): speedFactor=min(|v|/ **20** (DAT_00af3388),1) into **VA+0x28**, `hkpVehicleSteering_setSteeringAngle`; else velocity-coupled upright impulse when up·worldUp < **0.7** (DAT_00af3380) and >0.1; (8) `calcWheelTorque`; (9) `airStabilization`; (10) grounded helpers if not airborne (**VA+0x2c**); (11) anim vtbl+0x110; (12) dead/disabled boost tail. **VA+0x24 is steer ramp, NOT brake.** ~900-line clean; verified note `fn_00598650_applyAction.md`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00598650_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00598650_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleAction_applyAction.cpp` |
| Function record | `docs/reconstruction/functions/aa_00598650_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Orchestration order tickSubsystems→anti-sink→steer→torque→airStab` | High | Verified note + clean |
| `Stage-1: entity+0x618 → VA+0x24 → wheelsDesc+0x1c` | High | WI-MOV-002 / body |
| `VA+0x24 is steer ramp not brake` | High | Verified correction |
| `Mode 0x02 speedFactor |v|/20 not 0.6` | High | DAT_00af3388 read_memory |
| `Anti-sink min wheel+0xB0 <0 → raise Y` | High | Body step 5 |
| `Upright gate DAT_00af3380=0.7 non-mode-0x02` | High | Body + air-stab notes |
| `param_2[0]=dt param_2[1]=throttle for upright/boost` | High | Verified sig |
| `Full dead-boost impulse field seal` | Medium | DAT cluster residual |
| `Exact anim/helper FUN identities` | Medium | FUN_* residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| early-outs → tickSubsystems → anti-sink → stage-1 → mode branch → torque → airStab → tail | Yes |
| No invent service-brake torque in this fn | Yes |
| No invent hkDefaultEngine component | Yes |

---

## 5. Gaps / open

1. Seal dead/disabled boost DAT_00af3364..70 live values vs port.
2. Name FUN_005994e0 impulse applier and FUN_0053e090 grounded helper.
3. Bit-exact vs retail EXE deferred.

**Verdict:** accept-with-gaps
