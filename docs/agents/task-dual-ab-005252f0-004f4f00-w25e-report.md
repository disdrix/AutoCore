# Dual A/B report — W25-E OWN `aa_005252f0` + `aa_004f4f00`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W25-E  
**Scope:** VAs `0x005252f0`, `0x004f4f00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers / call-site bytes). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005252f0` Character_SwitchVehicle_Inferred | **accept-with-gaps** — ABI + HRESULT + stage CF + nested hardpoint duals sealed; product name + residual callees open |
| `aa_004f4f00` Vehicle_ActivateHardpointWeapons_Inferred | **accept-with-gaps** — ABI + 3-slot activate loop + fire-clear sealed; vfunc English open |

---

## VA `0x005252f0` — sealed facts

1. **Body:** `0x005252f0`–`0x00525a92` (**1955 / `0x7A3` B**; exclusive end `0x00525a93`; `RET 0x10`).
2. **ABI:** **ECX**=character* (`+0x250` vehicle); stack `newVehicle*`, `outOld**`, `argA`, `argB`; HRESULT return.
3. **Semantics:** Client chassis switch — cargo shrink-migrate, deactivate old hardpoints, create new cargo, optional phys+wheelset, rebind, activate hardpoints, dual-try stow old.
4. **HRESULTs:** `0` OK; `0x80070057` null new; `0x80004005` migrate/phys fail.
5. **Pages:** compare `vehicle+0x1e6` shorts; grid `6 × (pages×13)`.
6. **Hardpoint pair:** `004f4eb0` deactivate then `004f4f00` activate.
7. **Strings:** `"switched vehicles, and no room for old vehicle in either inventory"`; `"VOG_DEBUG_STOP"`.
8. **Callers (2):** `FUN_00810360` @ `0x008104a4`; `FUN_0093d880` @ `0x0093d95b`.
9. **Name:** `Character_SwitchVehicle_Inferred` (Ghidra `FUN_005252f0`).
10. **Decompile ≡ bytes** for CF (prologue/epilogue/call-site sealed).

### Gaps

- Product/PDB method name.  
- argA/argB non-sentinel English.  
- Mid-function `+0x250` rebind timing.  
- Nested residual duals (`005714e0`, `00571620`, `00571b80`, `004f39c0`, phys ctor, …).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005252f0_Character_SwitchVehicle_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005252f0_Character_SwitchVehicle_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005252f0_FUN_005252f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005252f0_FUN_005252f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SwitchVehicle_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005252f0.cpp` |
| Function | `docs/reconstruction/functions/aa_005252f0_FUN_005252f0.md` |
| Function named | `docs/reconstruction/functions/aa_005252f0_Character_SwitchVehicle_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005252f0.md` |

---

## VA `0x004f4f00` — sealed facts

1. **Body:** `0x004f4f00`–`0x004f4faa` (**171 / `0xAB` B**; exclusive end `0x004f4fab`; bare `RET`).
2. **ABI:** **ECX**=vehicle*; **0** stack formals; void.
3. **Semantics:** For each of **3** hardpoint weapons at `*(vehicle+0x260)`: `SetFireFlagPair(0)` then activate(1) via full vtbl[0] or short vtbl+0x18.
4. **Twin:** `Vehicle_DeactivateHardpointWeapons_Inferred` @ `0x004f4eb0` (suppress clear + activate(0)).
5. **Constant:** `g_flOne` @ `0x00a0f2a0` = `1.0f`.
6. **Caller (1):** `FUN_005252f0` @ `0x005259ad` (`mov ecx,[esi+0x250]`).
7. **Name:** `Vehicle_ActivateHardpointWeapons_Inferred` (Ghidra `FUN_004f4f00`).
8. **Decompile ≡ bytes** for CF.

### Gaps

- Product/PDB symbol.  
- `weapon+0x08` gate English.  
- Call-site vehicle identity (old vs rebound new) at activate instruction.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004f4f00_Vehicle_ActivateHardpointWeapons_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004f4f00_Vehicle_ActivateHardpointWeapons_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004f4f00_FUN_004f4f00.md` |
| Annotated | `docs/reconstruction/raw/aa_004f4f00_FUN_004f4f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_ActivateHardpointWeapons_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004f4f00.cpp` |
| Function | `docs/reconstruction/functions/aa_004f4f00_FUN_004f4f00.md` |
| Function named | `docs/reconstruction/functions/aa_004f4f00_Vehicle_ActivateHardpointWeapons_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004f4f00.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005252f0` | Character chassis switch — preserve page-shrink migrate, HRESULT set, old `+0x2ac=1`, hardpoint deactivate→activate order, dual inventory stow of old chassis. |
| `004f4f00` | Hardpoint activate twin of `004f4eb0` — 3 slots @ `+0x260`, fire clear only (no suppress), activate(1) with +0x08 branch; pair with deactivate on switch. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers / call-site).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- This report: `docs/agents/task-dual-ab-005252f0-004f4f00-w25e-report.md`
