# Dual A/B report — WQ9J-H OWN-ONLY (`0x00409880`, `0x004098d0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9J-H**  
**Scope:** VAs `0x00409880`, `0x004098d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-H**.  
**Work item:** WQ-009 depth-7 residual dual seal (00409xxx residual neighborhood — sealed as **Val24/isnil29 node construct twins**, not freelist).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00409880` StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred | **accept-with-gaps** — EAX-this usercall / RET 0xC / Val24 isnil29 leaf / 1 caller sealed; product open |
| `aa_004098d0` StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred | **accept-with-gaps** — thiscall / RET 0x14 / same store map / dualed buynode caller sealed; product open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): freelist/CNDHash, buynode-merge, Val12/isnil21 merge, same-symbol twin merge, and chain-of-caller plates **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00409880` — sealed facts

1. **Body:** `0x00409880`–`0x004098c4` inclusive / exclusive end `0x004098c5` (**69 B** / `0x45`).
2. **ABI:** **__usercall** — node **EAX**, value* **ECX**, left **EDX**, parent/right/color stack; void; **`RET 0xC`**.
3. **Semantics:** MSVC-style **tree node construct** (no alloc):
   - left/parent/right @ +0/+4/+8.
   - **6 dwords Val24** @ +0x10..+0x27.
   - **color@+0x28** from arg; **isnil=0** @ +0x29.
   - **+0x0C** untouched.
4. **Classification:** leaf (no callees).
5. **Xrefs (1 UNCONDITIONAL_CALL):** `FUN_00404180` @ `0x004041d6` (SEH `operator_new(0x30)` then this ctor; insert grandparent `FUN_004069f0`).
6. **Twin:** thiscall `FUN_004098d0` — **do not merge** (ABI only differs).
7. **Name:** `StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred` (Ghidra `FUN_00409880`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0xC + register ABI sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product / English map for Val24 value_type.  
- Parent buynode `FUN_00404180` / insert `FUN_004069f0` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00409880_FUN_00409880.md` |
| Annotated | `docs/reconstruction/raw/aa_00409880_FUN_00409880.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409880.cpp` |
| Function | `docs/reconstruction/functions/aa_00409880_FUN_00409880.md` |
| Function named | `docs/reconstruction/functions/aa_00409880_StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred.md` |

---

## VA `0x004098d0` — sealed facts

1. **Body:** `0x004098d0`–`0x0040991e` inclusive / exclusive end `0x0040991f` (**79 B** / `0x4F`).
2. **ABI:** **`__thiscall`**; ECX = node; stack left, parent, right, value*, color; void; **`RET 0x14`**.
3. **Semantics:** MSVC-style **tree node construct** (no alloc) — **same store map** as `00409880`:
   - links + Val24 + color@+0x28 + isnil0@+0x29.
4. **Classification:** leaf.
5. **Xrefs (1 UNCONDITIONAL_CALL):** `StdTree_Buynode_Val24_Isnil29_Inferred` (`FUN_00407e30`) @ `0x00407e88` (dualed WQ9F-B; insert `00406c40`).
6. **Twin:** EAX-this `FUN_00409880` — **do not merge**. Store peer inlined in `FUN_005a2de0` — **do not merge**.
7. **Name:** `StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred` (Ghidra `FUN_004098d0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 0x14 sealed via `read_memory` / disasm.

### Gaps

- Product / English map for Val24 value_type.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004098d0_FUN_004098d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004098d0_FUN_004098d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004098d0.cpp` |
| Function | `docs/reconstruction/functions/aa_004098d0_FUN_004098d0.md` |
| Function named | `docs/reconstruction/functions/aa_004098d0_StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004069f0  (insert/rebalance; "map/set<T> too long"; isnil@+0x28 color walks)
  └─ FUN_00404180  (SEH buynode operator_new(0x30))   [undualed residual]
        └─ StdTree_NodeCtor_Val24_Isnil29_EaxThis_Inferred (0x00409880)  [OWN WQ9J-H]

StdTree_InsertAndRebalance_Isnil29_Inferred (0x00406c40)   [dualed WQ9E-G]
  └─ StdTree_Buynode_Val24_Isnil29_Inferred (0x00407e30)   [dualed WQ9F-B]
        └─ StdTree_NodeCtor_Val24_Isnil29_Thiscall_Inferred (0x004098d0)  [OWN WQ9J-H]

Twin pair (same stores; different ABI):
  0x00409880  EAX-this  RET 0xC
  0x004098d0  thiscall  RET 0x14

Contrast:
  FUN_005a2de0  no-SEH buynode with inlined same stores (do not merge)
  Empty head / Val16 isnil21 buynodes (other waves)
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00409880` | Port as **in-place node ctor** Val24/isnil29 with **EAX=this** / ECX=value* / EDX=left / 3 stack args; **RET 0xC**. Pair with buynode `00404180` when dualed. **Not** freelist; **not** allocator. |
| `004098d0` | Port as **thiscall node ctor** same layout; **RET 0x14**. Already wired under dualed `StdTree_Buynode_Val24_Isnil29_Inferred`. |
| Pair with | Buynode `00407e30` / insert `00406c40`; undualed twin buy `00404180` / insert `004069f0`. |
| Naming caution | Neighborhood residual near 00409xxx is **co-location** — these two VAs are **node construct twins**, not freelist or UI POD. |

---

## Process

- OWN VAs only (`0x00409880`, `0x004098d0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decompiler incomplete `__fastcall` on EAX-this unit; +0x0C gap; hard isnil=0 independent of color.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems residual table (util/container / tree helpers)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00409880-004098d0-wq9jh-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
