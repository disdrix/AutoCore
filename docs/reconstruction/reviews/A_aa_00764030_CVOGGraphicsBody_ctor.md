# Review A (reconstruction fidelity): `aa_00764030` CVOGGraphicsBody_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00764030` |
| **VA** | `0x00764030` |
| **Canonical name** | `CVOGGraphicsBody_ctor` (**INFERRED**) |
| **Aliases** | `FUN_00764030`, gfx body / mesh host ctor (`operator_new(0x14c)`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00764030_CVOGGraphicsBody_ctor.md` |
| **System** | graphics / `inventory-transfer` (melee FX rebuild) |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Constructor** for a graphics-body object (allocation size **0x14c** on equip melee FX rebuild path):

1. SEH; base init `FUN_0096d830(this)`
2. Set vtable `PTR_LAB_00a9da8c`
3. Zero field block at dword indices `0x23..0x25`
4. `FUN_0096b100()` secondary base/init
5. Zero/init large field run (`0x2e..0x52` region): sentinels `0xffffffff` at `+0x2e` and `+0x40`; scale `this[0x51] = g_flOne`; link `this[0x37] = this[0x26]`, `this[0x38] = this+1`; clear flag bytes at `+0x3f`, `+0x139`, `+0x13a`, `+0x4e`
6. Return `this`

**Equip path:** `Vehicle_SetEquippedMeleeWeapon` rebuilds each entry in vehicle FX list `+0x3b8`: destroy old, `new(0x14c)`, **this ctor**, then `FUN_00989e00` load mesh name, vfuncs `+0x5c` / `+0x1c`.

Also called from `CVOGTacArc_InitializeMesh`, `CVOGCreature_SetupGraphics`, respawn/teleport special events, many graphics setup paths — **not melee-exclusive**.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX / arg0** | `this` storage (`__fastcall` / thiscall ctor) |
| return | `this` |

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00764030_*`, `reconstructed-exact/FUN_00764030.cpp` |
| Live decompile | Ghidra 2026-07-29 |
| Parent dual | `A_aa_004fe800` (melee FX rebuild) |
| Size evidence | `operator_new(0x14c)` at call sites |
| Vtable | `PTR_LAB_00a9da8c` |
| Resource sibling | `aa_00989e00` name lookup after ctor |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Base `FUN_0096d830` then vtable | **Yes** |
| Zero field clusters | **Yes** |
| `g_flOne` at scale slot | **Yes** |
| Self-links `0x37`/`0x38` | **Yes** |
| Returns this | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Ctor role | **High** | new+ctor pattern; returns this |
| Object size 0x14c | **High** | equip call site |
| Shared graphics body type | **High** | many non-equip callers |
| Product class name | **Tentative** | inferred GraphicsBody |
| Base helpers product | **Open** | `0096d830` / `0096b100` |

---

## 6. Gaps

1. Formal RTTI / product class name for vtable `00a9da8c`.
2. Full field dictionary beyond zeroed range.
3. Runtime open.

**Verdict:** Ctor CF sealed; equip uses as melee FX host factory. **accept-with-gaps.**
