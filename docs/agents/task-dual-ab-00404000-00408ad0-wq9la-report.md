# Dual A/B report — WQ9L-A OWN-ONLY (`0x00404000`, `0x00408ad0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9L-A**  
**Scope:** VAs `0x00404000`, `0x00408ad0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WQ-009 depth-9 residual dual seal — erase-range isnil131 free parents' callees: **iterator++ isnil131** + **erase+rebalance isnil131 DestroyStr0C**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00404000` StdTree_IteratorIncrement_Isnil131 | **accept** — CF/ABI/plain-RET/isnil@+0x131/EDX-it/6 call sites sealed |
| `aa_00408ad0` StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/isnil131/string@+0x0c/throw/size-- sealed; product English + full two-child plate open |

Path A (fidelity): `00404000` **accept**; `00408ad0` **accept-with-gaps**.  
Path B (adversarial): predecessor / isnil31-merge / ECX-thiscall / freelist / range-body / noreturn-on-delete / no-string-dtor claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00404000` — sealed facts

1. **Body:** `0x00404000`–`0x00404057` inclusive (**88 B** / `0x58`); pad `CC` from `0x00404058`.
2. **ABI:** **EDX** = `node**` (in/out `*it`); ECX unused at entry; void; plain **`RET`** (`C3` ×2).
3. **Semantics:** classic in-order **successor**:
   - if right child real → leftmost of right;
   - else climb parents while current is right child.
   - Nil-at-current = no-op.
4. **isnil** byte at node **`+0x131`**; links left@0 parent@4 right@8.
5. **Callees:** none (leaf).
6. **Callers / xrefs:** **6** UNCONDITIONAL_CALL:
   - `FUN_00407b70` @ `0x00407bc6` (erase-range advance)
   - `FUN_00408ad0` @ `0x00408b37` (OWN peer erase successor capture)
   - `FUN_00957820` @ `0x00957928` / `0x00957a9e` / `0x00957c34` / `0x00957d9e`
7. **Name:** `StdTree_IteratorIncrement_Isnil131` (Ghidra `FUN_00404000`). Algorithm sealed → no `_Inferred`.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English host map type (shared helper).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00404000_StdTree_IteratorIncrement_Isnil131.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00404000_StdTree_IteratorIncrement_Isnil131.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00404000_FUN_00404000.md` |
| Annotated | `docs/reconstruction/raw/aa_00404000_FUN_00404000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil131.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00404000.cpp` |
| Function | `docs/reconstruction/functions/aa_00404000_FUN_00404000.md` |
| Function named | `docs/reconstruction/functions/aa_00404000_StdTree_IteratorIncrement_Isnil131.md` |

---

## VA `0x00408ad0` — sealed facts

1. **Body:** `0x00408ad0`–`0x00408e1d` inclusive (**846 B** / `0x34E`); pad `CC` from `0x00408e1e`.
2. **ABI:** three stack args (`map*`, `outIt**`, `node*`); void; **`RET 0x0C`** (`C2 0C 00`).
3. **Semantics:** MSVC-style **single-node erase + RB rebalance**:
   - isnil @ **+0x131**, color @ **+0x130**, string value @ **+0x0c**
   - throw on nil iterator (`"invalid map/set<T> iterator"` @ `0x00a152f0` / ThrowInfo `DAT_00acc34c` via `FUN_00401bc0`)
   - capture successor via OWN `FUN_00404000`
   - splice unlink (incl. **two-child successor-swap** @ `0x00408be0` — decompiler "unreachable" is **false**)
   - fix head leftmost/rightmost via min `FUN_00404160` / max `FUN_004043c0`
   - if erased black → recolor/rotate (`FUN_00403cb0` L / `FUN_00403d00` R)
   - `~basic_string(node+0xc)`; `operator_delete`; size--; `*outIt=succ`
4. **Caller (1):** `FUN_00407b70` @ `0x00407bd2` only.
5. **Callees:** `FUN_00404000`, `FUN_00404160`, `FUN_004043c0`, `FUN_00403cb0`, `FUN_00403d00`, `FUN_00401bc0`, `~basic_string`, `operator_delete`, `_CxxThrowException`, `basic_string` ctor.
6. **Name:** `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` (Ghidra `FUN_00408ad0`). Product map open → `_Inferred`.
7. **Decompile caveats sealed:** false noreturn on delete; false unreachable two-child blocks; `param_3[0x4c]` = color@+0x130.

### Gaps

- Product map/key English.  
- Dual residual of min/max/rotate isnil131 peers.  
- Full two-child plate fidelity vs simplified clean.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00408ad0_StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00408ad0_StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00408ad0_FUN_00408ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_00408ad0_FUN_00408ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00408ad0.cpp` |
| Function | `docs/reconstruction/functions/aa_00408ad0_FUN_00408ad0.md` |
| Function named | `docs/reconstruction/functions/aa_00408ad0_StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00407b70  StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred  [dualed parent]
  ├─ full range: FUN_00409920 free-subtree isnil131 DestroyStr0C
  └─ partial loop:
        FUN_00404000  StdTree_IteratorIncrement_Isnil131  [OWN WQ9L-A]
        FUN_00408ad0  StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred  [OWN WQ9L-A]
          ├─ FUN_00404000  succ
          ├─ FUN_00404160  min isnil131  [residual]
          ├─ FUN_004043c0  max isnil131  [residual]
          ├─ FUN_00403cb0  Lrotate isnil131  [residual]
          ├─ FUN_00403d00  Rrotate isnil131  [residual]
          ├─ FUN_00401bc0  Std_OutOfRange_CtorFromString  [dualed WQ9L-B]
          ├─ ~basic_string @ node+0x0c
          └─ operator_delete

Family peers (do not merge):
  isnil31 erase  00408ed0  (no string dtor)
  isnil2d StringKey erase 004094c0
  isnil29 erase  004cb740
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00404000-00408ad0-wq9la-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00404000` | Port as **tree iterator++** for isnil@**+0x131** nodes. **EDX=`node**`**, plain **RET**. No container `this`. Keep distinct from isnil31/19/29/49 twins. |
| `00408ad0` | Port as **single-node erase+rebalance** for isnil@**+0x131** with **string@+0x0c** destroy. **3 stack args, RET 0x0C**. Preserve size--, *outIt, throw plate, and full two-child splice. Do **not** merge with isnil31 erase (no string dtor) or StringKey isnil2d. |
| Pair with | dualed erase-range parent `00407b70`; dualed free-subtree `00409920`; OWN peer succ; residual min/max/rotates; dualed out_of_range ctor `00401bc0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY` / coverage ledger entries
- progress / WORK_QUEUE residual clear for WQ9L-A
