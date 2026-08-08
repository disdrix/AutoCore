# Dual A/B report — R11-004 OWN-ONLY (`0x005738d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-004**  
**Scope:** VA `0x005738d0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_function_signature`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R11 residual dual partition — inventory-transfer residual under parent `0x00573700` (StdTree_EraseRange_Val12_InventoryGrid).  
**Hint:** map-shell dtor / bare tidy free-head.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005738d0` StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred | **accept-with-gaps** — CF/ABI/bare-RET/45 B/peer-clone/InventoryGrid shell ownership sealed; product demangle + unwind class English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): complete-dtor / free-this / partial-erase / SEH-frame / same-as-`0040d6d0` claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005738d0` — sealed facts

1. **Body:** `0x005738d0`–`0x005738fc` inclusive (**45 B** / `0x2D`); pad `CC` before next unit.
2. **ABI:** **ECX** = map shell (`head@+4`, `size@+8`); bare **`RET`** (`C3`); void. No stack args. No SEH in body.
3. **Semantics:** MSVC `_Tree` **tidy free-head** (bare):
   - Full erase `[begin,end)=[head->left, head)` via dualed `StdTree_EraseRange_Val12_InventoryGrid_Inferred` `0x00573700`.
   - `operator_delete(head)` cdecl + `ADD ESP,4`.
   - Null `head` and `size` (decomp drops — bytes restore).
4. **Callees:** `FUN_00573700` (dualed MEGA-120); `operator_delete` @ `0x00489822`.
5. **Callers (3 UNCONDITIONAL_CALL):** SEH unwind stubs only:
   - `Unwind@009a4f37` — `MOV ECX,[EBP-14]; ADD ECX,0x5c; JMP 005738d0`
   - `Unwind@009a4f57` — `MOV ECX,[EBP-10]; ADD ECX,0x5c; JMP 005738d0`
   - `Unwind@009a4f91` — third site
6. **Peer:** dualed `StdTree_Tidy_FreeHead_Bare_Val12` @ `0x0040d6d0` — **byte-identical** 45 B skeleton; only CALL displacements differ (erase=`00573700`).
7. **Name:** `StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred` (Ghidra `FUN_005738d0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF** for erase+delete; **bytes** seal null epilogue + bare RET.

### Gaps

- Product/MSVC demangle for map `T` / key English.  
- Enclosing class English for each unwind frame.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005738d0_StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005738d0_StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005738d0_FUN_005738d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005738d0_FUN_005738d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005738d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005738d0_FUN_005738d0.md` |
| Function named | `docs/reconstruction/functions/aa_005738d0_StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
InventoryGrid_ScalarDeletingDtor  0x00573910  [dualed]
  └─ FUN_005725a0  InventoryGrid complete dtor  [residual]
       ├─ FUN_00570f70  nested CS-host dtor path
       ├─ operator_delete[] cells @ +0x28
       ├─ FUN_00573700  StdTree_EraseRange_Val12_InventoryGrid  [dualed MEGA-120]
       │     (inlined tidy order — does NOT call 005738d0)
       └─ operator_delete(head @ +0x60)

FUN_005738d0  StdTree_Tidy_FreeHead_Bare_Val12_InventoryGrid  [OWN R11-004]
  └─ FUN_00573700 + operator_delete(head) + null head/size
       used as SEH unwind target (ADD ECX,0x5c → JMP)

Peer clone (not this VA):
  StdTree_Tidy_FreeHead_Bare_Val12  0x0040d6d0  [dualed W33-A]
    erase=0040d700
  StdTree_Tidy_FreeHead_Val12       0x0040d7c0  [dualed W32-B; SEH]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005738d0-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005738d0` | Port as **MSVC bare tree tidy free-head** for Val12 maps. **ECX=map shell** (InventoryGrid at object `+0x5c`), **not** grid `this`. Bare **RET**. |
| Order | Full erase via `00573700` → free head → null head+size. **Do not free shell**. |
| Pair with | dualed erase `00573700`; peer bare tidy `0040d6d0` (do not merge instances); residual complete dtor `005725a0` may inline same order. |
| Decomp caution | `operator_delete` false noreturn — restore null epilogue from bytes. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x005738d0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + disassemble_function + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; scaffold twin retained.  
- Odd behavior preserved: decomp drops null epilogue; assembly is authority.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
