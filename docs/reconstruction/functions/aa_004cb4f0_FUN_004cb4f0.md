# Function record: FUN_004cb4f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4f0` |
| **Canonical name** | `FUN_004cb4f0` |
| **Preferred name** | `StdTree_Predecessor_Isnil29_Inferred` |
| **Address** | `0x004cb4f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004cb4f0`–`0x004cb540` exclusive (80 B / `0x50`) |
| **System** | std red-black tree / map iterator (isnil @ +0x29) |
| **Completion status** | **Dual sealed** WQ9G-B 2026-08-04 — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | false |

## Alias

- Preferred: `StdTree_Predecessor_Isnil29_Inferred`
- Scaffold (reject product): `Named_CalleeOf_…_VOGClient_004cb4f0`

## Purpose

MSVC-style tree iterator **predecessor** (`operator--`) for nodes with **isnil @ +0x29**. **ECX = Node****; bare RET. Leaf.

## Signature (sealed)

```c
void __fastcall FUN_004cb4f0(void** it /*ECX*/);
// isnil@+0x29; left@0 parent@4 right@8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cb4f0_FUN_004cb4f0.md`
- Annotated: `docs/reconstruction/raw/aa_004cb4f0_FUN_004cb4f0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdTree_Predecessor_Isnil29_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cb4f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md`
- Named record: `docs/reconstruction/functions/aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md`

## Callers / callees

| Direction | Address / name |
|---|---|
| Callers (5) | `FUN_00406040`, `FUN_004cbe20`, `FUN_004cbee0`, `FUN_004cc220`, `FUN_005a3b00` |
| Callees | none (leaf) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| ECX ABI / isnil@+0x29 | **High** |
| Predecessor role | **High** |
| Parameter semantic names | **Inferred** |
| Product English | Open |
| Runtime | Open |
