# Review B (skeptical / adversarial): `aa_004d35c0` CVOGSectorMap_AddCharacter

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d35c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004d35c0_CVOGSectorMap_AddCharacter.md` |
| **Verdict** | **accept-with-gaps** on CF; High on always-player trigger |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always fires creator trigger | **Falsified — conditional bVar4** |
| 2 | Player trigger only once ever | **Falsified — every AddCharacter** |
| 3 | No vector growth | **Falsified — FUN_004e39d0 path** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always player on-load | High | Miss per-player missions |
| Creator once condition | High | Multi or never fire |
| Vector offsets | High | Corrupt sector list |

---

## 3. Cross-check against raw

```
push char into vector (+grow);
if count condition: DoCreatorLoadTrigger;
always DoPlayerOnLoadTrigger.
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
AddCharacter(sectorMap, character):
  append to sector character list
  maybe fire creator-load trigger when instance count condition met
  always fire per-player on-load trigger
Server should mirror player-on-load after Stage3 create; creator once per map instance.
```

---

## 5. Open questions

1. Seal +0xf6 and expected-count source.
2. Cross-check DoCreator/DoPlayer TFID fields.

**Verdict:** **accept-with-gaps** on CF; High on always-player trigger
