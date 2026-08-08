# Review B (skeptical / adversarial): `aa_004e3e70` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e3e70` |
| **VA** | `0x004e3e70` |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-013 OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_004e3e70_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (**no** `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler `void` + noreturn `operator_delete` is full body | Bytes continue: size--, `*outIt`, `ADD ESP,0x54`, **`ret 8`** | **Falsified** as complete decomp |
| 2 | isnil/color at Val12 (+0x19/+0x18) | Body uses **`CMP [node+0x21]`** and color via `param_3[8]` / `+0x20` | **Falsified** Val12 layout |
| 3 | Same unit as `StdTree_EraseAndRebalance_Val12` @ `004e4130` | Adjacent VA, same size class, **different** isnil offset + rotate pair (`0050e9f0`/`005a27f0` vs Val12 rotates) | **Falsified** interchange |
| 4 | Function frees whole tree / range | Single-node erase; range is parents `004e4e10` / `004e52a0` | **Falsified** |
| 5 | No size update on erase | Epilogue `--size` when size>0 | **Falsified** |
| 6 | `param_2` (outIt) is dead formal | Epilogue `MOV [outIt*], successor` | **Falsified** |
| 7 | Named_VOG_DEBUG identity is product role | Scaffold callee-of chain only | **Falsified** product id |
| 8 | Interchangeable with isnil29 erase clones | Different isnil offset / rotate VAs / node size family | **Falsified** |
| 9 | Value dtor runs here | Only `operator_delete(node)` — no vcall on payload | **Agree** POD/trivial path |
| 10 | PDB name proven | No body product demangle | **Agree Open**; role High OK |

---

## 2. Live ≡ raw

```
Live decompile 2026-08-05 ≡ raw 2026-07-23 CF for throw / splice / RB.
read_memory entry: 64 A1 … 80 78 21 00 … 68 F0 52 A1 00 (isnil + string).
Epilogue: … C2 08 00 @ 0x004e4123; exclusive end 0x004e4126; 694 B.
Callers: FUN_004e4e10 @ 004e4eaf; FUN_004e52a0 @ 004e533f (2 xrefs only).
Rotates: FUN_0050e9f0 (L) / FUN_005a27f0 (R) — isnil@+0x21 sealed in rotate bodies.
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
// NOT Val12 (004e4130); NOT range erase; NOT insert twin (00407200)
```

---

## 4. CF challenge of Review A

- Throw / splice / RB / delete role: **agree Confirmed**
- thiscall + ret 8 + size-- + outIt: **agree Confirmed** (bytes over decomp)
- isnil@+0x21 / color@+0x20: **agree Confirmed**
- Two EraseRange callers: **agree Confirmed**
- Name `StdTree_EraseAndRebalance_Isnil21_Inferred`: **agree acceptable** (family vocabulary)
- Do not substitute Val12 / isnil29 clones: **agree**

---

## 5. Residual risks

1. Product English / demangled `map<K,V>` for the two EraseRange parents.  
2. Whether all isnil21 map users share POD values (no erase-time dtor).  
3. Full bit-exact rebalance path golden vs MSVC `_Tree`.  
4. Runtime / differential not run.  
5. Parent dual `005a27f0` / Lrotate `0050e9f0` may still be residual duals themselves (roles sealed here by call graph + isnil offset).

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, layout, and inferred name.
