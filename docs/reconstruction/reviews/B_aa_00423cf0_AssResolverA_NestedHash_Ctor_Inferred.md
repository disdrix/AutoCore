# Review B (skeptical / adversarial): `aa_00423cf0` AssResolverA_NestedHash_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423cf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-D) |
| **Counterpart** | `reviews/A_aa_00423cf0_AssResolverA_NestedHash_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` stack formal |
| 2 | Decompiler `undefined FUN_00423cf0(void)` is full ABI | **Falsified** — body takes stack this*, returns this |
| 3 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 4 | Writes all 0x28 bytes of member | **Partial** — `+0x00/+0x04` never written; sealed as gap |
| 5 | Multiple unrelated roles | **Falsified** — sole xref from AssResolverA ctor nested `+0x08` |
| 6 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB English “Hash” | **Careful** — structural from sentinel+bucket-table shape; `_Inferred` only |
| 8 | FUN_004646e0 is 2-arg only | **Decompiler incomplete** — caller passes fill-value temp; `FUN_00436ef0` fill uses it |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout +8 / +0xc / +0x10.. / +0x20 / +0x24 | **High** | Member misaligned |
| Span 0x28 vs parent CS at outer +0x30 | **High** | Overlap CS |
| Nested hash product type | **Low** | Naming only |
| Flag semantics +0x20/+0x24 | **Med** | Wrong field meaning |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// AssManager_ResolverA_Ctor_Inferred:
//   *self = PTR_FUN_00a95acc
//   FUN_00423cf0(self+8)   // @ 0x00423c0e
//   InitializeCriticalSection(self+0x30)
//   *(u8*)(self+0x48) = 1
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 98 B hex seals offsets and `RET 4`.

Callee check: `FUN_00423d60` = `new(0x28)` circular; `FUN_004646e0` = pointer vector init capacity N filled via `FUN_00436ef0`.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
NestedHash* ctor(NestedHash* self) {
  self->sentinel = AllocCircularSentinel_0x28();  // FUN_00423d60
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);  // FUN_004646e0
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// Nested at AssResolverA+0x08; total nested 0x28.
// Do not invent product English; pair with parent AssManager_ResolverA_Ctor.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/sole-caller role. Residual product plate + unwritten head dwords + flag meaning → **accept-with-gaps**.
