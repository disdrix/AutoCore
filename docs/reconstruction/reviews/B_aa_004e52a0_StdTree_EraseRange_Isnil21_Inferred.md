# Review B (skeptical / adversarial): `aa_004e52a0` StdTree_EraseRange_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e52a0` |
| **VA** | `0x004e52a0` |
| **Canonical name** | `StdTree_EraseRange_Isnil21_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-025 OWN-ONLY dual) |
| **Counterpart** | `reviews/A_aa_004e52a0_StdTree_EraseRange_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (**no** `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is single-node erase | Body has full-range free + loop; single erase is callee `004e3e70` only | **Falsified** as single-erase |
| 2 | Val12 layout (isnil@+0x19) | Partial path uses **`+0x21`** exclusively | **Falsified** Val12 |
| 3 | Same unit as sibling `004e4e10` | Same CF/size class but free callee **`004e2e40` vs `004e2e00`** — keep clones separate | **Falsified** merge |
| 4 | Same as Val12 range `0040d700` | Same shell shape / 180 B, **different** isnil offset + free/erase VAs | **Falsified** interchange |
| 5 | Free call is cdecl-only / no this | Bytes leave **ECX=map (EDI)** into `004e2e40`; free prologue uses ECX | **Falsified** pure-cdecl |
| 6 | Decompiler `void FUN(void)` signature | Locals/stack formals + `RET 0x0C` seal 3 stack args | **Falsified** empty prototype |
| 7 | Uses erase return iterator only | After `004e3e70`, ESI/next overwrites; precomputed successor is authoritative for loop | **Agree nuance** — out-slot still written by erase |
| 8 | Implements RB rebalance here | No rotate calls; rebalance inside `004e3e70` | **Falsified** |
| 9 | PDB name proven | No body product demangle | **Agree Open**; role High OK |
| 10 | Runtime Confirmed | Static dual only | **Agree** — **Inferred** only |

---

## 2. Live ≡ raw

```
Live decompile 2026-08-05 ≡ raw 2026-07-23 CF for full free + partial successor+erase.
read_memory body: 180 B; entry 53 8B 5C 24 10 …; both exits C2 0C 00.
Call targets: 004e52bc→004e2e40; 004e533f→004e3e70.
Callers: FUN_004da160 @ 004da2b4; FUN_004e73f0 @ 004e7402 (2 xrefs only).
isnil probes: 80 7E 21 00 / 80 78 21 00 throughout partial path.
```

---

## 3. Surviving contract

```
// void __thiscall StdTree_EraseRange_Isnil21_Inferred(map*, Node** outIt, Node* first, Node* last)
// RET 0x0C
// if first==head->left && last==head:
//   FUN_004e2e40(map, head->parent); reset head L/P/R; size=0; *outIt=head->left
// else:
//   while first!=last: next=successor_isnil21(first); erase(map,&slot,first); first=next
//   *outIt=first
// NOT single-erase (004e3e70); NOT Val12 range (0040d700); NOT sibling free-004e2e00 (004e4e10)
```

---

## 4. CF challenge of Review A

- Full vs partial gate: **agree Confirmed**
- thiscall + ret 0x0C + 3 stack formals: **agree Confirmed** (bytes)
- isnil@+0x21 successor: **agree Confirmed**
- Callees free `004e2e40` + erase `004e3e70`: **agree Confirmed**
- Two callers: **agree Confirmed**
- Name `StdTree_EraseRange_Isnil21_Inferred`: **agree acceptable** (family vocabulary; **Inferred**)
- Do not merge with `004e4e10` / Val12 `0040d700`: **agree**

---

## 5. Residual risks

1. Product English / demangled `map<K,V>` for callers (`004da160` inserts via `004e48b0` Val16 family — product key still open).  
2. Whether free `004e2e40` runs value dtors (decomp incomplete; bytes show recursive free + `operator_delete`; residual dual).  
3. Sibling `004e4e10` free path difference (`004e2e00`) may encode value-destroy variant — do not assume identical.  
4. Runtime / differential / bit-exact not run.  
5. Parent dual `004e3e70` sealed statically; not re-owned here.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, CF, callers, layout, callees, and inferred name.
