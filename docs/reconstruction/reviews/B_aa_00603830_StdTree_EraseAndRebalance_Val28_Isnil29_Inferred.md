# Review B (skeptical / adversarial): `aa_00603830` StdTree_EraseAndRebalance_Val28_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00603830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md` |
| **Agent** | WQ9E-F OWN-ONLY dual |
| **Verdict** | **accept** on CF/ABI; product name remains Inferred |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is insert / rebalance-only | **Falsified** — `"invalid map/set<T> iterator"`, unlink, `operator_delete`, size-- |
| 2 | isnil is Val12 @+0x19 | **Falsified** — entry `80 78 29 00` (offset **0x29**) |
| 3 | Ghidra body end `0x00603acf` is true end | **Falsified** — `read_memory` shows size-- + `ret 8` through `0x00603b03` |
| 4 | `operator_delete` is noreturn (decompiler) | **Falsified** — code after both deletes: zero fields, size--, write outIt |
| 5 | param_2 unused | **Falsified as semantics** — out-iterator advanced by `FUN_004cb270`; written at epilogue |
| 6 | Skill-only cast residual | **Falsified** — shared STL tree helper; sole caller erase-range |
| 7 | No size maintenance | **Falsified** — `cmp size,0` / `jbe` / `add eax,-1` / store `map+8` |
| 8 | Runtime Confirmed | **Rejected** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Erase + RB fixup CF | **Confirmed** | Map corruption / double-free |
| isnil@+0x29 / color@+0x28 | **Confirmed** | Wrong nil gate writes into payload |
| ret 8 / size-- | **Confirmed** | Stack imbalance; size drift |
| Val28 / node 0x2C | **High** | From buynode peer + value span to color |
| Product C++ name | **Inferred** | Rename only |
| Mapped-type English | Open | Port needs heap free @+0x14 preserved |

---

## 3. Cross-check

```
00603830: erase isnil29 — peer of StdTree_EraseAndRebalance_Val12 (004e4130)
004192a0 / 004192f0: L/R rotate isnil29 (WQ9D duals; listed callers include this VA)
0051b5d0 / 00421b50: Min/Max isnil29 (WQ9D duals)
00603c90: insert twin (this dual WQ9E-F)
00604280: sole caller erase-range loop
```

**Attack on “decompiler void + lost size--”:** epilogue bytes restore size-- and `*outIt`; RET **8** not 0.

**Attack on “+0x29 is color”:** color tests use `param_3[10]` / `+0x28`; isnil uses `+0x29` before parent rewrites — MSVC `_Isnil` / `_Color` split.

---

## 4. Surviving contract for AutoCore

```
// Node: left@0 parent@4 right@8 Val28@0x0C color@0x28 isnil@0x29; size 0x2C
// Tree: this+4 head; size@+8; root=head->parent

void StdTree_EraseAndRebalance_Val28_Isnil29(Map* m, Node** out, Node* n) {
  if (n->isnil) throw invalid_map_iterator;
  *out = n; ++*out;                 // FUN_004cb270
  // splice replacement; fix root/leftmost/rightmost
  // if n black: RB erase fixup with L/R rotate isnil29
  // free mapped_heap @+0x14 if any; delete n
  if (m->size > 0) --m->size;
}
```

Port notes:
- Keep **separate** from Val12 erase (`isnil@+0x19`, node `0x1C`).
- Do not trust Ghidra noreturn on `operator_delete`.
- Pair rotates with `StdTree_Lrotate_Isnil29` / `StdTree_Rrotate_Isnil29_Inferred`.

---

**Verdict:** **accept**
