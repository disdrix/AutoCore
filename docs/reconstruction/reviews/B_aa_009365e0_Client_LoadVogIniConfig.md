# Review B (skeptical / adversarial): `Client_LoadVogIniConfig` @ `0x009365e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009365e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_009365e0_Client_LoadVogIniConfig.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Hard-codes auth server | Falsified — INI driven |
| 2 | Sector gameplay config | Falsified — boot/auth/display |
| 3 | No password field | Falsified — plate includes PASSWORD |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| VOG.ini auth endpoint keys | High | Cannot login |
| Client-local credentials file | High | Security/UX docs only |

---

## 3. Cross-check against raw

```
LoadVogIniConfig:
  fopen VOG.ini; parse USERNAME/PASSWORD/AUTHSERVERIP/AUTHSERVERID/display;
  fill boot config.
```

---

## 4. Surviving contract for AutoCore

```
LoadVogIniConfig:
  client boot INI; not server AutoCore config.
  Useful for client harness only.
```

---

## 5. Open questions

1. Document complete key schema.

**Verdict:** **accept-with-gaps**
