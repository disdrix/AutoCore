# Dual A/B report — MEGA-071 OWN-ONLY (`0x006c7fa0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-071**  
**Scope:** VA `0x006c7fa0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-071**.  
**Work item:** Mega residual dual seal — sphere-shape setup (mode-2 of dualed GetObjectsInArea).  
**Hint retired:** `Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0` plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006c7fa0` PhysicsShape_Sphere_CtorFromRadius_Inferred | **accept-with-gaps** — leaf thiscall RET4 / 0x10 sphere layout / vtbl `00a0d610` / radius@+0xc / 18 callers sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG_DEBUG_STOP-callee / box-capsule / non-thiscall / flags-not-radius / non-leaf claims **falsified**; Named_CalleeOf scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x006c7fa0` — sealed facts

1. **Body:** `0x006c7fa0`–`0x006c7fbc` (**29 B** / `0x1D`); terminal **`C2 04 00`**; `CC` pad @ `0x006c7fbd`.
2. **ABI:** **`__thiscall`**; **ECX** = shape*; stack **float radius**; **EAX** = this; **`RET 4`**.
3. **Semantics:** leaf sphere shape ctor/setup:
   - `word[this+0x06] = 1` (refcount)
   - `dword[this+0x08] = 0`
   - `float[this+0x0c] = radius`
   - `*this = PTR_FUN_00a0d610`
4. **Object size:** **0x10** (call-site alloc `(0x10, 0x22)`; parent tags `word[+4]=0x10`).
5. **Sphere proof (vtbl evidence):**  
   - `006c7f20` AABB expand by radius@+0xc  
   - `006c7c30` support + radius  
   - `006c7fc0` ray-sphere (`r*r` @ +0xc)
6. **Callers:** **17** functions / **18** UNCONDITIONAL_CALL (see function record).
7. **Callees:** **none** (leaf).
8. **Product parent:** dualed `CVOGPhysicsUtils_GetObjectsInArea` (`0x004ea350`) **mode `param_5==2`** @ `0x004ea6ce`.
9. **Name:** `PhysicsShape_Sphere_CtorFromRadius_Inferred` (Ghidra `FUN_006c7fa0`). Product demangle open → `_Inferred`.
10. **Decompile ≡ raw CF ≡ body hex**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product / PDB demangle for shape class (no RTTI on body).  
- Field @+0x08 English.  
- Full vtbl method English beyond sphere-proof subset.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.md` |
| Annotated | `docs/reconstruction/raw/aa_006c7fa0_FUN_006c7fa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysicsShape_Sphere_CtorFromRadius_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006c7fa0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_006c7fa0.cpp` |
| Function | `docs/reconstruction/functions/aa_006c7fa0_FUN_006c7fa0.md` |
| Function named | `docs/reconstruction/functions/aa_006c7fa0_PhysicsShape_Sphere_CtorFromRadius_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGPhysicsUtils_GetObjectsInArea  FUN_004ea350  [dualed]
  ├─ mode==1: box/list path (FUN_00581220 / FUN_0055ff20)  [residual]
  ├─ mode==2: sphere path
  │     alloc(0x10, 0x22); tag +4=0x10
  │     FUN_006c7fa0(radius)  PhysicsShape_Sphere_CtorFromRadius_Inferred  [OWN MEGA-071]
  │     FUN_005eb8d0 / center copy / FUN_005ebec0 collector  [residual]
  └─ else: AABB default + "CVOGPhysicsUtils::GetObjectsInArea::aabb"
        (VOG_DEBUG_STOP only on dead AABB world — NOT a caller of 006c7fa0)

Sphere vtbl PTR_FUN_00a0d610  [evidence only]
  ├─ [0] FUN_006c6490  dtor/release
  ├─ [6] FUN_006c7f20  AABB ± radius
  ├─ [7] FUN_006c7c30  support + radius
  └─ [8] FUN_006c7fc0  ray-sphere

Other OWN residual callers (not dualled here):
  FUN_004e9720 / 004e9aa0 / 004ed470 / 004ee080 / 005f* / 006ec* cluster
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-006c7fa0-mega-071-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006c7fa0` | Port as **sphere shape ctor-from-radius**. **thiscall RET 4**. Object **0x10** bytes; vtbl `00a0d610`; radius float @**+0x0c**; refcount u16 @**+0x06**. |
| Alloc pattern | Parent: heap `(0x10, 0x22)` then `word[+4]=0x10` then thiscall. |
| Distinct from | AABB default GetObjectsInArea path; mode-1 box path; VOG_DEBUG_STOP fail helper. |
| Pair with | dualed GetObjectsInArea `004ea350`; residual collector `005ebec0`; residual AABB inflate `006c7f20` / ray `006c7fc0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `PhysicsShape_Sphere_CtorFromRadius_Inferred` @ `0x006c7fa0` / `aa_006c7fa0`.
- System residual: interaction-activation / physics shape (not skill-specific).
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x006c7fa0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + call-site context + vtbl method decompiles (evidence). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_006c7fa0.cpp` kept; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: vtbl written last; size tag@+4 is parent-owned; decompiler void return corrected to EAX=this via assembly.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
