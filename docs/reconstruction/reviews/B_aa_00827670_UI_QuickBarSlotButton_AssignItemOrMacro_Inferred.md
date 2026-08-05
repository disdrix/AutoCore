# Review B (skeptical / adversarial): `aa_00827670` UI_QuickBarSlotButton_AssignItemOrMacro_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00827670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-I) |
| **Counterpart** | `reviews/A_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus call-site reads; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is skill assign | **Falsified** — SetQuickBarSkill(−1); no skill+0x5fc |
| 2 | ECX thiscall button | **Falsified** — ESI button; EAX kind; ret 4 |
| 3 | Macro-only (no Power/Battle) | **Falsified as body** — kinds 3/4 present; **callers** may only pass 5 |
| 4 | Same ABI as AssignSkill | **Falsified** — skill uses skill@EAX + button@stack |
| 5 | Leaves skill id intact | **Falsified** — skill forced −1 |
| 6 | Sends C2S QuickBarUpdate | **Falsified** — no send callee in body |
| 7 | CreateCharacter is direct role | **Falsified** — only indirect via rebind |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Item vs skill role | **High** | wrong exclusive policy |
| Slot page*10+col | **High** | QB array corruption |
| ESI/EAX ABI | **High** | call-site corruption |
| Kind 5 macro chrome | **High** | wrong icon |
| Live use of kinds 3/4 | Medium | chrome dead code risk only |
| Product English | Medium | naming |

---

## 3. Cross-check against raw + bytes

```
kind@EAX, id@stack, button@ESI
store; SetItem(id); SetSkill(-1); chrome 3/4/5; ret 1
```

Clean must **not** invent skill-object loads or packet sends.

---

## 4. Surviving contract for AutoCore

```csharp
// Client UI mirror (server already has exclusive slot policy)
bool AssignItemOrMacroToQuickBarSlot(QuickBarSlotButton btn, int kind, int id)
{
    int slot = btn.Page * 10 + btn.Column;
    char.QuickBarItems[slot] = id;   // or macro id in item lane
    char.QuickBarSkills[slot] = -1;
    btn.BindKindAndId(kind, id);
    return true;
}
// Table type 5 → kind 5 macro path from QuickBar_RebindPageColumns
```

---

## 5. Open questions

1. Callers that pass kind 3/4 (if any beyond body support).  
2. C2S `0x2062` emitters on drag paths (outside this unit).  
3. Meaning of display bias `id+0xbb9` (3001).

**Verdict:** **accept**
