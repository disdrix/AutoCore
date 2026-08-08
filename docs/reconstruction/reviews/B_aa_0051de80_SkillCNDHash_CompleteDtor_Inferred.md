# Review B (skeptical / adversarial): `aa_0051de80` SkillCNDHash_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051de80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9G-A) |
| **Counterpart** | `reviews/A_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This VA is the scalar deleting dtor | **Falsified** — scalar is `0x0051de60` (vtbl[0]); this is its complete-body callee |
| 2 | Lock aborts / noreturn | **Falsified** — log then fall through to destroy + freelist teardown |
| 3 | Frees host with operator_delete | **Falsified** — bare `C3`; free only in scalar when flags&1 |
| 4 | Inventory CNDHash dtor identity | **Falsified** — skill vtbl `009ce1b8`; skill strings; sizeof/layout family sealed by ctor dual |
| 5 | `FUN_0059c8a0` called with bare `this` | **Falsified** — `LEA ECX,[ESI+0x20]` |
| 6 | `__fastcall` with second reg arg | **Falsified for stack** — ECX=this only; bare ret (thiscall-equivalent) |
| 7 | Product name from VOG_DEBUG_STOP alone | **Reject** — shared debug stop; role from HashError:Destructor + scalar/ctor chain |
| 8 | DestroyBucketTable is the entire dtor | **Falsified** — freelist host teardown follows |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete dtor role | **High** | wrong lifecycle API |
| Soft-lock continue | **High** | false abort on locked destroy |
| Teardown order (table then +0x20 host) | **High** | leak / use-after-free |
| Vtbl family identity | **High** | merge with inventory hash |
| Freelist host algebra of 0059c8a0 | **Med** | residual dual |
| Product English | **Low** | naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against scalar deleting dtor

```
// SkillCNDHash_ScalarDeletingDtor @ 0x0051de60:
//   CALL 0x0051de80          // this complete dtor
//   if (flags & 1) operator_delete(this)
//   return this; RET 4
```

WQ9F-H left complete dtor open as not OWN — this wave seals it. Vtbl[0] remains scalar, not complete body.

---

## 4. Surviving contract for AutoCore

```csharp
// Complete object dtor — does not free host:
void SkillCNDHash_CompleteDtor(SkillCNDHash* self)
{
    self->vtbl = SkillCNDHash_Vtbl; // 009ce1b8
    if (self->lock /*+0x1d*/) {
        Log("HashError:Destructor, already locked for traversal");
        Log("VOG_DEBUG_STOP");
        // continue
    }
    DestroyBucketTable(self);           // 004cba60
    TeardownFreelistSlabHost(self+0x20); // 0059c8a0
}
// Scalar: CompleteDtor(); if (flags&1) delete self;
```

Port must **not** abort on traversal lock and **must not** free host inside complete dtor.

---

## 5. Open questions

1. Product/PDB demangle for class behind `009ce1b8`.  
2. Exact freelist/slab layout dual of `FUN_0059c8a0` at `+0x20`.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
