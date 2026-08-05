# Function record: RbTree_InitEmptyHeader

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7450` |
| **Canonical name** | `RbTree_InitEmptyHeader` |
| **Prior / Ghidra name** | `FUN_004e7450` |
| **Address** | `0x004e7450`–`0x004e747a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / RB-tree |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W22-R OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_004e7450`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_004e7450`
- Completes empty header after `RbTree_AllocEmptyNode_Inferred` (`0x00439770`)

## Purpose

In-place **empty RB-tree header** init:

1. `node = FUN_00439770()` — `operator_new(0x18)` sentinel factory.
2. `header+4 = node`.
3. `node+0x15 = 1` (head/nil; factory left 0).
4. Self-link `node` left (`+0`), parent (`+4`), right (`+8`).
5. `header+8 = 0` (size).
6. Return `header*` in EAX.

## Signature (sealed)

```c
// ECX = header*, plain RET, EAX = header*
void* RbTree_InitEmptyHeader(/* ECX */ void* header);
```

## Layout (touched)

| Object | Off | Role |
|---|---:|---|
| header | `+4` | head node* |
| header | `+8` | size = 0 |
| node | `+0/+4/+8` | left/parent/right = self |
| node | `+0x15` | head flag = 1 |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e7450_FUN_004e7450.md` |
| Annotated | `docs/reconstruction/raw/aa_004e7450_FUN_004e7450.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/RbTree_InitEmptyHeader.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_004e7450.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_004e7450_RbTree_InitEmptyHeader.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e7450_RbTree_InitEmptyHeader.md` |
| Function alias | `docs/reconstruction/functions/aa_004e7450_FUN_004e7450.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `RbTree_AllocEmptyNode_Inferred` / `FUN_00439770` | `0x00439770` |
| Caller | `FUN_004d8a10` | 4 sites (large ctor / Client init chain) |
| Xrefs | `0x009c0a05` / `0x009c0a65` / `0x009c0a85` / `0x009c0ce5` | additional |
| Sibling (not this) | `FUN_004e7420` | alternate node factory / `+0x19` |

## Confidence

| Claim | Level |
|---|---|
| CF: alloc → head → flag → self-link → size0 → return this | **High** |
| ECX thiscall, plain ret | **High** |
| Callee `00439770` identity | **High** |
| Empty-tree role | **High** |
| Product C++ typedef name | **Inferred** |
| Runtime / bit-exact | **Open** |
