# Review B (skeptical / adversarial): `aa_004309c0` StdMap_StringKey_InsertOrFind

| Field | Value |
|---|---|
| **Stable ID** | `aa_004309c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W21-P) |
| **Counterpart** | `reviews/A_aa_004309c0_StdMap_StringKey_InsertOrFind.md` |
| **Scratch** | `tmp/a_004309c0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Plain `__thiscall` map method | **Falsified** — map is **stack** formal; key EAX; out EBX; `RET 4` |
| 2 | Insert-or-**assign** updates value on hit | **Falsified** — equal path only stores out-pair with `inserted=0` |
| 3 | `FUN_004313d0` is insert | **Falsified** — predecessor walk only |
| 4 | isnil at `+0x19` like int maps | **Falsified** — string-key nodes use isnil **`+0x2D`** |
| 5 | Decompiler void return | **Overstated** — returns EBX (out pair*) in EAX |
| 6 | Many unknown callers | **Falsified** — exactly 2 xrefs |
| 7 | Finished product type names | **Overstated** — layout recovered; owner types open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | Wrong map semantics / double nodes |
| Equal-key no value write | **High** | Mistaken upsert model |
| ABI stack+EAX+EBX / `RET 4` | **High** | Stack smash / bad out-pair |
| isnil `+0x2D` / key `+0x0C` | **High** | Corrupt walk |
| `FUN_00430b60` = insert+rebalance | **High** | Size throw / RB wrong |
| `FUN_004313d0` = predecessor | **High** | Wrong insert side |
| Mapped value offsets | **Medium** | Consumer only (`+0x28`) |
| Runtime capture | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
map = stack0; key = EAX; out = EBX
header = *(map+4); cur = header->_Parent; goLeft=1
while !isnil(cur@+0x2D): goLeft = key < cur.key@+0xC; parent=cur; cur=L/R
if goLeft && parent==header->_Left: TreeInsert(...,1) → {it,1}
else if goLeft: Pred(&parent)
if parent.key < key: TreeInsert(...,goLeft) → {it,1}
else: {parent,0}
RET 4 ×3
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean plate updated for ABI + insert-or-find wording.

---

## 4. Surviving contract for AutoCore

```
// String-keyed map insert-or-find (not assign)
pair{it, inserted} = StdMap_StringKey_InsertOrFind(map, keyString)
// if inserted: new node, rebalanced
// else: existing node, mapped value UNCHANGED

// Do not model as thiscall-only; register key/out formals are required.
// Node isnil/color differ from int-key maps (+0x2D/+0x2C vs +0x19/+0x18).
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI sealed; gaps are product naming and value layout → **accept-with-gaps**.
