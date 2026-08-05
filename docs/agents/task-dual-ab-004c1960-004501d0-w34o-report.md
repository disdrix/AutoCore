# Dual A/B report — W34-O OWN-ONLY (`0x004c1960`, `0x004501d0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-O  
**Scope:** VAs `0x004c1960`, `0x004501d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave34_partition_map.md` → **W34-O**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c1960` ParticleFluidPhase_CreateLiquidChild_Inferred | **accept-with-gaps** — ECX phase / bare RET / +0xc4 / 0x40 / create→init→activate sealed; nested ctor+liquid init free |
| `aa_004501d0` AnimEventVec_InsertN_Inferred | **accept-with-gaps** — 4-stack / RET 0x10 / 0x1c / max / 1.5× / sole resize caller sealed; nested elem helpers + product demangle open |

---

## VA `0x004c1960` — sealed facts

1. **Body:** `0x004c1960`–`0x004c1a0f` exclusive (**175 B** / `0xAF`). Epilogue `ADD ESP,0x10` + bare **`C3`**. SEH `LAB_009a1ae5`.
2. **ABI:** **ECX=`phase*`** (`mov esi,ecx`); bare **RET**; void.
3. **Semantics:** Create/install/activate liquid child at **`phase+0xc4`**:
   - `operator_new(0x40)` under SEH.
   - `FUN_004c1800(new, phase)` thiscall ctor (or null).
   - Store pointer at `phase+0xc4`.
   - `FUN_004c0fe0(child)` — liquid filter/RT init (`UIFluid*.fx`, `VOGEnvironmentLiquid.cpp` in nested free).
   - If `child+0x10 != 1`: `FUN_0075bf40(0)` + `FUN_007567b0(child+0x38, 0)`; set `child+0x10 = 1`.
4. **Classification:** worker.
5. **Callers (2):** `FUN_004c2080` (`ParticleFluidPhase_Init_Inferred`, W33-S) @ `0x004c20a2`; `FUN_004c1a10` (`Gfx_NDParticleFluidBlendNormal_004c1a10`) @ `0x004c1c5c` (after delete of prior `+0xc4`).
6. **Callees:** `operator_new`, `FUN_004c1800`, `FUN_004c0fe0`, `FUN_0075bf40`, `FUN_007567b0`.
7. **Name:** `ParticleFluidPhase_CreateLiquidChild_Inferred` (Ghidra `FUN_004c1960`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_004c1960`.
8. **Decompile ≡ raw CF**; thiscall ECX + store offset sealed by `read_memory`. Full 175 B hex in raw W34-O section.

### Gaps

