# Review B (skeptical / adversarial): `aa_005a2ea0` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2ea0` |
| **VA** | `0x005a2ea0` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-030 OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_005a2ea0_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` (**no** `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void` + noreturn `operator_delete` is full body | Bytes continue: size--, `*outIt`, `ADD ESP,0x54`, **`ret 8`** | **Falsified** as complete decomp |
| 2 | isnil/color at Val12 (+0x19/+0x18) | Body uses **`CMP [node+0x21]`** and color via `param_3[8]` / `+0x20` | **Falsified** Val12 layout |
| 3 | Same binary unit as `004e3e70` (mergeable) | Same CF class / 694 B; **different VA**, SEH (`009a6342` vs `009a1e62`), call displacements; **distinct clone** | **Falsified** merge |
| 4 | Function frees whole tree / range | Single-node erase; range is parent `005a3860` | **Falsified** |
| 5 | No size update on erase | Epilogue `--size` when size>0 | **Falsified** |
| 6 | `param_2` (outIt) is dead formal | Epilogue `MOV [outIt*], successor` | **Falsified** |
| 7 | Skill-domain exclusive helper | Shared std tree; EraseRange + orphan map shell | **Falsified** product skill-only |
| 8 | Interchangeable with isnil29 erase clones | Different isnil offset / rotate VAs / node size family | **Falsified** |
| 9 | This is InsertAndRebalance | Ends in `operator_delete` + size--; no buynode | **Falsified** |
| 10 | Runtime Confirmed | No Launcher / no live hit | **Agree Open** — **never** Runtime Confirmed this dual |
| 11 | Value dtor runs here | Only `operator_delete(node)` — no vcall on payload | **Agree** POD/trivial path |
| 12 | PDB name proven | No body product demangle | **Agree Open**; role High OK |

---

## 2. Live ≡ raw

```
Live decompile 2026-08-05 ≡ raw 2026-07-23 CF for throw / splice / RB.
read_memory entry: 64 A1 … 80 78 21 00 … 68 F0 52 A1 00 (isnil + string).
Epilogue: … C2 08 00 @ 0x005a3153; exclusive end 0x005a3156; 694 B.
Xrefs: FUN_005a3860 @ 005a38ff; orphan 005a052b (2 only).
Rotates: FUN_0050e9f0 (L) / FUN_005a27f0 (R) — isnil@+0x21 sealed in rotate duals.
Call sites both: MOV ECX,EDI then 2 stack args → thiscall RET 8.
```

---

## 3. Surviving contract

```
// void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(map*, Node** outIt, Node* node)
// RET 8
// if node->isnil(+0x21): throw "invalid map/set<T> iterator"
// successor via FUN_004e12c0; splice; fix L/R extremes (004cb2c0 / 00421a60)
// if erased black(+0x20): RB with 0050e9f0 / 005a27f0
// operator_delete(node); if size>0 size--; *outIt = succ
// NOT Val12; NOT isnil29; NOT range erase; NOT insert twin (00407200)
// NOT merge with clone VAs 00405650 / 004e3e70 / 0059d300 / …
```

---

## 4. CF challenge of Review A

- Throw / splice / RB / delete role: **agree High**
- thiscall + ret 8 + size-- + outIt: **agree High** (bytes over decomp)
- isnil@+0x21 / color@+0x20: **agree High**
- Two xrefs (one EraseRange + orphan): **agree High**
- Name `StdTree_EraseAndRebalance_Isnil21_Inferred`: **agree acceptable** (family vocabulary; `_Inferred`)
- Do not substitute Val12 / isnil29 / insert: **agree**
- Runtime Confirmed: **reject any claim** — terminal false

---

## 5. Residual risks

1. Product English / demangled `map<K,V>` for `FUN_005a3860` and orphan host.  
2. Orphan body at `005a04d0` not created as Ghidra function (DATA `009d7f0c`).  
3. Whether all isnil21 map users share POD values (no erase-time dtor).  
4. Full bit-exact rebalance path golden vs MSVC `_Tree`.  
5. Runtime / differential not run.  
6. Clone VAs remain separate duals even when CF-isomorphic.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, layout, and inferred name. **Never Runtime Confirmed.**
