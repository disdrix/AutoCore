# Function record: AllocateNewObjectFromCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf120` |
| **Canonical name** | `AllocateNewObjectFromCbid` |
| **Ghidra name** | `FUN_004cf120` |
| **Address** | `0x004cf120`–`0x004cf296` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | sector-map / object-spawn (client) |
| **Classification** | worker (factory + optional template apply + host register) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29 W18-T; ABI + CF + plate name sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Allocate a new world object from a clonebase id (`cbid`), optionally overriding `cbid` and applying extras from a template id, initialize it, stamp host bookkeeping (`+0xe6e0` counter, `+0xe4e8` resolve ctx), and return the object pointer. Failure paths return **0** and may log **`allocatenewobjectfromcbid failed %d`**.

## Signature (sealed)

```c
// thiscall: ECX = sector-map host
// stack: cbid, templateId (-1 = none); RET 8
void * __thiscall AllocateNewObjectFromCbid(
    SectorMapHost *self,
    int cbid,
    int templateId);
```

| Param | Location | Meaning |
|---|---|---|
| `self` | `ECX` → `EDI` | host with `+0xe4e8`, `+0xe6e0/+0xe6e4` |
| `cbid` | `[esp+4]` | clonebase id; overwritten if template resolves |
| `templateId` | `[esp+8]` | `-1` skip template; else `FUN_00508e20` |
| return | `EAX` | new object*, or `0` |

## Plate / product name

| Evidence | Value |
|---|---|
| String VA | `0x00a7f228` |
| Text | `allocatenewobjectfromcbid failed %d` |
| Name confidence | **High** (`AllocateNewObjectFromCbid`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cf120_FUN_004cf120.md`
- Annotated: `docs/reconstruction/raw/aa_004cf120_FUN_004cf120.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AllocateNewObjectFromCbid.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_004cf120.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004cf120_AllocateNewObjectFromCbid.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cf120_AllocateNewObjectFromCbid.md`
- Report: `docs/agents/task-dual-ab-004bb1c0-004cf120-w18t-report.md`

## Callers / callees

**Callees:** `FUN_00508e20`, `CVOGReaction_GiveItemByCbid` (`0x0051a170`), `FUN_007a4480`, `FUN_00516720`, `FUN_00509c70`, `FUN_00512670`, `FUN_00512160`; virtuals `+8`, `+0x54`, `+0x64`, `+0x78`, `+0x9c`, `+0x218`, `+0x2a4`.

**Callers (2):**

- `FUN_004d08c0` `0x004d08c0`
- `FUN_004d31a0` `0x004d31a0`

**Xrefs:** 2.

## Confidence

| Claim | Level |
|---|---|
| Control flow + RET 8 thiscall | **High** |
| Product name from plate | **High** |
| Template override of cbid @ `+0x84` | **High** |
| Host offsets `+0xe4e8` / `+0xe6e0` | **High** |
| Flag path = template apply (not EDI high) | **High** (bytes) |
| Nested callee product names | **Tentative** |
| Virtual product names | **Tentative** |
| packedLocal exact product intent | **Probable** |
