# Review A (reconstruction fidelity): `aa_0052a1b0` CVOGReaction_RelockContinentObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052a1b0` |
| **VA** | `0x0052a1b0` |
| **Canonical name** | `CVOGReaction_RelockContinentObject` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052a1b0_CVOGReaction_RelockContinentObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **continent exploration relock** (inverse of UnlockContinentObject):

1. `FUN_00538c80(continentId, &local_ptr)` — lookup/remove path yielding node pointer.
2. If non-null: `operator_delete(local_ptr)` (decompiler marks noreturn warning — treat as delete of extracted node/value).
3. Dual-base adjust character; if points at current map (`char_dual+4 == map+0xe8a0`): `FUN_004d1d00()` + `FUN_004d9ec0(local,1)` with type `0x2a` (same UI refresh family as Unlock).

Used from UnlockRegion apply when unlock flag is 0 (MAP_REVEAL). Symmetric UI refresh to Unlock; **erase** instead of insert at `+0x534`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052a1b0_CVOGReaction_RelockContinentObject.md` |
| Annotated | `docs/reconstruction/raw/aa_0052a1b0_CVOGReaction_RelockContinentObject.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_RelockContinentObject.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052a1b0_CVOGReaction_RelockContinentObject.md` |
| Sibling | UnlockContinentObject `aa_00531c80` |
| MAP_REVEAL | `Documentation/MAP_REVEAL.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall(char*, continentId)` void | **High** | Raw |
| FUN_00538c80 then conditional delete | **High** | Explicit |
| UI refresh type 0x2a when local map | **High** | Same as Unlock |
| Inverse of Unlock hash insert | **Probable** | Erase via helper; not open-coded walk |
| operator_delete noreturn warning real | **Low** | Decompiler artifact; delete returns |
| Exact erase from +0x534 inside FUN_00538c80 | **Probable** | Not shown in this body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Extract helper + delete | **Yes** |
| Local map UI refresh | **Yes** |
| No insert path | **Yes** |

---

## 5. Gaps

1. FUN_00538c80 body (true hash erase).
2. Whether missing key is silent no-op.
3. operator_delete decompiler warning.
4. Runtime relock / UnlockFlag==0 capture.
5. Name collision with server Relock ContObj reaction type 70 — same caution as Unlock.

**Verdict:** Thin relock + UI CF faithful. **accept-with-gaps.**
