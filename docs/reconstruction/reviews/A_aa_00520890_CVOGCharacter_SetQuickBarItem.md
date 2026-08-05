# Review A (reconstruction fidelity): `aa_00520890` CVOGCharacter_SetQuickBarItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520890` |
| **VA** | `0x00520890` |
| **Canonical name** | `CVOGCharacter_SetQuickBarItem` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00520890_CVOGCharacter_SetQuickBarItem.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** (trivial) |

---

## 1. Purpose

Trivial setter: if slot < 100, store item COID int64 at char+0x930+slot*8 and OR dirty bit 2 at +0x634.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00520890_CVOGCharacter_SetQuickBarItem.md` |
| Annotated | `docs/reconstruction/raw/aa_00520890_CVOGCharacter_SetQuickBarItem.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetQuickBarItem.cpp` |
| Function record | `docs/reconstruction/functions/aa_00520890_CVOGCharacter_SetQuickBarItem.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `slot < 100 guard` | **High** | Body |
| `store lo/hi at +0x930/+0x934 stride 8` | **High** | Body |
| `dirty |= 2 at +0x634` | **High** | Body |
| `thiscall RET 0xC` | **Probable** | Plate |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Guard + store + dirty | **Yes** |

---

## 5. Gaps / open

1. Empty sentinel both halves 0xFFFFFFFF is convention from callers, not enforced here.

**Verdict:** **accept** (trivial)
