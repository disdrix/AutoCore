# Dual A/B report — W26-T OWN `aa_0060b410` + `aa_0060b440`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-T  
**Scope:** VAs `0x0060b410`, `0x0060b440` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave26_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0060b410` CVOGHBPendingUseObject_Stop_Inferred | **accept** — flag/owner cancel + EndOrDestroy(1,1) + this-adjust sealed |
| `aa_0060b440` CVOGHBPendingUseObject_OnHeartBeat_Inferred | **accept** — gate/match CF + Remove(16) + commit Resolve + Reschedule sealed |

---

## VA `0x0060b410` — sealed facts

1. **Body:** `0x0060b410`–`0x0060b438` (**41 B**; pad `CC` to `0x0060b440`).
2. **ABI:** **thiscall**; stack `char flag_cancel_pending`; **void**; `RET 4`.
3. **Semantics:**
   - If `flag≠0` **and** `HB+0x18` (owner) non-null → `FUN_00535ed0(commit=0)` with **ECX = `[HB+0x28]`** character.
   - Always `vtbl+0x18` **EndOrDestroy`(1,1)`** (OnEnd + hard).
4. **Classification:** worker (not leaf).
5. **Callers (4 CODE):** `CVOGReaction_RecordFirstTimeEvent` (flag 1), `FUN_0052f260` char dtor (flag 1), `FUN_00535ed0` ×2 (flag 0 clear).
6. **Callees:** `FUN_00535ed0` (ResolveUseObjectPending), virtual EndOrDestroy.
7. **Name:** `CVOGHBPendingUseObject_Stop_Inferred` (Ghidra `FUN_0060b410`; prior scaffold `Named_CalleeOf_…RecordFirstTimeEvent…`).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23); this-adjust sealed from `read_memory`.

### Gaps

- Product English class name.  
- Runtime / bit-diff.  
- Empty subclass OnEnd (`vtbl+0x14` = `0x005081f0`) intentionality.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0060b410_FUN_0060b410.md` |
| Annotated | `docs/reconstruction/raw/aa_0060b410_FUN_0060b410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBPendingUseObject_Stop_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060b410.cpp` |
| Function | `docs/reconstruction/functions/aa_0060b410_FUN_0060b410.md` |
| Function named | `docs/reconstruction/functions/aa_0060b410_CVOGHBPendingUseObject_Stop_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0060b410.md` |

---

## VA `0x0060b440` — sealed facts

1. **Body:** `0x0060b440`–`0x0060b49f` (**96 B**); next `FUN_0060b4a0` scalar dtor.
2. **ABI:** **thiscall**; stack `uint32_t* pOutStatus`; returns `pOutStatus`; `RET 4`.
3. **Semantics (OnHeartBeat):**
   - Gate: owner `+0x18`, character `+0x28`, secondary `+0x24`, `cStopped==0`.
   - If `*(character+0xc9c) != secondary` → `*out = DAT_00af49ac` (**16** = Remove).
   - Else: `FUN_00535ed0(commit=1)` on character, then `CVOGHBBase_RescheduleAfterFire(this, out)`.
   - Outer fail → same Remove 16.
4. **DATA:** `DAT_00af49ac` @ `0x00af49ac` = `0x00000010` (`read_memory`).
5. **Vtbl:** `PTR_FUN_009df668 + 0x0C` = this VA (OnHeartBeat); ctor `FUN_0060b380` size `0x2c`, type tag **10**.
6. **CODE callers:** none direct (virtual only). DATA xref `0x009df674`.
7. **Callees:** `FUN_00535ed0`, `CVOGHBBase_RescheduleAfterFire`.
8. **Name:** `CVOGHBPendingUseObject_OnHeartBeat_Inferred` (Ghidra `FUN_0060b440`).
9. **Decompile ≡ bytes** for CF; field map **corrected** (decomp misnamed `+0x24`/`+0x28` as base debounce / overlay vtbl).

### Gaps

- Product English.  
- Post-commit Reschedule vs immediate Remove residual (runtime).  
- Period source `object+0x25c` product name (ctor only; not OWN).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0060b440_FUN_0060b440.md` |
| Annotated | `docs/reconstruction/raw/aa_0060b440_FUN_0060b440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBPendingUseObject_OnHeartBeat_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0060b440.cpp` |
| Function | `docs/reconstruction/functions/aa_0060b440_FUN_0060b440.md` |
| Function named | `docs/reconstruction/functions/aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0060b440.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0060b410` | Pending-use HB teardown: flag 1 cancels character pending then hard EndOrDestroy; flag 0 EndOrDestroy only. **Must** this-adjust Resolve to `HB+0x28`, never ECX=HB. Couples to W25-A `ResolveUseObjectPending` clear of `char+0xca0`. |
| `0060b440` | OnHeartBeat commits pending only while `char+0xc9c` still equals HB secondary; else Remove(16). Do not drop the match gate. Remove token is **16**, not Continue. Closes residual left open by W25-A on `FUN_0060b410`/`FUN_0060b440` coupling. |

---

## Subclass layout (shared; from ctor `FUN_0060b380` + these units)

| Off | Field |
|-----|--------|
| `+0x00` | vtbl → `0x009df668` |
| `+0x08` | `nPeriodMs` = `object+0x25c` × 1000 |
| `+0x0C` | `nPeriodSentinel` = 1 |
| `+0x18` | `pOwnerObject` |
| `+0x1C` | type tag **10** |
| `+0x20` | `cStopped` |
| `+0x24` | secondary object* |
| `+0x28` | character* |
| size | **0x2c** |

Stored at `char+0xca0` by `CVOGReaction_RecordFirstTimeEvent` (with `char+0xc9c` = same secondary).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence (`_Inferred` only).  
- Avoided bare `undefined4` in clean (`uint32_t`).
