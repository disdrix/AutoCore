# Dual A/B report — WQ9H-G OWN-ONLY (`0x00942e20`, `0x00807550`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-G**  
**Scope:** VAs `0x00942e20`, `0x00807550` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-G**.  
**Work item:** WQ-009 depth-5 residual dual seal (env day-cycle parent of sky blend apply + TFID map find consumer).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00942e20` Client_FrameTick_EnvDayCycleAndSystems_Inferred | **accept-with-gaps** — EDI host, bare RET, dt clamp 0.2f, dualed sky-blend call site ECX=env, sole frame caller sealed; product host English open |
| `aa_00807550` Client_AssignPendingGhostByObjectTfid_Inferred | **accept-with-gaps** — EAX host, RET4, map@+0x244, TFID@+0x160, dualed find+erase, plate ghost string sealed; product class/vtbl English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): sky-blend-as-this-VA, ECX-this, skill-hash, find-only, insert, vehicle-only-scaffold mix-ups **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00942e20` — sealed facts

1. **Body:** `0x00942e20`–`0x009430f0` exclusive (**720 B** / `0x2D0`); frame `SUB ESP,0x114`; epilogue **`RET`** (`C3`).
2. **ABI:** **EDI** = client/session host (register this); no stack args; returns **0** success / **1** if gate `FUN_0092e510` fails.
3. **Semantics — env day-cycle frame parent:**
   - dt = min(`*(float*)(DAT_00d09874+0x30)`, **0.2f** `DAT_00a0f70c`).
   - If `[EDI+0xe04] != 0`: ECX = `*([EDI+0xe04]+0xe894)`; push dt; **`Env_DayCycle_ApplySkyBlendAndLight_Inferred`** (`0x004912c0`, dualed WQ9G-F).
   - Then system ticks, optional fog material (scale **0.01f** `DAT_00af9120`; `fFogHeight` = 1.0f), list drain, primary vtbl+0x344(dt).
   - One-shot `"%%%%%%%%%%%%%%%%%% All load time (%f)\n"` when `DAT_00d1f06c==0`.
4. **Caller (1):** `FUN_0094b520` @ `0x0094b865` (main frame; profile bucket 1).
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `Client_FrameTick_EnvDayCycleAndSystems_Inferred` (Ghidra `FUN_00942e20`). Product English open → `_Inferred`.
7. **Decompile ≡ raw CF**; EDI-this + sky-blend ECX path sealed by **disasm** (decomp hides ECX setup / shows `unaff_EDI`).

### Gaps

- Product / PDB client host class.  
- Gate + undualed helper English.  
- Exact world-root vs env types at `+0xe04` / `+0xe894`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00942e20_FUN_00942e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00942e20_FUN_00942e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_FrameTick_EnvDayCycleAndSystems_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00942e20.cpp` |
| Function | `docs/reconstruction/functions/aa_00942e20_FUN_00942e20.md` |
| Function named | `docs/reconstruction/functions/aa_00942e20_Client_FrameTick_EnvDayCycleAndSystems_Inferred.md` |

---

## VA `0x00807550` — sealed facts

1. **Body:** `0x00807550`–`0x008075cb` exclusive (**123 B** / `0x7B`); pad `CC`; epilogue **`RET 4`** (`C2 04 00`).
2. **ABI:** **EAX** = client/host; stack **object***; **`RET 4`**.
3. **Semantics — TFID map find consumer (pending ghost assign):**
   - manager = `(*(host+0xc78))->vtbl+0x48()`; null → return.
   - map = `manager+0x244` (head @ map+4 = manager+0x248).
   - key = `object+0x160` (TFID 8 B).
   - **`StdMap_Find_Tfid_Isnil29_Inferred`** (`0x004cba00`, dualed WQ9G-G).
   - Hit and `payload(node+0x20)+0x5c == 0`:
     - log `"Assigned a pending ghost to %I64d"`;
     - object vtbl **`+0x2b8`**(payload);
     - **`Map_EraseNode_B`** (`0x00409220`, dualed WQ9E-G).
4. **Classification:** worker / consumer (not the find leaf).
5. **Xrefs (4 UNCONDITIONAL_CALL):** `Client_CreateVehicleObjectApply` ×3; `FUN_0080af70` ×1.
6. **Name:** `Client_AssignPendingGhostByObjectTfid_Inferred` (Ghidra `FUN_00807550`). Scaffold plate/chain names narrowed. Product English open → `_Inferred`.
7. **Decompile ≡ raw CF**; EAX-host + map/key offsets + RET4 sealed by **bytes/disasm**.

### Gaps

- Product host/manager/payload class English.  
- Object vtbl `+0x2b8` / manager `+0x48` product names.  
- Full dual of callers (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00807550_FUN_00807550.md` |
| Annotated | `docs/reconstruction/raw/aa_00807550_FUN_00807550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_AssignPendingGhostByObjectTfid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00807550.cpp` |
| Function | `docs/reconstruction/functions/aa_00807550_FUN_00807550.md` |
| Function named | `docs/reconstruction/functions/aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0094b520  main client frame
  └─ Client_FrameTick_EnvDayCycleAndSystems_Inferred (0x00942e20)  [OWN WQ9H-G]
        └─ Env_DayCycle_ApplySkyBlendAndLight_Inferred (0x004912c0) [dualed WQ9G-F]
              ├─ WorldClock_GetSkyBlendAmount_Inferred (0x00553cd0)
              └─ WorldClock_GetQuarterPhase01_Inferred (0x00553dd0)

Client_CreateVehicleObjectApply / FUN_0080af70
  └─ Client_AssignPendingGhostByObjectTfid_Inferred (0x00807550)  [OWN WQ9H-G]
        ├─ StdMap_Find_Tfid_Isnil29_Inferred (0x004cba00) [dualed WQ9G-G]
        │     └─ StdMap_LowerBound_Tfid_Isnil29 (0x004cb4b0) [dualed W31-N]
        └─ Map_EraseNode_B (0x00409220) [dualed WQ9E-G]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00942e20-00807550-wq9hg-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00942e20` | Port as **client frame tick**: clamp dt ≤ **0.2**; if world root live, call env day-cycle sky blend on env at worldRoot`+0xe894` with dt (unread in child); then fog/systems/list/primary. Host in **EDI**. Not combat. Pair dualed `004912c0`. |
| `00807550` | Port as **pending-ghost resolve**: find TFID@object`+0x160` in map@manager`+0x244`; if hit and payload`+0x5c==0`, assign via object vtbl`+0x2b8`, erase node. **EAX** host + **RET 4**. Pair dualed find `004cba00` + erase `00409220`. |
| Pair with | dualed sky blend + clock leaves; TFID find + erase B; vehicle apply parent when dualed |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- environment / client-frame and ghost-net system notes  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00942e20`, `0x00807550`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only; clean sources use meaningful names.  
- Odd behavior preserved: decomp `unaff_EDI` / hidden sky-blend ECX; decomp `in_EAX` host; head compare via manager`+0x248`.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
