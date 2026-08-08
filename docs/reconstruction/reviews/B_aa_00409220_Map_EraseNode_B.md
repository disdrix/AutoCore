# Review B (skeptical / independent): `aa_00409220` Map_EraseNode_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409220` |
| **VA** | `0x00409220` |
| **Canonical name** | `Map_EraseNode_B` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00409220_Map_EraseNode_B.md` |
| **System** | STL / map-set |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00409220` only | Acceptable scaffold; under-describes sealed role |
| `Named_CalleeOf_*CreateVehicleObjectApply_00409220` | **Reject** — one caller cluster; shared erase |
| `Skill_EraseCastBindingNode` | **Reject** — multi-caller generic STL |
| `Map_EraseNode` (same as `0x0051cb40`) | **Reject as same VA** — distinct clone; use **`_B`** |
| `Map_EraseNode_IntKey` | **Reject** — that name is isnil@+0x15 family |
| `Map_EraseNode_B` | **Accept** — twin pattern (`Map_EraseRange_B`) |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Function only frees without rebalance | **Fails** — color loop + rot callees present |
| No size field | **Fails** — post-delete `dec [map+8]` when >0 |
| `ret 4` only one stack arg | **Fails** — `ret 8`; callers pass `&it, node` |
| operator_delete is true noreturn | **Fails** — bytes continue to size/out/ret |
| Same as isnil@+0x15 family | **Fails** — gate uses `+0x29` |
| Identical image body as `0051cb40` | **Fails** — different VA/throw construction; CF twin only |
| Decomp “unreachable” means dead transplant | **Fails** — mid-body bytes implement two-child path |

---

## 3. Agreement with Review A

- STL identity + ABI + post-delete commit: **agree Confirmed**
- Structural `_B` twin name: **agree**
- Gaps (PDB, payload English, runtime): **agree open**

---

## 4. Residual risks

- Decompiler will keep lying about `operator_delete` noreturn — agents must use annotated/bytes for size/`outIt`.
- Do not merge with `Map_EraseNode` (`0x0051cb40`) as one symbol without noting twin VA.
- Range parent `FUN_00407d70` undualed residual.

**Verdict:** **accept-with-gaps**
