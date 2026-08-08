# Function record: FUN_004cbb60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbb60` |
| **Canonical name** | `FUN_004cbb60` (Ghidra); dual-named **`StdTree_InsertAndRebalance_Isnil29_Inferred`** |
| **Address** | `0x004cbb60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std map/set tree insert (isnil@+0x29) |
| **Completion status** | **Dual sealed** WQ9E-E 2026-08-04 — raw re-verify + A/B + named clean |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Purpose

Always-insert + red-black rebalance for isnil@+0x29 trees. See named plate.

## Signature

```c
void __thiscall FUN_004cbb60(MapShell *map /*ECX*/, Node **outIt,
                             char addLeft, Node *where, Val24 *value);
// RET 0x10
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.md`
- Annotated: `docs/reconstruction/raw/aa_004cbb60_FUN_004cbb60.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil29_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004cbb60.cpp`
- Named record: `docs/reconstruction/functions/aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_004cbb60_StdTree_InsertAndRebalance_Isnil29_Inferred.md` / `B_…`

## Callers / callees

| Callers | `FUN_004cbe20`, `FUN_004cbee0`, `FUN_004cc220` (11 UNCONDITIONAL_CALL) |
| Callees | `FUN_005a2de0`, `FUN_004192a0`, `FUN_004192f0`, throw path |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| ABI RET 0x10 / thiscall | **High** |
| Buynode 0x30 / isnil@+0x29 | **High** |
| Product demangle | Tentative (`_Inferred`) |
