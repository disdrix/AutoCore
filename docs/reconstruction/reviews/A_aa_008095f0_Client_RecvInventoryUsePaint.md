# Review A (reconstruction fidelity): `aa_008095f0` Client_RecvInventoryUsePaint

| Field | Value |
|---|---|
| **Stable ID** | `aa_008095f0` |
| **VA** | `0x008095f0` |
| **Canonical name** | `Client_RecvInventoryUsePaint` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008095f0_Client_RecvInventoryUsePaint.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C vehicle paint/color apply: resolve target TFID `@+0x10`; require clone type **`0x0E`** (vehicle); require body handle vtbl `+0x1d4`; path selector `@+0x21`: 0 → `FUN_004faaf0(color@+0x20)`, 1 → `FUN_004fab40(color)`; if obj is local vehicle `char+0xcd0` → `FUN_0051f4e0(0)`; terminal `FUN_004fcd80(0)`. Packet in EDI; game state stack arg.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / clean | `raw/aa_008095f0_…`, `reconstructed-exact/Client_RecvInventoryUsePaint.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| TFID resolve + type 0x0E gate | **High** | |
| Dual paint helpers by `@+0x21` | **High** CF |
| Color byte `@+0x20` | **High** | |
| Local vehicle refresh branch | **High** CF |
| Body vcall required | **High** CF; clean stub width note |
| Packet in EDI | **Probable** | |
| Helper paint semantics | **Tentative** | Unnamed FUN_* |

---

## 4. Control flow: clean ≡ raw

Gates and dual path preserved; body vcall width incompletely recovered in clean (noted).

---

## 5. Gaps / open

Paint channel meaning; opcode identity; runtime paint use.

**Verdict:** **accept-with-gaps.**
