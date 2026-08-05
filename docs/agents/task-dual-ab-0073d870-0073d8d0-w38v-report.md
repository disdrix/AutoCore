# Dual A/B report — W38-V OWN `aa_0073d870` + `aa_0073d8d0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-V  
**Scope:** VAs `0x0073d870`, `0x0073d8d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site context + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-V).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0073d870` EffEffectFactory_OnDeviceReset_Inferred | **accept-with-gaps** — EAX factory host, 0x14 entry walk, child vcall +0x118, always return 0, Effect Factory plate sealed (82 B); product class English + unowned param helper open |
| `aa_0073d8d0` EffEffectFactory_OnDeviceLost_Inferred | **accept-with-gaps** — same host pre-reset release, FUN_0074f0c0 + FUN_00752640, global clear + device vtbl+0x134(0) sealed (103 B); product English + unowned callees open |

---

## VA `0x0073d870` — sealed facts

1. **Body:** `0x0073d870`–`0x0073d8c2` exclusive (**82 B** / `0x52`; pad `CC`×14 then `FUN_0073d8d0`).
2. **ABI:** **EAX = effect-factory host\*** (register formal); no stack args; plain **`RET`**; returns **0** (`XOR EAX,EAX`).
3. **Semantics:** post-`IDirect3DDevice9::Reset` recreate walk:
   - Outer: host `+4` begin / `+8` end; entry stride **0x14**.
   - If `(*entry)[+0xC] != 0`: vcall child vtbl **`+0x118`**.
   - Inner: `entry[+8..+0xC)` step 4 → `FUN_007525f0` (**EDI** formal).
4. **Classification:** **worker**.
5. **Callers (1):** `FUN_0075eff0` @ `0x0075f2f6` — `MOV EAX,[EBP+0x764]`; fail **"Failed to Reset() device on Effect Factory"** (`gfxDevice.cpp` `0x242`).
6. **Callees:** `FUN_007525f0`.
7. **Name:** `EffEffectFactory_OnDeviceReset_Inferred` (Ghidra `FUN_0073d870`; **Inferred**). **Reject** `Named_CalleeOf_Named_gfxDevice_0073d870`.
8. **Family:** pair of `aa_0073d8d0` OnDeviceLost on same host; neighbor 0x14 walkers in Effect/registry family.
9. **Decompile ≡ bytes** for stride / vcall / always-0.  
   Full hex: raw W38-V append (82 B).

### Gaps

- Product C++ class English for factory / entry / child `+0x118`.  
- Unowned `FUN_007525f0` full dual.  
- Always-0 vs caller `< 0` check (shared factory template).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073d870_EffEffectFactory_OnDeviceReset_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0073d870_EffEffectFactory_OnDeviceReset_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073d870_FUN_0073d870.md` |
| Annotated | `docs/reconstruction/raw/aa_0073d870_FUN_0073d870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffEffectFactory_OnDeviceReset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073d870.cpp` |
| Function | `docs/reconstruction/functions/aa_0073d870_FUN_0073d870.md` |
| Function named | `docs/reconstruction/functions/aa_0073d870_EffEffectFactory_OnDeviceReset_Inferred.md` |

---

## VA `0x0073d8d0` — sealed facts

1. **Body:** `0x0073d8d0`–`0x0073d937` exclusive (**103 B** / `0x67`; pad `CC`×9 then `FUN_0073d940`).
2. **ABI:** **EAX = effect-factory host\*** (register formal); no stack args; plain **`RET`**; **void**.
3. **Semantics:** pre-reset / device-lost release walk on **same** 0x14 table:
   - Per entry: `FUN_0074f0c0` (**ESI=`*entry`**); param range → `FUN_00752640` (**EBX** formal).
   - `DAT_00d1f048[+0xC] = 0`.
   - If `DAT_00d1f044[+0x77C] == 1` (`[0x1df]`): `(*DAT_00d1f044)->vtbl[+0x134](..., 0)`.
4. **Classification:** **worker**.
5. **Callers (1):** `FUN_0075eff0` @ `0x0075f0f7` — `MOV EAX,[EBP+0x764]` during **"Beginning shutdown for Device Reset()"**.
6. **Callees:** `FUN_0074f0c0`, `FUN_00752640`.
7. **Name:** `EffEffectFactory_OnDeviceLost_Inferred` (Ghidra `FUN_0073d8d0`; **Inferred**). **Reject** `Named_CalleeOf_Named_gfxDevice_0073d8d0`.
8. **Family:** pair of `aa_0073d870`; shares device mode field family with caller software-VP toggle.
9. **Decompile ≡ bytes** for stride / globals / vcall.  
   Full hex: raw W38-V append (103 B).

### Gaps

- Product factory / entry English.  
- Unowned callees `FUN_0074f0c0` (W38-X), `FUN_00752640`.  
- Product plate for device vtbl `+0x134` (software-VP residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0073d8d0_EffEffectFactory_OnDeviceLost_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0073d8d0_EffEffectFactory_OnDeviceLost_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0073d8d0_FUN_0073d8d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0073d8d0_FUN_0073d8d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffEffectFactory_OnDeviceLost_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0073d8d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0073d8d0_FUN_0073d8d0.md` |
| Function named | `docs/reconstruction/functions/aa_0073d8d0_EffEffectFactory_OnDeviceLost_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0073d870` | Port as **Effect Factory OnDeviceReset**: **EAX=host**, walk `+4/+8` entries stride **0x14**, optional child vcall **`+0x118`**, param rebind `FUN_007525f0`, **always return 0**. Do **not** model as ECX thiscall. Pair with Lost before any D3D Reset. |
| `0073d8d0` | Port as **Effect Factory OnDeviceLost**: same EAX host table; release via `FUN_0074f0c0` + `FUN_00752640`; clear `DAT_00d1f048[+0xC]`; if software-mode dword `device[+0x77C]==1`, device vtbl **`+0x134`(0)**. Void; call in Device Reset **shutdown** only. |

Shared: both are **EAX register-formal workers** on the **same** Effect Factory host (`[EBP+0x764]` in `FUN_0075eff0`). Complementary Device Reset polarity (Lost then Reset). Co-owned as natural W38-V pair.

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0075eff0` | `gfxDevice` Device Reset manager (sole caller) |
| `0x007525f0` | Param rebind on Reset (EDI formal) |
| `0x00752640` | Param release on Lost (EBX formal) |
| `0x0074f0c0` | Effect OnLost helper (ESI formal; W38-X) |
| `0x0073d940` | Neighbor 0x14-table finder (not owned) |
| `DAT_00d1f044` / `DAT_00d1f048` | Global device / graphics state |

Closes W38-V OWN pair: Effect Factory **OnDeviceLost** + **OnDeviceReset** under gfxDevice Device Reset.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names; caller string used for Effect Factory seal.  
- Rejected bare Named_CalleeOf_gfxDevice scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Distinguished OnLost vs OnReset polarity by call-site order in Device Reset.  
- Terminal coverage: **false** always.
