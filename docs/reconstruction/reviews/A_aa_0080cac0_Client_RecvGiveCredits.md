# Review A (reconstruction fidelity): `aa_0080cac0` Client_RecvGiveCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080cac0` |
| **VA** | `0x0080cac0` |
| **Canonical name** | `Client_RecvGiveCredits` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080cac0_Client_RecvGiveCredits.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C GiveCredits (plate opcode **0x205E**): require local character @ game+0xe98, **add** signed int64 money delta from packet+8 via `CVOGCharacter_AddCredits`, play "credits" UI sound when amount > 0, optional combat floater type **4**, money HUD refresh via game+0x1040.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0080cac0_Client_RecvGiveCredits.md` |
| Annotated | `docs/reconstruction/raw/aa_0080cac0_Client_RecvGiveCredits.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvGiveCredits.cpp` |
| Function record | `docs/reconstruction/functions/aa_0080cac0_Client_RecvGiveCredits.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Bail if no local char → VOG_DEBUG_STOP` | **High** | Entry gate |
| `AddCredits(char, int64@packet+8)` | **High** | Additive money @ char+0x720 |
| `Positive amount → "credits" interface sound` | **High** | Signed hi/lo > 0 test |
| `Floater type 4 when vehicle@+0x250 and char+0xd6c==0` | **High** | CombatFloater Credits |
| `Money HUD game+0x1040 / +0x50c vtbl+0x448` | **High** | Vehicle-present branch |
| `ESI=game, EDI=packet framing` | **Probable** | unaff residuals; plate notes tension |
| `Opcode 0x205E` | **Probable** | Plate/dispatch only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Local char gate + AddCredits | **Yes** |
| Positive sound branch | **Yes** |
| Floater + HUD path | **Yes** |
| No invented modernizations | **Yes** |

---

## 5. Gaps / open

1. Register framing ESI/EDI vs formals not sealed as portable ABI.
2. char+0xd6c floater suppress meaning open.
3. Floater color DAT_00a1e840 block ownership open.
4. Runtime / differential open.

**Verdict:** **accept-with-gaps**
