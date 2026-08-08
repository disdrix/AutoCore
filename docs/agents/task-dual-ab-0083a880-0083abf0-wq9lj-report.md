# Dual A/B report — WQ9L-J OWN-ONLY (`0x0083a880`, `0x0083abf0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-J**  
**Scope:** VAs `0x0083a880`, `0x0083abf0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; sibling `0x0083a860` (WQ9L-I).  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_wq009_depth9_partition_map.md` → **WQ9L-J**.  
**Work item:** WQ-009 depth-9 residual dual seal — shop reindex helpers (siblings of dualed parent reindex `0x0083ac90`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0083a880` ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred | **accept-with-gaps** — ABI/flag dual-path/default quat/call-site push 0\|1 sealed; product English + residual helpers open |
| `aa_0083abf0` ShopVehList_BindSlotFromListIndexIfMismatch_Inferred | **accept-with-gaps** — ABI/gates/list-container/mismatch-bind/sole-parent sealed; product English + residual helpers open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): thiscall-on-obj / identity-quat / always-Xform / thiscall-on-host / always-rebind / wrong-container claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

**These two VAs are chain siblings** (shop reindex helpers) — not structural twins. `0083abf0` → residual `0083ab90` → `0083a880(1)`; parent reindex also calls `0083a880(0)` directly.

---

## VA `0x0083a880` — sealed facts

1. **Body:** `0x0083a880`–`0x0083a94d` inclusive (**206 B** / `0xCE`); pad `CC CC` then `FUN_0083a950`.
2. **ABI:** **EAX** = slot object*; stack **uint8 flag**; void; **`RET 4`** (`C2 04 00`) both exits.
3. **Semantics:** Apply shopveh **default display quaternion**:
   - Load `DAT_00aaa988/984/980/97c` → local float[4]; `Math_QuatNormalize` (`FUN_0076e5e0`, dualed).
   - Floats: `-0.2244063, 0.0923448, -0.9699135, -0.01934201` (‖q‖≈1.0; **not** identity).
   - **flag == 0:** copy → `obj+0x5e0..+0x5ec`; `obj+0x5dc = 1`; normalize in place.
   - **flag != 0:** thiscall `FUN_0040d1a0(obj+0x510, &local)`; `FUN_00833490`; optional nested vtbl`+0x44` on `obj+0x508`; `FUN_00833390` with EAX=nested.
4. **Classification:** worker.
5. **Xrefs:** 3 UNCONDITIONAL_CALL (`0083ada4`, `0083ade0`, `0083abe4`).
6. **Callees:** `FUN_0076e5e0`×2, `FUN_0040d1a0`, `FUN_00833490`, `FUN_00833390`, vtbl+0x44.
7. **Name:** `ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred` (Ghidra `FUN_0083a880`). Shopveh English from parent graph — `_Inferred`.
8. **Decompile ≡ raw CF**; decompiler omits ECX on `FUN_0040d1a0` — assembly seals thiscall at `obj+0x510`.

### Gaps

- Product demangle for slot class.  
- Residual helpers `00833490` / `00833390` / vtbl`+0x44` English.  
- Default-quat product pose label.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0083a880_FUN_0083a880.md` |
| Annotated | `docs/reconstruction/raw/aa_0083a880_FUN_0083a880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0083a880.cpp` |
| Function | `docs/reconstruction/functions/aa_0083a880_FUN_0083a880.md` |
| Function named | `docs/reconstruction/functions/aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md` |

---

## VA `0x0083abf0` — sealed facts

1. **Body:** `0x0083abf0`–`0x0083ac89` inclusive (**154 B** / `0x9A`); pad `CC`×6 then parent `FUN_0083ac90`.
2. **ABI:** **ECX** = slot index [0..4]; **EDX** = list_i; stack **host***; void; **`RET 4`**.
3. **Semantics:** Conditional **bind slot from list index if mismatch**:
   - Gates: `list_i >= 0`; `host+0x508 != 0`; `slot ∈ [0,5)`; `slots[slot] != 0`; `*(nested+0x50) != 0`.
   - List container: `EDI = nested + 0x2c` for residual `FUN_00427d20(list_i, &entity)`.
   - Entity id: vtbl `+0x1d4` (GetEntityId-like); non-zero required.
   - Bind if `slot+0x508 == 0` **OR** `slot+0x50c != entity_id`; else no-op.
   - Bind action: re-load id into **EAX**; `PUSH host; MOV ECX,slot_obj; CALL FUN_0083ab90`.
4. **Classification:** worker.
5. **Xrefs:** 3 UNCONDITIONAL_CALL — all from `FUN_0083ac90` (`0083ad5a`, `0083adb7`, `0083add0`).
6. **Callees:** `FUN_00427d20`, `FUN_0083ab90`, entity vtbl `+0x1d4`.
7. **Name:** `ShopVehList_BindSlotFromListIndexIfMismatch_Inferred` (Ghidra `FUN_0083abf0`). Shopveh English from parent reindex dual — `_Inferred`.
8. **Decompile ≡ raw CF**; decompiler understates `FUN_0083ab90` ABI — assembly seals ECX/EAX/stack.

### Gaps

- Product demangle for host / slot / entity.  
- Dual of residual `FUN_00427d20` / `FUN_0083ab90` (not OWN).  
- Exact English for entity vtbl `+0x1d4`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0083abf0_FUN_0083abf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0083abf0.cpp` |
| Function | `docs/reconstruction/functions/aa_0083abf0_FUN_0083abf0.md` |
| Function named | `docs/reconstruction/functions/aa_0083abf0_ShopVehList_BindSlotFromListIndexIfMismatch_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0083ac90  ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred  [dualed WQ9K-H]
  ├─ match refresh:
  │     FUN_0083a860  [OWN WQ9L-I — not written here]
  │     FUN_0083a880(flag=0)  [OWN WQ9L-J]
  │     FUN_0083abf0          [OWN WQ9L-J]
  ├─ mismatch + donor:
  │     FUN_00833160  SwapSelectState  [dualed]
  │     FUN_0083a880(flag=0)  [OWN WQ9L-J]
  └─ no donor / post-swap dead path:
        FUN_0083abf0  [OWN WQ9L-J]
          └─ FUN_00427d20 (list by index)  [residual]
          └─ FUN_0083ab90 (bind worker)    [residual]
                └─ FUN_0083a880(flag=1)    [OWN WQ9L-J]
                      └─ Math_QuatNormalize / FUN_0040d1a0 / 833490 / 833390
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0083a880-0083abf0-wq9lj-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0083a880` | Port as **default-orient apply** on shopveh slot object. **EAX=obj**, stack **flag**, **RET 4**. flag0 seeds `+0x5e0` cache + `+0x5dc=1`; flag1 writes Xform via residual `0040d1a0(obj+0x510)`. Default quat from `DAT_00aaa97c` (unit, not identity). Do **not** treat as thiscall on obj. |
| `0083abf0` | Port as **conditional bind-from-list-index**. **ECX=slot**, **EDX=list_i**, stack **host**, **RET 4**. Gate five slots; list container at `*(host+0x508)+0x2c`; bind only on unbound/mismatch via residual `0083ab90`. Do **not** always rebind; do **not** treat as thiscall on host. |
| Pair with | dualed reindex `0083ac90`; dualed swap `00833160`; residual match helper `0083a860` (WQ9L-I); residual bind `0083ab90`; dualed `Math_QuatNormalize` `0076e5e0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md` row  
- `NAMING_REGISTRY.md` entry + rename-history line  
- `systems/skills-abilities.md` residual table entry (depth-9 section)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER / ACTIVE_WORK  

**Terminal:** false.  
**Runtime Confirmed:** not claimed.
