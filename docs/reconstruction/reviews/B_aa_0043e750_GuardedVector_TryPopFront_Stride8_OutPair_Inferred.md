# Review B (skeptical / adversarial): `aa_0043e750` GuardedVector_TryPopFront_Stride8_OutPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-A) |
| **Counterpart** | `reviews/A_aa_0043e750_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as header-only `GuardedVector_PopFront` (`0040d980`) | **Falsified** — this unit copies out pair, optional CS, returns AL; peer is void header-only |
| 2 | Dword stride / wrap cap×4 | **Falsified** — `LEA […+ECX*8]` stride **8**; wrap uses **cap×2** (`ADD EDX,EDX`) |
| 3 | ECX/EAX thiscall container | **Falsified** — all header loads via **ESI**; out via **EDI** |
| 4 | Always copies both dwords unconditionally | **Falsified** — first dword gated on `EDI != slotp`; second always |
| 5 | Stack formals / `RET 4` | **Falsified** — plain `C3`; no stack args |
| 6 | Unlocked-only / no CS | **Falsified** — `+0x2c` gate + Enter/Leave IAT both success and empty paths |
| 7 | Pop-back or erase-range | **Falsified** — advances **begin** (front), not end |
| 8 | Scaffold assPreloader product method name | **Rejected** — structural GuardedVector name; path is caller only |
| 9 | Multiple independent callers | **Falsified** — sole function caller `00971480` (two call sites in drain loop) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI container + EDI out + AL + RET | **High** | Caller ABI crash |
| Stride 8 / page = begin>>1 / wrap cap×2 | **High** | Corrupt ring |
| CS +0x2c / +0x14 | **High** | Race / deadlock |
| Odd first-dword alias skip | **High** | Must preserve |
| Product pair English | **Inferred/Open** | Naming only |
| Runtime | **Open** | Drain races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  optional Enter; if size==0 Leave+return 0;
  compute slot; copy pair; begin++/wrap/size--; Leave; return 1

bytes:
  CMP [ESI+0x2c]; LEA EBP,[ESI+0x14]; Enter IAT
  CMP [ESI+0x10],0 → empty path XOR AL,AL
  SHR begin; *8 addressing; conditional first dword
  ADD begin,1; cap*2 wrap; size--; B0 01 / C3
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF; **bytes win** on ESI/EDI ABI. W37-B drain consumer documents ESI=`host+0x4c`, EDI=out pair — matches.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector try pop_front stride-8:
//   ESI = container (pages+4, cap+8, begin+0xC, size+0x10, CS+0x14, lock+0x2c)
//   EDI = uint32_t out[2]
//   AL  = 1 popped / 0 empty
//   plain RET — do NOT invent RET 4 or thiscall ECX
// Do NOT use cap×4 dword addressing (that is PopFront 0040d980).
// Do NOT drop the EDI==slot first-dword skip (odd preserved).
// Do NOT free/dtor elements here — header advance only.
// Do NOT use scaffold assPreloader product name on this leaf.
```

---

## 5. Residual gaps (accepted)

- Product meaning of out-pair fields (object* + tag residual at drain site).
- Why first dword skips on alias (MSVC artifact vs intentional).
- Runtime / differential.

---

## 6. Verdict

Adversarial pass **confirms** A on ABI/CF/stride/CS and rejects peer-PopFront conflation / wrong wrap / wrong RET / scaffold-name claims → **accept-with-gaps**.
