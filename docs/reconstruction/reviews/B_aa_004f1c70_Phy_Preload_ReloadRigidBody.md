# Review B (skeptical / adversarial): `aa_004f1c70` Phy_Preload_ReloadRigidBody

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004f1c70_Phy_Preload_ReloadRigidBody.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | CPhysXBase_Step | Falsified — preload reload |
| 2 | Only logs | Falsified — multiple rebuild callees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Reload correctness | High | Stale collision |
| Callee identities | Medium | Port gap |

---

## 3. Cross-check against raw

```
Preload_ReloadRigidBody: open/reload RB asset chain.
```

---

## 4. Surviving contract for AutoCore

```
Asset hot-reload for rigid bodies during preload.
```

---

## 5. Open questions

1. Trigger condition from load node / UI.

**Verdict:** **accept-with-gaps**
