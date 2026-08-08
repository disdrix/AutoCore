# Review B (skeptical / adversarial): `aa_0086b9b0` UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086b9b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-009) |
| **Counterpart** | `reviews/A_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ABI/CF/builder role; **falsify** mini-label-only / inventory-wire / non-virtual-only / Runtime Confirmed claims |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Inventory transfer / grab-drop packet sender | Body is UI new/ctor/attach/XML + tab chrome helpers; **no** C2S opcodes or send paths | **Falsified** as inventory wire |
| 2 | Name = `UI_arena_tournament_schedule_mini_label` only | Builds full schedule tree (list, buttons, rewards, **3 tabs**, close, mini cluster). Mini label is **one** late plate | **Falsified** as sole role |
| 3 | Fastcall / non-thiscall / stack formals | Entry `MOV EBP,ECX`; epilogue plain `RET`; no stack formals | **Falsified** |
| 4 | Has direct CALL callers | `get_function_callers` empty; sole xref DATA `0x00a5ed20` | **Falsified** as direct-call graph |
| 5 | Not related to dualed parent `00756c90` | Two explicit call sites after tab unselect | **Falsified** — is caller of parent residual |
| 6 | All three tabs selected | Console/advanced `XOR BL,BL`; only tournament `MOV BL,1` | **Falsified** |
| 7 | Move-to-front on selected tournament tab | Move only after BL=0 paths on console/advanced | **Falsified** |
| 8 | Product name Confirmed | Plate paths only; no RTTI on VA | **Open** — `_Inferred` required |
| 9 | Runtime Confirmed | No Launcher this pass | **Open** — **never** claimed |
| 10 | `FUN_0086a900(-1,-1)` is inventory join | Residual helper; args are `-1,-1` only; no packet builder here | **Open** semantics; **falsify** as proven inventory wire |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX thiscall host + plain RET | **High** | Wrong call sites / stack cleanup |
| Virtual method via vtbl+0x43C | **High** | Miss factory/ctor install path |
| Mass child create/attach/xml CF | **High** | Incomplete UI port |
| Tab select/move policy | **High** | Wrong default tab UX |
| Plate family = tournament schedule | **High** | Mis-attributed dialog |
| Product host class English name | **Open** | Misnamed type in port |
| Tail helper semantics | **Tentative** | Wrong post-build refresh |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + siblings

- Frozen raw 2026-07-23 CF ≡ live 2026-08-05 decompile + full `disassemble_function`.
- Parent dual R12-003 listed this VA among callers of move-to-front — matches sealed sites.
- Parent dual R12-002 tab chrome — call ABI `ESI`+`BL`+force matches sites (`MOV ESI,tab; PUSH 1; XOR/MOV BL; CALL`).
- Ctor sibling `FUN_0086cd10` (`UI_arena_tournament_schedule`) installs `PTR_FUN_00a5e8e4` and seeds same `+0x4FC/+0x500` pattern — consistent host class.
- Dualed `NDUIButton_Ctor` / `NDUIFxPanel_Ctor` sizes match `0x4CC` / `0x4BC` sites.
- Partition system inventory-transfer is **ledger bucket** for residual UI chrome under parent helpers — **not** proof of inventory packets.

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred` | **Accept INFERRED** — full child-tree builder + plate family + virtual slot |
| `UI_arena_tournament_schedule_mini_label` | **Reject** as canonical — under-specific plate alias |
| `Client_SendInventory*` | **Reject** — no wire |
| `UI_Cs2dTabs_*` | **Reject** — different host; only reuses tab chrome helpers |
| `FUN_0086b9b0` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
// __thiscall ECX=host*
// virtual method (vtbl +0x43C on schedule dialog class)
init host flags (+0x4FC=0xF, +0x500=1, +0x528=0, +0xC5=0)
base host layout vcalls + FUN_00792600
for each child plate:
  new+ctor → host.slot → attach(vtbl+0xA8) → LoadXml(vtbl+0x28) [+id]
tabs:
  console@+0x630:    SetSelected(0,force=1); MoveToFront
  tournament@+0x634: SetSelected(1,force=1); vtbl+0x94
  advanced@+0x638:   SetSelected(0,force=1); MoveToFront
close + mini cluster (+ optional size normalize)
finalize vcalls + FUN_0086b370 + FUN_0086a900(-1,-1) + optional FUN_0086b3c0
// not inventory transfer packets
```

**Verdict:** **accept-with-gaps**.
