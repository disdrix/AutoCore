# Review B (skeptical / adversarial): `aa_00860700` Client_UI_InventorySheet_RebuildItemWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/A_aa_00860700_Client_UI_InventorySheet_RebuildItemWidgets.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on rebuild CF + ESI ABI; **reject** claims this sends inventory packets or is pure thiscall |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Standard `__thiscall` (ECX=this) | Body uses **ESI**; no `mov esi,ecx` entry | **Falsified** |
| 2 | This is mission-only | Callers include trade, cargo, equip sheets | **Falsified** |
| 3 | This mutates item grid occupancy | Only UI clear + widget add | **Falsified** |
| 4 | Always runs full body | Gate on `+0x56c==0` early return | **Falsified** always-run |
| 5 | AddItemWidget free call | Asm sets **EDI=ESI**, **EBX=item** first | **Falsified framing** |
| 6 | `FUN_00413be0` returns item* | Returns status; TFIDs in out-params; resolve separate | **Clarify** |
| 7 | Ready product rename | Role name only | **Open** |

---

## 2. Decisive dataflow (SEALED)

```text
void Client_UI_InventorySheet_RebuildItemWidgets(void) // ESI = window*
{
    if (*(void**)((uint8_t*)ESI + 0x56c) == nullptr)
        return;

    // local TFID list + CS …
    FUN_0085fd80(/*clear widgets on this sheet*/);
    FUN_00571260(&list, *(uint8_t*)((uint8_t*)ESI + 0x564));

    while (FUN_00413be0(&cursor, &tfid) == 0) {
        Item* item = CVOGReaction_ResolveObjectTarget(1, tfid.lo, tfid.hi);
        if (item) {
            // EDI = ESI, EBX = item
            Client_UI_InventorySheet_AddItemWidget();
        }
    }
    // list unlock/teardown …
    (*(void(**)(void*))(*(void**)ESI + 0x34c))(ESI);
}
```

Live ≡ raw. Child dual `aa_008605b0` seals Add path including ctor `0085e590` + place `0085f150`.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI this + gate | **High** | No-op / crash ports |
| Clear→collect→add→refresh | **High** | Wrong refresh order |
| UI-only (no C2S) | **High** | Fake network side effect |
| Collect/clear callee English | **Probable** | Doc drift |
| Page-only vs full bag | **Med** | Miss multi-page bugs |

---

## 4. Surviving contract for AutoCore

```text
// After inventory S2C / trade bind / mission pane open:
//   ESI = sheet window with typeHost at +0x56c
Client_UI_InventorySheet_RebuildItemWidgets();
// widgets recreated; model unchanged
```

**Verdict:** **accept-with-gaps**
