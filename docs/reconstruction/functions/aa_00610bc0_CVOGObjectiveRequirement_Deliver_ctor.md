# Function record: CVOGObjectiveRequirement_Deliver_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00610bc0` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_ctor` |
| **Address** | `0x00610bc0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (Deliver requirement) |
| **Completion status** | **Dual A/B accept-with-gaps** — type=3 and +0x23 default sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Duals** | `A_aa_00610bc0_*`, `B_aa_00610bc0_*`, residual `a_00610bc0.md` |

## Purpose

Client-side constructor for **`CVOGObjectiveRequirement_Deliver`**. Chains base requirement ctor, sets Deliver vtable, requirement **type code 3**, and field defaults used by Deliver cargo-ready / inventory-event evaluators.

## Signature

```c
CVOGObjectiveRequirement_Deliver* __thiscall
CVOGObjectiveRequirement_Deliver_ctor(
    CVOGObjectiveRequirement_Deliver* this,  // ECX
    void* owner);                            // stack; stored at +0x4 by base
// RET 4; returns this
```

## Body (behavior)

1. `FUN_00637da0(owner)` — base: vtable `009e3bac`, `+0x4 = owner`
2. `+0x20 = +0x21 = +0x22 = +0x23 = 1`
3. `*this = PTR_FUN_009e0f24` (Deliver vtable)
4. `+0x0c = 3` (requirement type **Deliver**)
5. `+0x10 = -1` (CBIDItem), `+0x14 = 0` (NumToDeliver)
6. `+0x18 = -1` (TargetNPCCBID), `+0x1c = -1` (ContinentID)
7. return `this`

## Sealed facts

| Fact | Level |
|------|-------|
| type `+0x0c = 3` | **High** |
| `+0x23` default **1** (require-count) | **High** |
| Class Deliver (RTTI + XML + type) | **High** |
| Vtable `PTR_FUN_009e0f24` | **High** |
| Not Collect (type 2 / `009e12c4`) | **High** |

## Field defaults

| Off | Field | Default |
|----:|-------|---------|
| +0x0c | type | **3** |
| +0x10 | CBIDItem | −1 |
| +0x14 | NumToDeliver | 0 |
| +0x18 | TargetNPCCBID | −1 |
| +0x1c | ContinentID | −1 |
| +0x20 | GiveItemAtStart | 1 |
| +0x21 | TakeItemAtEnd | 1 |
| +0x22 | NPCTargetCompletes | 1 |
| +0x23 | require-count | **1** |

## Callers / callees

| Dir | Address | Note |
|-----|---------|------|
| Caller | `FUN_00547050` @ `0x00547385` | sole code xref (factory) |
| Callee | `FUN_00637da0` | base requirement ctor |

Related virtual methods (same vtable; not this body):

| VA | Role |
|----|------|
| `0x00611290` | OnInventoryEvent |
| `0x00610f20` | CargoReady |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00610bc0_FUN_00610bc0.md`
- Annotated: `docs/reconstruction/raw/aa_00610bc0_CVOGObjectiveRequirement_Deliver_ctor.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Deliver_ctor.cpp`
- Dual A/B + residual under `docs/reconstruction/reviews/`

## Confidence

| Claim | Level |
|---|---|
| Control flow / stores from image | **High** |
| type=3 / +0x23=1 | **Sealed High** |
| Class name from RTTI | **High** |
| English `+0x23` tag name | Probable (inferred) |
| Factory full type map | Open |
