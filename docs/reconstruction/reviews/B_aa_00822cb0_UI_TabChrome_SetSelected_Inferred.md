# Review B (skeptical / adversarial): `aa_00822cb0` UI_TabChrome_SetSelected_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00822cb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-002) |
| **Counterpart** | `reviews/A_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ABI/CF/select-chrome; **falsify** inventory-wire / thiscall / pure-resize / sole-caller / Runtime Confirmed claims |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Inventory transfer / grab-drop packet sender | Body is only child style + visibility + optional size; **no** C2S opcodes / send helpers | **Falsified** as inventory wire |
| 2 | `__thiscall` ECX = widget | Entry uses **ESI** as widget; ECX loaded from `+0x818`/`+0x814` for child vcalls; call sites `MOV ESI, tab` | **Falsified** |
| 3 | `unaff_ESI` / `unaff_BL` are decompiler garbage | Call sites: `MOV ESI, [host+tabSlot]; MOV BL,1` / `XOR BL,BL; PUSH force; CALL 00822cb0` | **Falsified** — real formals |
| 4 | No stack formal / plain `RET` | Epilogue `ADD ESP,0x18; RET 4` (`C2 04 00`); force at `[ESP+0x1c]` after frame | **Falsified** as zero-stack |
| 5 | Pure size-only helper | Always may restyle childA and toggle childB before size; size arm is conditional on prior state | **Falsified** as pure-resize |
| 6 | "Expand" means grow geometry | Select (BL=1) **subtracts** deltas; unselect (BL=0) **adds** deltas | **Falsified** naive expand=grow |
| 7 | Sole caller is parent `00888b00` | **45** xrefs / **10** named callers (`00888b00`, `00889410`, `00889fb0`, `00887780`, …) | **Falsified** as sole |
| 8 | Same as `FUN_00756c90` (list detach/move) | Different ABI (ESI+BL+force vs EDI), different body; parent pairs them | **Falsified** as merge |
| 9 | Product name Confirmed | No RTTI on VA; `_Inferred` required | **Open** |
| 10 | Runtime Confirmed | No Launcher this pass | **Open** — **never** claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI widget + BL selected + force stack + RET 4 | **High** | Wrong call sites / stack cleanup |
| selected `@+0x4FC`, scale `@+0x4FD` | **High** | Wrong layout port |
| children `@+0x814/+0x818`, deltas `@+0x80C/+0x810` | **High** | Wrong chrome fields |
| Select shrinks / unselect grows by deltas | **High** | Inverted geometry |
| Child vtbl product English | **Tentative** | Misnamed style/show APIs |
| Host/tab class English name | **Open** | Mis-attributed UI |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + siblings

- Frozen raw 2026-07-23 CF ≡ live 2026-08-05 decompile + disasm (force gate, BL arms, store).
- Parent dual R11-031 residual: "ESI+BL expand/collapse" — sealed here as **selected chrome** (BL=1 active tab, BL=0 inactive); geometry shrinks when selected.
- Sibling dual R12-003 `FUN_00756c90`: EDI move-to-front after **this** unit with BL=0 — complementary, not duplicate.
- Sibling tab hosts `00889410` / `00889fb0` / `00887780` use the same ESI/BL/force pattern — multi-host helper, not Cs2d-only.
- Decompiler marks callees empty (all vcalls) — disasm seals vtbl ordinals; do not invent named FUN callees.

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `UI_TabChrome_SetSelected_Inferred` | **Accept INFERRED** — selected state store + dual chrome arms + parent call pattern |
| `UI_TabChrome_ExpandCollapse_Inferred` | **Accept synonym** only; "expand" is parent jargon, not geometric grow |
| `UI_Widget_SetSize_Inferred` | **Reject** as canonical — misses style/visibility arms |
| `Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00822cb0` | **Reject** as canonical — true multi-hop ancestry but under-specific |
| `Client_SendInventory*` | **Reject** — no wire |
| `FUN_00822cb0` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
// custom ABI: ESI=widget*; BL=selected(0/1); force@stack; RET 4
if (!force && widget[+0x4FC] == selected) return
// restyle optional childA@+0x818 (scale full or >>1 from +0x4FD)
// show/hide optional childB@+0x814 via vtbl+0x3C8 (flag=selected)
// if prior state differed: SetSize(GetSize ± deltas +0x80C/+0x810)
//   select: size - deltas; unselect: size + deltas
widget[+0x4FC] = selected
// not inventory transfer; not group list move (that is 00756c90)
```

**Verdict:** **accept-with-gaps**.
