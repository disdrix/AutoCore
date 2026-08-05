# Review B (skeptical / adversarial): `aa_0043fdf0` NestedHash_Ctor_Sentinel0xC_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043fdf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-F) |
| **Counterpart** | `reviews/A_aa_0043fdf0_NestedHash_Ctor_Sentinel0xC_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — `MOV ESI,[ESP+0x18]`; `RET 4` stack formal |
| 2 | Decompiler `undefined FUN_0043fdf0(void)` is full ABI | **Falsified** — body takes stack this*, returns this |
| 3 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 4 | Writes all 0x28 bytes of member | **Partial** — `+0x00/+0x04` never written; sealed as gap |
| 5 | Single exclusive host / Ass-only | **Falsified** — **three** xrefs at distinct outer offsets |
| 6 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name claims PDB English “Hash” | **Careful** — structural from sentinel+bucket-table shape + Ass twin; `_Inferred` only |
| 8 | Sentinel is 0x28 like Ass twins | **Falsified** — callee is sealed `StdList_AllocSentinel_0xC` (`0x004933f0`) |
| 9 | FUN_004646e0 is 2-arg only | **Decompiler incomplete** — caller passes fill temp; W33-B sealed 3-arg RET 12 |
| 10 | Same SEH as 00463bd0 | **Falsified** — `LAB_009bc89b` vs `LAB_009bd31b` (matches AssResolverCore twin plate) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout +8 / +0xc / +0x10.. / +0x20 / +0x24 | **High** | Member misaligned |
| Span 0x28 shell | **High** | Host overlap |
| Sentinel node 0x0C | **High** | Wrong freelist/node layout |
| Nested hash product type | **Low** | Naming only |
| Flag semantics +0x20/+0x24 | **Med** | Wrong field meaning |
| Host product roles | **Low** | Port placement only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0074e380: *param_1 = g_flOne; zeros; FUN_0043fdf0(param_1+5);  // +0x14
// FUN_0096eec0: FUN_0043fdf0(param_1); then +0x28 flag fields...
// FUN_00996bc0: zeros; FUN_0043fdf0(param_1+10);  // +0x28
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 98 B hex seals offsets and `RET 4`.

Callee check: W32-P `StdList_AllocSentinel_0xC`; W33-B `PtrVecShell_InitFill` count 9.

Family check: byte-identical CF skeleton to `0x00423cf0` / `0x00469db0` / sibling `0x00463bd0`.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
NestedHash* ctor(NestedHash* self) {
  self->sentinel = StdList_AllocSentinel_0xC();  // FUN_004933f0
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);  // FUN_004646e0
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// RET 4 stack this; shell span 0x28.
// Hosts embed at +0x00 / +0x14 / +0x28 depending on outer type.
// Do not invent product English; do not swap with 0x28/0x30 sentinel factories.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/three-caller roles/sentinel-0x0C distinction. Residual product plate + unwritten head dwords + flag meaning → **accept-with-gaps**.
