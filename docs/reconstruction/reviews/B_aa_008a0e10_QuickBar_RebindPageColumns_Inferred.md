# Review B (skeptical / adversarial): `aa_008a0e10` QuickBar_RebindPageColumns_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0e10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This **selects** the QuickBar page | No store to `host+0x50c`; only reads page | **Falsified** — SelectPage is `0x008a0ed0` |
| 2 | This **activates** a slot / casts skill | No network; only UI bind/clear callees | **Falsified** |
| 3 | Decompiler args are complete | type-2 shows `FUN_008283a0()` bare; type-1 only widget | **Falsified completeness** — bytes set EAX/ECX/stack |
| 4 | thiscall ECX=host | Epilogue `RET 4`; host from `[esp+8]` via EBP | **Falsified** thiscall — **stdcall** |
| 5 | Types other than 1/2/5 do something special | else → ClearActiveSlot only | **Survives** as clear |
| 6 | Table stride is 0x10 or 0x20 | Scale: index×0x18 via lea chain | **Falsified** other strides |
| 7 | Always rebinds even if hidden | Double gate vtbl+0x3d8 and DAT_00d1b6d8 | **Falsified** always |
| 8 | Name RebindPageColumns wrong | Called from SelectPage/CreateChildWidgets as rebind | **Survives** as inferred role |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Rebind-only role | **High** | Wrong UI feature ownership |
| stdcall host | **High** | Broken calls in ports |
| 1/2/5/else map | **High** | Wrong skill/item/macro chrome |
| Callee ABI details | **Probable** | Bind wrong id/widget if ports use decomp only |
| DAT_00d1b6d8 meaning | **Tentative** | Gate product name only |
| Product symbol | **Tentative** | Naming |

---

## 3. Cross-check against raw / bytes

```
raw: if vtbl+0x3d8 && DAT_00d1b6d8: fce10; for i<10: type=da60[page*10+i]; switch 1/2/5/else
bytes: RET 4; page at +0x50c; widgets +0x63c; type SUB 1/1/3 chain; richer callee setup
clean: CF ≡ raw; ABI notes in comments for type 1/2
```

No invented network or page-select logic in clean.

---

## 4. Surviving contract for AutoCore

```csharp
// UI-only. Porting server does not need this.
// Client parity / DevTool QB mock:
static void RebindPageColumns(QuickBarHost host)
{
    if (!host.IsReadyVirtual()) return;          // vtbl+0x3d8
    if (!GlobalQuickBarEnabled) return;          // DAT_00d1b6d8
    PrepareUiContext(QuickBarCtx);               // FUN_007fce10(&DAT_00d1a840)

    int page = host.CurrentPage;                 // +0x50c
    for (int col = 0; col < 10; col++)
    {
        var slot = SlotTable[page * 10 + col];   // stride 0x18
        var widget = host.ColumnWidgets[col];    // +0x63c
        switch (slot.Type)
        {
            case 1: BindSkill(widget, slot.SkillId); break;  // FUN_00826860
            case 2: BindItem(widget, slot.ItemId); break;    // FUN_008283a0
            case 5: BindMacro(widget, slot.MacroId); break;  // FUN_00827670(…, 5)
            default: ClearSlot(widget); break;
        }
    }
}
```

**Port traps to reject:**

- Implementing page selection inside this function.
- Trusting decompiler empty arg lists for type 1/2.
- Assuming ECX=host thiscall.
- Treating as network/skill-cast path.

---

## 5. Residual gaps (do not block seal)

1. Owner duals for the three bind callees + clear.
2. Product names / string xref for unit.
3. Live rebind on page button / create-character.
4. Exact 0x18 row typedef (extra fields unused here).

---

## Verdict

**accept-with-gaps** — adversarial review kills “this is SelectPage/Activate” and “decomp args are enough,” but cannot break the 10-column type-table rebind kernel. Gaps are naming + callee product ABI, not core CF.
