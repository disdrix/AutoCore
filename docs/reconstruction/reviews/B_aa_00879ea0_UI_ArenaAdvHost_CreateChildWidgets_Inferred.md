# Review B (adversarial): `aa_00879ea0` UI_ArenaAdvHost_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00879ea0` |
| **VA** | `0x00879ea0`–`0x0087b38a` inclusive (**5355 B** / `0x14EB`) |
| **Canonical name** | `UI_ArenaAdvHost_CreateChildWidgets_Inferred` |
| **Ghidra name** | `FUN_00879ea0` |
| **Review date** | `2026-08-05` (R13-011 dual seal) |
| **Reviewer role** | Adversarial / claim-falsification (OWN-ONLY R13-011) |
| **Counterpart** | `reviews/A_aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer |
| **Evidence pass** | Same live Ghidra set as A; assembly authority on conflicts |
| **Verdict** | **accept-with-gaps** |

---

## Claims tested

| # | Claim | Result | Evidence |
|---|---|---|---|
| 1 | cdecl / stdcall with stack host | **FALSIFIED** | `MOV EBP,ECX`; exit `C3` not `C2 xx` |
| 2 | pure `__fastcall` with used EDX formal | **FALSIFIED as product ABI** | ECX only; no EDX formal; Ghidra `__fastcall` is incomplete display |
| 3 | RET 4 / stack object arg | **FALSIFIED** | no stack args; `RET`/`C3` |
| 4 | Direct CALL callers | **FALSIFIED** | analyze callers empty; sole xref DATA `0x00a59500` |
| 5 | This is inventory grab/drop/transfer wire | **FALSIFIED** | body is pure UI new/XML/attach; no packet opcodes; no inventory grid calls |
| 6 | This is only the combo-boxes pane | **FALSIFIED** | plate string `…bg_combo_boxes` is **one** of 56 children; full host CreateChildWidgets |
| 7 | Same unit as CDlgArenaPrefs CreateChildWidgets | **FALSIFIED** | different VA `0x008747e0`, prefs XML family `i_d_arena_prefs_*`, different vtbl |
| 8 | Only builds three tabs | **FALSIFIED** | 56 XML paths; buttons/edits/radios/combos/dividers/labels |
| 9 | Parent `00756c90` is the outer caller of this VA | **FALSIFIED for CALL graph** | this unit **calls** dualed `00756c90` (×2) after inactive tabs; partition parent is score ancestry, not structural outer |
| 10 | Product class name Confirmed / Runtime Confirmed | **OPEN** | no RTTI sealed; no Launcher; name stays `_Inferred`; Terminal false |

---

## Odd behavior preserved

1. **Tab asymmetry:** console (`+0x630`) and tournament (`+0x634`) pair `FUN_00822cb0` + `FUN_00756c90`; advanced (`+0x638`) pairs `FUN_00822cb0` + child `vtbl+0x94` **without** `00756c90` — default-selected advanced tab path.
2. Close button stored at **`host+0x504`** (dword index `0x141`) while the rest of the new tree sits at **`+0x560`…`+0x638`** — interleaved with pre-existing host layout slots.
3. Password edit sets charset via `vtbl+0x3ac(&DAT_00a1419b)`, max len **8**, and byte flag at child **`+0x48c`**; level/fee/value edits use max len **3** and flag **`+0x48b`**.
4. Ladder/practice radios: both get group-related `vtbl+0x3b4(1)` and zero at child `+0x498`; then practice `vtbl+0xd4(0)` and ladder `vtbl+0x3c8(1,1)` — mutual-exclude setup order is product-specific.
5. Tail always runs residual `FUN_00879240` then host `vtbl+0x448` and `vtbl+0x34c` even if some `operator_new` returned null (null-tolerant stores of 0).

---

## Name challenge

- Reject plate alias `UI_arena_adv_bg_combo_boxes` as function name (single XML child, not host role).
- Reject inventing unconfirmed `CDlgArenaAdv_*` demangle without RTTI (prefs dual used `CDlgArenaPrefs_*` with separate sealed plate; this unit lacks that seal).
- Accept role family **CreateChildWidgets** (virtual DATA dispatch + mass XML tree + dualed craft/trade/prefs siblings).
- Accept host family **ArenaAdv** from sealed `i_d_arena_adv_*` path prefix.
- Final: `UI_ArenaAdvHost_CreateChildWidgets_Inferred`.

---

## Verdict

**accept-with-gaps** — adversarial pass falsifies wrong ABI/role/inventory-wire merges; residual English/RTTI/runtime remain open. Agrees with Path A.
