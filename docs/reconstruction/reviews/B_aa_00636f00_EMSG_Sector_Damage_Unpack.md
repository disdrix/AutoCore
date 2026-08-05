# Review B (skeptical / adversarial): `EMSG_Sector_Damage_Unpack` @ `0x00636f00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636f00` |
| **Review type** | Skeptical / adversarial dual |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00636f00_EMSG_Sector_Damage_Unpack.md` |
| **System tag** | `client-net` / `combat-floaters` |
| **Scope** | Dual A/B only — own VA; no WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---:|---|---|---|
| 1 | This **applies** HP / combat damage | Body only BitStream reads + malloc/copy + refcount wrap; no entity lookups, no pool writes | **Falsified** |
| 2 | This **queues combat floaters** itself | No call into floater / `CWndDamageText` / game+0xAA8 paths; sole output is `*param_1` buffer object | **Falsified** |
| 3 | Multi-opcode generic unpack | Header hardcodes `0x2023`; sole xref is `Client_UnpackSpecialMessage` after `param_2 == 0x2023` | **Falsified as multi-opcode** |
| 4 | Entry amount is unsigned 16 | Decompile forces `(int)(short)…` sign-extend after 16-bit read | **Falsified as unsigned** |
| 5 | Entry size is 16 or 24 bytes | `count * 0x20`; cursor `piVar8 += 8` dwords | **Falsified** |
| 6 | Packed size is only `count*0x20` | After scale, `puVar5 += 7` (dwords) before `malloc` → **+0x1C** header | **Falsified** |
| 7 | Crit/Resist/Deflect share one packed bitfield dword | Each flag is a separate `bool` store at distinct entry offsets; 11 flags total per entry | **Falsified as bitfield dword** |
| 8 | Residual flags after Deflect are unused so order does not matter | Wire order stores `+0x1D` **before** `+0x15…1A`; packers that write sequential bools in memory order desync the stream | **Conceded risk** — wire order is mandatory; AutoCore `DamagePacket` matches wire |
| 9 | Source TFID is 32-bit | Explicit `readBits(0x40)` into `local_178`/`local_174` pair | **Falsified** |
| 10 | Count is 8- or 32-bit | `readBits(0x10)` only | **Falsified** |
| 11 | `BitStream_readFlag` callees list means loop uses the named helper | Loop body is **inlined** flag extract on stream locals; only header uses named `BitStream_readFlag` in this decompile | **Conceded nuance** — behavior ≡ `readFlag`, call shape differs |
| 12 | Two-arg signature is wrong because caller shows one arg | Function stack uses `param_1` and `param_2` throughout; Ghidra caller display often drops the msg arg | **Conceded decompiler display issue** — body proves 2-arg use |
| 13 | Opcode stamp is decompiler fiction | `read_memory`: `C7 44 24 30 23 20 00 00` | **Falsified** |
| 14 | Product `DamagePacket` invents Crit-before-amount order | Matches this unit: flag @+0x14, then amount @+0x10, then target TFID | **Falsified as invention** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = unpack only for 0x2023 | **High** | Server couples apply/floater into pack path |
| Header: i64 source + global + u16 count | **High** | Desync entire packet |
| Entry: Crit, i16 amount, i64 target, global, Resist, Deflect, 7 flags | **High** | Floater flags / multi-hit corrupt |
| Entry stride 0x20; pack header 0x1C | **High** | Heap layout / consumer OOB |
| Amount signed int16 | **High** | Heal-style negative amounts break |
| Residual flag **wire** order (1D then 15–1A) | **High** | Any non-zero residual flags misaligned |
| Residual flag **semantics** | **Open** | Wrong combat-text variants if filled |
| Header +0x04 | **Open** | Consumer may read garbage if it cares |
| Wrapper class / vtbl name | **Open** | Lifetime bugs only if reimplemented wrong |
| Apply/floater mapping (0x812A60 etc.) | **Out of scope** | Not this VA |

---

## 3. Surviving contract (AutoCore)

```
// S2C special msg opcode 0x2023 (RPC type carries opcode; payload is pure BitStream)
// skipOpcode: true on send

Write:
  bits64 Source.Coid
  flag   Source.Global
  bits16 Count
  for each entry:
    flag   IsCrit
    bits16 Amount           // signed; store/consume as int16
    bits64 Target.Coid
    flag   Target.Global
    flag   IsResist
    flag   IsDeflect
    flag×7 residual (retail often 0; order fixed)

// Client unpack (this VA): materialize owned buffer
//   header 0x1C + entries Count×0x20
//   then later apply/floater paths consume buffer — not here
```

Cross-check: `DamagePacket.Write` order **agrees** with decompile store/wire order for Crit, amount, target, Resist, Deflect, and seven trailing false flags.

---

## 4. Cross-check against raw + memory + xrefs

| Check | Result |
|---|---|
| Live decompile 2026-07-29 vs raw 2026-07-23 | **Match** (same CF / stores / sizes) |
| `read_memory` opcode immediate | `23 20 00 00` @ first header store |
| `push 0x40` before first `readBits` | Present in prologue bytes |
| Xrefs | Single: `Client_UnpackSpecialMessage+…` `00637c87` |
| Callees | `BitStream_readBits`, `BitStream_readFlag`, `FUN_0042b3a0`, `FUN_0042b250`, `FUN_0042b270`, `malloc`/`free`, `operator_new`/`new[]`/`delete[]` |
| Clean scaffold CF | **Yes** (expanded whitespace; no modernization rewrite of algorithm) |

---

## 5. Open (do not invent)

1. Names of residual flags `entry+0x15…1A`, `+0x1D`.
2. Consumer field map for header `+0x04` / `+0x14`.
3. C++ type behind `PTR_LAB_009d7b00`.
4. Full apply path (`~0x812A60` / combat-event queue) — **other VAs**.
5. Runtime multi-hit capture with non-zero residual flags.
6. Bit-exact image / differential tests.

**Verdict:** adversarial “this is apply/floater/multi-opcode/unsigned amount” attacks **defeated**. Wire + pack layout sealed. **accept-with-gaps.**
