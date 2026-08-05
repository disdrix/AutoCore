# Dual A/B report — W27-Q OWN `aa_004e4130` + `aa_00539210`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W27-Q  
**Scope:** VAs `0x004e4130`, `0x00539210` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md` (W27-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e4130` StdTree_EraseAndRebalance_Val12 | **accept-with-gaps** — Val12 erase CF/ABI/`ret 8`/size--/isnil throw sealed; product demangle open |
| `aa_00539210` StdTree_InsertAndRebalance_Val12 | **accept-with-gaps** — Val12 always-insert CF/ABI/`ret 0x10`/max-size/buynode sealed; multi-caller product open |

---

## VA `0x004e4130` — sealed facts

1. **Body:** `0x004e4130`–`0x004e43e6` exclusive (**694** B); pad `CC` after `RET 8`. Ghidra list end `004e43b6` truncated by false noreturn on `operator_delete`.
2. **ABI:** **`__thiscall`**; ECX = map (`head` @ `+4`, `size` @ `+8`); stack `(outIt*, node*)`; **`RET 8`**.
3. **Semantics:** MSVC `_Tree` **erase(iterator)** for Val12: nil throw → successor prep → unlink → RB fixup if black → delete → size-- → `*outIt`.
4. **Throw:** `"invalid map/set<T> iterator"` @ `0x00a152f0` / `DAT_00acc34c`.
5. **Node:** Val12 / 0x1c — left@0 parent@4 right@8 value@0x0c **color@0x18 isnil@0x19**.
6. **Callees:** `FUN_005ae0b0`, `FUN_005adfa0` (min), `FUN_00418bf0` (max), `FUN_00573170` (Lrotate), `FUN_00418c10` (Rrotate), `operator_delete`, throw chain.
7. **Callers (1):** `FUN_004e5120` (xref `004e51bf`).
8. **Name:** `StdTree_EraseAndRebalance_Val12` (Ghidra `FUN_004e4130`). Legacy Named_VOG_DEBUG_* is **narrow**.
9. **Decompile ≡ raw CF**; **epilogue size-- sealed by bytes** (decomp miss).

### Gaps

- Product English / full MSVC demangle for map of `FUN_004e5120`.  
- Product names of `FUN_005ae0b0` / min-max helpers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e4130_StdTree_EraseAndRebalance_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004e4130_StdTree_EraseAndRebalance_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e4130_FUN_004e4130.md` |
| Annotated | `docs/reconstruction/raw/aa_004e4130_FUN_004e4130.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e4130.cpp` |
| Function | `docs/reconstruction/functions/aa_004e4130_FUN_004e4130.md` |
| Function named | `docs/reconstruction/functions/aa_004e4130_StdTree_EraseAndRebalance_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_004e4130.md` |

---

## VA `0x00539210` — sealed facts

1. **Body:** `0x00539210`–`0x005393fa` exclusive (**490** B); pad `CC` after `RET 0x10`.
2. **ABI:** **`__thiscall`**; ECX = map; stack `(outIt*, addLeft, where, value*)`; **`RET 0x10`**.
3. **Semantics:** MSVC `_Tree` **always-insert** + RB rebalance for Val12 (buynode → link → fixup → root black → `*outIt`).
4. **Throw:** size `> 0x15555553` → `"map/set<T> too long"` @ `0x00a1530c` / `DAT_00acc388`.
5. **Buynode:** `FUN_005ae220` / `StdTree_Buynode_Val12` color 0 (W24-I sealed).
6. **Callees:** buynode + `FUN_00573170` + `FUN_00418c10` (+ **inlined Lrotate** on parent-is-right branch) + throw chain.
7. **Callers (2 / 9 xrefs):** `FUN_0053a1a0`, `FUN_0053a8e0`.
8. **Peer:** `Map_TreeInsertAndRebalance_Val12` @ `0x0051c1c0` (W25-G; same body length / constants; sole category-cooldown caller).
9. **Name:** `StdTree_InsertAndRebalance_Val12` (Ghidra `FUN_00539210`). Legacy Named_CVOGCharacter_* is **narrow**.
10. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English / demangle for caller map types.  
- Buynode null OOM path.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00539210_StdTree_InsertAndRebalance_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00539210_StdTree_InsertAndRebalance_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00539210_FUN_00539210.md` |
| Annotated | `docs/reconstruction/raw/aa_00539210_FUN_00539210.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00539210.cpp` |
| Function | `docs/reconstruction/functions/aa_00539210_FUN_00539210.md` |
| Function named | `docs/reconstruction/functions/aa_00539210_StdTree_InsertAndRebalance_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_00539210.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e4130` | Port Val12 map/set **erase** with isnil@+0x19, color@+0x18, size--, and Val12 L/R rotate pair — do **not** reuse isnil@+0x15 erase (`004baa30`) offsets/rotates. |
| `00539210` | Port Val12 **always-insert** rebalance (max `0x15555553`, buynode `005ae220`). Parent owns key walk / uniqueness. Share algorithm with `0051c1c0` clone. |
| Pair with | `StdTree_Buynode_Val12` (`0x005ae220`), `StdTree_Lrotate_Val12` (`0x00573170`), `StdTree_Rrotate_Val12` (`0x00418c10`), peer insert `Map_TreeInsertAndRebalance_Val12` (`0x0051c1c0`). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names inferred from MSVC `_Tree` insert/erase + Val12 layout evidence.
