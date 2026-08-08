# Function record: StdTree_Max_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_004043e0` |
| **Canonical name** | `StdTree_Max_Isnil31` |
| **Ghidra name** | `FUN_004043e0` |
| **Address** | `0x004043e0` |
| **Body** | `0x004043e0`–`0x004043fb` inclusive (**28 B** / `0x1c`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` max / rightmost (isnil @ +0x31) |
| **Completion status** | **Dual-reviewed** WQ9L-C — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-C** |

## Purpose

Return the rightmost non-nil node in the subtree rooted at the input node (MSVC `_Tree_max`). Used by isnil@+0x31 erase helper `FUN_00408ed0` to recompute `head->right` after unlinking the previous rightmost.

Twin: `StdTree_Min_Isnil31` @ `0x00409160` (EAX ABI). Peer: `StdTree_Max_Isnil29_Inferred` @ `0x00421b50` (stack-arg ABI — keep distinct).

## Signature

```c
// EAX = node* in; returns node* in EAX; bare RET
void *StdTree_Max_Isnil31(void *node /*EAX*/);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00408ed0` @ `0x00408fbf` — `MOV EAX,EDI; CALL; MOV [EBX+8],EAX` |
| Callees | none (leaf) |

## Related (not OWN)

- Erase parent `FUN_00408ed0` (isnil@+0x31 map erase / rebalance)
- Min twin for head-left update: `StdTree_Min_Isnil31` @ `0x00409160` (dualed WQ9J-E)
- Rrotate peer: `StdTree_Rrotate_Isnil31_Inferred` @ `0x00403ee0` (OWN WQ9L-C)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004043e0_FUN_004043e0.md`
- Annotated: `docs/reconstruction/raw/aa_004043e0_FUN_004043e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil31.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004043e0.cpp`
- Review A: `reviews/A_aa_004043e0_StdTree_Max_Isnil31.md`
- Review B: `reviews/B_aa_004043e0_StdTree_Max_Isnil31.md`
- Scaffold record: `docs/reconstruction/functions/aa_004043e0_FUN_004043e0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| EAX in/out ABI | **High** |
| isnil every guard +0x31 | **High** |
| Role = tree max / rightmost | **High** |
| Product map key/value English | **Open** |
| Runtime | **Open** |
