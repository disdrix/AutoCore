# Review A (reconstruction fidelity): `aa_00862c00` Client_SendInventoryUnequip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862c00` |
| **VA** | `0x00862c00` |
| **Canonical name** | `Client_SendInventoryUnequip` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00862c00_Client_SendInventoryUnequip.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S InventoryUnequip builder: opcode **`0x203E` size `0x30`**. Requires local host `DAT_00d1b6d8` and char `+0x250`. Resolves item inventory root (`vtbl+0x3ac`); may force space-fail path via `FUN_004f6a80` → `FUN_00931db0`. Free-slot search `FUN_005714e0` writes dest X/Y `@+0x28/+0x29`; town fallback `FUN_004ce5c0`. No space → toast *“There is not enough space in your inventory for this equipment.”*; else send. Vehicle TFID fields not filled by this builder (plate).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00862c00_Client_SendInventoryUnequip.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendInventoryUnequip.cpp` |
| Function record | `docs/reconstruction/functions/aa_00862c00_Client_SendInventoryUnequip.md` |
| S2C sibling | `Client_RecvInventoryUnequipNotify` (same opcode bidirectional) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Host gate `DAT_00d1b6d8` + `+0x250` | **High** | |
| Item resolve via `in_EAX` vtbl `+0x3ac` | **High** CF |
| Space fail toast string | **High** | Present in raw |
| Free-slot → dest X/Y | **High** CF; helper names Probable |
| Opcode `0x203E` size `0x30` | **High** | Plate + raw builder comments |
| Vehicle TFID unfilled | **Probable** | Plate claim |
| Clean body fully refined | **Tentative** | Scaffold + plate; dual body copy in cpp |
| Signature (`in_EAX` item) | **Tentative** | Register this |

---

## 4. Control flow: clean ≡ raw

Clean includes plate + width-normalized decompiler body. Gates, free-slot, toast, send path present; not fully human-typed packet struct.

---

## 5. Gaps / open

Full field map of 0x30 packet; send helper identity; callers; runtime unequip.

**Verdict:** **accept-with-gaps** (scaffold + plate).
