# Function record: StdTree_LeftRotate_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e010` |
| **Canonical name** | `StdTree_LeftRotate_Isnil2D_Inferred` |
| **Ghidra name** | `FUN_0044e010` |
| **Address** | `0x0044e010` |
| **Body** | `0x0044e010`–`0x0044e05b` inclusive (**76 B** / `0x4C`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC std `_Tree` left-rotate (isnil@+0x2D family) |
| **Completion status** | **Dual-reviewed** WQ9K-I — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Partition** | `WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-I** |

## Purpose

Perform a **left rotate** about node X in the isnil@**+0x2D** red-black / std map tree family used by StringKey insert (`00430b60`) and erase (`004094c0`). Promotes X.right to X's place; fixes parent links for root / left-child / right-child cases. Does **not** recolor (callers write color@+0x2C).

## Signature

```c
// ECX = node X; stack map*; RET 4
void __thiscall StdTree_LeftRotate_Isnil2D_Inferred(void *node_x, void *map);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_0042a930`, `FUN_00430b60`, `FUN_004094c0`, `FUN_00401db0` (10 UNCONDITIONAL_CALL total) |
| Callees | none |

## Related

- R-rotate twin: `FUN_0042a840` @ `0x0042a840` (WQ9K-J)
- Layout peers: isnil@+0x2D, color@+0x2C, string@+0x0C, node size 0x30
- Reject isnil29 rotates `004192a0`/`004192f0`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044e010_FUN_0044e010.md`
- Annotated: `docs/reconstruction/raw/aa_0044e010_FUN_0044e010.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_LeftRotate_Isnil2D_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0044e010.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0044e010_FUN_0044e010.md`
- Review A: `reviews/A_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md`
- Review B: `reviews/B_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Left-rotate semantics | **High** |
| isnil@+0x2D | **High** |
| ABI | **High** |
| Product map English | **Open** |
| Runtime | **Open** |
