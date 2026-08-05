# Dual A/B report — W26-I OWN `aa_005bc120` + `aa_004bcc40`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-I  
**Scope:** VAs `0x005bc120`, `0x004bcc40` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005bc120` Emitter_SpawnOnIntervalTick_Inferred | **accept** — interval countdown + spawn burst + RNG reschedule CF/ABI sealed |
| `aa_004bcc40` ThreadSafeObjectList_ScalarDeletingDtor | **accept** — MSVC scalar dtor CF/ABI + vtbl[0] + sibling body sealed |

---

## VA `0x005bc120` — sealed facts

1. **Body:** `0x005bc120`–`0x005bc3bc` (**669 B** / `0x29D`; pad `CC` then `FUN_005bc3c0` @ `0x005bc3c0`).
2. **ABI:** **thiscall**; ECX = emitter*; stack `float *dt`, `uint32_t motionCtx`; **`RET 8`**; void.
3. **Semantics:** Accumulate rate `+0x928`; countdown `+0x804` by `*dt`; early return if still positive; else spawn group/burst (create/list/motion/optional pair) then reschedule `base + range * (u16 * ≈1/65535)`.
4. **Classification:** worker (emitter interval spawn).
5. **Callers (1):** `FUN_005bc3c0` @ `0x005bdcc1` (emitter update; string `"Emitter found at 0,0,0: %d %I64d"`).
6. **Callees:** `FUN_005be390`, `FUN_006759b0`, `FUN_005bdd50`, `FUN_004b3260`, `FUN_004b2b90`, `FUN_004b1100` (`ObjectMotion_IntegrateStep_Inferred`), `FUN_005b81e0`, `FUN_004b0be0`, `CVOGReaction_RandomUnitScalar`×2, `FUN_004b18f0`.
7. **Data:** `DAT_00aaa638` = `0x37800080` float **≈ 1/65535**.
8. **Name:** `Emitter_SpawnOnIntervalTick_Inferred` (Ghidra `FUN_005bc120`).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / Torque method name.  
- Full emitter layout; nested callee ECX models (decompiler-shaped residual).  
- Runtime / bit-exact RNG schedule.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005bc120_Emitter_SpawnOnIntervalTick_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005bc120_Emitter_SpawnOnIntervalTick_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005bc120_FUN_005bc120.md` |
| Annotated | `docs/reconstruction/raw/aa_005bc120_FUN_005bc120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Emitter_SpawnOnIntervalTick_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005bc120.cpp` |
| Function | `docs/reconstruction/functions/aa_005bc120_FUN_005bc120.md` |
| Function named | `docs/reconstruction/functions/aa_005bc120_Emitter_SpawnOnIntervalTick_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005bc120.md` |

---

## VA `0x004bcc40` — sealed facts

1. **Body:** `0x004bcc40`–`0x004bcc5d` (**30 B**; pad `CC` after last `RET 4`).
2. **ABI:** **thiscall**; ECX = list*; stack `uint8_t flags`; **`RET 4`**; EAX = this.
3. **Semantics:** Call complete dtor `ThreadSafeObjectList_Dtor` (`FUN_004bcbf0`); if `(flags & 1)` → `operator_delete(this)`; return this.
4. **Classification:** MSVC scalar deleting dtor (vtbl slot 0).
5. **Callers:** none direct — virtual via `PTR_FUN_009cb368[0]`.
6. **Callees:** `FUN_004bcbf0`, `operator_delete`.
7. **Data:** vtbl `0x009cb368` first dword = `0x004bcc40` (`read_memory`).
8. **Name:** `ThreadSafeObjectList_ScalarDeletingDtor` (Ghidra `FUN_004bcc40`; family with W25-C dtor dual).
9. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / PDB mangled name.  
- Runtime free path.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bcc40_FUN_004bcc40.md` |
| Annotated | `docs/reconstruction/raw/aa_004bcc40_FUN_004bcc40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ThreadSafeObjectList_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bcc40.cpp` |
| Function | `docs/reconstruction/functions/aa_004bcc40_FUN_004bcc40.md` |
| Function named | `docs/reconstruction/functions/aa_004bcc40_ThreadSafeObjectList_ScalarDeletingDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_004bcc40.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005bc120` | Emitter spawn cadence is **timer-gated** then **RNG-rescheduled** with scale ≈1/65535. Cap field **0 means unlimited**, not zero. Empty name still advances timer. |
| `004bcc40` | Virtual delete for `ThreadSafeObjectList` is this wrapper; stack/member destroy must use complete dtor only (`0x004bcbf0`) without free. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
