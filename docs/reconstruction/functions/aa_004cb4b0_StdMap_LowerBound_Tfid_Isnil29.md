# Function record: StdMap_LowerBound_Tfid_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4b0` |
| **Canonical name** | `StdMap_LowerBound_Tfid_Isnil29` (**Inferred** structural) |
| **Ghidra name** | `FUN_004cb4b0` |
| **Address** | `0x004cb4b0` |
| **Body** | `0x004cb4b0`–`0x004cb4eb` exclusive (**59 B** / `0x3B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC map/tree lower_bound (TFID-shaped key, isnil@+0x29) |
| **Completion status** | **Dual-reviewed** W31-N — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC-style `_Tree::_Lbound` for an 8-byte key `(uint32 lo, int32 hi)` matching TFID ordering. Walks from root (`head->parent`), isnil at `node+0x29`, keys at `+0x10/+0x14`. Returns first node not less than key (or head/end). No equality gate.

## Signature

```c
// ECX = map host (head@+4). Stack pKey. RET 4. Returns Node*.
Node_Isnil29* __fastcall StdMap_LowerBound_Tfid_Isnil29(
    MapHost_Head4* self, const KeyU32I32* pKey);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004c8970`, `FUN_004ca760`, `FUN_004cba00`, `FUN_004cc400`, `FUN_005a0470` |
| Callees | none (leaf) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.md`
- Annotated: `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_LowerBound_Tfid_Isnil29.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004cb4b0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md`
- Review B: `docs/reconstruction/reviews/B_aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md`
- Scaffold record: `docs/reconstruction/functions/aa_004cb4b0_FUN_004cb4b0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes ≡ decompile) | **High** |
| ABI thiscall + RET 4 | **High** |
| isnil@+0x29 / key@+0x10,+0x14 | **High** |
| lower_bound (not exact find) | **High** |
| TFID key shape (consumer-backed) | **High** structural / product plate **Low** |
| Product map value type | **Low** |

## Rejected plates

- `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cb4b0` (scaffold chain; no product evidence).
