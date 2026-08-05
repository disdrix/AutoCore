# Review B (skeptical / adversarial): `aa_0053b810` CNDHash_Dtor_009cfa70

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b810` |
| **VA** | `0x0053b810` |
| **Canonical name** | `CNDHash_Dtor_009cfa70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b810_CNDHash_Dtor_009cfa70.md` |
| **Live tools** | Independent decompile + reclaim walk + scalar dtor |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Owning like `009cfa64` dtor | Reclaim has no value free | **Falsified** owning claim |
| 2 | FreeBuckets shared with recreate `00539d70` | Recreate uses `00539090`, not `0053b880` | **Falsified** share claim |
| 3 | Loop exclusive upper bound | `u <= mask` inclusive | **Attack fails** |
| 4 | Product name for `+0x6f0` hash | Install only; no registry English | **Open** |
| 5 | Scalar dtor body is this | `0053b7f0` wraps + optional delete | **Falsified** merge |

---

## 2. Surviving contract

```
Dtor_009cfa70:
  vtbl 009cfa70; lock log non-fatal
  FreeBuckets_0053b880 → reclaim 0053b8c0 (NON-owning) + free table
  freelist slab vector teardown
```

### Traps

1. External value ownership — free payloads before dtor or leak.
2. **Do not** pair FreeBuckets with recreate `00539090` family.
3. Char field is **`+0x6f0`**, not mission hash cluster `+0x530..+0x55c`.

**Verdict:** **accept-with-gaps.** Accept A.
