# Review A (reconstruction fidelity): `aa_0086b9b0` UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086b9b0` |
| **VA** | `0x0086b9b0` |
| **Canonical name** | `UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred` |
| **Review date** | `2026-08-05` (R13-009 dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md` |
| **System** | inventory-transfer (UI arena tournament-schedule chrome builder) |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `disassemble_function`, `read_memory`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **create-child-widgets** method for the Arena Tournament Schedule dialog host: initialize host flags, mass-allocate/construct/attach/XML-load the schedule UI tree (list chrome, buttons, reward/item rows, three tabs, close + mini status), apply tab selected/move-to-front policy via dualed helpers, then finalize with host vcalls and residual refresh helpers.

Partition residual under dualed parent helpers `FUN_00756c90` / `FUN_00822cb0` (this unit is a **caller** of both).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x0086b9b0)` 2026-08-05 ≡ frozen raw CF |
| Body / epilogue | `get_function_by_address` body `0086b9b0`–`0086cc81`; `disassemble_function` + `read_memory` epilogue plain `RET` |
| ABI | entry `MOV EBP,ECX`; no stack formals; SEH + `ADD ESP,0x24; RET` |
| Vtbl dispatch | DATA xref `0x00a5ed20`; slot `0x43C` on `PTR_FUN_00a5e8e4` (ctor `FUN_0086cd10`) |
| Tab sites | disasm: `+0x630` unselect+move; `+0x634` select; `+0x638` unselect+move |
| Dualed callees | `FUN_00822cb0` / `FUN_00756c90` sealed R12 |
| Strings | `list_strings` filter `i_d_arena_tournament_schedule` |
| Raw / annotated / clean / records | R13-009 trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of nested residual ctors / `FUN_0086b370` / `FUN_0086a900` / `FUN_0086b3c0` / other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw CF | **Confirmed** | mass new/ctor/attach/xml + tab policy + tail |
| `__thiscall` ECX = host | **Confirmed** | `MOV EBP,ECX` + all host stores via EBP |
| No stack args; plain `RET` | **Confirmed** | epilogue `C3` not `C2 xx` |
| Body 4818 B (`0x12D2`) | **Confirmed** | `0086b9b0`–`0086cc81` inclusive |
| Sole DATA xref / virtual method | **Confirmed** | `0x00a5ed20`; 0 CALL callers |
| Vtbl slot `+0x43C` on schedule class | **Confirmed** | `00a5ed20 - 00a5e8e4` |
| Child pattern new+ctor+attach(+0xA8)+LoadXml(+0x28) | **Confirmed** | repeated in disasm |
| Tab policy console/advanced unselect+move; tournament select | **Confirmed** | BL/EDI setup at call sites |
| Plate family = arena tournament schedule | **Confirmed** | dozens of `i_d_arena/i_d_arena_tournament_schedule_*` strings |
| Not inventory grab/drop/equip wire | **Confirmed** | no C2S opcodes / send helpers in body |
| Product host RTTI English name | **Open** | keep `_Inferred` |
| Exact product names of residual ctors | **Open** | only two dualed (`00864f20`, `0079c860`) |
| `FUN_0086b370` / `0086a900` / `0086b3c0` semantics | **Open** | residual |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Host flag init `+0x4FC/+0x500/+0x528/+0xC5` | **Yes** |
| Base host vcalls + `FUN_00792600` | **Yes** |
| Mass child create/attach/xml | **Yes** (disasm seals XML pushes decomp omitted) |
| Three tabs + SetSelected + MoveToFront policy | **Yes** |
| Mini cluster + optional size normalize | **Yes** |
| Tail finalize + conditional `FUN_0086b3c0` | **Yes** |
| No inventory C2S packets | **Yes** |

### Sealed CF sketch

```
UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred(host@ECX):
  init host flags
  host layout vcalls + FUN_00792600
  for each schedule plate child:
    new+ctor → host.slot → attach(+0xA8) → LoadXml(+0x28) [+id/extras]
  tab_console:    SetSelected(0,force=1); MoveToFront
  tab_tournament: SetSelected(1,force=1); vtbl+0x94
  tab_advanced:   SetSelected(0,force=1); MoveToFront
  close + mini widgets (+ optional size normalize)
  host vtbl+0x448 / +0x34C
  FUN_0086b370(host); FUN_0086a900(host,-1,-1)
  if global && global[+0x4FC]: FUN_0086b3c0(host)
```

---

## 5. Gaps

1. Product / RTTI English name of host class.
2. Residual dual of `FUN_007b5dd0` / `FUN_0078b6e0` / `FUN_0078f890` / `FUN_008230b0` / tail helpers.
3. Exact product meaning of host vtbl ordinals and listbox extras.
4. `DAT_00aaac10` threshold semantics; UI scale globals residual.
5. Runtime schedule-open capture; bit-exact image.

**Verdict:** **accept-with-gaps** — ABI, body bounds, virtual dispatch, child-build pattern, tab policy, plate family sealed; product labels + residual helpers open.
