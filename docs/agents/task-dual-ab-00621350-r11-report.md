# Dual A/B report — R11-017 OWN-ONLY (`aa_00621350`)

**Date:** 2026-08-05  
**Agent:** R11-017 OWN-ONLY dual  
**Scope:** OWN ONLY VA `0x00621350` (`FUN_00621350`). Dual A/B + trio raw/annotated/clean + function records.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md`  
**System:** skills-abilities  
**Parent:** `0x005788d0` `CVOGHBSkillBase_ctor`  
**Excluded:** Launcher; parent ledgers (WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY); other VAs; `disassemble_bytes`; inventing non-RTTI product names; wiping raw.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs/callees + `get_function_by_address` + `audit_globals_in_function`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** false  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00621350` CVOGHBSkill_OnDoHit_Ctor | **accept** — RTTI OnDoHit + vtbl + base-then-vtbl ctor CF/ABI sealed |

Path A (fidelity): **accept** — clean ≡ raw ≡ live.  
Path B (adversarial): **accept** — no CF rejects; product English residual only (class name Confirmed).

---

## Sealed facts — `0x00621350`

1. **Body:** `0x00621350`–`0x00621383` inclusive (**52 B** / `0x34`). `CC` pad after `ret 0x18`.

2. **ABI:** MSVC **`__thiscall`**.  
   - ECX = `this`  
   - Stack: 6 args (`pSourceObj`, `pSkillBlob`, `arg4`, `pTarget`, `pTfid16`, `arg7`)  
   - Terminal **`ret 0x18`**  
   - **`EAX = this`**

3. **Identity (Confirmed):**  
   - RTTI **`.?AVCVOGHBSkill_OnDoHit@@`** (type_info `0x00af1d80`, name @ `0x00af1d88`)  
   - COL **`0x00aae1a0`** at vtbl-4 of **`PTR_FUN_009d15c4`**  
   - Installs vtbl **`0x009d15c4`** after parent base ctor

4. **Name:** `CVOGHBSkill_OnDoHit_Ctor` — class **Confirmed**, ctor role **High**.  
   Supersedes scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_00621350` (caller-string alias only).

5. **High-level CF:**  
   1. `CVOGHBSkillBase_ctor(this, p2..p7)` @ `0x005788d0`  
   2. `*this = PTR_FUN_009d15c4`  
   3. `return this`  
   **No branches; no extra field stores.**

6. **Callers (2 UNCONDITIONAL_CALL):**  
   - `FUN_00621f50` @ `0x00621fe9` — `operator_new(0x6d0)` then this ctor then upgrades vtbl → `009d1624`  
   - `FUN_006235e0` @ `0x0062361e` — subclass ctor upgrades vtbl → `009d185c` + creature cast  

7. **Callee:** sole `CVOGHBSkillBase_ctor` / `FUN_005788d0`.

8. **Decompile ≡ raw CF** (live re-verify 2026-08-05; Ghidra shows renamed parent symbol).

### Gaps — `00621350`

1. Product design English for “OnDoHit” beyond RTTI.  
2. Full vtbl method map for `PTR_FUN_009d15c4`.  
3. Dual of callers / pure object size when not further subclassed.  
4. Runtime / bit-exact open.

---

## Files

### `aa_00621350`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00621350_CVOGHBSkill_OnDoHit_Ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00621350_CVOGHBSkill_OnDoHit_Ctor.md` |
| Function record (named) | `docs/reconstruction/functions/aa_00621350_CVOGHBSkill_OnDoHit_Ctor.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00621350_FUN_00621350.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnDoHit_Ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00621350.cpp` |
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_00621350_FUN_00621350.md` |
| Annotated | `docs/reconstruction/raw/aa_00621350_FUN_00621350.annotated.md` |
| This report | `docs/agents/task-dual-ab-00621350-r11-report.md` |

---

## Compliance

| Rule | Status |
|------|--------|
| Exclusive VA `0x00621350` only | **Held** |
| No parent ledgers | **Held** |
| No Launcher | **Held** |
| No `disassemble_bytes` | **Held** |
| No invent names (RTTI only) | **Held** |
| Raw append-only (no wipe) | **Held** |
| Terminal false | **Held** |
