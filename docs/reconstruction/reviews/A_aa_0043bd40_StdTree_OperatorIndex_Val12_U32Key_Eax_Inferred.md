# Review A (reconstruction fidelity): `aa_0043bd40` StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bd40` |
| **VA** | `0x0043bd40` |
| **Body** | `0x0043bd40`–`0x0043bda5` exclusive (**101** B) |
| **Canonical name** | `StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred` |
| **Ghidra name** | `FUN_0043bd40` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0043bd40_StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.md` |
| **System** | std map operator[] / get-or-insert (Val12, u32 key) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, xrefs/callers (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **map operator[] / get-or-insert by unsigned 32-bit key**, returning a pointer to the **mapped pair at `node+0x10`**. Key pointer arrives in **EAX**; map in **ECX**. On miss, zero-fills mapped (`{0,0}`) and inserts via `FUN_0043be60`.

```c
// ECX = map*; EAX = uint32_t* pKey; plain ret
int32_t* StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred(MapShell* map, const uint32_t* pKey);
// returns node + 0x10
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `aa_0043bd40_*` |
| Live decompile | ≡ raw CF; `in_EAX` is real ABI |
| Body | `read_memory 0x0043bd40` length 101; plain **`ret`**; miss stages three dwords |
| Insert | `FUN_0043be60` (unowned) |
| Call sites | `FUN_0073e3a0`, `FUN_0096eec0`, `FUN_0098d870`, … write two dwords to returned mapped |
| Peer | W29-Q `StdTree_OperatorIndex_Val12` (`0x0053af20`) — signed + thiscall stack key + `ret 4` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Get-or-insert / operator[] | **Confirmed** | hit return vs miss insert |
| Return `node+0x10` | **Confirmed** | both paths |
| Val12 isnil@+0x19 key@+0x0c mapped@+0x10/+0x14 | **Confirmed** | |
| Unsigned key compare | **Confirmed** | `jnb` family in body hex |
| ECX map + EAX key* + plain ret | **Confirmed** | `mov esi,eax`; final `c3` |
| Miss `{*key,0,0}` | **Confirmed** | stack stage zeros |
| Product map demangle | Open | |
| Insert helper full ABI | Open | unowned |

---

## 4. Gaps (non-blocking)

- Full contract of `FUN_0043be60` (hint edge cases, rebalance).
- Product English for each map owner (effect factory vs NestedHash host vs Z-fill).
- Runtime / bit-exact / differential.

---

## 5. Verdict rationale

CF, Val12 layout, unsigned lower_bound, dual-register ABI, and mapped return are sealed. Distinguish carefully from signed thiscall twin `0x0053af20`. Residual gaps are unowned insert helper and product names → **accept-with-gaps**.
