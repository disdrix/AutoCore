# Review A (reconstruction fidelity): `aa_007e07b0` Named_tCloneBase

| Field | Value |
|---|---|
| **Stable ID** | `aa_007e07b0` |
| **VA** | `0x007e07b0` |
| **Canonical name** | `Named_tCloneBase` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007e07b0_Named_tCloneBase.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

DB table loader **`tCloneBase`** (plate DBReader pattern). Large column reader using shared open helpers `FUN_004230d0`/`00422fb0`/`0041a810`/`004231d0` and clonebase-specific `FUN_007b87c0`/`007b8910`/`007b8de0`. Foundation load for all item/vehicle/creature templates — feeds loot, combat pools, and load pipeline. Gate `DAT_00d1793c` empty-reader path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007e07b0_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007e07b0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_tCloneBase.cpp` |
| Function record | `docs/reconstruction/functions/aa_007e07b0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tCloneBase DBReader loader | High | Name + DB pattern |
| Shared open/read/close family with tDamage/tCharacter | High | Callees |
| DAT_00d1793c empty short-circuit | High | Body |
| Full column→offset map | Medium | 827-line residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if ready short; else open → many column reads → insert map → close | Yes |

---

## 5. Gaps / open

1. Publish column ledger for AutoCore clonebase import.
2. Ready-flag write site.

**Verdict:** **accept-with-gaps**
