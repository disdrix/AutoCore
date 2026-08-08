# Dual A/B report — R12-008 OWN-ONLY (`0x0092b2a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-008**  
**Scope:** VA `0x0092b2a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs; parent dual `0x0092af80` edits; grandcaller `0x0092bf60` edits.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-008**.  
**Work item:** Residual dual wave R12 — inventory-transfer partition (parent dual `0x0092af80`); role = MissionTracker secondary multi-target slot fill. Dual start **2646**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred | **accept-with-gaps** — CF/ABI/top-4 emit/sole caller/constants sealed; product English + residual arm micro-ops open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void / thiscall / cdecl-bare-RET / EAX-host / unlimited / TFID@+0x160 / multi-caller / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0092b2a0` — sealed facts

1. **Body:** `0x0092b2a0`–`0x0092bf5b` inclusive (**3260 B** / `0xCBC`); pad `CC` @ `0x0092bf5c+`; next `FUN_0092bf60`.
2. **ABI:** stack **stdcall** `(host, origin)`; **`RET 8`**; returns **AL** bool; host loaded `MOV EBX,[EBP+8]`. **Not** ECX-thiscall.
3. **Semantics — secondary multi-target fill:**
   - Init 4 dist slots = **FLT_MAX** (`DAT_00aaa630`).
   - If `host+0x54>0` or `host+0x80>0`: CBID/world mission-tree arm (level band `+0x108/+0x10C`, CBID lists, temp map rank → top-4).
   - Else if `host+0xAC>0`: race arm (CS key **0x36**, race/type tables, min distSq **10000** via `DAT_00aaa880`).
   - Else fail `AL=0`.
   - Optional `FUN_0092b1c0` when `host+6 != 0`.
   - Emit ≤4 nodes `0x20`: seed TFID `DAT_00a158a0`, push vector begin **`host+0x11C`**, copy pos `obj+0x84/88/8c`, TFID_16 from **`obj+0x164`**.
   - On any emit: `host+0x08 = 1`, `AL=1`.
4. **Callees:** `0092b1c0`, `00929c60`, `0040b3b0`/`0040b440`/`0040b890`/`0040bc10`, `0040b330`, `00419880`, `004294f0`/`004022a0`, `004f1e20`, `Object_GetRootRaceId`, `CVOGCharacter_WeaponAllowsKillXpBonus`, `operator_new`/`delete`, `LeaveCriticalSection`, vtbl `+0x1EC`/`+0x27C`/`+0x14`.
5. **Callers:** **1** — `FUN_0092bf60` @ `0x0092c058` (`PUSH origin; PUSH host; CALL; TEST AL`).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `MissionTracker_FillTrackedTargetSlots_Inferred` (Ghidra `FUN_0092b2a0`). Scaffold twin kept as `FUN_0092b2a0.cpp`.
8. **Decompile ⊊ sealed CF on iterators/SEH**; ABI + emit + arm gates sealed via `read_memory` / assembly context.

### Gaps

- Product/PDB host class and node English.  
- Residual interiors `0092b1c0` / `00929c60` / map helpers.  
- Official names for CBID list A/B and race tables.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092b2a0_MissionTracker_FillTrackedTargetSlots_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092b2a0_MissionTracker_FillTrackedTargetSlots_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ R12-008 re-verify append) | `docs/reconstruction/raw/aa_0092b2a0_FUN_0092b2a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0092b2a0_FUN_0092b2a0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/MissionTracker_FillTrackedTargetSlots_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092b2a0.cpp` |
| Function | `docs/reconstruction/functions/aa_0092b2a0_FUN_0092b2a0.md` |
| Function named | `docs/reconstruction/functions/aa_0092b2a0_MissionTracker_FillTrackedTargetSlots_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0092c640  MissionTracker timer/dirty tick  [residual]
  dirty → FUN_0092c080 bind lists → FUN_0092bf60 refresh

MissionTracker_RefreshTrackedTargets_Inferred  0x0092bf60  [dualed R11-040]
  ├─ clear vector +0x11c
  ├─ primary FUN_0092af80 TargetFilter_DispatchMatchArms_Inferred  [dualed R11-039 / parent]
  │     └─ arms include dualed 0092adf0 CBID nearest / locker gate
  ├─ primary bind FUN_0092a440 + TFID@obj+0x160  [residual]
  └─ secondary CALL 0x0092b2a0  MissionTracker_FillTrackedTargetSlots_Inferred  [OWN R12-008]
        ├─ CBID/world arm (lists +0x54 / +0x80)
        ├─ race arm (list +0xAC, CS key 0x36, min distSq 10000)
        └─ emit ≤4 nodes → vector +0x11C; TFID@obj+0x164; host+0x08=1
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0092b2a0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092b2a0` | Port as **MissionTracker secondary multi-target slot fill**. **Stack stdcall** `(host, origin)`, **`RET 8`**, **AL** bool. Top-4 nearest; CBID lists vs race list arm split; nodes `0x20` with TFID from **`obj+0x164`** (not primary `+0x160`); vector begin **`host+0x11C`**; success sets **`host+0x08=1`**. Pair with dualed refresh `0092bf60` and filter `0092af80`. Do not treat as inventory item move. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).
