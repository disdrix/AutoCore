# Dual A/B report — W26-A OWN `aa_0040d3f0` + `aa_00416260`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-A  
**Scope:** VAs `0x0040d3f0`, `0x00416260` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` (callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Parent:** nested callees of sealed `Math_FloatNearlyEqual_AbsRel` (`0x0040d450`, W25-T).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d3f0` Math_Vec3NearlyEqual_AbsRel | **accept** — 3-comp short-circuit CF + ESI/EDI+RET8 ABI sealed |
| `aa_00416260` Math_QuatNearlyEqual_DoubleCover | **accept** — q / −q dual path CF + same ABI family sealed |

---

## VA `0x0040d3f0` — sealed facts

1. **Body:** `0x0040d3f0`–`0x0040d44a` (**91 B**; pad `CC` to leaf at `0x0040d450`).
2. **ABI:** **ESI** = `const float *a` (vec3); **EDI** = `const float *b` (vec3); stack `relTol, absTol`; **`RET 8`**; **EAX** = 0|1. EBX/EBP used as tol scratch (pushed/popped).
3. **Semantics:** True iff all three components pass `Math_FloatNearlyEqual_AbsRel(b[i], a[i], rel, abs)`; short-circuit on first fail.
4. **Classification:** worker; sole callee `FUN_0040d450` ×3.
5. **Caller (1 xref):** `FUN_0090f490` @ `0x0090f625` — `LEA ESI,[EAX+0x90]`, `LEA EDI,[EBX+0x4fc]`, both tols `0x358637BD` ≈ **1e-6**.
6. **Name:** `Math_Vec3NearlyEqual_AbsRel` (Ghidra `FUN_0040d3f0`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Runtime FPU CW / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d3f0_Math_Vec3NearlyEqual_AbsRel.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040d3f0_Math_Vec3NearlyEqual_AbsRel.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d3f0_FUN_0040d3f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d3f0_FUN_0040d3f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_Vec3NearlyEqual_AbsRel.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d3f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d3f0_FUN_0040d3f0.md` |
| Function named | `docs/reconstruction/functions/aa_0040d3f0_Math_Vec3NearlyEqual_AbsRel.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d3f0.md` |

---

## VA `0x00416260` — sealed facts

1. **Body:** `0x00416260`–`0x0041634e` (**239 B**; pad `CC` after last RET).
2. **ABI:** same family as vec3 — **ESI**=`a`, **EDI**=`b` (float4 xyzw), stack rel/abs, **`RET 8`**, **EAX** 0|1.
3. **Semantics:** True if `b≈a` **or** `b≈-a` under abs+rel on all four components (order **w,x,y,z**). Negation via SSE `XORPS`/`SUBSS` of ESI components.
4. **Classification:** worker; sole callee `FUN_0040d450` ×8.
5. **Caller (1 xref):** `FUN_008335a0` @ `0x008335da` — stack copy of quat `@+0x590` in ESI, EDI=`@+0x5e0`, both tols `0x3B03126F` = **0.002f**; on true clears byte `@+0x5dc`.
6. **Name:** `Math_QuatNearlyEqual_DoubleCover` (Ghidra `FUN_00416260`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / original name.  
- Axis English labels conventional (w at [3]).  
- Runtime bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416260_Math_QuatNearlyEqual_DoubleCover.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00416260_Math_QuatNearlyEqual_DoubleCover.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00416260_FUN_00416260.md` |
| Annotated | `docs/reconstruction/raw/aa_00416260_FUN_00416260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_QuatNearlyEqual_DoubleCover.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416260.cpp` |
| Function | `docs/reconstruction/functions/aa_00416260_FUN_00416260.md` |
| Function named | `docs/reconstruction/functions/aa_00416260_Math_QuatNearlyEqual_DoubleCover.md` |
| Scratch | `docs/reconstruction/tmp/a_00416260.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d3f0` | Port vec3 nearness as three dual-gate scalar tests (not pure `\|a-b\|<eps`). Preserve short-circuit. Common client eps ~**1e-6**. Register ABI is custom — use portable C formals in ports. |
| `00416260` | Port quat equality **with double-cover** (`q` and `-q`). Do not use component-only positive path. Observed client eps **0.002f**. Closes residual left open by W25-T leaf dual (caller roles). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + call-site assembly context.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Avoided bare `undefined4` in clean C++ (`uint32_t` / `float`).
