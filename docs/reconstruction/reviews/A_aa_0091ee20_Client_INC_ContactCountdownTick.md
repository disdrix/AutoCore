# Review A (reconstruction fidelity): `aa_0091ee20` Client_INC_ContactCountdownTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091ee20` |
| **VA** | `0x0091ee20` |
| **Canonical name** | `Client_INC_ContactCountdownTick` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0091ee20_Client_INC_ContactCountdownTick.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_INC_ContactCountdownTick.cpp` |
| Raw | `docs/reconstruction/raw/aa_0091ee20_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** INC contact UI countdown tick. Option at this+0xc30: 0=repair-station airlift → SendRespawnInSector (0x2073); 1=instant repair → SendInstantRepairRequest (0x20B6); 2=transfer (fee check). Shows Contacting INC... countdown strings; cannot-afford toast.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Option this+0xc30 branches 0/1/2 | High | Plate + body |
| Option 0 → Client_SendRespawnInSector 0x2073 | High | Callee |
| Option 1 → Client_SendInstantRepairRequest 0x20B6 | High | Callee |
| Countdown UI strings Contacting INC... | High | Strings |
| Fee fail: You cannot afford the repair fee! | High | String |
| Tick gated by this+0xc24 counter | High | Body |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Tick countdown; on zero fire option-specific send/toast | Yes |

---

## 4. Gaps

1. Exact fee source fields for option 2.
2. Who starts countdown / sets +0xc30.

**Verdict:** **accept-with-gaps**
