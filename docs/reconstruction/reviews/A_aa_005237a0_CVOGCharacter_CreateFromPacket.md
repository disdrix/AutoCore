# Review A (reconstruction fidelity): `aa_005237a0` CVOGCharacter_CreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_005237a0` |
| **VA** | `0x005237a0` |
| **Canonical name** | `CVOGCharacter_CreateFromPacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005237a0_CVOGCharacter_CreateFromPacket.md` |
| **System** | `unknown` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Character create-from-packet method: call `FUN_005c9120` with args; if TFID valid and param_4 non-zero, stamp tick, resolve related object `FUN_004bafe0`, optional `FUN_005131b0` + vcall +0x218, conditional `FUN_00521310` follow-up when flags allow.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005237a0_CVOGCharacter_CreateFromPacket.md` |
| Annotated | `docs/reconstruction/raw/aa_005237a0_CVOGCharacter_CreateFromPacket.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CreateFromPacket.cpp` |
| Function record | `docs/reconstruction/functions/aa_005237a0_CVOGCharacter_CreateFromPacket.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `First FUN_005c9120(...)` | **High** | Body |
| `Gate TFID both halves != 0xFFFFFFFF and param_4` | **High** | Body |
| `GetTickCount stamp at this-relative -0xd8c` | **High** | Body |
| `Optional related object + vcall +0x218` | **High** | Body |
| `Skip FUN_00521310 when param_7 char set AND flag bit6` | **High** | Body |
| `thiscall with negative this-relative offsets (subobject)` | **Probable** | Multiple inheritance / embedded layout |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Base call + gated post-create | **Yes** |

---

## 5. Gaps / open

1. Negative this offsets indicate non-primary this — type layout open.
2. Callee semantics unresolved.

**Verdict:** **accept-with-gaps**
