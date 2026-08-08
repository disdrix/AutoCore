# Dual A/B report — R10-020 OWN-ONLY (`0x00403d60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-020**  
**Scope:** VA `0x00403d60` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; parent ledgers; other VAs; `disassemble_bytes` primary; invent product names; wipe raw.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — parent dual `0x00403c60` lower_bound; body is **isnil131 string-key upper_bound**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00403d60` StdTree_UpperBound_StringKey_Isnil131_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil131/string-key/2 call sites sealed; product map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): lower-bound / exact-find / thiscall-ECX / isnil31-merge / same-as-twin / plain-RET claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00403d60` — sealed facts

1. **Body:** `0x00403d60`–`0x00403da6` inclusive (**71 B** / `0x47`); pad `CC` before next function.
2. **ABI:** **EAX** = map (`_Myhead` at map+4); stack `const std::string*`; **EAX** = node*; **`RET 4`**.
3. **Semantics:** classic MSVC **upper_bound**:
   - `cand = head` (end); `cur = head->parent` (root).
   - while `!cur->isnil(+0x131)`: if `operator<(key, cur->key(+0xC))` → cand=cur, left; else right.
   - return cand.
4. **Callees:** string `operator<` via IAT `[0x009c62e8]` → `0x006eadd0` (cdecl `ADD ESP,8`).
5. **Callers (2 UNCONDITIONAL_CALL):**
   - `FUN_00957820` @ `0x0095797a` / `0x00957c6b` — slash help `[lb, ub]` with twin lower_bound `FUN_00403c60`.
6. **Xrefs:** 2 UNCONDITIONAL_CALL (both same function region).
7. **Name:** `StdTree_UpperBound_StringKey_Isnil131_Inferred` (Ghidra `FUN_00403d60`). Product host type open → `_Inferred`.
8. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory` + call-site context.
9. **Family:** dualed twin lower_bound `0x00403c60`; dualed iterator++ isnil131 `0x00404000`; erase/free isnil131 peers.

### Gaps

- Product map/key English for isnil131 string host type (slash-cmd usage only).  
- Runtime / bit-exact / differential.  
- No slash-dispatch call site (unlike twin lower_bound's third site).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00403d60_StdTree_UpperBound_StringKey_Isnil131_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00403d60_StdTree_UpperBound_StringKey_Isnil131_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00403d60_FUN_00403d60.md` |
| Annotated | `docs/reconstruction/raw/aa_00403d60_FUN_00403d60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_UpperBound_StringKey_Isnil131_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00403d60.cpp` |
| Function | `docs/reconstruction/functions/aa_00403d60_FUN_00403d60.md` |
| Function named | `docs/reconstruction/functions/aa_00403d60_StdTree_UpperBound_StringKey_Isnil131_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00957820  slash help / list  [residual]
  ├─ FUN_00403d60  StdTree_UpperBound_StringKey_Isnil131_Inferred  [OWN R10-020]
  ├─ FUN_00403c60  StdTree_LowerBound_StringKey_Isnil131_Inferred  [dualed MEGA-041]
  └─ FUN_00404000  StdTree_IteratorIncrement_Isnil131  [dualed]

isnil131 family (shared node layout):
  StdTree_LowerBound_StringKey_Isnil131_Inferred   0x00403c60
  StdTree_UpperBound_StringKey_Isnil131_Inferred   0x00403d60  [this]
  StdTree_IteratorIncrement_Isnil131              0x00404000
  StdTree_EraseAndRebalance_Isnil131_*            0x00408ad0
  StdMap_EraseRange_Isnil131_DestroyStr0C_*       0x00407b70
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00403d60-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00403d60` | Port as **string-key upper_bound** for isnil@**+0x131** nodes. **EAX=map**, stack=key*, **RET 4**. Not thiscall. Keep distinct from lower_bound `00403c60`, char-key `00402210`, isnil31 peers. |
| Pair with | dualed lower_bound isnil131 `00403c60`; dualed iterator++ isnil131 `00404000`; slash help caller `00957820`. |
| Not | product skill/QuickBar logic — pure STL range end. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md`
- `COVERAGE_LEDGER` / progress / inventory status → dual-sealed
- system map `skills-abilities.md` row if desired
- mark residual queue R10-020 complete

**Terminal:** false.
