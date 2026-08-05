# Dual A/B report — W26-E OWN `aa_0055fa40` + `aa_0053dbb0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-E  
**Scope:** VAs `0x0055fa40`, `0x0053dbb0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0055fa40` WorldObj_BindLinks_Inferred | **accept** — manager thiscall + ret 4 + scale 0.5f + simple/complex bind CF sealed |
| `aa_0053dbb0` CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred | **accept** — virtual mode apply + rebind + tail SwitchHBAI 1/6 CF/ABI sealed |

---

## VA `0x0055fa40` — sealed facts

1. **Body:** `0x0055fa40`–`0x0055fbeb` (**428 B**; pad `CC` after last `ret 4`).
2. **ABI:** **thiscall**; ECX = **manager**; stack = **world object**; **void**; `ret 4`.
3. **Gate:** early return if `*(obj+0xc) == 0`.
4. **Scale:** `*(float*)(*(manager+0xcc)+8) * DAT_00a0f298` with `DAT_00a0f298` = **0.5f** (`00 00 00 3F`).
5. **Attach:** if `(int)scale > 0`: simple `FUN_006297e0` when `obj+0x40==0`; else stack worklist + `FUN_006caaa0` multi-entry + optional allocator free.
6. **Teardown:** `FUN_0055f4c0` (local container / arena free).
7. **Callers (5):** `FUN_00560e90` (RebindActivate), `FUN_00560ec0`, `FUN_00560f30`, `FUN_00560f70`, `FUN_00561370`.
8. **Name:** `WorldObj_BindLinks_Inferred` (Ghidra `FUN_0055fa40`; matches prior RebindActivate dual language).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque original name.  
- Nested attach helpers `006297e0` / `006caaa0` / `0062d960` (not OWN).  
- Runtime bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055fa40_WorldObj_BindLinks_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0055fa40_WorldObj_BindLinks_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055fa40_FUN_0055fa40.md` |
| Annotated | `docs/reconstruction/raw/aa_0055fa40_FUN_0055fa40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_BindLinks_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055fa40.cpp` |
| Function | `docs/reconstruction/functions/aa_0055fa40_FUN_0055fa40.md` |
| Function named | `docs/reconstruction/functions/aa_0055fa40_WorldObj_BindLinks_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055fa40.md` |

---

## VA `0x0053dbb0` — sealed facts

1. **Body:** `0x0053dbb0`–`0x0053dcf6` (**327 B**; pad `CC` after last RET).
2. **ABI:** **thiscall**; ECX = **CVOGObject***; stack **char modeFlag**; **void**; `ret 4`.
3. **Virtual:** 8 rdata vtable xrefs; **0** direct function callers.
4. **Mode branch:** flag==0 → self vtbl **+0x10**; else self vtbl **+0xc**, `*(host+0x28)=0x10`, children vtbl **+8**(4).
5. **Always:** `FUN_00560e90(host, 1)` — WorldObj_RebindActivate (unbind+bind+flag).
6. **AI notify:** locked pair on `*(host+0x3c)` vtbl **+0x50** / **+0x54** with `DAT_00b04610`.
7. **Optional SwitchHBAI:** when `(host+0x40==0) || (host+8==0)` → tail `FUN_005d4440` with code **1** (flag==0) or **6** (flag≠0). Both JMP targets verified `0x005d4440`.
8. **Name:** `CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred` (Ghidra `FUN_0053dbb0`).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for modeFlag / stamp `0x10` / child arg 4.  
- Subclass inventory for 8 vtable installs.  
- Lock helpers `005070b0`/`005070d0` not OWN.  
- Runtime bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0053dbb0_FUN_0053dbb0.md` |
| Annotated | `docs/reconstruction/raw/aa_0053dbb0_FUN_0053dbb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0053dbb0.cpp` |
| Function | `docs/reconstruction/functions/aa_0053dbb0_FUN_0053dbb0.md` |
| Function named | `docs/reconstruction/functions/aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0053dbb0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0055fa40` | Client phys/world rebind must call **unbind then bind** with manager ECX. Bind uses **0.5f** profile scale and branches on `obj+0x40`. Do not skip multi-entry path when flag set. Closes residual left open by W24-B RebindActivate dual. |
| `0053dbb0` | Mode-flag apply is **virtual**: rebind always; AI switch only when host incomplete. Codes **1** vs **6** must match `CVOGObject_SwitchHBAIByCode` dual. Server NPC mode transitions need same pairing to avoid wrong HBAI family. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + get_function_by_address (+ callers/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
