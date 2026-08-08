# Dual A/B report — R13-010 OWN-ONLY (`0x00878300`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-010**  
**Scope:** VA `0x00878300` (`aa_00878300`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including residual helpers `00792600` / `00877790` / `008778e0` / `00877c50` / tab ctor `008230b0`, siblings R13-009/011/012).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `list_strings` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-010**.  
**System:** inventory-transfer (partition assignment; unit role is pure client UI CreateChildWidgets — **no inventory wire**).  
**Parent dual:** `0x00756c90` `UI_Widget_MoveToFrontInParentGroup_Inferred` (R12-003).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00878300` UI_ArenaConsole_CreateChildWidgets_Inferred | **accept-with-gaps** — CF/ABI/vtbl+0x43C/full XML↔slot/cmd table/tab policy/mini sentinel sealed; product demangle + residual helpers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): tournament-only plate / inventory-wire / stack-arg stdcall / multi-direct-callers / zero-size-threshold / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00878300` — sealed facts

1. **Body:** `0x00878300`–`0x00878c14` inclusive (**2325 B** / `0x915`); terminal plain **`RET`** (`C3`); pad `CC` after.
2. **ABI:** **`__thiscall`** — **ECX = host***; `MOV EBP,ECX` at entry; no stack formals; **void**; plain **`RET`**. **Not** stdcall / `RET n`.
3. **Semantics:** Virtual **CreateChildWidgets** for the **Arena Console** dialog:
   - SEH frame (`LAB_009b902f`).
   - Host pre-init: `+0x524=0`, `+0xc5=0`, `+0x4fc=0xf`, `+0x500=1`; vtbl `+0x110` / `+0x130`; `FUN_00792600`.
   - ~**19** children: `operator_new` → typed ctor-or-null → store → host attach vtbl `+0xa8` → load XML vtbl `+0x28` → optional show/cmd/hide/select/front.
   - **Default tab = console** (SetSelected 1); tournament + advanced SetSelected 0 + **MoveToFront** (`00756c90`).
   - Mini overlay; size normalize if host size slots ≤ **`DAT_00aaac10` = -99998.0f** using **1600/1200** scale (`DAT_00aaa674` / `DAT_00aaa670`).
   - Tail: `FUN_008778e0`; optional `FUN_00877c50` if `DAT_00d1b6d8 && player[+0x4fc]`; host vtbl `+0x34c`.
4. **Dispatch:** sole xref **DATA** from vtbl slot **`0x00a5a640`** (host vtbl base `PTR_FUN_00a5a204` + **0x43C**). **0** direct CALL callers.
5. **Command ids (High):** close `0x9c40`, instant `0x9c41`, my_stats `0x9c42`, tab_console `0x9c43`, tab_tournament `0x9c44`, tab_advanced `0x9c45`, news `0x9c46`, mini_cancel `0x9c47`.
6. **Callees:** `FUN_00792600`, `operator_new`, `FUN_007b5dd0`×12, `FUN_00864f20`, `FUN_0078f890`, `FUN_0079c860`×4, `FUN_008230b0`×3, dualed `FUN_00822cb0`, dualed `FUN_00756c90`×2, `FUN_00877790`, `FUN_008778e0`, `FUN_00877c50`.
7. **Family peers (do not merge):** dualed `CDlgArenaPrefs_CreateChildWidgets` (`008747e0`); dualed `UI_CraftHost_CreateChildWidgets_Inferred` (`008e6b50`); residual siblings R13-009/011/012 under same parent `00756c90`.
8. **Name:** `UI_ArenaConsole_CreateChildWidgets_Inferred` (Ghidra `FUN_00878300`). Retire plate `UI_arena_console_tab_tournament` as **canonical** (under-specific). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; XML/cmd immediates sealed via `disassemble_function` + `list_strings` + `read_memory` (decompiler drops most path args — not a CF conflict).
10. **Partition parent** `0x00756c90` is wave score parent and **live structural callee** (×2 after collapsed tabs) — not a caller of this VA.

### Gaps

- Product / RTTI demangle for host class (`CDlgArenaConsole*` open).  
- Residual duals of helpers / tab ctor / base ctors (not OWN).  
- Exact English meaning of host `+0x4fc=0xf` and player gate `+0x4fc`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00878300_UI_ArenaConsole_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00878300_UI_ArenaConsole_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00878300_FUN_00878300.md` |
| Annotated | `docs/reconstruction/raw/aa_00878300_FUN_00878300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ArenaConsole_CreateChildWidgets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00878300.cpp` |
| Plate scaffold (retired canonical) | `docs/reconstruction/reconstructed-exact/UI_arena_console_tab_tournament.cpp` |
| Function | `docs/reconstruction/functions/aa_00878300_FUN_00878300.md` |
| Function named | `docs/reconstruction/functions/aa_00878300_UI_ArenaConsole_CreateChildWidgets_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00878c70  UI_arena_console host ctor  [residual plate]
  └─ installs PTR_FUN_00a5a204
       └─ vtbl[+0x43C] @ 0x00a5a640
            └─ FUN_00878300  UI_ArenaConsole_CreateChildWidgets_Inferred  [OWN R13-010]
                  ├─ FUN_00792600  host prep  [residual]
                  ├─ FUN_007b5dd0 / 00864f20 / 0078f890 / 0079c860 / 008230b0  child ctors
                  ├─ FUN_00822cb0  UI_TabChrome_SetSelected_Inferred  [dualed R12-002]
                  ├─ FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  [dualed R12-003; parent]
                  ├─ FUN_00877790 / FUN_008778e0 / FUN_00877c50  post helpers  [residual]
                  └─ host vtbl[+0x34c] finalize

Peer CreateChildWidgets (do not merge names):
  FUN_008747e0  CDlgArenaPrefs_CreateChildWidgets  [dualed]
  FUN_008e6b50  UI_CraftHost_CreateChildWidgets_Inferred  [dualed]
```

Partition system **inventory-transfer** names residual queue membership (UI host proximity to inventory chrome helpers), **not** an inventory packet role for this unit.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00878300-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00878300` | Port as **Arena Console CreateChildWidgets** virtual: ECX host, plain RET, void. Build full `i_d_arena_console_*` tree; cmd ids **0x9c40–0x9c47**; default-select console tab; collapse+front tournament/advanced via dualed tab helpers; mini size sentinel **-99998.f** with 1600/1200 normalize. |
| Distinct from | Tournament-tab-only plate; Arena Prefs CreateChildWidgets `008747e0`; inventory grab/drop senders. |
| Pair with | dualed `00822cb0` SetSelected; dualed `00756c90` MoveToFront; residual host ctor `00878c70`; residual post helpers. |
| Naming caution | **Not** inventory transfer wire. **Not** tournament-only. **Not** Runtime Confirmed. Keep `_Inferred` until RTTI. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (UI CreateChildWidgets — not inventory wire)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

Name to register: `UI_ArenaConsole_CreateChildWidgets_Inferred` @ `0x00878300` / `aa_00878300`.  
Retire plate canonical: `UI_arena_console_tab_tournament`.  
Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00878300`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + list_strings. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (thiscall ECX; plain RET; full XML/cmd table from disasm).
- Odd behavior preserved: OOM path still attempts attach/load on null children; tournament/advanced built then collapsed and moved to front; size sentinel -99998 not 0.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
