# Review B (skeptical / adversarial): `aa_004cdcc0` CVOGSectorMap_DoPlayerOnLoadTrigger

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdcc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004cdcc0_CVOGSectorMap_DoPlayerOnLoadTrigger.md` |
| **Verdict** | **accept-with-gaps** on CF; contract clear for server port |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Once-per-map only | **Falsified — no +0x74 style gate** |
| 2 | Uses creator TFID slots | **Falsified — E7E0/E7E4 not E7E8/E7EC** |
| 3 | Fires even if TFID unresolved | **Falsified — null return** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| TFID offsets | High | Wrong trigger object |
| Every-add fire | High | Miss multi-player load missions |
| +0x114 vfunc | Tentative | Wrong activation |

---

## 3. Cross-check against raw

```
tfid = sector+E7E0/E7E4;
obj = lookup(tfid); if !obj return;
inner dual-base; vtbl+0x114().
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
DoPlayerOnLoadTrigger(sectorMap):
  resolve per-player load trigger TFID; fire activate vfunc if present
  call on every character add (not once-only)
  server analogue: FireOnLoadPlayerMissions after creates
```

---

## 5. Open questions

1. Map asset field names for E7E0 pair.
2. Live login on-load mission fire order.

**Verdict:** **accept-with-gaps** on CF; contract clear for server port
