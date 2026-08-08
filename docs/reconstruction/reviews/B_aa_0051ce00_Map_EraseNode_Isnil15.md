# Review B (skeptical / independent): `aa_0051ce00` Map_EraseNode_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051ce00` |
| **VA** | `0x0051ce00` |
| **Canonical name** | `Map_EraseNode_Isnil15` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051ce00_Map_EraseNode_Isnil15.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051ce00` only | Acceptable scaffold; under-describes sealed role |
| `Skill_*Erase*` product | **Reject** — multi-caller generic STL; no skill strings in body |
| `Map_EraseNode` (same as `0x0051cb40`) | **Reject as same VA** — different isnil family (+0x29) |
| `Map_EraseNode_B` | **Reject** — `_B` is isnil29 twin at `0x00409220` |
| `Map_EraseNode_IntKey` | **Reject as this VA** — that name is dualed `0x005d1df0` (also isnil15, different callees) |
| `Map_EraseNode_Isnil15` | **Accept** — structural; pairs `Map_EraseRange_Isnil15` |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function only frees without rebalance | **Fails** — color loop + rot callees present |
| isnil is +0x29 like Map_EraseNode | **Fails** — gate uses `+0x15`; color `+0x14` |
| No size field | **Fails** — post-delete `dec [map+8]` when >0 |
| `ret 4` only one stack arg | **Fails** — `ret 8`; callers pass `&it, node` + ECX=map |
| operator_delete is true noreturn | **Fails** — bytes continue to size/out/ret |
| Decomp “unreachable” means dead transplant | **Fails** — mid-body bytes implement two-child path |
| Identical to Map_EraseNode_IntKey | **Fails** — different VA + Min/Max/rot callees |

---

## 3. Agreement with Review A

- STL identity + ABI + post-delete commit: **agree Confirmed**
- Structural isnil15 name: **agree**
- Gaps (PDB, payload English, runtime): **agree open**

---

## 4. Residual risks

- Decompiler will keep lying about `operator_delete` noreturn — agents must use annotated/bytes for size/`outIt`.
- Do not merge with `Map_EraseNode_IntKey` (`0x005d1df0`) without noting distinct instantiation.
- Range parent dualed; other callers undualed residuals.

**Verdict:** **accept-with-gaps**
