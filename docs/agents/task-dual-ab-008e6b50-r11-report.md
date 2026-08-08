# Dual A/B report — R11-036 OWN-ONLY (`0x008e6b50`)

**Date:** 2026-08-05
**Agent:** OWN-ONLY dual **R11-036**
**Scope:** VA `0x008e6b50` (`aa_008e6b50`) only. Dual A/B + trio raw/annotated/clean + function records.
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.
**Image:** `autoassault.exe` base `0x400000`.
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-036**.
**Work item:** Residual dual seal — inventory-transfer craft host **CreateChildWidgets** (virtual).
**Parent (score only):** `0x008e5990` `UI_CraftHost_BindResolvedObject_Inferred` (dualed; called at tail — not OWN).
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008e6b50` UI_CraftHost_CreateChildWidgets_Inferred | **accept-with-gaps** — thiscall RET0 / vtbl DATA / XML craft_2d tree / +0x568×5 loop / tail bind+gate sealed; product demangle + residual helpers + runtime open |

Path A (fidelity): **accept-with-gaps**.
Path B (adversarial): cdecl/stdcall-RET4 / direct CALL callers / bind-role merge / decompiler unaff formals / plain-0x488 geo pane claims **falsified**.
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008e6b50` — sealed facts

1. **Body:** `0x008e6b50`–`0x008e811f` inclusive (**5584 B** / `0x15D0`); exit `MOV ESP,EBP; POP EBP; RET` (`8B E5 5D C3`).
2. **ABI:** **thiscall** **ECX = host*** (`MOV EBP,ECX`); no stack args; void; **`RET`** (`C3`).
3. **Dispatch:** sole xref **DATA** vtbl slot `0x00a3aca8` — virtual CreateChildWidgets*; no UNCONDITIONAL_CALL callers.
4. **Semantics:** craft 2d host child construction:
   - `FUN_00792600(host)` prep.
   - Mass `operator_new` + ctor + `host.vtbl+0xa8` attach + `child.vtbl+0x28` load `i_d_craft_2d_*` XML + optional alpha `vtbl+0xfc(1,0.5f)`.
   - Geo pane `new(0x4FC)` + dualed `CNDUIWndBuffered_Ctor_Inferred` → **`host+0x520`** (id `0x9c45`).
   - Object preview **`+0x530` / `+0x54c`** (+ enh stacks) — same slots parent bind shows/hides.
   - **5** material component rows; first column **`host+0x568 + 4*i`** (ESI base `+0x5b8`, EBX 0..4).
   - Tabs **`+0x784`** crafting id `0x9c43`, **`+0x788`** disciplines id `0x9c44`.
   - Optional `DAT_00d1b8b4` path → `host.vtbl+0x114` + `FUN_007fca10`.
   - Tail: dualed **`FUN_008e5990(host, host+0x7cc)`**; **`host+0x7e2 = FUN_0052eb90(DAT_00d1b6d8, object)`**; `host.vtbl+0x34c()`.
5. **Classification:** worker (virtual).
6. **Callees:** `00792600`, `operator_new`, `007b5dd0`, `0078caf0`, `0079c860`, `0078b6e0`, `0078f890`, `008230b0`, `00822cb0`, `00756c90`, `007fbe50`, `007fca10`, `008e5990`, `0052eb90`, vtbls.
7. **Name:** `UI_CraftHost_CreateChildWidgets_Inferred` (Ghidra `FUN_008e6b50`). Product host class open → `_Inferred`.
8. **Decompile:** available but temps corrupted; **assembly authority** for ABI/slots/RET. Scaffold raw body preserved; R11-036 section **appended only**.

### Gaps

- Product demangle for craft host class (vtbl COL/RTTI).
- Residual helper English (`00792600`, `0052eb90`, tab/list ctors).
- Secondary per-row component widget English.
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008e6b50_FUN_008e6b50.md` |
| Annotated | `docs/reconstruction/raw/aa_008e6b50_FUN_008e6b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CraftHost_CreateChildWidgets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008e6b50.cpp` |
| Function | `docs/reconstruction/functions/aa_008e6b50_FUN_008e6b50.md` |
| Function named | `docs/reconstruction/functions/aa_008e6b50_UI_CraftHost_CreateChildWidgets_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
vtbl[slot @ 0x00a3aca8]
  └─ FUN_008e6b50  UI_CraftHost_CreateChildWidgets_Inferred  [OWN R11-036]
        ├─ FUN_00792600  host prep (residual)
        ├─ many CNDUIWindow / buffered / tab children (i_d_craft_2d_*)
        ├─ FUN_008e5990  UI_CraftHost_BindResolvedObject_Inferred  [dualed MEGA-032]
        │     └─ uses slots this unit created (+0x520/+0x530/+0x54c/+0x568/+0x7cc)
        └─ FUN_0052eb90  gate -> host+0x7e2 (residual)

CDlgTrade2d_CreateChildWidgets  0x008847f0  [dualed] — same CreateChildWidgets role family; different XML
```

Partition parent `0x008e5990` is the dualed bind worker this unit **calls**, not a structural outer caller.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008e6b50-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008e6b50` | Port as **craft host CreateChildWidgets\*** (virtual). **thiscall RET 0**: ECX=host. Build full `i_d_craft_2d_*` child tree; material bank at **+0x568** (5 dwords); geo buffered at **+0x520**; always rebind via `UI_CraftHost_BindResolvedObject` on **+0x7cc**; write **+0x7e2** from gate helper. Do **not** implement TFID resolve or recipe fill here. |
| Pair with | dualed bind `008e5990`; dualed TFID parent `008e5ce0`; dualed buffered ctor `0078caf0`; residual prep `00792600` / gate `0052eb90`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history
- `systems/inventory-transfer.md` residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

**Name to register:** `UI_CraftHost_CreateChildWidgets_Inferred` @ `0x008e6b50` / `aa_008e6b50`.
**Verdict:** **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x008e6b50`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine twin `FUN_008e6b50.cpp`.
- Odd behavior preserved: always rebind at tail; gate byte from global mgr; interleaved z-order bumps.
- `_Inferred` (product host class unproven). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
