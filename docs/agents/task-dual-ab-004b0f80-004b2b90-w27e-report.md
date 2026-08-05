# Dual A/B report — W27-E OWN `aa_004b0f80` + `aa_004b2b90`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-E  
**Scope:** VAs `0x004b0f80`, `0x004b2b90` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004b0f80` ObjectMotion_AdvanceStage_Inferred | **accept-with-gaps** — CF + ABI ret4 + AL0\|1 + stage-chain contract sealed; product name open |
| `aa_004b2b90` ObjectMotion_ApplyStageParams_Inferred | **accept-with-gaps** — CF + ABI ret8 void + dirty/continuous dual path sealed; field English open |

---

## VA `0x004b0f80` — sealed facts

1. **Body:** `0x004b0f80`–`0x004b10fe` (**383 B / `0x17F`**; pad `CC` after last RET).
2. **ABI:** ECX = motion slot; stack `(char mode)`; epilogue **`ret 4`** (`C2 04 00`); **AL** = 0\|1.
3. **Classification:** **worker** (6 callees).
4. **Semantics:** Side effects on current stage (mission-complete audio when `host+4==0`, else one-shot FX + optional multi-hit flush) → advance `slot[1]` via `stage+0x2f4` → mode-1 end-sentinel fail → else reload duration `slot[0x5c]/[0x5d]` with optional RNG jitter (`DAT_00aaa638`).
5. **Caller (1 fn / 2 sites):** `ObjectMotion_SlotTick_Inferred` (`FUN_004b4620`) @ `0x004b4854` (mode 0), `0x004b488d` (mode 1).
6. **Callees:** `FUN_004e9530`, `Client_GetMissionCompleteAudioTable`, `FUN_00725a70` (`CSoundManager_TryQueueMissionCompleteSound_Inferred`), `FUN_004b7e50`, `FUN_004b6980` (`NDSpecialFX_FlushStagedMultiHits_Inferred`), `CVOGReaction_RandomUnitScalar`.
7. **Constant (`read_memory`):** `DAT_00aaa638` @ `0x00aaa638` = `80 00 80 37` ≈ **1/65535**.
8. **Name:** `ObjectMotion_AdvanceStage_Inferred` (Ghidra `FUN_004b0f80`). Supersedes keyword alias `Mission_Uses_Client_GetMissionCompleteAudioTable`.
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Nested free helpers `FUN_004e9530` / `FUN_004b7e50`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b0f80_ObjectMotion_AdvanceStage_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004b0f80_ObjectMotion_AdvanceStage_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b0f80_FUN_004b0f80.md` |
| Annotated | `docs/reconstruction/raw/aa_004b0f80_FUN_004b0f80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_AdvanceStage_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b0f80.cpp` |
| Function | `docs/reconstruction/functions/aa_004b0f80_FUN_004b0f80.md` |
| Function named | `docs/reconstruction/functions/aa_004b0f80_ObjectMotion_AdvanceStage_Inferred.md` |

---

## VA `0x004b2b90` — sealed facts

1. **Body:** `0x004b2b90`–`0x004b3253` (**1732 B / `0x6C4`**).
2. **ABI:** **`__thiscall`** ECX = motion slot; stack `(char dirty, float dt)`; epilogue **`ret 8`** (`C2 08 00`); **void**.
3. **Callers (2):** `FUN_004b4620` @ `0x004b48de`; `FUN_005bc120` @ `0x005bc2ae`.
4. **Callees:** `CVOGReaction_RandomUnitScalar` (many), `FUN_004b2910` (×3), `ROUND`.
5. **CF stages:**
   - **dirty≠0:** copy 0x1D dwords stage`+0x36c`→slot`+0x3e`; flag-gated template loads (`+0x3e0..3e3`); RNG; optional `FUN_004b2910`; snapshot slot`+4`→`+0x21`.
   - **dirty==0:** `progress = g_flOne − slot[0x5c]/slot[0x5d]`; flag-gated lerps; always `slot[0xb] += slot[9]*dt`.
6. **Constant:** `DAT_00aaa638` ≈ 1/65535; `g_flOne` for progress.
7. **Name:** `ObjectMotion_ApplyStageParams_Inferred` (Ghidra `FUN_004b2b90`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / stage bitmask field labels.  
- Nested `FUN_004b2910` dual; full `FUN_005bc120` site dual.  
- Runtime post-reinit bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b2b90_ObjectMotion_ApplyStageParams_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004b2b90_ObjectMotion_ApplyStageParams_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b2b90_FUN_004b2b90.md` |
| Annotated | `docs/reconstruction/raw/aa_004b2b90_FUN_004b2b90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_ApplyStageParams_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b2b90.cpp` |
| Function | `docs/reconstruction/functions/aa_004b2b90_FUN_004b2b90.md` |
| Function named | `docs/reconstruction/functions/aa_004b2b90_ObjectMotion_ApplyStageParams_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004b0f80` | SlotTick **must** treat mode-1 return 0 as **remove**. Soft mode-0 after radius must still advance stage and reload duration. Preserve **ret 4**. Do not reduce to “mission audio only.” |
| `004b2b90` | Call **before** IntegrateStep with correct dirty flag. Continuous path progress is **elapsed** fraction (`1−rem/total`), not remaining. Always integrate `rate*dt` into `slot[0xb]` on dirty==0. Preserve **ret 8**. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b4620` | `ObjectMotion_SlotTick_Inferred` (W26-H) — sole advance caller; primary apply caller |
| `0x004b1100` | `ObjectMotion_IntegrateStep_Inferred` (W24-C) — after ApplyStageParams |
| `0x00725a70` | `CSoundManager_TryQueueMissionCompleteSound_Inferred` (W18-R) |
| `0x004b6980` | `NDSpecialFX_FlushStagedMultiHits_Inferred` |
| `0x005bc120` | secondary ApplyStageParams caller |
| `0x004b18f0` / `0x004b2910` / `0x004b7e50` / `0x004e9530` | residual helpers |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
