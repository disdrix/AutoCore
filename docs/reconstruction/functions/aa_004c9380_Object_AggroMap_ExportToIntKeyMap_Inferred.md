# Function record: Object_AggroMap_ExportToIntKeyMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9380` |
| **Canonical name** | `Object_AggroMap_ExportToIntKeyMap_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_004c9380` |
| **Address** | `0x004c9380` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004c9380`–`0x004c9428` exclusive (**168 B** / `0xA8`) |
| **System** | Object aggro / AI target selection helper |
| **Agent** | WQ9G-C OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Walk the **object aggro map** (sentinel head at **this+0x158**, isnil@**+0x29**) inorder and **insert-or-find** each entry into a **destination** map using **signed score @ node+0x20 as int key** and TFID payload. Feeds `CVOGHBAIBase_GetTargetFromAggro` temp tree.

## Signature

```c
void __thiscall Object_AggroMap_ExportToIntKeyMap_Inferred(
    Object *self,              // ECX
    MapShell_Isnil29 *dest);   // stack
// RET 4
```

## Layout / constants

| Item | Value |
|---|---|
| Source head | object **+0x158** (map shell **+0x154**) |
| isnil | **+0x29** |
| Export key | signed score from source **+0x20** |
| Export payload | TFID dwords from source **+0x10** packed at value **+8** |
| Insert worker | `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` `0x004cbe20` |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `CVOGHBAIBase_GetTargetFromAggro` `0x00638ec0` |
| Insert-or-find | dualed `0x004cbe20` (WQ9F-D) |

## Evidence summary

- Live disasm seals dest map stack arg + `MOV ECX,EDI` + **RET 4** (decomp incomplete).
- Score-as-key + TFID pack sealed by byte stores before `CALL 0x004cbe20`.
- Equal-score collapse inherits insert-or-find no-rewrite.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Object_AggroMap_ExportToIntKeyMap_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_004c9380_FUN_004c9380.md`
- Annotated: `docs/reconstruction/raw/aa_004c9380_FUN_004c9380.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_004c9380_FUN_004c9380.md`
