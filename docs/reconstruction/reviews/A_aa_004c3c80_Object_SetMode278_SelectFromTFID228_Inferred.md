# Review A (reconstruction fidelity): `aa_004c3c80` Object_SetMode278_SelectFromTFID228_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3c80` |
| **VA** | `0x004c3c80`–`0x004c3d17` |
| **Canonical name** | `Object_SetMode278_SelectFromTFID228_Inferred` |
| **Ghidra name** | `FUN_004c3c80` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-L) |
| **Counterpart** | `reviews/B_aa_004c3c80_Object_SetMode278_SelectFromTFID228_Inferred.md` |
| **System** | object / AI owner mode / selected-target apply |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + xrefs; dual-sealed callees |
| **Verdict** | **accept** |

---

## 1. Purpose

Write owner mode at `+0x278`. When `mode==1`, resolve stored `TFID_16` at `+0x228` and promote `resolved+0xA0` to selected target after MI `vtbl+0x298` gate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c3c80_FUN_004c3c80.md` (+ 2026-07-29 W28-L append) |
| Annotated | `docs/reconstruction/raw/aa_004c3c80_FUN_004c3c80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetMode278_SelectFromTFID228_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c3c80.cpp` |
| Function | `docs/reconstruction/functions/aa_004c3c80_FUN_004c3c80.md` |
| Named record | `docs/reconstruction/functions/aa_004c3c80_Object_SetMode278_SelectFromTFID228_Inferred.md` |
| Live | decompile + full-body hex 151 B; epilogue `… 83 C4 10 C2 04 00` |
| Callee duals | `Object_ResolveFromTFID` `0x004bb950`; `Object_SetSelectedTarget` `0x005172d0` |

---

## 3. Signature (sealed)

```c
// thiscall; 1 stack formal (char); RET 4
void Object_SetMode278_SelectFromTFID228_Inferred(void *this, char mode);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX (`8B F1`) | **High** |
| mode | `[ESP+4]` (`8A 44 24 04`) | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
this+0x278 = mode
if mode != 1: return
copy TFID_16 from this+0x228
ctx = manager chain (+0xA8 / +0xE4E8)   // surface residual
resolved = Object_ResolveFromTFID(ctx, &local)
if resolved==0 or resolved+0xA0==0: return
mi = this + *(*(this+4)+4) + 4
if !mi->vtbl[+0x298](candidate): return
Object_SetSelectedTarget(mi, candidate)
```

| Stage | Match | Conf |
|---|---|---|
| Store +0x278 | **Yes** | **High** |
| mode==1 gate | **Yes** (`CMP AL,1` / `JNE`) | **High** |
| TFID_16 copy | **Yes** | **High** |
| Resolve → `0x004bb950` | **Yes** (rel32) | **High** |
| Manager ECX in bytes | **Yes** (surface omits) | **High** |
| vtbl+0x298 thiscall | **Yes** (`FF 92 98 02 00 00`) | **High** |
| SetSelectedTarget → `0x005172d0` | **Yes** (rel32; 1 push) | **High** |
| thiscall RET 4 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (151 B):
```
8a44240483ec103c01568bf1888678020000757d8d86280200008b088b5004894c24048b4808895424088b500c8b4604894c240c895424108b48048b9431a80000008b8ae8e40000578d44240850e87d7cffff8bf885ff74378b87a000000085c0742d8b4e048b51048d4c32048b1150ff929802000084c074168b4e048b87a00000008b5104508d4c3204e8c03505005f5e83c410c20400
```

Call sites: `0x004c3cce` → `0x004bb950`; `0x004c3d0b` → `0x005172d0`. Virtual `CALL [EDX+0x298]`.

---

## 6. Gaps

- Product English for mode enum at **+0x278** (also cited as death/respawn states in AI plates).
- Product name of TFID at **+0x228**.
- Product English for **vtbl+0x298**.
- Runtime / bit-exact — open.

---

## 7. Verdict

CF, ABI, mode gate, TFID source, dual-sealed callees, and virtual dispatch sealed against live decompile and full-body bytes. `_Inferred` only for product mode/TFID English. → **accept**.
