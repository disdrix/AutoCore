# Review A (reconstruction fidelity): `aa_0096de80` phyBone_CopySharedQsTransformToLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096de80` |
| **VA** | `0x0096de80` |
| **Body** | `0x0096de80`–`0x0096dedd` exclusive (**93** B) |
| **Canonical name** | `phyBone_CopySharedQsTransformToLocal` |
| **Prior / alias** | `FUN_0096de80`; residual `Named_CalleeOf_Named_gfxBodyMassageMachine_0096de80` |
| **Review date** | `2026-07-29` (W20-E OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` |
| **System** | physics / phy (asset I/O) |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Mirror shared hkQsTransform into bone locals** after BDAT unserialize:

1. `shared = *(EAX + 0xf4)`
2. Copy 10 floats: shared `+0x0c..+0x30` → bone `+0x04..+0x28` (quat4 + trans3 + scale3)
3. `*(EAX + 0x140) = 0xffffffff`

Leaf; no callees; bare ret.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096de80_FUN_0096de80.md` (+ W20-E append) |
| Annotated | `docs/reconstruction/raw/aa_0096de80_FUN_0096de80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBone_CopySharedQsTransformToLocal.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0096de80.cpp` |
| Function record | `docs/reconstruction/functions/aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` |
| Live decompile | ≡ raw (EAX bone, +0xf4 source, +0x140 = -1) |
| Live body bytes | `read_memory` @ `0x0096de80` length 100 |
| Call sites | `MOV EAX,ESI` / `MOV EAX,EBP` then CALL |
| Parent dual | `aa_0096e280` phyBone_unserialize (after BDAT) |
| Sibling dual | `aa_00449dc0` installs shared used as source |

---

## 3. Byte seal (`read_memory` @ `0x0096de80`)

```
8b 88 f4 00 00 00   mov ecx, [eax+0xf4]     ; shared*
56                  push esi
57                  push edi
8d 51 0c            lea edx, [ecx+0xc]      ; &shared.quat
8b 3a / 8d 70 04 / 89 3e …                  ; copy 4 dwords → bone+4
8d 51 1c            lea edx, [ecx+0x1c]     ; &shared.trans
…                   ; copy 3 dwords → bone+0x14
83 c1 28            add ecx, 0x28           ; &shared.scale
…                   ; copy 3 dwords → bone+0x20
c7 80 40 01 00 00 ff ff ff ff  mov [eax+0x140], -1
5e                  pop esi
c3                  ret
```

| Claim | Evidence | Conf |
|---|---|---|
| EAX = bone (`[eax+0xf4]`) | `8b 88 f4 00 00 00` + call-site `mov eax, bone` | **High** |
| Source offsets 0xc / 0x1c / 0x28 | LEAs / add in body | **High** |
| Dest offsets 4 / 0x14 / 0x20 | LEAs to `[eax+…]` | **High** |
| Exactly 10 dwords | 4+3+3 stores; no +0x40 | **High** |
| `+0x140 = -1` | `c7 80 40 01 00 00 ff ff ff ff` | **High** |
| Bare `ret`; leaf | final `c3`; no CALL in body | **High** |
| Body 93 B | exclusive end `0096dedd` | **High** |
| Decompile ≡ raw ≡ bytes | three-rep match | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load shared from +0xf4 | **Yes** |
| 10-float qs copy only | **Yes** |
| Invalidate +0x140 | **Yes** |
| No bind matrix / shape copy | **Yes** |
| EAX ABI; bare ret | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| hkQs component grouping | **High** | matches shared defaults + plate |
| +0x140 English (dirty/cache id) | **Med** | value sealed; name open |
| Product method spelling | **Low–Med** | structural |
| Runtime / bit-exact | Open | static dual only |

**Verdict:** **accept** — copy map + ABI + sentinel sealed.
