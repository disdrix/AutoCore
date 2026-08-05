# Review B (skeptical / adversarial): `aa_008ac110` UI_MissionDialog_BuildResponseButtons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ7R-B) |
| **Counterpart** | `reviews/A_aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is mission complete / packet send | **Falsified** — only new UI children + layout; no buffer/flush |
| 2 | Decompiler `cVar5 = ptr >> 24` is real | **Falsified** — bytes set/load stack flag `[esp+0x0F]` from last-item∧col0 predicate |
| 3 | Decompiler `unaff_EBP` is the **row** multiplier | **Falsified** — EBP = slot array cursor (`lea ebp,[edi+0x708]`; `add ebp,4`); Y uses `[esp+0x14]` row |
| 4 | Standard `__thiscall` ECX | **Falsified as exclusive** — body is **EDI-this**; no `mov edi,ecx` in this prologue (callers present EDI) |
| 5 | Column count can stay 0 | **Falsified** — clamp to 1 before idiv (avoids div0) |
| 6 | Always uses primary origin bases | **Falsified** — dual bases selected by last-alone flag; mode `{0,3}` adds extra |
| 7 | Scale constants are arbitrary magic | **Falsified** — exact 1/1600 and 1/1200 f32 |
| 8 | Name is product-sealed | **Not supported** — inferred from XML + parent BuildNpcMissionDialogWidgets |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Response-button strip role | **High** | Wrong chrome attribution |
| Grid / id / XML | **High** | Misbuilt dialog responses |
| Flag / row decompiler corrections | **High** | Broken last-row layout port |
| EDI-this ABI | **High** | Wrong register contract in hooks |
| Product spelling / mode enum English | **Low–Med** | Naming only |
| Child class full layout | **Med** (not OWN) | Size `0x4CC` only sealed |

---

## 3. Cross-check contract

```
BuildResponseButtons(dialog*):  // EDI
  if dialog[+0x4C0] == 0: return
  FUN_008aa560()
  cols = max(dialog[+0x640], 1)
  for i in 0 .. dialog[+0x510]-1:
    row, col = divmod(i, cols)
    alone_last = (i == count-1) && (col == 0)
    btn = new(0x4CC); ctor FUN_0079c860; slots[i] = btn
    dialog.vtbl+0xA8 attach
    btn.load("i_d_npc_2d_btn_response.xml")
    btn.setId(0x9C46 + i)
    btn.setSize(scale(w,h))   // * viewport * (1/1600, 1/1200)
    base = alone_last ? originB : originA
    pos = base + (col*strideX, row*strideY)
    if mode in {0,3}: pos += extra
    btn.setPos(scale(pos))
```

Clean must **not** invent C2S traffic, mission journal list fill, or scrollbar math (those are sibling OWN units).

---

## 4. Surviving contract for AutoCore

```c
// Client UI only — mission NPC dialog response strip
struct MissionDialogUi {
  // ...
  int  chromeGate;     // +0x4C0
  int  responseCount;  // +0x510
  int  columns;        // +0x640  (min 1)
  int  layoutMode;     // +0x648  // {0,3} → extra origin
  int  originBx, originBy; // +0x5B4 / +0x5B8
  int  extraX, extraY;     // +0x5BC / +0x5C0
  int  originAx, originAy; // +0x5C4 / +0x5C8
  int  btnW, btnH;         // +0x5CC / +0x5D0
  int  strideX, strideY;   // +0x5D4 / +0x5D8
  UiWidget* responseSlots[]; // +0x708 …
};

// control ids: 0x9C46 + index
// design ref: 1600 x 1200
```

Server mission logic does **not** need this builder; DevTool dialog mocks should honor grid + id base if replaying UI.

---

## 5. Gaps (aligned with A)

1. Product name.  
2. Non-OWN callees.  
3. Product meaning of last-alone + mode enum.  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
