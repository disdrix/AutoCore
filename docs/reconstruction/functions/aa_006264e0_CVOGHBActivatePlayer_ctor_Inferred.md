# Function record: CVOGHBActivatePlayer_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006264e0` |
| **Canonical name** | `CVOGHBActivatePlayer_ctor_Inferred` |
| **Ghidra name** | `FUN_006264e0` |
| **Address** | `0x006264e0`–`0x0062652a` (**75 B** / `0x4B`; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / timed-actions / player activate |
| **Completion status** | **Dual A/B complete** (2026-07-29 OWN-ONLY W28-G) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_006264e0`
- Parent dual W27-F referred as "HB action ctor helper (0x2c)"

## Purpose

Construct the **activate-player heartbeat** object: base HB ctor, install vtbl `0x009e3168`, attach owner, clear `+0x28`, seed period fields from a period-source blob, store host backref at `+0x24`, return `this`. Sole factory: `Object_ActivatePlayerEnqueueHB_Inferred` after `operator_new(0x2c)`.

## Signature (image-sealed)

```c
// __thiscall ECX=this, stack (periodSrc, pOwner, pHost), ret 0xC, returns this*
void *CVOGHBActivatePlayer_ctor_Inferred(
    void *this, void *periodSrc, void *pOwner, void *pHost);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006264e0_FUN_006264e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006264e0_FUN_006264e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_ctor_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_006264e0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_006264e0_FUN_006264e0.md` |
| Dual report | `docs/agents/task-dual-ab-0051f890-006264e0-w28g-report.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller (only) | `0x00626890` / site `0x006269e8` | `Object_ActivatePlayerEnqueueHB_Inferred` |
| Callee | `0x00508200` | `CVOGHBBase_ctor` |
| Callee | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` |
| Callee | `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Object size (caller) | `0x2c` | **High** |
| Subclass vtbl | `0x009e3168` | **High** |
| Flag @ `+0x28` init 0 | byte | **High** |
| Host backref @ `+0x24` | `param_4` | **High** |
| Period min clamp | 0 → 1 | **High** |
| Product class English | open | **Inferred name only** |

## Confidence

| Claim | Level |
|---|---|
| Control flow / call order / ABI | **High** |
| Sole caller + size 0x2c | **High** |
| Field offsets | **High** |
| Product/PDB class name | **Tentative / Inferred** |
| Nested vtbl method English | **Out of scope** |
