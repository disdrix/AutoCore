# Review A (reconstruction fidelity): `aa_004e4870` CVOGReaction_BuildTextParams

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4870` |
| **VA** | `0x004e4870` |
| **Canonical name** | `CVOGReaction_BuildTextParams` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e4870_CVOGReaction_BuildTextParams.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_BuildTextParams.cpp` |
| Raw | `docs/reconstruction/raw/aa_004e4870_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Insert one text-parameter node into doubly-linked list rooted at this+0x04. FUN_004e29c0(head, head->next, payload) allocates node; FUN_004e29f0(1) post-hook; head->next = newNode; fix pred link **(newNode+4)=newNode. Used by reaction dialog/toast substitution chains. Small pure list op.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| List head at this+0x04 | High | Load |
| FUN_004e29c0 insert after head->next | High | Call |
| FUN_004e29f0(1) after insert | High | Call |
| Relink head+4 and **(node+4) | High | Stores |
| Payload opaque u32 | High | Param |
| Dialog/toast param chain consumer | Medium | Plate purpose |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Load head → insert → post → relink | Yes |

---

## 4. Gaps

1. Node layout and payload type (string id vs ptr).
2. FUN_004e29f0 side effects (refcount/count).

**Verdict:** **accept**
