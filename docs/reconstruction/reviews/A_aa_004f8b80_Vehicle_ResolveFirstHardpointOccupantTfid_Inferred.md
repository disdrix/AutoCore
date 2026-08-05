# Review A (reconstruction fidelity): `aa_004f8b80` Vehicle_ResolveFirstHardpointOccupantTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f8b80` |
| **VA** | `0x004f8b80` |
| **Canonical name** | `Vehicle_ResolveFirstHardpointOccupantTfid_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004f8b80_Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** (walk sealed; method product English still `_Inferred`) |
| **Pass** | dual quality strengthen — vehicle+0x260 walk (asm + cross-fn strings) |

---

## 1. Purpose

Alt TFID helper for `Client_Skill_ResolveCastTarget` when the primary resolve list reports filter-reject bit4 and the skill has flag `+0x614 & 8`. Walks the **3-entry weapon hardpoint pointer table** at `*(vehicle+0x260)` and returns the first live occupant object TFID (`obj+0x160`), else sentinel `&DAT_009cd0f8`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004f8b80` |
| Body bytes | Ghidra `read_memory` @ `0x004f8b80` / `0x004f8c00` |
| Sentinel bytes | `read_memory` @ `0x009cd0f8` (16B) |
| Callers | `get_function_callers` → sole `Client_Skill_ResolveCastTarget` @ `0x0093b3a0` |
| Cross walk | decompile `FUN_004fe110`, `Vehicle_IsAnyWeaponFiring`, `VehicleAction_airStabilization` |
| List helpers | decompile `FUN_004294f0`, `FUN_004022a0` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact/…004f8b80…` |

---

## 3. Sealed walk contract (`vehicle+0x260`)

### 3.1 Table shape (asm Confirmed)

```
; ECX = vehicle (fastcall this)
mov  eax, [esp+vehicle]
mov  ecx, [eax+0x260]      ; tableBase = *(vehicle+0x260)
mov  esi, [ecx+ebp]        ; slot = tableBase[ebp/4], ebp in {0,4,8}
…
add  ebp, 4
cmp  ebp, 0x0C
jl   loop
```

| Claim | Confidence | Evidence |
|---|---|---|
| Base is `*(vehicle+0x260)` (pointer to array), **not** inline `vehicle+0x260+i` | **Confirmed** | `mov ecx,[eax+0x260]` then `[ecx+ebp]` |
| Exactly **3** slots | **Confirmed** | `ebp += 4` while `ebp < 0xC` |
| Index forms equivalent | **Confirmed** | this: byte off 0/4/8; equip `FUN_004fe110`: `slotIndex * 4`; fire `Vehicle_IsAnyWeaponFiring`: `piVar2++` over same base |

### 3.2 Table product identity (string Confirmed)

| Claim | Confidence | Evidence |
|---|---|---|
| Table holds **weapon** hardpoint objects | **Confirmed** | `FUN_004fe110` log `"Tried to equip same weapon %d"` on `*( *(veh+0x260) + slot*4 )`; stores via `Vehicle_AttachWeapon` |
| Slot count 0..2 | **Confirmed** | AttachWeapon dual + equip path; IsAnyWeaponFiring loop bound 3 |
| Physics “stabilizer slots” label | **Falsified as distinct table** | `VehicleAction_airStabilization` walks the **same** `*(entity+0x260)` 3-slot form; no second table — prior physics notes mislabeled weapon hardpoints |

### 3.3 Per-slot gates (asm Confirmed)

| Step | Op | Confidence |
|---|---|---|
| Null slot skip | `cmp esi, ebx; je` | **Confirmed** |
| `vtbl+0x40()` truthy | `call [edx+0x40]; test al,al` | **Confirmed** (semantic = active/valid — product name open) |
| List ptr = `slot+0x13c` (`slot[0x4f]`) | `mov esi,[esi+0x13c]` | **Confirmed** |
| Non-empty: `list+0x24 != 0` (unsigned) | `cmp [esi+0x24],ebx; jbe` | **Confirmed** |

### 3.4 List lock + first occupant TFID (asm Confirmed)

| Step | Detail | Confidence |
|---|---|---|
| Lock | `FUN_004294f0` thiscall list; string `"List Error! TraversalLock Call Stack"` / `VOG_DEBUG_STOP` | **Confirmed** role = traversal lock |
| Iterate | `FUN_004022a0(list, &cursor, &listValue)`; ret `0` = has element | **Confirmed** (sibling uses same API) |
| Occupant object | `edi = *(listValue + 4)` — **not** `listValue` itself | **Confirmed** (bytes `8b 54 24 10; 8b 7a 04`) |
| Success return | `lea eax, [edi+0x160]` → pointer to 16-byte TFID | **Confirmed** |
| Unlock | if `list+0x28`: clear + `LeaveCriticalSection(list+4)` | **Confirmed** |
| Miss return | `mov eax, offset DAT_009cd0f8` | **Confirmed** |

### 3.5 Sentinel content (read_memory Confirmed)

`DAT_009cd0f8` first 16 bytes: `ff ff ff ff ff ff ff ff 00 00 00 00 00 00 00 00`  
→ lo/hi coid = `0xFFFFFFFF`, then zeros. Caller compares via `TFID_EqualsObjectId` to its invalid template (pointer identity ≠ `g_abTfidInvalid_*`).

---

## 4. Confidence table (full)

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller ResolveCastTarget | **Confirmed** | callers API |
| 3-slot `*(v+0x260)` walk | **Confirmed** | asm |
| Table = weapon hardpoints | **Confirmed** | equip string + AttachWeapon |
| Returns first occupant TFID @ +0x160 | **Confirmed** | asm `lea eax,[edi+0x160]` after `*(listValue+4)` |
| Sentinel `&DAT_009cd0f8` all-ones coid | **Confirmed** | read_memory |
| Caller UX `"No enemies found."` | **Confirmed** | ResolveCastTarget path |
| Method product English “HardpointOccupant” | **Probable** | no string in body; keep `_Inferred` |
| `vtbl+0x40` product name | **Open** | truthy gate only |
| `listValue+4` element type name | **Open** | layout sealed; type word not |

---

## 5. Clean correctness notes

1. Earlier scaffold used `*(vehicle + 0x260 + off)` — **wrong**. Corrected: index through table pointer.
2. List path: `listValue` from iterator param_3; occupant = `*(listValue+4)`; TFID at `occupant+0x160`. Clean must not treat param_3 as raw object with TFID at +0x160 (unlike some sibling list walks such as `FUN_004f8e00`).
3. `FUN_004294f0` / `FUN_004022a0` are thiscall on the list at `slot+0x13c` (decompiler often drops ECX).

---

## 6. Gaps (remaining)

1. Product method symbol (still `_Inferred`).
2. Product name of `vtbl+0x40` predicate.
3. Typed layout of list element at `slot+0x13c` (why `*(value+4)` vs direct object in sibling lists).
4. Runtime capture of which hardpoint index supplies alt cast TFID in practice.

**Verdict:** **accept-with-gaps** — vehicle+0x260 **walk mechanics + weapon identity sealed**; residual is naming / list-element type English only.

---

## Checklist

| Check | Result |
|---|---|
| Sole caller | **Pass** |
| Double-indirection table walk | **Pass** (asm) |
| Weapon product string cross-link | **Pass** (`FUN_004fe110`) |
| Occupant `*(value+4)+0x160` | **Pass** (asm) |
| Sentinel bytes | **Pass** |
| Method product English | **Open** (`_Inferred`) |
| Verdict | **accept-with-gaps** |
