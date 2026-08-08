# Review A (reconstruction fidelity): `aa_00634c50` MeshHost_UploadXformPosNormAndIB16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00634c50` |
| **VA** | `0x00634c50`–`0x00634df8` exclusive (**424 B** / `0x1A8`) |
| **Canonical name** | `MeshHost_UploadXformPosNormAndIB16_Inferred` |
| **Ghidra name** | `FUN_00634c50` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-D) |
| **Counterpart** | `reviews/B_aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md` |
| **System** | mesh / gfx upload |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` + callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fastcall worker: given a mesh-upload host pointer, lock the owner's VB, transform host source positions/normals by a stack-copied owner xform (`FUN_00416240`), write them into FVF position/normal slots, unlock VB, lock IB (`0x800`), pack u32→u16 indices, unlock IB.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9J-D append) | `docs/reconstruction/raw/aa_00634c50_FUN_00634c50.md` |
| Annotated | `docs/reconstruction/raw/aa_00634c50_FUN_00634c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MeshHost_UploadXformPosNormAndIB16_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00634c50.cpp` |
| Function record | `docs/reconstruction/functions/aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md` |
| Peer wrapper | `FUN_00416240` (WQ9I-H dualed) |
| Live | decompile ≡ scaffold CF; prologue/epilogue sealed |

---

## 3. Signature (sealed)

```c
void __fastcall MeshHost_UploadXformPosNormAndIB16_Inferred(void* host); // ECX
```

| Formal | Source | Conf |
|---|---|---|
| host | ECX → EDI (`8B F9`) | **High** |
| return | void | **High** |
| cleanup | `C3` | **High** |

---

## 4. Control flow (authority)

```
if any of host[+0x10..+0x20] null/zero → return
*(owner+0xBC) |= 1
locked = VB_Lock(owner+0x10, 0, vertCount, 0)
if locked:
  stride = GetStride(...)
  temp = FieldBlock_CopyFrom_ClearFlags(stack, GetXformSrc(owner))
  posEl = FindFVF(decl, usage=0,0); nrmEl = FindFVF(decl, usage=3,0)
  for i in 0..vertCount-1:
    write xform(pos[i]) at locked+posOff
    write xform(nrm[i]) at locked+nrmOff
    locked += stride; src += 0xC
  if VB device: UnlockVB
ib = IB_Lock(owner+8, 0, indexCount, 0x800)
if ib:
  for i: dst_u16[i] = low16(src_u32[i])
  if IB device: UnlockIB
```

| Stage | Match | Conf |
|---|---|---|
| Gate + flag OR | decompile ≡ prologue CMPs + `OR [EAX+0xBC],1` | **High** |
| VB/IB lock-unlock pair | callees + `gfxDeviceVB/IB.cpp` strings | **High** |
| FieldBlock temp | call site `00634ce5` sealed | **High** |
| FVF usage 0 and 3 | PUSH 0/0 and 3/0 to `FUN_007468e0` | **High** |
| u16 index pack | `*(u16*)(ib+i*2) = *(u16*)(src+i*4)` | **High** |
| Sole caller Tick path | `005952a9` ECX from `this+0x1c4` table | **High** |

---

## 5. Machine bytes (entry / exit)

Prologue: `55 8B EC 83 E4 F0 81 EC F4 00 00 00 53 56 57 8B F9`  
Epilogue: `5F 5E 5B 8B E5 5D C3` @ end of body.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00595230` @ `0x005952a9` (1 UNCONDITIONAL_CALL) |
| Key callees | `00414ae0`, `0044bcc0`, `00437960`, `00416240`, `007468e0`×2, `009732d0`, `00973240`, `007464e0`, `0044ba40`, `00743ba0` |

---

## 7. Gaps

1. Product English for host / owner types.  
2. Exact ECX object identity for `FUN_0044bcc0` / unlock wrappers (pointer chain sealed at call sites; type names open).  
3. IB lock flag `0x800` product enum.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path seals ABI, body size, host offsets, VB/IB upload shape, FieldBlock temp use, and sole Tick caller. Residual product English + some device-wrapper typing → **accept-with-gaps**.
