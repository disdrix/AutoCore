# Review B (skeptical / adversarial): `aa_0041d860` StdTree_Buynode_CharKey_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041d860` |
| **VA** | `0x0041d860` |
| **Canonical name** | `StdTree_Buynode_CharKey_Isnil21_Inferred` |
| **Review date** | `2026-08-05` (OWN-ONLY R13-023) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0041d860_StdTree_Buynode_CharKey_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set buynode |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0041d860` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*` / Client chain | **Reject** — not a client method; shared STL helper |
| `CNDHash_*` / freelist reclaim | **Reject** — CRT `new(0x24)` + tree field stores; no freelist head |
| `StdTree_Buynode_Val16_Isnil21` (`00408990`) | **Reject** — wrong size (0x24≠0x28); char key not Val16 dwords |
| `StdTree_Buynode_Val24_Isnil29` | **Reject** — wrong isnil (+0x21≠+0x29); wrong size family |
| Placement-new freelist buy | **Reject** — `operator_new` not freelist pop |
| Skill/CVOGReaction product API | **Reject as name** — pure STL buynode; system tag is inventory only |
| `StdTree_Buynode_CharKey_Isnil21_Inferred` | **Accept** — family-aligned with parent insert; `_Inferred` honest |
| Runtime Confirmed | **Reject** — no Launcher / no live probe |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| thiscall ECX=map on entry | **Fails** — pure stack args; `RET 0x14`; ECX only loaded for nested value ctor |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before ret; analyze warns void display is false |
| Value is 4 dwords Val16 only | **Fails** — char @+0x0C + thiscall residual @+0x10 (not 4 dword stores) |
| isnil set from color arg | **Fails** — hard isnil=0 @+0x21; color separate @+0x20 from `[EBP+0x18]` |
| color at +0x28 | **Fails** — color @+0x20 for this family |
| Same body as Val16 buynode `00408990` | **Fails** — different size/args/payload shape |
| Multiple callers beyond insert | **Fails** — sole xref `0041ba9d` in `FUN_0041ba30` |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Decompiler shows no this for `FUN_0041c140` ⇒ not thiscall | **Fails** — bytes `LEA ECX,[ESI+0x10]` seal thiscall |

---

## 3. Agreement with Review A

- Alloc/construct CF + ABI + layout: **agree High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, residual value dual, runtime): **agree open**
- Runtime Confirmed: **not claimed**

---

## 4. Residual risks

- Do not merge with Val16 isnil21 buynode `00408990` or Val24 isnil29 buynodes (`00407e30` / `005a2de0`).
- Residual value ctor `FUN_0041c140` undualed (not OWN) — element type English open.
- Parent insert already dualed R12-011; placement parent `0041a570` still residual (not OWN).

**Verdict:** **accept-with-gaps**
