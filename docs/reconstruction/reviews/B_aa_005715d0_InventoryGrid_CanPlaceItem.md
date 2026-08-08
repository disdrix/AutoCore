# Review B (skeptical / adversarial): `aa_005715d0` InventoryGrid_CanPlaceItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_005715d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_005715d0_InventoryGrid_CanPlaceItem.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (first full dual) |
| **Verdict** | **accept** on CF/ABI/handoff; **reject** “stamps cells”, “non-thiscall”, and “finished PDB name” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function places / stamps the item | **Falsified** — only CanPlace; no cell stores |
| 2 | First stack arg is the grid | **Falsified** — item (null-checked; `+0xa8`); grid is ECX |
| 3 | cdecl / no this | **Falsified** — `PUSH ECX` save; CanPlace thiscall |
| 4 | Sizes are stack args | **Falsified** — loaded from clonebase `+0x406/+0x407` |
| 5 | Same as FindFreeForItem | **Falsified** — no first-fit, no stack-merge, no outs |
| 6 | Same as MoveItemFootprint | **Falsified** — no clear/stamp |
| 7 | `RET 0x0C` three args | **Falsified** — `C2 10 00` |
| 8 | No callers | **Falsified** — equip/UI multi-site xrefs |
| 9 | PDB name sealed | **Fail** — Inferred English only |
| 10 | Bit-exact complete | **Fail** — not required for leaf accept |

---

## 2. Decisive dataflow (bytes 2026-08-04)

```
// ECX = grid
push ecx
item = [esp+8]
if item == 0: xor al,al; pop ecx; ret 0x10

blob = *(*(item+0xa8)+0x3c)
sizeY = u8(blob+0x407); sizeX = u8(blob+0x406)
// push conflictOut, originY, originX, sizeY, sizeX
// ecx = grid; call InventoryGrid_CanPlace
pop ecx
ret 0x10
```

### Caller attack sample (`0x008012f0`)

```
// ECX = cargo grid; item = piVar1; origins from item GetX/GetY
FUN_005715d0(item, curX, curY, 0)   // conflictOut null
// on fail → FindFreeForItem fallback before PlaceItemFootprint
```

Role = **“does current footprint origin still fit?”** / **“does candidate origin fit InvSize?”** — not place.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf wrapper CF | **Confirmed** | Port invents place logic |
| ABI 4 stack + this | **Confirmed** | Stack misalign |
| InvSize offsets | **Confirmed** | Wrong footprint |
| CanPlace handoff | **Confirmed** | Divergent occupancy |
| Product English | **Probable** | Docs only |
| Bit-exact | **Open** | Policy |

---

## 4. Verdict

### **accept**

No adversarial hole in the leaf contract. Reject overclaims that this unit mutates inventory state or that decompiler non-thiscall display is ABI truth.
