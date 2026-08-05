# Function record: FUN_005bbc50 (scaffold alias)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbc50` |
| **Canonical name** | `ObjectMotion_HostTeardown_Inferred` |
| **Ghidra name** | `FUN_005bbc50` |
| **Address** | `0x005bbc50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object motion / reaction host teardown |
| **Completion status** | **Sealed** — dual A/B W30-S 2026-07-29; see promoted record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Promoted: **`ObjectMotion_HostTeardown_Inferred`**.  
Rejected scaffold: `Named_CalleeOf_Named_CalleeOf_Named_missileExplosion_005bbc50`.

## Purpose

Host teardown: free buffers, freelist-release all motion slots on `+0xa24`, free list sentinel.

## Signature (decompiler-derived)

```c
void __fastcall FUN_005bbc50(int param_1)  // ECX = host
```

## Artifacts

- Promoted record: `docs/reconstruction/functions/aa_005bbc50_ObjectMotion_HostTeardown_Inferred.md`
- Raw: `docs/reconstruction/raw/aa_005bbc50_FUN_005bbc50.md`
- Annotated: `docs/reconstruction/raw/aa_005bbc50_FUN_005bbc50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/ObjectMotion_HostTeardown_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005bbc50.cpp`

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x005be310` | `FUN_005be310` |
| Callee | `0x005b8340` | buffer clear |
| Callee | `0x005be2b0` | `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| Callee | `operator_delete` | heap free |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High (with noreturn gap on delete) |
| Role / name | High / Inferred product English |
