# Review B (skeptical / adversarial): `aa_005078f0` CVOGHBList_Enqueue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005078f0` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005078f0_CVOGHBList_Enqueue.md` |
| **Verdict** | **accept** on CF; reject overclaims about active insert / void return / unbounded grow |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Enqueue inserts into **active** and starts TryFire | **Falsified** — writes only `+0x28/+0x2c`; Tick promotes |
| 2 | Null is success / returns void | **Falsified** — `return 0x80070057`; success `0` |
| 3 | Unlocked push | **Falsified** — CS at `+0x04` wraps grow+store+count++ |
| 4 | Grow policy unknown / unfinished | **Falsified as gap** — `FUN_005b3370` doubles `param_1[1]` (count when full), floor 1; elem size 4 |
| 5 | Cap high bit is a separate “flag enum” for list state | **Overstated** — ctor seeds `0x80000000`; grow free path tests `(int)cap >= 0` (owned heap). Capacity usable bits = `& 0x7fffffff` |
| 6 | Clean “re-read count after grow” changes semantics | **Falsified as risk** — grow does **not** mutate count; re-read ≡ pre-grow count |
| 7 | `Returns: void` plate on raw comment is authoritative | **Falsified** — signature/`ret` is `uint` HRESULT-style |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pending-only append | **High** | Server/client HB never TryFires if implementer only Enqueues without Tick promote |
| CS correctness | **High** | Races with Tick promote/remove |
| Null HRESULT | **High** | Callers that ignore return still safe on null skip |
| Grow double | **High** | Wrong capacity → OOB write |
| Map slot `+0xe4ec` is *the* list | **Medium** | Many callers use it; not exclusive to all domains |

---

## 3. Cross-check against raw + grow

```
if !pAction: return E_INVALIDARG (0x80070057)
EnterCS(this+4)
if pendingCount == (pendingCapRaw & 0x7fffffff):
    grow(this+0x28 as {buf,count,cap}, elemSize=4)
      // newCap = count==0 ? 1 : count*2
      // alloc, memcpy(count*4), free old if (int)oldCap>=0
      // buf=new; cap=newCap  (count unchanged)
pending[buf][count] = pAction
pendingCount++
LeaveCS
return 0
```

Clean ≡ raw CF. Raw header “Returns: void” is **documentation error** (body returns HRESULT).

---

## 4. Surviving contract for AutoCore

```
Enqueue(list, hb):
  if hb is null: E_INVALIDARG; else append to pending under CS
  does NOT arm TryFire by itself
  CVOGHBList_Tick promotes pending → active, then TryFire
  Start + Enqueue is the usual arming pair (cast-again, regen, patrol, status FX)
  pending capacity grows by doubling (min 1); element size 4 (pointer)
  do not implement as lock-free vector without matching CS
```

---

## 5. Open questions (narrow)

1. Product name for `FUN_005b3370` / heap tag `0x12`.
2. Full audit: Start-without-Enqueue and Enqueue-without-Start sites.
3. Live confirmation of first-grow (empty → 1 slot) path.

**Verdict:** **accept** on CF + grow; residual naming only.
