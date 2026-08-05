# Review B (skeptical / adversarial): `aa_00567860` StdMap_InsertAlways_Val12_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-M) |
| **Counterpart** | `reviews/A_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is insert-or-find (prior W27-R parent note) | **Falsified** — no equal path; always insert; always `inserted=1` |
| 2 | Equal key returns existing / `inserted=0` | **Falsified** — equal goes right, still `FUN_00567450` |
| 3 | Unsigned key compare (like `00573810`) | **Falsified** — cast to `(int)` in compare |
| 4 | Enforces uniqueness (std::map insert) | **Falsified** — uniqueness not checked here |
| 5 | Insert helper is `00539210` / `00573510` | **Falsified** — sole callee `00567450` |
| 6 | Updates value fields on equal | **Falsified** — no equal branch at all |
| 7 | Product spawn-point-only logic in body | **Falsified** — pure map mutator; product is caller `00565950` |
| 8 | Same unit as `0053a1a0` | **Falsified** — different CF (find vs always) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert CF | **High** | wrongly port as unique map insert |
| Signed int key | **High** | sort order wrong vs uint peer |
| Out pair always inserted=1 | **High** | caller misread of bool |
| ABI `RET 8` | **High** | stack smash |
| `FUN_00567450` rebalance | **High** | crash / size throw |
| Product map type | **Tentative** | docs only |
| Runtime capture | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = map; head = *(this+4); walk root by signed key at node+0xC;
isnil = node+0x19; left=*n, right=n[2]; equal → right
ALWAYS TreeInsertAndRebalance_Val12 (00567450) → out{it,1}
RET 8
```

Live decompile 2026-07-29 ≡ raw capture 2026-07-23. No equal-key branch in either.

Correction to W27-R note "Uniqueness lives in parent `FUN_00567860`": **uniqueness does not live here** — this unit always inserts. Callers may assume unique keys by construction, or map is multimap-like.

---

## 4. Surviving contract for AutoCore

```
// Val12 map — ALWAYS insert by signed int key
InsertPair StdMap_InsertAlways_Val12_IntKey(map, entry{key,v1,v2}):
  walk by signed key (equal → right)
  node = InsertAndRebalance_Val12(...)   // FUN_00567450 → buynode 005ae220
  return {node, true}                    // always

// Do NOT merge with:
//   0053a1a0 InsertOrFindByIntKey (equal → {it,false})
//   00573810 InsertOrFind UintKey
// Do NOT treat as unique-map insert without caller guarantees.
```

---

## 5. Open questions

1. Product map type for the two inserts in `FUN_00565950` (spawn unpack).
2. Whether duplicate keys are ever inserted at runtime.
3. Runtime / differential.

**Verdict:** **accept-with-gaps**
