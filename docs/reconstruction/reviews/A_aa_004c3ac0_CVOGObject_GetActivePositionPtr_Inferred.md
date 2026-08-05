# Review A (reconstruction fidelity): `aa_004c3ac0` CVOGObject_GetActivePositionPtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3ac0` |
| **VA** | `0x004c3ac0` |
| **Body** | `0x004c3ac0`–`0x004c3aef` (48 bytes) |
| **Canonical name** | `CVOGObject_GetActivePositionPtr_Inferred` (Ghidra `FUN_004c3ac0`; **Inferred**) |
| **Review date** | `2026-07-29` (W20-O dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004c3ac0_CVOGObject_GetActivePositionPtr_Inferred.md` |
| **System** | object pose |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf **active position source pointer** getter. Selects among three homes for the object pose block used by motion/pose consumers:

1. **Local override** `this+0x240` when component flags low bits clear.
2. **Phys-linked** world position at `*( *(this+8)+0x3c ) + 0xb0` when phys pointer non-null.
3. **Embedded** component pose at `this + typeOff + 0x84`.

Sibling of gated writer `FUN_004c3a40` / store leaf `FUN_004cb3e0` (writes the `+0x240` block).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c3ac0_FUN_004c3ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c3ac0_FUN_004c3ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_GetActivePositionPtr_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_004c3ac0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c3ac0_FUN_004c3ac0.md` |
| Live decompile | `decompile_function` @ `0x004c3ac0` ≡ raw |
| Machine | `read_memory` 128 B @ `0x004c3ac0` |
| Callers | `get_function_callers` / xrefs → 5 functions / 7 sites |
| Sibling dual | `A_aa_004c3a40_CVOGObject_SetLocalPosition4_Gated_Inferred` |

---

## 3. Byte seal (`read_memory` @ `0x004c3ac0`)

```
8B 41 04                 mov  eax, [ecx+4]
8B 50 04                 mov  edx, [eax+4]            ; typeOff
F6 84 0A B8 00 00 00 07  test [edx+ecx+0xb8], 7
8D 04 0A                 lea  eax, [edx+ecx]
75 07                    jnz  phys_or_embed
8D 81 40 02 00 00        lea  eax, [ecx+0x240]
C3                       ret
8B 49 08                 mov  ecx, [ecx+8]
85 C9                    test ecx, ecx
74 09                    jz   embed
8B 41 3C                 mov  eax, [ecx+0x3c]
05 B0 00 00 00           add  eax, 0xb0
C3                       ret
05 84 00 00 00           add  eax, 0x84
C3                       ret
```

| Claim | Confidence | Evidence |
|---|---|---|
| ECX = this; bare `ret` | **High** | no stack arg loads; three `C3` epilogues |
| Flag mask imm **7** | **High** | `test …, 07` |
| Local path `+0x240` | **High** | `lea eax,[ecx+0x240]` |
| Phys: `*(phys+0x3c)+0xb0` | **High** | `mov eax,[ecx+0x3c]` then `add eax,0xb0` |
| Embed: `this+typeOff+0x84` | **High** | `lea eax,[edx+ecx]` then `add eax,0x84` |
| Leaf | **High** | no `call`/`E8` |
| Body 48 B | **High** | last `ret` @ `0x004c3aef`; next `push ebx` @ `0x004c3af0` |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| typeOff = *(*(this+4)+4) | **Yes** |
| (flags&7)==0 → return this+0x240 | **Yes** |
| phys = *(this+8); non-null → *(phys+0x3c)+0xb0 | **Yes** |
| else this+typeOff+0x84 | **Yes** |
| No callees / no stores | **Yes** |

---

## 5. Caller usage (context only)

Seven unconditional call sites in five functions (`FUN_005cd3b0`×2, `FUN_005cedf0`×2, `FUN_005d2800`, `FUN_0060a230`, `FUN_009190d0`). Role: read active pose for teleport/motion helpers. Full consumer dual out of OWN scope.

---

## 6. Gaps

1. Product/PDB symbol string — open (`_Inferred`).
2. Exact English type of `this+8` / `*(phys+0x3c)` — open.
3. Per-bit producers of component `+0xb8` — open (mask sealed).
4. Runtime / bit-exact differential — open.

**Verdict:** **accept**
