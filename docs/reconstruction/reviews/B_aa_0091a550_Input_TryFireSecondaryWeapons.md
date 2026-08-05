# Review B (skeptical / adversarial): `aa_0091a550` Input_TryFireSecondaryWeapons

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0091a550_Input_TryFireSecondaryWeapons.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always fires ignoring heat | Falsified — FUN_004f52e0 gate |
| 2 | Primary weapon path | Falsified — secondary name + flags |
| 3 | Server authority apply | Falsified — client input path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Heat gate order | High | Overheat still fires |
| Net conn + vehicle gates | High | Ghost fire |
| 0xd2 flag semantics | Medium | Blocked when should fire |

---

## 3. Cross-check against raw

```
TryFireSecondaryWeapons():
  if player && !(flags&0xd2) && netOk && vehicle:
    if !heatCheck: log heat fail; return
    fire(); maybe UI
Clean ≡ raw CF; FUN names residual.
```

---

## 4. Surviving contract for AutoCore

```
Client secondary fire entry; must preserve heat check before fire.
  AutoCore input/combat should mirror gate order.
```

---

## 5. Open questions

1. Map 0xd2 bits to combat-disabled / dead / stealth states.
2. Live: overheat secondary should only log.

**Verdict:** **accept-with-gaps**
