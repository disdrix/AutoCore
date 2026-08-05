# Review B (skeptical / independent): `aa_0051cb40` Map_EraseNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051cb40` |
| **VA** | `0x0051cb40` |
| **Canonical name** | `Map_EraseNode` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051cb40_Map_EraseNode.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051cb40` only | Acceptable scaffold; under-describes sealed role |
| `Named_CalleeOf_CVOGHBAIBase_GetTargetFromAggro_0051cb40` | **Reject** — one of four callers; generic erase |
| `Skill_EraseCastBindingNode` | **Reject** — also used by AI aggro + range wrappers |
| `Map_EraseNode_IntKey` | **Reject** — that name is `0x005d1df0` (isnil@+0x15) |
| `Map_EraseNode` | **Accept** — STL erase + family match ExactFind |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function only frees without rebalance | **Fails** — color loop + rot callees present |
| No size field | **Fails** — post-delete `dec [ebp+8]` when >0 |
| `ret 4` only one stack arg | **Fails** — `ret 8`; call sites pass `&it, node` |
| operator_delete is true noreturn | **Fails** — bytes continue to size/out/ret |
| Same as isnil@+0x15 family | **Fails** — gate uses `+0x29` |

---

## 3. Agreement with Review A

- STL identity + ABI + post-delete commit: **agree Confirmed**
- Structural name without product English: **agree**
- Gaps (PDB, payload English, runtime): **agree open**

---

## 4. Residual risks

- Decompiler will keep lying about `operator_delete` noreturn — agents must use annotated/bytes for size/`pOutIt`.
- Do not merge with `Map_EraseNode_IntKey` without isnil-offset check.

**Verdict:** **accept-with-gaps**
