# Review B (skeptical / adversarial): `aa_0044a0d0` NestedHashBag_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a0d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-D) |
| **Counterpart** | `reviews/A_aa_0044a0d0_NestedHashBag_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` stack formal |
| 2 | Decompiler `undefined FUN_0044a0d0(void)` is full ABI | **Falsified** — body takes stack this*, returns this |
| 3 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 4 | Writes all 0x28 bytes of member | **Partial** — `+0x00/+0x04` never written; sealed as gap |
| 5 | Multiple unrelated roles | **Falsified** — sole xref from `FUN_0074d750` nested `+0x0c` |
| 6 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB English “Hash” / Ass* | **Careful** — structural from sentinel+bucket-table shape + twin CF; `_Inferred` only; parent not sealed Ass* |
| 8 | FUN_004646e0 is 2-arg only | **Decompiler incomplete** — caller passes fill-value temp; sealed W33-B as 3-arg RET 12 |
| 9 | Distinct from 00423cf0 | **Body twin** — same CF/callees; different SEH label + sole parent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout +8 / +0xc / +0x10.. / +0x20 / +0x24 | **High** | Member misaligned |
| Nested span 0x28 shape | **High** | Overlap adjacent fields |
| Product type / parent English | **Low** | Naming only |
| Flag semantics +0x20/+0x24 | **Med** | Wrong field meaning |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0074d750 (sole caller):
//   *self = PTR_FUN_00aa05cc
//   self[1]=0; self[2]=0
//   FUN_0044a0d0(self+3)   // bag @ outer +0x0c  (@ 0x0074d786)
//   FUN_0043bdf0(self+0xd)
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 98 B hex seals offsets and `RET 4`.

Callee check: `FUN_00423d60` = `new(0x28)` circular; `FUN_004646e0` = pointer vector init capacity N filled via `FUN_00436ef0`.

Twin CF vs W32-D `AssResolverA_NestedHash_Ctor` and W32-E `AssResolverCore_HeadBag_Ctor` confirms structural name family without inventing parent Ass* product.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
NestedHashBag* ctor(NestedHashBag* self) {
  self->sentinel = AllocCircularSentinel_0x28();  // FUN_00423d60
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);  // FUN_004646e0
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// Nested at FUN_0074d750 outer +0x0c; total nested 0x28 shape.
// Do not invent product English; pair with twins 00423cf0 / 00469db0.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/sole-caller role. Residual product plate + unwritten head dwords + flag meaning + unowned parent → **accept-with-gaps**.
