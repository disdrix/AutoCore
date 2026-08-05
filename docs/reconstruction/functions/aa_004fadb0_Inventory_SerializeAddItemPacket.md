# Function record: Inventory_SerializeAddItemPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fadb0` |
| **Canonical name** | `Inventory_SerializeAddItemPacket` |
| **Address** | `0x004fadb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Human-refined clean + dual review (accept-with-gaps / needs-more-evidence)** — runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Fill InventoryAddItem packet fields (wasAdded, addToExisting, item COID, slot X/Y) for cargo place or stack-merge. Caller stamps opcode `0x2047`.

## Signature (decompiler-derived)

```c
char __thiscall Inventory_SerializeAddItemPacket(
    int pVehicle,   // this; cargo at +0x2b0
    int pPacket,    // 0x20 body
    int* pItem,
    int* pIterOut);
```

## Packet fields written

| Offset | Field | Notes |
|---|---|---|
| +0x08/+0x0c | item COID lo/hi | From item[0x58]/[0x59] (=+0x160/+0x164), **not** grid X/Y |
| +0x10/+0x11 | cargo X/Y | FindFreeSlot or 0 on merge |
| +0x12 | bAddToExisting | 0 free slot / 1 merge |
| +0x18 | wasAdded | success flag |

## Behavioral summary

Fail if no cargo (`+0x2b0==0`). Free-slot path vs stack-scan (`FUN_00513e70`). Merge matches same CBID + flag bit 19 clear + qty gate. Returns 1 if filled.

## Callers / callees

| Direction | Symbol | Notes |
|---|---|---|
| Caller | `Client_SendInventoryAddItem` | Builds 0x2047 |
| Callee | `FUN_005714e0` | Free slot → X/Y |
| Callee | `FUN_00513e70` | Stack-mode probe |
| Callee | `FUN_004022a0` | Inventory iterate |

## Confidence

| Claim | Level |
|---|---|
| Control flow | High |
| COID at +8 (plate correction) | High |
| X/Y at +0x10/+0x11 | High |
| Helper semantic names | Probable / Tentative |
| Overall | Probable — refined; runtime open |

## Dual reviews

| Kind | Path | Verdict |
|---|---|---|
| Reconstruction | `reviews/aa_004fadb0_reconstruction_review.md` | accept-with-gaps |
| Skeptical | `reviews/aa_004fadb0_skeptical_review.md` | needs-more-evidence |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004fadb0_Inventory_SerializeAddItemPacket.md`
- Annotated: `docs/reconstruction/raw/aa_004fadb0_Inventory_SerializeAddItemPacket.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Inventory_SerializeAddItemPacket.cpp`
