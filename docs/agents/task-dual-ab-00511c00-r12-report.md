# Dual A/B report — R12-015 OWN-ONLY (`0x00511c00`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-015**  
**Scope:** VA `0x00511c00` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including twin insert `00511950`, peer erases, parent rotate re-dual).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_function_callees` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-015**.  
**System (partition tag):** skills-abilities (score residual — unit itself is shared STL tree erase).  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (R11-007).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00511c00` StdTree_EraseAndRebalance_Isnil21_Inferred | **accept-with-gaps** — erase CF/ABI/RET8/isnil21/value-heap plate sealed; product residual; 0 inbound xrefs |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): insert-merge / isnil29-merge / RetC-merge / skill-only alias / noreturn-on-delete / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00511c00` — sealed facts

1. **Body:** `0x00511c00`–`0x00511ed3` exclusive (**723 B** / `0x2D3`); pad `CC`. Ghidra listed end `0x00511e9f` truncated by false noreturn on `operator_delete`.
2. **ABI:** **`__thiscall`** ECX=tree (`MOV EBX,ECX`); stack `Node** outIt`, `Node* node`; **`ret 8`** (`C2 08 00` @ `0x00511ed0`).
3. **Semantics:** MSVC-style **`_Tree` erase + RB rebalance** for **isnil@+0x21**:
   - SEH frame (`LAB_009a31f2` / FS:[0]).
   - Nil → `"invalid map/set<T> iterator"` @ `0x00a152f0` → `_CxxThrowException(..., DAT_00acc34c)`.
   - Successor prep via `FUN_004e12c0` (isnil21 iterator++).
   - Unlink + head extremity fix (min `FUN_004cb2c0`, max `FUN_00421a60`); two-child successor-swap path @ `0x00511d1d` **asm-live** (decomp wrongly "unreachable"); color exchange @+0x20.
   - If erased black → recolor + Lrot `FUN_0050e9f0` / Rrot `FUN_005a27f0`.
   - If `node[+0x14] != 0` → `operator_delete` value heap; zero `+0x14/+0x18/+0x1c`; `operator_delete(node)`; if size>0 then size--; `*outIt = succ`.
4. **Layout:** left@+0, parent@+4, right@+8; heap@**+0x14**; color@**+0x20**, isnil@**+0x21**; tree+4=head, head extremities, size@tree+8; node family **0x28**.
5. **Callees:** `FUN_004e12c0`, `FUN_004cb2c0`, `FUN_00421a60`, `FUN_0050e9f0`, `FUN_005a27f0`, `operator_delete`, throw path (`basic_string` / `exception` / `_CxxThrowException`).
6. **Callers:** **none** recovered (`get_function_callers` / `get_xrefs_to` empty).
7. **Xrefs:** 0.
8. **Name:** `StdTree_EraseAndRebalance_Isnil21_Inferred` (Ghidra `FUN_00511c00`). Product demangle open → `_Inferred`.
9. **Twins (CF):** Insert residual `00511950` (same family, not dualled here); peer thiscall RET8 erase isnil29 `004cb740`; parent rotates dualed isnil21.
10. **Decompile ≡ raw CF** for throw/unlink/rebalance; RET + isnil imm `0x21` + size-- sealed via `read_memory`; two-child plate sealed via `disassemble_function`.

### Gaps

- Product / MSVC demangle for map value_type / heap @+0x14.  
- Zero inbound xrefs (dead template vs dynamic call).  
- Two-child splice plate full line-by-line clean fidelity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00511c00_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00511c00_StdTree_EraseAndRebalance_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00511c00_FUN_00511c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00511c00_FUN_00511c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00511c00.cpp` |
| Function | `docs/reconstruction/functions/aa_00511c00_FUN_00511c00.md` |
| Function named | `docs/reconstruction/functions/aa_00511c00_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Parent dual R11-007:
  StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)
    ↑ called by OWN erase fixup

R10-030:
  StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)
    ↑ called by OWN erase fixup

OWN R12-015:
  StdTree_EraseAndRebalance_Isnil21_Inferred (0x00511c00)
    ├─ FUN_004e12c0   succ / iterator++ isnil21
    ├─ FUN_004cb2c0   min isnil21
    ├─ FUN_00421a60   max isnil21
    ├─ FUN_0050e9f0   Lrotate isnil21  [dualed]
    ├─ FUN_005a27f0   Rrotate isnil21  [dualed]
    └─ operator_delete (value heap @+0x14 + node)

Insert twin (same family; residual elsewhere):
  FUN_00511950  (R12-014; "map/set too long" insert path)

Peer erases (do not merge):
  004cb740  StdTree_EraseAndRebalance_Isnil29_Inferred  (thiscall RET8)
  00402850  StdTree_EraseAndRebalance_Isnil29_RetC_Inferred
  00408ed0  StdTree_EraseAndRebalance_Isnil31_Inferred
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00511c00-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00511c00` | Port as **shared StdTree erase + RB rebalance** for **isnil@+0x21 / color@+0x20 / node 0x28**. **thiscall** ECX=tree; stack `Node** outIt`, `Node* node`; **ret 8**. Free optional heap @+0x14 before node delete. Pair with L/R rotates `0050e9f0`/`005a27f0`, succ `004e12c0`, min `004cb2c0`, max `00421a60`. Do not merge with isnil29/31 erases or RetC stack family. Not skill product logic. |
| Pair with | dualed isnil21 L/R rotates; peer thiscall RET8 erase isnil29 for ABI shape; residual insert twin `00511950`. |
| Naming caution | **Not** insert (`00511950`). **Not** isnil29 erase (`004cb740`). **Not** skill-specific despite partition tag. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 listed this VA among rotate callers — now dualed R12-015 as erase consumer. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).

---

## Process

- OWN VA only (`0x00511c00`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs/callees. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name with `_Inferred`; machine ABI corrections (RET 8; epilogue past false noreturn; two-child plate live).  
- Odd behavior preserved: decomp unreachable two-child path is live; noreturn-on-delete truncation; 0 inbound xrefs.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
