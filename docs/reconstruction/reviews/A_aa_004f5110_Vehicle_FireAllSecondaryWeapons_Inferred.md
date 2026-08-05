# Review A (reconstruction fidelity): `aa_004f5110` Vehicle_FireAllSecondaryWeapons_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5110` |
| **VA** | `0x004f5110` |
| **Canonical name** | `Vehicle_FireAllSecondaryWeapons_Inferred` |
| **Ghidra symbol** | `FUN_004f5110` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004f5110_Vehicle_FireAllSecondaryWeapons_Inferred.md` |
| **System** | `combat` / vehicle weapons (nested from DriveControlTick → secondary fire) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin vehicle **thiscall / ECX=vehicle**: for each of **3 hardpoint weapons** at `*(vehicle+0x260) + {0,4,8}`, if non-null and **weapon vtbl+0x3C()** true, call **`FUN_0056d520(weapon)`** and OR the returned bytes. Returns aggregate success.

**Secondary-group fire-all** twin of primary `Vehicle_FireAllPrimaryWeapons_Inferred` (`0x004f50d0`, vtbl **+0x38**). Sole static caller: `Input_TryFireSecondaryWeapons` `0x0091a550` (after heat quantifier `0x004f52e0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f5110_FUN_004f5110.md` |
| Annotated | `docs/reconstruction/raw/aa_004f5110_FUN_004f5110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004f5110.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f5110_FUN_004f5110.md` (updated this pass) |
| Primary twin dual | `reviews/A_aa_004f50d0_Vehicle_FireAllPrimaryWeapons_Inferred.md` |
| Heat sibling dual (this batch) | `reviews/A_aa_004f52e0_Vehicle_CanFireAllSecondaryHeatOK_Inferred.md` |
| Parent dual | `reviews/A_aa_0091a550_Input_TryFireSecondaryWeapons.md` |
| Ghidra | `decompile_function` @ `0x004f5110`; `read_memory` 64 B; callers |
| Parent chain | DriveControlTick `0x009223b0` → `Input_TryFireSecondaryWeapons` |

**Not performed:** Launcher, runtime golden, bit-exact binary diff.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX vehicle thiscall | **High** | Asm `mov ebp,ecx`; parent loads vehicle into ECX |
| 3 hardpoint slots @ `*(+0x260)` | **High** | Loop `+4` while `< 0xC`; same family as primary fire-all |
| Table is **pointer** to array (not inline) | **High** CF | `mov eax,[ebp+0x260]; mov esi,[edi+eax]` |
| vtbl+**0x3C** secondary group predicate | **High** CF / **Probable** English | Asm `call [edx+0x3c]`; twin primary +0x38 |
| `FUN_0056d520` thiscall on **weapon** | **High** | Asm `mov ecx,esi` before relative call |
| OR-accumulate start results → AL | **High** | `or bl,al` … `mov al,bl` |
| No heat / no turret / no skill cast in unit | **High** | Body only vtbl+0x3C + 0056d520 |
| Sole static caller `0x0091a550` | **High** | Ghidra callers |
| Product name without `_Inferred` | **Probable** | No string/RTTI |
| `FUN_0056d520` full product semantics | **Probable** CF | Own dual residual; sets fire flags + HB |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| any=0; for byteOff 0,4,8 | **Yes** |
| null weapon → skip | **Yes** |
| vtbl+0x3C false → skip start | **Yes** |
| start → any \|= result | **Yes** |
| return any | **Yes** |
| No invented heat / primary group | **Yes** |

### Sealed CF sketch

```
Vehicle_FireAllSecondaryWeapons_Inferred(vehicle):
  any = 0
  table = *(weapon***)(vehicle + 0x260)
  for off in {0, 4, 8}:
    w = *(weapon**)((byte*)table + off)
    if w == null: continue
    if !w->vtbl[+0x3C](): continue   // secondary group
    any |= FUN_0056d520(w)           // start fire / HB
  return any
```

### Asm seal (prolog + loop)

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
  call [edx+0x3c]        ; secondary group
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
  pop… ret
```

### Primary vs secondary fire walker

| | Primary `0x004f50d0` | Secondary `0x004f5110` |
|---|---|---|
| Hardpoint table | same `*(v+0x260)`, 3 slots | same |
| Group vtbl | **+0x38** | **+0x3C** |
| Start callee | `FUN_0056d520` | same |
| Return | OR aggregate | same |
| Heat | caller `0x004f5290` (∃) | caller `0x004f52e0` (∀) |

---

## 5. Callers / callees

| Direction | Addr / symbol | Role |
|---|---|---|
| Caller (only) | `Input_TryFireSecondaryWeapons` `0x0091a550` | After heat gate |
| Callee | weapon vtbl **+0x3C** | Secondary-group predicate |
| Callee | `FUN_0056d520` | Start weapon fire |
| Twin | `0x004f50d0` primary fire-all | Same skeleton, +0x38 |

---

## 6. Gaps / open

1. Product English for vtbl **+0x3C** (IsSecondary_Inferred).
2. Full dual unit for `FUN_0056d520` side effects.
3. Runtime: mixed primary/secondary hardpoints → only +0x3C weapons start.
4. Bit-exact / Launcher deferred.

**Verdict:** **accept-with-gaps**
