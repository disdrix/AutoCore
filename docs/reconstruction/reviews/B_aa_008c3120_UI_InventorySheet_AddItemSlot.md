# Review B (skeptical / adversarial): `aa_008c3120` UI_InventorySheet_AddItemSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c3120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008c3120_UI_InventorySheet_AddItemSlot.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on add-slot UI helper; **reject** conflation with PlaceFootprint or remove helper ABI |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Places item into cargo grid | **Falsified** — caller already ran `FUN_00571620`; this only UI-tracks |
| 2 | Same ABI as `0x008c2940` (ECX=sheet) | **Falsified** — here **EAX**=sheet, **ECX**=item (bytes + caller) |
| 3 | Removes UI item | **Falsified** — callee allocates `0x514` and increments count |
| 4 | Stack args / thiscall only | **Falsified** — dual-register; bare `ret` |
| 5 | Unconditional | **Falsified** — dual null gates |
| 6 | Bit-exact ready | **Fail** — runtime open |

---

## 2. Decisive dataflow (SEALED)

```
if sheet[+0x580] == 0: return
if item == 0: return
FUN_008605b0()   // unaff EDI=sheet[+0x580] host, EBX=item
```

Bytes seal `mov edi,[eax+0x580]`; `mov ebx,ecx`; dual tests; `call FUN_008605b0`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI add not Place | **High** | Double-place / ghost cargo |
| ABI swapped vs remove | **High** | Silent no-op if ports share one signature |
| Callee alloc path | **High** | Leak / missing icon |
| Runtime | **Open** | Residual |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| Same register map as 008c2940 | Compatible? | **No** — ECX/EAX swapped |
| `+0x580` is item | Compatible? | **No** — loaded from sheet base |
| Hidden grid mutation | Hidden? | **No** — single external call to UI ctor path |

---

## 5. Cross-unit relations

| Unit | Relation |
|------|----------|
| `Client_RecvInventoryEquip` | Sole caller after `InventoryGrid_PlaceItemFootprint` |
| `aa_008c2940` | **Sibling remove** (before place) |
| `FUN_008605b0` | Slot factory |
| `FUN_0085fcc0` | Inverse remove used by sibling |

---

## 6. Verdict

**accept-with-gaps.** Sealed as the inventory-sheet **add-slot** counterpart to remove-by-COID. ABI swap vs `0x008c2940` is a footgun — document both.
