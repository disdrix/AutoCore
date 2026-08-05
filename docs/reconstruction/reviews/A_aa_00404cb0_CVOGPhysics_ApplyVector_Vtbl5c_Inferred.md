# Review A (reconstruction fidelity): `aa_00404cb0` CVOGPhysics_ApplyVector_Vtbl5c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404cb0` |
| **VA** | `0x00404cb0`–`0x00404ce1` |
| **Body span** | 50 B (`0x32`) through `RET 4` |
| **Canonical name** | `CVOGPhysics_ApplyVector_Vtbl5c_Inferred` (Ghidra still `FUN_00404cb0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual; DriveControlTick callee) |
| **Counterpart** | `reviews/B_aa_00404cb0_CVOGPhysics_ApplyVector_Vtbl5c_Inferred.md` |
| **System** | `physics / CVOGPhysics` (also hit from `input-drive-control` brake-edge path) |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **CVOGPhysics** helper: optional readiness prepare on `this+0x44`, then forward a caller-supplied vector pointer to the bound rigid-body virtual method at **vtable slot `+0x5c`**.

**Byte-identical twin** of `CVOGPhysics_ApplyImpulseVector` (`0x0040d260`) except the final vtbl offset:

| Unit | VA | Final call |
|---|---|---|
| `ApplyImpulseVector` | `0x0040d260` | `CALL dword ptr [EDX+0x50]` |
| **this unit** | `0x00404cb0` | `CALL dword ptr [EDX+0x5c]` |

Gate path, stack shape, and epilogue match. Product English for slot `+0x5c` (impulse vs force vs other apply) is **not** sealed — only the dispatch offset is **High**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00404cb0_FUN_00404cb0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_00404cb0_FUN_00404cb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00404cb0.cpp` + Named twin |
| Function record | `docs/reconstruction/functions/aa_00404cb0_FUN_00404cb0.md` |
| Sibling dual | `A/B_aa_0040d260_CVOGPhysics_ApplyImpulseVector.md` |
| Parent call (context only) | `Client_Input_DriveControlTick` SECTION 8 brake-edge @ `0x00922fd4` |
| Live Ghidra | `decompile_function` `0x00404cb0`; `analyze_function_complete`; `get_function_callers` / `xrefs`; `read_memory` body + helpers `0x005070b0` / `0x005070d0` + sibling `0x0040d260` |
| Float const (caller) | `DAT_00aaacc0` @ `0x00aaacc0` → **550.0f** (`read_memory` `00 80 09 44`) |

**Not performed:** Launcher, runtime golden, bit-exact image diff, deep dual of `FUN_005070b0` / `FUN_005070d0` / implementers of vtbl+0x5c.

---

## 3. Signature

```c
// MSVC __thiscall — ECX = CVOGPhysics*; stack arg = vector*; RET 4
void __thiscall CVOGPhysics_ApplyVector_Vtbl5c_Inferred(
    int /*CVOGPhysics**/ this,
    void /*const float**/ *pVec);
// Stack at entry: [esp+4] = pVec
// Return: void (EAX not a semantic result)
```

| Item | Evidence | Confidence |
|---|---|---|
| Convention | `RET 4` @ `0x00404cdf`; ECX saved/restored as `this` | **High** |
| `this` | `MOV ESI, ECX`; fields `+0x3c`, `+0x44` | **High** |
| Stack arg | `MOV EAX, [ESP+0xC]` after two pushes → original `[ESP+4]` | **High** |
| Leaf-ish | Direct callees only `FUN_005070b0`, `FUN_005070d0`, plus one vfunc | **High** |
| Body range | Entry `00404cb0`, end `00404ce1` (`get_function_by_address`) | **High** |

---

## 4. Control flow (sealed)

```
ESI = this (ECX)
outByte = high-byte of saved-this on stack   // LEA EAX,[ESP+7]; PUSH EAX
FUN_005070b0(this, &outByte)                // thiscall; writes *outByte; leaves EAX=outByte*
if (*outByte == 0 && *(this+0x44) != 0)
    FUN_005070d0(this)                      // thiscall / fastcall ECX=this
body = *(this+0x3c)
vtbl = *body
CALL vtbl[+0x5c](pVec)                      // thiscall ECX=body; stack=pVec
return
```

**No** null check on `body` / vtbl before the virtual call (null → fault). Intermediate `this` null likewise unchecked.

### 4.1 Decompiler artifact (do not port literally)

Ghidra shows:

```c
pcVar1 = (char *)FUN_005070b0((int)&uStack_4 + 3);
if (*pcVar1 == '\0' && ...)
```

Live bytes of `FUN_005070b0` (`0x005070b0`):

- `void __thiscall (this, uint8_t *out)` — writes `0` or `*( *(this+0x44) + 0x29 )` into `*out`
- Always ends with `MOV EAX, [ESP+4]` (the out pointer) then `RET 4`
- Caller `CMP BYTE PTR [EAX], 0` uses that returned out pointer

So: **out-param + EAX alias**, not “return a char* into a flag table.” Clean ports should model an out-byte, not a returned pointer into TLS.

---

## 5. Machine bytes (`read_memory` @ `0x00404cb0`, 50 code B)

```
51                      PUSH ECX                    ; save this
56                      PUSH ESI
8D 44 24 07             LEA  EAX, [ESP+7]           ; &high-byte of saved this
50                      PUSH EAX                    ; out arg
8B F1                   MOV  ESI, ECX               ; ESI = this
E8 F2 23 10 00          CALL FUN_005070b0           ; → 0x005070b0
80 38 00                CMP  BYTE PTR [EAX], 0
75 0D                   JNZ  apply
83 7E 44 00             CMP  DWORD PTR [ESI+0x44], 0
74 07                   JZ   apply
8B CE                   MOV  ECX, ESI
E8 00 24 10 00          CALL FUN_005070d0           ; → 0x005070d0
8B 4E 3C                MOV  ECX, [ESI+0x3c]        ; body*
8B 44 24 0C             MOV  EAX, [ESP+0xC]         ; pVec
8B 11                   MOV  EDX, [ECX]             ; vtbl
50                      PUSH EAX
FF 52 5c                CALL DWORD PTR [EDX+0x5C]   ; ★ slot 0x5c
5E                      POP  ESI
59                      POP  ECX
C2 04 00                RET  4
```

Hex: `51568d442407508bf1e8f2231000803800750d837e440074078bcee8002410008b4e3c8b44240c8b1150ff525c5e59c20400`

Decompile CF ≡ bytes. **No conflict** on gate order or vtbl offset.

### 5.1 Sibling identity (`read_memory` @ `0x0040d260`)

Same instruction stream through the prepare gate; only difference is `FF 52 50` (`+0x50`) vs `FF 52 5C` (`+0x5c`). Body lengths match (50 B code + INT3 pad). **High**.

---

## 6. Key offsets (this object)

| Offset | Role | Confidence |
|---|---|---|
| `this+0x3c` | rigid-body / physics-body pointer used as vfunc `this` | **High** |
| `this+0x44` | readiness / host pointer; null → skip prepare; non-null feeds `FUN_005070b0` flag at `host+0x29` | **High** (structural) |
| body vtbl `+0x5c` | virtual apply/set method taking the vector arg | **High** (offset); English **open** |
| body vtbl `+0x50` | sibling `ApplyImpulseVector` slot (linear apply/set) | **High** (prior dual) |

Helper `FUN_005070b0` (owned only as callee contract):

| Condition | Writes to `*out` |
|---|---|
| `*(this+0x44) == 0` | `0` |
| else | `*(uint8_t*)(*(this+0x44) + 0x29)` |

`FUN_005070d0`: if `*(this+8) != 0`, prepare path (`FUN_0055e490` / optional `FUN_0055eb80`) — **not dualed here**.

---

## 7. Call surface (list only — no parent ownership)

Ghidra xrefs (**4** call sites):

| Site | Enclosing | Notes |
|---|---|---|
| `0x00922fd4` | `Client_Input_DriveControlTick` | Brake-edge / air-stab SECTION 8: stack vec `(0, 550.0f, 0, 0)`; `ECX = [reg+8]` then call |
| `0x0091d64c` | `FUN_0091d460` | Random-direction scaled float4 → this helper |
| `0x0091da00` | `FUN_0091d660` | Similar random/base blend float4 → this helper |
| `0x0095846c` | (no Ghidra function name) | Same ABI pattern: `MOV ECX,[EBX+8]` / `PUSH EDX` / `CALL` |

Caller ABI pattern (all sampled sites): **`this = *(obj+8)`** (physics host on entity-like object), **stack = &float4**.

DriveControlTick constant: `DAT_00aaacc0 = 550.0f` on Y component — upward vector at the brake-edge fire. Parent semantics open; this unit only forwards the pointer.

---

## 8. Confidence

| Claim | Level |
|---|---|
| CF: probe → optional prepare → vtbl+0x5c(vec) | **High** |
| Twin of ApplyImpulseVector differing only by slot | **High** (byte diff) |
| `__thiscall` + `RET 4`, one stack vector* | **High** |
| `this+0x3c` body*, `this+0x44` gate host* | **High** |
| Decompiler `FUN_005070b0` return-as-char* presentation | **Artifact** — out-param model **High** |
| Product English for vtbl+0x5c | **Tentative / open** |
| Vec layout float3 vs float4 | **Probable float4** at callers (4 stores); body does not read fields |
| Runtime / bit-exact / implementer of +0x5c | **Open** |

---

## 9. Gaps (do not block dual seal)

1. Havok / wrapper product name for body vtbl `+0x5c` (vs `+0x50` linear apply/set, `+0x54` set ang vel, `+0x64` ang impulse in other notes).
2. Whether prepare helpers are “dirty write enable,” physics-activate, or heartbeat — product names open (`FUN_005070b0` / `d0` still scaffolds).
3. Full audit of site `0x0095846c` parent function (undefined in Ghidra).
4. Runtime live hit; bit-exact vs on-disk image.

---

## Verdict

**accept-with-gaps** — body CF and sibling slot split are sealed High from decompile + `read_memory`. Name remains **Inferred** until vtbl+0x5c English is recovered. Do not invent impulse/force/setLinear identity beyond “vector apply via body vtbl+0x5c.”
