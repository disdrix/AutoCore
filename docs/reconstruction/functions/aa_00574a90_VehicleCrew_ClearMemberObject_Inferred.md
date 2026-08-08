# Function record: VehicleCrew_ClearMemberObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574a90` |
| **Canonical name** | `VehicleCrew_ClearMemberObject_Inferred` |
| **Ghidra symbol** | `FUN_00574a90` |
| **Address** | `0x00574a90` |
| **Body** | `0x00574a90`–`0x00574af4` exclusive (**100** B / `0x64`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` (crew roster) |
| **Completion status** | **Sealed** — dual A/B accept-with-gaps (WQ9D-G 2026-08-04) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00574a90`
- Twins: `VehicleCrew_ContainsMember_Inferred` (`0x005749d0`); insert `FUN_005755b0` (OWN WQ9D-D)
- Callee: `FUN_00520330` (set `this+0xCB0`)

## Purpose

On COID match in the 4-slot crew table at `host+0x198`, null the live object* slot and clear `candidate+0xCB0` (crew-host back-link). Partial clear: does not free COID sentinel or decrement count. Sole retail call from `Client_ClearObjectReferences`.

## Signature (sealed)

```c
// __thiscall; RET 4; AL bool
uint8_t VehicleCrew_ClearMemberObject_Inferred(void *crewHost, void *candidate);
```

## Layout

| Offset | Field |
|---|---|
| host+0x198 + i*0x10 | COID lo / hi (dwords 0/1) |
| host+(i+0x1A)*0x10 | object* (nulled on hit) |
| candidate+0xCB0 | crew-host back-ptr (set 0 on hit) |
| candidate COID | SharedBase offBase +0x164/+0x168 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00574a90_FUN_00574a90.md` (+ WQ9D-G re-verify)
- Annotated: `docs/reconstruction/raw/aa_00574a90_FUN_00574a90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/VehicleCrew_ClearMemberObject_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00574a90.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md`
- Function FUN: `docs/reconstruction/functions/aa_00574a90_FUN_00574a90.md`

## Callers / callees

| Direction | Targets |
|---|---|
| **Callees** | `FUN_00520330` |
| **Callers (1)** | `Client_ClearObjectReferences` / `FUN_00944d50` |
| **Xrefs** | 1 UNCONDITIONAL_CALL |

## Confidence

| Claim | Level |
|---|---|
| Body size + RET 4 both exits | **Confirmed** |
| 4×0x10 COID scan @ +0x198 | **Confirmed** |
| object* clear @ (slot+0x1A)*0x10 | **Confirmed** |
| FUN_00520330 ECX=candidate, arg=0 | **Confirmed** (bytes + ECX live) |
| Does not free COID / count | **Confirmed** |
| Product English | **Inferred** |
| Runtime / differential | Open |
