# Dual A/B report — W32-Q OWN-ONLY (`0x0048f2d0`, `0x00756320`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-Q  
**Scope:** VAs `0x0048f2d0`, `0x00756320` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` → **W32-Q**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0048f2d0` PalantirEnv_ApplyDefaultScalars_Inferred | **accept-with-gaps** — ABI/body 145 B/child thiscall/scalar bank+100/200/clear+0x178 sealed; product field English + orphan site owner open |
| `aa_00756320` HostBase_EnsureAuxPtrs_Inferred | **accept-with-gaps** — thiscall+RET4/idempotent −1/flag bit0/+4/+8 ensure sealed; product host & nested allocator English open |

---

## VA `0x0048f2d0` — sealed facts

1. **Body:** `0x0048f2d0`–`0x0048f361` exclusive (**145 B** / `0x91`). Final **`C3`** (bare RET); frame `SUB ESP,0x10` / `ADD ESP,0x10`; pad `CC`.
2. **ABI:** ECX=`env*` (`8B F1`); Ghidra `__fastcall` ≡ thiscall; **no** stack formals; void.
3. **Semantics:** Palantir env default-scalar apply:
   - If `env+0x100 != 0` → `FUN_00497c80` with **ECX=child** (decompiler omits formal; bytes seal).
   - `+0x10c = DAT_00aaa7ac` (**100.0f**); `+0x110 = DAT_00aaa884` (**200.0f**).
   - Bank via `LEA EAX,[ESI+0x60]`: `+0x60=_DAT_009c774c` (~0.215646f), `+0x64/+0x68=DAT_009c7748` (~0.254894f), `+0x6c=g_flOne` (**1.0f** @ `0x00a0f2a0`).
   - `+0x178 = 0`.
4. **Classification:** worker.
5. **Callers / xrefs (2):** `FUN_00492dd0` (`PalantirEnv_Ctor_Inferred`) @ `0x00493090` (post child@`+0x100`); orphan CALL @ `0x004d966b` (`mov ecx,[esi+0xE894]`).
6. **Callees:** `FUN_00497c80` only.
7. **Related:** ctor W31-P; phases W31-P re-clear `+0x178`; child ctor `FUN_00497920` (W32-P).
8. **Name:** `PalantirEnv_ApplyDefaultScalars_Inferred` (Ghidra `FUN_0048f2d0`). **Reject** scaffold parent-seed long name.
9. **Decompile ≡ CF**; ABI/bounds/constants sealed by `read_memory` (full 145 B hex in raw W32-Q section).

### Gaps

- Product English for scalar fields / bank meaning.  
- Child@`+0x100` / `FUN_00497c80` product roles.  
- Orphan site enclosing function at `0x004d966b`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0048f2d0_PalantirEnv_ApplyDefaultScalars_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0048f2d0_PalantirEnv_ApplyDefaultScalars_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0048f2d0_FUN_0048f2d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0048f2d0_FUN_0048f2d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirEnv_ApplyDefaultScalars_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048f2d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0048f2d0_FUN_0048f2d0.md` |
| Function named | `docs/reconstruction/functions/aa_0048f2d0_PalantirEnv_ApplyDefaultScalars_Inferred.md` |

---

## VA `0x00756320` — sealed facts

1. **Body:** `0x00756320`–`0x007563bf` exclusive (**159 B** / `0x9F`). Multi-path **`C2 04 00`** (`RET 4`); SEH `LAB_009afd8d`.
2. **ABI:** **`__thiscall`**; ECX=`host*`; stack formal **flags** (`uint`); returns **0** or **`0xFFFFFFFF`**.
3. **Semantics:** host-base aux-pointer ensure (after `FUN_007560d0` zeros slots):
   - If `host+4` **or** `host+8` non-null → return **−1** (idempotent fail).
   - If `(flags & 1)` → EBX=`*DAT_00d1f624`; `FUN_00986070` → `host+4`.
   - Always: `operator_new(0x14)` + `FUN_00442c80` (`PTR_FUN_00a9f49c`, zero indices 2..4) → `host+8` (null on OOM).
   - Return **0**.
4. **Classification:** worker.
5. **Callers (6):** `FUN_0048fc90` @ `0x0048fcb1` (InitPhases prelude); `FUN_004c2080` @ `0x004c2088`; `FUN_0055cc50` @ `0x0055cc58`; `FUN_005b39a0` @ `0x005b39a8`; `FUN_0078caf0` @ `0x0078ceb1`; `FUN_00792600` @ `0x007926e2`.
6. **Callees:** `FUN_00986070`, `operator_new`, `FUN_00442c80`.
7. **Related base:** `FUN_007560d0` (vtbl `PTR_FUN_00a9f534`, zeros `+4/+8`); PalantirEnv ctor starts with this base; UI path `new(0x80)+FUN_007560d0`.
8. **Name:** `HostBase_EnsureAuxPtrs_Inferred` (Ghidra `FUN_00756320`). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_00756320`.
9. **Decompile ≡ CF**; return codes and RET 4 sealed by bytes.

### Gaps

- Product host / `FUN_007560d0` plate English.  
- `FUN_00986070` / `DAT_00d1f624` product roles.  
- Product identity of 0x14-byte object.  
- Flag bits beyond bit0.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00756320_HostBase_EnsureAuxPtrs_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00756320_HostBase_EnsureAuxPtrs_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00756320_FUN_00756320.md` |
| Annotated | `docs/reconstruction/raw/aa_00756320_FUN_00756320.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostBase_EnsureAuxPtrs_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00756320.cpp` |
| Function | `docs/reconstruction/functions/aa_00756320_FUN_00756320.md` |
| Function named | `docs/reconstruction/functions/aa_00756320_HostBase_EnsureAuxPtrs_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0048f2d0` | Port as **env method** after child@`+0x100` install: optional child prepare (`FUN_00497c80`), then write **100/200** ranges, float bank at `+0x60` (774c, 7748, 7748, 1.0), clear `+0x178`. Call from ctor tail; may re-apply when env reloaded from `parent+0xE894`. Do **not** fold into InitPhases. |
| `00756320` | Port as **host-base ensure** after `FUN_007560d0` (or equivalent zero of `+4/+8`): if either slot live → return −1; bit0 allocates optional `+4`; always small `+8` object (0x14). Used by InitPhases prelude and phase enables. Do **not** treat as PalantirEnv-only. |
| Pair with | `PalantirEnv_Ctor_Inferred` (`0x00492dd0`, W31-P); `PalantirEnv_InitPhases_Inferred` (`0x0048fc90`, W31-P); base `FUN_007560d0`; child `FUN_00497920` (W32-P); small ctor `FUN_00442c80`. |

### Lifecycle (sealed relative order)

```
FUN_007560d0(env)                 // zeros +4/+8; base vtbl
... PalantirEnv rest of ctor ...
new(0xC8)+FUN_00497920 → +0x100
PalantirEnv_ApplyDefaultScalars   // this dual's 0048f2d0
// factory wires view@+0xC0
PalantirEnv_InitPhases(flag=1)
  → HostBase_EnsureAuxPtrs(flag)  // this dual's 00756320
  → water/distort/owned phases...
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (PalantirEnv from W31-P factory; HostBase from `FUN_007560d0` family).  
- Rejected scaffold parent-seed / VOG_DEBUG_STOP names.  
- Pattern: `docs/agents/task-dual-ab-00492dd0-0048fc90-w31p-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
