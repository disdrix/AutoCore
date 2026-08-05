# Review A (reconstruction fidelity): `aa_008087e0` Client_RecvInventoryUnequipResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_008087e0` |
| **VA** | `0x008087e0` |
| **Canonical name** | `Client_RecvInventoryUnequipResponse` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008087e0_Client_RecvInventoryUnequipResponse.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Trivial S2C InventoryUnequipResponse (**`0x203F`** plate): if success byte `@+0x10 == 0`, `sprintf` unsync debug line with COID `@+0x08` and `OutputDebugStringA`. Success path is empty (no inventory mutation). Packet pointer in EAX.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / clean | `raw/aa_008087e0_…`, `reconstructed-exact/Client_RecvInventoryUnequipResponse.cpp` |
| Function record | `functions/aa_008087e0_…` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Fail-only side effect ODS | **High** | Entire observable body |
| Success no-op | **High** | |
| String identifies InventoryUnequip_Response | **High** | Self-describing |
| Opcode 0x203F | **Probable** | Plate |
| Packet in EAX | **Probable** | |

---

## 4. Control flow: clean ≡ raw

Trivial match.

---

## 5. Gaps / open

Dispatch opcode seal; whether any other build mutates on success elsewhere.

**Verdict:** **accept-with-gaps** (trivial unit).
