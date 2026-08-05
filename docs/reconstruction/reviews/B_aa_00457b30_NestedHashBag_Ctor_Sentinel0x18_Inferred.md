# Review B (skeptical / adversarial): `aa_00457b30` NestedHashBag_Ctor_Sentinel0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457b30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-G) |
| **Counterpart** | `reviews/A_aa_00457b30_NestedHashBag_Ctor_Sentinel0x18_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — stack this*, `RET 4` |
| 2 | Decompiler void/undefined full ABI | **Falsified** — returns this in EAX |
| 3 | Dtor / free this | **Falsified** — placement ctor only |
| 4 | Object size is only 0x28 | **Partial** — this unit writes 0x28 bag; sole host alloc is **0x40** with caller-zeroed tail |
| 5 | Same sentinel as Ass NestedHash | **Falsified** — `FUN_00457c60` (**0x18**), not 0x28 |
| 6 | Same as W34-G twin 004438c0 | **Layout same, sentinel size different** (0x18 vs 0x30) — do not unify |
| 7 | Name claims PDB English | **Careful** — structural `_Inferred` only |
| 8 | Multiple callers | **Falsified** — sole xref `0073cae5` (`FUN_0073c810`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong CC |
| Layout bag 0x28 | **High** | Misalign |
| Sentinel node 0x18 | **High** | Wrong node stride / freelist |
| Host outer 0x40 + tail zeros | **High** (caller) | Incomplete host ctor if omitted |
| Product English | **Low** | Naming only |
| Flag meaning | **Med** | Field semantics |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0073c810 @ ~0x0073cae5:
//   pv = operator_new(0x40);
//   FUN_00457b30(pv);
//   *(u32*)(pv+0x28)=0; bytes 0x2c..0x2e=0;
//   *(u32*)(pv+0x30)=0; bytes 0x34..0x36=0;
//   *(u32*)(pv+0x38)=0; bytes 0x3c..0x3e=0;
//   store into table slot [10]
```

Live decompile ≡ scaffold CF. Full 98 B hex. Callee `FUN_00457c60` sealed W30-E as `StdList_AllocSentinel_0x18`.

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
Bag* ctor(Bag* self) {
  self->sentinel = AllocCircularSentinel_0x18();  // FUN_00457c60
  self->size = 0;
  InitPtrBuckets(self+0x10, /*cap*/9, /*fill*/self->sentinel);
  self->flag20 = 1;
  self->flag24 = 1;
  return self;
}
// Host may be 0x40: zero +0x28.. after this returns (caller).
// Do NOT unify with 0x30 twin (004438c0) or Ass 0x28 NestedHash.
// Stack this*, RET 4.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/CF/sole-caller/sentinel size/host outer size. Residual product plate + flags → **accept-with-gaps**.
