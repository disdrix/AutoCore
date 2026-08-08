# Dual A/B report — MEGA-093 OWN-ONLY (`0x005cc560`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-093**  
**Scope:** VA `0x005cc560` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_xrefs_to` + RTTI memory. **No** `disassemble_bytes` primary.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md`  
**Hint:** follow-up after AI axis park (`0x005d73a0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005cc560` CVOGHBAI_DecEntityA4SecondaryCounter_Inferred | **accept-with-gaps** — CF/ABI/offsets/callers/park-tail sealed; product English for A4 / +0x250 / vtbl+0x214 open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cdecl / RET4 / sibling-merge / primary-lane-only / park-only-non-virtual / wrong ESI algebra claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005cc560` — sealed facts

1. **Body:** `0x005cc560`–`0x005cc5ad` inclusive (**78 B** / `0x4E`); pad `CC CC` before sibling `FUN_005cc5b0` @ `0x005cc5b0`.
2. **ABI:** **thiscall**; ECX = HBAI this; **0** stack formals; exits `JMP 0x005081e0` → bare **`RET`** (`C3`).
3. **Semantics:**
   - `entity = this+0x18`; require non-null.
   - `counters = entity+0xA4`; require non-null.
   - `related = entity->vtbl[+0x214]()` (thiscall, ECX=entity).
   - If related non-null: `related+0x250 == 0` → `counters[+0x18]--`; else `counters[+0x1c]--`.
4. **Classification:** leaf (no direct callees; one indirect virtual).
5. **Callers (code):** `FUN_005d73a0` @ `0x005d73e3` — Driver park zeros steer/longitudinal, handbrake 1, FollowVehicle weapons (0,0), push axes, **tail-JMP** here.
6. **Xrefs (DATA):** 5 HBAI vtables — `.?AVCVOGHBAICreatureBase@@`, `Character`, `Mine`, `Bot`, `WalkingCreatureTurreted` (slot after OnHeartBeat on CreatureBase dump @ `0x009da994`).
7. **Callees:** none direct.
8. **Name:** `CVOGHBAI_DecEntityA4SecondaryCounter_Inferred` (Ghidra `FUN_005cc560`). Product English residual → `_Inferred`. No `Named_CalleeOf_*` scaffold to retire for this VA.
9. **Decompile ≡ raw CF ≡ bytes**; ESI=`counters+0x10` then `+8/+C` ≡ decomp `+0x18/+0x1c`.

### Gaps

- Product English for entity counter block **`+0xA4`** and secondary pair role.  
- Product English for **`vtbl+0x214`** and **`related+0x250`**.  
- Full cross-class vtable ordinal map (MI).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005cc560_CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005cc560_CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_005cc560_FUN_005cc560.md` |
| Annotated | `docs/reconstruction/raw/aa_005cc560_FUN_005cc560.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cc560.cpp` |
| Function | `docs/reconstruction/functions/aa_005cc560_FUN_005cc560.md` |
| Function named | `docs/reconstruction/functions/aa_005cc560_CVOGHBAI_DecEntityA4SecondaryCounter_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGHBAIDriver vtbl park slot
  FUN_005d73a0  [axis park — residual / not OWN]
    VehicleEntity_SetSteerInput(0)
    VehicleEntity_SetLongitudinalInput(0)
    VehicleEntity_SetHandbrake(1)
    CVOGHBAIFollowVehicle_FireWeapons(0,0)
    VehicleEntity_PushDriveAxesToController()
    tail JMP → FUN_005cc560  [OWN MEGA-093]

CVOGHBAICreatureBase family vtbl (slot after OnHeartBeat)
  → FUN_005cc560 directly (no park override)

Sibling FUN_005cc5b0  [fuller A4 multi-lane release — residual]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005cc560-mega-093-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005cc560` | Port as **HBAI thiscall leaf**: resolve `entity=this+0x18`, `counters=entity+0xA4`, `related=entity.vtbl[+0x214]()`, then decrement **secondary** counter `+0x18` or `+0x1c` by `related+0x250`. **Plain ret**, 0 stack formals. |
| Pair with | Driver park `005d73a0` (override tails here); sibling fuller release `005cc5b0` (do **not** merge); OnHeartBeat `005d0310` (adjacent vtbl slot). |
| Do not | Claim product counter names; claim Runtime Confirmed; use primary lanes `+0x10/+0x14` only; invent NetDevil plate without `_Inferred`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / coverage ledgers when batching MEGA residuals  
- Optional rename in Ghidra to `CVOGHBAI_DecEntityA4SecondaryCounter_Inferred`  
- Residual dual of park `0x005d73a0` and sibling `0x005cc5b0` if still open  

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes` primary.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- No invented product plates: offsets from bytes; `_Inferred` for product English residual.
