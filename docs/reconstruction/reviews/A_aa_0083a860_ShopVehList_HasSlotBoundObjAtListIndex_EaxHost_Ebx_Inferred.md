# Review A (reconstruction fidelity): `aa_0083a860` ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083a860` |
| **VA** | `0x0083a860`–`0x0083a87a` inclusive (**27 B** / `0x1B`) |
| **Canonical name** | `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` |
| **Ghidra name** | `FUN_0083a860` |
| **Review date** | `2026-08-05` (WQ9L-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-I) |
| **Counterpart** | `reviews/B_aa_0083a860_ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.md` |
| **System** | shopveh list five-slot reindex helper (parent `0x0083ac90`) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body) + callers/xrefs + `get_assembly_context` @ `0x0083adc2`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory (+ analyze/xrefs/disassemble_function/assembly_context). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Tiny **predicate** used by dualed parent `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` (`0x0083ac90`) on the id-match refresh path: locate the five-window slot whose control id encodes `list_i` (`id - 0x9ca4 == list_i`) and report whether that slot object has a non-null bound payload at `+0x508`.

- **true** → parent soft-refreshes via `FUN_0083a880(0)`
- **false** → parent reloads via `FUN_0083abf0`

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-I append) | `docs/reconstruction/raw/aa_0083a860_FUN_0083a860.md` |
| Annotated | `docs/reconstruction/raw/aa_0083a860_FUN_0083a860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0083a860.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Drive_i_d_shopveh_2d_wnd_list_veh_0083a860.cpp` |
| Parent dual | `aa_0083ac90` WQ9K-H (accept-with-gaps) |
| Live | full 27 B hex; full disasm; sole CALL @ `0x0083adc2` |

### Full body hex (live `read_memory`)

```text
0083a860: 50 E8 6A FF FF FF 85 C0 74 0E 33 C9 39 88 08 05 00 00
          0F 95 C1 8A C1 C3 32 C0 C3
```

Pad: `CC` ×5 then `FUN_0083a880` @ `0x0083a880`.

### Full disasm (authority)

```text
0083a860  PUSH EAX                 ; host* → stack arg for FUN_0083a7d0
0083a861  CALL 0x0083a7d0          ; RET 4; EBX = list_i (live)
0083a866  TEST EAX,EAX
0083a868  JZ   0083a878            ; miss → AL=0
0083a86a  XOR  ECX,ECX
0083a86c  CMP  dword ptr [EAX+0x508], ECX
0083a872  SETNZ CL
0083a875  MOV  AL,CL
0083a877  RET
0083a878  XOR  AL,AL
0083a87a  RET
```

---

## 3. Signature (sealed)

```c
// EAX = host*; EBX = list_i; AL = bool; bare RET
uint8_t ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(void);
// Portable reconstruction form (typed call sites):
uint8_t ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred(void *host, int list_i);
```

| Formal | Source | Conf |
|---|---|---|
| host* | **EAX** (`PUSH EAX` → finder; caller `MOV EAX,EBP`) | **High** |
| list_i | **EBX** (live into finder; caller `MOV EBX,EDI`) | **High** |
| return | **AL** = (`slot != null && slot[+0x508] != 0`) | **High** |
| cleanup | bare **`C3`** ×2 | **High** |

**Reject:** thiscall ECX=host; EAX=list_i (incorrect prior parent clean plate comment).

---

## 4. Nested finder (evidence only — not OWN)

`FUN_0083a7d0` (undualed):

```text
// stack host*; EBX = list_i; RET 4
for i in 0..4:
  slot = host+0x50c[i]
  if slot && GetId(slot) - 0x9ca4 == EBX:
    return slot
return 0
```

Constants shared with parent dual WQ9K-H: slots `@+0x50c[5]`, id base **`0x9ca4`**, payload gate **`+0x508`**.

---

## 5. Call site (sole)

```text
// FUN_0083ac90 @ 0x0083adc2  (id-match branch)
MOV EBX, EDI     ; list_i
MOV EAX, EBP     ; host
CALL 0x0083a860
TEST AL, AL
JNZ  soft_a880   ; else FUN_0083abf0
```

| Direction | Target |
|---|---|
| Sole CALL caller | `FUN_0083ac90` @ `0x0083adc2` |
| Callee | `FUN_0083a7d0` only |

---

## 6. Naming

| Name | Status |
|---|---|
| Ghidra `FUN_0083a860` | sealed |
| Canonical `ShopVehList_HasSlotBoundObjAtListIndex_EaxHost_Ebx_Inferred` | sealed (parent shopveh dual + drive xml scaffold; product demangle open → `_Inferred`) |
| Scaffold `Named_CalleeOf_…_0083a860` | **retired** |

---

## 7. Gaps

- Product English for host / slot class (shopveh inferred from parent dual + drive xml).
- Finder `0083a7d0` undualed (WQ9L-J residual chain).
- Exact type behind `slot+0x508` (bound vehicle/obj ptr — structural only).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Full-body bytes, dual-exit bare RET, EAX=host / EBX=list_i / AL=bool, and sole parent id-match branch sealed live. Product demangle + finder dual open → **accept-with-gaps**.
