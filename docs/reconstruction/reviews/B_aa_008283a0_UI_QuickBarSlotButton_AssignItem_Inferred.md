# Review B (skeptical / adversarial): `aa_008283a0` UI_QuickBarSlotButton_AssignItem_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008283a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-J) |
| **Counterpart** | `reviews/A_aa_008283a0_UI_QuickBarSlotButton_AssignItem_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is skill-assign, not item | **Falsified** — kind forced to 2; SetQuickBarItem; GiveItemByCbid; pSkill=0 |
| 2 | Same ABI as skill twin (EAX skill, stack button, ret 4) | **Falsified** — button EAX; itemId ECX; plain `ret` |
| 3 | Slot is raw column only | **Falsified** — page*10+column |
| 4 | Leaves skill id intact | **Falsified** — SetQuickBarSkill(−1) after item set |
| 5 | Always clears selection | **Falsified** — only if bChanged && fSelected |
| 6 | Sends QuickBarUpdate packet itself | **Falsified** — no send callee; only character setters + UI |
| 7 | Scaffold CreateCharacter name is product role | **Falsified as product** — QB slot item assign; create path is indirect via rebind |
| 8 | DAT_00afdf0c is an icon path string | **Falsified** — color dword block (`ffffffff` / `3f800000`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Item vs skill role | **High** | Wrong port for skill drag |
| Slot indexing | **High** | Off-by-page corruption of QB arrays |
| Item set + skill clear order | **High** | Exclusive slot policy broken |
| ABI EAX/ECX/plain ret | **High** | Call-site corruption (≠ skill twin) |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
cmp ecx,-1; jz clear_slot
cmp kind,2 / cmp idLo,ecx / cmp idHi,edx -> bChanged
store id (cdq); kind=2; pSkill=0; slot=page*10+col
call SetQuickBarItem(id); call SetQuickBarSkill(-1)
optional SetSelected(0); GiveItemByCbid icon; return 1
```

Clean must **not** invent packet sends, skill-id stores as item ids, or skill-twin ABI.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client mirror; server exclusive-slot already exists)
bool AssignItemToQuickBarSlot(int itemId, QuickBarSlotButton button)
{
    if (itemId == -1) { ClearActiveSlot(); return true; }
    int slot = button.Page * 10 + button.Column;
    // exclusive: set item, clear skill
    char.QuickBarItems[slot] = itemId; // + hi half if 64-bit COID
    char.QuickBarSkills[slot] = -1;
    button.BindItem(itemId);
    return true;
}
```

---

## 5. Open questions

1. Caller paths that also emit C2S `0x2062`.
2. Whether ECX is always template CBID (GiveItemByCbid) or sometimes instance COID.

**Verdict:** **accept**
