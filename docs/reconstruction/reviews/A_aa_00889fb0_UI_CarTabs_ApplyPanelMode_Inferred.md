# Review A (reconstruction fidelity): `aa_00889fb0` UI_CarTabs_ApplyPanelMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00889fb0` |
| **VA** | `0x00889fb0` |
| **Body** | `0x00889fb0`–`0x0088a12e` inclusive (**383 B** / `0x17F`); pad `CC` @ `0x0088a12f` |
| **Canonical name** | `UI_CarTabs_ApplyPanelMode_Inferred` (**Inferred**); Ghidra `FUN_00889fb0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00889fb0_UI_CarTabs_ApplyPanelMode_Inferred.md` |
| **System** | inventory-transfer / car-tabs UI panel mode |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_by_address`, `get_function_callers`, `get_function_xrefs`, `read_memory`, `batch_decompile` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/mode arms/host offsets/XML-backed tab roles/callers sealed; product class English + full expand helper dual open |
| **Dual status** | **Present (R11-033)** |

---

## 1. Purpose

Apply **binary panel mode** on the car-tabs dialog host:

```text
gate: host.vtbl+0x3d8() visible
gate: force || mode != host+0x528
store mode @ host+0x528
mode 0: show chromeA(+0x50c), hide chromeB(+0x510);
        expand+layout cargo(+0x514); collapse+detach mission(+0x518)
mode 1: hide chromeA, show chromeB;
        collapse+detach cargo; expand+layout mission
```

Host identity: singleton `DAT_00d1b880`; init `FUN_0088a290` loads `i_d_tabs_car_2d_tab_cargo.xml` / `i_d_tabs_car_2d_tab_mission.xml` into `+0x514` / `+0x518`.

**ABI:** `EAX`=mode; stack `(host*, force)`; **`RET 8`**; void.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x00889fb0)` 2026-08-05 ≡ raw CF |
| Body bounds | `get_function_by_address` → `00889fb0`–`0088a12e` |
| Machine | `read_memory` full body 383 B; entry/mode-store/epilogue seals |
| Callers | `get_function_callers` + `get_function_xrefs` (13 CALL) |
| Callees | `FUN_00822cb0`, `FUN_00756c90` (batch decompile) |
| Host type | `FUN_0088a290` decompile — XML stems for cargo/mission tabs |
| Parent context | `FUN_0082f510` case `0xb` uses `DAT_00d1b880` + this VA |
| Trio | raw append + annotated + named clean R11-033 |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; dual of `FUN_00822cb0` / `FUN_0088a290` / siblings `00888b00`/`00889410`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw CF | **Confirmed** | 2026-08-05 |
| Body 383 B; `RET 8` epilogue | **Confirmed** | `C2 08 00` @ end + mid mode-1 exit |
| Mode in **EAX**; force stack; host stack | **Confirmed** | entry `MOV ESI,EAX`; `MOV EBP,[ESP+8]` |
| Mode store `host+0x528` (`[0x14a]`) | **Confirmed** | `89 B5 28 05 00 00` |
| Visible gate `vtbl+0x3d8` | **Confirmed** | imm `0x3d8` |
| Mode 0/1 child show-hide + layout order | **Confirmed** | decomp + mode-1/mode-0 byte arms |
| Cargo `+0x514` / mission `+0x518` | **Confirmed** | init XML strings in `FUN_0088a290` |
| Callees `00822cb0` / `00756c90` | **Confirmed** | relative calls in body |
| Multi-caller (menu / bind / init / tabs) | **Confirmed** | xrefs |
| Product PDB class English | **Open** | XML stem only |
| Official vtbl method names | **Open** | structural slots only |
| Runtime / bit-exact | **Open** | Terminal false |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Visible gate | **Yes** |
| Force / mode-changed gate | **Yes** |
| Mode store `+0x528` | **Yes** |
| Mode 0 chrome + cargo layout | **Yes** |
| Mode 1 chrome + mission layout | **Yes** |
| Mode ∉ {0,1} store-only | **Yes** |
| No invented inventory packets | **Yes** |

### Sealed CF sketch

```
UI_CarTabs_ApplyPanelMode_Inferred(host, force, mode/*EAX*/):
  if !host.IsVisible(vtbl+0x3d8): return
  if !force && mode == host.mode(+0x528): return
  host.mode = mode
  if mode == 0:
    ensure_show(chromeA); ensure_hide(chromeB)
    expand(cargo); layout(cargo); collapse(mission); detach(mission)
  else if mode == 1:
    ensure_hide(chromeA); ensure_show(chromeB)
    collapse(cargo); detach(cargo); expand(mission); layout(mission)
```

---

## 5. Gaps

1. Product / RTTI class name for `i_d_tabs_car_2d_*` host.
2. Official names of vtbl `+0x3d8/+0x43c/+0x440/+0x94/+4`.
3. Full dual of expand helper `FUN_00822cb0` and list-detach `FUN_00756c90`.
4. Product English for chrome children at `+0x50c/+0x510` (not named in this unit).
5. Runtime mode transition capture; bit-exact image.

**Verdict:** **accept-with-gaps** — ABI, mode arms, host offsets, cargo/mission tab roles, callers sealed; residual naming + helper duals + runtime.
