# Dual A/B report — R13-005 OWN-ONLY (`aa_004e48b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R13-005  
**Partition:** `WAVE_2026-08-05_r13_residual_partition_map.md` → R13-005  
**Dual start:** 2686  
**Scope:** OWN ONLY VA `0x004e48b0`. Dual A/B + trio + function record.  
**System:** skills-abilities  
**Parent dual:** `0x004e37e0` `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred`  
**Terminal:** false  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e48b0` StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred | **accept-with-gaps** — unique pair-key insert-or-find shell; ABI/bytes/layout sealed; product English open |

---

## VA `0x004e48b0` — sealed facts

1. **Body:** `0x004e48b0`–`0x004e4982` inclusive (**211 B** / `0xD3`); exclusive end `0x004e4983` (`cc` pad).
2. **ABI:** **ECX**=map*; stack `(out*, value*)`; **`RET 0x8`**.
3. **Semantics:** MSVC-style **map unique insert-or-find** for **pair key** (signed hi @+0x14 primary, unsigned lo @+0x10 secondary) on **isnil@+0x21 / Val16** nodes.
4. **Lower-bound walk** from `head->parent`; stop at isnil; track `goLeft` / `addLeft`.
5. **Insert worker:** dualed `FUN_004e37e0` ×2 (`004e4919`, `004e495a`) — always-insert + RB rebalance; uniqueness **not** in worker.
6. **Predecessor:** residual `FUN_005adff0` when last step went left and `where != begin`.
7. **Equal hit:** `out.inserted = 0`; `out.it = node` — **no** mapped rewrite.
8. **Out pair:** node* @ `out+0`; inserted byte @ `out+4` (`C6 40 04 01/00`).
9. **Callers (2):** `CVOGReaction_UpdateRepairStationPosition` @ `004d391f`; residual `FUN_004da160` @ `004da224`.
10. **Name:** `StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred` (Ghidra `FUN_004e48b0`; **Inferred** — never Runtime Confirmed).
11. **Peer clone:** dualed `0x00407060` `StdMap_InsertOrFind_PairKey_Isnil21_Inferred` (same CF/size/compare; insert via `00407200` — **keep separate**).
12. **Family peer:** dualed isnil29 pair shell `0x004cbee0` — do not merge.
13. **Decompile ≡ raw CF**; full body + epilogue sealed via `read_memory`.

### Gaps

- Product/PDB symbol for pair type (TFID-shaped under repair-station is plausible only).  
- Residual pred `005adff0` and second caller `004da160` not dualed this wave.  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` | **accept-with-gaps** |

### Files (trio + function + dual)

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e48b0_FUN_004e48b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e48b0_FUN_004e48b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.cpp` |
| Clean twin scaffold | `docs/reconstruction/reconstructed-exact/FUN_004e48b0.cpp` |
| Function (named) | `docs/reconstruction/functions/aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` |
| Function (FUN_*) | `docs/reconstruction/functions/aa_004e48b0_FUN_004e48b0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e48b0_StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred.md` |
| This report | `docs/agents/task-dual-ab-004e48b0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e48b0` | Port as **unique insert-or-find** for isnil@**+0x21** pair-key maps (Val16 nodes). Pair with dualed insert/rebalance `004e37e0`. Compare: **signed hi** then **unsigned lo**. Hit path must **not** rewrite mapped value. Do **not** merge with peer shell `00407060` (insert `00407200`) or isnil29 pair `004cbee0`. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + callers/xrefs + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Name suffix **`_Inferred`**; never Runtime Confirmed.  
- Terminal **false**.
