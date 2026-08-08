# Dual A/B report — WQ9J-I OWN-ONLY (`0x00409920`, `0x00409970`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-I**  
**Scope:** VAs `0x00409920`, `0x00409970` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-I**.  
**Work item:** WQ-009 depth-7 residual dual seal — string-value **FreeSubtree** twins (isnil131 + isnil2d) sharing `FUN_00409b80`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409920` StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil131/left-walk + string destroy @+0x0c sealed; product residual |
| `aa_00409970` StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred | **accept-with-gaps** — CF twin; isnil2d sealed; shared string dtor sealed; product residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): bare-cdecl-only / no-destroy / isnil29-merge / isnil131↔isnil2d merge / free-sentinel / thiscall-ECX=node / decompiler-complete claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409920` — sealed facts

1. **Body:** `0x00409920`–`0x00409960` inclusive last RET byte (**65 B** / `0x41`); pad `CC` to twin.
2. **ABI:** ECX = tree_base (threaded; unused in body except recursive pass); stack `node*`; **void**; **`RET 4`** (`C2 04 00`).
3. **Semantics:** MSVC-style **free-subtree** for **isnil@+0x131**:
   - If isnil → return.
   - Loop: free right recursively (`self`, ECX=tree_base); `left = node.left@+0`; **`FUN_00409b80(node)`** (stdcall RET4 — `~basic_string` @ **+0x0c**); `operator_delete(node)` cdecl; `node = left`; until isnil.
4. **isnil / layout:** isnil@**+0x131**; left@+0; right@+8; parent unused here.
5. **Value destroy:** **yes** — shared residual `FUN_00409b80` (not full large-value dtor; string only).
6. **Callees:** self; `FUN_00409b80`; `operator_delete` (`0x00489822`).
7. **Callers (1 external):** undualed erase-range `FUN_00407b70` @ `0x00407b8f` (`MOV ECX,ESI`; push `head->parent`; free; head L/P/R self-link; size=0).
8. **Xrefs:** 2 (self + parent).
9. **Name:** `StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred` (Ghidra `FUN_00409920`). Product open → `_Inferred`.
10. **Decompile ≢ raw CF** — decompiler collapses left-walk + false noreturn; **bytes win**. `disassemble_function` also omits loop-tail; full hex from `read_memory` sealed.

### Gaps

- Product English for large node (string @+0x0c + POD through isnil@+0x131).  
- Residual undualed: value dtor `00409b80`, erase parent `00407b70`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409920_StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409920_StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409920_FUN_00409920.md` |
| Annotated | `docs/reconstruction/raw/aa_00409920_FUN_00409920.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409920.cpp` |
| Function | `docs/reconstruction/functions/aa_00409920_FUN_00409920.md` |
| Function named | `docs/reconstruction/functions/aa_00409920_StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred.md` |

---

## VA `0x00409970` — sealed facts

1. **Body:** `0x00409970`–`0x004099aa` inclusive last RET byte (**59 B** / `0x3B`); pad `CC` to node-ctor `0x004099b0`.
2. **ABI:** same as twin — ECX=tree_base; stack node*; **void**; **`RET 4`**.
3. **Semantics:** MSVC-style **free-subtree** for **isnil@+0x2d** with same left-walk + **`FUN_00409b80`** string destroy + delete.
4. **isnil / layout:** isnil@**+0x2d** (not 0x131); left@+0; right@+8; color likely +0x2c (inferred).
5. **Value destroy:** **yes** — **same** `FUN_00409b80` as isnil131 free.
6. **Callees:** self; `FUN_00409b80`; `operator_delete`.
7. **Callers (1 external):** undualed erase-range `FUN_00407f90` @ `0x00407fb0` (`MOV ECX,EDI`; push `head->parent`; free; head reset + size=0). Partial path uses isnil@+0x2d successor + residual `FUN_004094c0`.
8. **Xrefs:** 2 (self + parent).
9. **Name:** `StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred` (Ghidra `FUN_00409970`). Reject merge with isnil131 / isnil29 no-destroy.
10. **Decompile ≢ raw CF** — same decompiler collapse as twin; **bytes win**.

### Gaps

- Product English for compact string-value node.  
- Residual undualed: `00409b80`, erase parent `00407f90`, partial erase `004094c0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409970_StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409970_StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409970_FUN_00409970.md` |
| Annotated | `docs/reconstruction/raw/aa_00409970_FUN_00409970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409970.cpp` |
| Function | `docs/reconstruction/functions/aa_00409970_FUN_00409970.md` |
| Function named | `docs/reconstruction/functions/aa_00409970_StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00407b70  erase-range (isnil131 family)              [undualed residual]
  └─ FUN_00409920  FreeSubtree Isnil131 + DestroyStr0C   [OWN WQ9J-I]
        ├─ self (right)
        ├─ FUN_00409b80  ~basic_string @ node+0x0c       [residual]
        └─ operator_delete

FUN_00407f90  erase-range (isnil2d family)               [undualed residual]
  └─ FUN_00409970  FreeSubtree Isnil2d + DestroyStr0C    [OWN WQ9J-I]
        ├─ self (right)
        ├─ FUN_00409b80  (shared with 00409920)
        └─ operator_delete

Compare no-destroy peers:
  FUN_00406c00  StdTree_FreeSubtree_Isnil29_Inferred     [dualed WQ9G-G]
  FUN_0051bbc0  Map_FreeSubtree_Isnil29                  [dualed]
  FUN_0040d630  StdTree_FreeSubtree_Val12                [dualed W31-A]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409920-00409970-wq9ji-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409920` | Port as **free-subtree** for **isnil@+0x131** with **string destroy @+0x0c** before delete. **ECX**=tree_base, stack node*, **RET 4**. Pair with erase parent `00407b70` when dualed. Do **not** merge with isnil2d twin or no-destroy isnil29 frees. |
| `00409970` | Port as **free-subtree** for **isnil@+0x2d** with **same string dtor** `00409b80`. Same ABI. Pair with erase parent `00407f90`. Keep **distinct** from isnil131 twin. |
| Pair with | shared residual dtor `00409b80`; no-destroy peers `00406c00` / `0051bbc0` / `0040d630`; erase parents `00407b70` / `00407f90`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (container/STL residual — general StdTree free with string value, not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00409920`, `0x00409970`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names; null-contaminated scaffold `FUN_00409920.cpp` / `FUN_00409970.cpp` replaced.  
- Odd behavior preserved: decompiler left-walk collapse + false noreturn; `disassemble_function` incomplete loop-tail; only string @+0x0c destroyed (not whole large payload).  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
