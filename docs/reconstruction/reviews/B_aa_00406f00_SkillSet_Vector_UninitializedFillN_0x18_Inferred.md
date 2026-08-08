# Review B (skeptical / independent): `aa_00406f00` SkillSet_Vector_UninitializedFillN_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406f00` |
| **VA** | `0x00406f00` |
| **Canonical name** | `SkillSet_Vector_UninitializedFillN_0x18_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md` |
| **System** | STL / SkillSet vector |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00406f00` only | Under-describes sealed Ufill role |
| `Named_CalleeOf_Skill_Uses_SkillSet_GetEntryCount_00406f00` | **Reject** — scaffold chain-of-caller; sole real caller is `FUN_00412730` |
| `StdTree_*` / map buynode / insert near `00406c40` | **Reject** — no tree links/color/isnil; pure vector fill |
| `UninitializedCopy` / move | **Reject** — prototype fill from one value, not range copy (`00412a80` is the Ucopy sibling) |
| Generic `vector_ufill` without 0x18 | Omits sealed stride discriminator |
| `SkillSet_Vector_UninitializedFillN_0x18_Inferred` | **Accept** — family + stride; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| unaff_ESI/EDI are decompiler garbage → unknown ABI | **Fails** — caller explicitly `mov esi,count; mov edi,dest` before both calls |
| `__stdcall` all-stack args | **Fails** — dest/count live in EDI/ESI; only value on stack |
| Stride 0x0c / 0x30 | **Fails** — `*0x18` end math + fill `add esi,0x18` |
| Multiple unrelated callers | **Fails** — both xrefs inside `FUN_00412730` |
| This is the tree insert residual | **Fails** — insert is dualed `00406c40`; this is vector helper in VA band |
| Product English proven | **Fails** — keep `_Inferred` |

---

## 3. Agreement with Review A

- ABI/stride/caller/fill callees: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, parent insert dual, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with 0x0c Ufill twin neighborhood (`00406ee0`) or other strides.  
- Do not treat as skill combat logic — container helper only.  
- Parent `FUN_00412730` still open for full insert dual.

**Verdict:** **accept-with-gaps**
