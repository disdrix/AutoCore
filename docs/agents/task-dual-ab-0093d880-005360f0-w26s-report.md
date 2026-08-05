# Dual A/B report — W26-S OWN `aa_0093d880` + `aa_005360f0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-S  
**Scope:** VAs `0x0093d880`, `0x005360f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0093d880` Client_ApplyVehicleSwitch_Inferred | **accept-with-gaps** — CF/ABI/Switch call-site sealed; invoker + product English + residual helpers open |
| `aa_005360f0` CVOGCharacter_TickUseObjectPending_Inferred | **accept** — thiscall + timer tick + commit-on-expiry + sole caller sealed |

---

## VA `0x0093d880` — sealed facts

1. **Body:** `0x0093d880`–`0x0093da25` (**422 / `0x1A6` B**; exclusive end `0x0093da26`; pad `CC`).
2. **ABI:** custom — **EAX** = client* (`8B D8`); stack `Vehicle* newVehicle` @ `[ebp+8]`; **AL** = 1; **`RET 4`**.
3. **Semantics:** Client apply vehicle chassis switch — UI teardown → `Character_SwitchVehicle_Inferred(new, &outOld, 0xFFFFFFFF, 0xFFFFFFFF)` → garage rebind → dialog **0x12** → combat pools → mission UI refresh; always returns 1 (HRESULT ignored).
4. **Switch site:** `0x0093d95b` — dual `push -1`, `lea/push &outOld`, `push newVehicle`, `mov ecx,[client+0xe98]`.
5. **Callees:** vehicle vfunc `+0x1c8`; UI vfuncs; `FUN_007fca10`; `FUN_005252f0` (W25-E); `FUN_009147a0`; `FUN_008801b0`; `FUN_0085e970`; `FUN_007fef20(0x12,1,0)`; `Vehicle_EnsureRegenerationHeartbeat`; `Vehicle_RecalcCombatPools`; `Client_RefreshOpenMissionUiWindows`.
6. **Callers:** **0** CODE/data xrefs (Ghidra) — invoker unresolved.
7. **Name:** `Client_ApplyVehicleSwitch_Inferred` (Ghidra `FUN_0093d880`); contrast `Client_OnVehicleSwitchFailure` @ `0x00810360`.
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product/PDB name.  
- Static invoker (vtable/dispatch).  
- Dialog index **0x12** English.  
- Nested helper duals (`009147a0`, `008801b0`, `0085e970`, …).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0093d880_Client_ApplyVehicleSwitch_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0093d880_Client_ApplyVehicleSwitch_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0093d880_FUN_0093d880.md` |
| Annotated | `docs/reconstruction/raw/aa_0093d880_FUN_0093d880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ApplyVehicleSwitch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0093d880.cpp` |
| Function | `docs/reconstruction/functions/aa_0093d880_FUN_0093d880.md` |
| Function named | `docs/reconstruction/functions/aa_0093d880_Client_ApplyVehicleSwitch_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0093d880.md` |

---

## VA `0x005360f0` — sealed facts

1. **Body:** `0x005360f0`–`0x00536143` (**84 / `0x54` B**; exclusive end `0x00536144`; pad `CC` before `0x00536150`).
2. **ABI:** **`__thiscall`**; ECX = character*; stack float `dt`; **AL** bool; **`RET 4`**.
3. **Semantics:** If vbase `+0x7e` and pending flag `+0xc7c` and timer `+0xc80 > 0`: `timer -= dt`; if `timer <= 0` call `CVOGCharacter_ResolveUseObjectPending_Inferred(1)`; return 1. Else return 0.
4. **Callee (1):** `FUN_00535ed0` / ResolveUseObjectPending (W25-A sealed) with commit **1**.
5. **Caller (1):** `FUN_00930040` @ `0x009300c3`; dt = `*(DAT_00d09874+0x30)`.
6. **Name:** `CVOGCharacter_TickUseObjectPending_Inferred` (Ghidra `FUN_005360f0`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / PDB name.  
- Who arms initial `+0xc80`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005360f0_CVOGCharacter_TickUseObjectPending_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005360f0_CVOGCharacter_TickUseObjectPending_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005360f0_FUN_005360f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005360f0_FUN_005360f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TickUseObjectPending_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005360f0.cpp` |
| Function | `docs/reconstruction/functions/aa_005360f0_FUN_005360f0.md` |
| Function named | `docs/reconstruction/functions/aa_005360f0_CVOGCharacter_TickUseObjectPending_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005360f0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0093d880` | Client chassis-switch **apply** path: tear down UI slots before `Character_SwitchVehicle` with **−1/−1** allocate-id pair; ignore HRESULT; open dialog **0x12**; refresh pools + mission UI. Do not confuse with `Client_OnVehicleSwitchFailure`. Invoker still open — wire when dispatch table recovered. |
| `005360f0` | Per-frame pending use-object countdown: gate vbase+flag+timer>0; subtract frame dt; **commit** (not cancel) on expiry via Resolve. Caller supplies `DAT_00d09874+0x30` dt. Completes the W25-A pending pair (tick → resolve). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence (`_Inferred` suffix).  
- Avoid bare `undefined4` in clean (`uint32_t` / `uint8_t`).
