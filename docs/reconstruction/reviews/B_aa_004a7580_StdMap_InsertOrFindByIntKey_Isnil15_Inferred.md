# Review B (skeptical / adversarial): `aa_004a7580` StdMap_InsertOrFindByIntKey_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W23-F) |
| **Counterpart** | `reviews/A_aa_004a7580_StdMap_InsertOrFindByIntKey_Isnil15_Inferred.md` |
| **Scratch** | `tmp/a_004a7580.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Insert-or-**assign** updates value on hit | **Falsified** — equal path only stores out-pair with `inserted=0` |
| 2 | Same node layout as `aa_00569320` (isnil `+0x49`) | **Falsified** — this unit isnil **`+0x15`**; twin is larger value_type |
| 3 | `FUN_005a2850` is insert | **Falsified** — pure predecessor walk |
| 4 | cdecl / no stack cleanup | **Falsified** — **`ret 8`** ×3 |
| 5 | Void return is wrong / EAX meaningful | **Overstated risk** — out-pair is memory-written; ret 8 sealed |
| 6 | Only one FX caller | **Falsified** — exactly **3** xrefs |
| 7 | Product name "FxEventMap_…" required | **Overstated** — structural StdMap name OK; consumers are FX |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | Wrong map semantics / double nodes |
| Equal-key no value write | **High** | Mistaken upsert model |
| ABI thiscall / `RET 8` | **High** | Stack smash / bad out-pair |
| isnil `+0x15` / key `+0x0C` | **High** | Corrupt walk |
| `FUN_004a6d80` = insert+rebalance | **High** | Size throw / RB wrong |
| `FUN_005a2850` = predecessor | **High** | Wrong insert side |
| Mapped value offsets | **Medium** | consumer-side only |
| Runtime capture | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
map=ECX; out=stack0; pKey=stack1
header=*(map+4); cur=header->_Parent; goLeft=1
while !isnil(cur@+0x15): goLeft=*pKey < cur.key@+0xC; parent=cur; cur=L/R
if goLeft && parent==header->_Left: TreeInsert(...,1) → {it,1}
else if goLeft: Pred(&parent)
if parent.key < *pKey: TreeInsert(...,goLeft) → {it,1}
else: {parent,0}
RET 8 ×3
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean plate updated for isnil15 + twin note.

---

## 4. Surviving contract for AutoCore

```
// Int-keyed map insert-or-find (not assign); isnil @ +0x15
pair{it, inserted} = StdMap_InsertOrFindByIntKey_Isnil15(map, pKey)
// if inserted: new node, rebalanced via FUN_004a6d80
// else: existing node, mapped value UNCHANGED

// Do not confuse with aa_00569320 (isnil +0x49) — different value_type size.
// FX callers use this for eventId→fx style maps.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI sealed; only residual is product naming → **accept**.
