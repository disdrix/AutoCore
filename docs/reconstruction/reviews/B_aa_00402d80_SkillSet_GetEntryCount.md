# Review B (skeptical / adversarial): `aa_00402d80` SkillSet_GetEntryCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00402d80_SkillSet_GetEntryCount.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uses capacity +0xc | Falsified — end-begin only |
| 2 | Stride 0x10 | Falsified — 0x18 |
| 3 | Same as Skill_Uses bulk VAs | Falsified — unique thin VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride 0x18 | High | Wrong skill-set length |
| +0x4/+0x8 vector | High | Crash / empty set |
| Alias vs real unit distinction | High | Mis-index reconstruction |

---

## 3. Cross-check against raw

```
if begin==0: 0; else (end-begin)/0x18.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
SkillSet_GetEntryCount(set) → n:
  NPC skill-set vector length; NOT the Skill_Uses_* string aliases
  AutoCore NPC skill selection
```

---

## 5. Open questions

1. Seal entry struct fields.
2. Do not merge duals with Skill_Uses_* bulk VAs.

**Verdict:** **accept**
