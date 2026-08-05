# Review B (skeptical / adversarial): `aa_004bcd40` CNDHash_Recreate_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcd40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bcd40_CNDHash_Recreate_009cb45c.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `param_2` is bucket **count** | Body does `1 << param_2` into +0x08 | **Falsified** — param is **log2** |
| 2 | Locked traversal **aborts** | `je` skips logs only; Free+Alloc always run | **Falsified** — warn-only |
| 3 | Rehashes / preserves entries | Free then empty Alloc; no reinsert loop | **Falsified** — destroy + empty |
| 4 | Same as `004bcce0` / mergeable | Free `004bcca0` vs `004bcc60`; Alloc `004bc840` vs `004bc7a0` | **Falsified** — distinct family |
| 5 | Bare `ret` / cdecl | Exit `C2 04 00` | **Falsified** — `ret 4` |
| 6 | `+0x08` stays as count after return | AllocBucketTable sets mask `N-1` (W29-K) | **Falsified** as permanent size |
| 7 | `Named_VOG_DEBUG_STOP_*` is product id | String only on lock-warn path | **Falsified** |
| 8 | Has static callers like twin | Zero xrefs | **Confirmed residual** — unreferenced in this image |
| 9 | Not CNDHash | Recreate string + Free/Alloc twins sealed as CNDHash | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| log2 vs count polarity | **High** | Wrong table size |
| Lock continues | **High** | False abort contract |
| Must use Free `004bcca0` + Alloc `004bc840` | **High** | Wrong stamp / free path |
| Do not use for tableC (`009cb450`) | **High** | Cross-family corruption |
| ret 4 | **High** | Stack imbalance |
| Dead/no static callers | **High** (xrefs) | Port may still need method for completeness |

---

## 3. Cross-check against raw / bytes

```
raw:   lock-log; Free 004bcca0; log2/N/head/tail; Alloc 004bc840; ret
bytes: 80 7E 1D 00 74 1B … E8→004bcca0 … D3 E0 … E8→004bc840 … C2 04 00
twin:  004bcce0 same CF, Free 004bcc60 + Alloc 004bc7a0 only
parallel: CNDHash_Recreate 0051d230 identical template
alloc post: +0x08 = N-1 after FUN_004bc840 (W29-K)
```

---

## 4. Surviving contract for AutoCore

```csharp
// CNDHash stamp 009cb45c — Recreate (hashA/hashB family)
void CNDHash_Recreate_009cb45c(CNDHash self, byte log2)
{
    if (self.lock1d != 0) {
        Log("HashError:Recreate, already locked for traversal");
        Log("VOG_DEBUG_STOP");
        // continue
    }
    FreeBuckets_004bcca0(self);       // not 004bcc60
    self.log2 = log2;
    self.listTail = 0;
    self.countOrMask = 1u << (log2 & 0x1f); // provisional N
    self.listHead = 0;
    AllocBucketTable_004bc840(self);  // → mask; stamp 009cb350
}
// ret 4
```

**Port traps to reject:**

- Passing bucket **count** instead of log2.
- Early-return on lock (must continue).
- Using Free/Alloc twins from `009cb450` family.
- Expecting entries to survive recreate.
- Treating `Named_VOG_DEBUG_STOP_*` as the API name.

---

## 5. Residual gaps (do not block seal)

1. Runtime / image diff.
2. FreeBuckets OWN body.
3. Why zero static callers (dead vs future/dynamic).
4. Product English / full vtbl matrix.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break Recreate ABI/CF/stamp contract. Residual is FreeBuckets OWN + zero-caller explanation + verification depth only.
