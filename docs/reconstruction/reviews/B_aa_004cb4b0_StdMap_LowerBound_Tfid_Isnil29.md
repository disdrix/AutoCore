# Review B (skeptical / adversarial): `aa_004cb4b0` StdMap_LowerBound_Tfid_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-N) |
| **Counterpart** | `reviews/A_aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md` |
| **Scratch** | `tmp/a_004cb4b0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is exact find / `operator[]` | **Falsified** — no equality gate; returns lower_bound cand; consumers gate |
| 2 | isnil at +0x15 / Val12 +0x19 | **Falsified** — bytes test `+0x29` |
| 3 | Int-only key at node[3] | **Falsified** — 8-byte (lo@+0x10, hi@+0x14) with signed hi |
| 4 | bare RET / no stack arg | **Falsified** — `C2 04 00` |
| 5 | Mutates tree / inserts | **Falsified** — leaf read-only walk |
| 6 | Key compare is string/char | **Falsified** — dword/int compares only |
| 7 | VOG_DEBUG_STOP scaffold plate is product | **Falsified** — chain name only |
| 8 | “TFID” in name is PDB-sealed | **Careful** — structural: consumers pass TFID pairs + `TFID_EqualsObjectId`; name is **Inferred** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| lower_bound vs find | **High** | Wrong insert/miss semantics |
| isnil +0x29 | **High** | Infinite walk / wrong end |
| key offsets + order | **High** | Missed hits |
| RET 4 | **High** | Stack imbalance |
| TFID product English | **Med** structural / **Low** plate | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against consumers

```
// FUN_004cba00: lb = FUN_004cb4b0(key); if lb!=end && node.key <= key → out=lb else end
// FUN_004c8970: map host = obj+0x154 (head +0x158); hit → *(node+0x20)
// FUN_004cc400: lb then insert path; return node+0x20
// FUN_005a0470: head at this+0x248; erase on hit
```

Exact-match / insert / erase are **outside** this unit. Port as pure `_Lbound`.

---

## 4. Surviving contract for AutoCore

```
// Port as pure lower_bound:
Node* StdMap_LowerBound_Tfid_Isnil29(Map* m, const TfidKey* k) {
  // head@m+4; isnil@node+0x29; key lo@+0x10 hi@+0x14 (hi signed)
  // return first node with !(node.key < *k), or head
}
// Callers must equality-gate before reading +0x20.
// Do not substitute int-key lower_bound helpers (different isnil/key packing).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/layout/role. Product map type residual → **accept-with-gaps**.
