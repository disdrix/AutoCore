# Review B (skeptical / adversarial): `aa_0062a6c0` PhysSim_PostActivateNotify

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062a6c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0062a6c0_PhysSim_PostActivateNotify.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sets host ready `+0x29` | Conflate with ActivateHost | **Falsified** — ready store is in parent `0x55eb80` only |
| 2 | Forward iteration only | Assume vector order | **Falsified** — reverse `i--` on both world list and sublists |
| 3 | Compacts during notify | Single loop | **Falsified** — **two** reverse loops: notify then compact |
| 4 | World list at `+8` (active hosts) | Confuse ActivateHost array | **Falsified** — this uses **`+0x78/+0x7c`**, different list |
| 5 | Teleport-only helper | Scaffold name | **Falsified as exclusive** — ActivateHost always calls it; teleport uses ActivateHost |
| 6 | Null listeners crash | No check | **Falsified** — null skip before vcall |
| 7 | `FUN_005fff20` is optional | Reorder | **Falsified** — always called between world notify and host walk |
| 8 | Name is PDB-proven | Inflation | **Not sealed** — **Probable** role name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Offsets `world+0x78/7c`, `host+0x3c/40`, `entry+0x70/74` | **High** | Miss notifications / corrupt lists |
| Vtbl slots `+4` / `+8` | **High** (slot) / **Low** (name) | Wrong callback |
| Compact-after-notify order | **High** | Use-after-free if merged wrong |
| `FUN_005fff20` necessity | **High** | Dropped world flush |
| Product name | **Medium** | Doc only |

---

## 3. Cross-check against raw

```text
// raw aa_0062a6c0 ≡ live
// param_1 = world, param_2 = host
for i = world.count78 - 1 .. 0:
  p = world.list78[i]; if p: p->vtbl[+4](host)
FUN_005fff20()
for i = 0 .. host.count3c:
  e = host.list3c[i]
  for j = e.count70 - 1 .. 0:
    c = e.list70[j]; if c: c->vtbl[+8](e)
  for j = e.count70 - 1 .. 0:
    if e.list70[j] == null: swap-remove
```

---

## 4. Surviving contract for AutoCore

```
PhysSim_PostActivateNotify(world, host):
  // NOT the ready write — parent does host+0x29=1 first
  reverse_foreach p in world.listeners(+0x78):
    if p: p.OnHostActivated(host)        // vtbl+4
  World_PostActivateFlush(world)         // FUN_005fff20
  foreach entry in host.attachments(+0x3c):
    reverse_foreach child in entry.list(+0x70):
      if child: child.OnParentActivated(entry)  // vtbl+8
    compact_nulls(entry.list)
```

**Port tests:**

* Must not set ready / free-list (parent).
* Must reverse-notify before compact.
* Must use `+0x78` list, not active-host `+8`.

---

## 5. Open questions

1. Dual `FUN_005fff20`.
2. Listener RTTI / method names.
3. Whether any other CALL sites exist beyond ActivateHost (Ghidra list showed one).

**Verdict:** **accept-with-gaps**
