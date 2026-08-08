# Function record: Object_ResolveTfIdVtbl1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0d0` |
| **Canonical name** | `Object_ResolveTfIdVtbl1dc_Inferred` |
| **Ghidra name** | `FUN_004bb0d0` |
| **Address** | `0x004bb0d0`–`0x004bb0f9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Classification** | thin wrapper (resolve + virtual get) |
| **Completion status** | **Sealed** — dual A/B 2026-08-04 WQ9R-D; ABI + CF + vtbl slot sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Resolve a TFID-like blob through `CVOGReaction_ResolveObjectTarget`, then return the result of **`obj->vtbl[+0x1dc]()`**. On resolve failure return **0**.

Same virtual slot as `Client_LookupObjectByTfid_Inferred` (`0x004bb0a0`), but **blob-pointer stack ABI** (`RET 4`) instead of three free stack args (`RET 0xc`).

## Signature (sealed)

```c
// ECX = resolve context (caller-supplied; body does not load it)
// stack blob*; cleaned by RET 4
void * __thiscall Object_ResolveTfIdVtbl1dc_Inferred(void *ctx, TFID_Head *pBlob);
```

| Param | Location | Meaning |
|---|---|---|
| `ctx` | `ECX` | resolve / reaction host tables |
| `pBlob` | `[esp+4]` | TFID head: `+0` lo, `+4` hi, `+8` bGlobal |
| return | `EAX` | `vtbl+0x1dc()` result, or `0` |

## Blob layout

| Offset | Width | Field |
|---|---|---|
| `+0` | `u32` | `dwCoidLo` |
| `+4` | `u32` | `dwCoidHi` |
| `+8` | `u8` | `bGlobal` |
| `+9..+15` | — | **not read** |

## Body hex (42 B)

```
8b4424048b5004528b108a40085250e88cfdffff85c0740d8b108bc8ff92dc010000c2040033c0c20400
```

- `FF 92 DC 01 00 00` = `CALL [EDX+0x1dc]`
- Twin of `0x004bb010` except slot `0x1d4` → `0x1dc` and resolve rel32.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.md`
- Annotated: `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ResolveTfIdVtbl1dc_Inferred.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_004bb0d0.cpp`
- Prior Named plate: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGHBAIBase_FindTargetToAttack_004bb0d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md`
- Report: `docs/agents/task-dual-ab-00943520-004bb0d0-wq9rd-report.md`

## Callers / callees

**Callees:** `CVOGReaction_ResolveObjectTarget` (`0x004bae70`); indirect `vtbl+0x1dc`.

**Callers (9 xrefs / 8 funcs):**

- `Skill_FilterTargetForResolveList_Inferred` `0x00550100` (sites `0x00550162`)
- `CVOGHBAIBase_FindTargetToAttack` `0x00638xxx` (`0x00639408`)
- `FUN_004c44c0`, `FUN_004c8780`, `FUN_005139f0` (×2), `FUN_00638be0`, `FUN_0080cfc0`, `FUN_00836410`

**Siblings:** `Object_ResolveFromTFID` `0x004bb950`; `Object_ResolveTfIdVtbl1d4_Inferred` `0x004bb010`; `Object_ResolveTfIdGetIdentity_Inferred` `0x004bb070`; `Client_LookupObjectByTfid_Inferred` `0x004bb0a0` (same `+0x1dc`, free-arg ABI).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| `RET 4` + ECX passthrough ABI | **High** |
| Blob +0/+4/+8 only | **High** |
| Virtual slot `+0x1dc` | **High** |
| Product name of `+0x1dc` | **Tentative** (`_Inferred`; matches Lookup sibling role) |
| Return type semantics | **Probable** (pointer / host-like unwrap) |
