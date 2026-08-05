# Review B (skeptical / adversarial): `aa_005b8340` CircularListHead_ClearFreeNodes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b8340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AC) |
| **Counterpart** | `reviews/A_aa_005b8340_CircularListHead_ClearFreeNodes_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Single free only (decompile as-is) | **Falsified by bytes** — loop `75 EE` after `ADD ESP,4` |
| 2 | `operator_delete` is noreturn | **Falsified** — cdecl continue; SEH teardown callers prove multi-call survival |
| 3 | Same as `StdList_Clear` `0x00404060` | **Partial** — similar re-ring+free intent; **differs**: ECX is sentinel (not list+head ptr), **no** size@+8 zero |
| 4 | Owning list with scalar dtor | **Falsified** — bare `operator_delete`, no `push 1; call [vtbl]` |
| 5 | Frees the head/sentinel too | **Falsified** — head re-ringed and retained; walk stops at head |
| 6 | Mission-complete-audio product plate | **Reject** scaffold callee-of name — multi-domain teardown helper |
| 7 | Buffer allocator free (not list) | **Falsified as sole role** — ObjectMotion still separately `operator_delete`s buffers; this clears **embedded lists** (`lea ecx,[buf+8]`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free-loop CF | **High** | Leaked nodes if ported as single free |
| ECX = sentinel head | **High** | Wrong this for port |
| No elem dtor | **High** | Double-free / skipped dtor bugs |
| Link field roles (prev/next labels) | **Med** | Naming only if walk direction sealed |
| Product node type | **Low** | Naming / sizeof |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// 15 UNCONDITIONAL_CALL sites across:
//   004ba0a0, 00593e10, 00594030, 005b85e0, 005bbc50
// ObjectMotion_HostTeardown pattern (bytes @ 005bbc50):
//   lea ecx, [host+0x7dc]; call 005b8340     // host list
//   if primary buf != inline+0x14:
//     lea ecx, [buf+8]; call 005b8340        // per-node list on buffer
//     free buffer; follow buf+0x2f4 chain
// NDSpecialFX path: lea ecx,[obj+0x7dc]; call; lea ecx,[inline+0x1c]; call
```

Scaffold decompile ≡ incomplete loop. W37-AC hex restores multi-node free. Closes W30-S residual “exact FUN_005b8340 ECX buffer headers” for the clear **primitive** (headers are 8-byte circular heads; payload type still open).

---

## 4. Surviving contract for AutoCore

```
// Port as circular list clear on embedded head:
void ClearFreeNodes(ListHead* head) {
  Node* first = head->link4;
  head->link4 = head;
  head->link0 = head;
  if (!first || first == head) return;
  for (Node* n = first; n != head; ) {
    Node* next = n->link4;
    ::operator delete(n);   // no T dtor
    n = next;
  }
}
// Do NOT free head. Do NOT assume size field. Do NOT trust decompile-only single free.
```

---

## 5. Verdict

Adversarial pass confirms A on free-loop/ABI/re-ring; rejects decompile-as-complete, mission scaffold plate, and scalar-dtor list alias. Residual product node type → **accept-with-gaps**.
