# Dual A/B report — W26-O OWN `aa_004cbd50` + `aa_005cedf0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-O  
**Scope:** VAs `0x004cbd50`, `0x005cedf0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cbd50` Map_LowerBoundFindByIntKey_Isnil65 | **accept** — leaf exact-find CF/ABI; isnil+0x65; key+0x0C; ret 8 sealed |
| `aa_005cedf0` CVOGHBAI_UpdateAimOffset_Inferred | **accept** — aim-offset SM CF/ABI/constants + exclusive HB AI callers sealed |

---

## VA `0x004cbd50` — sealed facts

1. **Body:** `0x004cbd50`–`0x004cbdb1` (**98 B**; dual `C2 08 00`).
2. **ABI:** **thiscall**; stack `Node** pOutIt`, `int* pKey`; **`ret 8`**; void (writes `*pOutIt`).
3. **Semantics:** Lower_bound tree walk + equality gate → **exact find** or end.
4. **Node:** left+0, right+8, key dword+0xC, **isnil+0x65**.
5. **Classification:** **leaf** (0 callees).
6. **Callers (5):** `FUN_004c9120`, `FUN_004c9430`, `CVOGHBAIDriver_DoLogic`, `FUN_005d7ca0`, `FUN_005d7f70`.
7. **Name:** `Map_LowerBoundFindByIntKey_Isnil65` (Ghidra `FUN_004cbd50`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product STL / RTTI name.  
- Full value_type (large node).  
- Negative float-key dword order edge if callers pass negatives.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cbd50_FUN_004cbd50.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbd50_FUN_004cbd50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_LowerBoundFindByIntKey_Isnil65.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cbd50.cpp` |
| Function | `docs/reconstruction/functions/aa_004cbd50_FUN_004cbd50.md` |
| Function named | `docs/reconstruction/functions/aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md` |
| Scratch | `docs/reconstruction/tmp/a_004cbd50.md` |

---

## VA `0x005cedf0` — sealed facts

1. **Body:** `0x005cedf0`–`0x005cf558` (**1897 B** inclusive end; pad `CC` after).
2. **ABI:** **fastcall/thiscall ECX=this**; **void**; plain `RET` after frame teardown (`SUB ESP,0x64`).
3. **Semantics:** AI aim-offset state machine — clear / arm / hold / build randomized local XZ → world aim@`+0x40`.
4. **Key constants:** TTL **6.0**, arm **1.5**, still **0.05**, near **0.75**, drift **1.0**, random bases **4/5** with ushort scales ≈5/65535 and 6/65535, flip **−1**.
5. **Callers (4 / 9 xrefs):** `CVOGHBAIDriver_DoLogic`, `FUN_005d7f70`, `CVOGHBAICreatureBase_OnHeartBeat`, `FUN_005d7ca0`.
6. **Callees:** `FUN_004c3ac0`×2, `FUN_005d6870`, `FUN_005d1d20`, `FUN_004e8bf0`, `CVOGReaction_RandomUnitScalar`×3, owner/vehicle/object vtbls.
7. **Name:** `CVOGHBAI_UpdateAimOffset_Inferred` (Ghidra `FUN_005cedf0`; aim role via `g_abInferredDefaultAimPos` + fields).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English class name of `this`.  
- Nested `FUN_005d1d20` / `FUN_005d6870` duals (not OWN).  
- Aim@`+0x40` consumer path.  
- Runtime RNG bit-exact — open.  
- Unreachable decompiler block residual (dead).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005cedf0_FUN_005cedf0.md` |
| Annotated | `docs/reconstruction/raw/aa_005cedf0_FUN_005cedf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_UpdateAimOffset_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cedf0.cpp` |
| Function | `docs/reconstruction/functions/aa_005cedf0_FUN_005cedf0.md` |
| Function named | `docs/reconstruction/functions/aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005cedf0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cbd50` | AI profile map lookup must use **this** tree layout (isnil **+0x65**, key **+0x0C**). Do not reuse `Map_LowerBoundFindByIntKey` (+0x15) on these maps. Exact-find only (end on miss). |
| `005cedf0` | NPC aim jitter/offset parity requires same thresholds (6 / 1.5 / 0.05 / 0.75 / 1.0) and same random local→world path. Aim consumer must read `helper+0x40` after DoLogic/HeartBeat ticks. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` / structural Map_* names used.
