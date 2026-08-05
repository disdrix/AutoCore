# Review A (reconstruction fidelity): `aa_00564700` CVOGSpawnPoint_SetObjectActiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_00564700` |
| **VA** | `0x00564700` |
| **Canonical name** | `CVOGSpawnPoint_SetObjectActiveState` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00564700_CVOGSpawnPoint_SetObjectActiveState.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Activate/deactivate spawn-owned object: non-NPC vs NPC (IsNPC) branches; NPC path enables AI wake, map list enrollment, optional wander offset. Recursive child spawn when template kind 0xe chain.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00564700_CVOGSpawnPoint_SetObjectActiveState.md` |
| Annotated | `docs/reconstruction/raw/aa_00564700_CVOGSpawnPoint_SetObjectActiveState.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGSpawnPoint_SetObjectActiveState.cpp` |
| Function record | `docs/reconstruction/functions/aa_00564700_CVOGSpawnPoint_SetObjectActiveState.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Reads desired state from *param_2 char` | **High** | cVar1 |
| `Branches on vtbl+0x1d8 IsNPC-style result` | **High** | zero vs non-zero |
| `Non-NPC: enable/disable via FUN_00560ec0 / FUN_00561450 family` | **Probable** | Helpers |
| `NPC path: tick gate 15s, AI flags, FUN_0053d970` | **High** | Complex mid-body |
| `Recursive SetObjectActiveState on child when kind 0xe` | **High** | param_1[0x2b] |
| `Large residual opacity` | **High** | Many FUN_* |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| NPC vs non-NPC split | **Yes** |
| Activate/deactivate polarity from *param_2 | **Yes** |
| Child recursion present | **Yes** |

---

## 5. Gaps / open

1. Full NPC AI wake side-effect list.
2. 15s g_dwClientTickMs gate purpose.
3. Wander random offset block necessity on server.
4. Runtime activate/deactivate capture.

**Verdict:** **accept-with-gaps**
