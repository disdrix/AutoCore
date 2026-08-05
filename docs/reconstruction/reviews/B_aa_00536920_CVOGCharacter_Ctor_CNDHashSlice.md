# Review B (skeptical / adversarial): `aa_00536920` CVOGCharacter_Ctor (CNDHash slice)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536920` |
| **VA** | `0x00536920` |
| **Canonical name** | `CVOGCharacter_Ctor_CNDHashSlice` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00536920_CVOGCharacter_Ctor_CNDHashSlice.md` |
| **Live tools** | Independent full decompile + field arithmetic + reset caller `0052b4e0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | All mission hashes use same vtbl | `009cfa4c` / `58` / `64` / `70` / `7c` / `88` mix | **Falsified** one-vtbl claim |
| 2 | `+0x538` is first hash written | Order: `+0x534` then `+0x540`… completed `+0x538` later | **Falsified** write-order≠offset-order |
| 3 | Inline ctor ≡ `FUN_0053b0b0` call | Same field map; **inlined** `operator_new`+init+Alloc, not call to `0053b0b0` | **Attack fails** on layout; **Confirmed** not a call |
| 4 | `param_1[0x14e]` is byte offset | dword index → `×4` = `0x538` | **Attack fails** |
| 5 | Dual seals entire character | Huge non-hash init remains | **Attack succeeds** as residual — dual scoped to hashes |
| 6 | Pending hash bits=8 | ctor sets bits=**2**, size=4 | **Falsified** 256-bucket claim |

---

## 2. Cross-check with reset path

`FUN_0052b4e0` (character mission hash reset) reads the same slots:

```
Recreate 00539dd0 on *(char+0x530) using stored bits
vcall +4 (RemoveAll) on +0x548, +0x540, +0x538, +0x53c, +0x544
Recreate 00539e30 on *(char+0x55c)
```

Confirms ctor installs are the live product tables for those fields.

---

## 3. Surviving contract

```
Ctor(this, bFullBaseInit):
  SEH; optional base when bFullBaseInit
  … character body …
  for each mission CNDHash slot:
    p = new 0x34 or null
    if p: vtbl; size=1<<bits; zero lists; bits@+0x1c; lock=0; freelist0; AllocBuckets_twin
    store p at char field
  … more character init …
  return this
```

### Traps

1. **Do not** assume every `009cfa4c` hash has bits=8 — active uses bits=4.
2. **Do not** treat `param_1[N]` as byte offset.
3. Dual does **not** claim full character bit-exact layout.

**Verdict:** **accept-with-gaps.** Accept A on CNDHash slice.
