# Dual A/B report — W28-P OWN `aa_004e5120` + `aa_0053a1a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-P  
**Scope:** VAs `0x004e5120`, `0x0053a1a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave28 (W28-P). Related prior: W27-Q sealed callees `004e4130` / `00539210`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e5120` StdMap_EraseRange_Val12 | **accept-with-gaps** — Val12 range erase; full free + partial successor/`004e4130`; **`ret 0x0c`**; sole caller `004e7350` |
| `aa_0053a1a0` StdMap_InsertOrFindByIntKey_Val12 | **accept-with-gaps** — int-key insert-or-find; isnil@+0x19; insert via `00539210`; **`ret 8`**; sole caller `0053a8e0` |

---

## VA `0x004e5120` — sealed facts

1. **Body:** `0x004e5120`–`0x004e51d4` exclusive (**180** B / `0xB4`); pad `CC` after **`RET 0x0C`**.
2. **ABI:** **`__thiscall`**; ECX = map (`head` @ `+4`, `size` @ `+8`); stack `(outIt*, first, last)`; **`RET 0x0C`**.
3. **Semantics:** MSVC `_Tree` **erase(first, last)** for Val12: full-range free via `FUN_004e2940` + head reset / size0; else successor (isnil@+0x19) + `FUN_004e4130` per node.
4. **Callees:** `FUN_004e2940`, `FUN_004e4130` (`StdTree_EraseAndRebalance_Val12`, W27-Q).
5. **Callers (1):** `FUN_004e7350` (xref `004e7362`) — clear then `operator_delete(head)`.
6. **Node:** Val12 — left@0 parent@4 right@8 value@0x0c; **isnil@+0x19** (successor); color owned by erase callee.
7. **Name:** `StdMap_EraseRange_Val12` (Ghidra `FUN_004e5120`). Peer isnil@+0x15: `aa_004bacf0`.
8. **Decompile ≡ raw CF**; **`ret 0x0c` sealed by bytes**.

### Gaps

- Product English / full MSVC demangle for map type.  
- Full left-recurse detail in `FUN_004e2940` (false-noreturn residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e5120_StdMap_EraseRange_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e5120_StdMap_EraseRange_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e5120_FUN_004e5120.md` |
| Annotated | `docs/reconstruction/raw/aa_004e5120_FUN_004e5120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseRange_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e5120.cpp` |
| Function | `docs/reconstruction/functions/aa_004e5120_FUN_004e5120.md` |
| Function named | `docs/reconstruction/functions/aa_004e5120_StdMap_EraseRange_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_004e5120.md` |

---

## VA `0x0053a1a0` — sealed facts

1. **Body:** `0x0053a1a0`–`0x0053a259` exclusive (**185** B / `0xB9`); pad `CC` after **`RET 8`**.
2. **ABI:** **`__thiscall`**; ECX = map; stack `(InsertPair* out, Val12* value)`; **`RET 8`**.
3. **Semantics:** MSVC map **insert-or-find** by signed int key (`*value` vs `node[3]` @ +0x0C); miss → `FUN_00539210`; hit → `inserted=0`.
4. **InsertPair:** `it` @ +0; **`inserted` byte @ +4**.
5. **Callees:** `FUN_00539210` (`StdTree_InsertAndRebalance_Val12`, W27-Q), `FUN_005ae050` (predecessor).
6. **Callers (1):** `FUN_0053a8e0` (xref `0053aa2d`) — hint-insert fallback.
7. **Name:** `StdMap_InsertOrFindByIntKey_Val12` (Ghidra `FUN_0053a1a0`). Peer role: `FUN_00567860` + insert `00567450` (W27-R) — **do not merge**.
8. **Decompile ≡ raw CF**; **`ret 8` sealed by bytes** (×3 exits).

### Gaps

- Product English / demangle for map type.  
- Value dwords beyond key meaning.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0053a1a0_FUN_0053a1a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0053a1a0_FUN_0053a1a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0053a1a0.cpp` |
| Function | `docs/reconstruction/functions/aa_0053a1a0_FUN_0053a1a0.md` |
| Function named | `docs/reconstruction/functions/aa_0053a1a0_StdMap_InsertOrFindByIntKey_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_0053a1a0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e5120` | Port Val12 **range erase** with isnil@+0x19 successor and Val12 single erase (`004e4130`). Full clear: free tree + head self-link + size0. **Do not** reuse isnil@+0x15 erase-range (`004bacf0`) offsets. |
| `0053a1a0` | Port int-key **insert-or-find** on Val12; pair out `{it, inserted@+4}`; miss uses `00539210` (max `0x15555553`, buynode `005ae220`). Uniqueness owned here; always-insert is separate. |
| Pair with | W27-Q `StdTree_EraseAndRebalance_Val12` / `StdTree_InsertAndRebalance_Val12`; buynode `005ae220`; rotates Val12; peer range erase isnil15 `004bacf0`; peer insert-or-find parent `00567860`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + get_function_by_address.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names inferred from MSVC `_Tree` range-erase / insert-or-find + Val12 layout evidence.
