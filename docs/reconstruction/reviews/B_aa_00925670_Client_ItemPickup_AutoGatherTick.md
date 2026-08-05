# Review B (skeptical / adversarial): `aa_00925670` Client_ItemPickup_AutoGatherTick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-T) |
| **Counterpart** | `reviews/A_aa_00925670_Client_ItemPickup_AutoGatherTick.md` |
| **Scratch** | `tmp/a_00925670.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is Activate-edge pickup | **Falsified** — PollBound calls it at `LAB_0092788e` **before** Activate edge tests; always runs |
| 2 | Decompiler `void(void)` is full ABI | **Overstated** — bytes seal `RET 4`; call site pushes `param_1`; client is **EAX** not stack |
| 3 | Stack formal is the client | **Falsified** — body `mov esi, eax`; call site loads `DAT_00d1b6d8` into EAX; stack arg unread |
| 4 | Throttle is 99 ms | **Partial** — compare is `> 99` (unsigned/signed as coded) → effective **>=100 ms** |
| 5 | Multiple callers | **Falsified** — single xref `0x00927894` |
| 6 | Gathers without ItemPickup | **Falsified** — hit path calls `FUN_00925580` (sealed 0x2055 parent dual) |
| 7 | Product name is retail | **Overstated** — inferred from role + parents; Ghidra still `FUN_00925670` |
| 8 | Decompiler shows complete gather argc | **Open residual** — shortened arg list vs `add esp,0x2c` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-on auto gather CF | **High** | Missed auto-loot path |
| 100 ms throttle + globals | **High** | Spam / starved pickups |
| 20.0f + mode-6 gather family | **High** | Wrong interact radius |
| Hit → 0x2055 ItemPickup | **High** | Wrong C2S opcode |
| EAX client ABI | **High** | Wrong this / crash |
| Gate +0xcd0 product English | **Medium** | Naming only |
| Full gather argc | **Medium** | Port formal mismatch |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
client = EAX
if *(client+0xcd0) != 0: return
now = GetTickCount(); DAT_00d218d4 = now
if now - DAT_00d1f0d4 <= 99: return
DAT_00d1f0d4 = now
pair = (-1,-1)
helper = vtbl+0x1a0(20.0f,1,6,0,0,1)
FUN_0058cd60(&pair, ...)
if (pair.d0 & pair.d1) != -1: FUN_00925580()  // ESI=pair
RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Clean plate names auto-tick role without changing CF.

---

## 4. Surviving contract for AutoCore

```
// Client auto loot tick (poll loop, not Activate edge)
// throttle: min 100 ms between attempts (DAT_00d1f0d4)
// gather radius 20.0f mode family 6 — same as Activate special gather
// on TFID hit: send ItemPickup 0x2055 size 0x30 (Client_SendItemPickup)
// gate: client+0xcd0 must be 0
// do not require Activate key edge for this path
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/throttle/pickup path; residual is gate English + full gather argc → **accept-with-gaps**.
