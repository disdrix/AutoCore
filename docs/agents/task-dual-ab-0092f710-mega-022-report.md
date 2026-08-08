# Dual A/B report — MEGA-022 OWN-ONLY (`0x0092f710`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-022**  
**Scope:** VA `0x0092f710` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — keymap.ini loader; partition system input-drive-control; parent context keymap load / `Client_InitInstance`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092f710` Client_LoadKeymapIni | **accept-with-gaps** — CF/ABI/RET4/path/delimiters/dual-lane apply/sole InitInstance caller sealed; helper duals + mode English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall-client / silent-fail / double-call-bug / VOG-merge / multi-caller / always-overwrite-custom / RET0 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092f710` — sealed facts

1. **Body:** `0x0092f710`–`0x0092f91a` inclusive (**523 B** / `0x20B`); pad `CC` @ `0x0092f91b`.
2. **ABI:** stack **`client*`**; void; **`RET 4`** ×2 exits (`0x0092f752` fail, `0x0092f918` success). Frame `SUB ESP,0xc18`.
3. **Semantics:** **keymap.ini loader** for ActionMap at **`client+0x116c`**:
   - `fopen("keymap.ini","r")` (`0x00a2e624` / `0x00a152e4`).
   - Fail: `EAX="keymap.ini"`; `FUN_007f9480(client+0x116c)` writes default key mapping file; return.
   - Success: line loop `fgets(…,0x800)`; strip comments via `strstr("//")`; tokenize on `"=;"`; require description `strlen>=2`; scan modes **0..3** with `FUN_007f9230` (find slot by description); copy primary/alt strings; `FUN_0092db30` parse key tokens; dualed **`ActionMap_TrySetSlotBind`** with **BL=0 then BL=1**.
4. **Delimiter constants:** `DAT_00a152dc="//"`, `DAT_00a152e0="=;"` (`read_memory` sealed).
5. **Callees:** CRT `fopen`/`fgets`/`fclose`/`strstr`/`strtok`/`strncpy`; `FUN_007f9480`; `FUN_007f9230`; `FUN_0092db30`; `FUN_007f72e0` / dualed `ActionMap_TrySetSlotBind`.
6. **Callers:** **1** — dualed `Client_InitInstance` `FUN_0094a6a0` @ `0x0094a83b` (plate `@@CoInitializeEx, Version, Ini, Keymap, colors`).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `Client_LoadKeymapIni` (Ghidra `FUN_0092f710`). Product surface sealed by literal + InitInstance Keymap plate + writer header. Scaffolds `Named_keymap_ini` / `Named_CalleeOf_Named_Client_InitInstance_0092f710` **retired**.
9. **Decompile ≡ raw CF**; ABI + fail-path EAX path + BL lanes sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product English for ActionMap mode groups 0..3 (counts/offsets sealed in dualed `ActionMap_TrySetSlotBind`: max 5 / 6 / 0x78 / 0x14).  
- Full dual seal of `FUN_007f9230` / `FUN_007f9480` / `FUN_0092db30` (evidence only).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092f710_Client_LoadKeymapIni.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092f710_Client_LoadKeymapIni.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0092f710_FUN_0092f710.md` |
| Annotated | `docs/reconstruction/raw/aa_0092f710_FUN_0092f710.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_LoadKeymapIni.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092f710.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_keymap_ini.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_Client_InitInstance_0092f710.cpp` |
| Function | `docs/reconstruction/functions/aa_0092f710_FUN_0092f710.md` |
| Function named | `docs/reconstruction/functions/aa_0092f710_Client_LoadKeymapIni.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_InitInstance  0x0094a6a0  [dualed]
  plate: "@@CoInitializeEx, Version, Ini, Keymap, colors"
  ├─ FUN_0092f960                 [residual — Version/Ini peer]
  ├─ FUN_0092f710  Client_LoadKeymapIni  [OWN MEGA-022]
  │     fopen("keymap.ini")
  │     fail → FUN_007f9480 write default  [residual]
  │     line loop:
  │       FUN_007f9230 find slot by desc   [residual]
  │       FUN_0092db30 parse key token     [residual]
  │       FUN_007f72e0 ActionMap_TrySetSlotBind  [dualed] ×2 (BL=0, BL=1)
  └─ FUN_0092f580                 [residual — colors peer]

Client_InitDefaultKeybinds  0x007f8720  [dualed]
  └─ ActionMap_TrySetSlotBind ×74 (defaults; flag-gated)

Client_LoadVogIniConfig  0x009365e0  [dualed — DISTINCT VOG.ini path]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092f710-mega-022-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092f710` | Port as **client keymap.ini loader**. **Stack client\***, **RET 4**, ActionMap at **`+0x116c`**. Format: `Description=KEY;ALT;` with `//` comments. Missing file → **write default** (not silent). Apply binds **primary then alt** via `ActionMap_TrySetSlotBind` (preserve customized-flag gate). Boot-time only from InitInstance. Keep distinct from `Client_LoadVogIniConfig`. |
| Pair with | dualed `ActionMap_TrySetSlotBind` `007f72e0`; dualed `Client_InitDefaultKeybinds` `007f8720`; dualed `Client_InitInstance` `0094a6a0`; residual find/write/parse helpers `007f9230` / `007f9480` / `0092db30`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_keymap_ini` / `Named_CalleeOf_*0092f710`)  
- `systems/*` input-drive-control residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0092f710`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + DAT strings. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name `Client_LoadKeymapIni`; machine twin `FUN_0092f710.cpp`; Named_* scaffolds retired.  
- Odd behavior preserved: fail path **writes** default file; dual TrySetSlotBind is primary/alt not a bug; decomp BL loss corrected via asm.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
