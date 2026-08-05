# Review B (skeptical / adversarial): `aa_00463bd0` NestedHash_Ctor_Sentinel0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00463bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-F) |
| **Counterpart** | `reviews/A_aa_00463bd0_NestedHash_Ctor_Sentinel0x30_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` stack formal |
| 2 | Decompiler `undefined FUN_00463bd0(void)` is full ABI | **Falsified** — body takes stack this*, returns this |
| 3 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 4 | Writes all 0x28 bytes of member | **Partial** — `+0x00/+0x04` never written; sealed as gap |
| 5 | Sentinel size is 0x0C or 0x28 | **Falsified** — callee `FUN_005b43b0` is `operator_new(0x30)` circular (decompile sealed) |
| 6 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB English “Hash” | **Careful** — structural from sentinel+bucket-table shape + Ass twin; `_Inferred` only |
| 8 | FUN_004646e0 is 2-arg only | **Decompiler incomplete** — caller passes fill-value temp; W33-B sealed 3-arg RET 12 |
| 9 | Same object as AssResolverA nested | **Falsified as identity** — same **shape** (98 B twin), different sentinel size / host |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout +8 / +0xc / +0x10.. / +0x20 / +0x24 | **High** | Member misaligned |
| Span 0x28 (caller alloc) | **High** | Over-alloc/under-write |
| Sentinel node 0x30 | **High** | Wrong freelist/node layout |
| Nested hash product type | **Low** | Naming only |
| Flag semantics +0x20/+0x24 | **Med** | Wrong field meaning |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0075f7f0 (sole caller snippet):
//   pvVar1 = operator_new(0x28);
//   if (pvVar1) { DAT_00d1f628 = pvVar1; FUN_00463bd0(pvVar1); }
//   param_2[0x1d6] = pvVar1;
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 98 B hex seals offsets and `RET 4`.

Callee check: `FUN_005b43b0` = `new(0x30)` circular next/prev; `FUN_004646e0` = pointer vector init capacity N filled via `FUN_00436ef0` (W33-B).

Family check: byte-identical CF skeleton to `0x00423cf0` / `0x00469db0` / sibling `0x0043fdf0` (only call rel32 + SEH handler differ).

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
NestedHash* ctor(NestedHash* self) {
  self->sentinel = AllocCircularSentinel_0x30();  // FUN_005b43b0
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);  // FUN_004646e0
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// Host alloc size 0x28; RET 4 stack this.
// Do not invent product English; do not mix with 0x0C / 0x28 sentinel twins without matching factory.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/sole-caller role/sentinel-0x30 distinction. Residual product plate + unwritten head dwords + flag meaning → **accept-with-gaps**.
