# Review A (reconstruction fidelity): `aa_0052f650` CVOGCharacter_SerializeCreatePacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052f650` |
| **VA** | `0x0052f650` |
| **Canonical name** | `CVOGCharacter_SerializeCreatePacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052f650_CVOGCharacter_SerializeCreatePacket.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Serialize character create/snapshot into packet buffer: starts with `CreateSimpleObject_SerializeVariant2`, then large character-specific field dump (level, currencies, quickbar, missions, etc.). Inverse of ApplyCreateFromPacket family. Scaffold-scale unit.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052f650_CVOGCharacter_SerializeCreatePacket.md` |
| Annotated | `docs/reconstruction/raw/aa_0052f650_CVOGCharacter_SerializeCreatePacket.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SerializeCreatePacket.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052f650_CVOGCharacter_SerializeCreatePacket.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Calls CreateSimpleObject_SerializeVariant2 first` | **High** | Entry |
| `Null param_2 early return 0` | **High** | Buffer gate |
| `Large sequential field write tail` | **High** | Body size / many stores |
| `Inverse relationship to ApplyCreateFromPacket` | **Probable** | Naming + create path |
| `Full field map not sealed in clean plate` | **High** | Scaffold residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Base serialize + null gate | **Yes** |
| Extended character fields present | **Yes** |
| No modernization of wire order | **Yes** |

---

## 5. Gaps / open

1. Complete ordered field map vs ApplyCreateFromPacket.
2. param_3/param_4 roles (flags/size).
3. Which paths use serialize vs server-authored packets.
4. Runtime create dump capture.

**Verdict:** **accept-with-gaps**
