# Dual A/B report — R12-031 OWN-ONLY (`aa_005a3500`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R12-031  
**Partition:** `WAVE_2026-08-05_r12_residual_partition_map.md` → R12-031  
**Dual start:** 2646  
**Scope:** OWN ONLY VA `0x005a3500`. Dual A/B + trio + function record.  
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
| `aa_005a3500` StdTree_InsertAndRebalance_Val16_Isnil21_Inferred | **accept-with-gaps** — always-insert + RB rebalance; ABI/bytes/layout sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): key-compare-in-body / wrong size gate / wrong isnil family / merge with `00407200` or overwrite twin `004e37e0` / wrong RET / Runtime Confirmed all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005a3500` — sealed facts

1. **Body:** `0x005a3500`–`0x005a36ea` inclusive (**491 B** / `0x1EB`); exclusive end `0x005a36eb` (`cc` pad).
2. **ABI:** **ECX**=map*; stack `(out**, addLeft, where*, value*)`; **`RET 0x10`**.
3. **Semantics:** MSVC-style **map/set always-insert + red-black rebalance** for **Val16 / isnil@+0x21 / node 0x28** (color@**+0x20**).
4. **Size gate:** `cmp [map+8], 0x0FFFFFFE`; throw `"map/set<T> too long"` @ `0x00a1530c` via `DAT_00acc388`.
5. **Buynode:** `FUN_004e2b80` (`operator_new(0x28)`; Val16 @+0x10; color arg **0**=red; isnil=0).
6. **Rotates:** `FUN_0050e9f0` Lrotate; `FUN_005a27f0` Rrotate (parent dual); one Lrotate path **inlined** (isnil `80 7a 21 00`).
7. **Link:** empty-head first node / right+rightmost / left+leftmost.
8. **Exit:** root color black; `*out = new node`.
9. **Callers (1):** `FUN_005a3be0` — 2 UNCONDITIONAL_CALL xrefs (`005a3c49`, `005a3c8a`). Parent owns key compare / uniqueness.
10. **Name:** `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` (Ghidra `FUN_005a3500`; **Inferred** — never Runtime Confirmed).
11. **Twins / peers:** near-byte twin dualed `0x004e37e0` (R12-012; same CF/size/buynode; caller `004e48b0`); peer always-insert `0x00407200` (buynode `00408990` — keep separate).
12. **Decompile ≡ raw CF**; entry/epilogue/full body bytes sealed via `read_memory`.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Residual buynode `004e2b80` and parent shell `005a3be0` not dualed this wave.  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files (trio + function + dual)

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005a3500_FUN_005a3500.md` |
| Annotated | `docs/reconstruction/raw/aa_005a3500_FUN_005a3500.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val16_Isnil21_005a3500_Inferred.cpp` |
| Clean twin scaffold | `docs/reconstruction/reconstructed-exact/FUN_005a3500.cpp` |
| Function (named) | `docs/reconstruction/functions/aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| Function (FUN_*) | `docs/reconstruction/functions/aa_005a3500_FUN_005a3500.md` |
| Review A | `docs/reconstruction/reviews/A_aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| This report | `docs/agents/task-dual-ab-005a3500-r12-report.md` |

---

## Chain context (not dualled here; evidence only)

```text
FUN_005a3be0  residual InsertOrFind-style (pair key at +0x10/+0x14)
  └─ StdTree_InsertAndRebalance_Val16_Isnil21_Inferred (0x005a3500)  [OWN R12-031]
       ├─ FUN_004e2b80   buynode Val16 / 0x28 / isnil21  [residual]
       ├─ FUN_0050e9f0   StdTree_Lrotate_Isnil21_Inferred [dualed]
       └─ FUN_005a27f0   StdTree_Rrotate_Isnil21_Inferred [parent dual R11-007]

Twin clone (dualed R12-012):
  0x004e37e0  StdTree_InsertAndRebalance_Val16_Isnil21_Inferred  (caller FUN_004e48b0)

Peer family (different buynode):
  0x00407200  StdTree_InsertAndRebalance_Isnil21_Inferred  (buynode 00408990)
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005a3500` | Shared isnil21 Val16 always-insert + rebalance leaf under `FUN_005a3be0`. Pair with Rrotate `005a27f0` / Lrotate `0050e9f0`. Do **not** put uniqueness here; do **not** merge with peer insert `00407200` (different buynode); do **not** overwrite twin clean `004e37e0`. Max size **`0x0FFFFFFE`**. |
| Pair with | Parent dual Rrotate isnil21; Lrotate isnil21; twin `004e37e0`; residual buynode `004e2b80`; residual parent `005a3be0`. |
| Naming caution | Structural name shared with twin `004e37e0`; clean path is VA-qualified (`…_005a3500_…`). **Not** skill-only. **Not** isnil29 InsertNode (`005a3310`). |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + callers/xrefs + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Name suffix **`_Inferred`**; never Runtime Confirmed.  
- Terminal **false**.

---

## Parent merge handoff (not done here)

Parent dual R11-007 (`005a27f0`) listed this insert shell as a residual caller of Rrotate — now dualed R12-031. Registry / matrix / system ledger updates are parent-merge responsibility (forbidden for this OWN agent).
