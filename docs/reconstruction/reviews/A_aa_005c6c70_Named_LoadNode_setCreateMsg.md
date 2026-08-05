# Review A (reconstruction fidelity): `aa_005c6c70` Named_LoadNode_setCreateMsg

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c6c70` |
| **VA** | `0x005c6c70` |
| **Canonical name** | `Named_LoadNode_setCreateMsg` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005c6c70_Named_LoadNode_setCreateMsg.md` |
| **System** | `client-load` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`CLoadNode::setCreateMsg`** — attach create-packet blob to load node (`+0x6c`). Switches on opcode **`*param_2`**: **0x2012** SimpleObject size **0xD8** (0x36 dwords), **0x2013** large **0x930** path + `FUN_005c67b0` (recalculateInitAI), **0x2015** size **0x1a8** (0x6a dwords), other cases in body; default logs `UNKNOWN message format … #%d` and may delete `+0x6c`. Ties to `CreateSimpleObject_Serialize` opcode **0x2012**. Core client-load ingress for net create messages.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005c6c70_*.md` |
| Annotated | `docs/reconstruction/raw/aa_005c6c70_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Named_LoadNode_setCreateMsg.cpp` |
| Function record | `docs/reconstruction/functions/aa_005c6c70_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode switch 0x2012/0x2013/0x2015+ | High | Body |
| Blob stored via node +0x6c | High | Body |
| 0x2012 size 0xD8 / 0x36 dwords | High | Body |
| 0x2013 calls FUN_005c67b0 recalculateInitAI | High | Callee |
| Unknown opcode logs + may free +0x6c | High | Body |
| Full case set beyond excerpt | Medium | Long body residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| new scratch → switch opcode → copy blob → special post → return | Yes |

---

## 5. Gaps / open

1. Enumerate remaining opcode cases (vehicle/character).
2. Seal copy direction (stream→node vs reverse) bit-exact.

**Verdict:** **accept-with-gaps**
