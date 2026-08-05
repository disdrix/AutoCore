# Review A (reconstruction fidelity): `aa_004f50d0` Vehicle_FireAllPrimaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f50d0` |
| **VA** | `0x004f50d0` |
| **Canonical name** | `Vehicle_FireAllPrimaryWeapons_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f50d0_Vehicle_FireAllPrimaryWeapons_Inferred.md` |
| **System** | `combat` / vehicle weapons |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin vehicle **thiscall**: for each of **3 hardpoint weapons** at `*(vehicle+0x260) + {0,4,8}`, if non-null and **weapon vtbl+0x38()** true, call **`FUN_0056d520(weapon)`** and OR the returned bytes. Returns aggregate success. Primary-group fire-all used by `Input_TryFirePrimaryWeapons_Inferred` after existential heat probe `FUN_004f5290`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f50d0_FUN_004f50d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004f50d0_FUN_004f50d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_FireAllPrimaryWeapons_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f50d0_Vehicle_FireAllPrimaryWeapons_Inferred.md` |
| Parent dual | `reviews/A_aa_00922270_Input_TryFirePrimaryWeapons_Inferred.md` |
| Sibling fire-all secondary | `FUN_004f5110` @ `0x004f5110` (vtbl+0x3C) |
| Heat probe primary | `FUN_004f5290` @ `0x004f5290` |
| Start-fire callee | `FUN_0056d520` @ `0x0056d520` |
| Ghidra | `decompile_function` + `analyze_function_complete` + `read_memory` prolog/loop |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX vehicle thiscall | **High** | Asm `mov ebp,ecx`; parent `mov ecx,esi` with `esi=[char+0x250]` |
| 3 hardpoint slots @ +0x260 | **High** | Loop `+4` while `< 0xC`; same family as `Vehicle_IsAnyWeaponFiring` |
| Table is **pointer** to array (not inline at +0x260) | **High** CF | `mov eax,[ebp+0x260]; mov esi,[edi+eax]` |
| vtbl+0x38 primary group predicate | **High** CF / **Probable** English | Asm `call [edx+0x38]`; twin secondary +0x3C |
| `FUN_0056d520` thiscall on **weapon** (ECX=esi) | **High** | Asm `mov ecx,esi` before relative call |
| OR-accumulate start results → AL | **High** | `or bl,al` … `mov al,bl` |
| No heat / no turret / no skill cast in unit | **High** | Body only vtbl+0x38 + 0056d520 |
| Sole static caller `0x00922270` | **High** | xrefs + analyze_function_complete |
| Product name without `_Inferred` | **Probable** | Parent sketch name; no string/RTTI |
| `FUN_0056d520` full product semantics | **Probable** CF | Own dual open; body sets `+0xC7` fire flag + HB |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| any=0; for byteOff 0,4,8 | **Yes** |
| null weapon → skip | **Yes** |
| vtbl+0x38 false → skip start | **Yes** |
| start → any \|= result | **Yes** |
| return any | **Yes** |
| No invented heat / turret / AI branches | **Yes** |

### Sealed CF sketch

```
Vehicle_FireAllPrimaryWeapons_Inferred(vehicle):
  any = 0
  table = *(weapon***)(vehicle + 0x260)
  for off in {0, 4, 8}:
    w = *(weapon**)((byte*)table + off)
    if w == null: continue
    if !w->vtbl[+0x38](): continue   // primary group?
    any |= FUN_0056d520(w)           // start fire / HB
  return any
```

### Asm seal (prolog + loop tail)

```
push ebx/ebp/esi/edi
xor  bl, bl              ; any = 0
mov  ebp, ecx            ; vehicle
xor  edi, edi            ; off = 0
loop:
  mov  eax, [ebp+0x260]
  mov  esi, [edi+eax]    ; weapon*
  test esi, esi
  jz   next
  mov  edx, [esi]        ; vtbl
  mov  ecx, esi
  call [edx+0x38]
  test al, al
  jz   next
  mov  ecx, esi
  call FUN_0056d520
  or   bl, al
next:
  add  edi, 4
  cmp  edi, 0xC
  jl   loop
  mov  al, bl
  ret
```

---

## 5. Gaps / open

1. Retail / PDB name for this unit and for weapon vtbl+0x38 product word.
2. Dual pack for `FUN_0056d520` (start-fire HB) if not already sealed as named.
3. Confirm whether empty hardpoint table pointer (null base) is possible — raw would fault; caller equip path usually allocates.
4. Cross-doc: physics airstab notes also cite `+0x260` as “stabilizer slots” — combat equip + this family seal **weapons**; resolve product word globally outside this unit.

**Verdict:** **accept-with-gaps**
