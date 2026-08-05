# Review B (skeptical / adversarial): `aa_0053b920` CNDHash_Dtor_009cfa7c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b920` |
| **VA** | `0x0053b920` |
| **Canonical name** | `CNDHash_Dtor_009cfa7c` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b920_CNDHash_Dtor_009cfa7c.md` |
| **Live tools** | Independent decompile + `read_memory` + FreeBuckets/reclaim chain + vtbl slot0 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Non-owning like dtor `009cfa70` | FreeBuckets is `005390d0` → reclaim `00538190` **deletes values** | **Falsified** non-owning claim — this family is **owning** |
| 2 | Bare `FUN_0059c8a0()` on hash this | Machine `lea ecx,[esi+0x20]` | **Falsified** bare-this claim — freelist subobject |
| 3 | Lock path aborts dtor | Log only; FreeBuckets always runs | **Attack fails** (non-fatal) |
| 4 | Scalar dtor body is this | `0053b900` wraps + optional delete | **Falsified** merge — this is body only |
| 5 | FreeBuckets exclusive to dtor | Also Recreate `00539dd0` | **Falsified** exclusive claim |
| 6 | Product name `CNDHash_Dtor_009cfa7c` | No PDB English | **Open** — inferred OK |

---

## 2. Surviving contract

```
Dtor_009cfa7c:
  SEH; vtbl 009cfa7c; lock log non-fatal
  FreeBuckets_005390d0 → reclaim 00538190 (OWNING, stamp 009cefe4) + free table
  FreelistSlabVector_dtor(this+0x20)
  bare ret
```

### Traps

1. **Do not** treat as non-owning twin of `0053b810` — values **are** deleted in FreeBuckets reclaim.
2. Freelist call **requires** `this+0x20` — wrong ECX double-frees or skips slabs.
3. External holders of values are invalid after dtor (ownership inside hash).
4. Scalar wrapper `0053b900` is separate; do not merge optional `operator_delete` into this plate.

**Verdict:** **accept-with-gaps.** Accept A.
