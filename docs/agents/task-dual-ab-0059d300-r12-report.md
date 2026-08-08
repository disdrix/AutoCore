# Dual A/B report — R12-029 OWN-ONLY (`0x0059d300`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-029**  
**Scope:** VA `0x0059d300` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including peer no-dtor erase clones `00405650` / `004e3e70`, range parent `0059d620`, twin Lrotate re-dual).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-029**.  
**System:** skills-abilities  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0059d300` StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred | **accept-with-gaps** — erase CF/ABI/RET8/isnil21/DestroyStr14/size-- sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): no-dtor-clone merge / isnil29-31 merge / range-as-body / RET0xC / skill-only alias / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0059d300` — sealed facts

1. **Body:** `0x0059d300`–`0x0059d5d2` inclusive (**723 B** / `0x2D3`); pad `CC` after `C2 08 00`.
2. **ABI:** **`__thiscall`** ECX=map shell; stack `outIt**`, `node*`; **`ret 8`** (`C2 08 00`).
3. **Semantics:** MSVC-style **`_Tree` erase(const_iterator)** for **isnil@+0x21**:
   - Nil iterator → throw `"invalid map/set<T> iterator"` @ `0x00a152f0` / `DAT_00acc34c`.
   - Successor prep via `FUN_004e12c0` (iterator++ isnil21).
   - Unlink replacement; fix root / leftmost (`FUN_004cb2c0`) / rightmost (`FUN_00421a60`).
   - If erased black (color@+0x20 == 1): RB fixup with Lrotate `0050e9f0` / Rrotate `005a27f0`.
   - **DestroyStr14:** free `node+0x14` if non-null; zero `+0x14/+0x18/+0x1C`; `operator_delete(node)`.
   - size-- when size>0; write `*outIt`; ret 8.
4. **Layout:** left@+0, parent@+4, right@+8, color@**+0x20**, isnil@**+0x21**; node **0x28**; tree+4=head, head+4=root, size@tree+8.
5. **Callees:** `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `operator_delete`, STL throw chain (`basic_string` / `exception` / `_CxxThrowException`).
6. **Callers (1):** `FUN_0059d620` @ `0x0059d6bf` (erase-range shell; `MOV ECX,EDI`).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred` (Ghidra `FUN_0059d300`). Product demangle open → `_Inferred`. Differentiator **DestroyStr14** vs no-dtor isnil21 erase clones.
9. **Peers (CF family; do not merge):**
   - No-dtor isnil21 erase: `0x00405650` (R12-009), `0x004e3e70` (R12-013)
   - Lrotate isnil21: `0x0050e9f0` (dualed)
   - Rrotate isnil21: `0x005a27f0` (parent dual R11-007)
   - Insert twin isnil21: `0x00407200` / Val16 insert `0x004e37e0`
10. **Decompile ≡ raw CF** for throw/unlink/RB; RET + DestroyStr14 + size-- sealed via `read_memory` past false noreturn; caller thiscall sealed via assembly context.

### Gaps

- Product / MSVC demangle for map value_type / string field English.  
- Full two-child successor-swap mid-path (decomp unreachable warnings at `0x0059d41d`…).  
- Dual of range parent `FUN_0059d620` and residual succ/min/max.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0059d300_FUN_0059d300.md` |
| Annotated | `docs/reconstruction/raw/aa_0059d300_FUN_0059d300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0059d300.cpp` |
| Function | `docs/reconstruction/functions/aa_0059d300_FUN_0059d300.md` |
| Function named | `docs/reconstruction/functions/aa_0059d300_StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_0059d620  (erase-range isnil21 shell)  [residual]
  └─ FUN_0059d300  StdTree_EraseAndRebalance_Isnil21_DestroyStr14_Inferred  [OWN R12-029]
        ├─ FUN_004e12c0   iterator++ isnil21  [residual]
        ├─ FUN_004cb2c0   min  [residual]
        ├─ FUN_00421a60   max  [residual]
        ├─ FUN_0050e9f0   StdTree_Lrotate_Isnil21_Inferred  [dualed]
        └─ FUN_005a27f0   StdTree_Rrotate_Isnil21_Inferred  [parent R11-007]

Peer no-dtor isnil21 erase clones (do not merge):
  00405650 StdTree_EraseAndRebalance_Isnil21_Inferred  [R12-009]
  004e3e70 StdTree_EraseAndRebalance_Isnil21_Inferred  [R12-013]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0059d300-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0059d300` | Port as **shared StdTree erase + rebalance** for **isnil@+0x21 / color@+0x20 / node 0x28** with **DestroyStr14** value teardown. **thiscall** ECX=map; stack `outIt**`, `node*`; **ret 8**. Pair with Lrotate `0050e9f0` and Rrotate `005a27f0`. Do **not** merge with no-dtor isnil21 erase clones or isnil29/2d/31 erase. |
| Pair with | Rrotate isnil21 (parent); Lrotate isnil21; erase-range parent `0059d620` (not dualed here); succ/min/max isnil21 helpers. |
| Naming caution | **Not** skill-specific product symbol. **Not** bare no-dtor erase (`00405650`/`004e3e70`). **Not** range erase body. **Not** Runtime Confirmed. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 listed erase shells among callers of Rrotate `005a27f0` — this unit dualed R12-029 as the DestroyStr14 erase specialization under range parent `0059d620`. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + callers/xrefs + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Name suffix **`_Inferred`**; never Runtime Confirmed.  
- Terminal **false**.
