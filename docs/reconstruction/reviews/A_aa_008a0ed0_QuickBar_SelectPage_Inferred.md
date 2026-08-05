# Review A (reconstruction fidelity): `aa_008a0ed0` QuickBar_SelectPage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0ed0` |
| **VA** | `0x008a0ed0` |
| **Canonical name** | `QuickBar_SelectPage_Inferred` (leave global FUN until registry rename) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008a0ed0_QuickBar_SelectPage_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Select a QuickBar **page** (index 0..9) on the QB dialog host. Stores the page at host dword index `0x143` (`+0x50c`), rebinds the 10 column slot widgets for that page, restores (or auto-picks) the remembered column selection, clears hover residual, and triggers host chrome refresh. **Not** slot activate / cast.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008a0ed0_FUN_008a0ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_008a0ed0_FUN_008a0ed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_SelectPage_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_008a0ed0_QuickBar_SelectPage_Inferred.md` |
| Parent dual | `reviews/A_aa_009436c0_Client_QuickBar_ActivateSlot.md` (mode-1 → this) |
| Callees (Ghidra) | `FUN_008a0e10`, `FUN_00826780`, `FUN_008a0210` |
| Callers | `Client_QuickBar_ActivateSlot` (mode 1), `FUN_008a0fb0` (page±delta), `FUN_008a0fe0` (show refresh), `FUN_009114f0` (bind next page), `Client_SkillTrainUiRequest_INFERRED` (post auto-map refresh) |
| Scratch | `tmp/a_008a0ed0.md` |

---

## 3. Signature / ABI

```c
// ECX = CDlgQuickBar* host (RTTI appears on activate path via FUN_00826780)
// EAX = page index (int); only accepted when 0 <= page <= 9
void __fastcall QuickBar_SelectPage_Inferred(int *host /*ECX*/, /* page in EAX */);
```

Decompiler surface: `void __fastcall FUN_008a0ed0(int *param_1)` with phantom `in_EAX`.

| Claim | Confidence | Notes |
|---|---|---|
| Host in ECX (`param_1`) | **High** | thiscall-family; field writes match CDlgQuickBar layout |
| Page in EAX | **High** | `in_EAX` gate + store; callers compute page into EAX (decomp drops handoff) |
| Page clamp **[0, 9]** inclusive | **High** | `(-1 < in_EAX) && (in_EAX < 10)`; else no-op return |
| Not a stack formal for page | **High** | Fastcall/register ABI; no stack push of page in body |

---

## 4. Control flow (sealed)

```
if page ∉ [0,9]: return

host[0x143] = page                          // +0x50c current page
prevCol = DAT_00d1da38[page]                // per-page remembered column (i32 × 10)

for colWidget in host[399 .. 408]:          // +0x63c .. +0x660; 10 ptrs
  if colWidget:
    colWidget+0x504 = page                  // stamp page onto each column widget
    if colWidget+0x4fc != 0:                // was "selected/active"
      FUN_00826780(this=colWidget, 0)       // deactivate (clear highlight; may clear DAT_00d1da38)

FUN_008a0e10(host)                          // rebind 10 widgets from DAT_00d1da60[page*10+i]
host.vtbl[+0x448]()                         // host refresh (indirect)

if prevCol ∉ [0,9]
   OR host[399+prevCol] == 0
   OR (widget+0x550 & widget+0x554) == 0xffffffff:   // empty mask (COID-style)
  FUN_008a0210(1)                           // auto-select next valid column (direction +1)
else:
  FUN_00826780(this=widget, 1)              // restore selection on prevCol

if DAT_00d1a9fc >= 0:                       // residual hover/focus column index
  if host[399+DAT_00d1a9fc]:
    thatWidget.vtbl[+0x44c](0)              // clear hover chrome
  DAT_00d1a9fc = -1

