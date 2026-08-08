# Dual A/B report — R13-021 OWN-ONLY (`0x0041a570`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-021**  
**Scope:** VA `0x0041a570` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including insert child re-dual `0041ba30`, pred `005adff0`, buynode `0041d860`, callers `007eaf20` / `0059a940`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory` + `disassemble_function` + `get_assembly_context` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-021**.  
**System:** skills-abilities.  
**Parent dual:** `0x0041ba30` StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (R12-011).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0041a570` StdMap_InsertOrFind_CharKey_Isnil21_Inferred | **accept-with-gaps** — insert-or-find CF/ABI/RET8/char-key/isnil21/equal-no-rewrite sealed; product + pred/host residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): always-insert-as-sole-role / merge-with-`0041ba30` / merge-with-pair-`00407060` / isnil29-merge / freelist / wrong RET / cdecl / hit-rewrite / skill-product-name / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0041a570` — sealed facts

1. **Body:** `0x0041a570`–`0x0041a628` exclusive (**184 B** / `0xB8`); pad `CC`.
2. **ABI:** **`__thiscall`** ECX=map; stack `InsertPair* out`, `const void* value`; **`ret 0x8`** (`C2 08 00` ×3). Out-pair written in place (`*out=node`, `out+4=inserted`).
3. **Semantics:** MSVC-style **unique insert-or-find** for **char-key isnil@+0x21**:
   - Lower-bound walk from root (`head->parent`); isnil@**+0x21**; compare `*key < node[+0x0C]`.
   - If goLeft and where==begin (`head->left`): insert via `0041ba30` addLeft=1 → `{it,1}`.
   - If goLeft and not begin: predecessor `005adff0` on where; then strict `where.key < key` → insert, else equal.
   - If !goLeft: strict `where.key < key` → insert with addLeft=goLeft; else equal `{it,0}`.
   - Equal hit does **not** rewrite mapped payload.
4. **Layout:** node left@0 / parent@4 / right@8 / **char key @+0x0C** / color@**+0x20** / isnil@**+0x21**; node **0x24** (via parent dual + buynode); map head@+4.
5. **Callees:** `0041ba30` InsertAndRebalance (dualed R12-011 parent); `005adff0` predecessor (undualed).
6. **Callers (2):** residual `FUN_007eaf20` (2 sites `007eba53`, `007ec6e4`); residual `FUN_0059a940` (1 site `0059ab1c`).
7. **Xrefs:** 3 UNCONDITIONAL_CALL.
8. **Name:** `StdMap_InsertOrFind_CharKey_Isnil21_Inferred` (Ghidra `FUN_0041a570`). Product demangle open → `_Inferred`. Reject scaffold CVOG/Named_CalleeOf chain as product name.
9. **Twins (CF):** peer pair-key InsertOrFind isnil21 `00407060` (different key/insert); always-insert child `0041ba30`; Val16 always-insert `00407200`.
10. **Decompile ≡ raw CF**; RET + thiscall + isnil/key offsets sealed via `read_memory` + disasm; caller `MOV ECX` seals thiscall.

### Gaps

- Product / MSVC demangle for value_type / map instantiation.  
- Full dual of predecessor `005adff0` and host callers.  
- Residual value payload after char key.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0041a570_FUN_0041a570.md` |
| Annotated | `docs/reconstruction/raw/aa_0041a570_FUN_0041a570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_CharKey_Isnil21_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0041a570.cpp` |
| Function | `docs/reconstruction/functions/aa_0041a570_FUN_0041a570.md` |
| Function named | `docs/reconstruction/functions/aa_0041a570_StdMap_InsertOrFind_CharKey_Isnil21_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_007eaf20 / FUN_0059a940  host map consumers  [residual]
  └─ StdMap_InsertOrFind_CharKey_Isnil21_Inferred (0x0041a570)  [OWN R13-021]
       ├─ StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred (0x0041ba30)  [R12-011 dualed ← parent dual]
       │    ├─ FUN_0041d860          buynode node0x24 / isnil21  [undualed]
       │    ├─ StdTree_Lrotate_Isnil21_Inferred (0x0050e9f0)   [R10 dualed]
       │    └─ StdTree_Rrotate_Isnil21_Inferred (0x005a27f0)   [R11 dualed]
       └─ FUN_005adff0               predecessor isnil21  [undualed]

Peer (other key family, dualed elsewhere):
  00407060 StdMap_InsertOrFind_PairKey_Isnil21_Inferred  (pair key / insert 00407200)
```

Partition system **skills-abilities** explains why this VA was queued under that residual set (host caller proximity / parent dual residual), not a skill-specific product name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0041a570-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0041a570` | Port as **shared StdMap unique insert-or-find** for **char-key isnil@+0x21 / color@+0x20 / node 0x24**. **thiscall** ECX=map; stack `(out, value)`; **ret 0x8**. Equal hit → `{it,0}` no rewrite. Pair with always-insert `0041ba30`, pred `005adff0`. |
| Pair with | Dualed insert `0041ba30` (R12-011); residual pred `005adff0`; residual hosts. |
| Naming caution | **Not** always-insert `0041ba30`. **Not** pair-key InsertOrFind `00407060`. **Not** Val16 always-insert `00407200`. **Not** skill/CVOGReaction-specific product API. |

---

## Parent merge handoff (not done here)

Parent dual R12-011 listed this unit as residual caller of always-insert `0041ba30` — now dualed R13-021. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual tables (generic STL insert-or-find — not skill UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0041a570`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (thiscall RET 8).  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
