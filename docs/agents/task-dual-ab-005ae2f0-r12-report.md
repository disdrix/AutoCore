# Dual A/B report — R12-034 OWN-ONLY (`0x005ae2f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-034**  
**Scope:** VA `0x005ae2f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including buynode `005ae1c0`, parent shell `005aec50`, peer inserts, rotate leaves dualed elsewhere).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-034**.  
**System:** skills-abilities.  
**Parent dual:** `0x005a27f0` StdTree_Rrotate_Isnil21_Inferred (this VA is a **caller residual** of that leaf).  
**Dual start:** 2646.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005ae2f0` StdTree_InsertAndRebalance_Val20_Isnil21_Inferred | **accept-with-gaps** — always-insert + RB rebalance; Val20/node 0x24; isnil@+0x21; RET 0x10; size≥`0xCCCCCCB` throw; sole caller `005aec50` |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Rrotate-merge / Val12-merge / Val16-merge / MissionStopLimit-only / wrong RET / wrong max / insert-or-find-in-body all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005ae2f0` — sealed facts

1. **Body:** `0x005ae2f0`–`0x005ae4da` inclusive (**491 B** / `0x1EB`); pad 5×`CC`; next `FUN_005ae4e0` @ `0x005ae4e0`.
2. **ABI:** **`__thiscall`** ECX=map; stack `(out**, addLeft, where*, value*)`; **`ret 0x10`** (`C2 10 00`).
3. **Semantics:** MSVC-style **`_Tree` always-insert + red-black rebalance** for **Val20 / isnil@+0x21**:
   - If `size >= 0xCCCCCCB`: throw `"map/set<T> too long"`.
   - `n = FUN_005ae1c0(head, where, head, value, color=0)` — node **0x24**.
   - `size++`; link first | left | right (+ leftmost/rightmost on head).
   - While parent color@+0x20 red: recolor uncle OR Lrotate `0050e9f0` / Rrotate `005a27f0` / **inline L** (isnil@+0x21).
   - Root black; `*out = n`.
4. **Layout:** left@+0, parent@+4, right@+8, Val20 5×u32 @+0x0C, color@**+0x20**, isnil@**+0x21**; tree+4=head, tree+8=size.
5. **Callees:** `FUN_005ae1c0`, `FUN_0050e9f0`, `FUN_005a27f0`×2, `_CxxThrowException`, `basic_string` / `exception`.
6. **Callers (1):** `FUN_005aec50` only.
7. **Xrefs:** 1 UNCONDITIONAL_CALL @ `0x005aecaf`.
8. **Name:** `StdTree_InsertAndRebalance_Val20_Isnil21_Inferred` (Ghidra `FUN_005ae2f0`). Product demangle open → `_Inferred`. Reject MissionStopLimit chain alias as product name.
9. **Peers (CF reference only):** Val16 insert `00407200` (same rotates; different max/buynode/node); Val12 insert `005ae4e0` (adjacent; different family).
10. **Decompile ≡ raw CF**; size imm `0xCCCCCCB` + RET sealed via `read_memory`; thiscall via `mov edi,ecx`.

### Gaps

- Product / MSVC demangle for map value_type (5-dword payload; caller keys first two ints).  
- Buynode null OOM path (unchecked in decomp).  
- Full dual of residual buynode `005ae1c0` / parent shell `005aec50` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae2f0_FUN_005ae2f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ae2f0.cpp` |
| Function | `docs/reconstruction/functions/aa_005ae2f0_FUN_005ae2f0.md` |
| Function named | `docs/reconstruction/functions/aa_005ae2f0_StdTree_InsertAndRebalance_Val20_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_005aec50  insert-or-find Val20 (composite int key)   [residual]
  └─ StdTree_InsertAndRebalance_Val20_Isnil21_Inferred (0x005ae2f0)  [OWN R12-034]
       ├─ FUN_005ae1c0  buynode node 0x24 / Val20              [residual]
       ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)         [R10-030 dualed]
       └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)         [R11-007 dualed; partition parent]

Peers (do not merge):
  00407200 StdTree_InsertAndRebalance_Isnil21_Inferred  (Val16 / node 0x28; same rotates)
  005ae4e0 StdTree_InsertAndRebalance_Val12             (node 0x1c; different rotates)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005ae2f0-r12-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005ae2f0` | Port as **generic StdTree always-insert + rebalance** for **Val20 / isnil@+0x21 / node 0x24**. **thiscall** ECX=map; stack `(out**, addLeft, where*, value*)`; **ret 0x10**. Size gate **`size >= 0xCCCCCCB`** → `"map/set<T> too long"`. Buynode `005ae1c0`; rotates pair with dualed isnil21 L/R. Parent owns uniqueness (`005aec50`). |
| Pair with | Buynode Val20; L/R isnil21 rotates; parent insert-or-find; peer Val16/Val12 inserts for CF reference only. |
| Naming caution | **Not** skill/MissionStopLimit-specific. **Not** Rrotate (`005a27f0`). **Not** Val12 insert (`005ae4e0`) despite adjacent VA + shared SEH shape. **Not** Val16 insert (`00407200`) despite shared rotates. |

---

## Parent merge handoff (not done here)

Parent dual R11-007 listed this rotate-caller as residual gap — now dualed R12-034. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).

---

## Notes

- No Launcher. No parent ledger / partition map / COVERAGE_LEDGER edits.  
- Did not write artifacts for non-owned helpers (`005ae1c0`, `005aec50`, rotate leaves already dualed).  
- Dual A (fidelity) + B (adversarial) both filed.  
- **Never Runtime Confirmed.**