- Product class English for 0x40 child / `FUN_004c1800` / `DAT_00b03794`.  
- Nested `FUN_004c0fe0` full ownership (free).  
- OOM null-child path residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c1960_ParticleFluidPhase_CreateLiquidChild_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c1960_ParticleFluidPhase_CreateLiquidChild_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c1960_FUN_004c1960.md` |
| Annotated | `docs/reconstruction/raw/aa_004c1960_FUN_004c1960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_CreateLiquidChild_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c1960.cpp` |
| Function | `docs/reconstruction/functions/aa_004c1960_FUN_004c1960.md` |
| Function named | `docs/reconstruction/functions/aa_004c1960_ParticleFluidPhase_CreateLiquidChild_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c1960.md` |

---

## VA `0x004501d0` — sealed facts

1. **Body:** `0x004501d0`–`0x00450526` exclusive (**854 B** / `0x356`). Final **`C2 10 00`** (`RET 0x10`); pad `CC` then `FUN_00450530`. SEH `LAB_009becf8`.
2. **ABI:** **4 stack args** — `vec*`, `where*`, `count`, `value*` — **not** ECX thiscall for vec; callee cleans **16**; void.
3. **Semantics:** MSVC-style **`vector<AnimEventElem, sizeof=0x1c>::insert(where, count, value)`**:
   - Element: vtbl `PTR_FUN_009d4828`, fields `+4/+8`, nested range via `FUN_00444100` / assign `FUN_0044ffa0`.
   - Capacity/size triad begin@`+4` / end@`+8` / capEnd@`+0xC`; `/0x1c` magic `0x92492493`.
   - Max `0x9249249` → `FUN_004540b0`.
   - Grow: 1.5× (`cap+(cap>>1)`), floor `size+count` (may call `StdVector_Elem28_Size` @ `0x00469c50`); relocate via `FUN_00450600` / fill `FUN_00450560` / destroy `FUN_004501a0` + `operator_delete`.
   - In-place: tail or mid paths (`FUN_00450530`, assign loops).
4. **Classification:** worker.
5. **Callers (1):** `FUN_00450050` @ `0x004500c6` — resize grow: insert `(newSize-oldSize)` at `end`.
6. **Callees:** `FUN_00444100`, `FUN_004540b0`, `FUN_00469c50`, `operator_new`/`delete`, `FUN_00450600`, `FUN_00450560`, `FUN_004501a0`, `FUN_00450530`, `FUN_0044ffa0`, `FUN_00987560`.
7. **Name:** `AnimEventVec_InsertN_Inferred` (Ghidra `FUN_004501d0`). **Reject** scaffold `Named_CalleeOf_*_anmAnimEvent_004501d0`. **Not** `StdVector_InsertN_BasicString` (`0x004306b0`).
8. **Decompile ≡ raw CF**; **`RET 0x10`** + 4-stack ABI sealed by bytes. Full 854 B hex in raw W34-O section.

### Gaps

- Product demangle for anim-event element / `PTR_FUN_009d4828`.  
- Nested free helpers product English / ownership.  
- Clean is contract-level (not full 854 B EH-state C rewrite).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004501d0_AnimEventVec_InsertN_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004501d0_AnimEventVec_InsertN_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004501d0_FUN_004501d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004501d0_FUN_004501d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimEventVec_InsertN_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004501d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004501d0_FUN_004501d0.md` |
| Function named | `docs/reconstruction/functions/aa_004501d0_AnimEventVec_InsertN_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004501d0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c1960` | Port as **phase method**: ECX=`phase`, bare RET; `new(0x40)` → `FUN_004c1800` → store **`phase+0xc4`** → `FUN_004c0fe0` → activate if `child+0x10!=1`. Do **not** name from NDRiver.fx. Do **not** treat as CreateFluidParticles. Nested ctor/init stay free. |
| `004501d0` | Port as **anim-event vector insert-n**: **4 stack args**, **`RET 0x10`**, stride **0x1c**, max `0x9249249`, 1.5× grow, element-aware copy/assign/destroy. Do **not** use string-vector thiscall ABI (`004306b0`). Sole known caller is resize grow. |
| Pair with | `ParticleFluidPhase_Init_Inferred` (`0x004c2080`, W33-S); `StdVector_Elem28_Size` (`0x00469c50`, W33-J); blend rebind `FUN_004c1a10`; resize parent `FUN_00450050` (unowned). |

### Lifecycle (sealed relative order)

```
// Fluid phase (W33-S + this dual):
phase = new(0xC8) ? FUN_004c0640(parent) : 0
env+0xCC = phase
ParticleFluidPhase_Init(phase, 1)
  → EnsureAuxPtrs / fluid-bump / CreateFluidParticles(0x7fff)
  → ParticleFluidPhase_CreateLiquidChild(phase)   // 004c1960
       → phase[+0xc4] = new(0x40)+FUN_004c1800
       → FUN_004c0fe0 + activate

// Anim-event vector (this dual):
FUN_00450050(vec, newSize)                      // resize (unowned)
  → if size < newSize:
       AnimEventVec_InsertN(vec, end, newSize-size, &value)  // 004501d0
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (liquid child from Init residual + nested VOGEnvironmentLiquid/UIFluid evidence; AnimEventVec from scaffold anmAnimEvent chain + vtbl construct).  
- Rejected scaffold NDRiver / multi-Named_CalleeOf names.  
- Pattern: `docs/agents/task-dual-ab-00442c80-004c2080-w33s-report.md`, `docs/agents/task-dual-ab-004306b0-0040d7c0-w32b-report.md`, `docs/agents/task-dual-ab-00469c50-0043ec50-w33j-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
