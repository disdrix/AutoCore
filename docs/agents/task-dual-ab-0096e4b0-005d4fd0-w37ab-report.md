# Dual A/B report — W37-AB OWN `aa_0096e4b0` + `aa_005d4fd0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-AB  
**Scope:** VAs `0x0096e4b0`, `0x005d4fd0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-AB).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0096e4b0` LightHost_Ctor_Inferred | **accept-with-gaps** — ctor CF/ABI/offsets/vtable/3 xrefs/size-via-callers sealed; product demangle open |
| `aa_005d4fd0` Object_UnloadGraphics_Entry_Inferred | **accept-with-gaps** — log string/core call/tail JMP/8 DATA xrefs sealed; format `%d` residual + product vfunc English open |

**Terminal coverage:** false (both).

---

## VA `0x0096e4b0` — sealed facts

1. **Body:** `0x0096e4b0`–`0x0096e4d1` exclusive (**33 B** / `0x21`). Final **`C3`** @ `0x0096e4d0`; pad `CC`.
2. **ABI:** **`__thiscall`** (Ghidra `__fastcall`); ECX=`this*`; returns **this** in EAX; bare **`RET`**.
3. **Semantics:**
   - Base ctor `FUN_0096d830(this)` (base vtable `PTR_FUN_00aa0824` + POD defaults).
   - Zero **`this+0x8c`** and **`this+0x90`** (effect-core slots).
   - Install derived vtable **`PTR_FUN_00aa0394`**.
4. **Object size (callers):** `operator_new(0x94)` — W32-R RebuildDefaultLights; particle path `FUN_0058f780`.
5. **Classification:** worker (ctor).
6. **CODE callers (2 fn / 3 sites):**
   - `FUN_0048f370` (`PalantirEnv_RebuildDefaultLights_Inferred`) @ `0048f3b1`, `0048f5a0` → `env+0x108` / `env+0x104`
   - `FUN_0058f780` @ `0058fac1` → `geom+0x91c` (Point light when `+0x90f & 2`)
7. **Xrefs:** 3.
8. **Callees:** `FUN_0096d830` only.
9. **Vtable slot0:** `0x004493d0` scalar-deleting dtor → `FUN_004492e0` + optional `operator_delete`.
10. **Name:** `LightHost_Ctor_Inferred` (Ghidra `FUN_0096e4b0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0096e4b0`.
11. **Decompile ≡ raw CF**; offsets sealed by full-body `read_memory`.  
    Full hex: `568bf156e877f3ffff33c089868c000000898690000000c7069403aa008bc65ec3`

### Gaps

- Product English / MSVC demangle for class of `PTR_FUN_00aa0394`.  
- Field English for `+0x90`.  
- Complete dtor `FUN_004492e0` (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096e4b0_LightHost_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096e4b0_LightHost_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096e4b0_FUN_0096e4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096e4b0_FUN_0096e4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LightHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096e4b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0096e4b0_FUN_0096e4b0.md` |
| Function named | `docs/reconstruction/functions/aa_0096e4b0_LightHost_Ctor_Inferred.md` |
| Legacy scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvLoginCa_0096e4b0.cpp` (**reject** as canonical) |

---

## VA `0x005d4fd0` — sealed facts

1. **Body:** `0x005d4fd0`–`0x005d5025` exclusive (**85 B** / `0x55`). Tail **`FF 60 04`**; pad `CC`.
2. **ABI:** **`__thiscall`** (Ghidra `__fastcall`); ECX = **MI object\***; void; **tail JMP** (not bare RET).
3. **Semantics:**
   - Name id from optional record via vbtable path (`root+0x6c` → `+0x34`, else **`-1`**).
   - Root **`vtbl+0x160(nameId)`** → log argument.
   - `FUN_007a4480(-1, "UnloadGraphics on %s (%d)" @ 0x009dac54, arg)`.
   - **`Object_UnloadGraphics_Inferred`** (`FUN_005825d0`, W31-T) with same ECX.
   - Tail: `LEA ECX,[this-0x40]; JMP [*(this-0x40)+4]`.
4. **Classification:** worker (logged unload entry / MI chain).
5. **CODE callers:** none.
6. **DATA xrefs (8):** `009ce7e0`, `009ceb30`, `009d4c90`, `009da6d8`, `009db8f0`, `009cbe40`, `009cd748`, `009cfd60`.
7. **Callees:** vcall `+0x160`, `FUN_007a4480`, `FUN_005825d0`, tail vfunc `+4`.
8. **Name:** `Object_UnloadGraphics_Entry_Inferred` (Ghidra `FUN_005d4fd0`; **Inferred** from string + core relationship).
9. **Decompile ≡ raw CF spine**; tail form corrected by bytes (JMP vs call+return warning).  
    Full hex: `568bf18b46c48b48048d4431c48b80a800000085c0750583c8ffeb038b40348b56c48b4a048b5431c48d4c31c450ff9260010000506854ac9d006affe86ff41c0083c4108bcee8b5d5faff8b46c08d4ec05eff6004`

### Gaps

- Format string has `%s` and `%d` but only **one** intentional vararg after format (bytes).  
- Product English for `vtbl+0x160`, name record, tail base method.  
- Full class atlas for 8 DATA installs.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d4fd0_FUN_005d4fd0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d4fd0_FUN_005d4fd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_UnloadGraphics_Entry_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d4fd0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d4fd0_FUN_005d4fd0.md` |
| Function named | `docs/reconstruction/functions/aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0096e4b0` | Port as **light-host ctor** after `new(0x94)`: base init, clear `+0x8c`/`+0x90`, bind vtable `00aa0394`. Do **not** set type/color/dir here — callers use `FUN_0096e430` + effect at `+0x8c`. Pair with W32-R RebuildDefaultLights and particle Point path. |
| `005d4fd0` | Port as **vtable unload entry**: log name → `Object_UnloadGraphics_Inferred` (W31-T) → **tail** base `vtbl+4` at `this-0x40`. DATA-only install (8 slots). Prefer bytes for tail (not call+return). Format `%d` residual — do not invent second arg without further evidence. |
| Shared | Unrelated pair (light ctor vs object unload entry). No shared type. Both client-side; no Launcher. |
| Pair with | `PalantirEnv_RebuildDefaultLights_Inferred` (`0x0048f370`, W32-R); `Object_UnloadGraphics_Inferred` (`0x005825d0`, W31-T); base `FUN_0096d830`; log `FUN_007a4480`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze_function_complete + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W37-AB sections).  
- No invented product plates; `_Inferred` names from call-site role / embedded string.  
- Rejected scaffold `Named_CalleeOf_*` for light ctor.  
- Avoided bare `undefined4` as sole clean surface (`uint32_t` / structs / explicit pointers).  
- Closed decompiler residual on `005d4fd0` tail form via machine bytes (`FF 60 04`).
