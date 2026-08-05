# Review B (skeptical / adversarial): `Client_INC_ContactCountdownTick` @ `0x0091ee20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091ee20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0091ee20_Client_INC_ContactCountdownTick.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always only instant repair | Falsified — 3 options |
| 2 | Client repairs without C2S | Falsified — sends 0x2073/0x20B6 |
| 3 | No fee check | Falsified — cannot-afford string path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 0x2073 vs 0x20B6 polarity | High | Wrong repair path |
| +0xc30 option enum | High | Wrong action |
| Countdown client-driven | High | Desync if server also times |

---

## 3. Cross-check against raw

```
INC_ContactCountdownTick:
  if countdown>0: update UI;
  else option:
    0 SendRespawnInSector(0x2073)
    1 SendInstantRepairRequest(0x20B6)
    2 transfer fee-gated
  toast strings for contact/repair/afford.
```

---

## 4. Surviving contract for AutoCore

```
INC_ContactCountdownTick:
  client INC kiosk countdown → C2S repair/respawn/transfer;
  pairs existing InstantRepair + RespawnInSector duals.
```

---

## 5. Open questions

1. Document fee formula for option 2.
2. Seal host object for +0xc24/+0xc30.

**Verdict:** **accept-with-gaps**
