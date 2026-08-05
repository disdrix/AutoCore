# Review A (reconstruction fidelity): `aa_00508c50` HandlerTable58_FindById6c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508c50` |
| **VA** | `0x00508c50` |
| **Body** | `0x00508c50`–`0x00508c91` exclusive (**65** B) |
| **Canonical name** | `HandlerTable58_FindById6c` (inferred) |
| **Ghidra symbol** | `FUN_00508c50` |
| **Prior / alias** | `Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c50` (misleading) |
| **Review date** | `2026-07-29` (W21-D OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00508c50_HandlerTable58_FindById6c.md` |
| **System** | status/hook handler tables |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **linear find-by-id** over a pointer table at **`this+0x58`**:

1. Reject `id == -1` and non-positive global count **`DAT_00d02984`**.
2. Walk `table[i]` for `i ∈ [0, DAT_00d02984)`.
3. Match when **`*(int32*)(table[i] + 0x6c) == id`**.
4. Return matching entry pointer, else **null**.

Part of a fixed family of identical helpers with different table slots / count globals. Equip status-hook dual assigns this slot to item-def subtype **0xa** (10) handlers (`Vehicle_ApplyItemStatusHooksOnEquip`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508c50_FUN_00508c50.md` (+ W21-D append) |
| Annotated | `docs/reconstruction/raw/aa_00508c50_FUN_00508c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HandlerTable58_FindById6c.cpp` |
| Scaffold | `reconstructed-exact/FUN_00508c50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508c50_HandlerTable58_FindById6c.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x00508c50` length 65+ |
| Twin dual | `aa_00508c00` HandlerTable54_FindById6c (`+0x54` / `DAT_00d02988`) |
| Parent dual | `A_aa_004fe380_*` subtype **0xa** consumer |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (`read_memory` @ `0x00508c50`)

```
push edi
mov  edi, [esp+8]           ; id
xor  eax, eax
cmp  edi, -1
jz   → return 0
mov  edx, [DAT_00d02984]
test edx, edx
push ebx / push esi
jle  → return 0
mov  esi, [ecx+0x58]        ; table
mov  ecx, esi
loop:
  mov  ebx, [ecx]           ; *entry
  cmp  [ebx+0x6c], edi
  jz   → return table[eax]
  add  eax, 1
  add  ecx, 4
  cmp  eax, edx
  jl   loop
→ return 0
; both success/fail: pop esi/ebx/edi; ret 4
```

Hex (65 B):

```
578b7c240833c083ffff74298b158429d00085d253567e198b71588bce8d49008b19397b6c741283c00183c1043bc27cef5e33c05b5fc204008b04865e5b5fc20400
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **65** B through `ret 4` | meta end `00508c91` + `c2 04 00` + `cc` pad | **High** |
| `__thiscall` one stack arg | ECX this; `ret 4` | **High** |
| Table `*(this+0x58)` | `mov esi,[ecx+58]` | **High** |
| Id field `entry+0x6c` | `cmp [ebx+6c],edi` | **High** |
| Count `DAT_00d02984` | dword load `84 29 d0 00` | **High** |
| Reject `id == -1` | early `jz` | **High** |
| Leaf | empty callees | **High** |
| Decompile ≡ raw ≡ bytes | three-rep | **High** |

---

## 4. Callers

| Function | Role |
|---|---|
| `FUN_004fe380` Vehicle_ApplyItemStatusHooksOnEquip | subtype **0xa** handler resolve |
| `FUN_005092b0` … `FUN_00509940` | loot / type-from-prefix family |
| `FUN_00513580` Item_SumEquippedComponentValues | related table family consumer |

---

## 5. Gaps / open

1. Product/PDB names for registry and entry.
2. Who constructs `+0x58` and writes `DAT_00d02984`.
3. Runtime / bit-exact / differential not run.

**Verdict:** **accept** — leaf CF, ABI, offsets, and family role sealed High.
