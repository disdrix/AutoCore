# Dual A/B report — W19-K OWN `0x00568b70` + `0x00538190`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00568b70`, `0x00538190`. Dual A/B + artifacts.  
**Agent:** W19-K  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00568b70` Tree_RotateLeft | **accept** — **78-byte thiscall left-rotate leaf sealed** (isnil `@+0x49`, `ret 4`) |
| `aa_00538190` CNDHash_ReclaimAll_ValueOwning_009cefe4 | **accept-with-gaps** — **98-byte owning bucket reclaim sealed** (stamp `009cefe4`; product name open) |

---

## Sealed facts — `0x00568b70`

1. **ABI:** `void __thiscall Tree_RotateLeft(MapShell *map, Node *x)` — ECX=map, `[esp+4]=x`, **`ret 4`**.
2. **Body:** `0x00568b70`–`0x00568bbd` (**78 bytes**). Leaf.
3. **Algorithm:** left rotate: `y=x->right`; splice `y->left`; reattach `y` at `x`'s parent; `y->left=x`.
4. **isnil:** guard `*(u8*)(child+0x49)==0` before parent rewrite.
5. **Name:** `Tree_RotateLeft` — role-sealed **INFERRED**.
6. **Callers:** `FUN_00538780`, `FUN_00538ea0`, `FUN_00568c60`, `FUN_005690a0`.

---

## Sealed facts — `0x00538190`

1. **ABI:** `void __thiscall CNDHash_ReclaimAll_ValueOwning_009cefe4(CNDHash *this)` — ECX=this, bare **`ret`**.
2. **Body:** `0x00538190`–`0x005381f1` (**98 bytes**).
3. **Algorithm:** for `i=0..mask(+8)` inclusive: walk chain, stamp vtbl `009cefe4`, `operator_delete(node+8)`, freelist-push `+0x20`, clear heads.
4. **Not FreeBuckets:** does not zero count or free table (parent `0x005390d0` does).
5. **Decomp gap:** `operator_delete` returns (not noreturn).
6. **Sole caller:** `FUN_005390d0` / `CNDHash_FreeBuckets_Owning_009cfa7c`.
7. **Name:** `CNDHash_ReclaimAll_ValueOwning_009cefe4` — **INFERRED**.

---

## Gaps

1. Product/PDB English symbols for both.
2. Runtime / bit-exact / differential — open.
3. Exact heap value type behind `node+0x08` for stamp family `009cefe4`.

---

## Files

### `aa_00568b70` Tree_RotateLeft

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00568b70_Tree_RotateLeft.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00568b70_Tree_RotateLeft.md` |
| Function record | `docs/reconstruction/functions/aa_00568b70_FUN_00568b70.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateLeft.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00568b70.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_00568b70_FUN_00568b70.md` |
| Annotated | `docs/reconstruction/raw/aa_00568b70_FUN_00568b70.annotated.md` |
| Scratch | `tmp/a_00568b70.md` |

### `aa_00538190` CNDHash_ReclaimAll_ValueOwning_009cefe4

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00538190_CNDHash_ReclaimAll_ValueOwning_009cefe4.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00538190_CNDHash_ReclaimAll_ValueOwning_009cefe4.md` |
| Function record | `docs/reconstruction/functions/aa_00538190_FUN_00538190.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_ReclaimAll_ValueOwning_009cefe4.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00538190.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_00538190_FUN_00538190.md` |
| Annotated | `docs/reconstruction/raw/aa_00538190_FUN_00538190.annotated.md` |
| Scratch | `tmp/a_00538190.md` |

| Report | `docs/agents/task-dual-ab-00568b70-00538190-w19k-report.md` |

---

## AutoCore impact

- **Tree_RotateLeft:** port as standard left-rotate with isnil test at **`+0x49`** (not MSVC default `+0xD`). Pair with right-rotate `FUN_005681a0` for full RB fixup.
- **CNDHash reclaim:** when tearing down family `009cfa7c` hashes, delete owned values then freelist nodes; FreeBuckets must still free the table and zero count.
