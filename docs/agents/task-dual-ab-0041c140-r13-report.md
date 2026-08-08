# Dual A/B report — R13-022 OWN-ONLY (`0x0041c140`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-022**  
**Scope:** VA `0x0041c140` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including buy `0041c250`, Ucopy `00422580`, buynode `0041d860`, parent re-dual `0041ba30`, callers `0059a940` / `007eaf20`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context` + `get_function_by_address` + callee/buynode decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-022**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC `vector` copy-ctor).  
**Parent dual:** `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (R12-011).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0041c140` StdVector_CopyCtor_Elem0x18_Inferred | **accept-with-gaps** — copy-ctor CF/ABI/RET4/stride-0x18/layout/node+0x10 sealed; product + element English residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): assign-op / bare-Ucopy-merge / SkillSet-`0040a600`-merge / leaf-`00442b00`-merge / cdecl / freelist / tree-insert-as-self / Named_CalleeOf product / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0041c140` — sealed facts

1. **Body:** `0x0041c140`–`0x0041c1c9` inclusive (**138 B** / `0x8A`).
2. **ABI:** **`__thiscall`** ECX=`VecShell* dest`; stack `const VecShell* src`; **`ret 0x4`** (`C2 04 00`). EAX returns `dest`.
3. **Semantics:** MSVC-style **`std::vector` copy constructor** for **0x18-byte** elements:
   - SEH frame (`LAB_009bce90` / FS:[0]).
   - `count = (src.begin == 0) ? 0 : (src.end - src.begin) / 0x18` (mul-inverse `0x2AAAAAAB`).
   - Residual buy `FUN_0041c250(dest, count)`: zero begin/end/cap; if `count==0` return 0; else `operator_new(count*0x18)`, set begin=end=buf, cap=buf+count*0x18, return 1.
   - If bought: residual POD Ucopy `FUN_00422580(src.begin, src.end, dest.begin, dest, src)` (6-dword / +0x18 step; two extra shell args unused); `dest.end = EAX`.
   - Return `dest`.
4. **Layout:** `begin@+0x4`, `end@+0x8`, `capacity_end@+0xC`. Map node (from buynode): char key @**+0x0C**, value vector @**+0x10**, color@**+0x20**, isnil@**+0x21**, node **0x24**.
5. **Callees:** `0041c250` buy (undualed); `00422580` POD Ucopy (undualed).
6. **Callers (3 fns / 7 sites):** `FUN_0041d860` @ `0041d8c2`; `FUN_0059a940` @ `0059aae5`, `0059ab03`; `FUN_007eaf20` @ `007eba0a`, `007eba34`, `007ec69b`, `007ec6c5`.
7. **Xrefs:** 7 UNCONDITIONAL_CALL.
8. **Name:** `StdVector_CopyCtor_Elem0x18_Inferred` (Ghidra `FUN_0041c140`). Product demangle open → `_Inferred`. Retired Named_CalleeOf / VOG_DEBUG chain as product name.
9. **Twins (do not merge):** SkillSet range Ucopy `0040a600` (cdecl); leaf Ucopy `00442b00`; parent always-insert `0041ba30` (different role).
10. **Decompile ≡ raw CF**; RET4 + thiscall + `/0x18` + node+0x10 sealed via `read_memory` + `get_assembly_context`.

### Gaps

- Product / MSVC demangle for `vector<T>` / map `value_type`.  
- Element-type English (0x18 POD; SkillSet-sized only until proven).  
- Full dual of buy `0041c250`, Ucopy `00422580`, buynode `0041d860`, other callers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0041c140_FUN_0041c140.md` |
| Annotated | `docs/reconstruction/raw/aa_0041c140_FUN_0041c140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_CopyCtor_Elem0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0041c140.cpp` |
| Function | `docs/reconstruction/functions/aa_0041c140_FUN_0041c140.md` |
| Function named | `docs/reconstruction/functions/aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (0x0041ba30)  [R12-011 dualed] ← parent dual
  └─ FUN_0041d860  buynode node0x24 / char@+0x0C / isnil21  [undualed]
       └─ StdVector_CopyCtor_Elem0x18_Inferred (0x0041c140)  [OWN R13-022]
            ├─ FUN_0041c250  buy/zero+alloc elem0x18  [undualed]
            └─ FUN_00422580  POD Ucopy 6-dword / 0x18  [undualed]

FUN_0059a940 / FUN_007eaf20  additional value/pair construct sites  [undualed]
  └─ StdVector_CopyCtor_Elem0x18_Inferred (0x0041c140)

Peers (do not merge):
  0040a600 SkillSet_Vector_UninitializedCopy_0x18_Inferred  (range Ucopy cdecl)
  00442b00 SkillSet_UninitializedCopy_0x18                  (leaf register ABI)
```

Partition system **skills-abilities** explains queue membership under residual skills map helpers; the unit itself is a **generic vector copy-ctor**, not a skill-cast product API.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0041c140-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0041c140` | Port as **shared StdVector copy-ctor** for **elem size 0x18**. **`__thiscall`** ECX=dest shell; stack src; **ret 4**; EAX=dest. Fields **begin@+4 / end@+8 / cap@+0xC**. Pair with buy `0041c250`, POD Ucopy `00422580`, char-key buynode `0041d860` (value vector @ **node+0x10**), always-insert parent `0041ba30`. |
| Pair with | dualed parent insert `0041ba30`; residual buy/Ucopy/buynode. |
| Naming caution | **Not** range Ucopy `0040a600`. **Not** leaf Ucopy `00442b00`. **Not** assign-operator. **Not** tree insert. **Not** skill-product name without element proof. **Never Runtime Confirmed** from this dual alone. |

---

## Parent merge handoff (not done here)

Parent dual R12-011 listed value-type English via this unit as a residual gap — now dualed R13-022 as vector copy-ctor for the map-value payload. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent). Dual start baseline **2686**; Terminal remains **false**.
