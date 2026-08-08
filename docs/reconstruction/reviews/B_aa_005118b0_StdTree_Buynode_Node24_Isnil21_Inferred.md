# Review B (skeptical / adversarial): `aa_005118b0` StdTree_Buynode_Node24_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005118b0` |
| **VA** | `0x005118b0` |
| **Canonical name** | `StdTree_Buynode_Node24_Isnil21_Inferred` |
| **Review date** | `2026-08-05` (OWN-ONLY R13-030) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_005118b0_StdTree_Buynode_Node24_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set buynode |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_005118b0` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_00511950` / skill method | **Reject** — shared STL helper; not skill product logic |
| `CNDHash_*` / freelist reclaim | **Reject** — CRT `new(0x24)` + field construct; no freelist head |
| `StdTree_Buynode_Val16_Isnil21` | **Reject** — wrong size (0x24≠0x28); has key@+0x0C + vector path not Val16 dword pack |
| `StdTree_Buynode_Val24_Isnil29` | **Reject** — isnil@+0x21≠+0x29; size 0x24≠0x30 |
| Placement-new freelist buy | **Reject** — `operator_new` not freelist pop |
| thiscall `map*` first arg | **Reject** — stack-only; `RET 0x14`; no ECX this on entry |
| `StdTree_Buynode_Node24_Isnil21_Inferred` | **Accept** — family-aligned with parent insert; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| thiscall ECX=map on entry | **Fails** — pure stack args; prolog frame only; `RET 0x14` |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before ret |
| Value is 4 dwords Val16 only | **Fails** — key dword + `FUN_005114e0` vector copy at +0x10 |
| isnil set from color arg | **Fails** — hard isnil=0 @+0x21; color separate @+0x20 |
| color at +0x28 / node 0x28 | **Fails** — color @+0x20; `new(0x24)` |
| Same body as Val16 buynode `00408990` | **Fails** — different VA/size/payload ctor |
| Multiple callers / global helper pool | **Fails** — single xref from `005119e2` |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Runtime Confirmed | **Fails** — no Launcher; static only |

---

## 3. Agreement with Review A

- Alloc/construct CF + ABI + layout: **agree High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, residual `005114e0` dual, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with Val16 isnil21 buynode `00408990` or Val24 isnil29 buynodes (`00407e30` / `005a2de0`).
- Vector ctor `FUN_005114e0` undualed residual (R13-029, not OWN) — element English open.
- Parent insert already dualed R12-014; do not re-dual here.

**Verdict:** **accept-with-gaps**
