# Review B (skeptical / adversarial): `aa_005e18d0` StdMap_InsertOrFindByIntKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e18d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W30-L) |
| **Counterpart** | `reviews/A_aa_005e18d0_StdMap_InsertOrFindByIntKey_Val12.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Always allocates new node | **Falsified** — equal key returns existing, `inserted=0` |
| 2 | Insert **updates** value fields when key exists | **Falsified** — equal path only writes out-pair |
| 3 | Pure lower_bound (no equality) | **Falsified** — third path is equal / no insert |
| 4 | `FUN_005ae050` is "tree insert" | **Falsified** — predecessor (`StdTree_Dec_Val12`) only |
| 5 | Unsigned key walk like inventory `00573810` | **Falsified** — retail uses **`setl`/`jge`** (signed) |
| 6 | Mission-only / reaction logic | **Falsified** — pure map mutator; mission is caller domain |
| 7 | Same body as `0053a1a0` | **Falsified** — peer CF; different always-insert helper VA (`005e13b0` vs `00539210`) |
| 8 | Legacy Mission Named_Callee is product role | **Narrow** — structural insert-or-find is the role |
| 9 | Vague stack arity | **Falsified** — `RET 8` sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | double-nodes or never-insert |
| Equal-key **no** value write | **High** | wrongly assume upsert |
| Out pair `{it@+0, bool@+4}` | **High** | caller misreads inserted |
| ABI `RET 0x8` | **High** | stack smash |
| `FUN_005e13b0` = insert+rebalance | **High** | crash / size throw |
| `FUN_005ae050` = predecessor | **High** | wrong insert side |
| Key = **signed** int @ +0x0c | **High** | wrong order for negative keys |
| Product English for v1/v2 | **Tentative** | docs only |
| Runtime capture | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = map (ECX/EDI); head = *(this+4); walk root by key at node+0xC;
isnil = node+0x19; left=*n, right=n[2];
SIGNED: setl on walk; jge on parent.key vs key
if goLeft && parent==leftmost: TreeInsert(…,1) → out{it,1};
else if goLeft: Predecessor(&parent);
if parent.key < key: TreeInsert(…,goLeft) → out{it,1};
else: out{parent,0}; // NO value copy
RET 0x8
```

Live decompile 2026-07-29 ≡ raw capture 2026-07-23. Clean plate documents insert-or-find (raw body append-only).

---

## 4. Surviving contract for AutoCore

```
// Val12 map — insert-or-find, NOT insert-or-assign; SIGNED int key
InsertPair StdMap_InsertOrFindByIntKey_Val12(map, entry{key,v1,v2}):
  if key missing: node = InsertAndRebalance(005e13b0); return {node, true}
  else: return {existing, false}  // v1/v2 UNCHANGED

// Do not substitute unsigned compare from inventory peer 00573810.
// Do not treat as mission-specific logic — share generic Val12 map path.
```

---

## 5. Open questions

1. Exact product map type for `FUN_005e0610`.  
2. Whether any caller depends on inserted==0 to refresh fields separately.  
3. Runtime / differential.

**Verdict:** **accept-with-gaps**
