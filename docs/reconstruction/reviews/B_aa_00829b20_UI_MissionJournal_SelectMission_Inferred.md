# Review B (skeptical / adversarial): `aa_00829b20` UI_MissionJournal_SelectMission_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829b20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-J) |
| **Counterpart** | `reviews/A_aa_00829b20_UI_MissionJournal_SelectMission_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is turn-in / claim gate | **Falsified** — calls journal-ready mode-0 helper, not turn-in `0052b420`; no claim packet |
| 2 | thiscall with context in ECX | **Falsified** — context in **EAX**; mission in **EDI** |
| 3 | Ready bool gates the list refresh | **Falsified in this body** — `FUN_00829ac0` follows unconditionally when char non-null |
| 4 | Title is free-form mission name only | **Falsified** — sprintf `"[%d] %s"` with level short |
| 5 | Writes mission pointer, not id | **Falsified** — stores `*mission` dword id at +0x500 |
| 6 | Product name Client_UpdateMissionJournal is this unit | **Falsified** — this is a nested select/bind helper; parent is `008ae130` |
| 7 | No dual needed — scaffold enough | **Falsified** — ABI + ready framing + string needed seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Journal select role | **High** | Mis-port as claim/turn-in |
| Title format | **High** | Wrong UI chrome |
| ABI EAX/EDI | **High** | Call-site corruption |
| Ready call identity | **High** | Wrong predicate sibling |
| Ready AL usage here | **High** (none) | Overclaim gating |
| Color formula | Low–Med | Visual only residual |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
sub esp,0x208; mov esi,eax
call [esi.vtbl+0x3d8]; jz out
test edi,edi; jz out
if title: sprintf("[%d] %s", level@+0x11c, name); set text; color path
if char: IsMissionJournalReady(char, edi); FUN_00829ac0()
optional chrome color copy
mov [esi+0x500], [edi]
ret
```

Clean must **not** invent packet sends, turn-in NPC filters, or ready-AL branching inside this VA.

---

## 4. Surviving contract for AutoCore

```csharp
// Client journal selection apply (UI only; no wire)
void SelectMissionInJournal(JournalPanel ctx, MissionDef mission)
{
    if (!ctx.IsLive() || mission == null) return;
    ctx.Title = $"[{mission.Level}] {mission.Name}";
    if (localChar != null) {
        _ = localChar.IsMissionJournalReady(mission); // side-effect free bool
        ctx.RefreshObjectiveList();                   // FUN_00829ac0
    }
    ctx.SelectedMissionId = mission.Id;
}
```

Server already owns readiness / objective state; this unit is **client UI chrome + selection store**.

---

## 5. Open questions

1. Product field names for level/name offsets.
2. FUN_00829ac0 dual (whether it re-reads ready).
3. Color residual duals.

**Verdict:** **accept-with-gaps**
