# Review B (skeptical / adversarial): `aa_004b73c0` NDSpecialFX_SetHostObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b73c0` |
| **VA** | `0x004b73c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_004b73c0_NDSpecialFX_SetHostObject_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Writes world transform matrix at `+0x18` | 4 dwords could be float transform | **Falsified as matrix** — integer −1 sentinel; TFID limb pattern; not float identity |
| 2 | Always walks child list | Null path might still walk | **Falsified** — null returns after sentinel copy |
| 3 | Same as `004b68c0` target set | Both cache 16B IDs | **Distinct slots** — host cache `+0x18` vs target `+0x68` |
| 4 | `DAT_009cb2a0` is quat identity | Common default | **Falsified** — `ffffffff ffffffff 00000000 00000000`, not `(0,0,0,1)` |
| 5 | Required for server authority | Client FX host bind | **Client FX surface** — weapon/interact/drive callers |
| 6 | List walk always calls `0058e370` | Unconditional | **Falsified** — only if `node[2] != 0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Host ptr @ `+0x10` | **High** | Update path null-crash |
| Sentinel bytes | **Confirmed** | Wrong null TFID |
| Child notify residual | **Probable** | Missed attach side effect |
| Product name | Tentative | Cosmetic |

---

## 3. Surviving contract

```
void SetHostObject(fx, host) {
  fx->host = host;                 // +0x10
  if (!host) { fx->hostTfid = SENTINEL_TFID; return; }
  fx->hostTfid = host->tfid@0x160; // +0x18..+0x24
  for (n in fx->list@0x204)
    if (n->payload) FUN_0058e370(host);
}
```

---

## 4. Open questions

1. `FUN_0058e370` dual seal.
2. Whether nulling host should also clear target `+0x68` (it does **not** — separate API).

**Verdict:** **accept-with-gaps**
