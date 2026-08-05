# Review A (reconstruction fidelity): `aa_007252d0` CSoundManager_TickHardKillAndRegions_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007252d0` |
| **VA** | `0x007252d0`–`0x0072589f` |
| **Canonical name (Ghidra)** | `FUN_007252d0` |
| **Proposed name** | `CSoundManager_TickHardKillAndRegions_Inferred` (**High** role; product open) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W18-F) |
| **Reviewer role** | Reconstruction fidelity (sound hard-kill / regions tick) |
| **Counterpart** | `reviews/B_aa_007252d0_CSoundManager_TickHardKillAndRegions_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**EBX-this tick** nested under `UpdateSounds::updateSoundRegions`:

1. Gate on `DAT_00afa9b1`, non-empty vectors, and `enableFlag != 0`.
2. Accumulate `dt` into `this+0x284`; when ≥ 0, walk hard-kill vector.
3. If `DAT_00afa9b2` and listener magnitude > 0, walk region vector.
4. `FUN_00415d60` cleanup.

### Primary use

Sole caller `FUN_00727440` after profile string `"UpdateSounds::updateSoundRegions()"`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007252d0_FUN_007252d0.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_007252d0_FUN_007252d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CSoundManager_TickHardKillAndRegions_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_007252d0_CSoundManager_TickHardKillAndRegions_Inferred.md` |
| Live Ghidra | `decompile_function` `0x007252d0`; complete analysis; parent `0x00727440`; `read_memory` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// this in EBX (custom)
// enableFlag @ [ebp+8], dt @ [ebp+0xC]; RET 8
void CSoundManager_TickHardKillAndRegions_Inferred(int enableFlag, float dt);
```

| Item | Evidence |
|---|---|
| Stack arity 2 | `RET 8` @ `C2 08 00` |
| EBX this | body `[EBX+disp]` throughout |
| enableFlag | compared to 0 early exit |
| dt add | `MOVSS` from `[EBP+0xC]` + `[EBX+0x284]` |

**Decompiler trap:** signature omits EBX this.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Triple gate | **Yes** |
| Accum +0x284; phase A when ≥ 0 | **Yes** |
| Timer / radius / dist hard-kill | **Yes** |
| Phase B region walk | **Yes** |
| Tail `FUN_00415d60` | **Yes** |

**Body size:** 1487 B.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Two-phase hard-kill + regions | **High** | |
| EBX-this ABI | **High** | |
| Constants 4.0f / ~1/65536 | **High** | `read_memory` |
| Nested under updateSoundRegions | **High** | string + call site |
| Product method name | **Tentative** | `_Inferred` |

---

## 6. Gaps / open

1. Retail/PDB name of this method and list element types.
2. Full semantics of several nested helpers.
3. EBX provenance at call site not byte-proved in this pass.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps**.
