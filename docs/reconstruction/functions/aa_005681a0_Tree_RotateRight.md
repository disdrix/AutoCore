# Function record: Tree_RotateRight

| Field | Value |
|---|---|
| **Stable ID** | `aa_005681a0` |
| **Canonical name** | `Tree_RotateRight` (Inferred) |
| **Ghidra name** | `FUN_005681a0` |
| **Address** | `0x005681a0`–`0x005681f1` (82 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / map-set tree |
| **Completion status** | **dual-sealed** W23-B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Leaf right-rotate for isnil@0x49 map/set trees. Twin of `Tree_RotateLeft` @ `0x00568b70`.

## Signature

```c
void __thiscall Tree_RotateRight(MapShell *map, Node *x);
// RET 4
```

## Artifacts

See `aa_005681a0_FUN_005681a0.md` for full table + A/B paths.
