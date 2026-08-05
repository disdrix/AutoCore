# Dual A/B report — W27-H OWN `aa_005f4380` + `aa_004c9120`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-H  
**Scope:** VAs `0x005f4380`, `0x004c9120` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005f4380` GameUtils_ParseRagDollBoneCount_Inferred | **accept** — SEH/cdecl/5-formals/count CF sealed; sole caller createRagDoll |
| `aa_004c9120` Object_CacheAIProfileFields_TypeMask_Inferred | **accept** — profile field cache + map type-bit + MI thunk entry sealed |

---

## VA `0x005f4380` — sealed facts

1. **Body:** `0x005f4380`–`0x005f441a` (**155 B** inclusive `C3`; pad `CC` after).
2. **ABI:** **cdecl** + MSVC SEH (`LAB_009a79e0`); **5** stack formals; **EAX** count; epilogue `POP ESI; POP EBX; FS restore; ADD ESP,0x28; RET`.
3. **Semantics:** Build primary container (`FUN_005f3120`) + secondary from `*(param_3+8)` (`FUN_00646d90`) → `count = FUN_005f4230(...)` → destroy both → return count.
4. **Classification:** worker (5 callees).
5. **Callers (1):** `GameUtils_createRagDoll` / `FUN_005f44c0` @ `0x005f45af` (machine **5 pushes**; parent decompiler may show 2 — bytes win).
6. **Name:** `GameUtils_ParseRagDollBoneCount_Inferred` (Ghidra `FUN_005f4380`; supersedes SkyBoxParticles mis-tag).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Nested helper duals (`005f3120`, `005f4230`, `00646d90`, …) not OWN.  
- Container / token product English.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005f4380_FUN_005f4380.md` |
| Annotated | `docs/reconstruction/raw/aa_005f4380_FUN_005f4380.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GameUtils_ParseRagDollBoneCount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005f4380.cpp` |
| Function | `docs/reconstruction/functions/aa_005f4380_FUN_005f4380.md` |
| Function named | `docs/reconstruction/functions/aa_005f4380_GameUtils_ParseRagDollBoneCount_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005f4380.md` |

---

## VA `0x004c9120` — sealed facts

1. **Body:** `0x004c9120`–`0x004c92e3` (**452 B** inclusive `C3`; pad `CC` after).
2. **ABI:** **thiscall/fastcall** ECX=this (mid-object); **void**; frame `SUB ESP,8` / `ADD ESP,8; RET`.
3. **Semantics:** `FUN_005c8eb0(this-0x3F0)` → resolve profile `+0x3c` via MI chain → copy 10 field slots → map key `*(profile+0x4dc)` via `Host_AIProfileMap_GetOrReset` + `Map_LowerBoundFindByIntKey_Isnil65` → on hit `*(this-0x300) = 1<<(node+0x10 & 0x1f)`.
4. **Classification:** worker (3 unique callees).
5. **Entry (2 MI adjustor thunks):** `0x004ccec0` (vtbl DATA `0x009cbb80`), `0x0053baa0` (vtbl DATA `0x009cfaa0`) — **E9 JMP**, not CALL.
6. **Name:** `Object_CacheAIProfileFields_TypeMask_Inferred` (Ghidra `FUN_004c9120`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23). Manager/thiscall ECX surfaces partially omitted by decompiler (bytes restore `LEA ECX,[ESI-0x3F0]`).

### Gaps

- Product English for each profile field.  
- Full MI / vbtable class names.  
- `FUN_005c8eb0` dual (not OWN).  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c9120_FUN_004c9120.md` |
| Annotated | `docs/reconstruction/raw/aa_004c9120_FUN_004c9120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CacheAIProfileFields_TypeMask_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c9120.cpp` |
| Function | `docs/reconstruction/functions/aa_004c9120_FUN_004c9120.md` |
| Function named | `docs/reconstruction/functions/aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c9120.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005f4380` | When porting `GameUtils::createRagDoll`, bone-count parse is this SEH wrapper + `FUN_005f4230`. Honor **5** buffer/context formals at the call (not a 2-arg simplification). Count feeds `< 0x21` / skeleton `< 0x41` gates. |
| `004c9120` | Object AI-profile cache must copy the sealed offset table from the MI-resolved `+0x3c` block, then exact-find key `+0x4dc` on the host map (`isnil+0x65` helper). Type mask goes to the object slot corresponding to `this-0x300` (mid-object this). Entry may require the same MI adjust (`[ecx-4]` and/or `−0x8A0`) as retail vtables. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence: `_Inferred` structural names; GameUtils prefix from parent plate only.
