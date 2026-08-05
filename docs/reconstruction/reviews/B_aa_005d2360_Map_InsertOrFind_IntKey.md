# Review B (skeptical / adversarial): `aa_005d2360` Map_InsertOrFind_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d2360` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005d2360_Map_InsertOrFind_IntKey.md` |
| **Verdict** | **accept-with-gaps** — scaffold gaps on ABI/node/helpers/caller **closed**; runtime/diff remain |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Formats UI / skill tooltips | **Falsified** — pure map mutator; no strings beyond throw path in callees |
| 2 | Always allocates a new node | **Falsified** — equal-key path returns existing, `inserted=0` |
| 3 | Insert **updates** mapped value when key exists | **Falsified** — third path only stores out-pair; no stores to `node+0x10` |
| 4 | Ghidra signature has 3 stack args (`pMap,pOutPair,pKey`) | **Overstated / wrong** — three `RET 0x8` = **two** stack dwords; third `pKey` never used in body |
| 5 | First stack arg is “the map” | **Falsified** — ECX is map; first stack is **out pair** written as `{ptr, bool}` |
| 6 | `FUN_005a2850` is tree insert / rebalance | **Falsified** — predecessor walk only (same role as `FUN_005ae050` for category-CD map) |
| 7 | Same node layout as `Skill_CategoryCooldownMap_Insert` | **Falsified** — here isnil `+0x15` / size `0x18`; category CD isnil `+0x19` / size `0x1C` |
| 8 | Node size / value width unknown | **Falsified this pass** — `FUN_006173a0` `new(0x18)` copies **two** dwords from value* |
| 9 | Many unknown callers | **Falsified** — only `NPC_TryCastSkillFromSet` @ `0x005d18f7` |
| 10 | Read-only lower_bound | **Falsified** — insert paths call `FUN_005d20b0` |
| 11 | Finished PDB / RTTI name | **Overstated** — structural name only; no product string on this VA |
| 12 | Concurrency-safe shared map | **Unproven** — no locks in unit; client single-thread assumption open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | Wrong timer arm / double nodes |
| Equal-key **no** value write | **High** | Assume re-cast refreshes deadline via this call alone |
| Node `+0x0C` key / `+0x10` mapped / `+0x15` isnil | **High** | Wrong timer read in lower_bound/erase path |
| Node size **0x18** | **High** | Heap corruption if ported wrong |
| Out pair `{it@+0, bool@+4}` | **High** | Caller misreads inserted |
| ABI `RET 0x8` / 2 stack args | **High** | Stack smash on call |
| `FUN_005d20b0` = insert+rebalance | **High** | Crash / size throw path |
| `FUN_005a2850` = predecessor | **High** | Mis-order insert side |
| Single static caller + map @ AI `+0x98` | **High** | Wrong domain ownership |
| Helper **product** English names | **Tentative** | Docs only |
| Dynamic/fn-ptr call sites | **Open** | Missed consumers |
| Runtime capture / bit-exact | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = map (ECX); head = *(this+4); walk root by key at node+0xC;
isnil = node+0x15; left=*n, right=n[2];
if goLeft && parent==leftmost: TreeInsert(…,1) → out{it,1};
else if goLeft: Predecessor(&parent);          // FUN_005a2850
if parent.key < key: TreeInsert(…,goLeft) → out{it,1};  // FUN_005d20b0
else: out{parent,0}; // NO value copy
RET 0x8  (×3 @ +0x6E, +0xA5, +0xB6)

Node ctor 0x006173a0: new(0x18);
  left/parent/right from args; key=*val; mapped=val[1];
  color@+0x14 = param; isnil@+0x15 = 0

Caller 0x005d18f7 NPC_TryCastSkillFromSet:
  map = AI+0x98; value stack {nSkillSetIndex, tick+delay};
  lower_bound/erase siblings on same shell for expiry
```

Live decompile 2026-07-29 ≡ raw capture 2026-07-23. Bytes confirm isnil `+0x15`, key `+0x0C`, out-bool `+4`, `RET 8`.

**Decompiler naming trap:** parameter list `(this, pMap, pOutPair, pKey)` inverts roles of stack slots and invents unused `pKey`. Trust body + `ret 8`, not the printed prototype.

---

## 4. Surviving contract for AutoCore

```
// Int-int map insert-or-find — NOT insert-or-assign
InsertPair Map_InsertOrFind_IntKey(map, value{key, mapped}):
  if key missing: node = new 0x18; key@+0x0C; mapped@+0x10; rebalance; return {node, true}
  else: return {existing, false}  // mapped UNCHANGED

// NPC post-cast timer (only static consumer):
  after CastSkillOnTarget success:
    value = { nSkillSetIndex, g_dwClientTickMs + wUsPostCastDelayMs }
    Map_InsertOrFind_IntKey(ai+0x98, value)
  entry gate uses Map_LowerBoundFindByIntKey + Map_EraseNode_IntKey on same shell
  when g_dwClientTickMs > node.mapped (+0x10)

// Port note: do NOT reuse CategoryCooldown node (0x1C / isnil+0x19) for this map.
```

If AutoCore ports NPC skill-set cast cooldowns, this layout and insert-or-find semantics are required or timer expiry / double-insert behavior will desync from client AI.

---

## 5. Open questions

1. Optional Ghidra prototype fix (drop phantom `pKey`; rename stack args to `pOut` / `pVal`).
2. Optional helper renames in Ghidra + `NAMING_REGISTRY`.
3. Dynamic call discovery (unlikely; no evidence).
4. Live trace that equal-key re-insert leaves `+0x10` unchanged (asm-sealed; runtime optional).
5. Bit-exact vs retail EXE image.

**Verdict:** **accept-with-gaps** — CF + ABI + node **0x18** + helper roles + no-update-on-equal + single caller **sealed**; runtime/diff/dynamic-xrefs open.
