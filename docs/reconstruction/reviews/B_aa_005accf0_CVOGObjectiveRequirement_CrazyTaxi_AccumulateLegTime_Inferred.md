# Review B (adversarial): `aa_005accf0` CrazyTaxi_AccumulateLegTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_005accf0` |
| **VA** | `0x005accf0` |
| **Canonical name** | `CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred` |
| **Review date** | `2026-07-29` (OWN-ONLY dual B — W30-M) |
| **Reviewer role** | Adversarial / disconfirm |
| **Counterpart** | `reviews/A_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Generic distance helper (not CrazyTaxi) | **Reject** — uses `this+0x4c` TFID vec + `this+0x8c` Val12 TimeLimit map matching CrazyTaxi ctor/XML |
| Pure scale distance (no Percent) | **Reject** — multiplies by `node+0x14` when map hit ≠ head |
| `DAT_00aaa688` is not 5.0f | **Reject** — `read_memory` `00 00 a0 40` |
| Wrong ABI (`ret 8` / `ret 0x10` / bare) | **Reject** — epilogue `c2 14 00` |
| Map family isnil@+0x15 / +0x29 | **Reject** — walk/Dec use **+0x19** |
| Always requires both TFIDs | **Reject** — `fromIndex < 0` uses actor GetPos; dest null skips distance add |
| Claim live callers without evidence | **Reject** — full-image scan found **zero** static refs; gap retained |
| Overclaim product method name | **Gap** — `_Inferred` retained |
| Confuse with random-stop picker `005aca60` | **Reject** — different CF (RNG + min distance index) |

---

## Residual risks

- Dead code: no static call/ptr refs in image may mean unreferenced residual after patch — still structurally valid.
- Source pose uninitialized if `fromIndex >= 0` and TFID resolve fails (decomp residual).
- Lower_bound + conditional Dec bracket policy may not match product English “exact Stops key”.
- Actor+0x250 scale chain type names not fully product-labeled.

---

## Decision

No successful disconfirm of sealed CF/ABI/constants/layout. Accept with caller and product-name gaps.

**Verdict:** **accept-with-gaps**
