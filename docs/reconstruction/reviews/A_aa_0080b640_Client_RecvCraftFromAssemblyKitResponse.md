# Review A (reconstruction fidelity): `aa_0080b640` Client_RecvCraftFromAssemblyKitResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b640` |
| **VA** | `0x0080b640` |
| **Canonical name** | `Client_RecvCraftFromAssemblyKitResponse` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0080b640_Client_RecvCraftFromAssemblyKitResponse.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C **craft-from-assembly-kit response** UI handler. Reads status dword at `packet+4`, then:

| Status | Behavior |
|-------:|----------|
| 0 | Localized **"Item Created!"** toast via `FUN_0040c5c0` (styled float UI) |
| 1 | `"Failed Crafting: Object not a kit."` |
| 2 | `"Failed Crafting: Invalid ingredient list."` |
| 3 | `"Experimentation Failed."` |
| 4 | `"Not enough skill to attempt this."` |
| 5 | `"You are not near a valid crafting station."` |
| other | silent return |

Failure cases: localize string (`FUN_007a6de0`) then `FUN_007fdfb0` message path. No inventory mutation in this body — **feedback only**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0080b640_Client_RecvCraftFromAssemblyKitResponse.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvCraftFromAssemblyKitResponse.cpp` |
| Function record | `docs/reconstruction/functions/aa_0080b640_Client_RecvCraftFromAssemblyKitResponse.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Status at `param_1+4` switch | **High** | Raw |
| Case 0 success toast path | **High** | Distinct UI helper |
| Cases 1–5 failure strings | **High** | Literals |
| Default no-op | **High** | Explicit |
| No inventory apply here | **High** | Body is pure UI |
| Opcode id of packet | **Tentative** | Not in body (dispatch table) |
| `FUN_007fdfb0` / toast semantics | **Probable** | Message UI family |
| `unaff_ESI` context | **Tentative** | Decomp register |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Prep `FUN_007a69d0` | **Yes** |
| Switch on `+4` | **Yes** |
| Success / fail arms | **Yes** |
| Default return | **Yes** |

---

## 5. Gaps

1. Opcode / dispatch table entry not in this unit.
2. Item-created toast params (`g_flLevelUpUiBase_Inferred`, color `0xffeee3d8`) partially named.
3. No craft request C2S dual-reviewed here.
4. Runtime craft not observed.

**Verdict:** Status→message table sealed. **accept-with-gaps.**
