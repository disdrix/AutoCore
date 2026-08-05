# Review B (skeptical / adversarial): `aa_004cd670` CVOGSectorMap_InitGenerators

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004cd670_CVOGSectorMap_InitGenerators.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Runtime loot roll | Falsified — singleton ctor only |
| 2 | Only creature gen | Falsified — loot gen too |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Global slots | High | Null generators |
| Ctor size 0xbc | Medium | Wrong layout |

---

## 3. Cross-check against raw

```
InitGenerators: DAT_00b037ec=CreatureGen; DAT_00b037e8=LootGen.
```

---

## 4. Surviving contract for AutoCore

```
Must run before loot/spawn use. AutoCore sector bring-up order.
```

---

## 5. Open questions

1. Assert non-null after map enter.

**Verdict:** **accept-with-gaps**
