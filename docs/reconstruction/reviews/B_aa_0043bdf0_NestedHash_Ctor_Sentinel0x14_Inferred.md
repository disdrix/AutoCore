# Review B (skeptical / adversarial): `aa_0043bdf0` NestedHash_Ctor_Sentinel0x14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bdf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-E) |
| **Counterpart** | `reviews/A_aa_0043bdf0_NestedHash_Ctor_Sentinel0x14_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` stack formal |
| 2 | Decompiler `undefined FUN_0043bdf0(void)` is full ABI | **Falsified** — body takes stack this*, returns this |
| 3 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 4 | Writes all 0x28 bytes of member | **Partial** — `+0x00/+0x04` never written; sealed as gap |
| 5 | Exclusive NDResourceCache-only | **Partial** — also nested in `FUN_0074d750`; name stays structural NestedHash |
| 6 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB English “Hash” | **Careful** — structural from sentinel+bucket-table shape; `_Inferred` only |
| 8 | Sentinel node is 0x28 like Ass twins | **Falsified** — callee `FUN_0043c460` is `new(0x14)` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout +8 / +0xc / +0x10.. / +0x20 / +0x24 | **High** | Member misaligned |
| Span 0x28 | **High** | Host overlap |
| Node size 0x14 | **High** | Wrong list node layout |
| Nested hash product type | **Low** | Naming only |
| Flag semantics +0x20/+0x24 | **Med** | Wrong field meaning |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0075d470 (NDResourceCache host):
//   DAT_00d1f050 = self
//   FUN_0043bdf0(self)          // bag at +0
//   zero +0x2c..+0x38; CS +0x3c; flag +0x54; tree +0x5c ...

// FUN_0074d750:
//   FUN_0044a0d0(self+0x0c)     // sibling NestedHash node 0x28
//   FUN_0043bdf0(self+0x34)     // this unit nested
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 98 B hex seals offsets and `RET 4`.
Callee check: `FUN_0043c460` = `new(0x14)` circular; `FUN_004646e0` = PtrVecShell_InitFill (W33-B).

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
NestedHash14* ctor(NestedHash14* self) {
  self->sentinel = AllocCircularSentinel_0x14();  // FUN_0043c460
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);  // FUN_004646e0
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// Do not invent product English; pair with NDResourceCache host and NestedHash family.
// Do not confuse node size with Ass 0x28 twins.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/node size/callers. Residual product plate + unwritten head dwords + flag meaning → **accept-with-gaps**.
