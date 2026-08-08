# Dual A/B report — MEGA-041 OWN-ONLY (`0x00403c60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-041**  
**Scope:** VA `0x00403c60` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-041 residual dual seal — QuickBar_ActivateSlot nested seed; body is **isnil131 string-key lower_bound**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00403c60` StdTree_LowerBound_StringKey_Isnil131_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil131/string-key/3 call sites sealed; product map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): upper-bound / exact-find / thiscall-ECX / isnil31-merge / QuickBar-product / plain-RET claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00403c60` — sealed facts

1. **Body:** `0x00403c60`–`0x00403ca6` inclusive (**71 B** / `0x47`); pad `CC` before `FUN_00403cb0` @ `0x00403cb0`.
2. **ABI:** **EAX** = map (`_Myhead` at map+4); stack `const std::string*`; **EAX** = node*; **`RET 4`**.
3. **Semantics:** classic MSVC **lower_bound**:
   - `cand = head` (end); `cur = head->parent` (root).
   - while `!cur->isnil(+0x131)`: if `operator<(cur->key(+0xC), key)` → right; else cand=cur, left.
   - return cand.
4. **Callees:** string `operator<` via IAT `[0x009c62e8]` → `0x006eadd0` (cdecl `ADD ESP,8`).
5. **Callers (3 UNCONDITIONAL_CALL):**
   - `FUN_0093bd10` @ `0x0093bdfa` — slash-command dispatch (`LEA EAX,[EBX+4]`).
   - `FUN_00957820` @ `0x0095798a` / `0x00957c7b` — slash help `[lb, ub]` with twin upper_bound `FUN_00403d60`.
6. **Xrefs:** 3 UNCONDITIONAL_CALL.
7. **Name:** `StdTree_LowerBound_StringKey_Isnil131_Inferred` (Ghidra `FUN_00403c60`). Product host type open → `_Inferred`. Retired `Named_CalleeOf_*QuickBar*` scaffold.
8. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory` + call-site context.
9. **Family:** dualed `StdTree_IteratorIncrement_Isnil131` `0x00404000`; erase/free isnil131 peers; twin upper_bound `0x00403d60` residual.

### Gaps

- Product map/key English for isnil131 string host type (slash-cmd usage only).  
- Twin upper_bound `00403d60` residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00403c60_StdTree_LowerBound_StringKey_Isnil131_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00403c60_StdTree_LowerBound_StringKey_Isnil131_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00403c60_FUN_00403c60.md` |
| Annotated | `docs/reconstruction/raw/aa_00403c60_FUN_00403c60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_LowerBound_StringKey_Isnil131_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00403c60.cpp` |
| Function | `docs/reconstruction/functions/aa_00403c60_FUN_00403c60.md` |
| Function named | `docs/reconstruction/functions/aa_00403c60_StdTree_LowerBound_StringKey_Isnil131_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0093bd10  slash-command dispatch  [residual]
  └─ FUN_00403c60  StdTree_LowerBound_StringKey_Isnil131_Inferred  [OWN MEGA-041]
       compare node.key vs token; handler @ node+0x12C; level @ +0x28

FUN_00957820  slash help / list  [residual]
  ├─ FUN_00403d60  upper_bound string isnil131  [residual]
  ├─ FUN_00403c60  lower_bound  [OWN MEGA-041]
  └─ FUN_00404000  StdTree_IteratorIncrement_Isnil131  [dualed WQ9L-A]

isnil131 family (shared node layout):
  StdTree_IteratorIncrement_Isnil131              0x00404000
  StdTree_EraseAndRebalance_Isnil131_*            0x00408ad0
  StdMap_EraseRange_Isnil131_DestroyStr0C_*       0x00407b70
  StdTree_FreeSubtree_Isnil131_DestroyStr0C_*     0x00409920
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00403c60-mega-041-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00403c60` | Port as **string-key lower_bound** for isnil@**+0x131** nodes. **EAX=map**, stack=key*, **RET 4**. Not thiscall. Keep distinct from upper_bound `00403d60`, char-key `00402210`, isnil31 peers. |
| Pair with | dualed iterator++ isnil131 `00404000`; residual upper_bound `00403d60`; slash callers `0093bd10` / `00957820`. |
| Not | QuickBar_ActivateSlot product logic — residual seed only. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER` / progress / inventory status → dual-sealed
- system map `skills-abilities.md` row if desired
- retire scaffold name from any residual queues

**Terminal:** false.
