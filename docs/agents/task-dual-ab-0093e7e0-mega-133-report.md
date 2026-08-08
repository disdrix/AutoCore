# Dual A/B report — MEGA-133 OWN-ONLY (`0x0093e7e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-133**  
**Scope:** VA `0x0093e7e0` (`aa_0093e7e0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `disassemble_function` + `get_function_callers` / `callees` / `xrefs` + `get_function_by_address` + `get_function_signature` + `read_memory` + caller decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-133 residual dual seal — Client UI init dialog host install (createNDUIDialogs body).  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-133**.  
**Hint:** Client UI init dialog host install.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0093e7e0` Client_UI_CreateNDUIDialogs_InstallHost_Inferred | **accept-with-gaps** — CF/ABI/RET4/sole caller/phase plates/install+winpos role sealed; product dialog catalog + vtbl English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): death-respawn-only / thiscall / cdecl / full-InitUserInterface-merge / Named_CalleeOf-final claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0093e7e0` — sealed facts

1. **Body:** `0x0093e7e0`–`0x0093ffa3` inclusive (**6084 B** / `0x17C4`). Meta: 1506 insns, 281 BBs, cyclomatic **97**, ~200 calls.
2. **ABI:** stack **`ClientUiHost* host`** → **EBP**; void; **`RET 4`** (`C2 04 00`). **Not** ECX-thiscall on entry.
3. **Semantics:** bulk **CreateNDUIDialogs** host install:
   - SEH + timing plates (`FUN_007a4400` / `FUN_007a4390`) starting `@@CreateNDUIDialogs`.
   - Cursor at `host+0x1168`: `i_g_2d_cursor.xml` (vtbl+0x28), finalize +0x180, rebind +0x88 from `*(host+0xde8)+0x2c`.
   - Mass `operator_new` + dialog ctor + store to host slots / `DAT_00d09a38`..`48`.
   - Death-respawn widget at `host+0x1158`: `i_g_2d_btn_death_respawn.xml`, id **0x4e5d**.
   - Post: **0x3a** × vtbl+0x174 on `host+0x1030` table; **0x1d** pairs set `dialog+0xc6=1`; `host+0x1100` forced **0**.
   - `FUN_00931570(host)` with **`winpos.ini`**.
   - QPC delta × `_DAT_00afa254` → `sprintf("(%f) %s\n")` → `OutputDebugStringA`.
4. **Caller:** **1** UNCONDITIONAL_CALL — `FUN_0094a580` @ `0x0094a649` after log `"createNDUIDialogs"`.
5. **Xrefs:** sole call site as above.
6. **Plate/XML (sample):** cursor/tooltip/death suite; `@@CNDUIDialog` phases (Title/Action, HUD, information, Arena); `@@CreateNDUIDialogs`.
7. **Name:** `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` (Ghidra `FUN_0093e7e0`). Product PDB open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.
9. **Retired:** `Named_CalleeOf_Mission_createNDUIDialogs_0093e7e0`; **rejected** `Combat_DeathRespawnButton`.

### Gaps

- Per-dialog product class English / full host-field map.  
- NDUI vtbl slot English (`+0x28`, `+0x43c`, `+0xcc`, `+0x174`, `+0x300`, `+0x74`, `+0x180`).  
- Parent wrapper `FUN_0094a580` residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0093e7e0_FUN_0093e7e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0093e7e0_FUN_0093e7e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CreateNDUIDialogs_InstallHost_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0093e7e0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Mission_createNDUIDialogs_0093e7e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0093e7e0_FUN_0093e7e0.md` |
| Function named | `docs/reconstruction/functions/aa_0093e7e0_Client_UI_CreateNDUIDialogs_InstallHost_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0094a580  Mission_createNDUIDialogs / InitUserInterface wrapper  [residual]
  ├─ log "InitUserInterface start"
  ├─ input device init (FUN_00796d70 / …)
  ├─ log "createNDUIDialogs"
  ├─ FUN_0093e7e0  Client_UI_CreateNDUIDialogs_InstallHost_Inferred  [OWN MEGA-133]
  │     ├─ cursor host+0x1168 / many dialog ctors / DAT_00d09a**
  │     ├─ FUN_004063a0  CNDHash_Ctor  [dualed elsewhere]
  │     ├─ FUN_00931570  winpos.ini apply  [residual]
  │     └─ OutputDebugStringA timing
  ├─ log "before switch(m_eServerConnectCurrent)"
  └─ connect / FUN_00937560 …
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0093e7e0-mega-133-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0093e7e0` | Port as **client CreateNDUIDialogs host install** (bulk dialog construction + post layout). **`__stdcall` RET 4**, stack host pointer. Preserve install order, SEH, timing plates, `+0xc6` flag loops, `winpos.ini` pass. |
| Do not | Collapse to death-respawn-only; use thiscall without stack host; skip winpos/post-flags; invent product dialog class names without further duals. |
| Pair with | residual parent `0094a580`; residual `00931570` winpos; dualed `CNDHash_Ctor` `004063a0`; individual dialog ctor residuals. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (client UI init / missions-progression)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0093e7e0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + disassemble_function + read_memory + callers/xrefs/callees + function meta + caller context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; Named_CalleeOf_ scaffold **retired**.  
- Odd behavior preserved: globals `DAT_00d09a38`..`48`; special `host+0x1100` flag clear; decompiler-omitted vtbl args recovered via assembly where needed (cursor XML, winpos, death id).  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
