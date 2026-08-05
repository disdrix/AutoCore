# Review B (skeptical / adversarial): `aa_00497920` ListTrackedCtx_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497920` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-P) |
| **Counterpart** | `reviews/A_aa_00497920_ListTrackedCtx_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra signature `undefined FUN_00497920(void)` means no args / void | **Falsified** — decompile + locals show thiscall + stack parent; epilogue `C2 04 00`; returns this |
| 2 | This is an in-place init of PalantirEnv itself | **Falsified** — factory allocates separate 0xC8; stores at env`+0x100`; env is 0x198 |
| 3 | `FUN_00788db0` is memcpy or ctor | **Falsified** — decompile is pure zero-fill loops; returns 1 |
| 4 | `FUN_00787520` is a heavy base ctor | **Falsified** — three dword stores of 0 only |
| 5 | Capacity 5 is a magic unrelated to bank | **Weak attack** — bank is 0xA0 bytes (larger than 5 pointers); 5 may be max active slots while bank holds richer records — **keep as capacity constant, not full bank math** |
| 6 | Multiple independent callers create many ctxs | **Falsified** — sole static caller PalantirEnv_Ctor; global `DAT_00b035cc` overwritten each construct |
| 7 | Parent at +0xC4 is unused after ctor | **Falsified** — W31-D `0x00497a30` uses `*(ctx+0xC4)` to reach host `+0xE898` |
| 8 | Flag@+0=1 means "enabled" | **Unresolved** — `FUN_004be7d0` early-outs when `*DAT_00b035cc != 0`; flag semantics open (gate/skip) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete ctor of 0xC8 | **High** | Wrong object lifecycle |
| ABI ret 4 / parent formal | **High** | Stack imbalance |
| Sole PalantirEnv install | **High** | Orphan instances |
| Global publish | **High** | Missed singleton wiring |
| Capacity=5 product meaning | **Med** | Wrong bank model |
| Flag@+0 English | **Low** | Wrong enable policy |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
// Epilogue hex: ... 8B C6 5E 64 89 0D 00 00 00 00 83 C4 10 C2 04 00
// Sole call site PalantirEnv_Ctor:
//   pv = operator_new(200);
//   if (pv) u = FUN_00497920(parent); else u = 0;  // thiscall ECX=pv
//   env[+0x100] = u;
// Global WRITE @ 0x00497988 → DAT_00b035cc
// Global READ  @ 0x004be7d4 in FUN_004be7d0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals ret 4 and field constants.

---

## 4. Surviving contract for AutoCore

```
// Port as complete ctor of owned 0xC8 child:
ctx = ListTrackedCtx_Ctor(raw_0xC8, parent);
// Must: flag=1, cap=5, count=0, zero +0x14..+0xB3, zero +0xB8 triple,
//       parent@+0xC4, DAT_00b035cc=ctx, return ctx / ret 4.
// Do not fold into PalantirEnv_Ctor body.
// Do not assume flag=1 means feature-enabled (readers early-out on non-zero).
// Keep FUN_00787520 / FUN_00788db0 as zero helpers or inline equivalent.
```

---

## 5. Verdict

Adversarial pass confirms A on ctor role/ABI/layout/sole factory/global. Residual product English + flag polarity + bank element type → **accept-with-gaps**.
