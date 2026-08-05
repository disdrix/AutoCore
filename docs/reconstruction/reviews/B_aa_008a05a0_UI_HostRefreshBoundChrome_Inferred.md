# Review B (skeptical / adversarial): `aa_008a05a0` UI_HostRefreshBoundChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a05a0` |
| **VA** | `0x008a05a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008a05a0_UI_HostRefreshBoundChrome_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Always refreshes | **Falsified** | Early-out if `+0x684 == 0` |
| 2 | Always vcalls +0x664 | **Falsified** | Second guard |
| 3 | Widget ctor | **Falsified** | No new/vtbl install |
| 4 | Sends packets | **Falsified** | Local UI callees only in body |
| 5 | CharSheet-only | **Falsified** | Level recv, mission chrome, skill train, etc. |

---

## 2. Surviving contract

```
if host[+0x684]:
  helper_af180(0); helper_a0370()
  if host[+0x664]: child.vtbl[+0x480]()
```

**Verdict:** **accept-with-gaps**
