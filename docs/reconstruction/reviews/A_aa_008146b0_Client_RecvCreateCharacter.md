# Review A (reconstruction fidelity): `aa_008146b0` Client_RecvCreateCharacter

| Field | Value |
|---|---|
| **Stable ID** | `aa_008146b0` |
| **VA** | `0x008146b0` |
| **Canonical name** | `Client_RecvCreateCharacter` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008146b0_Client_RecvCreateCharacter.md` |
| **System** | `unknown` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C create-character / create-from-packet path: if local vehicle TFID mismatch, lookup-or-allocate object by CBID, run create-from-packet vcalls, optional local-character UI (level, loot chrome), and on extended path (`in_AL`) restore 100 QuickBar item COIDs (@+0x410) and skill ids (@+0x730).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008146b0_Client_RecvCreateCharacter.md` |
| Annotated | `docs/reconstruction/raw/aa_008146b0_Client_RecvCreateCharacter.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvCreateCharacter.cpp` |
| Function record | `docs/reconstruction/functions/aa_008146b0_Client_RecvCreateCharacter.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Early skip when local TFID matches packet +0x90/+0x94` | **High** | Compound gate at entry |
| `Lookup by TFID then GiveItemByCbid alloc` | **High** | Client_LookupObjectByTfid + CVOGReaction_GiveItemByCbid |
| `Create vfuncs +0x8 / +0x210 / +0x1dc / +0xc4` | **High** | Call order preserved |
| `Local-char special path when TFID == client+0x508/0x50c` | **High** | UI + optional extended |
| `Extended QB restore 100 slots via SetQuickBarItem/Skill` | **High** | in_AL gate; offsets 0x410 / 0x730 |
| `in_AL as extended flag` | **Tentative** | Decompiler residual; plate labels CreateCharacterExtended |
| `param_1=packet, param_2=client` | **Probable** | Fastcall plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| TFID match early-out / alloc path | **Yes** |
| Create-from-packet vcall chain | **Yes** |
| Local UI + extended QB loop | **Yes** |
| Trailing inventory UI refresh | **Yes** |

---

## 5. Gaps / open

1. in_AL / extended flag register contract not sealed.
2. Full create-from-packet field map owned by ApplyCreateFromPacket sibling.
3. Many FUN_* helpers unresolved.
4. Runtime create / login restore open.

**Verdict:** **accept-with-gaps**
