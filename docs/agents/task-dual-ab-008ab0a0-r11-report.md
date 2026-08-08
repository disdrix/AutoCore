# Dual A/B report — R11-035 OWN-ONLY (`0x008ab0a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-035**  
**Scope:** VA `0x008ab0a0` (`aa_008ab0a0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Role hint:** NPC mission-dialog host mid-ctor runtime field init / sentinel pack.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (incl. parent `0x008ac3f0`, residual `0x0087b890`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-035**.  
**System:** `missions-progression`.  
**Parent (evidence only):** `Client_NpcMissionDialogHost_Ctor_Inferred` `0x008ac3f0`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008ab0a0` Client_NpcMissionDialog_InitRuntimeFields_Inferred | **accept-with-gaps** — ECX ABI, 670 B leaf body, bank offsets, float constants, sole ctor CALL + vtbl DATA sealed; product English + float4 roles open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ESI-this / XML-build / destroy-clear / stack-this / identity-matrix / panel-mode-at-0x64c claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008ab0a0` — sealed facts

1. **Body:** `0x008ab0a0`–`0x008ab33d` inclusive (**670 B** / `0x29E`); RET `C3` @ `0x008ab33d`; pad `CC CC` before `FUN_008ab340`.
2. **ABI:** **ECX = NpcMissionDialogHost***; no stack args; plain **`RET`**. Frame `SUB ESP,0x10` / `PUSH ESI` … `POP ESI` / `ADD ESP,0x10`.
3. **Semantics:** mid-ctor **runtime field init / sentinel pack**:
   - Zero widget/chrome/list pointers + chrome mode `+0x510` + `+0x644`.
   - **4×** reward/chrome banks: TFID pairs `+0x558+i*8` = `(−1,−1)`; zeros `+0x698/+0x6a8/+0x6b8/+0x6c8 + i*4`.
   - **8×** response banks: TFID pairs `+0x518+i*8` = `(−1,−1)`; widgets `+0x708+i*4` = `0`; extra `+0x578/+0x57c` = `−1`.
   - Float4s: `+0x594=(0,0,0,0.6)`, `+0x584=(0,1,0,0.157)`, `+0x5a4=(0,1,0,0.549)`.
   - Turn-in flag `+0x64c = 0`.
4. **Classification:** **leaf** (no callees).
5. **Xrefs:** 1 UNCONDITIONAL_CALL + 1 DATA.
6. **Callers:** `Client_NpcMissionDialogHost_Ctor_Inferred` (`FUN_008ac3f0`) @ `008ac505` (`MOV ECX,EDI` @ `008ac4bb`).
7. **DATA:** vtbl `0x00a4a51c` + **0x3AC** @ `0x00a4a8c8` → `0x008ab0a0`.
8. **Globals:** `g_flOne@00a0f2a0=1.0`, `DAT_00a0f71c=0.6`, `DAT_00aaa7e8=0.157`, `DAT_00aaa7e4=0.549`.
9. **Name:** `Client_NpcMissionDialog_InitRuntimeFields_Inferred` (Ghidra `FUN_008ab0a0`). Scaffold `Named_CalleeOf_Mission_i_d_npc_xml_008ab0a0` **retired**. Product demangle open → `_Inferred`.
10. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + caller `get_assembly_context` + `read_memory`.

### Gaps

- Product/PDB method name (vtbl+0x3AC).  
- Float4 bank product English (color vs layout).  
- Virtual dispatch use of vtbl slot beyond ctor.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008ab0a0_FUN_008ab0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialog_InitRuntimeFields_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ab0a0.cpp` |
| Function | `docs/reconstruction/functions/aa_008ab0a0_FUN_008ab0a0.md` |
| Function named | `docs/reconstruction/functions/aa_008ab0a0_Client_NpcMissionDialog_InitRuntimeFields_Inferred.md` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Mission_i_d_npc_xml_008ab0a0.cpp` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0093e7e0  (not OWN)
  └─ operator_new(0x748) ; CALL Client_NpcMissionDialogHost_Ctor_Inferred

Client_NpcMissionDialogHost_Ctor_Inferred  FUN_008ac3f0  [dualed MEGA-107; not OWN]
  ├─ FUN_0087b890(this, 0)                 base  [residual R11-030]
  ├─ install vtbl 0x00a4a51c + early fields
  ├─ CALL FUN_008ab0a0                      [OWN R11-035]  ECX=this
  ├─ NDUIWindow_ReloadInterface("i_d_npc.xml")
  ├─ UI_MissionDialog_BuildResponseButtons_Inferred  (008ac110) [dualed]
  └─ vtbl+0x34C virtual
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008ab0a0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008ab0a0` | Port as **ctor field init / sentinel pack** on NPC mission dialog host. **ECX=host**, plain **RET**, **leaf**. Seed response banks `+0x518/−1` + `+0x708/0` (8 slots), reward/chrome 4-slot `−1`/0 pattern, three float4 defaults, clear `+0x64c`. Do **not** treat as widget destroy (`008aa560`) or panel-mode applicator (`008ab550`). Do **not** invent stack args. |
| Pair with | dualed parent ctor `008ac3f0`; dualed BuildResponseButtons `008ac110`; dualed clear `008aa560`; dualed ApplyPanelMode `008ab550`; residual base `0087b890`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history (`Named_CalleeOf_*` → `Client_NpcMissionDialog_InitRuntimeFields_Inferred`)
- `systems/missions-progression.md` residual table
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK

**Terminal:** false.

---

## Process

- OWN VA only (`0x008ab0a0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + disassemble_function + get_function_by_address + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended**.
- Clean source uses meaningful name; ABI ECX thiscall; twin `FUN_008ab0a0.cpp` kept.
- Retired string-parent scaffold `Named_CalleeOf_Mission_i_d_npc_xml_008ab0a0`.
- `_Inferred` (product demangle open). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
