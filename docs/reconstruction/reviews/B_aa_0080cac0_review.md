# Review B (skeptical / adversarial): `Client_RecvGiveCredits` @ `0x0080cac0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080cac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080cac0_review.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Formal stack args drive the body | **Falsified in practice** — body reads unaffiliated ESI/EDI |
| 2 | GiveCredits is absolute money set | **Falsified** — `AddCredits` is additive (contrast `0x2017`) |
| 3 | Mission complete should always send 0x205E | **Dangerous** — CompleteObjective already mutates money; double-count risk |
| 4 | Floater always shows | **Falsified** — needs vehicle and `+0xd6c==0` |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| Additive int64 at packet+8 | High | Wrong wire layout |
| Opcode 0x205E dispatch | High | Missed credits UI |
| Register ABI | Medium | Amount read from wrong base |
| Double-count vs mission final | High policy risk | Inflated client money |

---

## 3. Surviving contract for AutoCore

```
S2C 0x205E GiveCredits:
  amount = int64 additive delta
  client: character.Currency += amount
  positive → sound; optional credits floater
Do NOT also apply mission credits client-side if CompleteObjective already did.
Prefer absolute 0x2017 CharacterLevel for login restore.
```

---

## 4. Open questions

1. Reconcile PacketDispatch `(unaff_EDI, unaff_ESI)` call vs callee plate ESI=game.
2. When server should emit GiveCredits vs only CharacterLevel.

**Verdict:** Safe as additive credits handler map; treat ABI as best-effort recovery.
