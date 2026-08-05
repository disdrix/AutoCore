# Review B (skeptical / adversarial): `aa_004b18f0` ObjectMotion_SyncChildPoseHF_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b18f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-F) |
| **Counterpart** | `reviews/A_aa_004b18f0_ObjectMotion_SyncChildPoseHF_Inferred.md` |
| **Scratch** | `tmp/a_004b18f0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / no stack formal | **Falsified** — `RET 4`; loads `[esp+…]` as flag into EDI |
| 2 | Always runs (no gate) | **Falsified** — `test edi,edi; jz` skips entire body |
| 3 | Writes slot self pose only | **Falsified** — all XYZ writes go through `*(slot+8)` child |
| 4 | Leaf / no heightfield | **Falsified** — CALL `FUN_004cd220` |
| 5 | Y lift is 0.4 (SlotTick constant) | **Falsified** — `DAT_00aaa8f4` = ≈**0.04** not 0.4 |
| 6 | `0x3f400000` is pointer | **Falsified** — imm float **0.75** |
| 7 | Product name is retail string | **Overstated** — no plate; structural `_Inferred` only |
| 8 | Basis triple is fixed (0,1,0) in image | **Residual** — image static **0**; runtime OPEN (divide hazard if Y stays 0) |
| 9 | Emitter path calls with 1 formal only | **Partial** — some clean twins omit flag; machine always thiscall+flag |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 | **High** | ABI break |
| Flag gate polarity | **High** | Silent no-op / always-on |
| Child@+8 ownership of pose | **High** | Wrong object moved |
| HF + 0.04 Y | **High** | Terrain snap error |
| Nested matrix English | **Low** | Mis-port of orientation path |
| Basis triple runtime | **Open** | NaN / div0 if zero Y |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall ObjectMotion_SyncChildPoseHF_Inferred(slot, flag)
if flag==0: RET 4
FUN_00973820 / FUN_00973690(0.75,…) / FUN_006a3db0 → child+0x37
copy slot+0x10/18/2c → child
hfY = SampleHeightfieldY(slot.x, slot.z)
child.pos = DAT_00b03530_triple * (-(slot.y-hfY)/basis.y) + slot.pos
child.y += ≈0.04
RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Call sites: SlotTick `@0x004b48f7` (push flag; ecx=slot); `FUN_005bc120` `@0x005bc335`.

---

## 4. Surviving contract for AutoCore

```
// After ObjectMotion_IntegrateStep when slot has child pointer slot[2]/slot+8]:
ObjectMotion_SyncChildPoseHF_Inferred(slot, flag);
// Do not invert flag gate; do not write pose onto slot instead of child
// Preserve 0.75 helper arg and ≈0.04 Y lift; preserve ret 4 thiscall
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/HF/constants; leaves nested matrix English + basis runtime as **gaps** → **accept-with-gaps**.
