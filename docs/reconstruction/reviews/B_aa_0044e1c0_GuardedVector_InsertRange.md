# Review B (skeptical / adversarial): `aa_0044e1c0` GuardedVector_InsertRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044e1c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-G) |
| **Counterpart** | `reviews/A_aa_0044e1c0_GuardedVector_InsertRange.md` |
| **Scratch** | `tmp/a_0044e1c0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as `GuardedVector_InsertN` (`0043cb00`) | **Falsified** — InsertN is N×fill via EAX push family; this is range via thiscall push |
| 2 | Flat `vector::insert` | **Falsified** — page-map ring + push_front/back polarity |
| 3 | Decompiler 5-arg complete ABI | **Falsified** — **RET 0x18** + sole caller **6** pushes |
| 4 | Entry thiscall ECX=container | **Falsified** — container is stack/`ESI`; ECX only for nested push |
| 5 | Nested helpers fully sealed | **Confirmed gap** — `0044e4f0`/`0043ec50`/`0043ebb0` unowned |
| 6 | Product name retail | **Overstated** — inferred `GuardedVector_InsertRange` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 0x18 / 6-arg ABI | **High** | Stack tear at sole caller |
| Shorter-side 4-arm CF | **High** | Wrong insert polarity |
| PushFront/PushBack thiscall | **High** | Wrong nest ABI |
| Page map math | **High** | Corrupt slots |
| Nested move/assign | **Open** | Bit-exact gap |
| 6th formal | **Tentative** | Caller residual only |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Complex SEH paths |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  prefix = insert_at - begin; suffix = size - prefix; N = (last-first)>>2
  front arms → FUN_0043e3d0; back arms → FUN_0043d670
  move → FUN_0043ec50 / FUN_0043ebb0; assign → FUN_0044e4f0

bytes:
  all epilogues C2 18 00
  call displ → 0043e3d0 / 0043d670 confirmed
  sole caller 0097176b: 6 pushes then call
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 success CF. Nested free remains deliberate gap (same pattern as W29-A InsertN).

---

## 4. Surviving contract for AutoCore

```
// GuardedVector range insert:
//   stdcall 6 args; RET 0x18
//   container, seed/out, insert_at, first*, last*, sixth?
//   N = (last-first)>>2 dwords
//   shorter-side: prefix<suffix → PushFront_Thiscall; else PushBack_Thiscall
//   then nested ring-move + assign helpers (unowned)
// Do NOT reuse InsertN (N×fill / EAX push) ABI or contract.
// Do not invent flat vector insert.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/push polarity; nested free + 6th formal + product residual → **accept-with-gaps**.
