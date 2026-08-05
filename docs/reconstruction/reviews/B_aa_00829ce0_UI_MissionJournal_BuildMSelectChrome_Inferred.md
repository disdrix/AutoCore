# Review B (skeptical / adversarial): `aa_00829ce0` UI_MissionJournal_BuildMSelectChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ce0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W26-R) |
| **Counterpart** | `reviews/A_aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is SelectMission / objective-list rebuild | **Falsified** — no mission walk, no sprintf objectives; only new widgets + XML + `00829ac0` |
| 2 | Status widget lives at title slot `+0x508` | **Falsified** — status stored `+0x50C`; title `+0x508` (matches peer dual) |
| 3 | Construct path calls `00829ac0` with undefined AL | **Falsified** — `mov al,[edi+0x4FD]` immediately before call |
| 4 | Category arm also builds button + status | **Falsified** — jnz skips to title_cat-only arm |
| 5 | `__cdecl` with stack panel pointer | **Falsified** — `mov edi,ecx` thiscall |
| 6 | Invented name without any evidence | **Falsified as pure invention** — four mselect XML strings + journal peers; name remains **Inferred** not product-sealed |
| 7 | Decompiler SEH assign is authoritative | **Falsified** — epilogue bytes restore `fs:[0]` cleanly; ignore `ExceptionList = in_stack_*` |
| 8 | Direct code callers exist in Ghidra | **Not supported** — only DATA xref `0x00a748c0`; dispatch is indirect |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mission vs category CF | **High** | Wrong UI skin on journal rows |
| Widget offsets | **High** | Corrupt peer SelectMission / complete-label paths |
| AL handoff to `00829ac0` | **High** | Mis-blame construct for “random” complete badge |
| Product method spelling | **Low–Med** | Naming only |
| `60000` property meaning | **Low** | Mis-port of button prop |
| Full child object layouts | **Med** (not OWN) | Size mismatch on alloc |

---

## 3. Cross-check against raw + bytes

```
FUN_00792600(panel)
if panel[+0x4FC] == 0:
  button = new(0x4CC)->FUN_0079c860
  panel[+0x504] = button; attach; load mission XML; prop 60000
  status = new(0x488)->FUN_007b5dd0(_,0)
  panel[+0x50C] = status; attach; load status XML
  AL = panel[+0x4FD]; ESI = panel; FUN_00829ac0()
  title = new(0x488)->FUN_007b5dd0(_,0)
  panel[+0x508] = title; attach
  titleXml = wnd_title.xml
else:
  title = new(0x488)->FUN_007b5dd0(_,0)
  panel[+0x508] = title; attach
  titleXml = wnd_title_cat.xml
load titleXml on title; refresh panel
```

Clean must **not** invent network mission sync, objective tree walks, or SelectMission binding.

---

## 4. Surviving contract for AutoCore

```c
// Port sketch — client UI only
struct MissionJournalPanel {
  // ...
  uint8_t categoryMode;   // +0x4FC
  uint8_t completeFlag;   // +0x4FD
  UiWidget* missionBtn;   // +0x504
  UiWidget* title;        // +0x508
  UiWidget* status;       // +0x50C
};

void BuildMSelectChrome(MissionJournalPanel* p) {
  BaseUiPass(p);
  if (!p->categoryMode) {
    // button + status + ApplyStatusCompleteLabel(p, p->completeFlag) + title
  } else {
    // title_cat only
  }
  Refresh(p);
}
```

XML asset names must match retail strings for skin parity.

---

## 5. Open questions

1. Product plate / source file name.  
2. Who writes `+0x4FC` and when.  
3. Meaning of `60000` on button `vtbl+0x74`.  
4. Runtime golden with journal open.  

**Verdict:** **accept-with-gaps**
