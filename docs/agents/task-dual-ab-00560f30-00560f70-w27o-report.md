# Dual A/B report — W27-O OWN `aa_00560f30` + `aa_00560f70`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-O  
**Scope:** VAs `0x00560f30`, `0x00560f70` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00560f30` WorldObj_ReattachLinksGuarded_Inferred | **accept** — flag-guarded attach+bind; ret 4; sole SwitchHBAI enter-mode-7 site |
| `aa_00560f70` WorldObj_RehomeLinksFromSnapshot_Inferred | **accept-with-gaps** — phase 0–3 CF + ret 8 sealed; `unaff_EBX` residual + product names open |

---

## VA `0x00560f30` — sealed facts

1. **Body:** `0x00560f30`–`0x00560f60` (**48 B**; pad `CC` after `ret 4`).
2. **ABI:** **thiscall**; ECX = **manager**; stack = **world object**; **void**; **`ret 4`**.
3. **Flag:** save `*(manager+0x12c)`; set **1**; restore after callees (same slot as enroll).
4. **Order:** `FUN_0055e760(obj)` then `FUN_0055fa40(obj)` (`WorldObj_BindLinks_Inferred`).
5. **Not** enroll (`00560ec0`) and **not** `WorldObj_RebindActivate` (`00560e90` / unbind `0055fbf0` / `ret 8`).
6. **Caller (1):** `FUN_005d4440` @ `0x005d46e0` when **new** mode code == **7** (`PUSH obj; MOV ECX,mgr`).
7. **Name:** `WorldObj_ReattachLinksGuarded_Inferred` (Ghidra `FUN_00560f30`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for manager / mode **7**.  
- Nested `FUN_0055e760` dual (not OWN).  
- Runtime bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00560f30_WorldObj_ReattachLinksGuarded_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00560f30_WorldObj_ReattachLinksGuarded_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00560f30_FUN_00560f30.md` |
| Annotated | `docs/reconstruction/raw/aa_00560f30_FUN_00560f30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_ReattachLinksGuarded_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560f30.cpp` |
| Function | `docs/reconstruction/functions/aa_00560f30_FUN_00560f30.md` |
| Function named | `docs/reconstruction/functions/aa_00560f30_WorldObj_ReattachLinksGuarded_Inferred.md` |

---

## VA `0x00560f70` — sealed facts

1. **Body:** `0x00560f70`–`0x00561312` (**930 B** / `0x3A2`; pad `CC` after `ret 8`).
2. **ABI:** **thiscall**; ECX = **manager**; stack #1 = **object**; stack #2 = **snapshot** `{ptr*, count}`; **void**; **`ret 8`**.
3. **Phase 0:** same guarded reattach as `00560f30` (flag + `0055e760` + `0055fa40`).
4. **Phase 1:** snapshot children → host `obj+0x44` list `+0x58` (grow `005b3370` elem 4); child `vtbl+0x28`; second virtual (**`unaff_EBX` residual**); `child+0x14 = host`.
5. **Phase 2:** link array `obj+0x88/+0x8c`; skip when `vtbl+0x20()==0xb`; else **open-coded** body-pair push on `manager+0x20` (≡ `PhysSim_PushBodyPair` / `0055efd0` policy via `005b3300` elem 8).
6. **Phase 3:** action array `obj+0x94/+0x98`; match host reverse list at `*(manager+0x2c)+0x4c`; on hit `006292a0` + `00628f10`; `action+0x10 = host`; neighbor collect `vtbl+0x18` + arena `DAT_00b05060`; more pairs.
7. **Caller (1):** `FUN_005d4440` @ `0x005d46d3` when **old** mode code == **7** (snapshot from `FUN_005617c0`).
8. **Name:** `WorldObj_RehomeLinksFromSnapshot_Inferred` (Ghidra `FUN_00560f70`).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for mode **7** / snapshot producer `005617c0`.  
- Exact second-virtual after child `vtbl+0x28` (`unaff_EBX`).  
- Link type code **0xb** product meaning.  
- Arena allocator dual.  
- Runtime bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00560f70_WorldObj_RehomeLinksFromSnapshot_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00560f70_WorldObj_RehomeLinksFromSnapshot_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00560f70_FUN_00560f70.md` |
| Annotated | `docs/reconstruction/raw/aa_00560f70_FUN_00560f70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_RehomeLinksFromSnapshot_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00560f70.cpp` |
| Function | `docs/reconstruction/functions/aa_00560f70_FUN_00560f70.md` |
| Function named | `docs/reconstruction/functions/aa_00560f70_WorldObj_RehomeLinksFromSnapshot_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00560f30` | After client HBAI / phys mode switch **into** code **7**, call **guarded attach+bind** with manager ECX — **not** enroll and **not** unbind+rebind (`00560e90`). Preserve `+0x12c` save/restore. |
| `00560f70` | After switch **out of** code **7**, rehome using the **snapshot** captured by `005617c0`: children onto host list, body pairs on `manager+0x20` (open-coded or shared helper), actions via host list push + reverse remove. Skipping any phase desyncs island glue / action ownership. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze_function_complete + get_function_by_address + assembly context at call sites.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names — `_Inferred` structural names only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / `uint8_t`).
