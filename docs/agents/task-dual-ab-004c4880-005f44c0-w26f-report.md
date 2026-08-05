# Dual A/B report — W26-F OWN `aa_004c4880` + `aa_005f44c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-F  
**Scope:** VAs `0x004c4880`, `0x005f44c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c4880` Object_SetTFID_ApplyPhysMode_Rebind | **accept** — TFID_16 store + mode 10/0xB + WorldObj rebind CF/ABI sealed |
| `aa_005f44c0` GameUtils_createRagDoll | **accept** — plate `GameUtils::createRagDoll` CF/ABI/limits/outs sealed; nested helpers residual |

---

## VA `0x004c4880` — sealed facts

1. **Body:** `0x004c4880`–`0x004c48f1` (**114 B**; pad `CC` after `RET 4`).
2. **ABI:** **thiscall**; ECX = object; stack = `const uint32_t src[4]`; **void**; epilogue `POP EDI; POP ESI; RET 4`.
3. **Semantics:** Copy 16 B TFID to `this+0x108..+0x114`. If `*(this+8)` phys non-null: write `phys+0x28` = **0xB** when `(lo&hi)==~0 && (char)w2==0`, else **10**; then `FUN_00560e90` / `WorldObj_RebindActivate_Inferred`.
4. **Classification:** worker (1 callee).
5. **Callers (1):** `FUN_00626890` @ `0x0062690d`.
6. **Name:** `Object_SetTFID_ApplyPhysMode_Rebind` (Ghidra `FUN_004c4880`); TFID evidence from sibling `FUN_004c4440` (`dwCoidLo/Hi`, `TFID_16`); mode leaf sibling `FUN_004c4620`.
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23). Manager ECX rebuild present in bytes (decompiler surface omits — known 00560e90 residual).

### Gaps

- Product English for phys modes 10 / 0xB.  
- Manager chain product types.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c4880_FUN_004c4880.md` |
| Annotated | `docs/reconstruction/raw/aa_004c4880_FUN_004c4880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetTFID_ApplyPhysMode_Rebind.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c4880.cpp` |
| Function | `docs/reconstruction/functions/aa_004c4880_FUN_004c4880.md` |
| Function named | `docs/reconstruction/functions/aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md` |
| Scratch | `docs/reconstruction/tmp/a_004c4880.md` |

---

## VA `0x005f44c0` — sealed facts

1. **Body:** `0x005f44c0`–`0x005f4ed9` (**2586 B** inclusive; pad `CC` after).
2. **ABI:** **cdecl** + MSVC SEH; 3 stack formals; **EAX** 0\|1; epilogue `POP EBX; MOV ESP,EBP; POP EBP; RET`.
3. **Plate name:** `GameUtils::createRagDoll` (two error strings — params invalid / bones not found).
4. **Semantics:** Validate Body/world/buffer → parse bone count (`FUN_005f4380`) → enforce `<0x21` / `<0x41` → ensure maps → match bone names (space→`_`) → poses/parents → on full match build outs at `param_3+0x50..+0x5c` and return 1; else log + return 0.
5. **Callers (1):** `FUN_005911b0` @ `0x0059195e` (sets `@+0x90d` bit2 from result).
6. **Name:** `GameUtils_createRagDoll` (Ghidra `FUN_005f44c0`; supersedes SkyBox mis-tag).
7. **Decompile ≡ raw** for CF (live 2026-07-29 ≡ 2026-07-23); EH unreachable warnings non-blocking.

### Gaps

- Nested helper duals (`005f4380`, `005f5190`, `005f5490`, …) not OWN.  
- Full bone struct product field English.  
- Runtime post-create ragdoll dump — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005f44c0_GameUtils_createRagDoll.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005f44c0_GameUtils_createRagDoll.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005f44c0_FUN_005f44c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005f44c0_FUN_005f44c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GameUtils_createRagDoll.cpp` |
| Clean twins | `docs/reconstruction/reconstructed-exact/FUN_005f44c0.cpp`, `Named_GameUtils_createRagDoll.cpp` |
| Function | `docs/reconstruction/functions/aa_005f44c0_FUN_005f44c0.md` |
| Function named | `docs/reconstruction/functions/aa_005f44c0_GameUtils_createRagDoll.md` |
| Scratch | `docs/reconstruction/tmp/a_005f44c0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c4880` | When applying object TFID/COID identity client-side, also set phys mode (**0xB** unassigned vs **10** assigned) and run world rebind (`WorldObj_RebindActivate`). Do not store TFID alone if phys child exists. |
| `005f44c0` | Ragdoll create is plate-named `GameUtils::createRagDoll`. Port must honor bone-name space→underscore, caps 32/64, and owner output slots `+0x50..+0x5c`. Failure clears success bit used at `@+0x90d` bit2. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names: TFID name inferred from sibling types; ragdoll name from plate strings.
