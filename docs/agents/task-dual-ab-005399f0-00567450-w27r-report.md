# OWN-ONLY dual agent report — W27-R

| Field | Value |
|---|---|
| Agent | W27-R |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x005399f0`, `0x00567450` |
| Partition | `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md` |
| Tools | Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + callers/callees (**no** `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005399f0` Map_EraseNode_Val12 | **accept-with-gaps** — **Val12 erase; ret 8; Ghidra end truncated; size-- + *outIt sealed from bytes** |
| `aa_00567450` Map_TreeInsertAndRebalance_Val12 | **accept-with-gaps** — **Val12 always-insert clone of 0051c1c0; ret 0x10; buynode 005ae220; sole caller 00567860** |

---

## VA `0x005399f0` — Map_EraseNode_Val12

| Field | Value |
|---|---|
| Ghidra | `FUN_005399f0` |
| Canonical | `Map_EraseNode_Val12` (**Inferred**) |
| Body | `0x005399f0`–`0x00539ca6` exclusive (**694** B / `0x2B6`); Ghidra listed end `0x00539c76` **stale** |
| Role | MSVC red-black single-node erase (Val12) |
| ABI | `__thiscall` ECX=map; stack `(outIt, node)`; **ret 8** |
| Callees | `FUN_005ae0b0`, `FUN_005adfa0`, `FUN_00418bf0`, `FUN_00573170`, `FUN_00418c10`, `operator_delete`, throw path |
| Callers | **1** — `FUN_0053a260` (range erase) |
| Live ≡ raw surface | Yes through delete; post-delete from bytes |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **isnil@+0x19** gate → throw `"invalid map/set<T> iterator"` / `DAT_00acc34c`.
2. Unlink + head leftmost/root/rightmost fixup; min/max helpers `FUN_005adfa0` / `FUN_00418bf0`.
3. Black-node RB fixup with Val12 **L/R rotates** (`FUN_00573170` / `FUN_00418c10`).
4. `operator_delete(node)` **falls through** (decomp noreturn residual).
5. **size--** if size>0; **`*outIt = successor`**; **`ret 8`**.
6. Peer `Map_EraseNode` `aa_0051cb40` is **different layout** (isnil@+0x29) despite same 694 B / ret 8 shape.

### Gaps

1. Product mangled name / map type for sole parent.
2. Full product role of `FUN_005ae0b0`.
3. Line-by-line RB formal proof vs MSVC reference.
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005399f0_Map_EraseNode_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005399f0_Map_EraseNode_Val12.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_005399f0_FUN_005399f0.md`
- `docs/reconstruction/raw/aa_005399f0_FUN_005399f0.annotated.md`
- `docs/reconstruction/reconstructed-exact/Map_EraseNode_Val12.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_005399f0.cpp`
- `docs/reconstruction/functions/aa_005399f0_Map_EraseNode_Val12.md`
- `docs/reconstruction/functions/aa_005399f0_FUN_005399f0.md`
- `docs/reconstruction/reviews/A_aa_005399f0_Map_EraseNode_Val12.md`
- `docs/reconstruction/reviews/B_aa_005399f0_Map_EraseNode_Val12.md`

---

## VA `0x00567450` — Map_TreeInsertAndRebalance_Val12

| Field | Value |
|---|---|
| Ghidra | `FUN_00567450` |
| Canonical | `Map_TreeInsertAndRebalance_Val12` (**Inferred**; clone of `aa_0051c1c0`) |
| Body | `0x00567450`–`0x0056763a` exclusive (**490** B / `0x1EA`) |
| Role | MSVC red-black always-insert + rebalance (Val12) |
| ABI | `__thiscall` ECX=map; stack `(outIt, addLeft, where, value)`; **ret 0x10** |
| Callees | `FUN_005ae220` (StdTree_Buynode_Val12), `FUN_00573170`, `FUN_00418c10`, throw path |
| Callers | **1** — `FUN_00567860` (int-key insert-or-find) |
| Live ≡ raw surface | Yes |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. Size gate **`0x15555553`** → `"map/set<T> too long"` / `DAT_00acc388`.
2. Buy via **`FUN_005ae220`** color **0**; size++; link empty/left/right + maybe leftmost/rightmost.
3. While parent red: recolor or rotate; paint root black; `*outIt = n`.
4. **`ret 0x10`**; entry `mov edi,ecx`.
5. Twin **`0x0051c1c0`** same size/max/buynode family — **do not merge** (different sole caller).
6. Parent owns key walk (`*key < node[3]`); this unit never compares keys.

### Gaps

1. Product mangled map type.
2. Buynode OOM (null) path.
3. One rotate path inlined vs helper call (retail exactness residual).
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00567450_Map_TreeInsertAndRebalance_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00567450_Map_TreeInsertAndRebalance_Val12.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_00567450_FUN_00567450.md`
- `docs/reconstruction/raw/aa_00567450_FUN_00567450.annotated.md`
- `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_00567450.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00567450.cpp`
- `docs/reconstruction/functions/aa_00567450_Map_TreeInsertAndRebalance_Val12.md`
- `docs/reconstruction/functions/aa_00567450_FUN_00567450.md`
- `docs/reconstruction/reviews/A_aa_00567450_Map_TreeInsertAndRebalance_Val12.md`
- `docs/reconstruction/reviews/B_aa_00567450_Map_TreeInsertAndRebalance_Val12.md`

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Erase (`0x005399f0`)

- Port as **Val12** erase leaf: isnil@+0x19, color@+0x18, size@+8, **ret 8**.
- Do **not** use large-node `Map_EraseNode` (isnil@+0x29) offsets here.
- After free: always size-- when size>0; publish successor iterator.
- Range clear path goes through parent `FUN_0053a260` (not owned).

### Insert (`0x00567450`)

- Shared Val12 insert contract with `aa_0051c1c0` / category-cooldown helper — same max constant and buynode.
- Keep **separate** from SkillElementTypeMap insert (`0x1ffffffd`, different node size).
- Uniqueness lives in parent lower_bound (`FUN_00567860`); this unit always inserts.

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / `WORK_QUEUE` / partition map edits.
- Owned VAs only; referenced but did not re-seal `005ae220`, `00573170`, `00418c10`, `0051c1c0`, `0051cb40`, parents `0053a260` / `00567860`.
- Scratch helper: `docs/reconstruction/tmp/_w27r_emit.py`
