# Dual A/B report — W37-P OWN `aa_0045dd60` + `aa_0052ade0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-P  
**Scope:** VAs `0x0045dd60`, `0x0052ade0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-P).  
**Note:** `0x0052ade0` is **mission-adjacent** (Val12 counter map / dirty flags; sole CODE caller is debug slash).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0045dd60` Anm_KestChunk_ReadF32Array_Inferred | **accept-with-gaps** — ECX count / EDI reader / stack dest / bare RET / KEST / *7 f32 sealed; product KEST English open |
| `aa_0052ade0` CVOGCharacter_SetMissionCounterMax_Inferred | **accept-with-gaps** — thiscall ret 8 / hit-only +0x10 clamp to +0x14 / dirty 0x40 sealed; max English + dual-field policy open |

---

## VA `0x0045dd60` — sealed facts

1. **Body:** `0x0045dd60`–`0x0045de07` inclusive (**168 B** / `0xA8`; pad `CC` then next).
2. **ABI:** **ECX=`elem_count`**, **EDI=`stoChunkReader*`** (register formal), stack **`float* dest`**, bare **`RET`** (caller **`ADD ESP,4`**). Returns **`readF32Array` status** or **`0xFFFFFFFF`** on tag miss. Decompiler void/unaff formals are **not** complete — **bytes + call site win**.
3. **Semantics:** KEYR-style nested chunk element load for track-master Pod28:
   - SEH + `stoChunkReader_EnterChunkScope(scope, reader=EDI)`.
   - Require scope tag **`KEST`** (`0x4B455354`, imm bytes `54 53 45 4B`).
   - On hit: `stoChunkReader_readF32Array(dest, reader, elem_count * 7)` — **7 f32 = one Pod28** (stride `0x1C`).
   - Leave via `FUN_00769e40` when scope `okFlag`; tag miss → leave → `-1`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_00459750` / `AnmTrackMaster_Unserialize_Inferred` @ `0x004599d6` — after `StdVector_Resize_Pod28`; `PUSH [this+0x20]` begin, `ECX=count`, `EDI=reader`.
6. **Callees:** `stoChunkReader_EnterChunkScope` (`0x004370b0`), `stoChunkReader_readF32Array` (`0x00436090`), `FUN_00769e40`.
7. **Name:** `Anm_KestChunk_ReadF32Array_Inferred` (Ghidra `FUN_0045dd60`; **Inferred** structural from tag + parent). **Reject** scaffold `Named_CalleeOf_Named_anmTrackMaster_inl_0045dd60`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on ECX/EDI/stack formals, count×7, bare RET.  
   Full hex: raw W37-P append (168 B).

### Gaps

- Product/PDB English for fourCC **KEST**.  
- SEH unwind path via `LAB_009bef98` not line-reconstructed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0045dd60_Anm_KestChunk_ReadF32Array_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0045dd60_Anm_KestChunk_ReadF32Array_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0045dd60_FUN_0045dd60.md` |
| Annotated | `docs/reconstruction/raw/aa_0045dd60_FUN_0045dd60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Anm_KestChunk_ReadF32Array_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0045dd60.cpp` |
| Function | `docs/reconstruction/functions/aa_0045dd60_FUN_0045dd60.md` |
| Function named | `docs/reconstruction/functions/aa_0045dd60_Anm_KestChunk_ReadF32Array_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0045dd60.md` |

---

## VA `0x0052ade0` — sealed facts

1. **Body:** `0x0052ade0`–`0x0052ae21` inclusive (**66 B** / `0x42`; pad `CC` then next).
2. **ABI:** **`__thiscall`**, **ECX=`Character*`**, stack **`(key, value)`**, void, **`RET 8`**.
3. **Semantics:** Val12 map field write (mission-adjacent):
   - `FUN_00418b80(map=char+0x584, &node, &key)` lower_bound.
   - If `node == *(char+0x588)` (**miss**): **return immediately** — **no insert** (contrast SetMissionCounter).
   - **Hit:** `*(node+0x10) = value`; if `*(node+0x14) < value` then `*(node+0x10) = *(node+0x14)` → stored value is **`min(value, node+0x14)`**.
   - `*(char+0x634) |= 0x40` dirty (hit only).
