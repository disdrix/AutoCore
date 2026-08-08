# Dual A/B report — MEGA-051 OWN-ONLY (`0x008ab550`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-051**  
**Scope:** VA `0x008ab550` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (incl. residual `0x008ab340` MEGA-105).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-051**.  
**Work item:** residual dual seal — Select a Mission multi-mission panel fill / panel-mode applicator under `Client_ShowNpcMissionDialogUI`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008ab550` Client_NpcMissionDialog_ApplyPanelMode_Inferred | **accept-with-gaps** — CF/ABI/mode table/mode-3 string fill/3 callers sealed; product demangle + mode1≠2 English + residual `008ab340` + runtime scale open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): locale-as-mode / stack-arg-RET4 / select-only / always-show-chrome claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008ab550` — sealed facts

1. **Body:** `0x008ab550`–`0x008ab799` inclusive (**586 B** / `0x24A`); pad `CC`×6.
2. **ABI:** **ECX** = dialog host*; **EAX** = panel mode `{0,1,2,3}`; void; plain **`RET`** (`C3`) both exits. No stack formals.
3. **Semantics:** NPC mission dialog **panel-mode applicator**:
   - Store mode at `dialog+0x648`.
   - Mode **0/3:** clear `+0x670`, clear `+0x580`, hide chrome (incl. 4×4 grid `+0x698..+0x6d4`).
   - Mode **1/2:** `+0x678/+0x67c = −1`; show `+0x6f8/+0x6fc`.
   - Mode **3:** title `+0x6dc` — style 10; scale `+0x170/+0x174` from base `+0x1b8/+0x1bc` × viewport `DAT_00d1e818/1c` × `DAT_00aaa67c/678` (≈1/1600, 1/1200); localize **`"Select a Mission:"`** via dualed Locale+StringPool; color `DAT_00afdf0c`; layout.
   - Tail: residual `FUN_008ab340` with **ESI=dialog**.
4. **Classification:** worker.
5. **Xrefs:** 3 UNCONDITIONAL_CALL.
6. **Callers:** `Client_ShowNpcMissionDialogUI` @ `00943972` (**EAX=3** multi-active), @ `00943a6c` (**EAX=1** single); `FUN_0093e450` @ `0093e623` (**EAX=0**).
7. **Callees:** `Locale_GetInstance_Inferred` (`007a69d0`), `StringPool_ApplyModeAndRingStore_Inferred` (`007a6de0`), `FUN_008ab340`, widget vtbls `+4/+0x1b0/+0x1d8/+0x15c/+0x34c`.
8. **Name:** `Client_NpcMissionDialog_ApplyPanelMode_Inferred` (Ghidra `FUN_008ab550`). Prior string-only `Mission_Select_a_Mission` **retired**. Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + call-site `get_assembly_context` + `read_memory` (decompiler locale/`in_EAX` lag corrected).

### Gaps

- Product / PDB dialog + widget class names.  
- Mode 1 vs 2 product English (same chrome path here).  
- Runtime viewport `DAT_00d1e818/1c` + visual scale.  
- Residual `FUN_008ab340` (MEGA-105).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008ab550_FUN_008ab550.md` |
| Annotated | `docs/reconstruction/raw/aa_008ab550_FUN_008ab550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_NpcMissionDialog_ApplyPanelMode_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008ab550.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Mission_Select_a_Mission_008ab550.cpp` |
| Function | `docs/reconstruction/functions/aa_008ab550_FUN_008ab550.md` |
| Function named | `docs/reconstruction/functions/aa_008ab550_Client_NpcMissionDialog_ApplyPanelMode_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_ShowNpcMissionDialogUI  [dualed parent 009438f0]
  ├─ multi-active (mission count > 1, key == -1):
  │     MOV EAX,3 ; MOV ECX,dialog ; CALL FUN_008ab550  [OWN MEGA-051]
  │     FUN_008aa4b0 / Client_UpdateMissionJournal / …
  └─ single present:
        … PrepareResponse …
        MOV EAX,1 ; MOV ECX,dialog ; CALL FUN_008ab550  [OWN MEGA-051]
        FUN_008aa4b0 / …

FUN_0093e450  dialog interact case 0  [not OWN]
  └─ XOR EAX,EAX ; MOV ECX,dialog ; CALL FUN_008ab550  [OWN MEGA-051]

FUN_008ab550  Client_NpcMissionDialog_ApplyPanelMode_Inferred  [OWN MEGA-051]
  ├─ Locale_GetInstance_Inferred              (007a69d0) [dualed]
  ├─ StringPool_ApplyModeAndRingStore_Inferred (007a6de0) [dualed]  // mode 3
  ├─ title/chrome widget vtbls
  └─ FUN_008ab340  list-row clear             [MEGA-105 residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008ab550-mega-051-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008ab550` | Port as **panel-mode applicator** on NPC mission dialog. **ECX=dialog**, **EAX=mode∈{0,1,2,3}**, plain **RET**. Mode 3 = multi-mission `"Select a Mission:"` title fill. Do **not** treat mode as Locale singleton return. Do **not** invent stack args. Pair with dualed Locale `007a69d0` + StringPool `007a6de0`; residual list clear `008ab340`. |
| Pair with | dualed parent `Client_ShowNpcMissionDialogUI` `009438f0`; dualed Locale/StringPool; residual `008ab340` (MEGA-105); residual dialog interact `0093e450`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (`Mission_Select_a_Mission` → `Client_NpcMissionDialog_ApplyPanelMode_Inferred`)  
- `systems/missions-progression.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x008ab550`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended**.  
- Clean source uses meaningful name; ABI corrections (EAX mode; locale EBP; plain RET).  
- Retired string-only `Mission_Select_a_Mission` scaffolds.  
- Odd behavior preserved: mode 1 and 2 share chrome path; early return only when `+0x6fc` non-null on mode 1/2; static viewport dims zero.  
- `_Inferred` (product demangle open). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
