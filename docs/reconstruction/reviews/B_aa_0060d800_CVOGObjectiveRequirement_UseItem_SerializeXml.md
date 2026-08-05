# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_UseItem_SerializeXml` @ `0x0060d800`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d800` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060d800_CVOGObjectiveRequirement_UseItem_SerializeXml.md` |
| **Verdict** | **accept-with-gaps on field map; COM loop tentative** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Serialize means write-only export | **Overstated — body is load/parse from COM children** |
| 2 | All offsets sealed without unaff noise | **Overstated — loop bounds use unaff_*** |
| 3 | PrimaryUseText stored at +0x20 directly | **Partial — pointer/string object helpers** |
| 4 | Missing tags silently error | **Falsified — unknown tags fall through LAB without assign** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tag/offset table | High | Wrong mission XML load |
| Loop/COM scaffolding | Medium | Fail parse entirely |
| Name Serialize vs Unserialize | Medium | Docs confusion |

---

## 3. Surviving contract for AutoCore

```
UseItem_LoadXml(req, comNode):
  for each child property name:
    map tag → field offset (Primary*, Secondary*, Progress*, Complete*, RepeatCount, ContinentID)
```

---

## 4. Open questions

1. Rename to Unserialize/LoadXml if writers agree.
2. Cross-check AutoCore UseItem XML fields.

**Verdict:** accept-with-gaps on field map; COM loop tentative.
