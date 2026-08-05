# Review B (skeptical / adversarial): `aa_004c1800` ParticleFluidLiquidChild_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1800` |
| **VA** | `0x004c1800` |
| **Canonical name** | `ParticleFluidLiquidChild_Ctor_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_004c1800_ParticleFluidLiquidChild_Ctor_Inferred.md` |
| **System** | client / particle fluid phase / liquid child |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Bare cdecl / no stack cleanup | Epilog is `C2 04 00` | **Falsified** bare cdecl |
| 2 | Decompiler `FUN_004c17b0(param_1)` is whole-object thiscall | Bytes: `LEA ECX,[ESI+0x18]; PUSH ESI` | **Falsified** whole-object ECX — subobject `+0x18` |
| 3 | NDRiver.fx / Drive product class | No strings in body; NDRiver is InitPhases tail only | **Falsified** product plate |
| 4 | Full liquid init / resource bind | Init is parent `FUN_004c0fe0` after return | **Falsified** as complete liquid setup |
| 5 | Many static callers | Exactly 1 xref (`004c1995`) | **Agree** |
| 6 | Object larger than 0x40 | Parent `new(0x40)`; last store `+0x3C` | **Agree** 0x40 |
| 7 | `DAT_00b03794` is phase host | Phase host publish is `DAT_00b03790` (ctor `004c0640`) | **Falsified** as phase global |
| 8 | PDB LiquidChild proven | No body string | **Agree Open** product English |

---

## 2. Live ≡ raw

```
Live decompile ≡ raw 2026-07-23.
read_memory: 6A FF 68 A2 1A 9A 00 … 83 C4 10 C2 04 00  (0x7E B).
Caller: FUN_004c1960 @ 004c1995 only.
Callees: FUN_004933f0, FUN_004c17b0.
```

Bytes win over decompiler on `FUN_004c17b0` ECX target. **Agree High** with A.

---

## 3. Surviving contract

```
// void* __thiscall ParticleFluidLiquidChild_Ctor_Inferred(self, phase)
// RET 4; size 0x40; parent at +0; sentinel list +8/+c; active +10=0;
// host-link subobj +18 via FUN_004c17b0; zero +20..+3c; DAT_00b03794=self.
// Do not treat as phase ctor (004c0640) or liquid filter init (004c0fe0).
```

---

## 4. CF challenge of Review A

- Body size / RET 4 / thiscall: **agree Confirmed**
- Sole CreateLiquidChild caller: **agree Confirmed**
- Sentinel W32-P + host-link free: **agree**
- Name `ParticleFluidLiquidChild_Ctor_Inferred`: **agree acceptable** (structural `_Inferred`)
- Gaps on product English / `+0x20` map: **agree Open**

---

## 5. Residual risks

1. Product demangle for 0x40 class / `009cb7a4` host-link type.
2. OOM path is parent's (null before ctor) — not this body.
3. Nested `FUN_004c17b0` list side effects on phase host unowned.
4. Runtime / bit-exact / differential not run.

**Verdict:** **accept-with-gaps.** Agree with A on ABI, body bounds, layout skeleton, sole caller, and bytes-win subobject call.
