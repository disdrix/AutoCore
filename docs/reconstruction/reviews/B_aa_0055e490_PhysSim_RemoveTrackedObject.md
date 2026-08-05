# Review B (skeptical / adversarial): `aa_0055e490` PhysSim_RemoveTrackedObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055e490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0055e490_PhysSim_RemoveTrackedObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **activates** host / sets `+0x29=1` | Confuse with `0x55eb80` | **Falsified** — no write to `+0x29`; only list remove + optional dtor |
| 2 | Ghidra one-arg form `FUN_0055e490(phys)` is ABI truth | PrepareReady decomp under-arity | **Falsified** — asm `ECX=world`, stack=`phys` |
| 3 | Always destroys arg | Skip refcount | **Falsified** — dtor only when `*(i16*)(arg+6)` hits 0 after dec |
| 4 | Ordered erase / memmove | STL vector mental model | **Falsified** — **swap-remove** last into hole |
| 5 | Null arg is safe | Defensive port | **Not sealed** — no null test; null may just fail scan or fault on refcount |
| 6 | Sole purpose is vehicle tick hot path | Domain overfit | **Falsified as exclusive** — only PrepareReady caller, but prepare is shared write-enable |
| 7 | Name is string-proven | Symbol inflation | **Not sealed** — **Probable** role; Ghidra `FUN_0055e490` |
| 8 | Array is at host `+0x108` (small object) | Wrong `this` | **Falsified** — `this` is world (`phys+8`); offsets 0x108/0x10c are large world layout |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| world+0x108 / +0x10c list | **High** | Wrong storage / leak |
| Swap-remove + refcount | **High** | Double-free / leak |
| PrepareReady ABI (world, phys) | **High** | Corrupt ECX / stack |
| Not the activate path | **High** | Miss ready flag |
| English list role | **Probable** | Doc only |
| Insert producers complete | **Low** | Incomplete lifecycle |

---

## 3. Cross-check against raw

```text
// raw aa_0055e490 ≡ live decompile 2026-07-29
arr = *(this+0x108); n = *(this+0x10c);
for i in 0..n:
  if arr[i] == arg:
    j = re-find index (or -1)
    n--; arr[j] = arr[n]; *(this+0x10c)=n
    if --*(i16*)(arg+6) == 0: (*arg->vtbl)(1)
```

Contrast `aa_0055eb80`: push onto active list, set `host+0x29=1`.

---

## 4. Surviving contract for AutoCore

```
PhysSim_RemoveTrackedObject(world, obj):
  scan world.tracked[+0x108], count[+0x10c]
  if found: swap-remove; refcount at obj+6; destroy if 0
  // often no-op if obj not tracked

// PrepareReady:
//   if phys.world(+8)==null: return
//   RemoveTrackedObject(world, phys)
//   if host(+0x44).ready(+0x29)==0 && host.index(+0x24)!=-1:
//       ActivateHost(world, host)  // 0x55eb80
```

**Port tests:**

* Must not set ready flag here.
* Must use world as `this`, not phys.
* Must swap-remove (not shift) to match retail iteration side-effects.
* Must only destroy on refcount→0.

---

## 5. Open questions

1. Insert site(s) into `world+0x108`.
2. Whether tracked type is always `CVOGPhysics*` or polymorphic.
3. Iteration hazard after swap-remove (does retail ever multi-hit same scan?).
4. Runtime frequency of non-no-op path.

**Verdict:** **accept-with-gaps** — attacks that merge this with activate or flip ABI **fail**; residual naming/lifecycle open.
