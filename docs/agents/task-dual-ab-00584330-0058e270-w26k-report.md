# Dual A/B report — W26-K OWN `aa_00584330` + `aa_0058e270`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-K  
**Scope:** VAs `0x00584330`, `0x0058e270` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00584330` Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred | **accept** — single-slot pack `(0,e,0,-1)` + host fan-out + always tail teardown sealed |
| `aa_0058e270` NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred | **accept** — slot gate + stop/start thiscall particle ops + exclusive `004b7030` caller sealed |

---

## VA `0x00584330` — sealed facts

1. **Body:** `0x00584330`–`0x005843af` (**127 B**).
2. **ABI:** **thiscall**; **no stack formals**; epilogue **tail jmp** `FUN_005179e0` (not call+ret).
3. **Semantics:** If `*(this-0x88)` effect non-null → apply pack `(want_start=0, want_stop=effect, use_slot_filter=0, slot_filter=-1)` via `FUN_00583f10(this-0x90, …)` and local host* vector at vb(`this-0x8c`)+`0xac`/`0xb0` calling `FUN_004b7030(*it, …)`; **always** tail to teardown `FUN_005179e0` with vbase-adjusted this.
4. **Filter path:** use_slot_filter **0** → sealed helpers take **`0058e300`** (unrestricted) path — distinct from dual-slot wild pack `(0,e,1,-1)`.
5. **Byte corrections:** `lea ecx,[esi-0x90]` for table owner; `mov ecx,[edi]` for host this (decomp miss); jmp not call to `005179e0`.
6. **Callers (4 named / 12 xrefs):** `FUN_004c8110` (tail at `self-0x430`), `FUN_004fd950`, `FUN_00505ba0`, `FUN_005a9220`.
7. **Callees:** `FUN_00583f10`, `FUN_004b7030`, tail `FUN_005179e0`.
8. **Name:** `Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred` (Ghidra `FUN_00584330`).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23); ABI details sealed by `read_memory`.

### Gaps

- Product English / C++ class.  
- Full dual of `FUN_005179e0`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00584330_Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00584330_Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00584330_FUN_00584330.md` |
| Annotated | `docs/reconstruction/raw/aa_00584330_FUN_00584330.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00584330.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_00584330_FUN_00584330.md` |
| Function named | `docs/reconstruction/functions/aa_00584330_Object_ApplySingleFxSlot_NoSlotFilter_ThenTeardown_Inferred.md` |

---

## VA `0x0058e270` — sealed facts

1. **Body:** `0x0058e270`–`0x0058e2f1` (**129 B**; pad `CC` after).
2. **ABI:** **thiscall**; 3 stack dwords; **`ret 0x0C`**.
3. **Gate:** `(slot_filter_lo == 0xFF OR child+0x25c == sext(slot_lo)) AND child+0x25c != -1`.
4. **Stop:** if `effect_stop != 0` → `FUN_0096d550(this=effect_stop, arg=*(child+0x914))`.
5. **Start:** if `effect_start != 0` and `FUN_0096d460(this=effect_start, arg=*(child+0x258))==0` → `FUN_0096dc80(…)` then `*(child+0x90f) |= 1` and return; else `&= ~1`.
6. **Callers (1 exclusive):** `FUN_004b7030` only.
7. **Callees:** `FUN_0096d550`, `FUN_0096d460`, `FUN_0096dc80`.
8. **Sibling:** `FUN_0058e300` — same body shape, gate `+0x25c < 0`, no slot formal (OWN of W26-L).
9. **Name:** `NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred` (Ghidra `FUN_0058e270`). Prior exhaust-only alias **retired as too narrow**.
10. **Decompile ≡ bytes** for CF; particle **this** pointers sealed by entry bytes (decomp flattens).

### Gaps

- Product English.  
- Full dual of `0096d*` particle helpers.  
- Slot_filter high 24 bits unused by bytes — residual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0058e270_NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0058e270_NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0058e270_FUN_0058e270.md` |
| Annotated | `docs/reconstruction/raw/aa_0058e270_FUN_0058e270.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058e270.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_0058e270_FUN_0058e270.md` |
| Function named | `docs/reconstruction/functions/aa_0058e270_NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00584330` | Chain after dual-slot wild apply: single effect at rebased `this-0x88`, **filter char 0**, then **always** run teardown `005179e0`. Ports must not skip teardown when effect is null. Preserve vbase ECX for tail. |
| `0058e270` | Slot-filtered child FX core. `effect_start`/`effect_stop` are **object pointers** (this for particle helpers), not pure bools. Wild slot is **byte 0xFF**. Child slot `-1` skips entirely. Exclusive path from `004b7030` when filter enabled — pairs with `0058e300` for unrestricted children. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence (`_Inferred` suffix).  
- Avoided bare `undefined4` in clean (`uint32_t` / `void*`).
