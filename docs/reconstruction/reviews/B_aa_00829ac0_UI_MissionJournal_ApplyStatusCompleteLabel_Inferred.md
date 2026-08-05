# Review B (skeptical / adversarial): `aa_00829ac0` UI_MissionJournal_ApplyStatusCompleteLabel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-G) |
| **Counterpart** | `reviews/A_aa_00829ac0_UI_MissionJournal_ApplyStatusCompleteLabel_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is objective-list refresh (`RefreshObjectiveList`) | **Falsified** — only status SetText + refresh; no list enumeration |
| 2 | thiscall with panel in ECX | **Falsified** — panel in **ESI**; AL flag |
| 3 | Complete path is single-arg SetText only | **Falsified** — bytes push `1`,`1` then string (same as clear path arity) |
| 4 | Operates on title widget +0x508 | **Falsified** — uses **+0x50c** status (build path stamps status XML there) |
| 5 | Ready AL is ignored (W24-J parent body) | **Context** — parent SelectMission does not branch on AL, but **this** unit **consumes** AL |
| 6 | Sends mission claim / complete packet | **Falsified** — pure UI vtbl calls |
| 7 | Scaffold alone is dual-complete | **Falsified** — ABI + string + dual-arg SetText needed seal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Status complete label role | **High** | Mis-port as list rebuild |
| ESI / AL ABI | **High** | call-site corruption |
| Offsets | **High** | wrong widget |
| String | **High** | wrong chrome |
| SetText arity | **High** | stack imbalance if emulated wrong |
| AL product meaning | Medium | wrong badge condition |
| Construct caller intent | Low–Med | init flash of "(complete)" |

---

## 3. Cross-check against raw + bytes

```
status = [esi+0x50c]
[esi+0x4fd] = al
if !status: ret
push 1; push 1
if al: push "(complete)"; else push 0
call [status.vtbl+0x1d8]
status = [esi+0x50c]; jmp [status.vtbl+0x34c]
```

Clean must **not** invent objective walks, title sprintf, packet sends, or ECX thiscall.

---

## 4. Surviving contract for AutoCore

```csharp
// Client UI only — no wire
void ApplyStatusCompleteLabel(JournalPanel panel, bool complete)
{
    panel.StatusCompleteFlag = complete;
    var status = panel.StatusWidget; // +0x50c
    if (status == null) return;
    status.SetText(complete ? "(complete)" : null, 1, 1);
    status.Refresh(); // vtbl+0x34c
}
```

Call from select path with the same bool returned by journal-ready / complete predicate used at `SelectMission`.

---

## 5. Open questions

1. Product name of flag field and method.  
2. Whether IsMissionJournalReady return is the intended complete badge source (likely; confirm product).  
3. Why construct path (`FUN_00829ce0`) calls this without an explicit flag set.  
4. Runtime golden for select complete vs incomplete missions.

**Verdict:** **accept-with-gaps**
