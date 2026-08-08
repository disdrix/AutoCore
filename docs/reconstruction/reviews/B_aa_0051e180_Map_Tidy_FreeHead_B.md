# Review B (skeptical / independent): `aa_0051e180` Map_Tidy_FreeHead_B

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e180` |
| **VA** | `0x0051e180` |
| **Canonical name** | `Map_Tidy_FreeHead_B` |
| **Review date** | `2026-08-04` (WQ9F-H OWN dual) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051e180_Map_Tidy_FreeHead_B.md` |
| **System** | STL / map tidy |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051e180` only | Scaffold; decomp incomplete after delete |
| `Map_EraseRange_B` | **Reject** — this is tidy host, not range erase |
| `Map_Tidy_FreeHead` (same name as 0051da30) | **Reject as identity** — different erase VA |
| `MapHost_CompleteDtor` / scalar deleting dtor | **Reject** — does not free the map facade; only head |
| `StdTree_Tidy_FreeHead_*` | **Reject** — map EraseRange_B family, not Val12 tree |
| `Map_Tidy_FreeHead_B` | **Accept** — matches sealed CF + `_B` twin convention |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Noreturn after delete (decomp warning) | **Fails** — bytes continue; null head/size + ret |
| Frees map facade object | **Fails** — only `operator_delete(head)`; facade nulls fields |
| Partial erase path inside tidy | **Fails** — always full-range args `*head, head` |
| Uses Map_EraseRange (A) not B | **Fails** — call target `0x0051d880` |
| isnil@+0x15 family | **Fails** — callee is EraseRange_B (isnil@+0x29) |
| SEH frame in body | **Fails** — bare 46 B; no ExceptionList |
| Dead / unused | **Fails** — atexit thunk + static map `0xb0427c` |

---

## 3. Agreement with Review A

- Tidy CF + post-delete null from bytes: **agree Confirmed**
- ABI ECX + bare ret: **agree Confirmed**
- Structural `_B` name without product English: **agree**
- Gaps (host class, peer tidies, runtime): **agree open**

---

## 4. Residual risks

- Do not claim this is the object complete dtor — it is map-facade tidy only.
- Outer process exit owns the static storage at `0x00b0427c`; tidy does not free the facade.
- Do not merge with `Map_Tidy_FreeHead` or `FUN_0051e150` (different erase callees).

**Verdict:** **accept-with-gaps**
