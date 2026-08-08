# Dual A/B report — WQ9D-C OWN-ONLY (`aa_0061b6f0`, `aa_004192a0`)

**Date:** 2026-08-04  
**Agent:** WQ9D-C OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0061b6f0`, `0x004192a0`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth residual dual seal (skill-cast nested callees; skills-abilities).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs/callees + COL/type_info. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0061b6f0` CVOGHBSkill_SharedOnHeartBeat_Inferred | **accept-with-gaps** — multi-class OnHB pulse + effect cascade sealed; nested leaves / field English residual |
| `aa_004192a0` StdTree_Lrotate_Isnil29 | **accept** — Lrotate leaf, isnil@+0x29 / ret 4 sealed |

Path A (fidelity): both **accept** / **accept-with-gaps** as above.  
Path B (adversarial): no CF rejects; OnHB-vs-TryFire residual weakened by Virus vtbl alignment; product English open on skill fields.

---

## Sealed facts — `0x0061b6f0`

1. **Body:** `0x0061b6f0`–`0x0061b955` exclusive (**613** B / `0x265`). Epilogue `add esp,0x18` + **`ret 4`**.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = skill HB object  
   - stack `uint32_t *pOutStatus`  
   - **`ret 4`**

3. **Role (High):** Shared skill **OnHeartBeat** pulse.  
   - Installed at **vtbl+0x08** for many `CVOGHBSkill_*` classes.  
   - RTTI-sampled hosts: **`.?AVCVOGHBSkill_Chain@@`**, **`…_InverseChain@@`**, **`…_Aggregate@@`**.  
   - Also **called** by specialized overrides: `CVOGHBSkill_Virus_OnHeartBeat` (`0x0061fdf0`), range-gated wrapper `FUN_0061ba80`.

4. **High-level CF:**  
   1. `FUN_005787a0` → local status (reschedule / health path residual)  
   2. `this[+0x6c8]++` pulse counter  
   3. If `status != DAT_00af4bd0 (0x10)` ∧ `flag@+0x20==0` ∧ `(state@+0x0c > 1 || == -1000)`:  
      - short@+0x74 → owner `vtbl+0x214` → target `vtbl+0x88` + TFID from `FUN_0061b960` (+0x668)  
      - float@+0x114 → resolve → heat `00589bc0`  
      - flag@+0x44 → `Object_HasFlag8SelfOrLinked` → else `this.vtbl+0x18(1,1)`  
      - bit2@+0x648 → resolve → HP `00589c70`  
      - float@+0x144 → resolve → shield/pool `00589d90`  
      - bit7@+0x649 → resolve → `0058cc40`  
      - bit0@+0x648 → resolve multi-arg → `0058d8e0`  
      - float@+0x110 → resolve + `DAT_00d02ac0` → impulse `0058c3b0`  
      - `this.vtbl+0x50()` post-pulse virtual  
   4. `*pOutStatus = status`

5. **Constants:** `DAT_00af4bd0` = **0x10** (adjacent `"Health"` string at `0x00af4bd8` — English of constant open). Intensity scale `this[+0x6c4]`.

6. **Decompile ≡ raw CF** (live re-verify 2026-08-04).

### Gaps — `0061b6f0`

1. Product field English / effect taxonomy.  
2. Dual of `FUN_005787a0` and effect leaves (not OWN).  
3. Complete RTTI census of all 9 DATA vtbl hosts.  
4. Flag8 MI branch duplication may be decompiler sticky (Probable).  
5. Runtime / stacking / bit-exact open.

---

## Sealed facts — `0x004192a0`

1. **Body:** `0x004192a0`–`0x004192ed` exclusive (**77** B; `CC` pad after last `ret 4`).

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = tree*  
   - stack `node* x`  
   - **`ret 4`** ×3 exits  
   - **Leaf** (0 callees)

3. **Algorithm (classical Lrotate):**  
   `y = x->right (+8)`  
   `x->right = y->left`  
   if `!isnil(y->left)` @ **+0x29**: `y->left->parent = x`  
   `y->parent = x->parent`  
   reattach root / parent.left / parent.right → `y`  
   `y->left = x`; `x->parent = y`

4. **Layout family:** isnil@**+0x29**, color@**+0x28** (same as `Map_EraseNode` / large-node maps). **Not** Val12 (isnil@+0x19).

5. **Name:** `StdTree_Lrotate_Isnil29` — role High; product English **Inferred**.  
   Twin Rrotate: `FUN_004192f0` (sibling OWN partition).  
   Peer: `StdTree_Lrotate_Val12` (`aa_00573170`).

6. **Callers:** 10 functions / **21** UNCONDITIONAL_CALL xrefs including `Map_EraseNode` (`0051cb40`), insert/rebalance, aggro paths.

7. **Decompile ≡ bytes** (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps — `004192a0`

1. Product/PDB demangle per map type.  
2. Exact value payload English (+0x0c … color).  
3. Twin `004192f0` dual (sibling OWN).  
4. Runtime / bit-exact open.

---

## Files

### `aa_0061b6f0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0061b6f0_CVOGHBSkill_SharedOnHeartBeat_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0061b6f0_FUN_0061b6f0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_SharedOnHeartBeat_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0061b6f0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0061b6f0_FUN_0061b6f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0061b6f0_FUN_0061b6f0.annotated.md` |

### `aa_004192a0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004192a0_StdTree_Lrotate_Isnil29.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004192a0_StdTree_Lrotate_Isnil29.md` |
| Function record | `docs/reconstruction/functions/aa_004192a0_StdTree_Lrotate_Isnil29.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004192a0_FUN_004192a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Lrotate_Isnil29.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004192a0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004192a0_FUN_004192a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004192a0_FUN_004192a0.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0061b6f0-004192a0-wq9dc-report.md` |

---

## AutoCore impact

### `0061b6f0`

- Port skill HB default tick as **shared pulse**: reschedule/status → counter++ → gated effect cascade → `vtbl+0x50` → out status.  
- Specialized skills (Virus, range-gated) **compose** this rather than reimplementing the cascade.  
- Do not confuse with cast entry managers — this is **post-cast HB tick**.  
- Parent merge should register RTTI multi-host name + skills-abilities row (out of agent scope).

### `004192a0`

- Port map erase/rebalance Lrotate for **isnil@+0x29** nodes only — do not reuse Val12 (`+0x19`) rotate on this family.  
- Keep paired with Rrotate twin `004192f0` in insert/erase rebalance.  
- Shared STL helper — not skill-domain exclusive.

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (for `0061b6f0`; tree helper may stay STL)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).
