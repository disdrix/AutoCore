# Review B (skeptical / adversarial): `aa_004ba770` StdMap_FreeSubtree_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba770` |
| **VA** | `0x004ba770` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ba770_StdMap_FreeSubtree_Isnil15_Inferred.md` |
| **Evidence** | Live decompile + full-body `read_memory` + 3 xrefs |
| **Agent** | W20-N OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler body is complete | Bytes show post-delete left walk `mov esi,[esi]; … jz loop` | **Falsified decompiler completeness** |
| 2 | `operator_delete` never returns (WARNING) | Code after call: isnil test + loop/return | **Falsified noreturn** |
| 3 | This is `__thiscall` with ECX = node | Node loaded from `[esp+0x10]` after 3 pushes; ECX only threaded | **Falsified thiscall-as-node** |
| 4 | Only frees right child once (no left) | Loop continues on left | **Falsified single-child** |
| 5 | isnil at `+0x49` (mission staging family) | Body uses `+0x15` | **Falsified wrong family** |
| 6 | Same as single erase `FUN_004baa30` | No throw string; no rebalance; recursive free only | **Falsified conflation** |
| 7 | Product name sealed | Name is role-inferred from layout + callers | **Accepted gap** |
| 8 | `ret` without stack cleanup | Epilogue `C2 04 00` | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Left-walk free CF | **Confirmed** | Leaks map nodes |
| ABI `ret 4` | **Confirmed** | Stack smash |
| isnil `+0x15` family | **Confirmed** | Wrong tree layout |
| Product name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs callers

`StdMap_EraseRange_Inferred` owns range erase policy and head reset; this unit owns **only** recursive node free. Do not merge ownership of `004bacf0` / `004baa30` into this dual.

---

## 4. Byte anchors

```text
0x004ba770: 53 56 57 8B 7C 24 10
            80 7F 15 00          ; isnil +0x15
            8B D9 8B F7 75 1E    ; save ECX; jnz done
            8B 46 08 50 8B CB E8 ; push right; call self
            8B 36 57 E8 …        ; left; delete
            83 C4 04 80 7E 15 00
            8B FE 74 E6          ; loop if left not nil
            5F 5E 5B C2 04 00
```

---

## 5. What would reverse the seal?

- Proof that left @ `+0` is not the next free target (would reclassify walk).
- Discovery that nodes require a value dtor call missing from this body (would reclassify as incomplete free helper only when payloads live in-node).

None observed from decompile + bytes + caller duals.
