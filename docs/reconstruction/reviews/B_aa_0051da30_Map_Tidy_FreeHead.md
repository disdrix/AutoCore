# Review B (skeptical / independent): `aa_0051da30` Map_Tidy_FreeHead

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051da30` |
| **VA** | `0x0051da30` |
| **Canonical name** | `Map_Tidy_FreeHead` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051da30_Map_Tidy_FreeHead.md` |
| **System** | STL / map tidy |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051da30` only | Scaffold; decomp incomplete after delete |
| `Map_EraseRange` | **Reject** — this is tidy host, not range erase |
| `MapHost_CompleteDtor` / scalar deleting dtor | **Reject** — does not free the map facade; caller may |
| `StdTree_Tidy_FreeHead_Bare_Val12` | **Reject as identity** — Val12 / different erase VA |
| `Object_Map68_Dtor` | **Reject** — over-narrow; also SEH unwind; no product class sealed |
| `Map_Tidy_FreeHead` | **Accept** — matches sealed CF + peer tidy template |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Noreturn after delete (decomp warning) | **Fails** — bytes continue; null head/size + ret |
| Frees map facade object | **Fails** — only `operator_delete(head)`; facade nulls fields |
| Partial erase path inside tidy | **Fails** — always full-range args `*head, head` |
| isnil@+0x15 family | **Fails** — callee is `Map_EraseRange` (isnil@+0x29) |
| SEH frame in body | **Fails** — bare 46 B; no ExceptionList |

---

## 3. Agreement with Review A

- Tidy CF + post-delete null from bytes: **agree Confirmed**
- ABI ECX + bare ret: **agree Confirmed**
- Structural name without product English: **agree**
- Gaps (host class, peer tidies, runtime): **agree open**

---

## 4. Residual risks

- Do not claim this is the object complete dtor — it is map-facade tidy only.
- Outer `FUN_00518ec0` may still `operator_delete` the map object after return.
- Peer `FUN_0051e150` uses different EraseRange (`Map_EraseRange_Isnil15`) — do not merge.

**Verdict:** **accept-with-gaps**
