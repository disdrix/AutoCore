# Function record: StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005738d0` |
| **Canonical name** | `StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred` |
| **Ghidra name** | `FUN_005738d0` |
| **Address** | `0x005738d0` |
| **Body range** | `0x005738d0`–`0x005738fc` inclusive (**45 B** / `0x2D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / MSVC `_Tree` bare tidy Val12 (InventoryGrid maps) |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** (R11-004) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005738d0_StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.md`, `reviews/B_aa_005738d0_StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.md` (2026-08-05 R11-004) |
| **Last reviewed** | `2026-08-05` |

## Alias

- `FUN_005738d0`
- map-shell dtor wrapper (MEGA-120 parent note for erase caller)

## Purpose

MSVC-style `_Tree` tidy on a Val12 facade (`head@+4`, `size@+8`) **without** an SEH frame:

1. Erase full range `[begin,end)=[head->left, head)` via dualed `StdTree_EraseRange_Val12_InventoryGrid_Inferred` (`0x00573700`).
2. Free the header sentinel with `operator_delete`.
3. Null `head` and `size`.

Used as SEH unwind target for InventoryGrid-family map shells (`ADD ECX,0x5c` then `JMP`). Peer bare tidy: `StdTree_Tidy_FreeHead_Bare_Val12` @ `0x0040d6d0` (erase leaf `0040d700`).

## Signature

```c
void __fastcall StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred(
    StdTreeShell_Val12* map);  // ECX; head@+4, size@+8; bare RET
```

### InventoryGrid embedding

| Offset | Field |
|---|---|
| object `+0x5c` | map shell base (ECX for this unit) |
| object `+0x60` | head sentinel pointer |
| object `+0x64` | size |

## Algorithm

```text
head = map->head
StdTree_EraseRange_Val12_InventoryGrid(map, &out, head->left, head)  // full
operator_delete(head)
map->head = 0; map->size = 0
// does NOT free map shell
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005738d0_FUN_005738d0.md`
- Annotated: `docs/reconstruction/raw/aa_005738d0_FUN_005738d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005738d0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005738d0-r11-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `StdTree_EraseRange_Val12_InventoryGrid_Inferred` `0x00573700` (dualed MEGA-120); `operator_delete` |
| **Callers** | SEH unwind `@009a4f37`, `@009a4f57`, `@009a4f91` |

## Related

- Peer bare tidy: `aa_0040d6d0` `StdTree_Tidy_FreeHead_Bare_Val12`
- Peer SEH tidy: `aa_0040d7c0` `StdTree_Tidy_FreeHead_Val12`
- Erase leaf (this family): `aa_00573700` `StdTree_EraseRange_Val12_InventoryGrid_Inferred`
- Complete dtor inlines erase+delete rather than calling this tidy: residual `FUN_005725a0`
