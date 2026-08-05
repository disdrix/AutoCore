# Review A (reconstruction fidelity): `aa_005d3cf0` CVOGHBAIBot_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3cf0` |
| **VA** | `0x005d3cf0` |
| **Canonical name** | `CVOGHBAIBot_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d3cf0_CVOGHBAIBot_ctor.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept** |

---

## 1. Purpose

Construct **Bot** HBAI (AICode **3**, summons). Chains `CVOGHBAICreatureBase_ctor`, installs Bot vtbl `PTR_LAB_009dabd0`. Factory size **0x100**. Profile string family "Bot summons ai". No extra field zeros beyond parent.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d3cf0_CVOGHBAIBot_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_005d3cf0_CVOGHBAIBot_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIBot_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d3cf0_CVOGHBAIBot_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Chains CreatureBase_ctor` | **High** | First call |
| `Vtbl PTR_LAB_009dabd0` | **High** | Bot |
| `Factory size 0x100` | **High** | CreateByAICode case 3 |
| `No extra body after vtbl` | **High** | Trampoline-ish |
| `AICode 3 summons` | **High** | NPC.md / factory map |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Parent + vtbl only | **Yes** |
| No invented init | **Yes** |

---

## 5. Gaps / open

1. Bot-specific virtual overrides vs CreatureBase.
2. Whether summons use same OnHeartBeat path as foot creatures.

**Verdict:** **accept**
