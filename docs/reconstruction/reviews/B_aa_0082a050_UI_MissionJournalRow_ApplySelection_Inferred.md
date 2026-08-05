# Review B (skeptical / adversarial): `aa_0082a050` UI_MissionJournalRow_ApplySelection_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082a050` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md` |
| **Agent** | W24-K OWN-ONLY |
| **Verdict** | **accept** on CF/ABI; **needs-more-evidence** only on product names |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is dead | 3 static CODE xrefs from journal rebuild | **Falsified** |
| 2 | `VOG_DEBUG_STOP` product role | No such string in body; legacy scaffold only | **Falsified** |
| 3 | This is turn-in claim chrome | Uses `IsMissionJournalReady` mode-0, not `IsMissionTurnInReady` | **Falsified** |
| 4 | Stack-arg thiscall | Entry uses EAX+ECX; epilogue plain `ret` | **Falsified** — register ABI |
| 5 | Always shows Complete | Requires journal-ready true + widgets | **Falsified** — empty label path |
| 6 | Kind field is full dword enum | Compare uses **low byte** only (`cmp byte [edi],0` / `kind==1/2`) | **Survives refined** — byte discriminant |
| 7 | Clean deleted clear path | Both clear + apply preserved | **Falsified** |
| 8 | `(Complete)` used elsewhere for same chrome | Sole xref to string is this VA | **Supports** ownership of journal chrome string |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX/EAX ABI | **High** | Wrong call framing in ports |
| Kind0 clear | **High** | Stale selection chrome |
| Kind1 title format | **High** | Wrong journal list text |
| Complete via journal-ready | **High** | False complete / claim confusion |
| Not turn-in | **High** | Collapsed with `0052b420` |
| Product names | **Tentative** | Docs only |
| Kind2 semantics | **Tentative** | Mis-typed payload |

---

## 3. Cross-check against raw / image

### Spine

```
sel null/kind0 → clear fields + hide title + layout
kind1 → "[level] name" + optional recolor
kind2 → title from p2+0x10
complete_label ← IsMissionJournalReady ? "(Complete)" : ""
always FUN_00829fa0 (layout)
```

### Image seals

| Fact | Bytes / pattern |
|---|---|
| Frame 0x208 | `81 EC 08 02 00 00` |
| EDI=EAX, ESI=ECX | entry movs |
| Journal-ready site | `mov ecx,[DAT_00d1b6d8]` + `call FUN_0052b3b0` @ `0x0082a248` |
| Epilogue | `add esp,0x208; ret` |

### Caller framing (`FUN_008a5240`)

After constructing/binding a row (`FUN_0082a8b0` size `0x534`), calls `FUN_0082a050` with selection in EAX / row in ECX — rebuilds active-mission journal rows.

Clean preserves spine. **No claim packet. No invented turn-in gate.**

---

## 4. Surviving contract for AutoCore

```
// Journal row selection chrome only — NOT claim/turn-in
void ApplyJournalRowSelection(Row row, Selection sel):
  if !sel or sel.kind==0: clear row selection; hide title; layout; return
  store sel on row
  if sel.kind==1: row.title = sprintf("[%d] %s", mission.level, mission.name)
  if sel.kind==2: row.title = sel.p2.string_at_0x10
  row.completeLabel = IsMissionJournalReady(localChar, mission) ? "(Complete)" : ""
  layout(row)

// Do NOT use IsMissionTurnInReady here.
// Do NOT send mission dialog / claim packets from this VA.
```

---

## 5. Open questions

1. Retail row-widget class name.
2. Kind 2 producers.
3. Runtime visual parity of recolor path (`FUN_006a3db0`×3).

**Verdict:** Adversarial review **accepts** ABI, selection kinds, and journal-ready complete chrome. Residual = naming / kind2 type only.
