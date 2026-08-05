# Review B (skeptical / adversarial): `aa_0055efd0` PhysSim_PushBodyPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055efd0` |
| **Canonical name** | `PhysSim_PushBodyPair_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0055efd0_PhysSim_PushBodyPair_Inferred.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX is first body; pair array lives on body | Decompile 2-arg thiscall noise | **Falsified** — call sites `MOV ECX, world (EBP/EDI)`; array offsets match world glue vector |
| 2 | Element size 4 (pointer vector) | Confuse with `006292a0` / `005b3370` | **Falsified** — push `8`; stride `*8` stores |
| 3 | Always doubles capacity only | Ignore clamp | **Falsified** — `newCap = max(cap*2, need)` via `FUN_005b3300` |
| 4 | Uses `FUN_005b3370` double-grow | Sibling mix-up | **Falsified** — sole callee **`FUN_005b3300`** (explicit capacity) |
| 5 | Free-standing stdcall 3 stack args | | **Falsified** — thiscall + **ret 8** (2 stack dwords) |
| 6 | Same as action-list push `006292a0` | | **Falsified** — different header (`+0x20` vs `+0x4c`), stride 8 vs 4, no backlink store |
| 7 | Writes only one pointer | | **Falsified** — two dwords per element |
| 8 | Product name recovered | | **Holds open** — `_Inferred` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall world + ret 8 | **Confirmed** | Wrong object / stack smash |
| Header `+0x20/+0x24/+0x28` | **Confirmed** | Corrupt sim state |
| Stride 8 + ordered (a,b) | **Confirmed** | Swapped bodies / wrong layout |
| Grow `max(2*cap, need)` via `005b3300` | **Confirmed** | OOM or truncated queue |
| Role = pending cross-host pair | **High** | Mis-port island merge |
| Product symbol | **Low** | Doc only |

---

## 3. Cross-check against raw / live

```text
raw:  thiscall; hdr=this+0x20; need=count+1; if need>cap: 005b3300(hdr, max(2*cap,need), 8);
      count=need; store a,b at last 8-byte slot
live: ≡ raw; C2 08 00
sites: ECX=world; push bodyA/bodyB (RegisterAction: EBX=first, EAX=next)
```

### Sentinel / sibling traps

| Trap | B position |
|---|---|
| Merge with `Phys_HostActionList_Push` (`006292a0`) | **Reject** — different container + stride |
| Merge with `GrowableArray_DoubleGrow` alone | **Reject** — this is push wrapper; grow is `005b3300` not `005b3370` |
| Assume free of old buffer here | **Reject** — free policy is inside grow helper |
| Assume inlined `00560f70` is a different algorithm | **Reject** — same need/grow/store math; just open-coded |

---

## 4. Surviving contract for AutoCore

```
PhysSim_PushBodyPair(world, bodyA, bodyB):
  hdr = world.pairVec @ +0x20   // {data, count, capRaw}
  need = count + 1
  cap  = capRaw & 0x7fffffff
  if need > cap:
      GrowTo(hdr, max(cap*2, need), elemSize=8)   // FUN_005b3300
  count = need
  data[need-1] = { bodyA, bodyB }
```

**Port tests:**

* First push from seed `capRaw` with high bit set must not free static empty (grow helper rule).
* Pair order matches call-site first/next bodies.
* Must not touch host action list `+0x4c`.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| World owns pair vector | **Agree** (asm ECX) |
| Cross-island / cross-host role | **Agree High** — not Confirmed product English |
| `body+0x44` is island id | **Probable only** — sealed as equality key, not English |
| Name `_Inferred` | **Agree** leave open |

---

## 6. Open questions

1. PDB/product symbol.
2. Full pair-list drain / island-merge consumer dual.
3. Whether any caller swaps (a,b) order deliberately.

**Verdict:** **accept-with-gaps** — leaf CF sealed; parent residual for this VA closed.
