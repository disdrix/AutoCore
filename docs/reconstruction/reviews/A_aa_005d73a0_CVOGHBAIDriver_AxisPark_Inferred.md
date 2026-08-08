# Review A (reconstruction fidelity): `aa_005d73a0` CVOGHBAIDriver_AxisPark_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d73a0` |
| **VA** | `0x005d73a0`–`0x005d73e7` inclusive (**72 B** / `0x48`) |
| **Canonical name** | `CVOGHBAIDriver_AxisPark_Inferred` |
| **Ghidra name** | `FUN_005d73a0` |
| **Review date** | `2026-08-05` (MEGA-015 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md` |
| **System** | input-drive-control / HB AI driver axis park |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address` + `analyze_control_flow` + `search_strings` + `batch_decompile` (callees) + ctor `FUN_005d7bb0`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Virtual **axis-park** method on **`CVOGHBAIDriver`**: zero steer + longitudinal, assert handbrake, clear weapon fire mask, push axes into the VehicleAction controller, then run residual owner-counter cleanup. Used as **`vtbl+0x10`** on the driver HB AI object bound to vehicle at **`this+0xbc`**.

```text
vehicle = this+0xbc
SetSteerInput(vehicle, 0)
SetLongitudinalInput(vehicle, 0)
SetHandbrake(vehicle, 1)
FireWeapons(this, mayFire=0, unused=0)   // RET 8; clears fire mask
PushDriveAxesToController(vehicle)
tail → FUN_005cc560(this)
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d73a0_FUN_005d73a0.md` (+ MEGA-015 append) |
| Annotated | `docs/reconstruction/raw/aa_005d73a0_FUN_005d73a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIDriver_AxisPark_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d73a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d73a0_FUN_005d73a0.md` |
| Named record | `docs/reconstruction/functions/aa_005d73a0_CVOGHBAIDriver_AxisPark_Inferred.md` |
| Live | decompile ≡ CF; body hex; vtbl DATA; RTTI Driver; ctor install; FireWeapons RET 8 |

---

## 3. Signature (sealed)

```c
// ECX = CVOGHBAIDriver* this; no stack args; void; tail JMP FUN_005cc560
void __thiscall CVOGHBAIDriver_AxisPark_Inferred(void *self);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`MOV ESI,ECX`) | **High** |
| vehicle | **`[ESI+0xbc]`** | **High** |
| stack args | **none** | **High** |
| exit | tail **`JMP 0x005cc560`** | **High** |
| FireWeapons ABI | **`RET 8`** (two stack dwords) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SetSteer(0) on vehicle | **Yes** | **High** |
| SetLong(0) on vehicle | **Yes** | **High** |
| SetHandbrake(1) on vehicle | **Yes** | **High** |
| FireWeapons(0,0) on this | **Yes** | **High** |
| PushDriveAxes on vehicle | **Yes** | **High** |
| Tail FUN_005cc560 on this | **Yes** | **High** |
| Product method English | open | **Inferred** |
| Virtual caller inventory | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** (vtable method) |
| External direct callers | **none** |
| Xrefs | 1 DATA @ `0x009db03c` (`*[vtbl+0x10]`) |
| Host | `CVOGHBAIDriver` RTTI + ctor `FUN_005d7bb0` → vtbl `009db02c` |
| Callees | 5 dualed/named axis/fire + residual `FUN_005cc560` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| RTTI `.?AVCVOGHBAIDriver@@` | **Yes** |
| Axis park SetSteer(0)+SetLong(0)+HB(1)+Push | **Yes** |
| FireWeapons may-fire cleared | **Yes** |
| Distinct from UI thr/steer park / SetSteer-only park | **Yes** |
| Product scoped method string | **No** |

**Decision:** promote **`CVOGHBAIDriver_AxisPark_Inferred`**. Reject player DriveControlTick, mission-UI park, pure SetSteer-only `00636ba0`, FireWeapons merge, DoLogic merge.

---

## 7. Gaps / open

1. Product English method name.
2. Sites that virtual-call `vtbl+0x10`.
3. Residual dual of `FUN_005cc560`.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
