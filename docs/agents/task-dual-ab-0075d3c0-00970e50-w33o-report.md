# Dual A/B report — W33-O OWN-ONLY (`0x0075d3c0`, `0x00970e50`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-O  
**Scope:** VAs `0x0075d3c0`, `0x00970e50` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` → **W33-O**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0075d3c0` AssManager_EnsureAssPreloader_Inferred | **accept-with-gaps** — RET4/idempotent +0x6c/new(0x114)+ctor/seed list+8→pre+0xAC sealed; product English + nested ctor open |
| `aa_00970e50` AssPreloader_RetireStaleNeverLoaded_Inferred | **accept-with-gaps** — RET8/age polarity/map+0x10/product never-loaded+count logs/ring+0xAC sealed; method English + erase dual open |

---

## VA `0x0075d3c0` — sealed facts

1. **Body:** `0x0075d3c0`–`0x0075d466` exclusive (**166 B** / `0xA6`). Final **`C2 04 00`** (`RET 4`); SEH `LAB_009acd06`; pad `CC`.
2. **ABI:** stack `host*` (AssManager / NDResourceCache @ `DAT_00d1f050`); **no** ECX thiscall; void.
3. **Semantics:** AssManager ensure AssPreloader:
   - If `host+0x6c != 0` → return (idempotent).
   - `operator_new(0x114)` + `FUN_00970cf0` (AssPreloader ctor) → store at `host+0x6c` (null on OOM).
   - Walk circular list at `host+8`; for each node pack PodU32U8 `{*(node+8), 1}` and **locked** push into **preloader `+0xAC`** via `FUN_0043e8f0` + `FUN_0043e7f0` (`GuardedVector_PushBackLocked_Stride2_U32U8`).
