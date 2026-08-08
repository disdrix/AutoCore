# Review B (skeptical / independent): `aa_005a4870` StdTree_Buynode_Isnil21_Node0x24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4870` |
| **VA** | `0x005a4870` |
| **Canonical name** | `StdTree_Buynode_Isnil21_Node0x24_Inferred` |
| **Review date** | `2026-08-05` (R13-008; dual start **2686**) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_005a4870_StdTree_Buynode_Isnil21_Node0x24_Inferred.md` |
| **System** | skills-abilities partition label; STL buynode |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_005a4870` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_005a4950` / skill UI chain | **Reject** — shared STL helper; not a skill method |
| `CNDHash_*` / freelist reclaim | **Reject** — CRT `new(0x24)` + tree construct; no freelist head |
| `StdTree_Buynode_Val16_Isnil21` (`00408990`) | **Reject** — wrong size (0x24≠0x28); no flat 4-dword copy; uses `005a42d0` |
| `StdTree_Buynode_Val24_Isnil29` | **Reject** — isnil@+0x21≠+0x29; node 0x24≠0x30 |
| Placement-new freelist buy | **Reject** — `operator_new` not freelist pop |
| thiscall map method | **Reject** — pure stack args; `RET 0x14` |
| `StdTree_Buynode_Isnil21_Node0x24_Inferred` | **Accept** — family-aligned with insert dual; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| thiscall ECX=map on entry | **Fails** — stack args only; ECX loaded solely for `005a42d0` (`LEA ECX,[ESI+0x10]`) |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before ret |
| Flat Val16 POD value | **Fails** — key dword + `FUN_005a42d0` vector path; heap @+0x14 |
| isnil set from color arg | **Fails** — hard isnil=0 @+0x21 (`C6 46 21 00`) |
| color at +0x24 / wrong size | **Fails** — color @+0x20; `PUSH 0x24` alloc |
| Same body as Val16 buynode `00408990` | **Fails** — different size, construct, payload helper |
| Same unit as erase `005a4590` | **Fails** — erase is thiscall ret 8 consumer of nodes this unit buys |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Runtime Confirmed | **Fails** — no Launcher / live hit; terminal false |

---

## 3. Agreement with Review A

- Alloc/construct CF + ABI + layout + sole caller: **agree High**
- Name with `_Inferred` + Node0x24 family tag: **agree**
- Gaps (PDB, payload ctor dual residual, runtime): **agree open**

---

## 4. Residual risks

- Do not merge with Val16 isnil21 `00408990` or Val24 isnil29 `00407e30` / `005a2de0`.
- Payload ctor `FUN_005a42d0` undualed residual (not OWN).
- skills-abilities partition must not become a product-only name.

**Verdict:** **accept-with-gaps**
