# Dual A/B report — W26-H OWN `aa_004b7330` + `aa_004b4620`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-H  
**Scope:** VAs `0x004b7330`, `0x004b4620` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004b7330` NDSpecialFX_LivenessDone_Inferred | **accept** — leaf CF + plain RET + AL 0\|1 + HostTick polarity sealed |
| `aa_004b4620` ObjectMotion_SlotTick_Inferred | **accept-with-gaps** — outer tick CF/ABI/constants + integrate linkage sealed; nested helper English open |

---

## VA `0x004b7330` — sealed facts

1. **Body:** `0x004b7330`–`0x004b73bc` (**140 B / `0x8C`**; pad `CC` after last RET).
2. **ABI:** ECX = fx host; **no stack formals**; plain **`RET`** (`C3`); **AL** = 0\|1.
3. **Classification:** **leaf** (0 callees, 0 globals).
4. **Semantics:** Done when host residual (`+9`, `+0xA`, `+0x1E4`, `+0x214`) clear, owned list `+0x204` all payloads have `+0x795 != 0`, and optional secondary list `+0x1EC` has no `+0x10B` active under `+0x1F0`/`+6/+7/+8` gate.
5. **Caller (1):** `NDSpecialFX_HostTick_Inferred` (`FUN_004b8ed0`) @ `0x004b8f55` — non-zero → DeactivateClear + return 1.
6. **Name:** `NDSpecialFX_LivenessDone_Inferred` (Ghidra `FUN_004b7330`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Semantic labels of flag bytes beyond polarity.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b7330_NDSpecialFX_LivenessDone_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004b7330_NDSpecialFX_LivenessDone_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b7330_FUN_004b7330.md` |
| Annotated | `docs/reconstruction/raw/aa_004b7330_FUN_004b7330.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_LivenessDone_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b7330.cpp` |
| Function | `docs/reconstruction/functions/aa_004b7330_FUN_004b7330.md` |
| Function named | `docs/reconstruction/functions/aa_004b7330_NDSpecialFX_LivenessDone_Inferred.md` |

---

## VA `0x004b4620` — sealed facts

1. **Body:** `0x004b4620`–`0x004b490d` (**749 B / `0x2ED`**). Frame `SUB ESP,0x28`.
2. **ABI:** **`__thiscall`** ECX = motion slot; stack `(flag, dt)`; epilogue **`ret 8`** (`C2 08 00`); **AL** 0\|1.
3. **Profiler:** `*(DAT_00d17958 + 0x13c)++`.
4. **Caller (1):** `FUN_005bb5e0` @ `0x005bb611` — return 0 → unlink + `operator_delete` list node.
5. **Callees:** `FUN_004b0f80`×2, `FUN_004cd220`×2 (`CVOGMap_SampleHeightfieldY`), `FUN_0076f5f0`, `FUN_004b2b90`, `FUN_004b1100` (`ObjectMotion_IntegrateStep_Inferred` W24-C), `FUN_004b18f0`.
6. **Data / constants (`read_memory`):**
   - `DAT_00a0f720` = **0.4** (`3ECCCCCD`)
   - `DAT_00aaa6cc` = **−0.5** (`BF000000`)
   - `DAT_009c8354` ≈ **0.99** (`3F7D70A4`)
   - `g_flZero` for radius-null compare
7. **CF stages:** host abort → optional radius pull (Y damp + normalize + r·0.99 + optional HF Y) → primary duration → secondary timer → `004b2b90` → integrate → optional `004b18f0` → clear `+0x240` → return 1.
8. **Name:** `ObjectMotion_SlotTick_Inferred` (Ghidra `FUN_004b4620`).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / class of motion slot.  
- Nested helpers `FUN_004b0f80` / `FUN_004b2b90` / `FUN_004b18f0` / `FUN_0076f5f0` (not OWN).  
- Runtime post-pull pose bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b4620_ObjectMotion_SlotTick_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004b4620_ObjectMotion_SlotTick_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b4620_FUN_004b4620.md` |
| Annotated | `docs/reconstruction/raw/aa_004b4620_FUN_004b4620.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotTick_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b4620.cpp` |
| Function | `docs/reconstruction/functions/aa_004b4620_FUN_004b4620.md` |
| Function named | `docs/reconstruction/functions/aa_004b4620_ObjectMotion_SlotTick_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004b7330` | HostTick **must** treat non-zero as **done** (DeactivateClear). Do not invert. Leaf — no free side effects. |
| `004b4620` | Outer slot tick owns radius/timer policy **before** IntegrateStep. Preserve **ret 8** + 0/1 remove contract. Constants **0.4 / −0.5 / ≈0.99** must match image. `param_2` is **int flag**, not a float distance. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b8ed0` | `NDSpecialFX_HostTick_Inferred` (W24-C) — sole liveness caller |
| `0x004b7150` | `NDSpecialFX_DeactivateClear_Inferred` (W23-H) |
| `0x004b1100` | `ObjectMotion_IntegrateStep_Inferred` (W24-C) — nested integrate |
| `0x004cd220` | `CVOGMap_SampleHeightfieldY` |
| `0x005bb5e0` | list walker sole caller of SlotTick |
| `0x004b0f80` / `0x004b2b90` / `0x004b18f0` | residual slot helpers |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
