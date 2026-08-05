# Function record: phyBoundingBox_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ce60` |
| **Canonical name** | `phyBoundingBox_Unserialize` |
| **Ghidra name** | `FUN_0074ce60` |
| **Address** | `0x0074ce60` |
| **Body** | **596 B** (`0x0074ce60`–`0x0074d0b4` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | palantir physics / sto-chunk |
| **Name confidence** | **High** (product path + log strings) |
| **Dual** | **accept** (W38-H A+B) |

## Role

Chunk unserialize for physics bounding box (`phyBoundingBox.cpp`). Consumed by geometry-piece and physics-asset paths.

## ABI

| Slot | Value |
|---|---|
| ECX | `phyBoundingBox*` |
| EBX | `stoChunkReader*` |
| return | `int` 0 / −1 |
| cleanup | bare `RET` (SEH frame) |

## Rejected aliases

- Treating solely as “post-effect/vertex piece hook” (prior tentative note under gfxGeometryPiece) — primary identity is phyBoundingBox unserialize; gfx piece is one caller embedding a bbox field.

## Artifacts

See `aa_0074ce60_FUN_0074ce60.md`.
