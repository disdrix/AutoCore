# Dual A/B report — R12-012 OWN-ONLY (`aa_004e37e0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R12-012  
**Partition:** `WAVE_2026-08-05_r12_residual_partition_map.md` → R12-012  
**Dual start:** 2646  
**Scope:** OWN ONLY VA `0x004e37e0`. Dual A/B + trio + function record.  
**System:** skills-abilities  
**Parent dual:** `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred`  
**Terminal:** false  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e37e0` StdTree_InsertAndRebalance_Val16_Isnil21_Inferred | **accept-with-gaps** — always-insert + RB rebalance; ABI/bytes/layout sealed; product English open |

---

## VA `0x004e37e0` — sealed facts

1. **Body:** `0x004e37e0`–`0x004e39ca` inclusive (**491 B** / `0x1EB`); exclusive end `0x004e39cb` (`cc` pad).
2. **ABI:** **ECX**=map*; stack `(out**, addLeft, where*, value*)`; **`RET 0x10`**.
3. **Semantics:** MSVC-style **map/set always-insert + red-black rebalance** for **Val16 / isnil@+0x21 / node 0x28** (color@**+0x20**).
4. **Size gate:** `cmp [map+8], 0x0FFFFFFE`; throw `"map/set<T> too long"` @ `0x00a1530c` via `DAT_00acc388`.
5. **Buynode:** `FUN_004e2b80` (`operator_new(0x28)`; Val16 @+0x10; color arg **0**=red; isnil=0).
6. **Rotates:** `FUN_0050e9f0` Lrotate; `FUN_005a27f0` Rrotate (parent dual); one Lrotate path **inlined**.
7. **Link:** empty-head first node / right+rightmost / left+leftmost.
8. **Exit:** root color black; `*out = new node`.
9. **Callers (1):** `FUN_004e48b0` — 2 UNCONDITIONAL_CALL xrefs (`004e4919`, `004e495a`). Parent owns key compare / uniqueness.
10. **Name:** `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (Ghidra `FUN_004e37e0`; **Inferred** — never Runtime Confirmed).
11. **Peer:** same-family always-insert `0x00407200` `StdTree_InsertAndRebalance_Isnil21_Inferred` (buynode `00408990` — keep clones separate).
12. **Decompile ≡ raw CF**; entry/epilogue bytes sealed via `read_memory`.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Residual buynode `004e2b80` and parent shell `004e48b0` not dualed this wave.  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files (trio + function + dual)

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e37e0_FUN_004e37e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e37e0_FUN_004e37e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.cpp` |
| Clean twin scaffold | `docs/reconstruction/reconstructed-exact/FUN_004e37e0.cpp` |
| Function (named) | `docs/reconstruction/functions/aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| Function (FUN_*) | `docs/reconstruction/functions/aa_004e37e0_FUN_004e37e0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e37e0_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| This report | `docs/agents/task-dual-ab-004e37e0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e37e0` | Shared isnil21 Val16 always-insert + rebalance leaf under `FUN_004e48b0`. Pair with Rrotate `005a27f0` / Lrotate `0050e9f0`. Do **not** put uniqueness here; do **not** merge with peer insert `00407200` (different buynode). Max size **`0x0FFFFFFE`**. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + callers/xrefs + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Name suffix **`_Inferred`**; never Runtime Confirmed.  
- Terminal **false**.
