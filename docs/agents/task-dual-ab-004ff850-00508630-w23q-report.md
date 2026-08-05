# Dual A/B report — W23-Q OWN `aa_004ff850` + `aa_00508630`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-Q  
**Scope:** VAs `0x004ff850`, `0x00508630` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004ff850` NDSpecialFX_ExpandVehicleHardpointSlots | **accept-with-gaps** — CF + ABI + multi-string HP case table + instantiate link sealed; nested attach/probe duals residual |
| `aa_00508630` CVOGHBBase_ScalarDeletingDtor | **accept** — full body bytes + vtbl[0] scalar dtor + listMgr unlink + free gate sealed |

---

## VA `0x004ff850` — sealed facts

1. **Body:** `0x004ff850`–`0x004ffe2e` (1502 B / `0x5DE`).
2. **ABI:** **`__thiscall`** (ECX = interior host); stack `templateFx`, `param_3`, `param_4`; **`ret 0x0C`**.
3. **Caller (1):** `CVOG_CreateFromPacketDispatch` @ `0x00507000` (thin trampoline).
4. **Type table:** dword half-open vector at `templateFx+0x94` / `+0x98`.
5. **Empty path:** `FUN_005829d0(template,…)` + 3× `FUN_004b7030` on slots at `this-0x330`.
6. **Cases / strings:**
   - `0x0B` `"%s_WHEELSET_%d"`
   - `0x0F` `"%s_VEHICLE_EXHAUST_%d"` (ids `0x4BB..0x4BF`)
   - `0x10` `"%s_VEHICLE_BRAKES_%d"` (ids `0x4C5..0x4CB`)
   - `0x11` `"%s_VEHICLE_LIGHTS_%d"` (ids `0x4CF..0x4D7`)
   - `0x15` `"%s_VEHICLE_MELEE_%d"` (ids `0x3E9..0x408`)
7. **Instantiate:** `FUN_004a0b90` = sealed `NDSpecialFX_InstantiateFromTemplate`; name prefix `template+0xD5`.
8. **Track gate:** `param_4 != 0` → `CVOGReaction_FailMissionNotify(&child)` (vector push family).
9. **Name:** `NDSpecialFX_ExpandVehicleHardpointSlots` (supersedes auto `Drive_s_VEHICLE_EXHAUST_d`).
10. **Decompile ≡ entry/exit bytes** for ABI + empty/walk CF; nested helpers residual.

### Gaps

- Product / PDB English name.  
- Interior-this class field dictionary (−0x330 / −0x418 / −0x628).  
- Duals for `FUN_005829d0`, `FUN_004b7030`, `FUN_00989270`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004ff850_FUN_004ff850.md` |
| Annotated | `docs/reconstruction/raw/aa_004ff850_FUN_004ff850.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_ExpandVehicleHardpointSlots.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004ff850.cpp` |
| Function | `docs/reconstruction/functions/aa_004ff850_FUN_004ff850.md` |
| Function named | `docs/reconstruction/functions/aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md` |
| Scratch | `docs/reconstruction/tmp/a_004ff850.md` |

---

## VA `0x00508630` — sealed facts

1. **Body:** `0x00508630`–`0x00508667` (55 B / `0x37`).
2. **ABI:** **`__thiscall`** (ECX = `CVOGHBBase*`); stack `byte flags`; **`ret 4`**; EAX = this.
3. **Vtbl slot 0:** `PTR_FUN_009cdab0` (`0x009cdab0`) → this VA.
4. **Always** restore base vtbl imm `0x009cdab0`.
5. **Unlink:** if `this+0x18` and `*(owner+0xB0)` → `FUN_005085b0` with **ECX = listMgr**, stack = HB (machine wins over decompiler).
6. **Scalar free:** `(flags & 1)` → `operator_delete(this)`.
7. **Sibling:** complete body only = `CVOGHBBase_dtor` @ `0x00508390`.
8. **Name:** `CVOGHBBase_ScalarDeletingDtor` (class + role sealed by family duals).
9. **Decompile ≡ full body bytes** for CF; callee this corrected in clean.

### Gaps

- Product / PDB mangled name.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00508630_CVOGHBBase_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00508630_CVOGHBBase_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00508630_FUN_00508630.md` |
| Annotated | `docs/reconstruction/raw/aa_00508630_FUN_00508630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00508630.cpp` |
| Function | `docs/reconstruction/functions/aa_00508630_FUN_00508630.md` |
| Function named | `docs/reconstruction/functions/aa_00508630_CVOGHBBase_ScalarDeletingDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_00508630.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004ff850` | Create-from-packet **FX child expansion** only — not inventory wheelset equip (`0x004ff510`). Preserve five HP type ids, name formats, and instantiate contract; do not invent mission-fail RPCs from FailMissionNotify name. |
| `00508630` | Virtual delete path for CVOGHBBase — restore base vtbl, unlink via listMgr thiscall, free only when flags bit0. Keep complete dtor (`0x00508390`) free-free for stack/member destroy. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
