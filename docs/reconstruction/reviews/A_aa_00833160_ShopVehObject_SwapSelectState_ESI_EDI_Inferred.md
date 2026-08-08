# Review A (reconstruction fidelity): `aa_00833160` ShopVehObject_SwapSelectState_ESI_EDI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00833160` |
| **VA** | `0x00833160`–`0x00833383` exclusive (**547 B** / `0x223`) |
| **Canonical name** | `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` |
| **Ghidra name** | `FUN_00833160` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-D) |
| **Counterpart** | `reviews/B_aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md` |
| **System** | shopveh list / object select-state swap |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Register-pair worker: swap a curated subset of fields between two objects (ESI/EDI), including a three-way nested XformState swap at `+0x510` (temp via `FUN_00416240` + two `FUN_00416160`), optional nested position cross-set through vtbl `+0x1a0` / `FUN_0040cf90`, and vtbl `+0x3bc` refresh. Used when the shopveh list reassigns two slot objects.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9J-D append) | `docs/reconstruction/raw/aa_00833160_FUN_00833160.md` |
| Annotated | `docs/reconstruction/raw/aa_00833160_FUN_00833160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehObject_SwapSelectState_ESI_EDI_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00833160.cpp` |
| Function record | `docs/reconstruction/functions/aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md` |
| Nested helpers | `FUN_00416240` (WQ9I-H), `FUN_00416160` (WQ9I-G) |
| Live | decompile + assembly for FieldBlock swap and dword offsets |

---

## 3. Signature (sealed)

```c
// ESI=objA*, EDI=objB*; returns 0 if EDI==null else 1
uint8_t ShopVehObject_SwapSelectState_ESI_EDI_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| objA | ESI (caller `MOV ESI,[host+0x50c+…]`) | **High** |
| objB | EDI (`TEST EDI,EDI` first) | **High** |
| return | AL 0/1 | **High** |
| cleanup | `C3` | **High** |

---

## 4. Control flow (authority)

```
if EDI==0: return 0
swap dwords +0x508,+0x50C,+0x5D4,+0x298
swap bytes involving +0x4FC,+0x5D0,+0x5DC,+0xBC
// three-way +0x510:
temp = CopyClearFlags(ESI+0x510)     // FUN_00416240
Assign(ESI+0x510, EDI+0x510)         // FUN_00416160
Assign(EDI+0x510, temp)              // FUN_00416160
swap 4 dwords +0x5E0..+0x5EC
swap +0x500,+0x504
if both vtbl+0x1a0 non-null:
  cross FUN_0040cf90 on nested +0x90 positions
EDI->vtbl+0x3bc(); ESI->vtbl+0x3bc()
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Null EDI → 0 | prologue `TEST EDI` / `XOR AL,AL` | **High** |
| FieldBlock three-way | assembly @ `00833238`–`00833267` | **High** |
| Dword offsets | assembly @ `00833178`+ | **High** |
| Return 1 | epilogue `B0 01 … C3` | **High** |
| Sole caller shopveh list | `0083ad72` in `FUN_0083ac90` | **High** |
| Byte-swap micro-order | decompiler weak; offsets sealed | **Med** |

---

## 5. Machine bytes (entry / exit)

Prologue: `55 8B EC 83 E4 F0 81 EC DC 00 00 00 85 FF 53 75 07 32 C0 5B 8B E5 5D C3`  
Success epilogue: `B0 01 5B 8B E5 5D C3`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0083ac90` @ `0x0083ad72` (1) |
| Callees | `00416240`, `00416160`×2, `0040cf90`×2, vtbl+0x1a0, vtbl+0x3bc |

---

## 7. Gaps

1. Product demangle for object class / shopveh window.  
2. English for each swapped offset.  
3. Exact vtbl `+0x1a0` / `+0x3bc` method names.  
4. Byte-swap intermediate instruction order (net offsets sealed).  
5. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals ESI/EDI ABI, return contract, FieldBlock three-way swap, major dword offsets, and sole shopveh-list caller. Residual product English + byte micro-order → **accept-with-gaps**.
