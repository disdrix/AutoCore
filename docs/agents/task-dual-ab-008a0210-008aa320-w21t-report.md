# Dual A/B report — W21-T OWN-ONLY (`0x008a0210`, `0x008aa320`)

**Date:** 2026-07-29  
**Agent:** W21-T OWN-ONLY  
**Scope:** OWN ONLY VAs `0x008a0210`, `0x008aa320`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis / assembly context). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_008a0210` QuickBar_CycleSelectValidColumn | **accept** — **EBX host, dir stack, 10-col cycle + SetSelected pair + bootstrap sealed; product spelling residual** |
| `aa_008aa320` NpcMissionDialog_TeardownChildWidgetLists | **accept** — **ESI dialog, two child vectors, vtbl+0x440→+0xb0 sealed; leaf of named FUN_*; product list English residual** |

---

## `aa_008a0210` — QuickBar_CycleSelectValidColumn

### Sealed facts

1. **Body:** `0x008a0210`–`0x008a0368` exclusive (**344** B). Final `ret 4` (`c2 04 00`); following `cc` pad then next function.

2. **ABI:** **EBX = CDlgQuickBar host***; stack **`char direction`** (0=prev, ≠0=next); **`ret 4`**. Frame: `push ebp; push esi; lea ebp,[ebx+0x63c]; push edi`. **Always AL=0**.

3. **Algorithm:**
   - Scan 10 columns at `host+0x63c` for `col+0x4fc != 0` (current selection).
   - Walk adjacent (next/prev, wrap 0..9) for first filled `col+0x548 ∉ {0, 6}`.
   - On hit: `UI_QuickBarSlotButton_SetSelected(current, 0)` then `SetSelected(target, 1)` — **different ECX** (decompiler drops rewrite; sealed from bytes).
   - If no selection (`cur==10`): bootstrap first filled column (RTTI → `FUN_0089fef0` → highlight `+0x56c vtbl+4(1)` → `DAT_00d1da38[page]=col+0x500` → `+0x4fc=1`).

4. **Globals / RTTI:** `DAT_00d1da38`; gfxUIWindow RTTI `0x00afe190`; CDlgQuickBar RTTI `0x00afe3b4`. Live host often `DAT_00d1b8f0`.

5. **Callees:** `UI_QuickBarSlotButton_SetSelected` (`0x00826780`); bootstrap: `__RTDynamicCast`, `FUN_0089fef0`, highlight virtual.

6. **Callers (8):** SkillTrainUiRequest; SelectPage (`008a0ed0`); `FUN_008a16b0`; `FUN_009114f0`×2 (push 1 / push 0); `FUN_009163a0` (push CL=SETG); PollBoundActions×2.

7. **Name:** structural `QuickBar_CycleSelectValidColumn`. Residual PollBoundActions-only auto-seed **incomplete**.

### Gaps

1. Product/PDB method spelling on `CDlgQuickBar`.  
2. English of fill sentinel **6**.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_008a0210_QuickBar_CycleSelectValidColumn.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_008a0210_QuickBar_CycleSelectValidColumn.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_008a0210_QuickBar_CycleSelectValidColumn.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008a0210_QuickBar_CycleSelectValidColumn.md` |
| Function record | `docs/reconstruction/functions/aa_008a0210_QuickBar_CycleSelectValidColumn.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_008a0210_FUN_008a0210.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_CycleSelectValidColumn.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_008a0210.cpp` |
| Raw | `docs/reconstruction/raw/aa_008a0210_FUN_008a0210.md` |
| Annotated | `docs/reconstruction/raw/aa_008a0210_FUN_008a0210.annotated.md` |

---

## `aa_008aa320` — NpcMissionDialog_TeardownChildWidgetLists

### Sealed facts

1. **Body:** `0x008aa320`–`0x008aa3ef` exclusive (**207** B). Final bare `c3`; next function follows.

2. **ABI:** **ESI = NpcMissionDialog***; bare **`ret`**. Saves EBX/EBP/EDI. **Not** ECX-thiscall.

3. **CF:** Two vector walks:
   - begin/end `ESI[0x1cb]/[0x1cc]` → **+0x72c / +0x730**
   - begin/end `ESI[0x1cf]/[0x1d0]` → **+0x73c / +0x740**  
   Count = `(end-begin)>>2` when begin ≠ 0; else 0.  
   Per non-null child: **`child->vtbl+0x440()`** then **`dialog->vtbl+0xb0(child)`**.

4. **Does not:** clear `+0x650`, free vector storage, zero begin/end, or call dialog `vtbl+0x3ac`.

5. **Callees:** pure virtuals only (no named FUN_*).

6. **Callers (1):** `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab998` (ESI live; then `vtbl+0x3ac` → `FUN_00792490`).

7. **Name:** structural `NpcMissionDialog_TeardownChildWidgetLists` (Flush dual already noted “tears child lists only”).

### Gaps

1. Product English of the two child lists.  
2. Product names for `vtbl+0xb0` / child `vtbl+0x440`.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` |
| Function record | `docs/reconstruction/functions/aa_008aa320_NpcMissionDialog_TeardownChildWidgetLists.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_008aa320_FUN_008aa320.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NpcMissionDialog_TeardownChildWidgetLists.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_008aa320.cpp` |
| Raw | `docs/reconstruction/raw/aa_008aa320_FUN_008aa320.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa320_FUN_008aa320.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### CycleSelectValidColumn (`0x008a0210`)

- Port as **UI selection cycle**, not skill cast / QuickBarUpdate wire.
- Preserve **EBX host + stack direction + ret 4**; always ignore return (AL=0).
- Honor fill gate **`+0x548 ∉ {0,6}`** and selected flag **`+0x4fc`**.
- Pair deselect/select must target **current then next** columns (two this pointers).
- Bootstrap path when nothing selected: first filled column only.

### TeardownChildWidgetLists (`0x008aa320`)

- Call with **dialog in ESI** (or explicit equivalent) from flush/close path after wire work.
- Tear **both** vectors; order **child 0x440 → dialog 0xb0**.
- Do **not** fold wire flush / `+0x650` clear / `vtbl+0x3ac` into this unit.

### Pairing

Units are **unrelated** systems (quickbar UI vs mission dialog). Co-owned only for W21-T dual batching; no shared data path.

---

## This report

`docs/agents/task-dual-ab-008a0210-008aa320-w21t-report.md`
