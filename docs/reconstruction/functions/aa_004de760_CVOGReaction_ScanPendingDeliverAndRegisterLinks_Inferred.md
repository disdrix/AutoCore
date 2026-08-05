# Function record: CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de760` |
| **Canonical name** | `CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred` |
| **Prior / Ghidra name** | `FUN_004de760` |
| **Address** | `0x004de760`–`0x004de9e6` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / object-hash links |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W23-M OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_004de760`
- **Rejected:** `Mission_CVOGObjectiveRequirement_RTTI_Type_Descriptor` (coverage false positive — worker, not typeinfo)
- Prior string alias: `Named_VOG_DEBUG_STOP_004de760`

## Purpose

Host method: under **TraversalLock** on the character's **pending objectives** hash (`character+0x55c`), scan evaluators for **Deliver (type 3)** requirements that match `host+0xfc`, then for matching world objects re-register object-hash link entries via `FUN_004dbef0` with mode **5** (predicate false) or **8** (true).

Used from Patrol init-active, Deliver-related host paths, post give-item, and deferred host queues.

## Signature (sealed)

```c
// __thiscall  ECX = host*; ret 8
void CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred(
    void *host,             // this ECX — RegisterObjectHashEntry host
    void *character,        // stack+4 — pending hash at +0x55c
    void *optionalObject);  // stack+8 — null => scan host list at +0xe4e8
```

## Layout (touched)

| Object | Off | Role |
|---|---:|---|
| character | `+0x55c` | pending objectives CNDHash* |
| hash | `+0x1d` | TraversalLock |
| hash | `+0x14` | first node |
| node | `+0x08` / `+0x14` | entry* / next |
| objective | `+0x158/+0x15c` | evaluator vector |
| deliver | `+0x18/+0x1c` | match keys |
| host | `+0xfc` | filter vs deliver `+0x1c` |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004de760_FUN_004de760.md` |
| Annotated | `docs/reconstruction/raw/aa_004de760_FUN_004de760.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_004de760.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_004de760_CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004de760_CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.md` |
| Function alias | `docs/reconstruction/functions/aa_004de760_FUN_004de760.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `FUN_007a4480` | lock error log |
| Callee | `__RTDynamicCast` | Deliver cast |
| Callee | `FUN_004dbef0` | `CVOGReaction_RegisterObjectHashEntry_Inferred` |
| Caller | `CVOGObjectiveRequirement_Patrol_InitActive` | `0x0060e3d0` |
| Caller | `FUN_00610e60` | Deliver-related |
| Caller | `FUN_004dea70` | host queue drain |
| Caller | `FUN_0080af70` | give-item path |
| Caller | `FUN_0092a440` | additional |

## Confidence

| Claim | Level |
|---|---|
| CF: lock → walk pending → type3 Deliver → match → register 5/8 → unlock | **High** |
| ABI thiscall + `ret 8` | **High** |
| Pending hash `+0x55c` / lock `+0x1d` | **High** |
| Deliver type code 3 | **High** (sealed peer + this unit) |
| Register modes 5/8 constants | **High** |
| Product English of host `+0xfc` / modes 5/8 | **Inferred / open** |
| Runtime / bit-exact | **Open** |
