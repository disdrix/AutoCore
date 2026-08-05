# Function record: CVOGHB_FixedPeriod1_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626530` |
| **Canonical name** | `CVOGHB_FixedPeriod1_ctor_Inferred` |
| **Ghidra name** | `FUN_00626530` |
| **Address** | `0x00626530`–`0x00626561` (**50 B** / `0x32`; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / timed-actions |
| **Completion status** | **Dual A/B complete** (2026-07-29 OWN-ONLY W29-O) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00626530`

## Purpose

Construct an HB subclass object: `CVOGHBBase_ctor` → vtbl **`0x009e3188`** → `AttachOwnerObject` → seed **`+0x08 = arg5`** → `SetPeriodAndCounter(1, true)` → return `this`. Sole factory site uses `operator_new(0x50)` (parent undelimited).

## Signature (image-sealed)

```c
// __thiscall ECX=this, stack (pOwner, arg3, arg4, arg5), ret 0x10, returns this*
void *CVOGHB_FixedPeriod1_ctor_Inferred(
    void *this, void *pOwner, uint32_t arg3, uint32_t arg4, uint32_t arg5);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00626530_FUN_00626530.md` |
| Annotated | `docs/reconstruction/raw/aa_00626530_FUN_00626530.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHB_FixedPeriod1_ctor_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00626530.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00626530_CVOGHB_FixedPeriod1_ctor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00626530_CVOGHB_FixedPeriod1_ctor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00626530_FUN_00626530.md` |
| Dual report | `docs/agents/task-dual-ab-00581500-00626530-w29o-report.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller (only code xref) | site `0x006267f1` | undelimited parent after `new(0x50)` |
| Callee | `0x00508200` | `CVOGHBBase_ctor` |
| Callee | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` |
| Callee | `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Object size (caller) | `0x50` | **High** (call-site) |
| Subclass vtbl | `0x009e3188` | **High** |
| Field `+0x08` | `arg5` dword | **High** |
| Period | fixed **1** | **High** |
| Product class English | open | **Inferred name only** |

## Confidence

| Claim | Level |
|---|---|
| Control flow / call order / ABI | **High** |
| Sole code xref + size 0x50 | **High** |
| Unused arg3/arg4 semantics | **Open** |
| Product/PDB class name | **Tentative / Inferred** |
| Nested vtbl method English | **Out of scope** |
