# Review B (skeptical / adversarial): `aa_00810280` Client_RecvInventoryUseItemResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00810280_Client_RecvInventoryUseItemResponse.md` |
| **Verdict** | **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Clean is bit-exact on success path | **Weak** — qty/metadata vcalls stubbed as comments in places |
| 2 | count < 1 always removes | **Partial** — gated on `FUN_00571d80` nonzero |
| 3 | Always user-visible fail | **Unknown** — fail helpers unnamed |
| 4 | Opcode sealed | **Fail** |
| 5 | Core inventory-transfer critical | **Overstated** — specialty use path |

---

## 2. Surviving contract

```
require local char + vehicle/cargo host
if remaining@+0x10 < 1:
  if remove helper(TFID): fail UI helpers
else:
  item = find(TFID); set qty; write meta short
refresh mission UI (+ optional craft hosts)
```

**Verdict:** Branch map OK; do not ship success-path stubs without re-reading raw vcalls.
