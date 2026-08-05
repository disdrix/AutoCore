# Function record: Tree_RotateRight_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_006753b0` |
| **Canonical name** | `Tree_RotateRight_Isnil15` (**Inferred**) |
| **Ghidra name** | `FUN_006753b0` |
| **Address** | `0x006753b0` |
| **Body** | `0x006753b0`–`0x00675401` (82 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / map-set tree |
| **Completion status** | **Dual-sealed 2026-07-29 W24-O** — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Pure structural **right rotate** for the isnil@`+0x15` map/set tree family. No recolor, no allocation.

## Signature

```c
void __thiscall Tree_RotateRight_Isnil15(MapShell *map, TreeNode_Isnil15 *x);
// ECX=map, [esp+4]=x; RET 4
```

## Algorithm

```
y = x->left
x->left = y->right
if !isnil(y->right): y->right->parent = x   // isnil @ +0x15
y->parent = x->parent
if x is root: root = y
else if x is right of parent: parent->right = y
else: parent->left = y
y->right = x
x->parent = y
```

## Twins

| Unit | VA | Role |
|---|---|---|
| `Tree_RotateLeft_Isnil15` | `0x004e22d0` | left rotate, same family (W24-O) |
| `Tree_RotateRight` | `0x005681a0` | right rotate, isnil@`+0x49` staging (W23-B) |

## Artifacts

See `aa_006753b0_FUN_006753b0.md` for full artifact table and callers.
