# Dual A/B report — W31-T OWN `aa_0094e530` + `aa_005825d0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-T  
**Scope:** VAs `0x0094e530`, `0x005825d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-T).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0094e530` Client_DebugCmd_AddDisciplinePoints | **accept-with-gaps** — CF/ABI/`ret 8`/strtok tokens/Set+optional max/command plate sealed; key catalog residual |
| `aa_005825d0` Object_UnloadGraphics_Inferred | **accept-with-gaps** — CF/ABI/bare RET/manager-this residual/UnloadGraphics role/state 3 sealed; product vfunc English open |

---

## VA `0x0094e530` — sealed facts

1. **Body:** `0x0094e530`–`0x0094e617` exclusive (**231 B** / `0xE7`); pad `CC` after.
2. **ABI:** **`__thiscall`**; ECX = **client**; stack `(unused, delim*)`; returns **1** fail / **0** ok; **`ret 8`**.
3. **Semantics:** continue-`strtok`/`atoi` → key + amount (required); optional third token `1` → also set max; require `*(client+0xe98)`; `CVOGCharacter_SetMissionCounter` then optional `FUN_0052ade0` (mapped `+0x10` clamp to `+0x14`, dirty `+0x634\|=0x40`); UI `client+0x1074` active (`vtbl+0x3d8`) → `vtbl+0x448`.
4. **Classification:** worker.
5. **Registration:** sole xref DATA imm in `Client_RegisterDebugSlashCommands` @ `0x00959294` — name **`adddisciplinepoints`**, help **`Set discipline [x] to [y], [1] to set max as well`**.
6. **Callees:** `strtok` (IAT `*0x009c6684`), `atoi` (IAT `*0x009c667c`), `FUN_005305b0` (W30-I sealed), `FUN_0052ade0`.
7. **Name:** `Client_DebugCmd_AddDisciplinePoints` (Ghidra `FUN_0094e530`; **Inferred** from slash plate).
8. **Decompile ≡ bytes** for CF; character ECX on nested calls sealed by machine.  
   Full hex: raw W31-T append (231 B).

### Gaps

- Product/MSVC demangle; discipline key catalog.  
- Unused stack formal 0 role.  
- Nested `FUN_0052ade0` product English (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0094e530_Client_DebugCmd_AddDisciplinePoints.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0094e530_Client_DebugCmd_AddDisciplinePoints.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0094e530_FUN_0094e530.md` |
| Annotated | `docs/reconstruction/raw/aa_0094e530_FUN_0094e530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_DebugCmd_AddDisciplinePoints.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0094e530.cpp` |
| Function | `docs/reconstruction/functions/aa_0094e530_FUN_0094e530.md` |
| Function named | `docs/reconstruction/functions/aa_0094e530_Client_DebugCmd_AddDisciplinePoints.md` |
| Scratch | `docs/reconstruction/tmp/a_0094e530.md` |

---

## VA `0x005825d0` — sealed facts

1. **Body:** `0x005825d0`–`0x00582664` exclusive (**148 B** / `0x94`); pad `CC` then `FUN_00582670`.
2. **ABI:** **`__thiscall`** (Ghidra `__fastcall`); ECX = **MI this**; bare **`RET`** (`C3`); void.
3. **Semantics:**
   - `FUN_004bfd10(manager, this)` with manager = `*(*(MI_host_via_vb+0xA8)+0xE914)` — **bytes win** over decompiler `FUN_004bfd10(this)`.
   - Clear flag `this+0x0F = 0`.
   - Object root `vtbl+0x144()`; `Object_SetMissionStateFx_Inferred(root, 3)` (W30-H).
   - Optional host notify `*(host+0xE500)->vtbl[0](root)`.
   - Object `vtbl+0xFC()`; self `vtbl+0x04()`; self `vtbl+0x18(0)` then `(1)`.
4. **Classification:** worker.
5. **CODE callers (1):** `FUN_005d4fd0` @ `0x005d5016` (logs `"UnloadGraphics on %s (%d)"` then body).
6. **DATA:** 14 vtable installs (see raw).
7. **Name:** `Object_UnloadGraphics_Inferred` (Ghidra `FUN_005825d0`; **Inferred** from caller string).
8. **Decompile ≡ raw CF spine**; first-callee this residual closed by bytes.  
   Full hex: raw W31-T append (148 B).

### Gaps

- Product class / vfunc English (`+0x144` / `+0xFC` / self `+0x18`).  
- Nested `FUN_004bfd10` product type.  
- Host fields `+0xA8` / `+0xE500` / `+0xE914` product names.  
- Full vtable-slot atlas for 14 DATA xrefs.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005825d0_Object_UnloadGraphics_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005825d0_Object_UnloadGraphics_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005825d0_FUN_005825d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005825d0_FUN_005825d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_UnloadGraphics_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005825d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005825d0_FUN_005825d0.md` |
| Function named | `docs/reconstruction/functions/aa_005825d0_Object_UnloadGraphics_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005825d0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0094e530` | Port as **debug slash only**: parse key/amount; absolute set via sealed `CVOGCharacter_SetMissionCounter`; optional third token `1` also sets max (`+0x10`) via `FUN_0052ade0` + dirty `0x40`. Do **not** use AddMissionCounter. Refresh UI `client+0x1074` when active. |
| `005825d0` | Port as **unload-graphics core** (not full delete). Untrack via manager at host`+0xE914`; clear `+0x0F`; destroy-graphics `vtbl+0x144`; mission FX state **3**; optional notify `+0xE500`; residual virtuals. Prefer bytes over decompiler for first callee this. |
| Pair with | `CVOGCharacter_SetMissionCounter` (`0x005305b0`), `Object_SetMissionStateFx_Inferred` (`0x00518370`), `Client_RegisterDebugSlashCommands` (`0x00959230`), wrapper `FUN_005d4fd0`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw body for `005825d0` preserved; re-verify **appended** only. New raw for `0094e530`.  
- No invented product plates; structural / slash-string / caller-string names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit pointers).  
- Closed decompiler residual on `005825d0` first callee this via machine bytes.
