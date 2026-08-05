# Reconstruction review: `aa_004fadb0` Inventory_SerializeAddItemPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fadb0` |
| **VA** | `0x004fadb0` |
| **Canonical name** | `Inventory_SerializeAddItemPacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `raw/aa_004fadb0_Inventory_SerializeAddItemPacket.md` | Authoritative decompile |
| Annotated | `…annotated.md` | Scaffold |
| Exact C++ | `reconstructed-exact/Inventory_SerializeAddItemPacket.cpp` | Clean |
| Function record | `functions/aa_004fadb0_….md` | Status |
| Caller | `Client_SendInventoryAddItem` `0x00530df0` | Opcode 0x2047 fill |
| Packet docs | `Documentation/PACKET STRUCTURES.md` (0x2047 layout) | Field map cross-check |
| Wire RE | `docs/inventory-cargo-wire-re.md` | AddItem role |

**Primary claims under review:**

1. Early fail if `this+0x2b0 == 0` (no cargo inventory)
2. `wasAdded` at packet `+0x18` cleared first
3. Branch on `FUN_00513e70()`: free-slot vs stack-scan
4. Free-slot: type==4 OR `FUN_005714e0` writes X/Y at `+0x10/+0x11`; sets `addToExisting=0`, COID at `+8/+0xc` from item `[0x58]/[0x59]`
5. Stack path: scan matches same CBID, flag bit 19 clear both sides, qty gate `FUN_0040abf0`; merge sets `addToExisting=1`, X=Y=0, COID from matched object `+0x160/+0x164`
6. CS release on cargo `+0x54/+0x30` after scan
7. Scan miss falls back to free-slot fill
8. Returns filled flag (`char` 0/1)

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | Full body CF |
| Clean C++ | reconstructed-exact | Fidelity |
| PACKET STRUCTURES 0x2047 | Docs | COID @+8, X/Y @+10/+11, flags @+12/+18 |
| Caller raw | SendInventoryAddItem | Opcode 0x2047, uses +0x12 branch |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| wasAdded=0 init | **Yes** |
| cargo null → 0 | **Yes** |
| FUN_00513e70 branch | **Yes** |
| Free-slot type4 \|\| FindSlot | **Yes** |
| Stack scan while + match predicates | **Yes** |
| Merge field writes | **Yes** |
| LeaveCriticalSection path | **Yes** |
| Fallback free-slot | **Yes** |
| Return cWasFilled | **Yes** |

### 3.2 Packet field map (important correction)

| Offset | Raw writes | PACKET STRUCTURES | Plate (old) | Clean |
|---|---|---|---|---|
| +0x08/+0x0c | item[0x58]/[0x59] or match+0x160/164 | item COID | **wrongly said grid X/Y** | **COID (corrected in comments)** |
| +0x10/+0x11 | FindFreeSlot outs / 0 on merge | cargo X/Y | implied elsewhere | **X/Y** |
| +0x12 | 0 free / 1 merge | bAddToExisting | plate ok | **Yes** |
| +0x18 | wasAdded | bWasSuccessful | plate ok | **Yes** |

Clean documents that older plate text equating `+8` with grid X is incorrect — consistent with caller and PACKET STRUCTURES.

### 3.3 Item dword indices

`piVar2[0x58]` / `[0x59]` = byte offsets `0x160` / `0x164` — same COID halves used in grab/equip TFID loads. High confidence.

### 3.4 Type renames

`undefined1`→`uint8_t`, `undefined4`→`uint32_t`. No CF invents.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `FUN_00513e70` meaning | Medium | “stack eligible” is interpretive; body only branches on non-zero |
| `FUN_005714e0` = FindFreeSlot | Probable | Writes two bytes; aligned with grid docs, not proven by symbol in body |
| Signature `this` = vehicle | Probable | `+0x2b0` cargo matches vehicle layout used in equip path |
| param_4 / iter | Tentative | Stack-scan iterator surface still opaque |
| Annotated still scaffold | Meta | Clean header now carries the field correction |

**No revision required** for clean-vs-raw CF faithfulness.

---

## 5. What remains uncertain

1. Exact identity of `FUN_00513e70` (global stack mode vs per-item).
2. Whether type class `4` is “currency/quest” or another non-grid class (accepted without slot find).
3. Flag bit 19 at `+0x17c` semantic name.
4. Runtime add/merge round-trip not observed.
5. Live re-decompile not performed.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean faithfully mirrors raw CF and corrects the packet+8 grid-X plate error using PACKET STRUCTURES + dword/byte offset math.

**Gaps:** Unresolved helpers, stack-mode probe, no runtime seal.
