# Review B (skeptical / adversarial): `aa_004e2940` StdMap_FreeSubtree_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2940` |
| **VA** | `0x004e2940` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e2940_StdMap_FreeSubtree_Val12.md` |
| **Evidence** | Live decompile + full-body `read_memory` + xrefs |
| **Agent** | W29-L OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Decompiler body is complete | Bytes show post-delete left walk + loop | **Falsified decompiler completeness** |
| 2 | `operator_delete` never returns | Code after call tests isnil and loops/returns | **Falsified noreturn** |
| 3 | Thiscall with ECX = node | Node from `[esp+0x10]` after 3 pushes; ECX only threaded | **Falsified thiscall-as-node** |
| 4 | Only frees right once | Left walk loop | **Falsified single-child** |
| 5 | isnil at +0x15 (peer family) | Body uses **+0x19** | **Falsified wrong family** |
| 6 | Same as single erase `004e4130` | No rebalance / no size-- / recursive free only | **Falsified conflation** |
| 7 | Missing value dtor ⇒ incomplete | Same shape as sealed isnil15 free; erase path owns values | **Accepted residual** (documented) |
| 8 | Plain `ret` | Epilogue `C2 04 00` | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Left-walk free CF | **Confirmed** | Map node leaks |
| ABI `ret 4` | **Confirmed** | Stack smash |
| isnil `+0x19` Val12 | **Confirmed** | Wrong tree layout |
| Product name | Open | Doc-only |
| Runtime | Open | — |

---

## 3. Cross-check vs callers

`StdMap_EraseRange_Val12` owns range policy + head reset; this unit owns **only** recursive node free. Do not merge `004e4130` / `004e5120` ownership into this dual. Closes W28-P gap item “full left-recurse proof inside FUN_004e2940”.

---

## 4. Byte anchors

```text
0x004e2940: 53 56 57 8B 7C 24 10
            80 7F 19 00          ; isnil +0x19
            8B D9 8B F7 75 1E    ; save ECX; jnz done
            8B 46 08 50 8B CB E8 ; push right; call self
            8B 36 57 E8 …        ; left; delete
            83 C4 04 80 7E 19 00
            8B FE 74 E2          ; loop if left not nil
            5F 5E 5B C2 04 00
```

---

## 5. What would reverse the seal?

- Proof left @ `+0` is not the free walk target.
- Required in-node value dtor call missing from body (would reclassify completeness).

None observed from decompile + bytes + Val12 family duals.

**Verdict:** **accept**
