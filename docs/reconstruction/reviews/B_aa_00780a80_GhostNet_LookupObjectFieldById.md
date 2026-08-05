# Review B (skeptical / adversarial): `aa_00780a80` GhostNet_LookupObjectFieldById

| Field | Value |
|---|---|
| **Stable ID** | `aa_00780a80` |
| **VA** | `0x00780a80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00780a80_GhostNet_LookupObjectFieldById.md` |
| **Evidence** | Live decompile; 4 ghost unpack callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always hashes id | **Falsified** | +0x208==0 bypasses hash |
| 2 | Returns 0 on miss | **Falsified** | returns 0xFFFFFFFF |
| 3 | Matches any node with same id | **Falsified** | requires `(flags&0x3C)==0` |
| 4 | Bucket count 256 | **Falsified** | mask 0x3FF → 1024 |
| 5 | Clean ≠ raw | **Falsified** | ≡ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hash + flag gate + −1 miss | **High** | ghost object mis-bind |
| Passthrough +0x20 path | **High CF** | wrong field if mode flipped |
| Returned field semantics | **Medium** | wrong consumer cast |
| Runtime | **Open** | — |

---

## 3. Surviving contract

```
Lookup(host, id):
  if id==0: return -1
  if host.mode(+0x208)==0: return *(id+0x20)
  for n in host.buckets[id & 0x3FF]:
    if n.key==id and (n.flags & 0x3C)==0: return n.field12
  return -1
```

**Verdict:** **accept-with-gaps**
