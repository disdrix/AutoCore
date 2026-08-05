# Review B (skeptical / adversarial): `aa_0055eb80` PhysSim_ActivateHost

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055eb80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0055eb80_PhysSim_ActivateHost.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **removes** from `world+0x108` list | Confuse with `0x55e490` | **Falsified** — pushes onto `world+8` active array; no `+0x108` touch |
| 2 | Clears ready flag (`+0x29=0`) | Polarity flip | **Falsified** — stores **`1`** |
| 3 | Ghidra `FUN_0055eb80(host)` one-arg form is ABI | PrepareReady under-arity | **Falsified** — asm ECX=world, stack=host |
| 4 | Sole caller is PrepareReady | Incomplete xrefs | **Falsified** — 5 caller funcs |
| 5 | Always called unconditionally from PrepareReady | Miss gates | **Falsified** — only if `host+0x29==0` **and** `host+0x24!=-1` |
| 6 | Grow step is optional decoration | Skip capacity check | **Falsified** — when count==cap, `FUN_005b3370` must run or overflow |
| 7 | Name string-proven | Symbol inflation | **Not sealed** — Probable role only |
| 8 | Sets body vtbl / Havok pose | Overfit phys write helpers | **Falsified** — list + flags only; no rigid-body vtbl |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ready flag `host+0x29=1` | **High** | Writes silently dropped forever |
| Active list push world+8/+0xc | **High** | Host never simulated |
| Free-list rewire CF | **High** | Corrupt indices / crash |
| Free-list English semantics | **Probable** | Doc only |
| `FUN_0062a6c0` role | **Medium** | Miss post-hook |
| Product name | **Low–Med** | Naming only |

---

## 3. Cross-check against raw

```text
// raw aa_0055eb80 ≡ live decompile 2026-07-29
if count == (cap & 0x7fffffff): grow(+8 vec, 4)
arr[count] = host; count++
// free-list shuffle using host+0x24, world+0x14/+0x18
host+0x24 = count-1
host+0x29 = 1
host+0x34 = host+0x38 = 0
FUN_0062a6c0(world, host)
host+0x30 = 0
```

Contrast `aa_0055e490`: scan `+0x108`, swap-remove, optional dtor.

---

## 4. Surviving contract for AutoCore

```
PhysSim_ActivateHost(world, host):
  ensure active capacity
  append host to active ptrs
  rewire free-list slot host.index(+0x24)
  host.ready(+0x29) = 1
  clear host+0x34/38; notify FUN_0062a6c0; clear host+0x30

// PrepareReady coupling:
//   RemoveTrackedObject(world, phys)   // 0x55e490 — often no-op
//   if !host.ready && host.index != -1:
//       ActivateHost(world, host)
```

**Port tests:**

* Must set `+0x29=1` (probe depends on it).
* Must not implement remove-list logic here.
* Must grow before overflow push.
* Must pass world as `this`.

---

## 5. Open questions

1. Full free-list invariants and `+0x24 == -1` producer.
2. `FUN_0062a6c0` body dual.
3. Whether double-activate without gate corrupts free-list.
4. Runtime / product name.

**Verdict:** **accept-with-gaps** — attacks conflating activate vs remove or flipping ready polarity **fail**; residual free-list depth and naming open.
