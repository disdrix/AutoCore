# Dual A/B report — W27-A OWN `aa_0090f490` + `aa_008335a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-A  
**Scope:** VAs `0x0090f490`, `0x008335a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_assembly_context` (callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Parent:** nested callers of sealed `Math_Vec3NearlyEqual_AbsRel` (`0x0040d3f0`) and `Math_QuatNearlyEqual_DoubleCover` (`0x00416260`) — W26-A.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090f490` FUN_0090f490 | **accept** — EBX+`RET 4` ABI; far/near CF; sealed vec3 near-equal gate @ `0x0090f625` |
| `aa_008335a0` FUN_008335a0 | **accept** — EBX host ABI; sealed quat double-cover early-out; slerp 0.25 + orient write |

---

## VA `0x0090f490` — sealed facts

1. **Body:** `0x0090f490`–`0x0090f8d3` (**1092 B** / `0x444`; pad `CC` after last RET).
2. **ABI:** **EBX** = host object; stack `param_1` optional object*; **`RET 4`**; void.
3. **Semantics:** Pose-track worker. Default `@+0x544` to **0.1f** if zero. If related `@+0xa20` non-null:
   - Far (dist to live `@+0x90` ≥ 0.1): gate with `Math_Vec3NearlyEqual_AbsRel` (live vs cache `@+0x4fc`, both tols ≈ **1e-6**). On miss: refresh cache, rebuild basis (normalize×3, cross with **−1.0f**), matrix→quat, write orient/pos; optional `param_1` vfunc `+0x10`(3).
   - Near: if secondary vector length > plate **20.0f**, snap zero-rot + global pos.
4. **Classification:** worker.
5. **Sealed callee:** `FUN_0040d3f0` / `Math_Vec3NearlyEqual_AbsRel` @ call `0x0090f625` — `LEA ESI,[EAX+0x90]`, `LEA EDI,[EBX+0x4fc]`, both tols `0x358637BD`.
6. **Callers:** **no static xrefs** (indirect / vtable).
7. **Name:** keep `FUN_0090f490` (no product string).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / class name.  
- Direct caller table (indirect dispatch).  
- Exact ECX at every pose-write site (Medium).  
- Runtime FPU CW / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090f490_FUN_0090f490.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0090f490_FUN_0090f490.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0090f490_FUN_0090f490.md` |
| Annotated | `docs/reconstruction/raw/aa_0090f490_FUN_0090f490.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0090f490.cpp` |
| Function | `docs/reconstruction/functions/aa_0090f490_FUN_0090f490.md` |
| Scratch | `docs/reconstruction/tmp/a_0090f490.md` |

---

## VA `0x008335a0` — sealed facts

1. **Body:** `0x008335a0`–`0x0083363b` (**156 B**; pad `CC` after last RET).
2. **ABI:** **EBX** = host (caller `MOV EBX,ECX`); no stack formals; void; `ADD ESP,0x10; RET`.
3. **Semantics:** Copy quat `@+0x590` → stack. If `Math_QuatNearlyEqual_DoubleCover(stack, @+0x5e0, 0.002, 0.002)` → clear `@+0x5dc` and return. Else slerp toward target with **t = 0.25**, `FUN_0040d1a0(ECX=host+0x510)`, `FUN_00833490`, optional `[*+0x508]+0x44`, `FUN_00833390`.
4. **Classification:** worker.
5. **Sealed callee:** `FUN_00416260` / `Math_QuatNearlyEqual_DoubleCover` @ call `0x008335da` — ESI=stack copy, EDI=`@+0x5e0`, both tols `0x3B03126F` = **0.002f**.
6. **Caller (1 xref):** `FUN_00833a30` @ `0x00833a3d` — gates on `@+0x5dc != 0`.
7. **Name:** keep `FUN_008335a0` (no product string).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23); full body hex captured.

### Gaps

- Product English / class name.  
- Full roles of siblings `FUN_00833490` / `FUN_00833390` (not owned).  
- Runtime bit-exact slerp — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008335a0_FUN_008335a0.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_008335a0_FUN_008335a0.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008335a0_FUN_008335a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008335a0_FUN_008335a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_008335a0.cpp` |
| Function | `docs/reconstruction/functions/aa_008335a0_FUN_008335a0.md` |
| Scratch | `docs/reconstruction/tmp/a_008335a0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090f490` | Port far-path with **abs+rel vec3 nearness** (not pure epsilon length) before pose rebuild. Cache field `@+0x4fc`. Common eps **~1e-6**. Distance threshold **0.1f**. Register host ABI → use portable host pointer in ports. |
| `008335a0` | Port orientation step with **double-cover** early-out at **0.002f**, then slerp **t=0.25** toward target `@+0x5e0`. Pending flag `@+0x5dc` is caller-set / clear-on-done. Closes residual left open by W26-A quat dual (caller roles). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + call-site assembly context.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Avoided bare `undefined4` in clean C++ (`uint32_t` / `float` / `uint8_t`).  
- No invented product names — canonical remains `FUN_*`.
