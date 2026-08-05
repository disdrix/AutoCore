# Dual A/B report — W27-D OWN `aa_004ba0a0` + `aa_005bb5e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-D  
**Scope:** VAs `0x004ba0a0`, `0x005bb5e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004ba0a0` NDSpecialFX_StopFinalize_Inferred | **accept-with-gaps** — CF + ABI + list family sealed; nested helper English open |
| `aa_005bb5e0` ObjectMotion_SlotListTick_Inferred | **accept** — list tick CF + ret 8 + SlotTick linkage + count-- sealed |

---

## VA `0x004ba0a0` — sealed facts

1. **Body:** `0x004ba0a0`–`0x004ba26d` (**461 B / `0x1CD`**).
2. **ABI:** ECX = fx host; `SUB ESP,8`; plain **`RET`** (`C3`); **AL** = 0\|1.
3. **Classification:** **worker**.
4. **Semantics:** Manager stop/finalize — re-entry `+8`, type-gated early clear (case 4 via `FUN_004b6a80`), mark `+8=1`, tear down lists `+0x1E0/+1EC/+204/+210/+21C`, clear `+0x10`, return free polarity.
5. **Callers (2):** `FUN_005179e0` @ `0x00517a1d` (free on non-zero + `+9==0`); `FUN_00514d80` @ `0x00514d9a` (type 0xF).
6. **Name:** `NDSpecialFX_StopFinalize_Inferred` (Ghidra `FUN_004ba0a0`). **Reject** keyword `Mission_Uses_Client_GetMissionCompleteAudioTable_*`.
7. **Decompile ≡ bytes** for outer CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Nested helpers `004b9af0` / `004b9270` / `005b8340` / `00593e10` (not OWN).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004ba0a0_FUN_004ba0a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004ba0a0_FUN_004ba0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_StopFinalize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ba0a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004ba0a0_FUN_004ba0a0.md` |
| Function named | `docs/reconstruction/functions/aa_004ba0a0_NDSpecialFX_StopFinalize_Inferred.md` |

---

## VA `0x005bb5e0` — sealed facts

1. **Body:** `0x005bb5e0`–`0x005bb666` (**134 B / `0x86`**); pad `CC`.
2. **ABI:** **`__thiscall`** ECX = motion host; stack `(float *dt, uint32 flag)`; epilogue **`ret 8`** (`C2 08 00`); EAX = host`+0xA28` count.
3. **Global:** `DAT_00af3f68 = *dt` (`movss`); image default ≈ **0.1** (`3DCCCCCD`).
4. **Caller (1):** `NDSpecialFX_HostTick_Inferred` (`FUN_004b8ed0`) @ `0x004b9103` — ECX = list`+0x1E0` payload; after `FUN_005bc3c0` keep.
5. **Callees:** `FUN_004b4620` (`ObjectMotion_SlotTick_Inferred` W26-H), `FUN_005be2b0`, `operator_delete`.
6. **CF:** walk `+0xA24` → SlotTick → on 0 teardown/unlink/delete/**count--** → return count.
7. **Decompiler gap sealed:** post-delete `*(+0xA28)--` (`83 87 28 0A 00 00 FF`) omitted by false noreturn on delete.
8. **Name:** `ObjectMotion_SlotListTick_Inferred` (Ghidra `FUN_005bb5e0`).

### Gaps

- Product English / class of motion host.  
- Nested `FUN_005be2b0` (not OWN).  
- Runtime multi-remove golden.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005bb5e0_FUN_005bb5e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005bb5e0_FUN_005bb5e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectMotion_SlotListTick_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005bb5e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005bb5e0_FUN_005bb5e0.md` |
| Function named | `docs/reconstruction/functions/aa_005bb5e0_ObjectMotion_SlotListTick_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004ba0a0` | Manager prune must use this stop/finalize — **not** DeactivateClear. Preserve case-4 AnyFlag10 keep break and AL free polarity. |
| `005bb5e0` | List tick owns remove contract for SlotTick. Preserve **ret 8**, dt global mirror, and **count--** on each free (do not trust raw decompile alone). |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b8ed0` | `NDSpecialFX_HostTick_Inferred` (W24-C) — sole list-tick caller |
| `0x004b4620` | `ObjectMotion_SlotTick_Inferred` (W26-H) — per-slot tick |
| `0x004b6a80` | `NDSpecialFX_List1e0_AnyFlag10` — case 4 gate |
| `0x004b7150` | `NDSpecialFX_DeactivateClear_Inferred` (W23-H) — distinct |
| `0x004b7330` | `NDSpecialFX_LivenessDone_Inferred` (W26-H) |
| `0x00723b20` | `CSoundManager_StopMatchingSounds_Inferred` |
| `0x005be2b0` | slot teardown on remove |
| `0x005179e0` / `0x00514d80` | manager callers of StopFinalize |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural labels only.
