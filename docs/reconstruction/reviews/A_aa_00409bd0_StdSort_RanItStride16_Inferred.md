# Review A (reconstruction fidelity): `aa_00409bd0` StdSort_RanItStride16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409bd0` |
| **VA** | `0x00409bd0`–`0x00409cb9` inclusive (**234 B** / `0xEA`) |
| **Canonical name** | `StdSort_RanItStride16_Inferred` |
| **Ghidra name** | `FUN_00409bd0` |
| **Prior scaffold** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_00409bd0` |
| **Rejected misname** | PollBoundActions nested worker / action-map poll leaf |
| **Review date** | `2026-08-05` (MEGA-043 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00409bd0_StdSort_RanItStride16_Inferred.md` |
| **System** | MSVC STL `std::_Sort` (stride-16 random-access) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `batch_decompile` callees + caller `FUN_00930360`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf-ish **introsort driver** (partition + recurse + insertion/heap finishers) for contiguous **16-byte** elements. Matches classic MSVC Dinkumware `std::_Sort(_RanIt, _RanIt, _Diff, _Pr)`:

```text
StdSort_RanItStride16_Inferred(first, last, ideal, pred)
  count = (last-first)/16
  if count ≤ 32: InsertionSort if count>1; return
  if ideal ≤ 0:  MakeHeap? + SortHeap; return
  Partition → recurse smaller; iterate larger with ideal *= ¾
```

Sole external consumer in this image: `FUN_00930360` (sort-target-list by view-angle score) seeds `ideal = count` and pred `LAB_0092cdd0` (float less-than on record `+4`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (do-loop; thresholds; partition; recurse) |
| Full body | `disassemble_function` `00409bd0`–`00409cb9` + `read_memory` prologue/epilog |
| ABI | plain `RET` (`C3`); caller `ADD ESP,0x10` @ `00930608` |
| Stride | `SAR …,4` / `& 0xfffffff0` |
| Callees | `00409f90`, `0040a410`, `0040a820`, `0040a380`, self |
| Callers | `FUN_00930360` @ `009305fc`; self ×2 |
| Pred sample | `read_memory` @ `0092cdd0` — COMISS float@+4 |

---

## 3. Signature (sealed)

```c
// __cdecl; plain RET; void
void __cdecl StdSort_RanItStride16_Inferred(
    Elem16 *first,
    Elem16 *last,
    int ideal,
    bool (__cdecl *pred)(const Elem16 *, const Elem16 *));
```

| Formal | Source | Conf |
|---|---|---|
| first | stack → EBX | **Confirmed** |
| last | stack → EDI | **Confirmed** |
| ideal | stack → ESI | **Confirmed** |
| pred | stack pushed to helpers | **Confirmed** |
| cleanup | `POP*` + `ADD ESP,8` + `RET` | **Confirmed** |
| convention | cdecl (caller cleans 16) | **Confirmed** |
| thiscall / ECX=this | **No** — ECX only temp for partition out LEA | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| count = (last-first)>>4 | `SUB`+`SAR 4` | **Confirmed** |
| count ≤ 32 → insertion if >1 | CMP 0x20 / CALL `0040a410` | **Confirmed** |
| ideal ≤ 0 → heap path | TEST ESI / CALL `0040a820`+`0040a380` | **Confirmed** |
| else partition pair-out | CALL `00409f90` | **Confirmed** |
| ideal = ¾ prior | CDQ/SAR/ADD | **Confirmed** |
| recurse smaller; loop larger | two self CALLs + tail loop | **Confirmed** |
| Decompile ≡ raw CF | live re-verify | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (STL sort driver) |
| External callers | **1** (`FUN_00930360`) |
| Self xrefs | 2 recurse |
| Site role | Sort 16-byte score records before rewriting TFID list |
| Callees | partition / insertion / make_heap / sort_heap / self |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| MSVC `_Sort` control shape (32 / heap / ¾ depth) | **Yes** |
| Stride 16 sealed | **Yes** |
| cdecl 4-arg plain RET | **Yes** |
| RTTI / export demangle | **No** |
| PollBoundActions strings / direct call | **No** |

**Decision:** promote **`StdSort_RanItStride16_Inferred`**. Retire PollBoundActions `Named_CalleeOf_*` scaffold. Keep `_Inferred`.

---

## 7. Gaps

- Nested helpers not dual-owned in MEGA-043.
- Element field English beyond call-site float@+4 pred.
- Runtime / bit-exact / differential.
- Possible other callers via non-xref mechanisms: none found in Ghidra xrefs.

---

## 8. Verdict

Fidelity path seals CF/ABI/stride/algorithm family with residual product English + undualed helpers → **accept-with-gaps**.
