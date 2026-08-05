# Dual A/B report — W28-S OWN `aa_00629d90` + `aa_0053a260`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-S  
**Scope:** VAs `0x00629d90`, `0x0053a260` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` (+ xrefs/callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md` (W28-S).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00629d90` PhysSim_LtBroadPhase_Inferred | **accept** — ABI ret 8 + LtBroadPhase stage spine + sole caller sealed; stack-arg English residual |
| `aa_0053a260` Map_EraseRange_Val12 | **accept** — ABI ret 0x0c + full/partial range + Val12 isnil@+0x19 sealed |

---

## VA `0x00629d90` — sealed facts

1. **Body:** `0x00629d90`–`0x0062a160` exclusive (**2000** B / `0x7D0`); entry `sub esp,0x44`; epilogue **`ret 8`**.
2. **ABI:** **thiscall**; ECX = **sub-island**; 2 stack args (call site: ctx + stepBlock); void.
3. **Dispatch:** **1** CODE caller — `FUN_00561910` (`PhysSim_LtSimulate_Collide`) @ `0x00561a21`.
4. **Spine:** profile `"LtBroadPhase"` → prep `FUN_0062d960` x2 → AABB scratch (stride **0x20**) → `"StCalcAabbs"` → `"St3AxisSweep"` → `"StExamine"` (+ optional static pairs `+0x74/+0x78`) → `FUN_006297e0` → `sub+0x30=1` → narrowphase `FUN_00629c40` / `FUN_00629990` on `parentWorld+0x23e`.
5. **Constants (read_memory):** `DAT_00a0f298` = **0.5f**; strings `"StCalcAabbs"`/`"LtBroadPhase"` @ `0x009e3350`/`0x009e335c`; end tag `"lt"` @ `DAT_009d282c`.
6. **Callees:** `FUN_0062d960`, `FUN_005b3300`, `FUN_006297e0`, `FUN_00629c40`, `FUN_00629990`.
7. **Name:** `PhysSim_LtBroadPhase_Inferred` (Ghidra `FUN_00629d90`).
8. **Caveat:** decompiler stack formal map partial vs call-site push order; **not** integrate/applyAction (`FUN_00628f70`).

### Gaps

- Product English / exact sub-island type.  
- Nested narrowphase / `FUN_0062d960` not OWN.  
- Runtime / bit-diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00629d90_PhysSim_LtBroadPhase_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00629d90_PhysSim_LtBroadPhase_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00629d90_FUN_00629d90.md` |
| Annotated | `docs/reconstruction/raw/aa_00629d90_FUN_00629d90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysSim_LtBroadPhase_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00629d90.cpp` |
| Function | `docs/reconstruction/functions/aa_00629d90_FUN_00629d90.md` |
| Function named | `docs/reconstruction/functions/aa_00629d90_PhysSim_LtBroadPhase_Inferred.md` |

---

## VA `0x0053a260` — sealed facts

1. **Body:** `0x0053a260`–`0x0053a314` exclusive (**180** B / `0xB4`); pad `CC`; epilogue **`ret 0x0c`**.
2. **ABI:** **thiscall**; ECX = map (`head`@+4, `size`@+8); stack `(outIt, first, last)`; void.
3. **Gate full clear:** `first == *head && last == head` → `FUN_00538690(head->parent)` + reset head + `size=0`.
4. **Partial:** in-order successor (isnil@+0x19) + `FUN_005399f0` (`Map_EraseNode_Val12`) per node; `*outIt = end`.
5. **Callers (CODE):** **1** — `FUN_0053ba50` @ `0x0053ba62` (then `operator_delete` head).
6. **Name:** `Map_EraseRange_Val12` (Ghidra `FUN_0053a260`).
7. **Decompile ≡ raw** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / demangled map type for parent.  
- Nested free helper residual (not OWN).  
- Runtime / bit-diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053a260_Map_EraseRange_Val12.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0053a260_Map_EraseRange_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0053a260_FUN_0053a260.md` |
| Annotated | `docs/reconstruction/raw/aa_0053a260_FUN_0053a260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseRange_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0053a260.cpp` |
| Function | `docs/reconstruction/functions/aa_0053a260_FUN_0053a260.md` |
| Function named | `docs/reconstruction/functions/aa_0053a260_Map_EraseRange_Val12.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00629d90` | Sub-island **LtBroadPhase** under `LtSimulate` collide half only. Keep margin **0.5f**, AABB stride **0x20**, pair commit `006297e0`, dual narrowphase on `world+0x23e`. Do **not** put applyAction here. |
| `0053a260` | Val12 **range erase**: full-clear via recursive free; partial via `Map_EraseNode_Val12`. **ret 0x0c**, isnil@**+0x19**. Do not merge with isnil@+0x29 or +0x15 erase-range clones. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs/callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence (`_Inferred` / Val12 structural only).  
- Avoided bare `undefined4` in clean (`uint32_t`).
