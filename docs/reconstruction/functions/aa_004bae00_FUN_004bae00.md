# Function record: FUN_004bae00

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae00` |
| **Canonical name** | `FUN_004bae00` |
| **Named alias** | `Host_DualCNDHash_TraverseNextObject_Inferred` |
| **Address** | `0x004bae00`–`0x004bae63` inclusive (**100 B** / `0x64`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation (pick-list / SelectBestPick residual) |
| **Completion status** | **Dual A/B sealed** (MEGA-011 2026-08-05) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / superseded

| Name | Status |
|---|---|
| `FUN_004bae00` | Ghidra canonical (this record) |
| `Host_DualCNDHash_TraverseNextObject_Inferred` | **Preferred human name** (MEGA-011) |
| `Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00` | **Retired** wrong parent chain |

## Purpose

Single-step dual-CNDHash object enumerator: select hash by `listSelect` (0→host+0x8, ≠0→host+0x4), TraversalLock set, TraverseToNext payload (node+0xc), inline unlock `hash+0x1d=0`, return object* or NULL.

## Signature

```c
void* /* object* */ __thiscall FUN_004bae00(
    int host /* ECX */,
    char listSelect,
    int* cursor);
// RET 8; EAX = object*|0
```

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `Client_Interact_SelectBestPickTarget` `0x00490070` | 2 sites; ECX=`Client+0xBC`; flag 0 then 1 |
| Caller | 12 other host/sweep functions | 28 total UNCONDITIONAL_CALL |
| Callee | `CNDHash_TraversalLock_Set_Inferred` `0x00402c40` | dualed MEGA-110 |
| Callee | `FUN_004bc530` | TraverseToNext residual MEGA-029 |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_004bae00_FUN_004bae00.md`
- Annotated: `docs/reconstruction/raw/aa_004bae00_FUN_004bae00.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Host_DualCNDHash_TraverseNextObject_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_004bae00.cpp`
- Retired scaffold: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md`
- Named function record: `docs/reconstruction/functions/aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ assembly | **High** |
| ABI thiscall RET 8 | **Confirmed** |
| Dual list offsets / flag polarity | **High** |
| Parameter semantic names | **High** (role); product English **Tentative** |
| Types (full host class) | Tentative beyond `+0x4..+0xd` |
