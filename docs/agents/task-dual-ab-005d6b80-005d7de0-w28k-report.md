# Dual A/B report — W28-K OWN `aa_005d6b80` + `aa_005d7de0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-K  
**Scope:** VAs `0x005d6b80`, `0x005d7de0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005d6b80` CVOGHB_SlewFacingYaw_ctor_Inferred | **accept-with-gaps** — CF/ABI/vtbl/factory/slew this-arg sealed; product class English residual |
| `aa_005d7de0` CVOGHBAI_ProfileType4_ctor_Inferred | **accept-with-gaps** — thin chain+vtbl/factory sealed; product class + base mid `005d1990` residual |

---

## VA `0x005d6b80` — sealed facts

1. **Body:** `0x005d6b80`–`0x005d6c0f` (**144 B**; SEH; `ADD ESP,0x10; RET 4`).
2. **ABI:** **thiscall** ECX=HB; stack `void *pOwnerRaw`; returns `this`.
3. **Semantics:** `CVOGHBBase_ctor` → vtbl `PTR_FUN_009daee8` → `*(+8)=0x1e` → `SetPeriodAndCounter(-1000,true)` → stash raw owner at `+0x24` → MI-adjust + `AttachOwnerObject` → float-zero `owner+0x11c` → `CVOGCreature_SlewFacingYaw_Inferred(owner, 0x1e)`.
4. **Factory:** secondary HB `new(0x28)` when def `+0x4e8==1` in `Object_EnsurePrimaryHBAI_FromAIProfile` (sole caller `@0x004c9648`).
5. **Vtbl tick:** `FUN_005d6c10` @ `009daee8+0x0C` (not OWN) re-slews then `RescheduleAfterFire`.
6. **Name:** `CVOGHB_SlewFacingYaw_ctor_Inferred` (Ghidra `FUN_005d6b80`; **Inferred** from sealed slew callee + factory role).
7. **Decompile residual:** Ghidra prints `FUN_004c7bd0(param_1[2])` with wrong this — **bytes seal** ECX=raw owner, stack=0x1e.

### Gaps

- Product/PDB English for vtbl `009daee8`.
- HB `+0x24` shared layout plate.
- Tick sibling dual not OWN.
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d6b80_FUN_005d6b80.md` |
| Annotated | `docs/reconstruction/raw/aa_005d6b80_FUN_005d6b80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHB_SlewFacingYaw_ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d6b80.cpp` |
| Function | `docs/reconstruction/functions/aa_005d6b80_FUN_005d6b80.md` |
| Function named | `docs/reconstruction/functions/aa_005d6b80_CVOGHB_SlewFacingYaw_ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005d6b80.md` |

---

## VA `0x005d7de0` — sealed facts

1. **Body:** `0x005d7de0`–`0x005d7df8` (**25 B**; `RET 4`; pad `CC`).
2. **ABI:** **thiscall** ECX=this; stack owner; returns `this`.
3. **Semantics:** `FUN_005d1990(this, owner)` then `*this = PTR_FUN_009db08c`.
4. **Factory:** case **4** of `Object_EnsurePrimaryHBAI_FromAIProfile` → `new(0xC0)` + this ctor (sole call `@0x004c9556`).
5. **Vtbl:** `009db08c`; sealed DoLogic `CVOGHBAI_ProfileType4_DoLogic_Inferred` @ DATA `0x009db0dc` = `0x005d7ca0` (vtbl+0x50).
6. **Name:** `CVOGHBAI_ProfileType4_ctor_Inferred` (Ghidra `FUN_005d7de0`; structural twin of sealed DoLogic name).
7. **Not:** AICode `CVOGHBAI_CreateByAICode` table; not secondary slew HB `005d6b80`.

### Gaps

- Product class English for `009db08c`.
- Base mid-ctor `FUN_005d1990` (not OWN).
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d7de0_FUN_005d7de0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d7de0_FUN_005d7de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_ProfileType4_ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d7de0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d7de0_FUN_005d7de0.md` |
| Function named | `docs/reconstruction/functions/aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005d7de0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005d6b80` | Secondary facing-slew HB (size **0x28**): pulse **30 ms** at `+0x08`, schedule sentinel −1000, zero owner `+0x11c`, immediate slew with Δt=30 on **raw owner**. Do not treat as primary HBAI or Regeneration. Enqueue+Start owned by factory caller. |
| `005d7de0` | Type-4 HBAI leaf: always run mid-base `005d1990` then install `009db08c`. Alloc **0xC0**. Do not merge with AICode factory or with secondary slew HB. DoLogic is virtual on installed vtbl (`005d7ca0`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits; no cross-agent VA writes.
- Tools: `decompile_function` + `read_memory` (+ callers/callees/xrefs). No `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed per VA.
- Scaffold raw bodies preserved; re-verify **appended** (rewrite preserved original block + append).
- Names **Inferred** from sealed sibling families (slew callee; ProfileType4 DoLogic); no invented product plate strings.
- This report: `docs/agents/task-dual-ab-005d6b80-005d7de0-w28k-report.md`
