# Function record: CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b850` |
| **Canonical name** | `CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget` (inferred) |
| **Ghidra name** | `FUN_0051b850` |
| **Address** | `0x0051b850`–`0x0051b861` (bare `ret`; pad `0x0051b862+`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / targeting link / object combat-target |
| **Completion status** | **Dual A/B complete** (2026-07-29); **gap-fill** raw/annotated/clean/function **2026-08-05** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0051b850`
- Derived vtbl slot 7 of `PTR_FUN_009cdfd4` (`0x009cdff0`)

## Purpose

Clear the owning entity's **selected-target pointer** (`owner+0xA0`) when this virtual runs, if `this+0x18` (owner) is non-null. Base family slot 7 is a nop (`FUN_0056f570`); only the self-side player targeting HB performs this clear.

## Signature (image-sealed)

```c
// __thiscall ECX=this, no stack args, bare ret
void CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget(void *this);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051b850_FUN_0051b850.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b850_FUN_0051b850.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_0051b850.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md` |
| Scaffold / FUN record | `docs/reconstruction/functions/aa_0051b850_FUN_0051b850.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| DATA xref | `0x009cdff0` | Derived vtbl slot 7 → this |
| Code callers | none | Virtual dispatch only |
| Callees | none | Leaf |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Body size | 18 B through `c3` | **High** |
| Owner field | `this+0x18` | **High** |
| Selected target | `owner+0xA0` | **High** (SetSelectedTarget dual) |
| Derived vtbl | `0x009cdfd4` | **High** |
| Slot 7 entry | `0x009cdff0` → `0x0051b850` | **High** |
| Base slot 7 | `0x0056f570` empty | **High** |

## Confidence

| Claim | Level |
|---|---|
| Control flow (null-check owner → store 0 at +0xA0) | **High** |
| ABI thiscall ECX-only bare ret | **High** |
| Vtbl slot 7 derived-only override | **High** |
| Field identity `+0xA0` = selected target | **High** |
| Product virtual English name | **Tentative / Inferred** |
| Exhaustive slot-7 dispatch catalog | **Open** |
