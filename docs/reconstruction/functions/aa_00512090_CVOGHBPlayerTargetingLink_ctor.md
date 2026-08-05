# Function record: CVOGHBPlayerTargetingLink_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512090` |
| **Canonical name** | `CVOGHBPlayerTargetingLink_ctor` (inferred) |
| **Ghidra name** | `FUN_00512090` |
| **Address** | `0x00512090`–`0x005120a8` (`ret 4`; pad `0x005120a9+`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / combat-target / HB |
| **Completion status** | **Dual A/B complete** (2026-07-29 OWN-ONLY) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00512090`
- `Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_00512090`
- Prior scaffold human plate treated DriveControlTick chain; **sole direct caller** is `Object_SetSelectedTarget` (`0x005172d0`), itself reachable from drive/AI/net paths.

## Purpose

Construct the **self-side** `CVOGHBPlayerTargetingLink` heartbeat object: run base targeting HB ctor `FUN_00604d40(attachOwner)`, then install subclass vtbl **`0x009cdfd4`**. Returns `this`. Object size **`0x28`** at the sole call site.

## Signature (image-sealed)

```c
// __thiscall ECX=this, stack attachOwner, ret 4, returns this
void *CVOGHBPlayerTargetingLink_ctor(void *this, void *attachOwner);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00512090_FUN_00512090.md` |
| Annotated | `docs/reconstruction/raw/aa_00512090_FUN_00512090.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBPlayerTargetingLink_ctor.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_00512090.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00512090_CVOGHBPlayerTargetingLink_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00512090_CVOGHBPlayerTargetingLink_ctor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00512090_FUN_00512090.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller (only) | `0x005172d0` / site `0x00517374` | `Object_SetSelectedTarget` — self link after `new(0x28)` |
| Callee | `0x00604d40` | Base targeting HB ctor (also used alone for target-side HB) |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Object size (caller) | `0x28` | High |
| Derived vtbl | `0x009cdfd4` | High |
| Base vtbl (pre-override) | `0x009cdfb0` | High (base leaf / contrast dump) |
| Vtbl slots 0,7 differ from base | `0x0051b870` / `0x0051b850` vs base | High (addresses only) |

## Confidence

| Claim | Level |
|---|---|
| Control flow (base → vtbl → return this) | **High** |
| ABI thiscall + ret 4 + attachOwner stack | **High** |
| Class family `CVOGHBPlayerTargetingLink` | **High** (RTTI on purge sibling) |
| Product ctor spelling | **Tentative / Inferred** |
| Base field init / virtual bodies | **Out of scope** (other VAs) |
