# Review B (skeptical / adversarial): `aa_0085f150` Client_UI_InventoryItemWidget_PlaceFromCell

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085f150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/A_aa_0085f150_Client_UI_InventoryItemWidget_PlaceFromCell.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on ABI + formula; **reject** claims this converts page/absolute Y or mutates inventory |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Pure `__thiscall` (window in ECX) | Body reads pitch/origin from **EAX**; caller loads EDI→EAX | **Falsified** |
| 2 | Pure `__fastcall` (window in EDX) | Second object is **EAX**, not EDX | **Falsified** |
| 3 | This computes page-local Y | No pageH/pageIdx; parent already wrote page-local into `+0x49c` | **Falsified** |
| 4 | Formula is origin − pitch×cell | Bytes: `imul` then `add` origin | **Falsified** — `pitch*cell + origin` |
| 5 | Widget offsets are `[0x126]` as bytes | Dword indices: `0x126*4 = 0x498` | **Clarify** — dword slots |
| 6 | Multiple place sites | Only xref `0x008606b6` | **Sole caller** confirmed |
| 7 | Grid footprint / inventory model write | Only UI vfunc call | **Falsified** |

---

## 2. Decisive dataflow (SEALED)

```text
void Client_UI_InventoryItemWidget_PlaceFromCell(Widget* widget /*ECX*/, Window* window /*EAX*/)
{
    if (!widget) return;
    int cellX = *(int*)((uint8_t*)widget + 0x498);
    int cellY = *(int*)((uint8_t*)widget + 0x49c);
    int pos[/*≥2*/];
    pos[0] = *(int*)((uint8_t*)window + 0x50c) * cellX
           + *(int*)((uint8_t*)window + 0x504);
    pos[1] = *(int*)((uint8_t*)window + 0x510) * cellY
           + *(int*)((uint8_t*)window + 0x508);
    (*(void(**)(void*, int*))(*(void**)widget + 0x118))(widget, pos);
}
```

Live body matches raw; parent dual `aa_008605b0` §5.5 matches.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX/EAX | **High** | Broken ports |
| Pitch/origin formula | **High** | Misaligned icons |
| Does not touch item object | **High** | Fake inventory bug |
| Position blob arity | **Med** | Stack layout port risk |
| vfunc English name | **Probable** | Doc only |

---

## 4. Surviving contract for AutoCore

```text
// After stamping widget cell X/Y (page-local):
PlaceFromCell(widget, sheetWindow);
// px = originX + pitchX * cellX
// py = originY + pitchY * cellY
```

Inverse of DropToGrid page math remains **parent’s** responsibility, not this leaf.

**Verdict:** **accept-with-gaps**
