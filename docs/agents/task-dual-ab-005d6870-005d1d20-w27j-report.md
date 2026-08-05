# Dual A/B report — W27-J OWN `aa_005d6870` + `aa_005d1d20`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-J  
**Scope:** VAs `0x005d6870`, `0x005d1d20` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005d6870` Math_Float3_IsFiniteIEEE_Inferred | **accept** — thiscall float3 Inf/NaN gate; mask `0x7f800000`; bound 3; RET 4; leaf sealed |
| `aa_005d1d20` Math_QuatExtractForwardZ_OutFirst_Inferred | **accept** — cdecl (out, quat) +Z extract; consts 2.0/1.0; algebra ≡ `0x004e8a40` with swapped args |

---

## VA `0x005d6870` — sealed facts

1. **Body:** `0x005d6870`–`0x005d68ab` (60 B; `RET 0x4` ×2; pad `CC` to sibling `0x005d68b0`).
2. **ABI:** **ECX** = `float[3]*`; stack `uint8_t *outOk`; void; EAX residual often = outOk*.
3. **Semantics:** For `i∈{0,1,2}`, if `(as_u32(v[i]) & 0x7f800000) == 0x7f800000` → `*outOk=0` return; else `*outOk=1`.
4. **Not:** unit-length, magnitude, denorm reject, four-component (sibling `Math_Float4_IsFiniteIEEE_Inferred` @ `0x005d68b0`).
5. **Callers (live xrefs):** `VehicleAction_applyAction`, `FUN_005cedf0`, `FUN_004e8dc0`, `FUN_004e9060`, `FUN_004c6360`, `FUN_00517680`, `FUN_0053d170`, `FUN_005c2030`, `FUN_004dcb80`×3, `FUN_004deb20`, `FUN_004dfcc0`, `0x0060644c`.
6. **Name:** `Math_Float3_IsFiniteIEEE_Inferred` (Ghidra `FUN_005d6870`; **Inferred** — mirrors sealed float4 sibling naming).
7. **Decompile ≡ bytes** for CF (hex path: MOVSS spill → AND/CMP mask → out store).

### Gaps

- Product/PDB English symbol.
- Runtime golden samples.
- Per-caller product narratives beyond gate role.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d6870_Math_Float3_IsFiniteIEEE_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005d6870_Math_Float3_IsFiniteIEEE_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d6870_FUN_005d6870.md` |
| Annotated | `docs/reconstruction/raw/aa_005d6870_FUN_005d6870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005d6870.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/Math_Float3_IsFiniteIEEE_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_005d6870_FUN_005d6870.md` |
| Function named | `docs/reconstruction/functions/aa_005d6870_Math_Float3_IsFiniteIEEE_Inferred.md` |

---

## VA `0x005d1d20` — sealed facts

1. **Body:** `0x005d1d20`–`0x005d1d93` (116 B; bare `RET`; pad `CC`).
2. **ABI:** **cdecl** — `param_1` = out `float[4]*`, `param_2` = quat `float[4]*` XYZW.
3. **Semantics:** rotation-matrix **column 2** (local +Z → world), W forced 0:
   - `out.x = 2*(xz + yw)`
   - `out.y = 2*(yz - xw)`
   - `out.z = 1 - 2*(x² + y²)`
   - `out.w = 0`
4. **Constants (`read_memory`):** `0x00a10e74` = **2.0f**; `0x00a0f2a0` / `g_flOne` = **1.0f**. Ghidra UI name on 2.0 pool is a misnomer.
5. **Twin algebra:** sealed `Math_QuatExtractForwardZ` @ `0x004e8a40` — **same formula**, args **(quat, out)** vs this **(out, quat)**.
6. **Callers:** sole live xref `FUN_005cedf0` / `CVOGHBAI_UpdateAimOffset_Inferred` @ `0x005cf312`.
7. **Name:** `Math_QuatExtractForwardZ_OutFirst_Inferred` (Ghidra `FUN_005d1d20`; **Inferred**).
8. **Leaf:** no callees; single block; no normalize.

### Gaps

- Product/PDB English symbol.
- Runtime golden (identity / 90° yaw) optional.
- Historical reason for duplicate +Z extract — not required for seal.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d1d20_Math_QuatExtractForwardZ_OutFirst_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005d1d20_Math_QuatExtractForwardZ_OutFirst_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d1d20_FUN_005d1d20.md` |
| Annotated | `docs/reconstruction/raw/aa_005d1d20_FUN_005d1d20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005d1d20.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/Math_QuatExtractForwardZ_OutFirst_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_005d1d20_FUN_005d1d20.md` |
| Function named | `docs/reconstruction/functions/aa_005d1d20_Math_QuatExtractForwardZ_OutFirst_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005d6870` | Preserve thiscall + RET 4; mask-only Inf/NaN reject on **3** floats; out byte polarity 1=ok; do not substitute float4 sibling or `isfinite` denorm policy without audit. |
| `005d1d20` | Preserve cdecl **(out, quat)** order — do not call through `0x004e8a40` ABI without swapping; +Z only; force W=0; use 2.0/1.0 factors; no normalize. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits; no cross-agent VA writes.
- Tools: `decompile_function` + `read_memory` (+ callers/xrefs). No `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed per VA.
- Names **Inferred** from sealed sibling families (`Math_Float4_IsFiniteIEEE_Inferred`, `Math_QuatExtractForwardZ`); no invented product strings without evidence.
- Bare `undefined4` avoided in clean (`uint32_t` / `uint8_t` / `float`).
- This report: `docs/agents/task-dual-ab-005d6870-005d1d20-w27j-report.md`
