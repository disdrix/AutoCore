# Review B (skeptical / adversarial): `aa_008aa610` UI_MissionPanel_SyncListScrollbar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa610` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ7R-B) |
| **Counterpart** | `reviews/A_aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This rebuilds mission list contents | **Falsified** — only scrollbar sync; list fill is caller `FUN_008aaf60` |
| 2 | Null scrollbar still touches list | **Falsified** — first compare `[esi+0x700]==0` returns |
| 3 | Pages can be zero after success path | **Falsified** — clamp stores **1** when `pages < 1` |
| 4 | Always shows bar at full opacity | **Falsified** — if `vtbl+0xD0` false, show with **0.5f** (`0x3F000000`) |
| 5 | Thumb size is content/viewport ratio directly | **Falsified** — uses `1.0f / pages` with pages from line-step ceil formula |
| 6 | Many direct callers | **Falsified** — single code xref from `FUN_008aaf60` |
| 7 | ECX thiscall | **Falsified** — body is **ESI-this** (`[esi+0x700]`, `[esi+0x6e0]`) |
| 8 | Product name sealed | **Not supported** — inferred from offsets + caller |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Sync-after-fill role | **High** | Mis-order UI refresh |
| Hide vs multi-page branch | **High** | Stuck invisible/visible bar |
| Pages formula | **High** | Wrong thumb granularity |
| Metric noun labels (viewport/content) | **Med** | Doc wording only if CF preserved |
| Product vtbl names | **Low** | Naming |

---

## 3. Cross-check contract

```
SyncListScrollbar(panel*):  // ESI
  bar = panel[+0x700]; if !bar: return
  list = panel[+0x6e0]
  if !list || !list.metricsHost():
    bar.hide(0); return
  viewport = list.rangePair().second
  content  = list.queryContent(&tmp)   // tmp starts 1
  if content <= viewport:
    bar.hide(0); return
  lineStep = list.metricsHost()->[+0x7C]
  pages = (lineStep - viewport + content - 1) / lineStep
  if pages < 1: pages = 1
  panel[+0x704] = pages
  if !bar.isVisible(): bar.show(1, 0.5f)
  bar.setThumb(1.0f / pages)
  bar.setPos(list.scrollMetric(0) / (float)pages)
```

Clean must **not** invent list population, string mission titles, or network.

---

## 4. Surviving contract for AutoCore

```c
struct MissionUiPanel {
  UiList*      list;       // +0x6E0
  UiScrollBar* scrollbar;  // +0x700
  int          pageCount;  // +0x704  (min 1 when active)
};

// pages = ceil_div(content - viewport, lineStep)
//        == (content - viewport + lineStep - 1) / lineStep
//        implemented as (lineStep - viewport + content - 1) / lineStep
```

Server has no dependency. Client journal/list UI ports must recompute bar after list rebuild (same call order as `FUN_008aaf60` → this).

---

## 5. Gaps (aligned with A)

1. Product names.  
2. Vtbl English.  
3. Caller dual not OWN.  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
