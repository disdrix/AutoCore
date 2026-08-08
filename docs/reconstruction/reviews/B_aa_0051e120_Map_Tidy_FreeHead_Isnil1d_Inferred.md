# Review B (skeptical / independent): `aa_0051e120` Map_Tidy_FreeHead_Isnil1d_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e120` |
| **VA** | `0x0051e120` |
| **Canonical name** | `Map_Tidy_FreeHead_Isnil1d_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051e120_Map_Tidy_FreeHead_Isnil1d_Inferred.md` |
| **System** | STL / map tidy |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051e120` only | Scaffold only; under-describes sealed tidy role |
| `MapHost_CompleteDtor_*` product class | **Reject without RTTI** — body is bare tidy; sole caller is atexit MOV ECX+JMP, not vtbl scalar delete |
| `Map_Tidy_FreeHead` (same as `0x0051da30`) | **Reject as same VA** — different erase-range family |
| `Map_Tidy_FreeHead_Isnil1d_Inferred` | **Accept** — template twin + isnil discriminator from dualed callee |
| Skill/host-specific dtor English | **Reject** — no skill strings; multi-domain STL helper |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| operator_delete is true noreturn / no nulls | **Fails** — bytes write head=0 size=0 then RET |
| Function frees the map facade (`this`) | **Fails** — only `operator_delete(head)` |
| Partial erase not full clear | **Fails** — args are `*head, head` full-range form |
| Uses isnil@+0x29 `Map_EraseRange` | **Fails** — call target `0x0051d700` is isnil1d dual |
| Vtbl complete dtor of named class | **Fails** — thunk loads absolute global, JMP (atexit pattern) |

---

## 3. Agreement with Review A

- Tidy CF + ABI + null epilogue: **agree Confirmed**
- Structural twin name with isnil1d discriminator + `_Inferred`: **agree**
- Gaps (host English, runtime): **agree open**

---

## 4. Residual risks

- Decompiler will keep dropping post-delete nulls — agents must use bytes/annotated.
- Do not claim product host name for `0xb04240` without RTTI/string evidence.
- Neighbor family tidies are separate OWN partitions.

**Verdict:** **accept-with-gaps**
