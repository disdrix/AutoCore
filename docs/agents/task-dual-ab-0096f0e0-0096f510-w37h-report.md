# Dual A/B report — W37-H OWN `aa_0096f0e0` + `aa_0096f510`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-H  
**Scope:** VAs `0x0096f0e0`, `0x0096f510` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-H).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0096f0e0` EffTexture_CreateOrAssignSlot_Inferred | **accept-with-gaps** — thiscall slot create-or-assign; plates + ref@+8/iface@+4 sealed; factory arg English open |
| `aa_0096f510` RefCountedPtr3Flags_Dtor_Inferred | **accept-with-gaps** — 18 B leaf dtor; ref@+4 / tail JMP vtbl[+8]; peer ctor W35-G sealed; payload English open |

---

## VA `0x0096f0e0` — sealed facts

1. **Body:** `0x0096f0e0`–`0x0096f15c` exclusive (**124 B** / `0x7C`; pad `CC`).
2. **ABI:** **ECX=`slot*`** (`mov edi,ecx`); **6 stack dwords**; **`RET 0x18`**; returns **0** / **`0xffffffff`**. One stack dword dead-loaded to EBX.
3. **Semantics:** effect-texture **create-or-assign**:
   - `FUN_0096e9f0` (five pushes; Ghidra factory formals under-declared).
   - Fail → `vog_LogMessage` path `0x00a9ed50` (`…\Effects\effTexture.cpp`), line **`0x57`**, severity **3**, msg `0x00a9ed24` `"Failed to create instance of texture."` → **-1**.
   - Success → `++ref@+8`; if first, thiscall **vtbl[+4]** on subobject **+4**; release prior `*slot` (dec +8 / final **vtbl[+8]** on +4); `*slot = neu`; **0**.
4. **Classification:** worker — create-or-replace assign helper for texture slots.
5. **Callers (15 named + xrefs):** `FUN_0048ed00` (PalantirEnv_InitEffectTextures ×2), `FUN_004c0fe0`, `FUN_0055cf60`×4, `FUN_0055d8c0`×4, `FUN_005843b0`, `FUN_00586c40`×3, `FUN_005c0f40`×2, `FUN_0073cb70`/`0073cd70`, `FUN_00754fb0`, `FUN_007fa420`, `FUN_00850490`×2, `FUN_00858080`×2, `FUN_008d42b0`, `FUN_008edf80`, …
6. **Callees:** `FUN_0096e9f0`, `vog_LogMessage`.
7. **Name:** `EffTexture_CreateOrAssignSlot_Inferred` (Ghidra `FUN_0096f0e0`; **Inferred**). Reject scaffold `Named_effTexture_0096f0e0`.
8. **Layout:** payload **iface@+4 / ref@+8** (same family as `0096efd0`) — **not** RefCountedPtr3Flags.  
   Full hex: raw W37-H append (124 B). Decompile ≡ raw 2026-07-23 CF.

### Gaps

- Factory argument product English (format/dims/usage).  
- Virtual method names at vtbl[+4]/[+8].  
- Full dual of unowned factory `0096e9f0`.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096f0e0_EffTexture_CreateOrAssignSlot_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096f0e0_EffTexture_CreateOrAssignSlot_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096f0e0_FUN_0096f0e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096f0e0_FUN_0096f0e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffTexture_CreateOrAssignSlot_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f0e0.cpp` |
| Function | `docs/reconstruction/functions/aa_0096f0e0_FUN_0096f0e0.md` |
| Function named | `docs/reconstruction/functions/aa_0096f0e0_EffTexture_CreateOrAssignSlot_Inferred.md` |

---

## VA `0x0096f510` — sealed facts

1. **Body:** `0x0096f510`–`0x0096f522` exclusive (**18 B** / `0x12`; pad `CC` to ctor `0x0096f530`).
2. **ABI:** **ECX=`handle*`**; bare **`C3`**; **void**. No stack formals. **No SEH**.
3. **Semantics:** **RefCountedPtr3Flags dtor/release**:
   - `payload = *handle`; if null return.
   - `--refcount` at payload **+4**; if remaining return.
   - **Tail `JMP [vtbl+8]`** (`FF 60 08`) — not CALL; decompiler "jumptable" warning is noise.
   - **Does not clear `*handle`**. Does not touch handle flag bytes +4/+5/+6.
4. **Classification:** leaf / worker (dtor paired with default ctor).
5. **Callers:** many SEH `Unwind@*`; named include `CVOGTacArc_dtor_helper`, `FUN_0048fc90`, `FUN_004c0fe0`×4, `FUN_00586c40`×4, ParticleFluid/graphics hosts; **DATA** dtor slots `@0045777b` / `@004577d0` (vector size **8** with ctor `0096f530`).
6. **Callees:** none direct (indirect Release only).
7. **Name:** `RefCountedPtr3Flags_Dtor_Inferred` (Ghidra `FUN_0096f510`; **Inferred**). Peer ctor W35-G `RefCountedPtr3Flags_DefaultCtor_Inferred` @ `0x0096f530`. Reject scaffold `Named_CalleeOf_CVOGTacArc_dtor_helper_0096f510`.
8. **Hex:** `8b 09 85 c9 74 0b 83 41 04 ff 75 05 8b 01 ff 60 08 c3`. Decompile ≡ raw CF; bytes win on JMP vs CALL presentation.

### Gaps

- Product/RTTI English of payload type.  
- Whether hosts require post-dtor null store (this unit never writes).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096f510_RefCountedPtr3Flags_Dtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0096f510_RefCountedPtr3Flags_Dtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096f510_FUN_0096f510.md` |
| Annotated | `docs/reconstruction/raw/aa_0096f510_FUN_0096f510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RefCountedPtr3Flags_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096f510.cpp` |
| Function | `docs/reconstruction/functions/aa_0096f510_FUN_0096f510.md` |
| Function named | `docs/reconstruction/functions/aa_0096f510_RefCountedPtr3Flags_Dtor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0096f0e0` | Port as **effect-texture create-or-assign**: **ECX=slot***, **6 stack args**, **RET 0x18**, return **0/-1**. Acquire new + release prior via **ref@+8 / iface@+4**. Log fail from plates. Do **not** merge with `0096f510` release layout. |
| `0096f510` | Port as **RefCountedPtr3Flags dtor**: **ECX=handle***, bare RET, void. Dec payload ref@**+4**; tail Release vtbl[+8]. Do **not** clear handle; do **not** touch flags. Pair with ctor `0096f530`. Do **not** substitute `0096efd0`. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0096e9f0` | Texture factory (callee of `0096f0e0`) |
| `0x0096ef70` / `0x0096efd0` | RefCountedPtr default ctor / dtor (ref@+8 family) |
| `0x0096f530` | RefCountedPtr3Flags_DefaultCtor (W35-G peer of `0096f510`) |
| `0x0048ed00` | PalantirEnv_InitEffectTextures — dual create via `0096f0e0` |
| `0x00457720` | vector_ctor binds size 8, ctor=`0096f530`, dtor=`0096f510` |
| `0x00a9ed50` / `0x00a9ed24` | effTexture path / fail plate |

Together they close the **effTexture create-or-assign slot helper** used by Palantir env init and the **missing peer dtor** of W35-G `RefCountedPtr3Flags_DefaultCtor`.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf / underspecified Named_effTexture scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
