# Review B (skeptical / adversarial): `aa_00573810` StdMap_InsertOrFind_Val12_UintKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573810` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W28-T) |
| **Counterpart** | `reviews/A_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Always allocates new node | **Falsified** — equal key returns existing, `inserted=0` |
| 2 | Insert **updates** value fields when key exists | **Falsified** — equal path only writes out-pair |
| 3 | Pure lower_bound (no equality) | **Falsified** — third path is equal / no insert |
| 4 | `FUN_005ae050` is "tree insert" | **Falsified** — predecessor walk only |
| 5 | Uses ESI buynode `0046c6c0` | **Falsified** — insert helper is `00573510` → stack buy `005ae220` |
| 6 | Inventory-only / UI modal logic | **Falsified** — pure map mutator; inventory is caller domain |
| 7 | Signed key compare | **Falsified** — `uint` / unsigned `<` in decompile (`*param_3 < (uint)puVar4[3]`) |
| 8 | Vague stack arity | **Falsified** — three `RET 8` sites |
| 9 | Same as `Skill_CategoryCooldownMap_Insert` body | **Falsified** — different always-insert helper VA; peer pattern only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | double-nodes or never-insert |
| Equal-key **no** value write | **High** | wrongly assume upsert |
| Out pair `{it@+0, bool@+4}` | **High** | caller misreads inserted |
| ABI `RET 0x8` | **High** | stack smash |
| `FUN_00573510` = insert+rebalance | **High** | crash / size throw |
| `FUN_005ae050` = predecessor | **High** | wrong insert side |
| Key = uint @ +0x0c | **High** | wrong order |
| Product English for v1/v2 | **Tentative** | docs only |
| Runtime capture | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = map (ECX/EDI); head = *(this+4); walk root by key at node+0xC;
isnil = node+0x19; left=*n, right=n[2];
if goLeft && parent==leftmost: TreeInsert(…,1) → out{it,1};
else if goLeft: Predecessor(&parent);
if parent.key < key: TreeInsert(…,goLeft) → out{it,1};
else: out{parent,0}; // NO value copy
RET 0x8  (×3)
```

Live decompile 2026-07-29 ≡ raw capture 2026-07-23. Clean plate documents insert-or-find (raw body append-only).

---

## 4. Surviving contract for AutoCore

```
// Val12 map — insert-or-find, NOT insert-or-assign
InsertPair StdMap_InsertOrFind_Val12_UintKey(map, entry{key,v1,v2}):
  if key missing: node = InsertAndRebalance(...); return {node, true}
  else: return {existing, false}  // v1/v2 UNCHANGED

// Do not substitute ESI buynode 0046c6c0 into this chain — insert uses 005ae220.
// Inventory callers may pass inventory-specific keys; this unit stays generic map.
```

---

## 5. Open questions

1. Exact product map type for inventory grid consumers.  
2. Whether any caller depends on inserted==0 to refresh fields separately.  
3. Runtime / differential.

**Verdict:** **accept-with-gaps**
