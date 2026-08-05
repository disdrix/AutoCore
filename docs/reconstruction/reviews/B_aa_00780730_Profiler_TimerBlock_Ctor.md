# Review B (skeptical / adversarial): `aa_00780730` Profiler_TimerBlock_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00780730` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00780730_Profiler_TimerBlock_Ctor.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Truly `void` no inputs | Decompiler `unaff_ESI`; caller sets ESI; body `mov eax,esi` | **Falsified** “no object” |
| 2 | ECX/thiscall timer | No ECX use; ESI convention | **Falsified** |
| 3 | Divisor is raw QPF (seconds scale) | `__alldiv` by **1e6** → ticks/µs | **Falsified** |
| 4 | Divides by 1000 (ms) | Imm is `0xF4240` = 1_000_000 not 1000 | **Falsified** |
| 5 | Zeros divisor then leaves it 0 | QPF then divide overwrite `+0x10` | **Falsified** |
| 6 | Mission/gameplay clock helper | Only profiler timer block under zone | **Falsified** |
| 7 | Multiple independent ctors | Single xref from zone ctor | **Overstated** if claimed multi-entry |
| 8 | Stack formal self | `ret` not `ret 4` | **Falsified** |
| 9 | Scaffold “void” clean is safe to call from C without ESI | Wrong object | **Overstated** risk |
| 10 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI/EAX ABI | **High** | Ctor writes random memory |
| µs divisor | **High** | 1000× or 1e6× profiler numbers |
| Field offsets | **High** | Start/accumulate corruption |
| Single caller | **High** | Miss alternate init path |
| Product typename | **Low–Med** | Naming only |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Imm 1000000 in body | `68 40 42 0f 00` via `read_memory` |
| Caller ESI setup | `8b f0 e8 …` @ zone ctor after `new(0x30)` |
| Start path preserves divisor | StartZoneTimer dual zeroes sample fields only |
| Accumulate uses `+0x10` denom | QpcAccumulate dual |

**Attack on “avg is zeroed at +0x10”:** **Falsified** — `+0x10` is divisor; avg is `+0x18`.

---

## 4. Surviving contract for AutoCore

```
// ESI = allocated 0x30 timer
// divisor_us = QPF / 1e6
// No stack args; return pointer in EAX
```

**Falsified port mistakes:**

- Calling as cdecl with pointer on stack only (ESI unset).
- Treating divisor as raw Hz without /1e6 when converting deltas.
- Clearing `+0x10` on start (would destroy scale).
- Assuming ms (`/1000`) or seconds (`/QPF` only).

---

## 5. Open questions

1. Pad at `+0x2c` unused forever?
2. QPF failure path (API returns 0) — body does not check; divide by zero risk is in consumers if div=0.
3. Original source symbol / namespace.

**Verdict:** **accept** — no residual that blocks sealing ABI + µs divisor contract.
