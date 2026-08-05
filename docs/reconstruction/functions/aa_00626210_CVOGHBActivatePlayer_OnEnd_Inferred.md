# Function record: CVOGHBActivatePlayer_OnEnd_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626210` |
| **Canonical name** | `CVOGHBActivatePlayer_OnEnd_Inferred` |
| **Ghidra name** | `FUN_00626210` |
| **Address** | `0x00626210`–`0x0062623a` (**43 B** / `0x2B`; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / timed-actions / player activate |
| **Completion status** | **Dual A/B complete** (2026-07-29 OWN-ONLY W29-P) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00626210`
- Parent duals: “subclass vtbl method (host `+0x6c8` side effects)”

## Purpose

Activate-player heartbeat **OnEnd** virtual (`vtbl 0x009e3168 + 0x14`). When host backref is live and skip-flag `this+0x28` is clear: stamp **`host+0x6c8 = 1`** and call **`host.vtbl+0x18(1,1)`**. Always exits via empty `FUN_005081f0` tail.

## Signature (image-sealed)

```c
// __thiscall ECX=this (activate-player HB, size 0x2c)
// no stack args; void (tail-jmp empty RET)
void CVOGHBActivatePlayer_OnEnd_Inferred(void *this);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00626210_FUN_00626210.md` |
| Annotated | `docs/reconstruction/raw/aa_00626210_FUN_00626210.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_OnEnd_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00626210.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00626210_FUN_00626210.md` |
| Dual report | `docs/agents/task-dual-ab-00626210-006261e0-w29p-report.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| DATA install | `0x009e317c` | vtbl `0x009e3168` + **0x14** |
| Virtual callers | (none static) | dispatched by Stop / EndOrDestroy / list |
| Callee | `0x005081f0` | empty `RET` (tail-jmp) |
| Nested (not OWN) | host `vtbl+0x18` | notify with `(1,1)` |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Host backref | `this+0x24` | **High** (ctor W28-G) |
| Skip / reentrancy flag | `this+0x28` (byte) | **High** |
| Host complete flag | `host+0x6c8 = 1` | **High** |
| Host vcall | `+0x18` args `(1,1)` | **High** (args); English open |
| Empty tail | `FUN_005081f0` = `C3` | **High** |
| Product method English | open | **Inferred name only** |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / vtbl slot | **High** |
| Host flag write + gate | **High** |
| Product/PDB name | **Tentative / Inferred** |
| Host vfunc body English | **Out of scope** |
| Runtime | **Open** |
