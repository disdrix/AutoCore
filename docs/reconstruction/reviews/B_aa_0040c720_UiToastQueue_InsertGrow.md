# Review B (skeptical / adversarial): `UiToastQueue_InsertGrow` / `FUN_0040c720` @ `0x0040c720`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040c720_UiToastQueue_InsertGrow.md` |
| **Verdict** | **accept** on CF/stride/thiscall; reject decompiler this-elision and “this is push” overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** `Client_UiToastQueue_Push` | **Falsified** — push is `0040c5c0`; this is grow branch only |
| 2 | Ghidra `FUN_0040c720(&param_2, end, elem)` means ECX is element | **Falsified** — bytes `mov edi,ecx` then `mov ecx,edi` before insert call |
| 3 | Inserts multiple elements | **Falsified** — hard-coded `push 1` |
| 4 | Element stride ≠ `0x98` | **Falsified** — same `/0x98` magic as parent |
| 5 | Performs POD copy itself (`00404710`) | **Falsified** — only callee `00403980` (which may call copy helpers) |
| 6 | Formats "Received Mission" / craft strings | **Falsified** — no string ops |
| 7 | Out-iterator is unused | **Falsified** — writes `*param_2` after grow |
| 8 | Product name required | **Open** — structural OK |
| 9 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX = queue this | **Confirmed** | Insert into wrong object |
| Insert count = 1 | **Confirmed** | Multi-insert corruption |
| Index math /0x98 | **Confirmed** | Wrong out iterator after realloc |
| Sole static caller = push grow | **High** | Naming only if more appear |
| Role = grow bridge | **High** | Ports merging push+grow into one API still OK if CF preserved |
| Product symbol | **Open** | Docs |

---

## 3. Surviving contract for AutoCore

```
// Called only when push cannot take the fast path (empty or full).
void UiToastQueue_InsertGrow(ToastQueue* q, void** outIt, void* pos /*usually end*/, ToastElem* e):
  idx = (q.begin && q.size()) ? (pos - q.begin) / 0x98 : 0
  q.InsertN(pos, 1, *e)          // FUN_00403980
  *outIt = q.begin + idx * 0x98  // post-realloc begin

// NOT the public push API (that's 0040c5c0).
// NOT mission grant.
```

---

## 4. Cross-check vs parent dual

Parent B already sealed:

- Grow path: `MOV ECX,ESI; CALL 0x0040c720`
- Decompiler this-elision on grow is a **known artifact**

This dual reconfirms the callee side of that claim.

---

## 5. Open questions

1. Retail name.
2. Whether `outIt` is consumed by any push caller (parent often ignores) — residual of **caller**, not this CF.
3. Full insert realloc policy — owned by `00403980`.

**Verdict:** **accept**. Reject identity-with-push, wrong-`this`, multi-insert, and string/mission overclaims.
