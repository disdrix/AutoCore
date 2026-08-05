# Dual A/B report — W27-I OWN `aa_004c9430` + `aa_005d7ca0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-I  
**Scope:** VAs `0x004c9430`, `0x005d7ca0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c9430` Object_EnsurePrimaryHBAI_FromAIProfile | **accept-with-gaps** — CF/ABI/factory table/list policy sealed; product type English + SEH early-return residual |
| `aa_005d7ca0` CVOGHBAI_ProfileType4_DoLogic_Inferred | **accept-with-gaps** — CF/ABI/vtbl/binary-SM sealed; product class/method plate residual |

---

## VA `0x004c9430` — sealed facts

1. **Body:** `0x004c9430`–`0x004c96a9` (**634 B**; `RET 8`). Jump table `@0x004c96ac` (cases 2..5).
2. **ABI:** **thiscall** + MSVC SEH; stack `char deferStop`, `char profileKeyOrMinus1`; **`RET 8`**.
3. **Semantics:** If `this+0x1fc==0`, resolve AI profile map key → allocate type-specific HBAI (`0xB0`/`0xC0` + ctor table) → store `+0x1fc`, bitmask `+0x200`, `CVOGHBList_Enqueue`, Start or Stop → optional secondary `FUN_005d6b80` when def`+0x4e8==1` → skill refresh if clone type `!=0x14`.
4. **Classification:** worker.
5. **Xrefs:** DATA `0x009cfe54`, `0x009cbf34` (no code callers listed).
6. **Name:** `Object_EnsurePrimaryHBAI_FromAIProfile` (Ghidra `FUN_004c9430`; no plate string).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23). Linked factory case **4** owns sibling VA `005d7ca0`.

### Gaps

- Product English for profile type words 2/3/4/5/default.  
- SEH early-out EAX residual (`ExceptionList` surface).  
- Code call-site recovery.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c9430_FUN_004c9430.md` |
| Annotated | `docs/reconstruction/raw/aa_004c9430_FUN_004c9430.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_EnsurePrimaryHBAI_FromAIProfile.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c9430.cpp` |
| Function | `docs/reconstruction/functions/aa_004c9430_FUN_004c9430.md` |
| Function named | `docs/reconstruction/functions/aa_004c9430_Object_EnsurePrimaryHBAI_FromAIProfile.md` |
| Scratch | `docs/reconstruction/tmp/a_004c9430.md` |

---

## VA `0x005d7ca0` — sealed facts

1. **Body:** `0x005d7ca0`–`0x005d7dd0` (**305 B**; pad `CC` after).
2. **ABI:** **thiscall** ECX=this; **void**; bare `RET` after `ADD ESP,8`.
3. **Vtbl:** sole DATA xref `0x009db0dc` in `PTR_FUN_009db08c` (factory type **4** / `FUN_005d7de0`).
4. **Semantics:** Profile map lower_bound → `FUN_004c3c80(owner,0)` → binary `owner+0x26c` with skill sets **0/2**, aim (`005cedf0`), busy/path gates, pursue (`005cf560`), vtbl tails; fallthrough `FUN_005cc450`.
5. **Callers:** virtual only (vtbl).
6. **Name:** `CVOGHBAI_ProfileType4_DoLogic_Inferred` (Ghidra `FUN_005d7ca0`; DoLogic role structural vs Driver/CreatureBase).
7. **Decompile ≡ raw** for CF (live 2026-07-29 ≡ 2026-07-23).

### Gaps

- Product class name for `009db08c`.  
- Product method plate string.  
- Nested helper duals not OWN (`005cc980`, `005cebd0`, `005cc450`, `004c3c80`).  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d7ca0_FUN_005d7ca0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d7ca0_FUN_005d7ca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_ProfileType4_DoLogic_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d7ca0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d7ca0_FUN_005d7ca0.md` |
| Function named | `docs/reconstruction/functions/aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005d7ca0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c9430` | Host AI attach must create the correct HBAI subclass from profile type word, enqueue on `CVOGHBList`, honor Start vs Stop deferral, optional secondary period HB, and type-gated skill refresh. Do not treat as AICode CreateByAICode table. |
| `005d7ca0` | Type-4 HBAI tick is a **binary** combat SM (not CreatureBase ternary). Port skill sets 0/2 + aim + pursue; clear `owner+0x278` each tick; require profile map hit. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plate names: structural `_Inferred` / `FromAIProfile` names only.
