# Review B (skeptical / adversarial): `aa_0052f650` CVOGCharacter_SerializeCreatePacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052f650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0052f650_CVOGCharacter_SerializeCreatePacket.md` |
| **Verdict** | **accept-with-gaps** on CF skeleton; **needs-more-evidence** on full field map |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Trivial empty serializer | **Falsified — huge body** |
| 2 | Skips simple-object base | **Falsified — calls variant2 first** |
| 3 | Finished exact wire map | **Overstated — needs dual with Apply** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base-then-character order | High | Incompatible create packets |
| Field ordering vs Apply | High | Login desync |
| Buffer null behavior | Tentative | Crash vs skip |

---

## 3. Cross-check against raw

```
CreateSimpleObject_SerializeVariant2(...);
if !buffer: return 0;
... large character field serialize ...
Clean preserves call order; field names incomplete.
```

---

## 4. Surviving contract for AutoCore

```
SerializeCreatePacket(char, buffer, ...):
  serialize simple-object base then character extensions
  must stay field-compatible with ApplyCreateFromPacket / create S2C
Do not invent field order — seal against Apply sibling before server emit changes.
```

---

## 5. Open questions

1. Produce offset table vs ApplyCreateFromPacket.
2. Quickbar 100-slot layout cross-check with RecvCreateCharacter.
3. Runtime packet size samples.

**Verdict:** **accept-with-gaps** on CF skeleton; **needs-more-evidence** on full field map
