# Function record: Tree_RotateLeft_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e22d0` |
| **Canonical name** | `Tree_RotateLeft_Isnil15` (**Inferred**) |
| **Ghidra name** | `FUN_004e22d0` |
| **Address** | `0x004e22d0` |
| **Body** | `0x004e22d0`–`0x004e231d` (78 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | container / map-set tree |
| **Completion status** | **Dual-sealed 2026-07-29 W24-O** — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Pure structural **left rotate** for the isnil@`+0x15` map/set tree family. No recolor, no allocation.

## Signature

```c
void __thiscall Tree_RotateLeft_Isnil15(MapShell *map, TreeNode_Isnil15 *x);
// ECX=map, [esp+4]=x; RET 4
```

## Algorithm

```
y = x->right
x->right = y->left
if !isnil(y->left): y->left->parent = x   // isnil @ +0x15
y->parent = x->parent
if x is root: root = y
else if x is left of parent: parent->left = y
else: parent->right = y
y->left = x
x->parent = y
```

## Twins

| Unit | VA | Role |
|---|---|---|
| `Tree_RotateRight_Isnil15` | `0x006753b0` | right rotate, same family (W24-O) |
| `Tree_RotateLeft` | `0x00568b70` | left rotate, isnil@`+0x49` staging (W19-K) |

## Artifacts

See `aa_004e22d0_FUN_004e22d0.md` for full artifact table and callers.
