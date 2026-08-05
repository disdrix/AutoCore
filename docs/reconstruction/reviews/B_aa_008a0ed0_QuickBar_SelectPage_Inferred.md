# Review B (skeptical / adversarial): `aa_008a0ed0` QuickBar_SelectPage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008a0ed0_QuickBar_SelectPage_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF; role **High**; product name `_Inferred` |

---

## 1. Claims under attack

| # | Claim | Attack | Residual outcome |
|---|---|---|---|
| 1 | This is slot activate / cast helper | Parent ActivateSlot mode-1 **returns after** this call; body never walks `client+0x3220` payloads | **Retracted.** Page select only |
| 2 | `param_1[0x143]` is something other than page | ActivateSlot resolves `page==-1` from `UI+0x50c`; SkillTrain uses `host[0x143]*10` as page base for empty-slot scan | **Holds** as current page |
| 3 | `DAT_00d1da38` is a type/content table | Stride 4, indexed by page; `FUN_00826780` writes **column** `widget+0x500` into it; content types live at `DAT_00d1da60` stride 0x18 | **Holds** as per-page last-column memory |
| 4 | Ten widgets are all pages | Loop bound 10; ActivateSlot flatIndex uses **page*10 + slot** with slots 0..9 | **Holds** as columns on current page |
| 5 | `FUN_008a0210(1)` is "cancel" | Body walks columns for next non-empty; direction arg 0/1; used from PollBoundActions binds too | **Holds** as auto-select next valid column |
| 6 | Mode-1 uses resolved UI page | PollBoundActions shift-QB: `ActivateSlot(i,1,-1)` — page formal is -1 but mode-1 exits before flatIndex; page index is the **slot formal** | **Holds** (slot-as-page); EAX handoff still decomp-noisy |
| 7 | Empty mask is definitely item COID | Idiom matches empty COID `(lo&hi)==-1` but widget fields may hold skill sentinels too | **CF holds**; product field name **open** |
| 8 | Host class is certainly `CDlgQuickBar` | RTTI cast is on **column activate** path, not SelectPage entry | **Probable** only — leave `_Inferred` host type |

---

## 2. Surviving contract for AutoCore

```
QuickBar_SelectPage(host, page):
  if page not in 0..9: return
  host.currentPage (+0x50c) = page
  prevCol = g_pageLastColumn[page]          // DAT_00d1da38[page]
  for each of 10 column widgets at host+0x63c:
    widget.page (+0x504) = page
    if widget.selected (+0x4fc): DeactivateColumn(widget)
  RebindPageWidgets(host)                   // FUN_008a0e10 ← DAT_00d1da60[page*10+i]
  host.RefreshChrome()                      // vtbl+0x448
  if prevCol invalid or widget empty:
    AutoSelectNextColumn(host, dir=+1)      // FUN_008a0210(1)
  else:
    ActivateColumn(widget[prevCol])         // FUN_00826780(1)
  clear residual hover index (DAT_00d1a9fc)
  host.FinalLayout()                        // vtbl+0x34c
```

Server parity:

- **No wire.** Page is pure client UI state.
- Slot contents / QuickBarUpdate remain on other units (`0x2062`).
- Do not invent server "page" fields.

---

## 3. Skeptical hits on residual “seals”

| Seal | Challenge | Hold? |
|---|---|---|
| Page in EAX | Could some callers pass page in another reg? | **Hold** for this body (`in_EAX`); per-caller setup still residual |
| 10 pages | Could pages be 0..7 only in product UI? | **Hold gate** as coded `[0,9]`; UI chrome may hide some |
| `DAT_00d1da60` mirror vs `client+0x3220` | Two tables? Risk of drift story | **Both exist** in decomp; rebind uses global `d1da60`; activate uses client table — **document dual mirror**, do not merge without owner dual |
| Name SelectPage | No string | **Keep `_Inferred`** |

---

## 4. Cross-check vs parent dual

Parent residual (`aa_009436c0`) claimed:

> `FUN_008a0ed0`: page index clamp **[0,9]** → `ui[0x143]` (`+0x50c`); refresh 10 column widgets; **Page select**, not slot activate.

This dual **confirms** that claim with full body CF + callee map. No retraction.

---

## 5. Open questions

1. Caller EAX framing (especially page±delta and show-refresh).
2. Global rename of callees + `DAT_00d1da38` / `DAT_00d1a9fc`.
3. Relationship / sync between `DAT_00d1da60` and `client+0x3220` slot tables (out of unit).
4. Live shift-QB / page-key capture.
5. Bit-for-bit / diff.

**Verdict:** Safe to treat as client-only page switch for hotbar UI. **accept-with-gaps.**
