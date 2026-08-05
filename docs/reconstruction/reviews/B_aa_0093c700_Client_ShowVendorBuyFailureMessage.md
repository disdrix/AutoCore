# Review B (skeptical / adversarial): `Client_ShowVendorBuyFailureMessage` @ `0x0093c700`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093c700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0093c700_Client_ShowVendorBuyFailureMessage.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Buys item on this path | Falsified — failure messages |
| 2 | Only cannot-afford | Falsified — three string family |
| 3 | No network ever | Weak — SendSectorPacket in callees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Three fail reasons | High | Wrong vendor UX |
| Client-side afford/space checks | High | Desync if server differs |

---

## 3. Cross-check against raw

```
ShowVendorBuyFailureMessage:
  stock / full inv / cannot afford toasts;
  note any C2S side-branches carefully.
```

---

## 4. Surviving contract for AutoCore

```
ShowVendorBuyFailureMessage: vendor buy error UX;
  server remains buy authority.
```

---

## 5. Open questions

1. Diff toast-only vs send branches.

**Verdict:** **accept-with-gaps**
