# Review B (skeptical / adversarial): `aa_008285a0` UI_QuickBarSlotButton_AssignItemObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008285a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-026) |
| **Counterpart** | `reviews/A_aa_008285a0_UI_QuickBarSlotButton_AssignItemObject_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + xrefs.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is skill-assign, not item | **Falsified** — kind forced to 2; SetQuickBarItem; pSkill=0; SetQuickBarSkill(−1) |
| 2 | Same unit as AssignItem `0x008283a0` | **Falsified** — different VA; object* EAX + button ESI vs button EAX + id ECX; no GiveItemByCbid; null returns 0 not clear-slot |
| 3 | Same ABI as skill twin (EAX skill, stack button, ret 4) | **Falsified** — button ESI; plain `ret`; item not skill |
| 4 | Slot is raw column only | **Falsified** — page*10+column |
| 5 | Leaves skill id intact | **Falsified** — SetQuickBarSkill(−1) after item set |
| 6 | Always clears selection | **Falsified** — only if bChanged && fSelected |
| 7 | Sends QuickBarUpdate packet itself | **Falsified** — no send callee; only character setters + UI |
| 8 | DAT_00afdf0c is an icon path string | **Falsified** — color dword block (`ffffffff` / `3f800000`) |
| 9 | Decompiler `FUN_0085d970()` is argless | **Falsified as complete** — disasm `PUSH path; PUSH item; CALL` |
| 10 | Partition parent `0x005208c0` is structural caller | **Falsified** — parent is score/callee SetQuickBarSkill; live xrefs are UI sites |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Item-object vs skill role | **High** | Wrong port for skill drag |
| Distinct from id-based AssignItem | **High** | Merge twins / wrong icon path |
| Slot indexing | **High** | Off-by-page corruption of QB arrays |
| Item set + skill clear order | **High** | Exclusive slot policy broken |
| ABI EAX/ESI/plain ret | **High** | Call-site corruption |
| Product English | Medium | Naming only |
| clonebase product type at +0xa8 | Medium | Field docs only |

---

## 3. Cross-check against raw + bytes

```
test edi,edi; jz ret0
cmp kind,2 / cmp idLo,eax / cmp idHi,edx -> bChanged
store kind=2; id (cdq from [ [item+0xa8]+0x34 ]); pSkill=0; slot=page*10+col
call SetQuickBarItem(id); call SetQuickBarSkill(-1)
optional SetSelected(0); FUN_0085d970(item,path); chrome; return 1
```

Clean must **not** invent packet sends, skill-id stores as item ids, GiveItemByCbid, or skill-twin ABI / AssignItem EAX-button ABI.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client mirror; exclusive-slot policy)
bool AssignItemObjectToQuickBarSlot(ItemObject item, QuickBarSlotButton button)
{
    if (item == null) return false;
    int id = item.CloneBase.Id; // *( *(item+0xa8)+0x34 )
    int slot = button.Page * 10 + button.Column;
    char.QuickBarItems[slot] = id; // + hi half if 64-bit
    char.QuickBarSkills[slot] = -1;
    button.BindItemFromObject(item, id);
    return true;
}
```

Contrast id-based twin: `AssignItem(itemId, button)` uses GiveItemByCbid for icon and accepts −1 clear.

---

## 5. Open questions

1. Caller paths that also emit C2S `0x2062`.
2. Whether id is always template CBID vs instance COID (source is clonebase+0x34).
3. Product method name; `char+0xcd0` object identity.

**Verdict:** **accept-with-gaps**
