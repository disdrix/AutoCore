# Dual A/B report — W28-H OWN `aa_005179e0` + `aa_00514d80`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-H  
**Scope:** VAs `0x005179e0`, `0x00514d80` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005179e0` Object_TeardownOwnedFxLists_Inferred | **accept** — ABI + free gate + always-zero triad + caller chain sealed |
| `aa_00514d80` Object_StopTypeF_ReloadEventVariant_Inferred | **accept** — type-0xF stop + LoadEvent pack + virtual apply sealed |

---

## VA `0x005179e0` — sealed facts

1. **Body:** `0x005179e0`–`0x00517a6a` (**139 B / `0x8B`**); pad `CC`.
2. **ABI:** **thiscall**; ECX = object host; plain **`RET` (`C3`)**; no stack formals cleaned.
3. **Classification:** **worker** + **virtual** (4 DATA vtable installs) + 2 CODE callers.
4. **Spine:**
   - `FUN_00516930(this, 0)` — secondary ptr-vector at `+0x138` (callee **`ret 4`**).
   - Optional `FUN_00517250(this, *(this+0x130))`; clear sticky `+0x130`.
   - Walk primary `+0x124..+0x128` (stride **4**): if `fx+9==0` && `NDSpecialFX_StopFinalize_Inferred(fx)` → `TeardownCore` + `delete`.
   - Free begin buffer if non-null; **always** zero `+0x124/+0x128/+0x12c`.
5. **Byte corrections vs decompile:** StopFinalize/TeardownCore ECX = fx\*; post-`operator_delete` triad zeroing (false noreturn collapsed it); `FUN_00516930` stack formal **0** is real.
6. **CODE callers:** `FUN_00518ec0` @ `0x00518f8b` (call); `FUN_00584330` @ `0x005843ab` (**tail jmp**, vbase-adjusted this — W26-K).
7. **Name:** `Object_TeardownOwnedFxLists_Inferred` (Ghidra `FUN_005179e0`).
8. **Decompile ≡ bytes** for outer free-gate CF; epilogue zeroing sealed only via `read_memory`.

### Gaps

- Product English / C++ class.  
- Nested duals of `FUN_00516930` / `FUN_00517250` (not OWN).  
- Runtime / bit-diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005179e0_Object_TeardownOwnedFxLists_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005179e0_Object_TeardownOwnedFxLists_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005179e0_FUN_005179e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005179e0_FUN_005179e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_TeardownOwnedFxLists_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005179e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005179e0_FUN_005179e0.md` |
| Function named | `docs/reconstruction/functions/aa_005179e0_Object_TeardownOwnedFxLists_Inferred.md` |

---

## VA `0x00514d80` — sealed facts

1. **Body:** `0x00514d80`–`0x00514df3` (**116 B / `0x74`**); pad `CC`.
2. **ABI:** **thiscall** impl; plain **`RET` (`C3`)**. Public entry via MI thunk `FUN_00581500` (vb-adjust `this`, **`ret 4`** — one ignored stack dword on virtual ABI).
3. **Classification:** **worker**; sole CODE caller is the thunk.
4. **Spine:**
   - Walk same primary vector `+0x124..+0x128`.
   - If `*(fx+0x28) == 0x0F` → `NDSpecialFX_StopFinalize_Inferred(fx)` (**no free**).
   - `linked = *(this+0xA8)`; `FUN_004eb3b0(linked)` Ensure.
   - If `*(linked+0x88) != 0`: Ensure again; `FxMaster_LoadEventVariant_Inferred(catalog, 0xF, 1, -1)`; if non-null → `this->vtbl[+0xF8](fx, 1, 0)`.
5. **Byte corrections vs decompile:** ECX setups for StopFinalize (`*it`), Ensure (`*(this+0xA8)`), LoadEvent (`*(linked+0x88)`); push pack `0xF / 1 / -1`.
6. **Shared layout:** primary FX* vector triad with `005179e0` (stop-only vs free-teardown).
7. **Name:** `Object_StopTypeF_ReloadEventVariant_Inferred` (Ghidra `FUN_00514d80`).
8. **Decompile ≡ bytes** for type gate + reload CF (live 2026-07-29 ≡ raw 2026-07-23 outer spine).

### Gaps

- Product English for event 0xF / `vtbl+0xF8`.  
- Nested dual of Ensure / vfunc target (not OWN).  
- Runtime / bit-diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00514d80_Object_StopTypeF_ReloadEventVariant_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00514d80_Object_StopTypeF_ReloadEventVariant_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00514d80_FUN_00514d80.md` |
| Annotated | `docs/reconstruction/raw/aa_00514d80_FUN_00514d80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_StopTypeF_ReloadEventVariant_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00514d80.cpp` |
| Function | `docs/reconstruction/functions/aa_00514d80_FUN_00514d80.md` |
| Function named | `docs/reconstruction/functions/aa_00514d80_Object_StopTypeF_ReloadEventVariant_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005179e0` | Object FX list teardown used by destroy path and ApplySingleFxSlot tail. Preserve free gate (`+9` + StopFinalize polarity), secondary list first, **always** clear vector triad. Do **not** free entries that fail the gate. |
| `00514d80` | Type-0xF stop-without-free then LoadEventVariant reload + virtual apply. Distinct from full teardown. Keep Ensure on `+0xA8`, pack `(0xF,1,-1)`, vtbl `+0xF8`. Public MI path may ignore one stack dword. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs/callers/callees). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence (`_Inferred` only).  
- Avoided bare `undefined4` in clean (`uint32_t` / typed voids).
