# Review A (reconstruction fidelity): `aa_0065eb10` Phys_StackDesc_ResetFlag0_Float1000

| Field | Value |
|---|---|
| **Stable ID** | `aa_0065eb10` |
| **VA** | `0x0065eb10` |
| **Body** | `0x0065eb10`–`0x0065eb22` (19 bytes) |
| **Canonical name** | `Phys_StackDesc_ResetFlag0_Float1000` (Ghidra `FUN_0065eb10`; **Inferred**) |
| **Review date** | `2026-07-29` (W25-O dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0065eb10_Phys_StackDesc_ResetFlag0_Float1000.md` |
| **System** | physics / Havok stack or CCS descriptor |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_function_by_address` only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf **stack/CCS descriptor reset**: clear flag byte at `+0`, write **1000.0f** at `+4` from `DAT_00a0f520`. Two callers — wheels post-ctor stack-desc teardown (`FUN_0064fe40`) and chassis vtbl+0x18 optional CCS reset (`hkDefaultChassis_vtbl_0x18`). Does not free or mutate a heap wheels/chassis instance by itself.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0065eb10_FUN_0065eb10.md` |
| Annotated | `docs/reconstruction/raw/aa_0065eb10_FUN_0065eb10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_StackDesc_ResetFlag0_Float1000.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0065eb10.cpp` |
| Function record | `docs/reconstruction/functions/aa_0065eb10_FUN_0065eb10.md` |
| Live decompile | `decompile_function` @ `0x0065eb10` ≡ raw |
| Machine | `read_memory` 64 B @ `0x0065eb10`; 8 B @ `0x00a0f520` |
| Callers | `analyze_function_complete` → 2 |
| Parent context | `physics/verified/fn_0064fee0_wheelsCtor.md`, `fn_0064fdf0_chassisCtor.md` |

---

## 3. Byte seal (`read_memory` @ `0x0065eb10`)

```
F3 0F 10 05 20 F5 A0 00   movss xmm0, [0x00a0f520]   ; 1000.0f
8B C1                     mov   eax, ecx
C6 00 00                  mov   byte ptr [eax], 0
F3 0F 11 40 04            movss [eax+4], xmm0
C3                        ret
```

Full body hex (19 B):
```
f30f100520f5a0008bc1c60000f30f114004c3
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__fastcall` ECX = desc | **High** | `mov eax,ecx`; no stack arg; plain `ret` |
| Leaf | **High** | no call |
| `*desc = 0` | **High** | `C6 00 00` |
| float@+4 = 1000.0f | **High** | movss store; `read_memory` `00 00 7a 44` |
| Live decompile ≡ raw | **High** | side-by-side |
| Clean ≡ raw CF | **High** | two stores only |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load DAT_00a0f520 | **Yes** |
| Clear byte +0 | **Yes** |
| Store float +4 | **Yes** |
| No callees / no free | **Yes** |
| Two callers only | **Yes** (xrefs) |

---

## 5. Gaps (non-blocking)

- Product/PDB symbol (Inferred name only).
- Exact product typedef for the 8-byte descriptor (CCS vs wheels stack-desc).
- Runtime / bit-exact not run.
- Decompiler `void` vs EAX=this residual (bytes prefer return-this; clean documents both).

---

## 6. Verdict

Fidelity pass seals 19 B leaf, constant 1000.0f, two stores, two callers → **accept**.
