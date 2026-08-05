# Dual A/B report — W24-D OWN VAs `0x009168d0` + `0x004b7030`

**Date:** 2026-07-29  
**Agent:** W24-D (OWN-ONLY dual A/B)  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module / base:** `autoassault.exe` @ `0x400000`  
**Owned VAs only:** `0x009168d0`, `0x004b7030`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs / callee decompiles). **No** `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdicts

| Unit | Proposed name | Verdict |
|------|---------------|---------|
| `aa_009168d0` @ `0x009168d0` | `Client_Camera_DefaultModeUpdate_Inferred` | **accept-with-gaps** |
| `aa_004b7030` @ `0x004b7030` | `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` | **accept** |

Both A and B reviews agree per VA.

---

## VA1 — `0x009168d0` Client_Camera_DefaultModeUpdate_Inferred

### Sealed facts

1. **Body:** `009168d0`–`00917603` (**3379** B / `0xD33`). Epilogue **`ret 0x14`** (`C2 14 00`).
2. **ABI:** MSVC **stdcall**, **5 stack dwords** (cam*, focus xyz*, range_a, range_b, dt_or_scale); not thiscall.
3. **Role:** **Default** camera-mode update — sole caller `FUN_0091ce80` default arm of mode switch (`cam[0x331]`); modes 1/2/3/5/7/8 branch to other helpers.
4. **Orbit aim:** `cos/sin(cam+0xcc8)` × ranges × basis `+0x5ac/+0x5b4` + focus.
5. **Collision:** multi-pass; each pass **8** probes via `FUN_00915ad0` + dualed `Client_Map_RaySegmentHitDistance_Inferred` (`0x00916090`).
6. **Eye commit:** `DAT_00d17944 + 0x228/0x22c/0x230` (integrate vs snap by `DAT_00d1f0a0`).
7. **Look writeback:** gamepad path → `*(DAT_00d1b6d8+0x250)+0x170..`; else basis/`DAT_00d1a640` fallbacks.
8. **Constants (bytes):** `1.5`, `3.5`, `12.0`, `0.2`, `~10000`, `0.05`, `g_flOne=1.0`, `-1.0`.

### Gaps

- Product / PDB camera method name  
- Mode-id enum English  
- Full gate-byte dictionary  
- Precise `param_5` unit  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009168d0_FUN_009168d0.md` |
| Annotated | `docs/reconstruction/raw/aa_009168d0_FUN_009168d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_009168d0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Camera_DefaultModeUpdate_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_009168d0_FUN_009168d0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_009168d0_Client_Camera_DefaultModeUpdate_Inferred.md` |

---

## VA2 — `0x004b7030` NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred

### Sealed facts

1. **Body:** `004b7030`–`004b708a` (**90** B). Epilogue **`ret 0x10`** (`C2 10 00`).
2. **ABI:** MSVC **thiscall**, **4 stack dwords**; ECX = NDSpecialFX host.
3. **List:** circular own-list at **`host+0x204`** (same family as dualed `NDSpecialFX_DeactivateClear_Inferred` @ `0x004b7150`).
4. **Gate:** child payload `node[2]`; require **`*(child+0x90e) & 0x80`** (bit7).
5. **Callee this:** bytes `mov ecx,[esi+8]` before calls — **decompiler omits** child as this for `FUN_0058e300` / `FUN_0058e270`.
6. **Branch:** `use_slot_filter==0` → `0058e300(child, want_start, want_stop)`; else → `0058e270(child, want_start, want_stop, slot_filter)`.
7. **Callers (5):** `FUN_004c8110`, `FUN_004ff850` (near `%s_VEHICLE_EXHAUST_%d`), `FUN_005829d0`, `FUN_00583f10`, `FUN_00584330`.
8. **Reject alias:** `Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_004b7030` — exhaust is one parent path only.

### Gaps

- Product / PDB method name  
- Bit7 English (phys-detach vs FX-capable overlap)  
- Full dual of `0058e270` / `0058e300`  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b7030_FUN_004b7030.md` |
| Annotated | `docs/reconstruction/raw/aa_004b7030_FUN_004b7030.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004b7030.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_004b7030_FUN_004b7030.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004b7030_NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred.md` |

---

## AutoCore impact

- **`009168d0`:** client-only default camera path. Server ports that need camera collision parity should reuse map segment cast + distance (filter **7** via `00916090` contract), not vehicle wheel phantoms. Do not conflate with mode-specific helpers (`00914930` / `0091b1c0` / `0091c220`).
- **`004b7030`:** client FX host apply gate over owned children with bit7. Ports that spawn/teardown FX must not use this as deactivate/clear (`004b7150`); this only **dispatches** start/stop toggles. Preserve slot-filter branch (`0058e300` vs `0058e270`) and child ECX.
- No server Launcher / live runtime work performed this pass.

---

## Compliance

| Rule | Status |
|---|---|
| OWN VAs only | **Yes** (`009168d0`, `004b7030`) |
| decompile_function + read_memory | **Yes** |
| No disassemble_bytes | **Yes** |
| No Launcher | **Yes** |
| No parent ledger edits | **Yes** |
| raw / annotated / reconstructed-exact / functions / reviews A+B | **Yes** (both VAs) |
