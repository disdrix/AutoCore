# Review B (skeptical / adversarial): `aa_00826860` UI_QuickBarSlotButton_AssignSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-D) |
| **Counterpart** | `reviews/A_aa_00826860_UI_QuickBarSlotButton_AssignSkill_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is item-assign, not skill | **Falsified** — kind forced to 1; SetQuickBarSkill; skill+0x5fc |
| 2 | thiscall with button in ECX | **Falsified** — skill in EAX; button stack; ret 4 |
| 3 | Slot is raw column only | **Falsified** — page*10+column |
| 4 | Leaves item COID intact | **Falsified** — SetQuickBarItem(−1,−1) first |
| 5 | Always clears selection | **Falsified** — only if bChanged && fSelected |
| 6 | Sends QuickBarUpdate packet itself | **Falsified** — no send callee; only character setters + UI |
| 7 | Scaffold CreateCharacter name is product role | **Falsified as product** — QB slot assign; create path is indirect via rebind |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Skill vs item role | **High** | Wrong port for item drag |
| Slot indexing | **High** | Off-by-page corruption of QB arrays |
| Item clear + skill set order | **High** | Exclusive slot policy broken |
| ABI EAX/stack | **High** | Call-site corruption |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
test skill; jz ret0
cmp kind,1 / cmp pSkill,skill -> bChanged
skillId = [skill+0x5fc]; store button; kind=1; slot=page*10+col
call SetQuickBarItem(-1,-1); call SetQuickBarSkill(skillId)
optional SetSelected(0); rebuild icon path; return 1
```

Clean must **not** invent packet sends or item COID stores as skill ids.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client mirror already partially exists server-side)
bool AssignSkillToQuickBarSlot(SkillObject skill, QuickBarSlotButton button)
{
    if (skill == null) return false;
    int slot = button.Page * 10 + button.Column;
    // exclusive: clear item, set skill (server CharacterSkillService.TryUpdateQuickBar)
    char.QuickBarItems[slot] = -1;
    char.QuickBarSkills[slot] = skill.Id;
    button.BindSkill(skill);
    return true;
}
```

---

## 5. Open questions

1. Caller paths that also emit C2S `0x2062`.
2. Icon-state `+0x4fe` readers elsewhere.

**Verdict:** **accept**
