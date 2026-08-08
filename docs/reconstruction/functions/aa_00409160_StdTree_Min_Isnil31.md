# Function record: StdTree_Min_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409160` |
| **Canonical name** | `StdTree_Min_Isnil31` |
| **Ghidra name** | `FUN_00409160` |
| **Address** | `0x00409160` |
| **Body** | `0x00409160`–`0x00409172` inclusive (**19 B** / `0x13`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC `std::_Tree` min / leftmost (isnil @ +0x31) |
| **Completion status** | **Dual-reviewed** WQ9J-E — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-E** |

## Purpose

Return the leftmost non-nil node in the subtree rooted at the input node (MSVC `_Tree_min`). Used by isnil@+0x31 erase helper `FUN_00408ed0` to recompute `head->left` after unlinking the previous leftmost.

Twin: `StdTree_Min_Isnil29` @ `0x0051b5d0` (stack-arg ABI). Family peer: `StdTree_IteratorIncrement_Isnil31` @ `0x00408590`.

## Signature

```c
// EAX = node* in; returns node* in EAX; bare RET
void *StdTree_Min_Isnil31(void *node /*EAX*/);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_00408ed0` @ `0x00408f9d` — `MOV EAX,EDI; CALL; MOV [EBX],EAX` |
| Callees | none (leaf) |

## Related (not OWN)

- Erase parent `FUN_00408ed0` (isnil@+0x31 map erase / rebalance)
- Max twin for head-right update: `FUN_004043e0` (context only)
- Iterator++ isnil31: `StdTree_IteratorIncrement_Isnil31` @ `0x00408590` (WQ9H-H)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00409160_FUN_00409160.md`
- Annotated: `docs/reconstruction/raw/aa_00409160_FUN_00409160.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil31.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00409160.cpp`
- Review A: `reviews/A_aa_00409160_StdTree_Min_Isnil31.md`
- Review B: `reviews/B_aa_00409160_StdTree_Min_Isnil31.md`
- Scaffold record: `docs/reconstruction/functions/aa_00409160_FUN_00409160.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| EAX in/out ABI | **High** |
| isnil every guard +0x31 | **High** |
| Role = tree min / leftmost | **High** |
| Product map key/value English | **Open** |
| Runtime | **Open** |
