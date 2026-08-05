# Review B (skeptical / adversarial): `Client_LookupObjectByTfid_Inferred` @ `0x004bb0a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb0a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004bb0a0_Client_LookupObjectByTfid_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Creates object | Falsified — lookup only |
| 2 | Ignores globalFlag | Falsified — passed to ResolveObjectTarget |
| 3 | Direct hash only no Resolve | Falsified — uses ResolveObjectTarget |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID triple resolve | High | Wrong level-packet apply target |
| vtbl+0x1dc unwrap | High | Null/wrong object |
| CharacterLevel pre-step | High | Level UI desync |

---

## 3. Cross-check against raw

```
LookupObjectByTfid(global, lo, hi):
  p = ResolveObjectTarget(...);
  return p ? p->vtbl[+0x1dc]() : null;
```

---

## 4. Surviving contract for AutoCore

```
LookupObjectByTfid(globalFlag, coidLo, coidHi) -> object*|null:
  used before ApplyCharacterLevelPacket;
  null-safe.
```

---

## 5. Open questions

1. Name vtbl+0x1dc.
2. Cross-check with other TFID resolve sites.

**Verdict:** **accept-with-gaps**
