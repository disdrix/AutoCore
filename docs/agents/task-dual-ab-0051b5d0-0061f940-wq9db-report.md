# Dual A/B report — WQ9D-B OWN-ONLY (`aa_0051b5d0`, `aa_0061f940`)

**Date:** 2026-08-04  
**Agent:** WQ9D-B OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051b5d0`, `0x0061f940`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth residual dual seal (skills-abilities nested callees, priority 93 lineage).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs/callees + function meta. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051b5d0` StdTree_Min_Isnil29 | **accept** — leftmost / isnil@+0x29 / EAX return sealed; decompiler void hazard closed |
| `aa_0061f940` CVOGHBSkill_Virus_Ctor | **accept** — RTTI Virus + vtbl + budget/period ctor CF sealed |

Path A (fidelity): both **accept** as above.  
Path B (adversarial): no CF rejects; product English residual only on Virus design (class name Confirmed).

---

## Sealed facts — `0x0051b5d0`

1. **Body:** `0x0051b5d0`–`0x0051b5ea` inclusive (**27 B** / `0x1b`). `CC` pad to next @ `0x0051b5f0`.

2. **ABI:** MSVC stack arg (**`__cdecl`-style** bare `ret`).  
   - Stack: `Node *node`  
   - **`EAX = leftmost non-nil`**  
   - Ghidra `void` display is **wrong** (same hazard class as `StdTree_Min_Val12`).

3. **Algorithm:** MSVC **`_Tree_min`**  
   - `left = node->left`  
   - if `left->isnil` (**`+0x29`**) → return `node`  
   - else walk left while child `!isnil`; return last non-nil  
   - **No stores, no callees, no right-child walk.**

4. **Role:** Leaf **leftmost** helper for isnil@+0x29 map/set erase.  
   Callers (5 UNCONDITIONAL_CALL):  
   `FUN_00409220`, `Map_EraseNode`/`FUN_0051cb40`, `FUN_004cb740`, `FUN_0058dc30`, `FUN_00603830`  
   (erase family; `"invalid map/set<T> iterator"`).

5. **Name:** `StdTree_Min_Isnil29` — role High.  
   Twin: `StdTree_Min_Val12` (`0x005adfa0`, isnil @ +0x19).  
   Supersedes scaffold `Named_CalleeOf_…Aggro_0051b5d0`.

6. **Decompile body ≡ raw 2026-07-23**; **return semantics from live bytes 2026-08-04**.

### Gaps — `0051b5d0`

1. Product/PDB symbol.  
2. Exact value payload width for this node class.  
3. Runtime / bit-exact open.  
4. Rightmost peer `FUN_00421b50` not OWN.

---

## Sealed facts — `0x0061f940`

1. **Body:** `0x0061f940`–`0x0061f998` inclusive (**89 B** / `0x59`); **`ret 0x20`**.

2. **Identity (Confirmed):**  
   - RTTI **`.?AVCVOGHBSkill_Virus@@`** (type_info `0x00af2b08`)  
   - Installs vtbl **`PTR_FUN_009d14bc`**  
   - Vtbl **[+0x0c] = `0x0061fdf0`** = `CVOGHBSkill_Virus_OnHeartBeat`  
   - Object size **`0x6e0`** (`operator_new` at sole CALL site)

3. **Name:** `CVOGHBSkill_Virus_Ctor` — class **Confirmed**, ctor role **High**.

4. **High-level CF:**  
   1. `FUN_00618180(p2..p7, 0, 1.0f)` intermediate base (thiscall ECX=this)  
   2. `this+0x6d0 = remainBudget` (param_8) — multi-spread budget  
   3. `*this = PTR_FUN_009d14bc`  
   4. `this+0x6d4 = remainPeriod` (param_9)  
   5. `CVOGHBBase_SetPeriodAndCounter(this, remainPeriod, true)`  
   6. return `this`

5. **Sole CALL:** `CVOGHBSkill_Virus_OnHeartBeat` @ `0x0062008d` (child-spawn after ally gather).  
   OnHeartBeat decrements `+0x6d0`/`+0x6d4` before constructing children — matches field roles.

6. **Decompile ≡ raw CF** (live re-verify 2026-08-04).

### Gaps — `0061f940`

1. Product design English for “Virus” beyond RTTI.  
2. Field English for base-ctor args / `arg7` / skill blob.  
3. Dual of intermediate base `FUN_00618180` / pulse `FUN_0061b6f0` (other partitions).  
4. Runtime / stacking / bit-exact open.

---

## Files

### `aa_0051b5d0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051b5d0_StdTree_Min_Isnil29.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051b5d0_StdTree_Min_Isnil29.md` |
| Function record | `docs/reconstruction/functions/aa_0051b5d0_StdTree_Min_Isnil29.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0051b5d0_FUN_0051b5d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Min_Isnil29.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0051b5d0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051b5d0_FUN_0051b5d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b5d0_FUN_0051b5d0.annotated.md` |

### `aa_0061f940`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0061f940_CVOGHBSkill_Virus_Ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0061f940_CVOGHBSkill_Virus_Ctor.md` |
| Function record | `docs/reconstruction/functions/aa_0061f940_CVOGHBSkill_Virus_Ctor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0061f940_FUN_0061f940.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_Virus_Ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0061f940.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0061f940_FUN_0061f940.md` |
| Annotated | `docs/reconstruction/raw/aa_0061f940_FUN_0061f940.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051b5d0-0061f940-wq9db-report.md` |

---

## AutoCore impact

### `0051b5d0`

- Port map erase Lmost recompute as **leftmost walk with isnil @ +0x29**, not Val12 (+0x19).  
- Correct Ghidra void: **returns node\***.  
- Shared by skill-related erase (`Map_EraseNode`) and other map instantiations — keep as **generic tree helper**, not skill-only API.

### `0061f940`

- Virus multi-spread factory: **`new(0x6e0)` + this ctor + Enqueue(world+0xe4ec) + Start**.  
- Preserve **budget @ +0x6d0** and **period @ +0x6d4** for child HB lifetime.  
- Do not substitute a non-Virus HB ctor; vtbl must be **`PTR_FUN_009d14bc`**.

---

## Parent merge notes (for parent only — not edited here)

When lockstep runs, for both VAs:

1. `VERIFICATION_MATRIX.md` rows → partial dual sealed.  
2. `NAMING_REGISTRY.md` + rename history:  
   - `FUN_0051b5d0` → `StdTree_Min_Isnil29`  
   - `FUN_0061f940` → `CVOGHBSkill_Virus_Ctor`  
3. `systems/skills-abilities.md` residual table (Virus ctor; tree min as cross-cutting erase helper).  
4. WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER.

**Terminal:** false (partition partial; 18 other OWN VAs concurrent).
