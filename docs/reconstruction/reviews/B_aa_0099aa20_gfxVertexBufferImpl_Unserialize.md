# Review B (skeptical / adversarial): `gfxVertexBufferImpl_Unserialize` @ `0x0099aa20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099aa20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0099aa20_gfxVertexBufferImpl_Unserialize.md` |
| **Verdict** | **accept-with-gaps** on version tree; **needs-more-evidence** on legacy v1 element codecs |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Only modern v3 assets load | **Falsified** — v1 and v2 full paths still present |
| 2 | Soft-skip returns −1 | **Falsified** — FUN_00767120 non-zero returns **0** |
| 3 | Id fail returns −1 | **Falsified** for v3 — returns **−2** |
| 4 | All attributes always floats | **Falsified** — usage 2/10 use byte path FUN_00436900 |
| 5 | Stride table is sealed in this function | **Overstated** — plate commentary; not computed here |
| — | Runtime verified | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tag + version tree | High | Load rejects valid retail |
| Soft-skip vs hard fail codes | High | Wrong asset pipeline behavior |
| Lock/create/bulk v2/v3 path | High | Mesh GPU fill bugs |
| v1 8-byte element walk | High (structure) / Medium (type meanings) | Legacy mesh import |
| Param packing (this/reader/context) | Medium | Wrong call sites |

---

## 3. Surviving contract for AutoCore

```
gfxVertexBufferImpl_Unserialize(this, reader, ctx) -> int:
  EnterChunkScope(reader)
  if tag != 0x56455254: log; leave; return -1
  if soft-skip(): leave; return 0
  if version == 1: legacy per-element decode → success 0 or fail -1
  else if version == 3:
    if id-helpers fail: return -2
  else if version != 2: log; return -1
  // v2 and v3 body:
  load DECL; CreateVB; Lock(0x800); bulk-read; unlock/cleanup
  return 0 on clean residual else -1
```

---

## 4. Open questions

1. What condition does FUN_00767120 implement (already-loaded? stream empty?).
2. Map usage cases 0–6/2/10 to D3DDECLUSAGE fully.
3. Round-trip with Serialize `0x009994c0` (writes v3 only).

**Verdict:** **accept-with-gaps** — primary Autocore need is v2/v3 path; v1 kept as compatibility map.
