# Review A (reconstruction fidelity): `aa_00801760` Client_MaybeShowFirstTimeTip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00801760` |
| **VA** | `0x00801760` |
| **Canonical name** | `Client_MaybeShowFirstTimeTip` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00801760_Client_MaybeShowFirstTimeTip.md` |
| **System tag** | `first-time-tips` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_MaybeShowFirstTimeTip.cpp` |
| Raw | `docs/reconstruction/raw/aa_00801760_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Maybe show first-time tip UI (CDlgFirstTime). param_2 tip id 0..0x31. Skip if tip bit already set in char+0xD30 dword[id>>5] bit(id&0x1f). If FirstFlags1 signed <0 (hide-tips bit31), mark bit + Client_SendUpdateFirstTimeFlags without showing. Else create/show CDlgFirstTime and queue tip. AutoCore persists bits on account.FirstFlags1..4.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Tip id param_2 range ~0..0x31 | High | Plate |
| Bit test char+0xD30 [id>>5] bit id&0x1f | High | Plate + SetFirstTimeTipBit |
| Hide-all if FirstFlags1 bit31 signed <0 | High | Plate |
| Hide path: Set bit + SendUpdateFirstTimeFlags, no UI | High | Callees |
| Else CDlgFirstTime show path | High | ctor callee |
| Pairs SetFirstTimeTipBit + SendUpdateFirstTimeFlags | High | Graph |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Bit already set → return | Yes |
| Hide-all → mark+send no dialog | Yes |
| Else dialog path | Yes |

---

## 4. Gaps

1. Exact FirstFlags1 field offset vs +0xD30 layout.
2. All tip id → string table mapping.
3. CDlgFirstTime widget lifecycle.

**Verdict:** **accept-with-gaps**
