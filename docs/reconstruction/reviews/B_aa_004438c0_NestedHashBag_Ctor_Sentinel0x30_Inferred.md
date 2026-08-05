# Review B (skeptical / adversarial): `aa_004438c0` NestedHashBag_Ctor_Sentinel0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004438c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-G) |
| **Counterpart** | `reviews/A_aa_004438c0_NestedHashBag_Ctor_Sentinel0x30_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` stack formal |
| 2 | Decompiler `undefined FUN_004438c0(void)` is full ABI | **Falsified** — stack this*, returns this |
| 3 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 4 | Writes all fields of bag | **Partial** — `+0x00/+0x04` never written; sealed as gap |
| 5 | Identical to Ass NestedHash including sentinel size | **Falsified** — uses `FUN_005b43b0` (**0x30**), not `FUN_00423d60` (**0x28**) |
| 6 | Scaffold `Named_CalleeOf_*_gfxFont_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB English “Hash” | **Careful** — structural from sentinel+bucket-table shape; `_Inferred` only |
| 8 | FUN_004646e0 is 2-arg only | **Decompiler incomplete on some call sites** — here 3 stack args: base, 9, &fill (W33-B sealed stdcall) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout +8 / +0xc / +0x10.. / +0x20 / +0x24 | **High** | Member misaligned |
| Sentinel node size 0x30 | **High** | Wrong freelist/node stride |
| Nested hash product type English | **Low** | Naming only |
| Flag semantics +0x20/+0x24 | **Med** | Wrong field meaning |
| Host class product plate | **Open** | Caller naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_00754ee0 (sole caller):
//   *host = PTR_FUN_00a9f584; ... string + fields ...
//   FUN_004438c0(host + 0x11)  // +0x44 @ 0x00754f3e
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 98 B hex seals offsets and `RET 4`.

Callee bytes: `FUN_005b43b0` = `push 0x30; call operator_new; *eax=eax; *(eax+4)=eax; ret`.
`FUN_004646e0` sealed W33-B as PtrVecShell_InitFill count×4 / fill / max-size.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
Bag* ctor(Bag* self) {
  self->sentinel = AllocCircularSentinel_0x30();  // FUN_005b43b0
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);  // FUN_004646e0
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// Do NOT unify with Ass NestedHash (0x28 sentinel) or 0x18 twin (00457b30).
// Stack this*, RET 4. Host embeds at +0x44 (FUN_00754ee0).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/sole-caller/sentinel size. Residual product plate + unwritten head dwords + flag meaning → **accept-with-gaps**.
