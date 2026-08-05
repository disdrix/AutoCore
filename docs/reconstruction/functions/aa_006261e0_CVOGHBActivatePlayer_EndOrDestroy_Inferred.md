# Function record: CVOGHBActivatePlayer_EndOrDestroy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006261e0` |
| **Canonical name** | `CVOGHBActivatePlayer_EndOrDestroy_Inferred` |
| **Ghidra name** | `FUN_006261e0` |
| **Address** | `0x006261e0`–`0x00626202` (**35 B** / `0x23`; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | heartbeat / timed-actions / player activate |
| **Completion status** | **Dual A/B complete** (2026-07-29 OWN-ONLY W29-P) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_006261e0`
- Overrides shared base slot usually filled by `CVOGHBBase_EndOrDestroy` (`0x005083f0`)

## Purpose

Activate-player heartbeat **EndOrDestroy** virtual (`vtbl 0x009e3168 + 0x18`). When `flag_onEnd==0`, **pre-calls** own OnEnd (`vtbl+0x14`) so host notify still runs (base skips OnEnd on flag0==0). Always chains to `CVOGHBBase_EndOrDestroy(flag_onEnd, flag_hard)`.

## Signature (image-sealed)

```c
// __thiscall ECX=this
// stack: flag_onEnd, flag_hard
// ret 8; void
void CVOGHBActivatePlayer_EndOrDestroy_Inferred(
    void *this, uint32_t flag_onEnd, uint32_t flag_hard);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006261e0_FUN_006261e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006261e0_FUN_006261e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_EndOrDestroy_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_006261e0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_006261e0_CVOGHBActivatePlayer_EndOrDestroy_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_006261e0_FUN_006261e0.md` |
| Dual report | `docs/agents/task-dual-ab-00626210-006261e0-w29p-report.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| DATA install | `0x009e3180` | vtbl `0x009e3168` + **0x18** |
| Virtual callers | (none static) | HB end / host-driven teardown |
| Callee | `0x005083f0` | `CVOGHBBase_EndOrDestroy` |
| Nested virtual | `vtbl+0x14` | `CVOGHBActivatePlayer_OnEnd_Inferred` when flag0==0 |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| `ret 8` | two stack args | **High** |
| Pre-OnEnd only if flag0==0 | char test on first stack arg | **High** |
| Always base EndOrDestroy | relative call sealed | **High** |
| Product method English | open | **Inferred name only** |

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / vtbl slot | **High** |
| Double-OnEnd avoidance design | **High** (relative to sealed base) |
| Product/PDB name | **Tentative / Inferred** |
| Runtime | **Open** |
