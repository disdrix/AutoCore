# Review B (skeptical / adversarial): `NDSpecialFX_ExpandVehicleHardpointSlots` / `FUN_004ff850` @ `0x004ff850`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff850` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ff850_NDSpecialFX_ExpandVehicleHardpointSlots.md` |
| **Verdict** | **accept-with-gaps** on sealed CF/ABI/case table; **needs-more-evidence** on product name, interior-this type, and nested helper product roles |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is only exhaust-related (`Drive_s_VEHICLE_EXHAUST_d`) | **Falsified** — five format strings / five cases |
| 2 | stdcall / cdecl plain `ret` | **Falsified** — epilogue **`ret 0x0C`** (`C2 0C 00`) |
| 3 | Free-function with no `this` | **Falsified** — `mov edi,ecx`; negative offs from ECX |
| 4 | Type table is byte-sized / pointer list | **Falsified** — `(end-begin)>>2` dword count |
| 5 | Instantiates via unknown factory | **Falsified** — calls sealed `FUN_004a0b90` |
| 6 | Always tracks fail-notify | **Falsified** — gated on `param_4 != 0` |
| 7 | WHEELSET loops `0..count-1` inclusive 0 | **Falsified** — starts at **1** |
| 8 | Empty path skips attach | **Falsified** — `FUN_005829d0(template)` first |
| 9 | `CVOGReaction_FailMissionNotify` is mission fail RPC | **Open / weak** — dual elsewhere shows u32 vector push helper; product English open |
| 10 | Product/PDB name sealed | **Open** |
| 11 | Nested attach helpers fully understood | **Open** — residual OWN duals |
| 12 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + `ret 0x0C` | **Confirmed** | Stack imbalance / wrong this |
| Case table + format strings | **Confirmed** | Wrong child names / missing HP class |
| Instantiate link `0x004a0b90` | **Confirmed** | Wrong factory |
| Type vector dword half-open | **Confirmed** | Overrun / skip |
| Interior-this field map | **Low–Med** | Wrong host class port |
| `FUN_005829d0` product role | **Low** | Mis-port attach side effects |
| `FUN_00989270` presence probe | **Low** | Extra/missing children |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall  ret 0x0C
void ExpandVehicleHardpointSlots(thisHost, templateFx, p3, p4):
  types = dword_vector(templateFx+0x94, templateFx+0x98)
  if empty(types):
    Attach(templateFx, p3, p4)
    for i in 0..2:
      if slot = *(thisHost - 0x330 + 4*i): ProbeSlot(slot, 0, 1, i)
    return
  for each typeId in types:
    switch typeId:
      0x0B WHEELSET:  // needs *(this-0x418); count clamp; i=1..count-1
      0x0F EXHAUST:   // ids 0x4BB..0x4BF; stamp id-0x4BA
      0x10 BRAKES:    // ids 0x4C5..0x4CB; stamp id-0x4C4
      0x11 LIGHTS:    // ids 0x4CF..0x4D7; stamp id-0x4CE
      0x15 MELEE:     // ids 0x3E9..0x408; stamp id-1000
      each: snprintf name from template+0xD5;
            child = InstantiateFromTemplate(template, name, 1, typeId, stamp);
            if p4: Track(child);
            Attach(child, p3, p4)
  Attach(templateFx, p3, p4)

// NOT physics hardpoint equip (see Vehicle_EquipWheelset @ 0x004ff510 — different unit).
// NOT a single exhaust-only helper.
```

---

## 4. Falsification notes

### 4.1 Exhaust-only rename trap

Scaffold `Drive_s_VEHICLE_EXHAUST_d` overfits one string. Ports that only expand exhaust miss wheelset/brakes/lights/melee children.

### 4.2 Confuse with inventory wheelset equip

Nearby `Vehicle_EquipWheelset` (`0x004ff510`) mutates vehicle hardpoint **item** slots (`+0x258`). This VA expands **FX child instances** from a type table during create-from-packet. Different systems.

### 4.3 FailMissionNotify product fantasy

Named symbol suggests mission failure. Family duals treat the helper as a **u32 vector push**. Do not invent S2C mission-fail RPCs from this call site alone.

### 4.4 Decompiler void return

`analyze_function_complete` warns return type undefined. Body is void (no EAX result contract); epilogue is pure stack cleanup — do not invent a return value.

### 4.5 Case 0x10 fall-through

BRAKES omits the early `index++/goto` used by siblings and falls to the common tail. Net effect is the same single-step advance — do not invent a double-increment bug.

---

## 5. Open questions

1. Retail / PDB symbol.
2. Class of interior `thisHost` and field dictionary for −0x330 / −0x418 / −0x628.
3. Product semantics of `FUN_005829d0` / `FUN_004b7030` / `FUN_00989270`.
4. Runtime golden for multi-type table.

**Verdict:** **accept-with-gaps** on sealed CF, ABI, multi-string case table, and instantiate linkage. Reject exhaust-only and inventory-equip confusions. Nested helpers + product name open.
