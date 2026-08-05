# Function record: InventoryGrid_FindFreeForItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005714e0` |
| **Canonical name** | `InventoryGrid_FindFreeForItem` |
| **Address** | `0x005714e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean C++** — dual A/B + FindFreeSlot relation sealed 2026-07-29; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_005714e0`
- Legacy: `Named_CalleeOf_Client_SendInventoryUnequip_005714e0`
- Call-site plates: “inventory space check”, “free-slot search”

## Purpose

Item-aware inventory **space / origin** probe on a grid: type-4 trivial success, optional stack-merge to peer XY, else first-fit via `InventoryGrid_FindFreeSlot` (`0x005713a0`) using clonebase InvSize. **Does not place/stamp** (that is `0x00571620`).

## Signature (sealed)

```c
uint32_t __thiscall InventoryGrid_FindFreeForItem(
    InventoryGrid* this,   // ECX
    void* item,            // Item* — null → 0
    uint8_t* outX,
    uint8_t* outY,
    char allowStackMerge,  // 0 = skip stack path
    char pageIndex);       // passthrough to FindFreeSlot; -1 = whole grid
// callee cleans 0x14 stack bytes (ret 0x14)
```

## Relation to FindFreeSlot (SEALED)

```text
// fallthrough (asm mov ecx,ebx; call 0x005713a0)
sizeX = *(u8*)(clonebase(item) + 0x406)
sizeY = *(u8*)(clonebase(item) + 0x407)
return InventoryGrid_FindFreeSlot(this, sizeX, sizeY, outX, outY, pageIndex)
```

| Piece | Confidence |
|---|---|
| Tail call identity | **High / Sealed** |
| InvSize source | **High / Sealed** |
| pageIndex passthrough | **High / Sealed** |
| thiscall grid ECX | **High / Sealed** |
| Type-4 → (0,0)/1 | **High / Sealed** CF |
| Stack path optional | **High / Sealed** CF |

FindFreeSlot scan formula itself: see `aa_005713a0` residual (Y outer, X inner, CanPlace, etc.).

## Control flow (summary)

1. `item == 0` → 0  
2. `*(int*)(*(item+0xa8)+0x38) == 4` → outs 0,0; return 1  
3. If `allowStackMerge`: `FUN_00513e70` → `FUN_005710c0`(cbid,0,qty) → `FUN_0040abf0` → peer vfuncs `+0x250/+0x254` → outs; return 1  
4. Else FindFreeSlot(InvSize, outs, page)

## Notable callers

| Address / name | Role |
|---|---|
| `Client_MissionDialogHandleButton` `0x008ae7c0` | Reward inventory-full gate |
| `Inventory_SerializeAddItemPacket` `0x004fadb0` | Packet XY for 0x2047 |
| `Client_SendInventoryUnequip` `0x00862c00` | Dest XY for 0x203E |
| `FUN_00588290` | Stack-or-free then Place |
| `FUN_00520dc0`, `FUN_00533220`, drag cleanup, vendor, … | Same pattern |

Sampled call sites: `allowStackMerge=1`, `pageIndex=0xffffffff`, ECX = cargo/grid (`+0x2b0` / `+0x35c`).

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | High |
| Signature / convention | **High / Sealed** |
| Control flow | High (live ≡ raw) |
| FindFreeSlot relation | **High / Sealed** |
| Naming | Probable (proposed canonical) |
| Side effects | High (outs only) |
| Overall | **Probable / accept-with-gaps** |

## Open questions

- Product meaning of type class `4`
- Exhaustive matrix of non-`-1` pageIndex producers
- Deep duals for `FUN_00513e70` / `FUN_005710c0` (stack helpers)
- Runtime / differential tests

## Dual reviews

| Kind | Path | Verdict |
|---|---|---|
| A (fidelity) | `reviews/A_aa_005714e0_InventoryGrid_FindFreeForItem.md` | accept-with-gaps |
| B (skeptical) | `reviews/B_aa_005714e0_InventoryGrid_FindFreeForItem.md` | accept-with-gaps |
| Residual scratch | `reviews/a_005714e0.md` | **FindFree relation sealed** |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005714e0_FUN_005714e0.md` |
| Annotated | `raw/aa_005714e0_FUN_005714e0.annotated.md` |
| Clean | `reconstructed-exact/InventoryGrid_FindFreeForItem.cpp` |
| FindFreeSlot | `aa_005713a0` dual + `InventoryGrid_FindFreeSlot.cpp` |
| Prior scaffold clean | `reconstructed-exact/FUN_005714e0.cpp` (superseded by named clean) |
