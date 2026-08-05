# Dual A/B report — W26-L OWN `aa_0058e300` + `aa_008120d0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-L  
**Scope:** VAs `0x0058e300`, `0x008120d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0058e300` CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred | **accept** — unslotted gate + start/stop phys helpers + bit0 + thiscall RET 8 sealed |
| `aa_008120d0` Client_CreateObjectFromCbidPacket_Inferred | **accept-with-gaps** — factory create + mode-2 apply + fail string sealed; `0092a3b0` residual |

---

## VA `0x0058e300` — sealed facts

1. **Body:** `0x0058e300`–`0x0058e370` (**112 B**; pad `CC` after last RET).
2. **ABI:** MSVC **thiscall**; ECX = object*; stack `want_start`, `want_stop`; **`RET 8`**.
3. **Gate:** acts only when `*(this+0x25c) < 0` (negative slot / unslotted).
4. **Stop:** if `want_stop != 0`: `FUN_0096d550(this=want_stop, key=*(this+0x914))` — bytes seal ECX (decompiler omits).
5. **Start:** if `want_start != 0`: lookup `FUN_0096d460(this=want_start, key=*(this+0x258))`; if **0**, attach `FUN_0096dc80(..., +0x258, +0x914, +0x254)` and **set** `+0x90f` bit0; else **clear** bit0.
6. **Callers (2):** `FUN_004b7030` (FX toggle), `FUN_004b7150` (often stop-only `(0, phys)`).
7. **Sibling:** `FUN_0058e270` — same body with slot-filter gate (not OWN this dual).
8. **Name:** `CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred` (Ghidra `FUN_0058e300`).
9. **Decompile ≡ bytes** for primary CF (live 2026-07-29 ≡ raw 2026-07-23); callee this restored from bytes.

### Gaps

- Product English / class method name.  
- Nested `0096d*` product duals (not OWN).  
- Runtime attach/detach differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0058e300_CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0058e300_CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0058e300_FUN_0058e300.md` |
| Annotated | `docs/reconstruction/raw/aa_0058e300_FUN_0058e300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0058e300.cpp` |
| Function | `docs/reconstruction/functions/aa_0058e300_FUN_0058e300.md` |
| Function named | `docs/reconstruction/functions/aa_0058e300_CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0058e300.md` |

---

## VA `0x008120d0` — sealed facts

1. **Body:** `0x008120d0`–`0x008122de` (**526 B** / `0x20E` exclusive end; pad `CC CC`; next `FUN_008122e0`).
2. **ABI:** **2 stack formals** `game*`, `packet*`; **not** thiscall; **`RET 8`**; **EAX** = object* \| null.
3. **Factory:** `CVOGReaction_GiveItemByCbid(*(packet+4))`.
4. **Fail:** `FUN_007a4480(1, "allocatenewobjectfromcbid failed %d Get a programmer", cbid)`; return **0**.
5. **Success stages:** `vtbl+8(cbid, *(game+0xe04), 0)` → `vtbl+0x1cc` → flag fuse into `obj[0x61]` → `vtbl+0xc4(packet, **mode=2**, host, !pkt[+0xa1], flags…)` → optional `+0xa1` / `+0xc0` post helpers.
6. **Callers (7):** `FUN_00814400` (0x201C), `FUN_00814470`, `FUN_008144b0`, `FUN_008144f0`, `FUN_008122e0`, `FUN_00812320`, `FUN_00812360`.
7. **Twin:** `FUN_00811e00` sector-update (`OutputDebugStringA("Requesting ProcessSectorUpdate\n")`) — not OWN.
8. **Name:** `Client_CreateObjectFromCbidPacket_Inferred` (Ghidra `FUN_008120d0`).
9. **Decompile ≡ bytes** for primary CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product packet / method English.  
- Nested vfunc / helper duals (`008024d0`, `007fb2b0`, factory) not OWN.  
- **`FUN_0092a3b0` residual** — listed as callee; present in bytes under multi-flag gate; decompiler marks nearby blocks unreachable.  
- Runtime wire create differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008120d0_Client_CreateObjectFromCbidPacket_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008120d0_Client_CreateObjectFromCbidPacket_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008120d0_FUN_008120d0.md` |
| Annotated | `docs/reconstruction/raw/aa_008120d0_FUN_008120d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CreateObjectFromCbidPacket_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008120d0.cpp` |
| Function | `docs/reconstruction/functions/aa_008120d0_FUN_008120d0.md` |
| Function named | `docs/reconstruction/functions/aa_008120d0_Client_CreateObjectFromCbidPacket_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_008120d0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0058e300` | Unslotted FX phys start/stop only (`slot < 0`). Do not use for positive slot ids (use `0058e270` + filter). Preserve stop-before-start, lookup-before-attach, and `+0x90f` bit0. Deactivate paths often pass `want_start=0`. |
| `008120d0` | Client create path on resolve-miss. Preserve CBID factory, mode **2** create-from-packet, packet flag offsets, and fail log. Do not substitute `FUN_00811e00` update. Note optional `0092a3b0` residual for HB-list side effects. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` where plate/role only.
