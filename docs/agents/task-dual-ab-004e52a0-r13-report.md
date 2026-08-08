# Dual A/B report — R13-025 OWN-ONLY (`aa_004e52a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual R13-025  
**Partition:** `WAVE_2026-08-05_r13_residual_partition_map.md` → R13-025  
**Dual start:** 2686  
**Scope:** OWN ONLY VA `0x004e52a0`. Dual A/B + trio + function record.  
**System:** skills-abilities  
**Parent dual:** `0x004e3e70` `StdTree_EraseAndRebalance_Isnil21_Inferred`  
**Terminal:** false  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e52a0` StdTree_EraseRange_Isnil21_Inferred | **accept-with-gaps** — full/partial range erase shell; ABI/bytes/layout/callers sealed; product English open |

---

## VA `0x004e52a0` — sealed facts

1. **Body:** `0x004e52a0`–`0x004e5353` inclusive (**180 B** / `0xB4`); exclusive end `0x004e5354` (`CC`×12 pad → `FUN_004e5360`).
2. **ABI:** **ECX**=map*; stack `(outIt**, first*, last*)`; **`RET 0x0C`** on both exits (`C2 0C 00`).
3. **Semantics:** MSVC-style **map/set range erase** `[first, last)` for **isnil@+0x21** family:
   - full range `[head->left, head)` → free-subtree `FUN_004e2e40(head->parent)`; reset head L/P/R; `size(+8)=0`; `*outIt=head->left`
   - partial → in-order successor (isnil@+0x21) + single erase `FUN_004e3e70` (parent dual); `*outIt=end`
4. **Layout:** head@map+4; size@map+8; node left/parent/right @+0/+4/+8; isnil@**+0x21**; color@**+0x20** (via erase callee).
5. **Callees:** `FUN_004e2e40` @ call `0x004e52bc`; `FUN_004e3e70` @ call `0x004e533f`.
6. **Callers (2):** `FUN_004da160` @ `0x004da2b4`; `FUN_004e73f0` @ `0x004e7402` — UNCONDITIONAL_CALL only.
7. **Name:** `StdTree_EraseRange_Isnil21_Inferred` (Ghidra `FUN_004e52a0`; **Inferred** — never Runtime Confirmed).
8. **Sibling clone (not owned):** `FUN_004e4e10` same CF/size; free=`FUN_004e2e00` (R13-024).
9. **Peer family:** Val12 range `0x0040d700` `StdTree_EraseRange_Val12` (isnil@+0x19; keep separate).
10. **Decompile ≡ raw CF**; entry/epilogue/`RET 0x0C` sealed via `read_memory`.

### Gaps

- Product/PDB symbol (Inferred name only).  
- Residual free `004e2e40` and sibling range `004e4e10` not dualed this wave.  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md` | **accept-with-gaps** |

### Files (trio + function + dual)

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e52a0_FUN_004e52a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e52a0_FUN_004e52a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil21_Inferred.cpp` |
| Clean twin scaffold | `docs/reconstruction/reconstructed-exact/FUN_004e52a0.cpp` |
| Function (named) | `docs/reconstruction/functions/aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md` |
| Function (FUN_*) | `docs/reconstruction/functions/aa_004e52a0_FUN_004e52a0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md` |
| This report | `docs/agents/task-dual-ab-004e52a0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e52a0` | Shared isnil21 **range erase** shell under clear/dtor callers. Pair with single erase `004e3e70` and free `004e2e40`. Do **not** put RB rebalance here; do **not** merge with sibling `004e4e10` (different free) or Val12 range `0040d700`. ABI **`RET 0x0C`**. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + callers/xrefs + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Name suffix **`_Inferred`**; never Runtime Confirmed.  
- Terminal **false**.
