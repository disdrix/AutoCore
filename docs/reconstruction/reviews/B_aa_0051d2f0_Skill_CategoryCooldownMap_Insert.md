# Review B (skeptical / adversarial): `aa_0051d2f0` Skill_CategoryCooldownMap_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d2f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_0051d2f0_Skill_CategoryCooldownMap_Insert.md` |
| **Scratch** | `reviews/a_0051d2f0.md` |
| **Verdict** | **accept-with-gaps** — prior open node/helper/update path **closed**; runtime/diff remain |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Formats tooltips | **Falsified** — pure map mutator |
| 2 | Always allocates new | **Falsified** — equal key returns existing, `inserted=0` |
| 3 | Insert **updates** start/duration when key exists | **Falsified** — third path stores only out-pair; no stores to `+0x10/+0x14` |
| 4 | `FUN_005ae050` is "tree insert" | **Falsified** — predecessor walk only (`0x005ae050` body) |
| 5 | Node field offsets unknown / Tentative | **Falsified this pass** — sealed via `FUN_005ae220` `new(0x1c)` + GetRemaining |
| 6 | Finished PDB types | **Overstated** — layout recovered; no PDB names required |
| 7 | Many unknown callers | **Falsified** — only InsertCategoryCooldown + CastAgain ctor xrefs |
| 8 | Stack arity vague / decomp only | **Falsified** — three `RET 0x8` sites |
| 9 | Concurrency-safe shared map | **Unproven** — unit has no locks; client ST assumption open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | CD never arms or double-nodes |
| Equal-key **no** value write | **High** | Wrongly assume re-cast refreshes category CD |
| Node `+0x0C/+0x10/+0x14` | **High** | GetRemaining / UI gauge wrong |
| Out pair `{it@+0, bool@+4}` | **High** | Caller misreads inserted |
| ABI `RET 0x8` | **High** | Stack smash on call |
| `FUN_0051c1c0` = insert+rebalance | **High** | Crash / size throw path |
| `FUN_005ae050` = predecessor | **High** | Mis-order insert side |
| Helper **product** English names | **Tentative** | Docs only |
| Server authority parity | **Open** | Desync if server differs |
| Runtime capture | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = map (ECX); head = *(this+4); walk root by key at node+0xC;
isnil = node+0x19; left=*n, right=n[2];
if goLeft && parent==leftmost: TreeInsert(…,1) → out{it,1};
else if goLeft: Predecessor(&parent);
if parent.key < key: TreeInsert(…,goLeft) → out{it,1};
else: out{parent,0}; // NO value copy
RET 0x8  (×3)
Node ctor 0x005ae220: new(0x1c); copy 3 dwords; color@+0x18; isnil@+0x19=0
```

Live decompile 2026-07-29 ≡ raw capture 2026-07-23. Clean plate updated for insert-or-find wording (raw body append-only).

---

## 4. Surviving contract for AutoCore

```
// CategoryCooldownMap — insert-or-find, NOT insert-or-assign
InsertPair Skill_CategoryCooldownMap_Insert(map, entry{key,start,duration}):
  if key missing: node = new 0x1C; copy entry into +0x0C..+0x14; rebalance; return {node, true}
  else: return {existing, false}  // start/duration UNCHANGED

// Higher-level arm (InsertCategoryCooldown / CastAgain ctor):
  if categoryId != -1:
    entry = { categoryId, g_dwClientTickMs, durationMs }
    Insert(GetCategoryCooldownMap(owner), entry)  // ignore inserted
// Refresh-while-active requires erase (GetRemaining expiry path) or a different writer — not this unit.

AutoCore cast pipeline: category CD map must use same node layout and insert-or-find semantics
or UI/local validate remaining will desync after re-arm attempts on live keys.
```

---

## 5. Open questions

1. Optional rename of `FUN_0051c1c0` / `FUN_005ae050` / `FUN_005ae220` in Ghidra + NAMING.
2. Live trace that equal-key re-insert leaves `+0x10/+0x14` unchanged (asm-sealed; runtime optional).
3. Diff vs any server-side category CD map.
4. Bit-exact vs retail EXE image.

**Verdict:** **accept-with-gaps** — CF + ABI + node layout + helper roles + no-update-on-equal **sealed**; runtime/diff/server open.
