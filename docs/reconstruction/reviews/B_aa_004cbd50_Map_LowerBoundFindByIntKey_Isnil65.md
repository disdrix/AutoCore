# Review B (skeptical / adversarial): `aa_004cbd50` Map_LowerBoundFindByIntKey_Isnil65

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbd50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-O) |
| **Counterpart** | `reviews/A_aa_004cbd50_Map_LowerBoundFindByIntKey_Isnil65.md` |
| **Scratch** | `tmp/a_004cbd50.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure STL `lower_bound` returning first ≥ without equality | **Falsified** — post-gate `cand.key <= *pKey` with walk ⇒ exact; miss writes end |
| 2 | Insert / rebalance helper | **Falsified** — leaf; no alloc; only writes `*pOut` |
| 3 | cdecl / no this | **Falsified** — ECX loads `this+4`; `ret 8` thiscall |
| 4 | isnil at +0x15 like `Map_LowerBoundFindByIntKey` | **Falsified** — bytes `80 78 65 00` → **+0x65** |
| 5 | Key is float compare (FUCOM) | **Falsified** — integer `cmp` of dwords at +0x0C |
| 6 | Returns node in EAX only | **Overstated** — writes `*pOut`; EAX not sealed as return |
| 7 | Same layout as char-key helper | **Falsified** — different isnil (+0x21 vs +0x65) and key width |
| 8 | Product name is retail string | **Open** — structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Exact-find CF | **High** | Wrong miss/hit in AI profile lookup |
| thiscall ret 8 | **High** | Stack imbalance |
| isnil/key offsets | **High** | Corrupt walk / wrong tree family |
| Leaf | **High** | Missed side effects |
| Float-key dword order | **Medium** | Breaks if negative keys used |
| Product English | **Open** | Naming only |

---

## 3. Cross-check against raw + bytes

```
PUSH ECX (scratch frame)
end=[ECX+4]; root=[end+4]
if isnil(root)==0: lower_bound walk on signed key @+0xC
if cand!=end && key<=search: *pOut=cand; POP EDI; POP ECX; RET 8
*pOut=end; POP EDI; POP ECX; RET 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Five callers all AI/map-select paths.

---

## 4. Surviving contract for AutoCore

```
// Exact map find (node or end) — not insert, not pure lower_bound API:
Map_LowerBoundFindByIntKey_Isnil65(map, &it, &keyDword);
if (it == map->head) { /* miss */ }
// Layout-specific: isnil @ +0x65; do not reuse +0x15/+0x1d helpers on this tree.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/layout sealed; product name + float-key edge residual → **accept**.
