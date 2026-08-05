# Review B (skeptical / adversarial): `aa_00512090` CVOGHBPlayerTargetingLink_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A narrative polish) |
| **Counterpart** | `reviews/A_aa_00512090_CVOGHBPlayerTargetingLink_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | “Ctor does all HB setup itself” | Body is only base call + one DWORD vtbl store | **Falsified if over-read** — setup lives in `FUN_00604d40` |
| 2 | Self and target HB share this ctor | Parent calls **this** for self and **`0x00604d40`** for target | **Falsified same-class claim** — different entry points |
| 3 | `__cdecl` / no stack cleanup | Bytes end `C2 04 00` | **Falsified** — `__thiscall` + `ret 4` |
| 4 | Decompiler `undefined` / void signature | Analyze warns return type unresolved; body clearly returns `this` in EAX | **Trust decomp body, not Ghidra sig stub** |
| 5 | Vtbl write is “init first field of a POD” only | Base already wrote `*this = 0x009cdfb0`; this **overrides** | **Subclass promote**, not first-touch |
| 6 | Name is product-confirmed on this VA | No RTTI / string in leaf; class name from purge RTTI | **Class High; ctor symbol Inferred** |
| 7 | Allocates its own object | No `operator_new` in leaf; caller `push 0x28` | **Ctor only** — size is caller contract |
| 8 | Multiple construction sites | `xref_count: 1` → only `Object_SetSelectedTarget` | **Single factory path** in this image |
| 9 | `param_2` is the *selected target* | Call site passes **selector entity** (self), target gets separate base ctor | **attachOwner = self entity** |
| 10 | Derived vtbl is wholly unique | Slots 1–6 match base `009cdfb0` | **Partial override** (slots 0 and 7 differ in first 8) |
| 11 | Scaffold clean is complete | Prior clean had auto “unknown” plate and no ABI/bytes | **Prior incomplete** — refined dual required |
| 12 | Base call loses `this` | ECX not clobbered before `call`; only stack arg pushed | **thiscall chain intact** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + one owner arg + ret 4 | **High** | Wrong stack / wrong attach |
| Base then vtbl `009cdfd4` order | **High** | Miss subclass identity → purge fails |
| Sole caller SetSelectedTarget | **High** | Invent multi-site construction |
| Object size 0x28 | **High (caller)** | Buffer under/overflow if reimplemented |
| Class family PlayerTargetingLink | **High** | Wrong RTTI / purge coupling |
| Product ctor spelling | **Tentative** | Naming only |
| Virtual slot meaning (0 / 7) | **Open** | Tick/destroy wrong if assumed without those VAs |
| Base field layout / period constants | **Out of scope** | Must dual `0x00604d40` separately |

---

## 3. Cross-check against raw / decompile / memory

```
raw scaffold (2026-07-23) and live decompile (2026-07-29):
  FUN_00604d40(param_2);
  *param_1 = &PTR_FUN_009cdfd4;
  return param_1;

read_memory body:
  8B 44 24 04  56  50  8B F1  E8 A3 2C 0F 00
  C7 06 D4 DF 9C 00  8B C6  5E  C2 04 00

call target: 0051209d + 000F2CA3 = 00604D40
vtbl dword: little-endian D4 DF 9C 00 → 0x009CDFD4

base vtbl @ 009cdfb0 slot0=00512070 slot7=0056f570
der  vtbl @ 009cdfd4 slot0=0051b870 slot7=0051b850
shared slots 1..6 identical in first 32 bytes sampled
```

Clean **must not**:
- invent null-`this` / null-owner guards (retail has none),
- allocate,
- write partner `+0x24` (that is `FUN_00604db0` at parent),
- enqueue on HB list (parent),
- claim target-side objects use this entry.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_00512090 — CVOGHBPlayerTargetingLink_ctor (inferred)
// thiscall: this in ECX, attachOwner on stack.
// Size: 0x28 (caller new). Returns this.
unsafe CVOGHBPlayerTargetingLink* Ctor(CVOGHBPlayerTargetingLink* self, ClonedObject* attachOwner)
{
    // Base targeting HB ctor (same as target-side entry 0x00604d40).
    CVOGHBBase_Targeting_ctor((CVOGHBBase*)self, attachOwner); // FUN_00604d40
    // Promote to PlayerTargetingLink so RTTI purge (0x005121d0) matches.
    *(void**)self = (void*)0x009CDFD4;
    return self;
}
```

Parent pairing (context only, not this body):

```
selfLink  = Ctor(new(0x28), entity);          // THIS VA
targetHb  = BaseCtor(new(0x28), newTarget);   // 0x00604d40 only
LinkPartner both ways; Enqueue both.
```

---

## 5. Residual gaps (do not over-seal)

1. English/product ctor identifier beyond RTTI class stem.
2. Bodies of overridden vtbl entries at `0x0051b870` / `0x0051b850`.
3. Full base ctor field layout (`FUN_00604d40` OWN-ONLY elsewhere).
4. Runtime proof that purge RTTI fails if vtbl write is skipped (logical High; not golden-tested here).

---

## 6. Verdict vs Review A

| Topic | A | B | Resolve |
|---|---|---|---|
| Body shape base+vtbl+return | Sealed | Confirmed | **Agree** |
| ABI thiscall ret 4 | Sealed | Confirmed | **Agree** |
| Subclass vs base entry split | Sealed | Attacked same-class myth | **Agree** |
| Class name confidence | High class / inferred ctor | Same | **Agree** |
| Virtual slot semantics | Open | Open | **Agree — leave open** |

**accept-with-gaps** — adversarial pass finds no control-flow or ABI contradiction; residual risk is out-of-VA base/virtual behavior and product spelling only.