4. **Classification:** worker.
5. **Callers (2):** `FUN_0075d470` @ `0x0075d4ec` (host ctor: zeros `+0x6c` then ensure); `FUN_00934420` @ `0x00934448` ("Preloading enabled" → `DAT_00d1f050`).
6. **Callees:** `operator_new`, `FUN_00970cf0`, `FUN_0043e8f0`, `FUN_0043e7f0`.
7. **Related:** disable path `FUN_00934420` destroys `*(DAT_00d1f050+0x6c)`; AssManager_SweepTrackedAssets uses same list `+8` and secondary host `+0x6c`; retire dual uses ring `+0xAC`.
8. **Name:** `AssManager_EnsureAssPreloader_Inferred` (Ghidra `FUN_0075d3c0`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_0075d3c0`.
9. **Decompile ≡ CF**; ABI/bounds/seed offsets sealed by `read_memory` (full 166 B hex in raw W33-O section).

### Gaps

- Product method English.  
- Nested AssPreloader ctor (`FUN_00970cf0`) full dual.  
- OOM seed path residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0075d3c0_AssManager_EnsureAssPreloader_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0075d3c0_AssManager_EnsureAssPreloader_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0075d3c0_FUN_0075d3c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075d3c0_FUN_0075d3c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_EnsureAssPreloader_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075d3c0.cpp` |
| Function | `docs/reconstruction/functions/aa_0075d3c0_FUN_0075d3c0.md` |
| Function named | `docs/reconstruction/functions/aa_0075d3c0_AssManager_EnsureAssPreloader_Inferred.md` |

---

## VA `0x00970e50` — sealed facts

1. **Body:** `0x00970e50`–`0x00970fb8` exclusive (**360 B** / `0x168`). Final **`C2 08 00`** (`RET 8`); SEH `LAB_009adafb`.
2. **ABI:** stack `(AssPreloader* self, float maxAge)`; void.
3. **Semantics:** AssPreloader age-based retire of never-loaded tracked entries:
   - `now = FUN_0076c330()`.
   - Walk map at `self+0x10` (end sentinel `self+0x14`).
   - Node: key `@+0x0C`, object* `@+0x10`, float stamp `@+0x14`.
   - If `(now - stamp) <= maxAge` → iterator++ only (`FUN_00457cc0`).
   - Else: optional `vtbl[0](obj, 1)`; `FUN_0096a630` assId; log **line 0x2A8**  
     `"Preloaded asset <%s> never loaded. Retiring and removing."`;  
     locked PodU32U8 push to **`self+0xAC`**; iterator++; `FUN_00447350(self+0x10)` erase; `retired++`.
   - Always log **line 0x2B7** `"Retired %d preload blocks from pool."`.
4. **Classification:** worker.
5. **Callers (1):** `FUN_007b7000` @ `0x007b708a` — `self=*(DAT_00d1f050+0x6c)`, `maxAge=300.0f` (`0x43960000`), after 5.0f period gate (`DAT_00aaa688`).
6. **Callees:** `FUN_0076c330`, `FUN_00457cc0`, vtbl release, `FUN_0096a630`, `FUN_0076cec0`, `vog_LogMessage`, `FUN_0043e8f0`, `FUN_0043e7f0`, `FUN_00447350`.
7. **Related:** ensure dual installs preloader + seeds same `+0xAC` ring; worker/enqueue duals share AssPreloader host.
8. **Name:** `AssPreloader_RetireStaleNeverLoaded_Inferred` (Ghidra `FUN_00970e50`). **Reject** scaffold `Named_assPreloader_00970e50` as final plate (family only).
9. **Decompile ≡ CF**; RET 8 / product strings / age polarity sealed by bytes + `read_memory`.

### Gaps

- Product method English.  
- Exact map element / key product types.  
- Nested erase (`FUN_00447350`) dual residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00970e50_AssPreloader_RetireStaleNeverLoaded_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00970e50_AssPreloader_RetireStaleNeverLoaded_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00970e50_FUN_00970e50.md` |
| Annotated | `docs/reconstruction/raw/aa_00970e50_FUN_00970e50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_RetireStaleNeverLoaded_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970e50.cpp` |
| Function | `docs/reconstruction/functions/aa_00970e50_FUN_00970e50.md` |
| Function named | `docs/reconstruction/functions/aa_00970e50_AssPreloader_RetireStaleNeverLoaded_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0075d3c0` | Port as **AssManager ensure** when preloading turns on or host constructs: if `+0x6c` null, construct AssPreloader (`0x114` + ctor) and seed ring `pre+0xAC` from current tracked-asset list keys (`host+8`, PodU32U8 `{key,1}`). Idempotent. Do **not** re-seed when preloader already live. |
| `00970e50` | Port as **AssPreloader periodic retire**: map at `+0x10`, age stamp `node+0x14`, keep if age ≤ maxAge (retail tick **300s**), else release + log never-loaded + push `+0xAC` + erase; always log count. Pair with ensure so `+0x6c` exists before tick. |
| Pair with | AssPreloader ctor `FUN_00970cf0`; `AssManager_SweepTrackedAssets_Inferred` (`0x0075de80`); `GuardedVector_PushBackLocked_Stride2_U32U8` (`0x0043e7f0`, W32-N); `Palantir_StartPreloadThread_Inferred` (`0x00754280`); worker/enqueue duals W31–W32. |

### Lifecycle (sealed relative order)

```
AssManager ctor (FUN_0075d470)
  zeros host+0x6c
  AssManager_EnsureAssPreloader   // this dual 0075d3c0 (may construct + seed +0xAC)
...
"Preloading enabled" (FUN_00934420)
  AssManager_EnsureAssPreloader(DAT_00d1f050)
  Palantir_StartPreloadThread
...
tick FUN_007b7000 (period ≥ 5.0f)
  if preloader live:
    AssPreloader_RetireStaleNeverLoaded(pre, 300.0f)  // this dual 00970e50
```

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/body bounds). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (AssManager from SweepTrackedAssets / `+0x6c` secondary; AssPreloader from `assPreloader.cpp` + logs).  
- Rejected scaffold Client_InitInstance / bare Named_assPreloader plates.  
- Pattern: `docs/agents/task-dual-ab-0048f2d0-00756320-w32q-report.md`.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
