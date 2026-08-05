# Dual A/B report — W26-M OWN `aa_00811e00` + `aa_0096f660`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-M  
**Scope:** VAs `0x00811e00`, `0x0096f660` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00811e00` Client_ProcessSectorUpdate_Inferred | **accept-with-gaps** — multi-reg ABI + CF + string role sealed; nested physics helpers not OWN |
| `aa_0096f660` Material_ReleaseAndNullField0x18_Inferred | **accept** — 34 B refcount release + null `+0x18` CF/ABI/hex sealed |

---

## VA `0x00811e00` — sealed facts

1. **Body:** `0x00811e00`–`0x008120c8` (**713 B** / `0x2C9`); pad `CC` then create sibling `FUN_008120d0` @ `0x008120d0`.
2. **ABI:** **multi-reg** — **ECX** = packet body*; **EAX** = world object* (`in_EAX`/EDI); **Stack[0x4]** = game/client*; **`RET 4`**; void.
3. **Prologue:** align stack; `EBX=[EBP+8]` game; `EDI=EAX` object; `ESI=ECX` packet; `OutputDebugStringA("Requesting ProcessSectorUpdate\n")` string @ `0x00a7f17c`.
4. **CF stages:**
   - `packet+0xA1 ≠ 0` → `vtbl+0xC4`, `FUN_009972a0`, `FUN_008024d0` → return
   - bind match via `game+0xE98` vs `obj+0xAC` → return
   - `(pkt+8 & pkt+0xC) ≠ 0xFFFFFFFF` → `vtbl+0x260` → return
   - merge `packet+0xA8` into `obj+0x17C` bit2; optional `FUN_0092a200` mark
   - physics `vtbl+0x1CC`; copy transform `pkt+0x64..` → `obj+0x80..`; phys bit @ adj `+0x188`; apply via `FUN_004e87d0` / `FUN_004e88e0` + phys vtbls
5. **Callers (7):** `FUN_008122e0`, `FUN_00812320`, `FUN_00812360`, `FUN_00814400`, `FUN_00814470`, `FUN_008144b0`, `FUN_008144f0`.
6. **Callees:** `OutputDebugStringA`, `FUN_009972a0`, `FUN_008024d0`, `FUN_0092a200`, `FUN_004e87d0`, `FUN_004e88e0` + object/phys vtbls.
7. **Name:** `Client_ProcessSectorUpdate_Inferred` (Ghidra `FUN_00811e00`; string-backed).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for multi-caller packet family.  
- Nested helper full CF (`004e87d0` / `004e88e0` / `008024d0` / `009972a0`) — not OWN.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00811e00_Client_ProcessSectorUpdate_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00811e00_Client_ProcessSectorUpdate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00811e00_FUN_00811e00.md` |
| Annotated | `docs/reconstruction/raw/aa_00811e00_FUN_00811e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ProcessSectorUpdate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00811e00.cpp` |
| Function | `docs/reconstruction/functions/aa_00811e00_FUN_00811e00.md` |
| Function named | `docs/reconstruction/functions/aa_00811e00_Client_ProcessSectorUpdate_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00811e00.md` |

---

## VA `0x0096f660` — sealed facts

1. **Body:** `0x0096f660`–`0x0096f681` (**34 B** / `0x22`); pad `CC` after `POP ESI; RET`.
2. **ABI:** **`__fastcall`**; **ECX** = holder `int*`; void; plain `RET`.
3. **Semantics:** `obj=*holder`; if null return; `res=*(obj+0x18)`; if res: `--*(res+4)`; if zero `call [(*res)+8]`; always `*(obj+0x18)=0`.
4. **Classification:** near-leaf (0 direct FUN_* callees; 1 indirect vtbl).
5. **Callers (2):** `FUN_0051aed0` (pickup paint when `def+0x3F4==8`), `FUN_005dbca0` (paint RGB apply) — both after `FUN_009700f0` MatAmbient/Diffuse/Emissive.
6. **Name:** `Material_ReleaseAndNullField0x18_Inferred` (Ghidra `FUN_0096f660`).
7. **Decompile ≡ bytes** (full body hex sealed).

### Gaps

- Product type / vtbl[+8] English (`Release` vs custom).  
- Allocator of `+0x18` slot (`FUN_009700f0` sibling) — not OWN.  
- Runtime — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096f660_Material_ReleaseAndNullField0x18_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0096f660_Material_ReleaseAndNullField0x18_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096f660_FUN_0096f660.md` |
| Annotated | `docs/reconstruction/raw/aa_0096f660_FUN_0096f660.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Material_ReleaseAndNullField0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f660.cpp` |
| Function | `docs/reconstruction/functions/aa_0096f660_FUN_0096f660.md` |
| Function named | `docs/reconstruction/functions/aa_0096f660_Material_ReleaseAndNullField0x18_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0096f660.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00811e00` | Create-or-update handlers must call this **update** path with **object in EAX**, packet in **ECX**, game on **stack** — not a pure thiscall. Honor `packet+0xA1` early path, bind-skip, partial-id branch, and transform source offsets. Sibling create = `FUN_008120d0`. |
| `0096f660` | After MatAmbient/Diffuse/Emissive (or equivalent constant writes), release holder field `+0x18` with refcount semantics; always null the slot. Skipping leaks or leaves stale material state on paint paths. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented retail product names; `_Inferred` where string/role only.
