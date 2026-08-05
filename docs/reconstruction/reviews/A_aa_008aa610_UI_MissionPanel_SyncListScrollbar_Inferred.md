# Review A (reconstruction fidelity): `aa_008aa610` UI_MissionPanel_SyncListScrollbar_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa610` |
| **VA** | `0x008aa610`–`0x008aa758` exclusive |
| **Body size** | **328** B (`0x148`) |
| **Canonical name** | `UI_MissionPanel_SyncListScrollbar_Inferred` |
| **Ghidra symbol** | `FUN_008aa610` |
| **Review date** | `2026-08-04` (WQ7R-B OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md` |
| **System** | client UI / mission panel list + scrollbar |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `read_memory`, callers (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Given mission UI panel `this` (**ESI**): if scrollbar widget `+0x700` is present, sync it from list widget `+0x6e0`. When list metrics are unavailable, hide/disable the bar (`vtbl+0x04`). When content fits in the viewport, hide. Otherwise compute **page count** into `+0x704` (min 1), ensure the bar is shown (alpha **0.5** if currently hidden), set thumb size `1/pages` and normalized position from list scroll query.

UI layout helper only; no mission data edits.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008aa610_FUN_008aa610.md` (+ WQ7R-B append) |
| Annotated | `docs/reconstruction/raw/aa_008aa610_FUN_008aa610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionPanel_SyncListScrollbar_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_008aa610.cpp` |
| Function record | `docs/reconstruction/functions/aa_008aa610_UI_MissionPanel_SyncListScrollbar_Inferred.md` |
| Live decompile | CF ≡ raw |
| Live body bytes | entry, hide branch, page `idiv`, thumb `divss g_flOne` |
| Parent | `FUN_008aaf60` calls this after list `+0x6e0` rebuild (sole code caller) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (key sites)

### Entry / null bar

```
83 ec 18
83 be 00 07 00 00 00     ; cmp [esi+0x700], 0
74 ...                   ; ret
8b 8e e0 06 00 00        ; list = [esi+0x6e0]
85 c9 0f 84 ...          ; no list → hide path
ff 90 b8 01 00 00        ; list vtbl+0x1B8 metrics host
```

### Viewport vs content hide

```
6a 01 8d 44 24 10 50
ff 92 40 01 00 00        ; list vtbl+0x140 → pair
8b 08 8b 78 04           ; ecx=pair[0], edi=viewport metric pair[1]
...
ff 92 04 02 00 00        ; list vtbl+0x204(&contentLocal)  ; local starts 1
39 7c 24 08              ; cmp content, viewport (edi)
7f 12                    ; jg pages
6a 00 ff 52 04           ; bar vtbl+0x04(0) hide
5f 83 c4 18 c3
```

### Pages + clamp

```
; pages = (lineStep - viewport + content - 1) / lineStep
; lineStep = *(*vtbl+0x1B8() + 0x7C)
8d 44 02 ff 99 f7 f9
89 86 04 07 00 00        ; [esi+0x704] = pages
; if pages < 1 → store 1
```

### Show / thumb / position

```
ff 90 d0 00 00 00        ; bar vtbl+0xD0 visible?
; if false: vtbl+0xFC(1, 0x3F000000)  ; 0.5f
f3 0f 10 0d a0 f2 a0 00  ; movss xmm1, g_flOne
f3 0f 5e c8              ; divss xmm1, pages
ff 92 60 04 00 00        ; bar vtbl+0x460(1/pages)
6a 00 ff 92 18 02 00 00  ; list vtbl+0x218(0) → scroll metric
; bar vtbl+0x454( metric / pages )
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body 328 B exclusive end `0x008aa758` | **pass** |
| ESI this; bare ret | **pass** |
| Offsets `+0x6E0` list / `+0x700` bar / `+0x704` pages | **pass** |
| Hide when no metrics or content≤viewport | **pass** |
| Page ceil formula via `lineStep@+0x7C` | **pass** |
| `0x3F000000` = 0.5f show path | **pass** |
| `g_flOne / pages` thumb | **pass** |
| Sole caller `FUN_008aaf60` | **pass** |
| Product vtbl English names | **gap** |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = list→scrollbar sync after journal/list fill | **High** | sole caller chain + offsets |
| Page count formula | **High** | bytes + decomp agree |
| Hide / show / thumb / pos order | **High** | |
| Which metric is viewport vs content | **High** CF; **Med** product labels | pair[1] vs +0x204 out |
| Product C++ name | **Inferred** | |

---

## 6. Gaps

1. Product method / scrollbar class English.  
2. Exact product names for list vtbl `+0x140/+0x1B8/+0x204/+0x218` and bar `+0x04/+0xD0/+0xFC/+0x454/+0x460`.  
3. Dual of caller `FUN_008aaf60` (WQ residual sibling, not OWN).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
