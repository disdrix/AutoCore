# Review B (skeptical / adversarial): `aa_0054eb20` SkillElementTypeMap_InsertOrFind

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054eb20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054eb20_SkillElementTypeMap_InsertOrFind.md` |
| **Verdict** | **accept-with-gaps** — scaffold gaps on ABI/node/helpers/caller **closed**; runtime/diff remain |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Formats UI / skill tooltips | **Falsified** — pure map mutator; strings only in insert-helper throw path |
| 2 | Always allocates a new node | **Falsified** — equal-key path returns existing, `inserted=0` |
| 3 | Insert **updates** mapped value when key exists | **Falsified** — third path only stores out-pair; no stores to `node+0x10` |
| 4 | Same function as `Map_InsertOrFind_IntKey` (`005d2360`) | **Overstated** — same CF family / isnil layout; **different** insert helper VA (`0054de50` vs `005d20b0`) and callers |
| 5 | First stack arg is “the map” | **Falsified** — ECX is map; first stack is **out pair** |
| 6 | `FUN_005a2850` is tree insert / rebalance | **Falsified** — predecessor walk only |
| 7 | `FUN_0054de50` is lower_bound | **Falsified** — allocates, size++, rebalances, may throw `"map/set<T> too long"` |
| 8 | Node size / value width unknown | **Falsified this pass** — insert path uses `FUN_006173a0` `new(0x18)` / two dwords |
| 9 | Many unknown callers | **Falsified** — only `FUN_0054a640` (39 sites) |
| 10 | Read-only find | **Falsified** — insert paths call `FUN_0054de50` |
| 11 | Finished PDB / RTTI name | **Overstated** — structural + domain name only |
| 12 | Owning map of heap factories on equal-key reinsert | **Unproven / N/A** — equal path does not replace pointer; catalog is one-shot |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | Double factory / wrong type lookup |
| Equal-key **no** value write | **High** | Assume re-register replaces factory via this call alone |
| Node `+0x0C` key / `+0x10` mapped / `+0x15` isnil | **High** | Wrong type-id resolution |
| Node size **0x18** | **High** | Heap corruption if ported wrong |
| Out pair `{it@+0, bool@+4}` | **High** | Caller misreads inserted |
| ABI `RET 0x8` / 2 stack args | **High** | Stack smash on call |
| `FUN_0054de50` = insert+rebalance | **High** | Crash / size throw path |
| `FUN_005a2850` = predecessor | **High** | Mis-order insert side |
| Sole static caller catalog ×39 | **High** | Wrong domain ownership |
| Helper **product** English names | **Tentative** | Docs only |
| Dynamic/fn-ptr call sites | **Open** | Missed consumers |
| Runtime capture / bit-exact | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = map (ECX); head = *(this+4); walk root by key at node+0xC;
isnil = node+0x15; left=*n, right=n[2];
if goLeft && parent==leftmost: TreeInsert(…,1) → out{it,1};   // FUN_0054de50
else if goLeft: Predecessor(&parent);                        // FUN_005a2850
if parent.key < key: TreeInsert(…,goLeft) → out{it,1};
else: out{parent,0}; // NO mapped copy
RET 0x8  (×3)

Caller FUN_0054a640 SkillElementFactory_RegisterCatalog:
  39 call sites; each arm builds {typeId, factoryObj*} then insert
```

Live decompile 2026-07-29 ≡ raw capture 2026-07-23. Bytes confirm isnil `+0x15`, out-bool `+4`, `RET 8`.

**Decompiler naming trap:** treat printed prototype loosely; trust body + `ret 8` for stack arity.

---

## 4. Surviving contract for AutoCore

```
// Int-key / pointer-mapped map insert-or-find — NOT insert-or-assign
// Used only by skill-element factory catalog registration (bootstrap).
// Equal type-id → return existing factory node; do not replace pointer.
// Node 0x18; isnil +0x15; key +0x0C; mapped +0x10; color +0x14.
// ABI: thiscall + RET 8; out {it*, inserted@+4}.
```

**Verdict:** **accept-with-gaps**
