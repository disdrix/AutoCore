# Review B (skeptical / adversarial): `aa_0041c7e0` LockedList_InsertPayloadTail_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041c7e0` |
| **VA** | `0x0041c7e0` |
| **Canonical name** | `LockedList_InsertPayloadTail_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041c7e0_LockedList_InsertPayloadTail_Inferred.md` |
| **System** | skills-abilities / CS-protected locked list |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Head insert / push-front | Writes update `list+0x20` as tail; first node only seeds `+0x1C` | **Falsified head-insert** |
| 2 | Singly-linked only | Both `node+0x0C` (prev) and old_tail`+0x08` (next) written | **Falsified singly** |
| 3 | Soft-fail returns HRESULT on lock | Throws via `_CxxThrowException`; no return on fail | **Falsified soft-fail** |
| 4 | cdecl / caller cleans stack | Epilogue `ret 8`; parent `0041ac60` does not `add esp` after call | **Falsified cdecl** |
| 5 | Flag `+0x28` means “enabled” like iterator require-nonzero | Insert rejects when **non-zero** (opposite of TryAdvance require-nonzero) | **Partial** — same byte, inverted sense for insert vs iterate |

---

## 2. Live ≡ raw

Live `decompile_function` @ `0x0041c7e0` (autoassault.exe, 2026-07-29) matches `raw/aa_0041c7e0_FUN_0041c7e0.md` control flow, throw constants, and link order. `read_memory` confirms `ret 8` and CS enter/leave IAT calls.

---

## 3. Surviving contract

```
// stdcall: int InsertPayloadTail(LockedList* list, void* payload)
// EnterCS → if flag+0x28: throw E_ACCESSDENIED
// node = vtbl+4(0); if !node: throw E_OUTOFMEMORY
// doubly link at tail; count++; LeaveCS; return 0
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; naming remains `_Inferred` where product symbols absent. Flag polarity vs iterator sibling documented as intentional dual-mode use of `+0x28`.
