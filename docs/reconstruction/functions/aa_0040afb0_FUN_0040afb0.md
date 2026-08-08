# Function record: FUN_0040afb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040afb0` |
| **Canonical name** | `FUN_0040afb0` |
| **Named form** | `Host_LookupObjectByKey_PairTable30_Inferred` |
| **Address** | `0x0040afb0`–`0x0040afed` (**62 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation (shared pair-table leaf) |
| **Completion status** | **Dual sealed MEGA-028** — raw/annotated/clean + A/B; runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

| Kind | Name |
|---|---|
| Ghidra | `FUN_0040afb0` |
| Named | `Host_LookupObjectByKey_PairTable30_Inferred` |
| Retired scaffold | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0040afb0` |

## Purpose

Linear-scan lookup of a keyed `object*` in the host pair table at **`+0x30`** (count **`+0x34`**, stride 8). Writes match to `*out` or NULL. Shared by soft-cast hit resolve, GetObjectsInArea, and collision material pair keys.

## Signature (sealed)

```c
// __thiscall; RET 8; EAX = outObject
void* __thiscall FUN_0040afb0(void* host, void** outObject, int key);
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_0040afb0_FUN_0040afb0.md`
- Annotated: `docs/reconstruction/raw/aa_0040afb0_FUN_0040afb0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Host_LookupObjectByKey_PairTable30_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0040afb0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md`
- Named record: `docs/reconstruction/functions/aa_0040afb0_Host_LookupObjectByKey_PairTable30_Inferred.md`
- Report: `docs/agents/task-dual-ab-0040afb0-mega-028-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_00925820` | soft-cast / interaction parent; key 1 @ `0x00925c8f` |
| Caller | `FUN_004ea350` | GetObjectsInArea ×3; key 1 |
| Caller | `FUN_005d9ea0` | Drive contact prep; keys 3/4 |
| Caller | `FUN_005da0a0` | Contact; key 3 |
| Caller | `FUN_005911b0` | key 3 @ `0x00593160` |
| Caller | `FUN_00642b70` | key 1 |
| Caller | `FUN_00932c80` | key 1 |
| Sites | `0x005dd718`, `0x005dd80d` | key 1 (function owner residual) |
| Callees | *(none)* | leaf |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ assembly | **High** |
| ABI RET 8 / out-param / offsets | **High** |
| Parameter semantic names | **High** (role) / product host type **Tentative** |
| Types | **Probable** (`void*` value; int key) |
| Product symbol | **Inferred** |
