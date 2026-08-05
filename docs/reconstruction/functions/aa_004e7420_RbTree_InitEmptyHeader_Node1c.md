# Function record: RbTree_InitEmptyHeader_Node1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e7420` |
| **Canonical name** | `RbTree_InitEmptyHeader_Node1c` |
| **Prior / Ghidra name** | `FUN_004e7420` |
| **Address** | `0x004e7420`–`0x004e744a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | containers / RB-tree |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W23-M OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_004e7420`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_004e7420`
- Completes empty header after `FUN_005ae2b0` (`0x005ae2b0`, `operator_new(0x1c)`)

## Purpose

In-place **empty RB-tree header** init for the **0x1c-node** map flavor:

1. `node = FUN_005ae2b0()` — `operator_new(0x1c)` sentinel factory.
2. `header+4 = node`.
3. `node+0x19 = 1` (head/nil; factory left 0).
4. Self-link `node` left (`+0`), parent (`+4`), right (`+8`).
5. `header+8 = 0` (size).
6. Return `header*` in EAX.

## Signature (sealed)

```c
// ECX = header*, plain RET, EAX = header*
void* RbTree_InitEmptyHeader_Node1c(/* ECX */ void* header);
```

## Layout (touched)

| Object | Off | Role |
|---|---:|---|
| header | `+4` | head node* |
| header | `+8` | size = 0 |
| node | `+0/+4/+8` | left/parent/right = self |
| node | `+0x19` | head flag = 1 |
| node size | `0x1c` | via factory |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e7420_FUN_004e7420.md` |
| Annotated | `docs/reconstruction/raw/aa_004e7420_FUN_004e7420.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/RbTree_InitEmptyHeader_Node1c.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_004e7420.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_004e7420_RbTree_InitEmptyHeader_Node1c.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e7420_RbTree_InitEmptyHeader_Node1c.md` |
| Function alias | `docs/reconstruction/functions/aa_004e7420_FUN_004e7420.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `FUN_005ae2b0` | `0x005ae2b0` — 0x1c empty node factory |
| Caller | `FUN_004d8a10` | 2 sites (`0x004d8d92`, `0x004d8d9d`) |
| Sibling (not this) | `RbTree_InitEmptyHeader` / `FUN_004e7450` | 0x18 node / flag `+0x15` (W22-R sealed) |

## Confidence

| Claim | Level |
|---|---|
| CF: alloc → head → flag → self-link → size0 → return this | **High** |
| ECX thiscall, plain ret | **High** |
| Callee `005ae2b0` / node size 0x1c | **High** |
| Head flag at `+0x19` | **High** |
| Empty-tree role | **High** |
| Product C++ typedef name | **Inferred** |
| Runtime / bit-exact | **Open** |
