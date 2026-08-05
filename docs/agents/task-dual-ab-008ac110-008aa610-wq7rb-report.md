# Dual A/B report — WQ7R-B OWN `0x008ac110` + `0x008aa610`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ7R-B**  
**Scope:** VAs `0x008ac110`, `0x008aa610` only. Dual A/B + artifacts.  
**Partition:** WQ-007 residual — Mission UI helpers.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008ac110` `UI_MissionDialog_BuildResponseButtons_Inferred` | **accept-with-gaps** — gate/grid/XML/id/scale/mode sealed; decomp flag+row bugs corrected by bytes; product plate open |
| `aa_008aa610` `UI_MissionPanel_SyncListScrollbar_Inferred` | **accept-with-gaps** — ESI ABI, hide/pages/thumb/pos sealed; sole caller `FUN_008aaf60`; vtbl English open |

---

## VA `0x008ac110` — sealed facts

1. **Body:** `0x008ac110`–`0x008ac318` exclusive (**520** B / `0x208`).
2. **ABI:** **EDI = MissionDialogUi***; SEH `LAB_009b63f9`; bare **`RET`** (`C3`); saves EBX/EBP/ESI.
3. **Gate:** `dialog+0x4C0 != 0` else return.
4. **Pre:** `FUN_008aa560()`; clamp **columns** `+0x640` to **≥ 1**.
5. **Loop:** `i = 0 .. count-1`, `count` at `+0x510`; slot array at **`+0x708`** (EBP `+4`/iter).
6. **Grid:** `row = i / cols`, `col = i % cols` (`idiv`); row saved `[esp+0x14]`.
7. **Last-alone flag:** stack byte = 1 only when **last index and col==0**; else 0. Decompiler `btn>>24` is **wrong**.
8. **Child:** `operator_new(0x4CC)` → `FUN_0079c860`; attach `dialog vtbl+0xA8`.
9. **Chrome:** load **`i_d_npc_2d_btn_response.xml`** (`vtbl+0x28`); control id **`0x9C46 + i`** (`vtbl+0x74`).
10. **Size/pos scale:** `viewport * design * field`; **`DAT_00aaa67c = 0.000625` (1/1600)**, **`DAT_00aaa678 ≈ 0.000833333` (1/1200)**; viewport `DAT_00d1e818/1c` runtime.
11. **Origins:** flag0 → `+0x5C4/+0x5C8`; flag1 → `+0x5B4/+0x5B8`; + `stride*col/row`; if mode `+0x648` ∈ **{0,3}** add `+0x5BC/+0x5C0`.
12. **Y multiplier:** **row** (`[esp+0x14]`), not EBP (EBP is slot pointer) — bytes over decompile.
13. **Callers (5):** `Client_BuildNpcMissionDialogWidgets`, `Client_ShowNpcMissionDialogUI`, `Client_UpdateMissionJournal`, `FUN_008ac3f0`, `FUN_008ac890`.
14. **Name:** `UI_MissionDialog_BuildResponseButtons_Inferred` (Ghidra `FUN_008ac110`).

### Gaps

- Product / PDB English name.  
- Full dual of `FUN_008aa560` / `FUN_0079c860` (not OWN).  
- Product meaning of last-alone origin + mode enum beyond `{0,3}` offset.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008ac110_FUN_008ac110.md` |
| Annotated | `docs/reconstruction/raw/aa_008ac110_FUN_008ac110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionDialog_BuildResponseButtons_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ac110.cpp` |
| Function | `docs/reconstruction/functions/aa_008ac110_FUN_008ac110.md` |
| Function named | `docs/reconstruction/functions/aa_008ac110_UI_MissionDialog_BuildResponseButtons_Inferred.md` |

---

## VA `0x008aa610` — sealed facts

1. **Body:** `0x008aa610`–`0x008aa758` exclusive (**328** B / `0x148`).
2. **ABI:** **ESI = MissionUiPanel***; `sub esp,0x18` / `add esp,0x18`; bare **`RET`**.
3. **Early out:** `panel+0x700 == 0` (no scrollbar) → return.
4. **List:** `panel+0x6E0`; require list + `vtbl+0x1B8()` metrics host else **hide** bar (`vtbl+0x04`).
5. **Metrics:** `vtbl+0x140` pair → viewport in second dword; `vtbl+0x204(&content)` (content local starts 1).
6. **Fit hide:** if `content <= viewport` → bar `vtbl+0x04(0)` return.
7. **Pages:**  
   `pages = (lineStep - viewport + content - 1) / lineStep`  
   with `lineStep = *(*metrics + 0x7C)`; store **`panel+0x704`**; clamp **min 1**.
8. **Show:** if bar `vtbl+0xD0()` false → `vtbl+0xFC(1, 0x3F000000)` (**0.5f**).
9. **Thumb:** bar `vtbl+0x460(g_flOne / pages)`.
10. **Position:** `list.vtbl+0x218(0) / pages` → bar `vtbl+0x454`.
11. **Caller (1):** `FUN_008aaf60` @ `0x008ab084` (post list rebuild).
12. **Name:** `UI_MissionPanel_SyncListScrollbar_Inferred` (Ghidra `FUN_008aa610`).

### Gaps

- Product scrollbar/list class + vtbl English.  
- Dual of caller `FUN_008aaf60` (sibling residual, not OWN).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008aa610_FUN_008aa610.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa610_FUN_008aa610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionPanel_SyncListScrollbar_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008aa610.cpp` |
| Function | `docs/reconstruction/functions/aa_008aa610_FUN_008aa610.md` |
| Function named | `docs/reconstruction/functions/aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008ac110` | **Client UI only** — NPC dialog response strip. Preserve EDI-this, id base `0x9C46`, design 1600×1200 scale, last-alone origin, mode `{0,3}` extra. No server mission logic. |
| `008aa610` | **Client UI only** — after list rebuild, recompute scrollbar pages/thumb/pos. Honor null bar, content≤viewport hide, min pages 1. Call order: list fill (`FUN_008aaf60` family) → this sync. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Trio+dual A/B residual partition **WQ7R-B** complete for this pair.

---

## This report

`docs/agents/task-dual-ab-008ac110-008aa610-wq7rb-report.md`
