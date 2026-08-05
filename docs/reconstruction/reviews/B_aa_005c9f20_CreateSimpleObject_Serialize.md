# Review B (skeptical / adversarial): `aa_005c9f20` CreateSimpleObject_Serialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c9f20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005c9f20_CreateSimpleObject_Serialize.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Different opcode than 0x2012 | Falsified — hard 0x2012 |
| 2 | Same this-base as Variant2 | Falsified — -0xbc vs -0x10c |
| 3 | Server-only path | Falsified — client identify force etc. |
| 4 | Leaves IsIdentified from source | Falsified — forces 1 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0xD8 field order | High | Client desync / ghost create fail |
| this-base offsets | High | Garbage CBID/HP |
| Variant split | High | Wrong serializer for char create |

---

## 3. Cross-check against raw

```
CreateSimpleObject_Serialize(obj, buf):
  if !buf: return 0
  buf.opcode = 0x2012
  pack CBID/HP/factions/prefixes/pos/rot/... per 0xD8 map
  force identified=1; | flag 0x10; FUN_00512670
Clean CF ≡ raw; residual FUN + some offset labels.
```

---

## 4. Surviving contract for AutoCore

```
Primary SimpleObject create serializer for AutoCore packet parity.
  Keep layout identical to CreateSimpleObjectPacket.
```

---

## 5. Open questions

1. Hex-diff one live 0x2012 vs clean field order.
2. Map FUN_00512670 side effects.

**Verdict:** **accept-with-gaps**
