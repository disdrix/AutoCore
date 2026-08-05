# Review B (skeptical / adversarial): `aa_0096eec0` Host34_NestedHash0xC_Singleton_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096eec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-S) |
| **Counterpart** | `reviews/A_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall ctor | **Falsified** — stack self in ESI; `RET 4` |
| 2 | Decompiler `undefined FUN_0096eec0(void)` is full ABI | **Falsified** — stack this*, returns this |
| 3 | Complete dtor / free this | **Falsified** — no `operator_delete`; returns this (placement ctor) |
| 4 | Scaffold `Named_CalleeOf_*` is product | **Rejected** — parent-seed chain only |
| 5 | Decompile fully describes `FUN_0043bd40` call | **Falsified** — decompile omits `DAT_00d1f050+0x58` tree and key `0x00d1f7e4`; **bytes win** |
| 6 | Object size unknown / larger than NestedHash | **Sealed 0x34** — sole caller `operator_new(0x34)`; writes through `+0x30` |
| 7 | Name claims PDB “NDResource host” English | **Careful** — structural from NestedHash0xC + singleton + type-token sites; `_Inferred` only |
| 8 | Once-init is process-wide unrelated static | **Related** — same `DAT_00d1f7e4`/`PTR_FUN_00a9ef54` used as type token in `FUN_0096ea60` |
| 9 | `LAB_0096ed30` is data | **Falsified** — site has SEH function prologue bytes |
| 10 | Twin of `00996bc0` is same layout | **Falsified** — sibling embeds NestedHash at **+0x28**, span **0x54**, no singleton/map |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Placement ctor ABI | **High** | Wrong calling convention in port |
| Layout NestedHash@0 + 0x34 size | **High** | Host overlap / alloc size |
| Singleton `DAT_00d1f04c` | **High** | Wrong global |
| Once-init type-token | **High** | Double-register / missed atexit |
| Map insert key/value | **High** (bytes) | Wrong registry |
| Product host English | **Low** | Naming only |
| Handler `LAB_0096ed30` semantics | **Low** | Wrong callback contract |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0075f7f0:
//   pv = operator_new(0x34);
//   u = FUN_0096eec0(pv);
//   param_2[0x1d5] = u;
// peer: FUN_00463bd0(new(0x28)) → param_2[0x1d6] (W34-F NestedHash0x30 host)
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 NestedHash/flags CF. Full **170 B** hex seals epilogue `C2 04 00` and map path.

Callee check: W34-F `NestedHash_Ctor_Sentinel0xC`; unowned `FUN_0043bd40` (tree lower_bound/insert value slot).

---

## 4. Surviving contract for AutoCore

```
// Port as placement ctor (not thiscall):
Host34* ctor(Host34* self) {
  g_singleton_00d1f04c = self;
  NestedHash_Ctor_Sentinel0xC(self);   // FUN_0043fdf0 at +0
  self->flag28 = 1; self->f2c = 0; self->f30 = 0;
  once_init_type_token_00d1f7e4();     // guard bit + vtbl + atexit
  map_insert(*g_NDResourceCache + 0x58, key=0x00d1f7e4,
             value={LAB_0096ed30, 0}); // FUN_0043bd40
  return self;
}
// RET 4; alloc size 0x34.
// Do not invent product English; do not drop map registration.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/layout/singleton/once-init/map-register. Residual product plate + handler body + unowned map node → **accept-with-gaps**.
