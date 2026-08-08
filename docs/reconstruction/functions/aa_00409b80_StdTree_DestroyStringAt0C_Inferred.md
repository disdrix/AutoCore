# Function record: StdTree_DestroyStringAt0C_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409b80` |
| **Canonical name** | `StdTree_DestroyStringAt0C_Inferred` |
| **Ghidra name** | `FUN_00409b80` |
| **Address** | `0x00409b80`–`0x00409bc0` inclusive (**65 B** / `0x41`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / STL tree node value destroy |
| **Wave** | WQ9K-A OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual A/B sealed; **accept-with-gaps** |
| **Terminal** | **false** |

## Alias history

- Ghidra: `FUN_00409b80`
- Structural: `StdTree_DestroyStringAt0C_Inferred` (product map type open)
- Scaffold: partial raw/annotated from 2026-07-23
- Free-subtree docs refer as “string destroy @+0x0c” / `DestroyNodeStringAt0C`

## Purpose

Destroy the `std::basic_string` value embedded at **offset +0x0c** of a tree node. Shared by both isnil families that free-subtree with string destroy. Node allocation free is **caller** responsibility (`operator_delete`).

## Signature

```c
// stdcall; stack node*; void; RET 4
void __stdcall StdTree_DestroyStringAt0C_Inferred(void* node);
// thiscall ~basic_string at (char*)node + 0x0c via IAT [0x009c62f4]
```

## Family / peers

| VA | Name | Role |
|---|---|---|
| `0x00409920` | `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` | free-subtree caller (isnil +0x131) |
| `0x00409970` | `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` | free-subtree caller (isnil +0x2d) |
| `0x00407b70` | erase-range full clear (isnil131) | parent of free-subtree (residual WQ9K-B) |
| `0x00407f90` | erase-range full clear (isnil2d) | parent of free-subtree (residual WQ9K-B) |
| `0x00406c00` / `0x0051bbc0` / `0x0040d630` | free-subtree no value destroy | peers without this dtor |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00409b80_FUN_00409b80.md`
- Annotated: `docs/reconstruction/raw/aa_00409b80_FUN_00409b80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_DestroyStringAt0C_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00409b80.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00409b80_StdTree_DestroyStringAt0C_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00409b80_StdTree_DestroyStringAt0C_Inferred.md`
- Report: `docs/agents/task-dual-ab-00409ae0-00409b80-wq9ka-report.md`

## Callers / callees

| **Callers** | FreeSubtree isnil131 + isnil2d (2 sites) |
| **Callees** | `~basic_string` IAT |
| **Xrefs** | 2 |

## Confidence

| Claim | Level |
|---|---|
| String dtor @+0x0c + SEH + RET 4 | **Confirmed** |
| Shared by both free-subtree twins | **Confirmed** |
| Product map English | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
