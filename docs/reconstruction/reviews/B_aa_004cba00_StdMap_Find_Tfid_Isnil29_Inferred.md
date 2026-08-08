# Review B (skeptical / adversarial): `aa_004cba00` StdMap_Find_Tfid_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9G-G) |
| **Counterpart** | `reviews/A_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is pure lower_bound only | **Falsified** — equality gate after `FUN_004cb4b0`; writes end on miss |
| 2 | This is insert-or-find / `operator[]` | **Falsified** — no buynode/link; callers may separately call `004cc400` |
| 3 | isnil Val12 / +0x19 family | **Falsified** — no isnil walk here; lower_bound is isnil@+0x29 |
| 4 | bare RET / one stack arg | **Falsified** — `C2 08 00` (out + key) |
| 5 | Skill CNDHash bucket lookup | **Falsified** — callee is TFID tree lower_bound; not skill hash table |
| 6 | Key is single int | **Falsified** — 8-byte lo@+0x10 hi@+0x14 |
| 7 | VOG_DEBUG_STOP scaffold is product | **Falsified** — chain name only |
| 8 | “TFID” PDB-sealed | **Careful** — structural from consumers + lower_bound dual; name **Inferred** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| find vs lower_bound vs insert | **High** | Wrong miss/insert semantics |
| RET 8 / thiscall | **High** | Stack imbalance |
| key order / signed hi | **High** | Missed hits |
| TFID product English | **Med** structural | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against lower_bound dual

```
// W31-N B: consumers apply equality outside lower_bound
// FUN_004cba00: lb = LowerBound; if lb!=end && node.key <= key → out=lb else end
// Confirms residual find shell closed here.
```

`FUN_00807550` assembly: `MOV ECX,ESI` map `@+0x244`; key TFID `@+0x160`; after call compares `*out` to head and reads `node+0x20`.

---

## 4. Surviving contract for AutoCore

```
// Port as pure find (not insert, not lower_bound alone):
void StdMap_Find_Tfid_Isnil29(Map* m, Node** out, const TfidKey* k) {
  Node* lb = StdMap_LowerBound_Tfid_Isnil29(m, k);
  if (lb != m->head && !(k < lb->key)) *out = lb;
  else *out = m->head;
}
// RET 8; ECX=map. Do not merge with skill CNDHash find paths.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/role. Product map type residual → **accept-with-gaps**.
