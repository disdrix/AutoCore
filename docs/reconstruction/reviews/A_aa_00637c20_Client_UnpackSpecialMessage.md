# Review A (reconstruction fidelity): `aa_00637c20` Client_UnpackSpecialMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637c20` |
| **VA** | `0x00637c20` |
| **Canonical name** | `Client_UnpackSpecialMessage` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00637c20_Client_UnpackSpecialMessage.md` |
| **System tag** | `client-net` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_UnpackSpecialMessage.cpp` |
| Raw | `docs/reconstruction/raw/aa_00637c20_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** TNL special-message unpack dispatcher by opcode (param_2). Branches include 0x206c (GroupReactionCall path FUN_006374f0), 0x2005, damage unpack EMSG_Sector_Damage_Unpack, TNL_ByteBuffer_UnpackData helpers. SEH frame present. Client net unpack layer.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode param_2 switch/cascade | High | Body |
| 0x206c → FUN_006374f0 | High | Body |
| Damage unpack callee present | High | Callees |
| TNL_ByteBuffer_UnpackData | High | Callees |
| SEH ExceptionList framing | High | Body |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if opcode < 0x206d: special cases; else higher opcodes...; unpack helpers | Yes |

---

## 4. Gaps

1. Full opcode case table in unit.
2. Relationship to Client_PacketDispatch vs TNL layer.

**Verdict:** **accept-with-gaps**
