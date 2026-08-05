# Review B (skeptical / adversarial): `gfxIndexBufferImpl_Unserialize` @ `0x00989030`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989030` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00989030_gfxIndexBufferImpl_Unserialize.md` |
| **Verdict** | **accept-with-gaps** on CF/tags/versions; **needs-more-evidence** on FUN_* body readers |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Accepts any chunk version | **Falsified** — only 1 and 2; else invalid-version log |
| 2 | Version 2 always succeeds | **Falsified** — id helper fail returns `0xfffffffe` |
| 3 | Usage always 0x20 | **Falsified** — can be 0x18 from context flags |
| 4 | Lock failure ignored | **Falsified** — lock fail or null map → status −1 |
| 5 | v1 body layout fully visible in this function | **Overstated** — count read + create/lock/read via FUN_* |
| — | Runtime verified | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| INDX tag gate | High | Load wrong asset family |
| v1/v2 split + −2 id fail | High | Silent mesh load fail codes wrong |
| Device lock/unlock around fill | High | GPU corruption |
| Param roles (this / reader / context*) | Medium | Calling convention / wrong this |
| Plate triangle-list only | Medium | If strip assets appear, wrong topology assumption |

---

## 3. Surviving contract for AutoCore

```
gfxIndexBufferImpl_Unserialize(this, reader, context*) -> int:
  EnterChunkScope(reader)
  if tag != 0x494e4458: log; leave; return -1
  if version == 2:
    if id-helpers fail: return -2 (0xfffffffe)
  else if version != 1: log; leave; return -1
  read count; usage = (ctx soft-flag) ? 0x18 : 0x20
  CreateIB(count, usage)
  Lock(device, 0x800); read indices; unlock helper
  leave scope; return status (-1 on lock/map fail)
```

---

## 4. Open questions

1. Semantic of `param_3` (parent material/mesh context) for 0x18 vs 0x20.
2. Whether v1 always forces index size 2 (plate yes; not re-proved in body).
3. Pair with Serialize `0x00988a10` for round-trip Autocore writer.

**Verdict:** **accept-with-gaps** — behavioral map for INDX load; do not seal FUN_* as final wire codecs.
