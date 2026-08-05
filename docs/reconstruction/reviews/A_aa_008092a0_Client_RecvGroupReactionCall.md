# Review A (reconstruction fidelity): `aa_008092a0` Client_RecvGroupReactionCall

| Field | Value |
|---|---|
| **Stable ID** | `aa_008092a0` |
| **VA** | `0x008092a0` |
| **Canonical name** | `Client_RecvGroupReactionCall` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008092a0_Client_RecvGroupReactionCall.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C group/logic reaction batch (plate opcode **0x206C**): loop `count@+4` entries of size **0x28**; either `CVOGMap_SetVariable` for variable entries or resolve reaction + object TFID and fire reaction vtbl **+0x2c0**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008092a0_Client_RecvGroupReactionCall.md` |
| Annotated | `docs/reconstruction/raw/aa_008092a0_Client_RecvGroupReactionCall.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvGroupReactionCall.cpp` |
| Function record | `docs/reconstruction/functions/aa_008092a0_Client_RecvGroupReactionCall.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Count byte @ packet+4; stride 0x28` | **High** | Loop bound + indexing |
| `Variable path: flag@+0xc non-zero → CVOGMap_SetVariable(+0x10,+0x14,0)` | **High** | Body |
| `Reaction path: resolve reaction; object TFID@+0x18; vcall +0x2c0` | **High** | FUN_004bb160 + Object_ResolveFromTFID |
| `Extra TFID filters vs local char / vehicle+0x250` | **High** | Branches before fire |
| `Opcode 0x206C` | **Probable** | Plate only |
| `param_1=client, param_2=packet body` | **Probable** | Formals |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Count loop | **Yes** |
| Variable vs reaction branch | **Yes** |
| TFID filter gates | **Yes** |
| Fire vcall | **Yes** |

---

## 5. Gaps / open

1. Opcode not in body.
2. Entry layout field names beyond flags/ids open.
3. FUN_004bb160 exact reaction resolve semantics.
4. Server soft-pedal timing is external policy note, not body.

**Verdict:** **accept-with-gaps**
