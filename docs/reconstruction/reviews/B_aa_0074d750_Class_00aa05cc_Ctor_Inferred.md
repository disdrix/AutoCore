# Review B (skeptical / adversarial): `aa_0074d750` Class_00aa05cc_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074d750` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-C) |
| **Counterpart** | `reviews/A_aa_0074d750_Class_00aa05cc_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack-self* / RET 4 like NestedHash bag ctors | **Falsified** — `MOV ESI,ECX`; bare `C3`; no stack formal |
| 2 | Decompiler `__fastcall` is wrong | **Confirmed as right** for ECX this; still not stdcall |
| 3 | Complete dtor / free this | **Falsified** — no delete; returns this (ctor) |
| 4 | Host size unknown / larger than 0x5C | **Falsified** — multi-caller `operator_new(0x5c)`; bags end at +0x5B |
| 5 | Bags are thiscall ECX | **Falsified** — parent `LEA`+`PUSH` into W34-D/E stack-self* RET 4 |
| 6 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed alias only |
| 7 | Name invents “AnimController” product English | **Careful** — structural `Class_00aa05cc_*` from vtbl only; anim pairing is caller context, not plate |
| 8 | Single-purpose AssResolver host | **Falsified** — multi geo/anm bind sites; not Ass bag twin |
| 9 | `MOVSS` zeros 8 bytes at +8 | **Falsified** — MOVSS writes **4** bytes; only +8 dword |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thiscall ABI + return this | **High** | Wrong calling convention |
| Layout +0x0c/+0x34 + size 0x5C | **High** | Member overlap / heap overrun |
| NestedHashBag + NestedHash 0x14 callees | **High** | Wrong bag type at offset |
| Product class English | **Low** | Naming only |
| Vtbl method / bind semantics | **Med** | Mis-port host as pure container |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Typical caller (e.g. FUN_004930b0 sky_box path):
//   host = operator_new(0x5c)
//   if (host) host = FUN_0074d750()   // ECX=host thiscall
//   store host; pair with AnimSlot new(0x78) + tree new(0x14)
//   FUN_0074d420(geo); vtbl methods on host
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Full 94 B hex seals vtbl imm `cc 05 aa 00`, offsets `0x0c`/`0x34`, bare RET.

Callee duals W34-D/E already sealed NestedHash family; this unit is their composed parent residual.

---

## 4. Surviving contract for AutoCore

```
// Port as ECX thiscall ctor (not stack-self* RET 4):
Class_00aa05cc* ctor(Class_00aa05cc* self /*ECX*/) {
  self->vtbl = PTR_FUN_00aa05cc;
  self->field04 = 0;
  self->field08 = 0;
  NestedHashBag_Ctor(&self->bag0c);           // +0x0c, RET 4 placement
  NestedHash_Ctor_Sentinel0x14(&self->bag34);  // +0x34, RET 4 placement
  return self;
}
// Always new(0x5c). Do not invent product English.
// Pair with sealed W34-D/E bags; do not re-implement bag bodies here.
// Callers bind geo/anm after construction — ctor itself only installs layout.
```

---

## 5. Verdict

Adversarial pass confirms A on thiscall ABI, dual-bag layout, host size, and sealed callees. Residual product plate + method contracts + runtime → **accept-with-gaps**.
