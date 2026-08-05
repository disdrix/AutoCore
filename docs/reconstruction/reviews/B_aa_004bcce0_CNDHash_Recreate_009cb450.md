# Review B (skeptical / adversarial): `aa_004bcce0` CNDHash_Recreate_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcce0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bcce0_CNDHash_Recreate_009cb450.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `param_2` is bucket **count** | `1 << param_2` into +0x08 | **Falsified** — **log2** |
| 2 | Locked traversal aborts | Fall-through after dual log | **Falsified** |
| 3 | Same as `004bcd40` / interchangeable | Free/Alloc stamps differ | **Falsified** |
| 4 | Rehashes existing keys | Free then empty Alloc | **Falsified** |
| 5 | Caller may pass arbitrary sizes in practice | Sole site hardcodes **5** | **Survives** as observed use; API still takes log2 |
| 6 | Bare ret | `C2 04 00` | **Falsified** |
| 7 | `+0x08` remains N | Alloc → mask N-1 | **Falsified** |
| 8 | `Named_VOG_DEBUG_STOP_*` product name | lock-warn only | **Falsified** |
| 9 | Many callers | Single xref `004bbeb8` | **Confirmed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| log2 polarity | **High** | 2^N wrong size |
| tableC family stamps only | **High** | Cross-family free/alloc |
| Caller always 5 | **High** | Unexpected mask if host changes |
| Lock continue | **High** | Wrong abort contract |
| ret 4 | **High** | ABI break |

---

## 3. Cross-check against raw / bytes

```
raw:   lock-log; Free 004bcc60; log2/N/head/tail; Alloc 004bc7a0; ret
bytes: … E8→004bcc60 … D3 E0 … E8→004bc7a0 … C2 04 00
caller: FUN_004bbeb0: FUN_004bcce0(5); …
ctor path: CNDHash_Ctor_009cb450(5) always (W28-J)
alloc: stamp 009cb348; gate log2 1..16 (W29-K)
```

---

## 4. Surviving contract for AutoCore

```csharp
// CNDHash stamp 009cb450 — Recreate (tableC family)
void CNDHash_Recreate_009cb450(CNDHash self, byte log2)
{
    if (self.lock1d != 0) { Log(...Recreate locked...); Log("VOG_DEBUG_STOP"); }
    FreeBuckets_004bcc60(self);       // not 004bcca0
    self.log2 = log2;
    self.listTail = 0;
    self.countOrMask = 1u << (log2 & 0x1f);
    self.listHead = 0;
    AllocBucketTable_004bc7a0(self);  // stamp 009cb348
}
// Observed: host always Recreate(5) → 32 buckets → mask 31
// ret 4
```

**Port traps to reject:**

- Using hashA/hashB Free/Alloc (`004bcca0` / `004bc840`).
- Treating hard-coded 5 as the only legal log2 (Alloc still gates 1..16).
- Expecting content preservation across recreate.
- Passing count instead of log2.

---

## 5. Residual gaps (do not block seal)

1. Runtime / image diff.
2. FreeBuckets OWN; host `FUN_004bbeb0` product name.
3. Full product English.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break the tableC Recreate contract. Residual is FreeBuckets/host OWN + verification depth only.
