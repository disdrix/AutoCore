# Review B (skeptical / adversarial): `Client_SetAnnouncementLabelTextures` @ `0x0090b9c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090b9c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0090b9c0_Client_SetAnnouncementLabelTextures.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Generates announcement content | Falsified — textures only |
| 2 | Server broadcast | Falsified — client art bind |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Correct .dds per category | High | Wrong announce chrome |

---

## 3. Cross-check against raw

```
SetAnnouncementLabelTextures: bind mission/level/item/medal label .dds.
```

---

## 4. Surviving contract for AutoCore

```
SetAnnouncementLabelTextures: client announce UI art.
```

---

## 5. Open questions

1. Map category enum → texture.

**Verdict:** **accept**
