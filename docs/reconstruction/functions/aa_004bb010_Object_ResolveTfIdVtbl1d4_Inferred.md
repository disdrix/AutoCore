# Function record: Object_ResolveTfIdVtbl1d4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb010` |
| **Canonical name** | `Object_ResolveTfIdVtbl1d4_Inferred` |
| **Ghidra name** | `FUN_004bb010` |
| **Address** | `0x004bb010`–`0x004bb039` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Classification** | thin wrapper (resolve + virtual get) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29; ABI + CF + vtbl slot sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Resolve a TFID-like blob through `CVOGReaction_ResolveObjectTarget`, then return the result of **`obj->vtbl[+0x1d4]()`**. On resolve failure return **0**. Used by CreateVehicle apply as the “object already present” gate (`pkt+0x90`) and by respawn special-event paths.

## Signature (sealed)

```c
// ECX = resolve context (caller-supplied; body does not load it)
// stack blob*; cleaned by RET 4
void * __thiscall Object_ResolveTfIdVtbl1d4_Inferred(void *ctx, TFID_Head *pBlob);
```

| Param | Location | Meaning |
|---|---|---|
| `ctx` | `ECX` | resolve / reaction host tables |
| `pBlob` | `[esp+4]` | TFID head: `+0` lo, `+4` hi, `+8` bGlobal |
| return | `EAX` | `vtbl+0x1d4()` result, or `0` |

## Blob layout

| Offset | Width | Field |
|---|---|---|
| `+0` | `u32` | `dwCoidLo` |
| `+4` | `u32` | `dwCoidHi` |
| `+8` | `u8` | `bGlobal` |
| `+9..+15` | — | **not read** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bb010_FUN_004bb010.md`
- Annotated: `docs/reconstruction/raw/aa_004bb010_FUN_004bb010.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ResolveTfIdVtbl1d4_Inferred.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_004bb010.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred.md`
- Report: `docs/agents/task-dual-ab-004bb010-00944b20-w17t-report.md`

## Callers / callees

**Callees:** `CVOGReaction_ResolveObjectTarget` (`0x004bae70`); indirect `vtbl+0x1d4`.

**Callers (5):**

- `Client_CreateVehicleObjectApply` `0x00812630`
- `ClientSpecialEvent_Respawn_Update` `0x00979730`
- `ClientSpecialEvent_Respawn_dtor` `0x00979c70`
- `FUN_00979290`
- `FUN_00979310`

**Xrefs:** 5.

**Siblings:** `Object_ResolveFromTFID` `0x004bb950` (no vtbl); `Object_ResolveTfIdGetIdentity_Inferred` `0x004bb070` (`+0x1d8`); `Client_LookupObjectByTfid_Inferred` `0x004bb0a0` (`+0x1dc`).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| `RET 4` + ECX passthrough ABI | **High** |
| Blob +0/+4/+8 only | **High** |
| Virtual slot `+0x1d4` | **High** |
| Product name of `+0x1d4` | **Tentative** (`_Inferred`) |
| Return type semantics | **Probable** (pointer / host object; CreateVehicle treats 0 as miss) |
