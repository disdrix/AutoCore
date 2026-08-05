# Function record: CVOGHB_TargetingLink_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604d40` |
| **Canonical name** | `CVOGHB_TargetingLink_ctor_Inferred` |
| **Address** | `0x00604d40`–`0x00604dab` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / combat-target (targeting-link HB) |
| **Completion status** | **Dual A/B sealed 2026-07-29** — ABI + constants + dual-period High; product type English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Prior scaffold names** | `FUN_00604d40`; `Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00604d40` (**rejected** as product role) |

## Purpose

Shared ctor for **targeting-link** heartbeat objects: base ctor → vtbl `PTR_FUN_009cdfb0` → attach owner → type tag **2** → periods (**+0x08=1000**, **+0x0C=−1000**) → `Start`. Target-side keeps this vtbl; self-side wrapper `FUN_00512090` upgrades to PlayerTargetingLink vtbl `009cdfd4` after return. Allocation, partner cross-link (`+0x24`), and Enqueue are **caller** responsibilities.

## Signature (machine-sealed)

```c
CVOGHBBase* __thiscall CVOGHB_TargetingLink_ctor_Inferred(
    CVOGHBBase* thisHb,  // ECX; pre-allocated 0x28
    void* pOwner);       // stack; attached at +0x18
// ret 4; returns thisHb
```

## Sealed facts

| Claim | Level |
|---|---|
| Control flow / call order | **High** |
| ABI thiscall + ret 4 + return this | **High** |
| Vtbl `0x009cdfb0` | **High** |
| Type tag `+0x1C = 2` | **High** (value) |
| Dual period +0x08=1000 / +0x0C=−1000 | **High** |
| Shared core for PlayerTargetingLink self ctor | **High** |
| Product C++ type name for `009cdfb0` | **Tentative / Inferred** |
| OnHeartBeat English (`0x00604dd0`) | **Not owned** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00604d40_FUN_00604d40.md`
- Annotated: `docs/reconstruction/raw/aa_00604d40_FUN_00604d40.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHB_TargetingLink_ctor_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00604d40_CVOGHB_TargetingLink_ctor_Inferred.md`
- Legacy scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00604d40.cpp` (superseded)

## Callers / callees

| Direction | Symbol / VA | Notes |
|---|---|---|
| Callee | `CVOGHBBase_ctor` `0x00508200` | base layout init |
| Callee | `CVOGHBBase_AttachOwnerObject` `0x005083b0` | owner + list mgr |
| Callee | `CVOGHBBase_Start` `0x005081c0` | clear dormant + OnStart |
| Caller | `Object_SetSelectedTarget` `0x005172d0` | target-side HB of dual pair |
| Caller | `FUN_00512090` | self PlayerTargetingLink: call then vtbl `009cdfd4` |

## Gaps

- Product name / RTTI for vtbl `009cdfb0`
- Type-tag **2** English + consumers
- OnHeartBeat / dtor family duals
- Runtime / bit-exact
