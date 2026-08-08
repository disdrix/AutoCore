# Dual A/B report — R13-029 OWN-ONLY (`0x005114e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-029** (dual start **2686**)  
**Scope:** VA `0x005114e0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including residual buynode `005118b0`, InsertOrFind `00511b40`, range-copy `005dd920`, length_error `004540b0`, peer InsertN `00408640`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-029**.  
**System:** skills-abilities.  
**Parent dual:** `0x00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (R12-014).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005114e0` StdVector_CopyCtor_Elem0x10_Inferred | **accept-with-gaps** — copy-ctor CF/ABI/RET4/stride0x10/triad sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): copy-assign / InsertN / wrong stride / cdecl / wrong RET / tree-op / skill-only / merge-with-InsertN all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005114e0` — sealed facts

1. **Body:** `0x005114e0`–`0x00511583` inclusive (**164 B** / `0xA4`); epilogue `C2 04 00`; `CC` pad before next unit.
2. **ABI:** **`__thiscall`** ECX=dest vector; stack `(const src*)`; **`ret 4`**; returns dest in EAX.
3. **Semantics:** MSVC-style **`std::vector` copy constructor** for **Elem0x10**:
   - `n = (src.end - src.begin) >> 4` (0 if begin null).
   - Zero dest `+4/+8/+0xC`.
   - Empty → return this.
   - If `n > 0x0FFFFFFF` → `FUN_004540b0` noreturn length_error.
   - `operator_new(n * 0x10)`; plant begin=end=buf, capEnd=buf+bytes.
   - `FUN_005dd920` POD uninit_copy (4 dwords/element); set end.
4. **Layout:** vec `+0` allocator untouched; `+4` begin; `+8` end; `+0xC` capEnd; element **0x10**.
5. **Callees:** `FUN_004540b0` (throw), `operator_new`, `FUN_005dd920` (range POD copy).
6. **Callers (2):** `FUN_005118b0` @ `0x00511912` (buynode payload); `FUN_0050ba90` @ `0x0050bb93`, `0x0050bbae` (value build → InsertOrFind).
7. **Xrefs:** 3 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_CopyCtor_Elem0x10_Inferred` (Ghidra `FUN_005114e0`). Product demangle open → `_Inferred`. **Not** InsertN `00408640` / PodCopy `00409f70` / tree insert `00511950`.
9. **Decompile ≡ raw CF**; RET / stride / max gate sealed via `read_memory` + `disassemble_function`; call sites `LEA ECX,…` seal thiscall.

### Gaps

- Product / MSVC demangle for exact `vector<T>` element type.  
- Nested range-copy `005dd920` and length_error `004540b0` residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005114e0_StdVector_CopyCtor_Elem0x10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005114e0_StdVector_CopyCtor_Elem0x10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005114e0_FUN_005114e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005114e0_FUN_005114e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_CopyCtor_Elem0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005114e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005114e0_FUN_005114e0.md` |
| Function named | `docs/reconstruction/functions/aa_005114e0_StdVector_CopyCtor_Elem0x10_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_00511b40  InsertOrFind int-key shell  [residual]
  └─ StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (0x00511950)  [parent dual R12-014]
       └─ FUN_005118b0  buynode Node24 isnil21  [residual]
            └─ StdVector_CopyCtor_Elem0x10_Inferred (0x005114e0)  [OWN R13-029]
                 ├─ FUN_005dd920  POD uninit_copy 0x10  [residual]
                 └─ FUN_004540b0  length_error  [residual]

FUN_0050ba90  skill-map value build  [residual]
  └─ (2×) StdVector_CopyCtor_Elem0x10_Inferred  [OWN]
       └─ FUN_00511b40 InsertOrFind  [residual]

Elem0x10 family peers (dualed elsewhere):
  00409f70 StdVector_PodCopyElement_0x10_Inferred
  00409e20 StdVector_ConstructN_Elem0x10_Inferred
  00408640 StdVector_InsertN_Elem0x10_Inferred
  00407000 StdVector_UninitializedFillN_Elem0x10_Inferred
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005114e0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005114e0` | Port as **shared std::vector copy-ctor** for **Elem0x10** (16-byte POD). **thiscall** ECX=dest; stack `const src*`; **ret 4**; return this. Triad `+4/+8/+0xC`. Max `0x0FFFFFFF` elements. Pair with residual range-copy `005dd920` and throw `004540b0`. Do **not** merge with InsertN `00408640` or PodCopy leaf `00409f70`. |
| Pair with | parent dual Node24 insert `00511950`; residual buynode `005118b0` embeds vector at `node+0x10`. |
| Naming caution | **Not** InsertN / assign / tree insert. Keep **`_Inferred`**. Never Runtime Confirmed. |

---

## Parent merge handoff (not done here)

Parent dual R12-014 listed value_type as int key + vector of 0x10 elements — this unit seals that vector copy-ctor. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).

**Terminal:** false.
