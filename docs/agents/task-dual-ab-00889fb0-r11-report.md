# Dual A/B report — R11-033 OWN-ONLY (`0x00889fb0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-033**  
**Scope:** VA `0x00889fb0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x0082f510` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `batch_decompile` (callees/siblings/init). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R11 — undualed callee of dualed class-8 OnCommand; partition system inventory-transfer; parent dual `0x0082f510`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00889fb0` UI_CarTabs_ApplyPanelMode_Inferred | **accept-with-gaps** — CF/ABI/mode 0–1 arms/host offsets/XML cargo·mission roles/multi-caller sealed; product class English + expand-helper dual + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall-only / mode-on-stack / inventory-packet / sole-caller / scaffold-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00889fb0` — sealed facts

1. **Body:** `0x00889fb0`–`0x0088a12e` inclusive (**383 B** / `0x17F`); pad `CC` @ `0x0088a12f`.
2. **ABI:** **EAX** = panel mode `{0,1}`; stack `(host*, force)`; **`RET 8`**; **void** return.
3. **Gates:** host `vtbl+0x3d8` visible; apply if `force != 0` **or** `mode != host+0x528` (`[0x14a]`).
4. **Mode store:** `host+0x528` ← mode.
5. **Mode 0:** show chrome `+0x50c`, hide `+0x510`; expand+layout **cargo** `+0x514`; collapse+detach **mission** `+0x518`.
6. **Mode 1:** hide `+0x50c`, show `+0x510`; collapse+detach cargo; expand+layout mission.
7. **Callees:** `FUN_00822cb0` (ESI=child, BL=show, stack force), `FUN_00756c90` (EDI=child list-detach).
8. **Callers:** 13 CALL — incl. `FUN_0082f510` case `0xb`, `Client_Input_PollBoundActions` ×2, `FUN_0088a290` init tail, `FUN_0080c240`, tab OnCommand sites.
9. **Host type:** init `FUN_0088a290` loads `i_d_tabs_car_2d_tab_cargo.xml` → `+0x514`, `i_d_tabs_car_2d_tab_mission.xml` → `+0x518`; singleton `DAT_00d1b880`.
10. **Name:** `UI_CarTabs_ApplyPanelMode_Inferred` (Ghidra `FUN_00889fb0`). Scaffold `Named_CalleeOf_Client_Input_PollBoundActions_00889fb0` **retired as product**.
11. **Decompile ≡ raw CF**; ABI + mode arms + offsets sealed via `read_memory` (no `disassemble_bytes`).

### Gaps

- Product/PDB class English for car-tabs host.  
- Official vtbl method names (`+0x3d8/+0x43c/+0x440/+0x94`).  
- Full dual of `FUN_00822cb0` / `FUN_00756c90`.  
- Chrome A/B product labels at `+0x50c/+0x510`.  
- Runtime / bit-exact / differential.  
- Sibling panel appliers `0x00888b00` / `0x00889410` residual (not owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00889fb0_UI_CarTabs_ApplyPanelMode_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00889fb0_UI_CarTabs_ApplyPanelMode_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00889fb0_FUN_00889fb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00889fb0_FUN_00889fb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CarTabs_ApplyPanelMode_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00889fb0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_Input_PollBoundActions_00889fb0.cpp` |
| Function | `docs/reconstruction/functions/aa_00889fb0_FUN_00889fb0.md` |
| Function named | `docs/reconstruction/functions/aa_00889fb0_UI_CarTabs_ApplyPanelMode_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0082f510  UI_Window_OnCommand_Class8_Inferred  [dualed — partition parent]
  case 0xb:
    DAT_00d1b880 visible && mode[0x14a]==0 → close helper
    else FUN_007fef20(4,1,0); if visible:
      CALL 0x00889fb0  UI_CarTabs_ApplyPanelMode_Inferred  [OWN R11-033]
        EAX=0, force=1

Client_Input_PollBoundActions
  keybind paths → CALL 0x00889fb0 (mode 0 force 0; related)

FUN_0088a290  car-tabs init
  load i_d_tabs_car_2d_tab_cargo.xml   → host[0x145] (+0x514)
  load i_d_tabs_car_2d_tab_mission.xml → host[0x146] (+0x518)
  CALL 0x00889fb0 (force=1 apply)

Siblings (same family pattern; not owned):
  FUN_00888b00  binary mode @ [0x14d]  DAT_00d1b870
  FUN_00889410  ternary mode @ [0x14c] DAT_00d1b874
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00889fb0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00889fb0` | Port as **car-tabs binary panel mode apply**. **EAX**=mode `{0,1}`, stack `(host*, force)`, **`RET 8`**, void. Mode 0 = cargo tab active; mode 1 = mission tab active. Preserve force-or-changed gate and `+0x528` mode store. Do **not** treat as inventory C2S emitter or pure thiscall. Pair with host init XML paths for cargo/mission children. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire PollBoundActions scaffold)  
- `systems/inventory-transfer.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
