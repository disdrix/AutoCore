# Dual A/B report — MEGA-064 OWN-ONLY (`0x00401c50`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-064**  
**Scope:** VA `0x00401c50` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + `search_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-064**.  
**Work item:** MEGA residual dual seal — string-key insert-or-find isnil2D nested under Mission null-dialog path.  
**Hint:** Mission_Attempting_to_open_null_dialog nested (host evidence only).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00401c50` StdMap_StringKey_InsertOrFind_Via401db0_Inferred | **accept-with-gaps** — CF/ABI RET4 / isnil2D / string key / pred dual / insert worker residual; product map open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): Mission product name / twin-merge `004309c0` / isnil29-31 / freelist-CNDHash / thiscall-ECX-map / always-insert / stream `operator<<` claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00401c50` — sealed facts

1. **Body:** `0x00401c50`–`0x00401d26` inclusive (**215 B** / `0xD7`); pad `CC` from `0x00401d27`.
2. **ABI:** **stack** = map*; **EAX** = `const basic_string*` key; **EBX** = out `{it*, inserted}`; **EAX** returns EBX; **`RET 4`** ×3 exits.
3. **Semantics:** MSVC-style **unique insert-or-find** (string key):
   - Lower-bound walk on **isnil@+0x2d**; go left iff `key < node.key` (IAT `operator<` @ `0x009c62e8` → `0x006eadd0`).
   - If goLeft: leftmost → insert addLeft=1; else dualed pred `StdTree_IteratorDecrement` (`0x004313d0`, EDX=`node**`).
   - Equal: out.it=where, inserted=0 (**no** mapped-value rewrite).
   - Else insert via undualed `FUN_00401db0` (ECX=where, EDI=map): inserted=1.
4. **Node:** L/P/R @ +0/+4/+8; key string @ **+0x0C**; color @ +0x2C; isnil @ **+0x2D**.
5. **Caller (1):** `FUN_00980160` @ `0x009801dd` — builds string key; map subobject @ host **+0x0C**; `LEA EBX,out` / `LEA EAX,key` / `PUSH map`.
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Callees:** IAT string `<`; `FUN_00401db0` (undualed); `StdTree_IteratorDecrement` `0x004313d0` (dualed).
8. **Twin:** dualed `StdMap_StringKey_InsertOrFind` `0x004309c0` (insert `0x00430b60`) — same CF/ABI/family; **do not merge**.
9. **Name:** `StdMap_StringKey_InsertOrFind_Via401db0_Inferred` (Ghidra `FUN_00401c50`). Product map open → `_Inferred`. Reject Named_CalleeOf Mission scaffold.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product / English key-value type for host+0x0C map (Mission path only).  
- Dual of insert worker `FUN_00401db0` / buynode `FUN_00401f40`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401c50_FUN_00401c50.md` |
| Annotated | `docs/reconstruction/raw/aa_00401c50_FUN_00401c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_StringKey_InsertOrFind_Via401db0_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401c50.cpp` |
| Function | `docs/reconstruction/functions/aa_00401c50_FUN_00401c50.md` |
| Function named | `docs/reconstruction/functions/aa_00401c50_StdMap_StringKey_InsertOrFind_Via401db0_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00980160  (Mission-related string parse / map upsert host)
  ├─ find(")") / substr
  ├─ FUN_00401d30 / FUN_00402040  (string pair build; residual)
  └─ FUN_00401c50  StdMap_StringKey_InsertOrFind_Via401db0_Inferred  [OWN MEGA-064]
        ├─ IAT operator< basic_string  [0x009c62e8]
        ├─ FUN_004313d0  StdTree_IteratorDecrement  [dualed W22-O]
        └─ FUN_00401db0  insert+rebalance string-key isnil2D  [residual]

Twin monomorph (not OWN):
FUN_004309c0  StdMap_StringKey_InsertOrFind  [dualed W21-P]
  └─ FUN_00430b60  insert worker  (different monomorph)

Ancestor string (host plate only):
  "Attempting to open null dialog %i." @ 0x00a84654
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00401c50-mega-064-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00401c50` | Port as **unique insert-or-find** for **string-keyed** isnil@**+0x2d** map. **Stack map + EAX key + EBX out; RET 4**. Equal key → inserted=false, no value rewrite. |
| Pair with | dualed pred `004313d0`; residual insert `00401db0`; monomorph twin `004309c0` (do not merge). |
| Do not | Treat Named_CalleeOf Mission plate as product method; merge with isnil29/31 insert-or-find families; claim thiscall ECX=map. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable  
- retire any remaining Named_CalleeOf inventory pointers to this VA
