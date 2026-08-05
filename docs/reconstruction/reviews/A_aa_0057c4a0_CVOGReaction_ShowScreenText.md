# Review A (reconstruction fidelity): `aa_0057c4a0` CVOGReaction_ShowScreenText

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057c4a0` |
| **VA** | `0x0057c4a0` |
| **Canonical name** | `CVOGReaction_ShowScreenText` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0057c4a0_CVOGReaction_ShowScreenText.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Build a small **Logic UI packet** for on-screen text and send it:

1. `local_138[0] = param_1+0x160` (text/source handle from reaction).
2. Copy four dwords from `param_2+0x160..+0x16c` into local pose/param slots.
3. Set opcode/type `local_11c = 0x26`.
4. `Client_SendLogicUiPacket(local_138)`.

Client-only UI toast/banner path; not a mission fail/grant.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0057c4a0_CVOGReaction_ShowScreenText.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_ShowScreenText.cpp` |
| System map | `docs/reconstruction/systems/missions-progression.md` (when present) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(reaction, source)` | **High** | Raw |
| Opcode 0x26 Logic UI | **High** | Constant |
| Send via Client_SendLogicUiPacket | **High** | Tail call |
| Uses +0x160 field family | **High** | Same as ShowDialog src fields |
| Packet layout beyond locals | **Tentative** | Stack frame inferred |
| Exact on-screen style | **Tentative** | UI side |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Field gather | **Yes** |
| Opcode 0x26 | **Yes** |
| SendLogicUiPacket | **Yes** |
| No grant/fail side effects | **Yes** |

---

## 5. Gaps

1. Logic UI opcode 0x26 schema.
2. Which UI widget consumes it.
3. Duration/color fields if any outside this frame.
4. Runtime capture.

**Verdict:** accept-with-gaps.
