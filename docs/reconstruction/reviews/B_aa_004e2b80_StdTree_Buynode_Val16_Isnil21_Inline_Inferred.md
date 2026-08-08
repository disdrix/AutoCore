# Review B (skeptical / independent): `aa_004e2b80` StdTree_Buynode_Val16_Isnil21_Inline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2b80` |
| **VA** | `0x004e2b80` |
| **Canonical name** | `StdTree_Buynode_Val16_Isnil21_Inline_Inferred` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_004e2b80_StdTree_Buynode_Val16_Isnil21_Inline_Inferred.md` |
| **System** | skills-abilities (partition); body = STL / map-set buynode |
| **Terminal** | **false** |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_004e2b80` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*CVOGReaction*` | **Reject** — chain-of-caller plate; not a reaction method |
| Skill/ability product method | **Reject** — no skill strings/IDs; pure STL helper |
| `CNDHash_*` / freelist reclaim | **Reject** — CRT `new(0x28)` + tree field writes; no freelist head |
| `StdTree_Buynode_Val24_Isnil29` | **Reject** — wrong size (0x28≠0x30), isnil@+0x21≠+0x29 |
| `StdTree_Buynode_Val12` | **Reject** — Val16 (4 dwords), not Val12 |
| Placement-new freelist buy | **Reject** — `operator_new` not freelist pop |
| Merge name with `00408990` peer | **Reject as registry identity** — same family, different body (SEH+ctor vs inline) |
| `StdTree_Buynode_Val16_Isnil21_Inline_Inferred` | **Accept** — family-aligned + inline differentiator; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| thiscall ECX=map on entry | **Fails** — pure stack args; `RET 0x14`; ECX is temp only |
| void return / no pointer | **Fails** — both callers `MOV ECX,EAX` after CALL; EAX holds new |
| Value is 6 dwords (Val24) | **Fails** — exactly 4 dword copies @+0x10..+0x1c |
| isnil set from color arg | **Fails** — hard isnil=0 @+0x21 |
| color at +0x28 | **Fails** — color @+0x20 for this family |
| SEH frame present | **Fails** — no FS:[0] setup; leaf after new |
| Same body as peer `00408990` | **Fails** — peer calls NodeCtor under SEH; this inlines |
| Same body as empty `004088f0` | **Fails** — different args/value path |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Runtime Confirmed | **Fails** — no Launcher; Terminal **false** |

---

## 3. Agreement with Review A

- Alloc/construct CF + ABI + layout: **agree Confirmed/High**
- Name with `_Inferred` + Inline differentiator: **agree**
- Gaps (PDB, peer insert dual residual, runtime): **agree open**
- Scaffold CVOGReaction chain: **retired**

---

## 4. Residual risks

- Do not merge with Val24 isnil29 buynodes (`00407e30` / `005a2de0`) or empty shell `004088f0`.
- Do not treat as identical binary twin of `00408990` (same layout family; different CF).
- Peer insert `FUN_005a3500` undualed residual (not OWN).
- Product map value_type under skills host chain open.

**Verdict:** **accept-with-gaps**
