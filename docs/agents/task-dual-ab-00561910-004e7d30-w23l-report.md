# Dual A/B report — W23-L OWN `aa_00561910` + `aa_004e7d30`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-L  
**Scope:** VAs `0x00561910`, `0x004e7d30` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00561910` PhysSim_LtSimulate_Collide | **accept** — collide-half CF + ABI + stepInfo install + sub-island broadphase this sealed |
| `aa_004e7d30` CNDHash_InsertDualKey | **accept** — dual-key insert CF + ABI + HRESULT returns + strings sealed; VOG_DEBUG_STOP alias rejected |

---

## VA `0x00561910` — sealed facts

1. **Body:** `0x00561910`–`0x00561B5B` (588 B; `RET 4`).
2. **ABI:** **ECX**=island/world manager*; stack `float* stepInfo` `{dt, inv_dt}`; void return.
3. **Semantics:** Install stepInfo + agent copy + scaled dt block → flush pairs → per-sub-island `FUN_00629d90` (LtBroadPhase) → optional island post-collide CB → deferred deletes → `StPostCollideCB`.
4. **Profiler:** `"LtSimulate"` @ `0x009d2894`; also `TtIslandPostCollideCb`, `StPostCollideCB`.
5. **Callers (2):** `CVOGSectorMap::StepTo` / `FUN_004d6c80` @ `0x004d6d90`; `FUN_00562bf0` @ `0x00562c19`.
6. **Not applyAction:** integrate half is companion `FUN_00561b60` → `FUN_00628f70`.
7. **Decompiler residual:** `FUN_00629d90` true `this` = `subIslands[i]` (bytes @ `0x00561a13`); fixed in clean.
8. **Name:** `PhysSim_LtSimulate_Collide` (Ghidra `FUN_00561910`).
9. **Decompile ≡ bytes** for CF (with documented call-site fix).

### Gaps

- Product English for island manager type.  
- Full sub-island / agent layouts beyond used offsets.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00561910_PhysSim_LtSimulate_Collide.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00561910_PhysSim_LtSimulate_Collide.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00561910_FUN_00561910.md` |
| Annotated | `docs/reconstruction/raw/aa_00561910_FUN_00561910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysSim_LtSimulate_Collide.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00561910.cpp` |
| Function | `docs/reconstruction/functions/aa_00561910_FUN_00561910.md` |
| Function named | `docs/reconstruction/functions/aa_00561910_PhysSim_LtSimulate_Collide.md` |
| Scratch | `docs/reconstruction/tmp/a_00561910.md` |

---

## VA `0x004e7d30` — sealed facts

1. **Body:** `0x004e7d30`–`0x004e7e5d` (302 B; all paths `RET 0x10`).
2. **ABI:** **ECX**=CNDHash table*; stack `keyLo`, `keyHi`, `value*`, `soft`; **EAX** status.
3. **Returns:** `0` insert OK; `1` soft-exists; `0x80004003` E_POINTER; `0x80004005` E_FAIL duplicate.
4. **Strings:** `HashError:insert, already locked for traversal`; `VOG_DEBUG_STOP`; `Duplicate hash insert %u, failing out`.
5. **Caller (1):** `FUN_004dbef0` @ `0x004dc014` (RegisterObjectHashEntry — soft=0).
6. **Callees:** find `FUN_004e23d0`; freelist `FUN_00589890` (table+0x20); repair `FUN_004e2360`; log `FUN_007a4480`.
7. **Node:** vtbl `PTR_FUN_009cc208`; payload +0xC; keys +0x18/+0x1c; bucket next +0x10; DLL +0x20/+0x24.
8. **Name:** `CNDHash_InsertDualKey` (Ghidra `FUN_004e7d30`). **Reject** `Named_VOG_DEBUG_STOP_004e7d30`.
9. **Decompile ≡ bytes** for CF.

### Gaps

- Product English for this hash instance vs insert twins.  
- Soft-mode live use (sole sealed caller passes 0).  
- Freelist slab details (callee residual).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e7d30_CNDHash_InsertDualKey.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004e7d30_CNDHash_InsertDualKey.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e7d30_FUN_004e7d30.md` |
| Annotated | `docs/reconstruction/raw/aa_004e7d30_FUN_004e7d30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_InsertDualKey.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e7d30.cpp` |
| Function | `docs/reconstruction/functions/aa_004e7d30_FUN_004e7d30.md` |
| Function named | `docs/reconstruction/functions/aa_004e7d30_CNDHash_InsertDualKey.md` |
| Scratch | `docs/reconstruction/tmp/a_004e7d30.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00561910` | Client island collide half — preserve stepInfo install at +0x150 before broadphase; pair with integrate half for full substep; do not attribute applyAction here. |
| `004e7d30` | Object-hash dual-key insert — preserve HRESULT semantics and soft flag; callers must free descriptor on non-zero; keys are two u32 (TFID halves). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
