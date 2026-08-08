# Dual A/B report — R13-031 OWN-ONLY (`0x00511b40`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-031**  
**Scope:** VA `0x00511b40` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including residual pred `005adff0`, residual caller `0050ba90`, residual buynode `005118b0`, peer erase `00511c00`, parent insert re-dual).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-031**.  
**System:** skills-abilities (partition assignment; unit role is generic MSVC map insert-or-find).  
**Parent dual:** `0x00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (R12-014).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00511b40` StdMap_InsertOrFind_IntKey_Isnil21_Inferred | **accept-with-gaps** — insert-or-find CF/ABI/RET8/isnil21/signed-int-key sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): always-insert-merge / isnil29-merge / PairKey-merge / unsigned-key / wrong RET / skill-product / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00511b40` — sealed facts

1. **Body:** `0x00511b40`–`0x00511bf8` inclusive (**185 B** / `0xB9`); pad `CC` before `FUN_00511c00` @ `0x00511c00`.
2. **ABI:** **`__thiscall`** ECX=map; stack `(InsertPair* out, Val* value)`; **`ret 8`** (`C2 08 00` ×3 exits).
3. **Semantics:** MSVC-style **`map::insert` unique insert-or-find** for **Node24 / isnil@+0x21**:
   - lower-bound walk: signed key @ **node+0x0C** / value[0]; isnil @ **+0x21**.
   - goLeft && where==begin → always-insert with **addLeft=1**.
   - goLeft && not begin → predecessor `FUN_005adff0`, then open-side test.
   - `hint->key < *value` → always-insert with **goLeft** flag.
   - else equal → **`inserted=0`**, keep existing; **no mapped rewrite**.
4. **Layout:** left@+0, parent@+4, right@+8, int key@**+0x0C**, payload@+0x10.., color@**+0x20**, isnil@**+0x21**; node **0x24** (from dualed parent buynode); shell head@+4.
5. **Callees:** `FUN_00511950` (dualed parent always-insert) ×2; `FUN_005adff0` (pred residual) ×1.
6. **Callers (1):** `FUN_0050ba90` @ `0x0050bbc4` (host map insert loop; int key = loop index).
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdMap_InsertOrFind_IntKey_Isnil21_Inferred` (Ghidra `FUN_00511b40`). Product demangle open → `_Inferred`. **Not** always-insert parent; **not** isnil29 IntKey peer `004cbe20`; **not** PairKey isnil21 `00407060`.
9. **Decompile ≡ raw CF**; RET / isnil / key imm sealed via `read_memory` + `disassemble_function`; call site `MOV ECX,EDI` seals thiscall.

### Gaps

- Product / MSVC demangle for mapped value_type (int key + vector of 0x10 elements per parent notes).  
- Residual predecessor `005adff0` and sole caller `0050ba90` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00511b40_StdMap_InsertOrFind_IntKey_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00511b40_StdMap_InsertOrFind_IntKey_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00511b40_FUN_00511b40.md` |
| Annotated | `docs/reconstruction/raw/aa_00511b40_FUN_00511b40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_IntKey_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00511b40.cpp` |
| Function | `docs/reconstruction/functions/aa_00511b40_FUN_00511b40.md` |
| Function named | `docs/reconstruction/functions/aa_00511b40_StdMap_InsertOrFind_IntKey_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_0050ba90  host map insert loop (int key)  [residual]
  └─ StdMap_InsertOrFind_IntKey_Isnil21_Inferred (0x00511b40)  [OWN R13-031]
       ├─ StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (0x00511950)  [R12-014 dualed parent]
       │    ├─ FUN_005118b0  buynode Node24 isnil21  [residual]
       │    ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)  [R10 dualed]
       │    └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)  [R11 dualed]
       └─ FUN_005adff0  predecessor isnil21  [residual]

Peers (do not merge):
  004cbe20 StdMap_InsertOrFind_IntKey_Isnil29_Inferred
  00407060 StdMap_InsertOrFind_PairKey_Isnil21_Inferred
  00511c00 erase peer isnil21 Node24 family  [residual after pad]
```

Partition system **skills-abilities** explains why this VA was queued under that residual set (host caller proximity under parent insert chain), not a skill-specific product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00511b40-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00511b40` | Port as **shared StdMap unique insert-or-find** for **isnil@+0x21 / key@+0x0C signed / Node24**. **`__thiscall`** ECX=map; stack `(out*, value*)`; **ret 8**. Equal key → `{it,false}` no rewrite. Pair with dualed always-insert parent `00511950`; residual pred `005adff0`. Do **not** merge with isnil29 IntKey `004cbe20` or PairKey isnil21 `00407060`. |
| Pair with | dualed parent insert `00511950`; dualed L/R rotates isnil21; residual pred `005adff0`; residual caller `0050ba90`. |
| Naming caution | **Not** always-insert. **Not** skill product logic. **Not** isnil29 / PairKey peers. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL map insert-or-find — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00511b40`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine ABI correction (thiscall RET8; out-pair result).  
- Odd behavior preserved: equal → inserted=0 no rewrite; begin insert forces addLeft=1.  
- `_Inferred` where product English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
