# Review B (skeptical / adversarial): `aa_0040d7c0` StdTree_Tidy_FreeHead_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d7c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-B) |
| **Counterpart** | `reviews/A_aa_0040d7c0_StdTree_Tidy_FreeHead_Val12.md` |
| **Scratch** | `tmp/a_0040d7c0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete | **Falsified** — false noreturn stops before null head/size and RET |
| 2 | Function is only `erase` without freeing head | **Falsified** — explicit `operator_delete(*(this+4))` then null |
| 3 | Same as clear (`0040d5b0`) | **Falsified** — clear destroys values + frees nodes, **keeps** head; this frees head after erase |
| 4 | Same as free-subtree (`0040d630`) | **Falsified** — this is tidy wrapper; free-subtree is callee of erase path |
| 5 | Operates on full host with head@+8 | **Partial** — unit ECX is tree subobject (host+4); head@tree+4 ≡ host+8 |
| 6 | RET 4 / stack arg | **Falsified** — bare `C3`; ECX-only |
| 7 | Product demangle known | **Open** — structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tidy stage order | **High** | Leak header / double free |
| ABI ECX bare RET | **High** | Stack corruption |
| head@+4 size@+8 | **High** | Wrong fields cleared |
| Full-range erase args | **High** | Incomplete free |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Complete dtor FUN_0040d820 @ 0x0040d85b:
//   LEA ECX,[ESI+4]; CALL FUN_0040d7c0
// After clear FUN_0040d5b0 (values+nodes free, sentinel kept).
// Unwind @009be2b6 also references this unit.
```

Live decompile 2026-07-29 ≡ scaffold raw collapsed shape. Full 92 B hex seals post-delete null + RET. Closes W31-A residual “nested `FUN_0040d7c0` not dual-owned”.

---

## 4. Surviving contract for AutoCore

```
// Port as tree tidy (not clear, not free-subtree alone):
void StdTree_Tidy_FreeHead_Val12(Tree* t) {
  EraseFullRange(t);          // FUN_0040d700(t, &out, *head, head)
  operator_delete(t->head);
  t->head = nullptr;
  t->size = 0;
}
// Call from host complete dtor on this+4 AFTER value-aware clear.
// Ignore Ghidra noreturn / truncated body.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/offsets. Residual product types + nested erase dual → **accept-with-gaps**.
