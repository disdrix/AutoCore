# Review A (reconstruction fidelity): `aa_0080cac0` Client_RecvGiveCredits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080cac0` |
| **VA** | `0x0080cac0` |
| **Canonical name** | `Client_RecvGiveCredits` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0080cac0_Client_RecvGiveCredits.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvGiveCredits.cpp` |
| Caller | `Client_PacketDispatch` case `0x205E` |
| Callee | `CVOGCharacter_AddCredits` |

---

## 2. Signature & CF

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Null local char → VOG_DEBUG_STOP | Present | Present | **Yes** |
| `AddCredits(char, int64@packet+8)` | Present | Present | **Yes** |
| Positive amount → "credits" sound | Present | Present | **Yes** |
| Vehicle `+0x250` + `+0xd6c==0` → floater type 4 | Present | Present | **Yes** |
| Money HUD via game+0x1040/+0x50c | Present | Present | **Yes** |
| Register framing ESI=game, EDI=packet | Present | Present (documented tension) | **Yes** |

---

## 3. State mutations

| Target | Mutation |
|---|---|
| Character money `+0x720` (via AddCredits) | Additive int64 delta |
| Floater queue | Optional type 4 |
| UI sound | Optional "credits" |

---

## 4. Gaps

1. Formal `(pGameClient, pPacket)` vs body `unaff_ESI`/`unaff_EDI` — dispatch call order still contested across units.
2. Floater DAT color constants not semantic-named.
3. Gate `char+0xd6c` meaning unresolved.

**Verdict:** Handler CF faithful for additive credits. **accept-with-gaps.**
