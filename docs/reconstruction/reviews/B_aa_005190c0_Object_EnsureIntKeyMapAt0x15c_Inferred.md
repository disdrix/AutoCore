# Review B (skeptical / adversarial): `aa_005190c0` Object_EnsureIntKeyMapAt0x15c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005190c0` |
| **VA** | `0x005190c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY dual B — WQ9R-E) |
| **Counterpart** | `reviews/A_aa_005190c0_Object_EnsureIntKeyMapAt0x15c_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always allocates | No cache | **Falsified** — early out when `+0x15C != 0` |
| 2 | This is a skill bank vector | WQ-009 skill residual | **Falsified as vector** — 0xC map header + tree sentinel; consumers use `Map_LowerBoundFindByIntKey` |
| 3 | Free function | many xrefs | **Falsified** — ECX host (`8B D9`); field `+0x15C` |
| 4 | Product name from scaffold chain | prior alias | **Holds as false** — caller-chain name is not product |
| 5 | Same as `Object_EnsureFxMasterFromDef` | both Ensure* | **Distinct** — FX master is 8-byte catalog @ `+0x88`; this is int-key map @ `+0x15C` |
| 6 | `FUN_0040f400` returns ready map | sentinel factory | **Partial** — factory zeros links + stamps bytes; ensure re-stamps is_nil=1 and self-links + size 0 |
| 7 | OOM leaves garbage | new fail | **Falsified** — explicit null store path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lazy `+0x15C` ensure | **High** | Double free / leak on dtor |
| Map vs vector classification | **High** | Wrong port container |
| Sentinel is_nil layout | **High** | Tree walk crash |
| Req-aggregate consumer role | **Probable** | Wrong system folder |
| Product type name | **Tentative** | Naming only |

---

## 3. Cross-check against raw / live

```
if (host[+0x15C]) return it
map = new(0xC) or null
if map: sentinel=FUN_0040f400(); wire empty tree; size=0
host[+0x15C] = map
return host[+0x15C]
```

Live ≡ raw scaffold ≡ clean. Callers clear/rebuild via myhead+size then insert int keys.

---

## 4. Surviving contract for AutoCore

```
map = Object_EnsureIntKeyMapAt0x15c_Inferred(host);
// Post: host[+0x15C] == map
// Post: map may be null (OOM)
// Post: if non-null, empty int-key tree ready for Map_LowerBoundFindByIntKey / insert
// Pair free: Object_SharedBase_Dtor path frees +0x15C
```

---

## 5. Open questions

1. Entry value layout beyond key/`+0x10` count seen in `FUN_0052d450`.
2. Whether all hosts with `+0x15C` share Object_SharedBase or only some.

**Verdict:** **accept-with-gaps**
