# Dual A/B report — W21-I OWN `aa_004cf080` + `aa_0079a110`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W21-I  
**Scope:** VAs `0x004cf080`, `0x0079a110` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cf080` Combat_RollCritMultiplier_Inferred | **accept-with-gaps** — percent gate + `level*0.01+~1.2` sealed; chance helper dual + product English open |
| `aa_0079a110` TimerHost_GetTimeFloat | **accept** — 7 B `FLD [ECX+0x238]; RET` fully sealed |

---

## VA `0x004cf080` — sealed facts

1. **Body:** `0x004cf080`–`0x004cf0f4` (117 B to final `RET`).
2. **ABI:** cdecl; stack formals `attacker*`, `target*`, `roll` ushort; plain `RET`; return float in ST0.
3. **Null attacker** → `g_flOne` (1.0).
4. **Level:** `attacker->vtbl[+0x27c]()` (int via FILD; GetLevel-like, Probable).
5. **Chance:** `FUN_004cef70(attacker, target)` @ `0x004cef70`.
6. **Gate:** `(roll % 100) <= chance * 100.0` (`DAT_00aaa7ac` = 100.0f).
7. **Crit mult:** `level * 0.01 + ~1.2000000476837158` (doubles `@0x009cc1c8` / `@0x009cc1c0`).
8. **Miss:** return 1.0.
9. **Callers (2):** `Weapon_ApplyDamageToTargets_Inferred` @ `0x0056e000` (call `0x0056e289`), `Skill_ApplyMultiTargetHits_Inferred` @ `0x0058c850` (call `0x0058cb5c`).
10. **Name:** `Combat_RollCritMultiplier_Inferred` (Ghidra `FUN_004cf080`). Former VOG_DEBUG scaffold name **misleading**.

### Gaps

- Product English for function / level vfunc.  
- Dual of chance helper `FUN_004cef70` (not owned).  
- Runtime crit mult histogram / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cf080_Combat_RollCritMultiplier_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cf080_Combat_RollCritMultiplier_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cf080_FUN_004cf080.md` |
| Annotated | `docs/reconstruction/raw/aa_004cf080_FUN_004cf080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Combat_RollCritMultiplier_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cf080.cpp` |
| Function | `docs/reconstruction/functions/aa_004cf080_FUN_004cf080.md` |
| Function named | `docs/reconstruction/functions/aa_004cf080_Combat_RollCritMultiplier_Inferred.md` |
| Scratch | `tmp/a_004cf080.md` |

---

## VA `0x0079a110` — sealed facts

1. **Body:** `0x0079a110`–`0x0079a116` (7 B).
2. **ABI:** ECX = host*; return ST0 float.
3. **Algorithm:** `return *(float *)(host + 0x238)`.
4. **Callees:** none.
5. **Xrefs:** **34** (anim slots, turret aim, drive/update, …). Common host `DAT_00b04c74`.
6. **Name:** `TimerHost_GetTimeFloat` (Ghidra `FUN_0079a110`). Former turret-only scaffold name **misleading**.
7. **Decompile ≡ bytes** exactly.

### Gaps

- Product English for host type / field.  
- Units (seconds vs other).  
- Layout dual of `DAT_00b04c74` (not owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0079a110_TimerHost_GetTimeFloat.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0079a110_TimerHost_GetTimeFloat.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0079a110_FUN_0079a110.md` |
| Annotated | `docs/reconstruction/raw/aa_0079a110_FUN_0079a110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TimerHost_GetTimeFloat.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0079a110.cpp` |
| Function | `docs/reconstruction/functions/aa_0079a110_FUN_0079a110.md` |
| Function named | `docs/reconstruction/functions/aa_0079a110_TimerHost_GetTimeFloat.md` |
| Scratch | `tmp/a_0079a110.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cf080` | Combat crit mult — implement `%100` gate + `level*0.01+~1.2`; do not invent flat 2×; chance stays in `FUN_004cef70` sibling. Callers scale only when mult `> 1`. |
| `0079a110` | Pure float field getter at `+0x238` — use for anim/time sample; no conversion in this unit. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
