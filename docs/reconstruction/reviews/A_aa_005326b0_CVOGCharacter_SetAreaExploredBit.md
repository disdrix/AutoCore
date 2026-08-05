# Review A (reconstruction fidelity): `aa_005326b0` CVOGCharacter_SetAreaExploredBit

| Field | Value |
|---|---|
| **Stable ID** | `aa_005326b0` |
| **VA** | `0x005326b0` |
| **Canonical name** | `CVOGCharacter_SetAreaExploredBit` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005326b0_CVOGCharacter_SetAreaExploredBit.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set or clear one explored-area bit (areaId 1..32) on continent unlock entry; LogicUI type **0x20** notify; if entry missing and local (+0x7e), attempt `UnlockContinentObject` then **return without bit write**. Optional secondary list walk for local player.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005326b0_CVOGCharacter_SetAreaExploredBit.md` |
| Annotated | `docs/reconstruction/raw/aa_005326b0_CVOGCharacter_SetAreaExploredBit.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetAreaExploredBit.cpp` |
| Function record | `docs/reconstruction/functions/aa_005326b0_CVOGCharacter_SetAreaExploredBit.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `areaId 1..32 else return` | **High** | Same range as reader |
| `bit = 1<<(areaId-1); OR or AND~ by setBit` | **High** | entry+0x08 |
| `Missing entry + local → UnlockContinentObject then return` | **High** | No bit write same call |
| `LogicUI type 0x20 payload areaId` | **High** | Client_SendLogicUiPacket |
| `Secondary list walk only if local +0x7e` | **Probable** | FUN_00540060 / FUN_004e2060 opaque |
| `No XP award` | **High** | No AddExperience call |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Range + hash path | **Yes** |
| Missing-entry unlock early-out | **Yes** |
| Bit set/clear + LogicUI | **Yes** |
| Local secondary walk | **Yes** |
| No invented XP | **Yes** |

---

## 5. Gaps / open

1. Whether UnlockContinentObject inserts synchronously (body returns before re-lookup).
2. Secondary list node layout (continent @ [3], area byte).
3. LogicUi packet full framing.
4. Runtime discovery tick capture.

**Verdict:** **accept-with-gaps**
