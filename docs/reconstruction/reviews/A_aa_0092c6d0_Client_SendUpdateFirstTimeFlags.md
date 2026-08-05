# Review A (reconstruction fidelity): `aa_0092c6d0` Client_SendUpdateFirstTimeFlags

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092c6d0` |
| **VA** | `0x0092c6d0` |
| **Canonical name** | `Client_SendUpdateFirstTimeFlags` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0092c6d0_Client_SendUpdateFirstTimeFlags.md` |
| **System** | `unknown` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

C2S UpdateFirstTimeFlags (**0x20B1**): copy 4×uint32 flags into local char+0xD30, build 0x14-byte packet (opcode + 4 dwords), send via client+0xc78 vtbl+0x18.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0092c6d0_Client_SendUpdateFirstTimeFlags.md` |
| Annotated | `docs/reconstruction/raw/aa_0092c6d0_Client_SendUpdateFirstTimeFlags.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendUpdateFirstTimeFlags.cpp` |
| Function record | `docs/reconstruction/functions/aa_0092c6d0_Client_SendUpdateFirstTimeFlags.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Opcode 0x20B1 size 0x14` | **High** | Body |
| `4 dwords from param_2 → char+0xD30` | **High** | Loop bVar2 < 4 |
| `Requires char at ESI+0xe98 and param_2 non-null` | **High** | Body |
| `Send via *(ESI+0xc78)+0x18` | **High** | Body |
| `ESI = game client residual` | **Probable** | Custom convention |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Copy + pack + send gates | **Yes** |

---

## 5. Gaps / open

1. param_1 unused (fastcall residual).
2. Flag bit meanings owned by first-time docs, not body.

**Verdict:** **accept-with-gaps**
