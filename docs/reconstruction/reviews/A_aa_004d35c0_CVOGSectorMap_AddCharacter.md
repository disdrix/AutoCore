# Review A (reconstruction fidelity): `aa_004d35c0` CVOGSectorMap_AddCharacter

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d35c0` |
| **VA** | `0x004d35c0` |
| **Canonical name** | `CVOGSectorMap_AddCharacter` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d35c0_CVOGSectorMap_AddCharacter.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Push character pointer into sector map vector @ **+0xe75c/+0xe760/+0xe764**; if capacity full grow via FUN_004e39d0. Conditionally `DoCreatorLoadTrigger` once when count condition met; **always** `DoPlayerOnLoadTrigger`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d35c0_CVOGSectorMap_AddCharacter.md` |
| Annotated | `docs/reconstruction/raw/aa_004d35c0_CVOGSectorMap_AddCharacter.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSectorMap_AddCharacter.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d35c0_CVOGSectorMap_AddCharacter.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vector push character param_2` | **High** | Grow or inplace store |
| `Capacity check (end-begin)>>2` | **High** | Standard vector |
| `Creator trigger when first/matching count conditions` | **High** | Flag +0xf6 branches |
| `Always DoPlayerOnLoadTrigger after` | **High** | Unconditional tail |
| `Invoked from character create path` | **Probable** | Plate note FUN_00521310 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Push + grow | **Yes** |
| Creator conditional + player always | **Yes** |

---

## 5. Gaps / open

1. Exact meaning of +0xf6 / e5d0+0xc expected count.
2. Whether param_2 is character* or dual-base.
3. Server Stage3 FireOnLoadPlayerMissions parity.

**Verdict:** **accept-with-gaps**
