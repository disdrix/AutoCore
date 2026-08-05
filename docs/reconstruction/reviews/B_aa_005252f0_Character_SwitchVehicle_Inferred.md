# Review B (skeptical / adversarial): `aa_005252f0` Character_SwitchVehicle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005252f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-E) |
| **Counterpart** | `reviews/A_aa_005252f0_Character_SwitchVehicle_Inferred.md` |
| **Scratch** | `tmp/a_005252f0.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | `this` is the **new vehicle** | **Falsified** — call site loads `ECX=[client+0xe98]` character; body uses `this+0x250` as current vehicle |
| 2 | `__cdecl` / bare `ret` | **Falsified** — epilogue **`ret 0x10`**; prologue thiscall |
| 3 | Always fails / only error path | **Falsified** — happy path returns 0; error paths are specific HRESULTs + debug strings |
| 4 | Skips hardpoint deactivate/activate | **Falsified** — calls `004f4eb0` then later `004f4f00` |
| 5 | Cargo migrate always runs | **Falsified** — only when `new.pages < old.pages` |
| 6 | `+0x2ac=1` written on **new** vehicle | **Falsified** — decompile writes `*(old+0x2ac)=1` after create on new |
| 7 | argA/argB unused | **Falsified** — `(argA&argB)==0xFFFFFFFF` gates 64-bit counter bump |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Character thiscall + RET 0x10 | **High** | Wrong port ABI |
| HRESULT set | **High** | Client shows false success/fail |
| Stage order | **High** | Race / half-switched state |
| Nested hardpoint pair | **High** | Fire state stuck |
| Full phys 0x2F0 layout | **Low–Med** | Residual — do not invent fields |
| arg pair English | **Med** | Wrong id allocation policy |

---

## 3. Cross-check against raw + bytes

```
if (!new) return E_INVALIDARG
if (out) *out = this->vehicle
if (new.pages < old.pages) migrate_or_E_FAIL
snapshot; flag; DeactivateHardpoints(old)
CreateCargo(new); old+0x2ac=1
if (!new.chassis) alloc_phys; maybe_bump_id; SetWheelset
rebind; ActivateHardpoints(current)
stow_old_dual_fit or debug_stop
return S_OK
```

Clean must **not** claim bit-exact nested helper parity without their duals; must not invent product name.

---

## 4. Surviving contract for AutoCore

```c
// Port sketch — Character::SwitchVehicle (client)
// thiscall; RET 0x10; HRESULT
HRESULT Character_SwitchVehicle(
    Character* self,
    Vehicle* newVeh,
    Vehicle** outOld,
    uint32_t a, uint32_t b)
{
  if (!newVeh) return 0x80070057;
  Vehicle* old = self->vehicle; // +0x250
  if (outOld) *outOld = old;
  // pages@+0x1e6 shrink-migrate via InventoryGrid 6*(pages*13)
  // DeactivateHardpointWeapons(old)
  // CreateCargoInventoryFromPageCount(new, pages)
  // old->flag_2ac = 1
  // optional phys@+0x258 + SetWheelset; if (a&b)==~0u bump host counter
  // ActivateHardpointWeapons(self->vehicle)
  // dual inventory fit old or VOG_DEBUG_STOP
  return 0;
}
```

---

## 5. Gaps that survive adversarial pass

1. Product/PDB method name / class spelling.
2. argA/argB non-sentinel semantics.
3. Exact mid-function rebinding of `character+0x250`.
4. Nested residual duals (fit/place/phys ctor/transform helpers).
5. Runtime / bit-exact switch scenario.

**Verdict:** Adversarial pass **confirms** A on ABI, HRESULTs, stage spine, hardpoint pair → **accept-with-gaps**.
