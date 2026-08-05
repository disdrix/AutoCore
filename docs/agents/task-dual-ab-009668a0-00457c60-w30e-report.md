# Dual A/B report — W30-E OWN-ONLY (`0x009668a0`, `0x00457c60`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-E  
**Scope:** VAs `0x009668a0`, `0x00457c60` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` → **W30-E**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009668a0` PerfStatRings_CommitAndTrim_Inferred | **accept-with-gaps** — stdcall `ret 4` + 4+1 GuardedVector rings + dual window trims (500/3000) + snapshot publish sealed; product channel labels/units open |
| `aa_00457c60` StdList_AllocSentinel_0x18_Inferred | **accept** — `operator_new(0x18)` + circular self-link + EAX return + 3 call sites fully sealed |

---

## VA `0x009668a0` — sealed facts

1. **Body:** `0x009668a0`–`0x00966c03` exclusive (**867 B** / `0x363`; pad `CC`).
2. **ABI:** **1 stack formal** (stats object*); **`RET 4`** (`C2 04 00`). Prologue `53 55 8B 6C 24 0C`. Decompiler cdecl/`void` presentation is misleading.
3. **Semantics:** Commit current period bins into perf rings and trim windows:
   - `+0x3D0++` (commit counter).
   - If `+0xC8==0`: `FUN_0076c3c0` (ECX=object) → attribute delta into `bins[+0x34 + phase*4]`; `phase(+0xC4)=3`.
   - For `i=0..3`: `GuardedVector_PushBack` ring at `+0x5C + i*0x14` with value `&bins[+0x34+i*4]` (**EAX=container**, stack=value* — W29-B); accumulate channel totals `+0x44..+0x50` and local sum.
   - Add sum to short `+0x54` and long `+0xC0`; PushBack sum ring `+0xAC`; `sample_count(+0x58)++`.
   - While `+0x54 > 500`: load oldest absolute index per ring (`begin + size - sample_count`, page-wrapped); subtract from channel totals and short sum; `sample_count--`.
   - While `+0xC0 > 3000`: advance begin / dec size on 4 channel rings + sum ring (wrap at `capacity*4`); subtract oldest sum from long sum. Cold body laid out after epilogue linear address.
   - Zero bins `+0x34..+0x40`; copy **0x4C** dwords `+0xCC → +0x1FC`; zero live `+0xCC`.
   - Optional timer close; `phase=0`.
4. **Classification:** worker — callees `FUN_0076c3c0`, `FUN_0043c830` (PushBack ×5).
5. **Callers (1):** `FUN_007545c0` @ `0x007545e1` — `FUN_009668a0(DAT_00d1f614)` (Palantir frame path).
6. **Name:** `PerfStatRings_CommitAndTrim_Inferred` (Ghidra `FUN_009668a0`; **Inferred** structural). Legacy Palantir seed is caller-path evidence only.
7. **Decompile ≡ raw CF stages** (live 2026-07-29 ≡ raw 2026-07-23). ABI + PushBack call shape corrected by `read_memory`.  
   Full hex: see raw W30-E append (entry 0x80 + seals).

### Gaps

- Product English for 4 channel names / overlay labels.  
- Timer sample units and physical meaning of 500 / 3000.  
- Snapshot blob product type at `+0xCC` / `+0x1FC`.  
- Parent `007545c0` / global `DAT_00d1f614` ownership (unowned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009668a0_PerfStatRings_CommitAndTrim_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009668a0_PerfStatRings_CommitAndTrim_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009668a0_FUN_009668a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009668a0_FUN_009668a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PerfStatRings_CommitAndTrim_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009668a0.cpp` |
| Function | `docs/reconstruction/functions/aa_009668a0_FUN_009668a0.md` |
| Function named | `docs/reconstruction/functions/aa_009668a0_PerfStatRings_CommitAndTrim_Inferred.md` |

---

## VA `0x00457c60` — sealed facts

1. **Body:** `0x00457c60`–`0x00457c7a` exclusive (**26 B** / `0x1A`; pad `CC`).
2. **ABI:** no formals; **EAX out** = `operator_new(0x18)` result; bare **`C3` RET**. Decompiler `void` is wrong.
3. **Semantics:** Sentinel factory:
   - `operator_new(0x18)`.
   - If non-null: `*node = node` (next=self).
   - `*(node+4) = node` (prev=self); LEA/TEST pattern matches 0x0C sibling.
   - Only first **8** bytes written; trailing **0x10** untouched by this unit.
4. **Classification:** wrapper / factory — callee `operator_new`.
5. **Callers (3):** `FUN_00457b30`, `FUN_00496f70` / Class_009c7a1c_Ctor (list head `+0x10`), `FUN_00575440` / Object_009d33c4_Ctor (list head `+0x1E0`). All store EAX and zero size.
6. **Name:** `StdList_AllocSentinel_0x18_Inferred` (Ghidra `FUN_00457c60`; **Inferred**). Sibling of `StdList_AllocEmptySentinel_Inferred` (`0x0040fb90`, node **0x0C**).
7. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `6a18e82b1c030083c40485c0740289008d480485c974028901c3`.

### Gaps

- Product element / payload type for 0x18 node.  
- Whether callers require zeroed trailing 0x10.  
- Runtime under non-throwing `operator_new` (null path would write absolute address 4).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00457c60_StdList_AllocSentinel_0x18_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00457c60_StdList_AllocSentinel_0x18_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00457c60_FUN_00457c60.md` |
| Annotated | `docs/reconstruction/raw/aa_00457c60_FUN_00457c60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_AllocSentinel_0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457c60.cpp` |
| Function | `docs/reconstruction/functions/aa_00457c60_FUN_00457c60.md` |
| Function named | `docs/reconstruction/functions/aa_00457c60_StdList_AllocSentinel_0x18_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009668a0` | Port as **stdcall** (`ret 4`) on global stats object. Push bins via **GuardedVector_PushBack** (EAX=ring, stack=value*) into 4 rings at `+0x5C` stride `0x14` plus sum ring `+0xAC`. Enforce short window **500** and long window **3000**. Publish `0x4C` dwords then clear live. Do not use thiscall or plain `vector::push_back`. |
| `00457c60` | Port as pure factory: `new 0x18`, self-link next/prev, return node*. Callers set head + size=0. Do not merge with **0x0C** sibling `0040fb90`. |
| Pair with | `GuardedVector_PushBack` (`0x0043c830`), `Class_009c7a1c_Ctor` (`0x00496f70`), `Object_009d33c4_Ctor` (`0x00575440`), `StdList_AllocEmptySentinel_Inferred` (`0x0040fb90`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` structural names only (`PerfStatRings_*`, `StdList_AllocSentinel_0x18_*`).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
