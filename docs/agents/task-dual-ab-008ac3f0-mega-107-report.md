# Dual A/B report — MEGA-107 OWN-ONLY (`0x008ac3f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-107**  
**Scope:** VA `0x008ac3f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` — Mission dialog host ctor.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` / `signature` + callers / callees / xrefs + `get_function_call_graph` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Mega residual dual seal — host ctor for dualed Flush / ShowNpcMissionDialogUI family (`0x008ab8f0` / `0x009438f0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008ac3f0` Client_NpcMissionDialogHost_Ctor_Inferred | **accept-with-gaps** — CF/ABI/RET4/vtbl/string/caller/callee chain sealed; product class English + nested base/virtual plates open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): show/packet/ECX-thiscall/multi-caller/string-as-product/wrong-vtbl-slot claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008ac3f0` — sealed facts

1. **Body:** `0x008ac3f0`–`0x008ac53f` inclusive last byte of **`RET 4`** (**336 B** / `0x150`); Ghidra Body `008ac3f0 - 008ac53f`; **1** basic block; cyclomatic **1**.
2. **ABI:** Stack **`this*`** → **EDI**; base `FUN_0087b890(this, 0)`; **EAX = this**; **`RET 4`** (`C2 04 00` @ `0x008ac53d`). SEH `LAB_009b645d`.
3. **Semantics (ctor):**
   - Base NDUI/host ctor with secondary arg **0**.
   - Install vtable **`0x00a4a51c`** (`PTR_FUN_00a4a51c`).
   - Init 3×`(0,0,0,1)` float basis @ **`+0x584`** using **`g_flOne`** (`0x00a0f2a0` = 1.0f).
   - Defaults: **`+0x4FC = 0x0C`**, **`+0x500 = 1`**, **`+0x63C = 1`**, **`+0x640 = 1`** (columns), **`+0x648 = 0`** (mode), select zeros.
   - `FUN_008ab0a0()` mission-dialog field pack (ECX=this).
   - `NDUIWindow_ReloadInterface("i_d_npc.xml")` — string @ **`0x00a4b0e0`**.
   - `FUN_008ac110` / `UI_MissionDialog_BuildResponseButtons_Inferred` (dualed peer).
   - Virtual **`vtbl+0x34C`** → **`FUN_00791dc0`** (DATA @ `0x00a4a868`).
4. **Caller (1):** `FUN_0093e7e0` @ `0x0093f420` — `operator_new(0x748)` → ctor → store **`client+0x1058`**.
5. **Xrefs:** 1 UNCONDITIONAL_CALL (same site).
6. **Callees:** `FUN_0087b890`, `FUN_008ab0a0`, `NDUIWindow_ReloadInterface` (`0x00792980`), `FUN_008ac110`, virtual `FUN_00791dc0`.
7. **Name:** `Client_NpcMissionDialogHost_Ctor_Inferred` (Ghidra `FUN_008ac3f0`). Product map open → **`_Inferred`**. Retired string scaffold `Mission_i_d_npc_xml_008ac3f0`.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `read_memory` body + vtable/string reads.

### Gaps

- Product / PDB class English for vtable `0x00a4a51c`.  
- Dual of base `FUN_0087b890`, field pack `FUN_008ab0a0`, virtual `FUN_00791dc0` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.md` |
| Annotated | `docs/reconstruction/raw/aa_008ac3f0_FUN_008ac3f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialogHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ac3f0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Mission_i_d_npc_xml_008ac3f0.cpp` |
| Function | `docs/reconstruction/functions/aa_008ac3f0_FUN_008ac3f0.md` |
| Function named | `docs/reconstruction/functions/aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0093e7e0  client UI subsystem table ctor
  operator_new(0x748)
  └─ FUN_008ac3f0  Client_NpcMissionDialogHost_Ctor_Inferred  [OWN MEGA-107]
        ├─ FUN_0087b890(self, 0)          base  [residual]
        ├─ *self = vtbl 0x00a4a51c
        ├─ defaults (columns=1, mode=0, id=0xC, basis, …)
        ├─ FUN_008ab0a0()                 field zero pack  [residual]
        ├─ NDUIWindow_ReloadInterface("i_d_npc.xml")
        ├─ FUN_008ac110  UI_MissionDialog_BuildResponseButtons_Inferred  [dualed WQ7R-B]
        └─ vtbl+0x34C → FUN_00791dc0      [residual]

client+0x1058 ──host──► class 0x00a4a51c
  ├─ vtbl+0x43C  Client_BuildNpcMissionDialogWidgets     [dualed]
  ├─ vtbl+0x440  Client_MissionDialog_FlushPreparedResponse [dualed]
  └─ consumers: Client_ShowNpcMissionDialogUI (0x009438f0) [dualed]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008ac3f0-mega-107-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008ac3f0` | Port as **client NPC mission dialog host ctor**. Stack **this***, **`RET 4`**, **EAX=this**. Alloc **`0x748`**, store **`client+0x1058`**, vtable **`0x00a4a51c`**, skin **`i_d_npc.xml`**. Preserve order: base → vtbl → defaults → zero pack → XML → response buttons → virtual `+0x34C`. Default **columns=1**, **mode=0**. **No** server mission logic / no 0x206E send here. |
| Pair with | dualed BuildResponseButtons `008ac110`; dualed Flush `008ab8f0`; dualed BuildWidgets `008ad240`; dualed ShowUI `009438f0`; residual base `0087b890` / zero pack `008ab0a0` / virtual `00791dc0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` missions-progression residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x008ac3f0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; string-only `Mission_i_d_npc_xml_*` retired.  
- Odd behavior preserved: stack-this (not ECX) outer ABI; `RET 4`; skips dword index `0x1ce` in trailing zero band; builds response strip at construct time (full tree later via BuildWidgets).  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
