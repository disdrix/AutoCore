# Review B (skeptical / adversarial): `aa_00878300` UI_ArenaConsole_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00878300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-010) |
| **Counterpart** | `reviews/A_aa_00878300_UI_ArenaConsole_CreateChildWidgets_Inferred.md` |
| **Live tools** | Same Ghidra decompile + complete analysis + disassemble_function + xrefs + list_strings + read_memory as A |
| **Verdict** | **accept-with-gaps** on ABI/CF/CreateChildWidgets/XML map/tab policy; **falsify** tournament-only / inventory-wire / stack-arg / Runtime Confirmed claims |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function only builds the **tournament tab** | Disasm builds fill/fx/title/logos/help/news/buttons/**three** tabs/mini; tournament is one of 19 children | **Falsified** as tournament-only; plate name under-specific |
| 2 | Inventory transfer / grab-drop / arena **C2S** sender | Callees are UI factory + dualed tab chrome helpers only; no bitstream/sector send | **Falsified** as inventory wire |
| 3 | Arena match rules / host-now net commit | Body only constructs widgets; button **handlers** live elsewhere (cmd ids only stamped) | **Falsified** as match engine |
| 4 | `__stdcall` / stack host formal / `RET n` | Entry `MOV EBP,ECX`; epilogue plain `RET` (`C3`); no stack formals | **Falsified** |
| 5 | Multiple direct CALL callers | `get_function_callers` empty; sole xref **DATA** `0x00a5a640` | **Falsified** as call-graph leaf |
| 6 | Decompiler shows complete XML inventory | Live decompile inlines only ~5 paths; **all** paths recovered via disasm PUSH + `list_strings` | **Falsified** as decompile-complete |
| 7 | `UI_arena_console_tab_tournament` product Confirmed | Plate string heuristic only; no RTTI on VA | **Open** — require `_Inferred` CreateChildWidgets name |
| 8 | Default selected tab is tournament | Console tab gets `MOV BL,1` + SetSelected; tournament/advanced get `XOR BL,BL` | **Falsified** |
| 9 | MoveToFront means detach/remove | Dualed parent `00756c90` is erase+InsertN front; does not clear `+0x88` | **Falsified** as detach (use dualed contract) |
| 10 | Runtime Confirmed / bit-exact sealed | No Launcher this pass | **Open** — **never** claimed |
| 11 | Size threshold is 0.0 / epsilon | `read_memory` `DAT_00aaac10` = **-99998.0f** | **Falsified** as zero threshold |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX host + plain RET void | **High** | Wrong call ABI / stack cleanup |
| Virtual DATA +0x43C CreateChildWidgets role | **High** | Wrong lifecycle hook |
| Full XML domain under `i_d_arena_console_*` | **High** | Missing assets / wrong dialog |
| Slot/cmd table (19 children, ids 0x9c40–0x9c47) | **High** | Wrong click routing / layout |
| Console default-selected; other tabs collapsed+front | **High** | Wrong initial tab UX |
| No C2S in body | **High** | False intercept hooks |
| Product English class/method name | **Open** | Mis-attributed CDlg* |
| Residual helpers `877790`/`8778e0`/`877c50`/`792600` | **Tentative** | Unknown post-build side effects |
| Player global + gate byte meaning | **Probable / Open** | Wrong conditional path story |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + siblings

- Frozen raw 2026-07-23 CF ≡ live 2026-08-05 decompile; **disasm seals** path/id immediates decompiler drops.
- Peer dualed CreateChildWidgets: `CDlgArenaPrefs` (`008747e0`), `UI_CraftHost` (`008e6b50`), trade/charsheet family — same factory pattern, different XML domain.
- Host ctor plate `UI_arena_console` @ `00878c70` installs `PTR_FUN_00a5a204` — consistent vtbl home for this slot.
- Dualed tab helpers used correctly:
  - `00822cb0` ESI=tab, BL state, stack force 1
  - `00756c90` EDI=tab (tournament/advanced only)
- Sibling residual R13-009/011/012 share parent `00756c90` — same tab-chrome family, different hosts; do not merge names.
- Partition system **inventory-transfer** is residual queue membership (UI host proximity), **not** proof of inventory packet role for this unit.

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `UI_ArenaConsole_CreateChildWidgets_Inferred` | **Accept INFERRED** — full tree + CreateChildWidgets family + vtbl virtual |
| `UI_arena_console_tab_tournament` | **Reject as canonical** — first-string plate; under-specific |
| `CDlgArenaConsole_CreateChildWidgets` without `_Inferred` | **Reject Confirmed** — RTTI/demangle open |
| `Client_SendInventory*` / `Client_RecvArena*` | **Reject** — no wire |
| `FUN_00878300` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
// Client UI only — call when Arena Console dialog builds children.
// Do not treat as arena host/match commit or inventory transfer.
void UI_ArenaConsole_CreateChildWidgets_Inferred(void* host /* ECX */);

// Assets: i_d_arena/i_d_arena_console_*.xml
// Tabs: console (selected), tournament + advanced (collapsed + move-to-front)
// Cmd ids: close 0x9c40, instant 0x9c41, my_stats 0x9c42,
//          tab_console 0x9c43, tab_tournament 0x9c44, tab_advanced 0x9c45,
//          news 0x9c46, mini_cancel 0x9c47
// Size sentinel: host size slots ≤ -99998.f → normalize with 1200/1600 scale
// Vtbl slot: host vtbl[+0x43C] @ 0x00a5a640
```

**Verdict:** **accept-with-gaps**. Terminal **false**. Runtime Confirmed **not claimed**.