host.vtbl[+0x34c]()                         // final paint/layout (indirect; decomp jumptable warning)
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = **page select**, not slot activate | **High** | Mode-1 early return in ActivateSlot; body never reads skill/item payloads |
| `host[0x143]` / `+0x50c` = current page | **High** | Store + ActivateSlot page resolve + SkillTrain auto-map page base |
| 10 column widgets at `host+399` (`+0x63c`) | **High** | Loop count 10; same base in `FUN_008a0210` / `FUN_008a0770` |
| `widget+0x504` = page stamp | **High** | Written here; read by `FUN_00826780` for `DAT_00d1da38` index |
| `widget+0x4fc` = selected/active flag | **High** | Set/cleared by `FUN_00826780`; gate for deactivate loop |
| `DAT_00d1da38[page]` = last selected **column** on that page | **High** | Written on activate in `FUN_00826780` as `widget+0x500`; cleared to -1 on deactivate |
| Empty gate `(+0x550 & +0x554) == -1` | **High** CF | Same dual-dword empty idiom as char QB item COIDs |
| `FUN_008a0e10` rebinds page contents | **High** role | Uses `page*10+col` into `DAT_00d1da60` type table (1 skill / 2 item / 5 macro / else clear) |
| `FUN_008a0210(1)` = pick next valid column | **High** role | Sibling of direction-0; RTTI `CDlgQuickBar` on fallthrough |
| `FUN_00826780(0/1)` = deactivate / activate column | **High** | thiscall; highlight + `DAT_00d1da38` update |
| `DAT_00d1a9fc` hover column residual | **Probable** | Cleared after optional `vtbl+0x44c(0)`; product name open |
| Host is `CDlgQuickBar` | **Probable** | RTTI cast on activate path; global `DAT_00d1b8f0` used as host in callers |
| Product name `SelectPage` | **Inferred** | Behavior sealed; no UI string in unit |

---

## 6. Callers (evidence)

| Caller | VA | How page reaches EAX (role) |
|---|---|---|
| `Client_QuickBar_ActivateSlot` | `0x009436c0` | **Mode 1** (shift-QB): early call; formal slot used as page index (PollBoundActions `(i,1,-1)`) |
| `FUN_008a0fb0` | `0x008a0fb0` | Page delta: `host+0x50c + delta` (both arms call SelectPage; exact clamp residual) |
| `FUN_008a0fe0` | `0x008a0fe0` | On show/refresh when visible (`vtbl+0x3d8`); page already in host or EAX residual |
| `FUN_009114f0` | `0x009114f0` | Bind `0x12` → next page (`host[0x143]+1` style); decomp loses EAX math |
| `Client_SkillTrainUiRequest_INFERRED` | `0x00897170` | After first-rank auto-map onto current page: refresh UI (`FUN_008a0ed0` @ `0x008972ad`) |

Xref sites (Ghidra): `008972ad`, `00943789`, `0091172f`, `00911741`, `008a1020`, `008a0fc1`, `008a0fd0`.

---

## 7. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Page gate [0,9] | **Yes** |
| Store page + load prevCol | **Yes** |
| 10-widget stamp/deactivate loop | **Yes** |
| Rebind + host vtbl+0x448 | **Yes** |
| Restore vs auto-pick branch | **Yes** |
| Hover clear + host vtbl+0x34c | **Yes** |
| No invented cast/network | **Yes** |

---

## 8. Gaps / open questions

1. Exact EAX setup at each caller (decomp drops register handoff; especially `FUN_008a0fb0` negative-delta arm and `FUN_008a0fe0` show path).
2. Product symbols for `FUN_008a0e10` (rebind), `FUN_00826780` (select column), `FUN_008a0210` (cycle column), `DAT_00d1da38` / `DAT_00d1a9fc`.
3. Semantic of `widget+0x550/+0x554` beyond empty dual-dword (item COID pair vs skill sentinel).
4. `vtbl+0x448` / `+0x34c` / `+0x44c` method names (Scaleform/gfx chrome).
5. Runtime: shift-QB page switch + page-button delta capture.
6. Bit-for-bit / differential open.

**Verdict:** Page-select CF and layout offsets sealed High. Callee product names + caller EAX framing residual. **accept-with-gaps.**
