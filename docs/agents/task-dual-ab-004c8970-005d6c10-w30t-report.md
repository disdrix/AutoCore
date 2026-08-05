# Dual A/B report — W30-T OWN `aa_004c8970` + `aa_005d6c10`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-T  
**Scope:** VAs `0x004c8970`, `0x005d6c10` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ callers/callees/xrefs / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c8970` Object_TFIDMapLookupOrRelatedMatch_Inferred | **accept-with-gaps** — CF/ABI/map offsets/sole-caller gate sealed; product map/field English residual |
| `aa_005d6c10` CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred | **accept-with-gaps** — CF/ABI/vtbl/slew this-arg sealed; product class English residual |

---

## VA `0x004c8970` — sealed facts

1. **Body:** `0x004c8970`–`0x004c8a58` (**0xE9 / 233 B**; pad `CC` after). Ghidra listed end `004c8a56` (start of final `RET`).
2. **ABI:** **thiscall** ECX=self; stack **16 B TFID** (4 dwords); **`RET 0x10`** (`C2 10 00`).
3. **Semantics:** `FUN_004cb4b0` lower_bound on map at `self+0x154` (head `+0x158`) → hit returns `*(node+0x20)`; miss gates related object at MI+`0xA4` (direct TFID `@+0x160/+0x164/+0x168` or `vtbl+0x214` + `TFID_EqualsObjectId` on returned object `MI+0x164`) → `1`/`0`.
4. **Classification:** worker.
5. **Xrefs:** sole code caller `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` / `FUN_005ccff0` @ `0x005cd103` (non-zero early-out before LinkedDeath walk).
6. **Name:** `Object_TFIDMapLookupOrRelatedMatch_Inferred` (Ghidra `FUN_004c8970`; **Inferred** from map+related structural role; no plate string).
7. **Decompile residuals closed by bytes:** map `this` = `self+0x154` (not bare `&tfid`); stack width **16** not 12.

### Gaps

- Product English for map value type at node `+0x20`.
- Product English for MI field `+0xA4` / `vtbl+0x214`.
- Nested helper `FUN_004cb4b0` not OWN.
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c8970_Object_TFIDMapLookupOrRelatedMatch_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c8970_Object_TFIDMapLookupOrRelatedMatch_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c8970_FUN_004c8970.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8970_FUN_004c8970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_TFIDMapLookupOrRelatedMatch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c8970.cpp` |
| Function | `docs/reconstruction/functions/aa_004c8970_FUN_004c8970.md` |
| Function named | `docs/reconstruction/functions/aa_004c8970_Object_TFIDMapLookupOrRelatedMatch_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c8970.md` |

---

## VA `0x005d6c10` — sealed facts

1. **Body:** `0x005d6c10`–`0x005d6c37` (**0x28 / 40 B**; pad `CC` after). Ghidra end exclusive `005d6c38`.
2. **ABI:** **thiscall** ECX=HB; stack `uint32_t *pOutStatus`; **`RET 4`**; returns `pOutStatus` in EAX. Decompiler `__fastcall`/EDX residual **rejected**.
3. **Semantics:** If `pOwnerObject (+0x18) != 0` → `CVOGCreature_SlewFacingYaw_Inferred(rawOwner@+0x24, nPeriodMs@+0x08)`; always `CVOGHBBase_RescheduleAfterFire(self, pOutStatus)`; return `pOutStatus`.
4. **Vtbl:** sole DATA xref `0x009daef4` = `PTR_FUN_009daee8 + 0x0C` (SlewFacingYaw class OnHeartBeat).
5. **Callers:** virtual only (no direct code callers).
6. **Name:** `CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred` (Ghidra `FUN_005d6c10`; structural twin of sealed ctor `005d6b80` + slew callee + HB OnHeartBeat family).
7. **Decompile residual:** prints `FUN_004c7bd0(nPeriodMs)` without this — **bytes seal** ECX=`[self+0x24]` raw owner (same residual class as ctor W28-K).

### Gaps

- Product/PDB English for vtbl `009daee8`.
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d6c10_CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d6c10_CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d6c10_FUN_005d6c10.md` |
| Annotated | `docs/reconstruction/raw/aa_005d6c10_FUN_005d6c10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d6c10.cpp` |
| Function | `docs/reconstruction/functions/aa_005d6c10_FUN_005d6c10.md` |
| Function named | `docs/reconstruction/functions/aa_005d6c10_CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005d6c10.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c8970` | Engage retarget must call this map/related gate on owner TFID **before** LinkedDeath partner walk. Preserve **payload return** on map hit (not bool-only). ABI: thiscall + 16 B TFID stack. Do not substitute bare `TFID_EqualsObjectId`. |
| `005d6c10` | Secondary facing-slew HB tick: slew **raw owner** with Δt from `+0x08` when `pOwnerObject` set; always reschedule. Wire as vtbl+0x0C of class `009daee8` (size **0x28** HB). Do not pass HB as slew this; do not use period sentinel −1000 as Δt. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits; no cross-agent VA writes.
- Tools: `decompile_function` + `read_memory` (+ callers/callees/xrefs). No `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed per VA.
- Scaffold raw bodies preserved; re-verify **appended** only.
- Names **Inferred** from sealed sibling families (engage caller / TFID leaf; slew ctor + OnHeartBeat pattern); no invented product plate strings.
- This report: `docs/agents/task-dual-ab-004c8970-005d6c10-w30t-report.md`