4. **Classification:** worker.
5. **Callers (1):** `FUN_0094e530` / `Client_DebugCmd_AddDisciplinePoints` @ `0x0094e5de` — optional third-token "set max as well" after sealed `CVOGCharacter_SetMissionCounter`.
6. **Callees:** `FUN_00418b80` only.
7. **Name:** `CVOGCharacter_SetMissionCounterMax_Inferred` (Ghidra `FUN_0052ade0`; **Inferred** from slash help + field +0x10). Sibling field policy: Set/Add write **+0x14**; Get path reads **+0x10**.
8. **Decompile vs bytes:** CF ≡ raw; bytes seal map LEA `+0x584`, end `+0x588`, store/clamp/dirty, **`C2 08 00`**.  
   Full hex: raw W37-P append (66 B).

### Gaps

- Product English for "max" vs other +0x10 meanings; dual-field Get/Set sync policy open.  
- Production (non-debug) callers not found — may be debug-only.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0052ade0_CVOGCharacter_SetMissionCounterMax_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0052ade0_CVOGCharacter_SetMissionCounterMax_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0052ade0_FUN_0052ade0.md` |
| Annotated | `docs/reconstruction/raw/aa_0052ade0_FUN_0052ade0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetMissionCounterMax_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0052ade0.cpp` |
| Function | `docs/reconstruction/functions/aa_0052ade0_FUN_0052ade0.md` |
| Function named | `docs/reconstruction/functions/aa_0052ade0_CVOGCharacter_SetMissionCounterMax_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0052ade0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0045dd60` | Port as **KEST nested f32 blob read** after Pod28 track resize: **ECX=count**, **reader** (retail **EDI**), **dest***, bare RET, status/`-1`. Pack **count×7** floats. Do **not** invent thiscall(reader) or omit ×7. Server can expose `ReadArray<Pod28>(n)` without EDI artifact. |
| `0052ade0` | Port as **hit-only map field +0x10 set** with clamp ≤ **+0x14** and dirty **`+0x634\|=0x40`**, **ret 8**. Do **not** use for current-value set (+0x14) — that is `CVOGCharacter_SetMissionCounter`. Do **not** insert on miss. Debug slash optional max path today; still seal for counter dual-field policy. |
| Shared | Wave co-ownership only — **not** algorithmically related. Closes W36-M residual element load under track-master unserialize + W31-T residual max helper under debug discipline slash. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00459750` | `AnmTrackMaster_Unserialize_Inferred` (W36-M) — sole parent of KEST reader |
| `0x0045c4b0` | `StdVector_Resize_Pod28` (W35-M) — resize before element fill |
| `0x004370b0` | `stoChunkReader_EnterChunkScope` |
| `0x00436090` | `stoChunkReader_readF32Array` |
| `0x00769e40` | leave chunk scope |
| `0x0045d810` | sibling KEYR-style reader (different tag) |
| `0x005305b0` | `CVOGCharacter_SetMissionCounter` — writes +0x14 |
| `0x00530610` | `CVOGCharacter_AddMissionCounter` — += +0x14 |
| `0x0052ada0` | GetResourceBalance path — reads +0x10 |
| `0x00418b80` | map lower_bound |
| `0x0094e530` | `Client_DebugCmd_AddDisciplinePoints` — sole max helper caller |

Closes W37-P OWN pair: **KEST/Pod28 track element load** + **mission-adjacent counter max field setter**.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural / slash-help names only.  
- Rejected long Named_CalleeOf scaffold alias for `0045dd60`.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit pointers / ChunkScope).  
- Flagged `0052ade0` as mission-adjacent per task note.
