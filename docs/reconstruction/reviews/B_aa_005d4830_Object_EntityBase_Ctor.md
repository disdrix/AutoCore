# Review B (skeptical / adversarial): `aa_005d4830` Object_EntityBase_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-E) |
| **Counterpart** | `reviews/A_aa_005d4830_Object_EntityBase_Ctor.md` |
| **Scratch** | `tmp/a_005d4830.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a thin flag-setter, not a ctor | **Falsified** — SEH frame, mostDerived path, two sub-ctors, returns this |
| 2 | SharedBase is at this+0 (same as mid-base +0x110) | **Falsified** — bytes `lea ecx,[esi+0xe0]`; mid-base uses +0x110 for its own embed |
| 3 | Both sub-ctors run on `this` (decomp surface) | **Partially false** — `00581330` is `lea ecx,[esi+0x40]`; only `0053cdc0` is on `this` |
| 4 | Flags 0x40/0x20 are unrelated | **Falsified** — same bits set inside `00581330` (0x40) and `0053cdc0` (0x20); parent re-applies after sub-ctors |
| 5 | Product name is retail PDB | **Overstated** — Inferred from hierarchy under `Object_EntityMidBase_Ctor` |
| 6 | Only one caller | **Falsified** — two xrefs: mid-base + `FUN_005dbfa0` |
| 7 | Nested sub-ctors fully typed here | **Open by design** — residual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor CF + RET 4 + EAX=this | **High** | Wrong object lifetime |
| SharedBase +0xe0 / 00581330 +0x40 | **High** | Corrupt subobjects |
| Dual vb cookies imm32 | **High** | Bad MI layout |
| Flag ORs at vb+0x180 | **High** | Feature bits missing |
| Product English name | **Medium** | Naming only |
| Nested 0053cdc0 / 00581330 duals | **Open** | Port of subobjects |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
mostDerived? cookies + SharedBase(+0xe0)
0053cdc0(this,0)
00581330(this+0x40,0)
zero +0xbc/+0xc0
OR 0x40; OR 0x20 @ vb+0x180
RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 body. Clean plate restores this-adjusts decomp dropped.

---

## 4. Surviving contract for AutoCore

```
// Entity base under MidBase — construct order matters
Object_EntityBase_Ctor(self, mostDerivedFlag)
// mostDerived=0 when chained from MidBase/children
// mostDerived!=0 installs dual vb + SharedBase at +0xe0
// always: base@+0 (0053cdc0), base@+0x40 (00581330), flags 0x40|0x20
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/subobject offsets/flags; residuals are product English + nested duals + runtime → **accept-with-gaps**.
