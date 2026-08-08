
# Review B (skeptical / adversarial): `aa_00887780` UI_TabsSo_SetActiveTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00887780` |
| **VA** | `0x00887780` |
| **Canonical name** | `UI_TabsSo_SetActiveTab_Inferred` (**Inferred**) |
| **Review date** | `2026-08-05` (R13-012) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00887780_UI_TabsSo_SetActiveTab_Inferred.md` |
| **System** | inventory-transfer / `i_d_tabs_so_*` social dialog tab switch |
| **Live tools** | Independent decompile + `disassemble_function` + `read_memory` + call-site context + ctor disasm + `list_strings` |
| **Verdict** | **accept-with-gaps** — accept CF/ABI/tab matrix/9 xrefs; reject thiscall / void-only-stack / param2-as-tabIndex / TabsC-merge / inventory-wire / sole-caller / scaffold-product / Runtime Confirmed claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Ghidra signature `void FUN_*(int*, undefined4)` is complete ABI | **Falsified** — entry `MOV ESI,EAX`; 9 call sites preload EAX with 0/1/2/current; **tabIndex is a third formal in EAX** |
| 2 | thiscall / ECX = dialog | **Falsified** — entry loads dialog from **stack** (`MOV EBP,[ESP+8]` after `PUSH EBP`); no `MOV reg,ECX` of this |
| 3 | `in_EAX` is leftover garbage / return of prior call | **Falsified** — call sites explicitly `XOR EAX,EAX` / `MOV EAX,1` / `MOV EAX,2` / `MOV EAX,[EDI+0x534]` immediately before CALL |
| 4 | `param_2` is the tab index | **Falsified** — `param_2` is force byte (`TEST BL,BL`); tab index is ESI/EAX; force 0/1 both observed with varying EAX |
| 5 | Same unit as `UI_TabsC_SetActiveTab` (`00889410`) / merge names | **Falsified** — different host global (`DAT_00d1b878` vs `DAT_00d1b874`), different active slot (`+0x534` vs `+0x530`), different XML domain (`i_d_tabs_so_*` vs `i_d_tabs_c_*`), linear vs swapped pane map |
| 6 | Tab 2 is friends / linear name order wrong | **Falsified** — ctor stores friends@`+0x518` cmd `0x9c42`, clan@`+0x51c` cmd `0x9c43`, enemies@`+0x520` cmd `0x9c44`; matrix selects matching panes |
| 7 | Scaffold `Named_CalleeOf_Client_Input_PollBoundActions_*` is product | **Rejected** — parent-seed chain name; not plate / not PDB |
| 8 | This is a C2S inventory / social packet builder | **Falsified** — pure UI show/hide + tab chrome; no opcode / no grid place |
| 9 | `FUN_00822cb0` takes only force (no widget) | **Falsified** — every call site sets **ESI=widget** and **BL=selected** before CALL |
| 10 | Mode 2 falls through shared tail | **Falsified** — early `RET 8` @ `0x008878b3` after selecting enemies |
| 11 | Sole caller is CreateChildWidgets `0x00887c70` | **Falsified** — **9** xrefs: ctor + 3 input poll + 5 residual cmd/toggle sites |
| 12 | Active index lives at `+0x530` (copy TabsC) | **Falsified** — machine `CMP/MOV [EBP+0x534]`; dword index `[0x14d]` |
| 13 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hybrid ABI EAX+2 stack+RET 8 | **High** | Wrong calling convention on port |
| 3-tab matrix friends/clan/enemies | **High** | Wrong pane shown |
| Layout +0x50c..+0x534 | **High** | Corrupt dialog object |
| force / same-tab gate | **High** | Spurious / missing switches |
| 00822cb0 / 00756c90 register ABI | **High** | Silent no-op helpers |
| XML string → tab button map | **High** | Wrong English labels only if swapped — matrix matches ctor |
| Product method English | **None** | Overclaim name |
| Official vtbl method names | **Low** | Wrong UI API labels on port |
| Content-pane product types | **Low** | Adjacent field misuse |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + siblings

- Frozen raw 2026-07-23 CF ≡ live 2026-08-05 decompile; **disasm seals** ESI/EDI/BL pairing decompiler drops.
- Peer dualed SetActiveTab: `UI_TabsC_SetActiveTab_Inferred` (`00889410`) — same hybrid ABI family, **do not merge**.
- Peer dualed helpers (already sealed R12): `00822cb0` SetSelected; `00756c90` MoveToFront — register ABI reused correctly.
- Host CreateChildWidgets plate `UI_tabs_so_tab_enemies` @ `00887c70` loads full `i_d_tabs_so_2d_*` tree then force-calls this VA — under-specific plate for ctor, **not** this setter.
- Partition system **inventory-transfer** is residual queue membership (UI host proximity to inventory chrome helpers), **not** proof of inventory packet role for this unit.

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `UI_TabsSo_SetActiveTab_Inferred` | **Accept INFERRED** — SO XML domain + 3-tab setter family + hybrid ABI twin of TabsC |
| `UI_tabs_so_tab_enemies` | **Reject as canonical** — single-tab plate for ctor |
| `CDlgTabsSo_SetActiveTab` without `_Inferred` | **Reject Confirmed** — RTTI/demangle open |
| `Client_SendInventory*` / `Client_RecvSocial*` | **Reject** — no wire |
| Merge with `UI_TabsC_SetActiveTab_Inferred` | **Reject** — different host/layout/XML |
| `FUN_00887780` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
// Client UI only — call when i_d_tabs_so dialog switches active tab.
// Do not treat as inventory transfer or social C2S.
// hybrid __usercall: EAX=tabIndex, stack dialog* + force, RET 8, void
void UI_TabsSo_SetActiveTab_Inferred(
    int tabIndex /* @EAX */,
    int *dialog  /* stack+4 */,
    char force   /* stack+8 */);

// Host global: DAT_00d1b878
// Active: dialog+0x534
// Tabs: 0 friends (+0x50c/+0x518), 1 clan (+0x510/+0x51c), 2 enemies (+0x514/+0x520)
// XML: i_d_tabs_so_2d_tab_friends/clan/enemies.xml
// Cmd ids (ctor): friends 0x9c42, clan 0x9c43, enemies 0x9c44, close 0x9c40
// Helpers: 00822cb0 ESI=widget BL=selected; 00756c90 EDI=widget
```

**Verdict:** **accept-with-gaps**. Terminal **false**. Runtime Confirmed **not claimed**.
