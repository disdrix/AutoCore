# Review B (skeptical / independent): `aa_0051e1b0` Map_Tidy_FreeHead_Isnil15_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e1b0` |
| **VA** | `0x0051e1b0` |
| **Canonical name** | `Map_Tidy_FreeHead_Isnil15_B` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051e1b0_Map_Tidy_FreeHead_Isnil15_B.md` |
| **System** | STL / map tidy |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051e1b0` only | Scaffold only; under-describes sealed tidy role |
| `MapHost_CompleteDtor_*` product class | **Reject without RTTI** — body is bare tidy; consumer is atexit vector iterator, not vtbl scalar delete |
| `Map_Tidy_FreeHead` / `_B` / `Isnil1d_Inferred` same VA | **Reject** — different erase-range families |
| `Map_Tidy_FreeHead_Isnil15_B` | **Accept** — template twin + isnil15_B discriminator from dualed callee |
| Skill/host-specific dtor English | **Reject** — no skill strings; multi-domain STL helper |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| operator_delete is true noreturn / no nulls | **Fails** — bytes write head=0 size=0 then RET |
| Function frees the map facade (`this`) | **Fails** — only `operator_delete(head)` |
| Partial erase not full clear | **Fails** — args are `*head, head` full-range form |
| Uses isnil@+0x29 `Map_EraseRange` / `_B` | **Fails** — call target `0x0051d940` is isnil15_B dual |
| Vtbl complete dtor of named class | **Fails** — atexit vector dtor over static array |

---

## 3. Agreement with Review A

- Tidy CF + ABI + null epilogue: **agree Confirmed**
- Structural twin name with isnil15_B discriminator: **agree**
- Gaps (host English, runtime): **agree open**

---

## 4. Residual risks

- Decompiler will keep dropping post-delete nulls — agents must use bytes/annotated.
- Do not claim product host name for `0xb04288` without RTTI/string evidence.
- Keep distinct from peer tidies `0051da30` / `0051e120` / `0051e150` / `0051e180`.

**Verdict:** **accept-with-gaps**
